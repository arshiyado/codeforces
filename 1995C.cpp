#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double 
int n;
vector<ld> arr; 

void input ()
{
    cin >> n; 
    for (int i = 0; i < n; i ++) {
        ld a; cin >> a; 
        arr.push_back(a); 
    }
}


void solve ()
{
    ld dp[n + 1]; 
    dp[0] = 0; 
    ll ans = 0; 
    for (int i = 1; i < n; i ++) {
        if (arr[i] == 1 && arr[i - 1] != 1) {
            cout << "-1\n"; return; 
        } 
        if (arr[i] == 1 || arr[i - 1] == 1) {
            dp[i] = 0; 
            continue; 
        }
        
        ld k = dp[i - 1]; 
        ld d = log2(arr[i - 1]); 
        d /= (log2(arr[i])); 
        d = log2(d); 
        k += d; 
        dp[i] = ceil(k); 
        if (k <= 0) {
            dp[i] = 0; 
        }
    }
    for (int i = 0; i < n; i ++) {
        
        ans += dp[i]; 
    }
    cout << ans << endl; 
}


int main ()
{
    
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);  
    int t; cin >> t; 
    while (t--) {
        input ();
        solve (); 
        arr.clear(); 
    }   
}