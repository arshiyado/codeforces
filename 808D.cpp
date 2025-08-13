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
map<ll, int> cnt; 
ll sum = 0; 
void input ()
{
    cin >> n; 
    for (int i = 0; i < n; i ++) {
        int a; cin >> a; 
        arr.pb(a); 
        sum += a; 
    }
}


void solve ()
{
    if (sum % 2) {
        cout << "NO\n"; 
        return; 
    }
    // cout << sum << "\n"; 
    ll pre = 0; 
    for (int i = 0; i < n; i ++) {
        pre += arr[i]; 
        if (pre == sum/2) {
            cout << "YES\n"; 
            return; 
        }
        if (pre < sum/2) {
            cnt[arr[i]] += 1; 
            continue; 
        }
        else {
            ll q = pre - sum/2; 
            
            // cout << q << "\n"; 
            if (cnt[q]) {
                cout << "YES\n"; 
                return; 
            }
            cnt[arr[i]] += 1; 
        }
    }
    cnt.clear(); 
    reverse(arr.begin(), arr.end()); 
    pre = 0; 
    for (int i = 0; i < n; i ++) {
        pre += arr[i]; 
        if (pre == sum/2) {
            cout << "YES\n"; 
            return; 
        }
        if (pre < sum/2) {
            cnt[arr[i]] += 1; 
            continue; 
        }
        else {
            ll q = pre - sum/2; 
            
            // cout << i << " " << arr[i] << " " << q << "\n"; 
            if (cnt[q]) {
                cout << "YES\n"; 
                return; 
            }
            cnt[arr[i]] += 1; 
        }
    }
    cout << "NO\n"; 
    return; 
}

int main ()
{
    IOS; 
    input ();
    solve (); 
}