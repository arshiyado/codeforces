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

int q; 
const int n = 5e5; 

vector<ll> arr(n + 1, 0);
const int a = 720; 
ll sum[720][720]; 
void input ()
{
    cin >> q; 
}

void solve ()
{
    while (q--) {
        int t; cin >> t;
        int x, y; cin >> x >> y; 
        if (t == 1) {
            arr[x] += y; 
            for (int i = 1; i < a; i ++) {
                sum[i][x%i] += y;
            }
        }
        else {
            ll ans = 0; 
            if (x >= 720) {
                ll p = y; 
                while (p <= n) {
                    ans += arr[p]; 
                    p += x; 
                }
            }
            else {
                ans = sum[x][y]; 
            }
            cout << ans << endl; 
        }
    }
}

int main ()
{
    IOS; 
    input ();
    solve (); 
}