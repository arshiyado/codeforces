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


int n, k; 
vector<int> arr;

void input ()
{   
    cin >> n >> k; 
    for (int i = 0; i < n; i ++) {
        int a; cin >> a; 
        arr.pb(a); 
    }
    
}

bool finder(int m, bool flag) 
{
    bool odd = 1; 
    int cnt = 0; 
    for (auto x: arr) {
        if (odd==flag && x <= m) {
            cnt += 1; 
            odd = !flag; 
        }
        else if (odd==flag && x > m) {
            continue; 
        }
        else {
            odd = flag; 
            cnt += 1;
        }
    }
    if (cnt >= k) {
        return true; 
    }
    return false; 
}


void solve ()
{
    int l = 0, r = 1e9; 

    while (l <= r) {
        int m = (l + r) / 2; 
        if (l == r) {
            if (finder(l, true) || finder(l, false)) {
                cout << l << endl; 
                return; 
            }
            break; 
        }
        if (finder(m, true) || finder(m, false)) {
            r = m; 
            continue; 
        }
        else {
            l = m + 1; 
            continue; 
        }
    }
    cout << r << endl; 
    return; 
}


int main ()
{
    IOS; 
    input ();
    solve (); 
}   