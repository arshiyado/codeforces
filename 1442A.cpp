#include <bits/stdc++.h>
using namespace std;

#define IOS ios:: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 
#define ll long long 
#define ld long double 
#define pb push_back
#define pf push_front
#define qf pop_front
#define qb pop_back
#define S second 
#define F first

vector<int> arr; 
int n; 

void input ()
{
    cin >> n; 
    for (int i = 0; i < n; i ++) {
        int a; cin >> a; 
        arr.push_back(a); 
    }
}


void solve ()
{
    int dp[n + 1]; 
    int lf[n + 1]; 
    
    dp[0] = arr[0]; 
    lf[0] = 0; 
    for (int i = 1; i < n; i ++) {
        if (arr[i] < lf[i - 1]) {
            cout << "NO\n"; 
            return; 
        }
        dp[i] = min(dp[i - 1], arr[i] - lf[i - 1]); 
        lf[i] = arr[i] - dp[i]; 
    }
    
   
    cout << "YES\n"; 
    return; 
}


int main ()
{
    IOS; 
    int t;
    cin >> t; 
    while (t--) {
        input();
        solve(); 
        arr.clear(); 
    }
}