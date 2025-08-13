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

ll n, c;
vector<ll> arr, brr; 

void input ()
{
    cin >> n >> c;
    for (int i = 0;i  < n;i ++) {
        ll a; cin >> a; arr.pb(a); 
    }
    for (int i = 0; i < n - 1; i ++) {
        ll b;
        cin >> b; 
        brr.pb(b); 
    }
}

void solve ()
{
    ll ans, rem, cnt; 
    ans = (c + arr[0] - 1)/arr[0]; 
    cnt = (brr[0] + arr[0] - 1)/arr[0]; 
    rem = cnt * arr[0] - brr[0]; 
    cnt += 1; 
    // cout << 0 << ": " << ans << " " << cnt << " " << rem << endl; 
    for (int i = 1; i < n; i ++) {
        if (c <= rem) {
            ans = min(cnt, ans); 
            cout << ans << endl; 
            return; 
        }
        
        ll q = c - rem; 
        ll t = (q + arr[i] - 1)/arr[i]; 
        ans = min(ans, cnt + t); 
        // cout << i << ": " << t << " " << ans << " " << cnt << " " << rem << endl; 
        if (i == n - 1) {
            break; 
        }
        t = 0; 
        if (brr[i] > rem) {
            t = brr[i] - rem;             
            t = (t + arr[i] - 1)/arr[i]; 
            rem = t * arr[i] - brr[i] + rem; 
        }
        else {
            rem -= brr[i]; 
        }
        cnt += t + 1; 
        continue; 
    }
    cout << ans << endl;
}


int main ()
{
    IOS; 
    int t;
    cin >> t;
    while (t--) {
        input ();
        solve (); 
        arr.clear(); brr.clear(); 
    }
}