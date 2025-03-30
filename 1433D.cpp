#include <bits/stdc++.h>
using namespace std;

int n; 
vector<int> arr; 
set<int> cnt; 
void input ()
{
    arr.clear(); cnt.clear(); 
    cin >> n;
    for (int i = 0; i < n; i ++) {
        int a; cin >> a; 
        arr.push_back(a); 
        cnt.insert(a); 
    }
}
void solve ()
{
    if (cnt.size() == 1 && n != 1) {
        cout << "NO" << endl; 
        return; 
    }
    cout << "YES\n";
    int q = -1; 
    for (int i = 1; i < n; i ++) {
        if (arr[i] != arr[0]) {
            q = i + 1; 
            cout << i + 1 << " " << 1 << "\n"; 
        }
    }
    for (int i = 1; i < n; i ++) {
        if (arr[i] == arr[0]) {
            cout << q << " " << i + 1 << "\n"; 
        }
    }
    
}

int main ()
{
    int t;
    cin >> t; 
    while (t--) {
        input (); 
        solve (); 
    }
}