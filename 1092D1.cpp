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
vector<int> arr; 

void input ()
{
    cin >> n; 
    for (int i = 0; i < n; i ++) {
        int a; cin >> a; 
        arr.pb(a%2); 
    }
}

void solve ()
{
    set<pair<int, int>> all, eve; 
    for (int i = 0; i < n; i ++) {
        int j = i; 
        while (j + 1 < n && arr[j + 1] == arr[i]) {
            j += 1;
        }
        all.insert({i, j}); 
        if ((j - i + 1)%2 == 0) {
            eve.insert({i, j}); 
        }
        i = j; 
    }


    while (all.size() > 1 && !eve.empty()) {

        auto seg = *eve.begin(); 
        // cout << seg.first << " - "  << seg.second << "\n"; 
        all.erase(seg); eve.erase(seg); 

        auto it = all.lower_bound(seg); 
        if (it != all.end()) {
            seg.second = it->second; 
            if ((it->second - it->first + 1) % 2 == 0) {
                eve.erase(*it); 
            }
            all.erase(*it); 
        }


        it = all.lower_bound(seg); 
        if (it != all.begin()) {
            it --; 
            seg.F = it->first; 
            if ((it->second - it->first) % 2 == 0) {
                eve.erase(*it); 
            }
            all.erase(*it); 
        }
        if ((seg.second - seg.F + 1) % 2 == 0) {
            eve.insert(seg); 
        }
        // cout << seg.first << " - "  << seg.second << "\n"; 
        all.insert(seg);
    }
    if (all.size() == 1) {
        cout << "YES\n"; 
    }
    else {
        cout << "NO\n"; 
    }
    return; 

}

int main ()
{
    IOS; 
    input ();
    solve (); 
    return 0; 
}