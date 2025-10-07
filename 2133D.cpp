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


int n; 
vector<ll> arr; 
void input ()
{
    arr.clear(); 
    arr.pb(-1); 
    cin >> n; 
    for (int i = 0; i < n; i ++) {
        int a; cin >> a; 
        arr.pb(a); 
    }
}


void solve ()
{
    const int maxn = 2e5 + 10; 
    ll dp[maxn]; 
    dp[0] = 0; dp[1] = arr[1]; 
    for (int i = 2; i <= n; i ++) {
        dp[i] = min(dp[i - 1] + arr[i] - 1, dp[i - 2] + arr[i - 1] + max(arr[i] - (i - 1), 0ll)); 
    }
    cout << dp[n] << "\n"; 
}

int32_t main ()
{
    int t;
    cin >> t;
    while (t--) {
        input ();
        solve (); 
    }
}