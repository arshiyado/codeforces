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
const int maxn = 3e5 + 10; 
vector<ll> arr; 

ll n; 

ll ans[maxn]; 
ll res[maxn]; 
ll inf;
void input ()
{
    cin >> n; 
    inf = n; 
    for (int i = 0; i < n; i ++) {
        int a; cin >> a; 
        arr.pb(a); 
        ans[i] = inf; 
        res[i] = inf; 
    }
}

void solve ()
{
    vector<ll> pre(n + 1); 
    int dif[n + 1]; 
    dif[0] = -1; 
    inf = n + 1; 
    ans[0] = inf; 
    
    for (int i = 1; i < n; i ++) {
        ans[i] = inf; 
        if (arr[i] != arr[i - 1]) {
            dif[i] = i - 1; 
            continue; 
        }
        dif[i] = dif[i - 1]; 
    }

    pre[n - 1] = arr[n - 1]; 
    for (int i = n - 2; i >= 0; i --) {
        pre[i] = pre[i  + 1] + arr[i]; 
    }
    if (arr[0] > arr[1]) {
    
        ans[1] = 1;
    }
    
    for (int i = 2; i < n; i ++) {
        
        int l = 0, r = i - 1;
        while (l < r) {
            int m = (l + r)/2; 
            if ((pre[m] - pre[i] > arr[i])) {
                if (l == m) {
                    if (pre[r] - pre[i] > arr[i]) {
                        l = r; 
                    }
                    break; 
                }
                l = m; 
                continue; 
            }
            else {
                r = m - 1; 
            }
        }
        if (pre[l] - pre[i] <= arr[i]) {
            ans[i] = inf; 
            continue; 
        }
        if (l == i - 1) {
            ans[i] = 1; 
            continue; 
        }
        if (r == -1) {
            continue; 
        }
        if (dif[i - 1] >= l) {
            ans[i] = i - l; 
            continue; 
        }
        else {
            
            if (dif[l] == -1) {
                continue; 
            }
            l = dif[l]; 
            ans[i] = i - l; 
            continue; 
        }
    }
}


int main ()
{
    IOS; 
    int t; cin >> t; 
    while (t--) {
        input ();
        solve ();
        reverse(arr.begin(), arr.end()); 
        for (int i = 0; i < n; i ++) {
            res[i] = ans[i]; 
        }
        solve ();
        for (int i = 0; i < n; i ++) {
            if (ans[n - i - 1] == inf && res[i] == inf) {
                cout << -1 << " "; 
            }
            else {
                cout << min(ans[n - 1 - i], res[i]) << " "; 
            }
        }
        cout << "\n"; 
        arr.clear(); 
    }
}