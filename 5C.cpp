#include <bits/stdc++.h>
using namespace std;
#define IOS ios:: sync_with_stdio(false); cin.tie(NULL); //.tie(NULL); 
#define ll long long 
#define ld long double 
#define pb push_back
#define pf push_front
#define qf pop_front
#define qb pop_back
#define S second 
#define F first


string s; 
int dp[1000002][2];

void input ()
{
    cin >> s; 
}
void solve ()
{
    int n = s.size(); 
    int ans = 0; 
    
    deque<int> deq; 
    for (int i = 0 ;i < n; i ++){
        
        if (s[i] == '(') {
            dp[i][0] = -1; 
            dp[i][1] = -1; 
            deq.pb(i); 
            continue; 
        }
        if (deq.empty()) {
            dp[i][0] = -1; 
            dp[i][1] = -1;  
            continue; 
        }
        int x = deq.back(); deq.qb(); 
        dp[i][0] = x; dp[i][1] = x; 
        ans = max(ans, i - x + 1); 
        int a = x - 1; 
        
        if (dp[a][0] == -1 || s[a] != ')') {
           
            continue; 
        }
        if (dp[a][1] != -1) {
            dp[i][1] = dp[a][1]; 
           
        }
        ans = max(ans, i - dp[i][1] + 1); 
    }
    
    int cnt = 0; 
    if (ans == 0) {
        cout << 0 << " " << 1 << "\n"; 
        return; 
    }
    for (int i = 0; i < n; i ++) {
        if (s[i] == '(') continue; 

        if (dp[i][0] == -1) continue; 

        if (i - dp[i][1] + 1 == ans) cnt += 1; 
    }
    cout << ans << " " << cnt << "\n"; 
}
int main ()
{
    IOS; 
    input ();
    solve (); 
}