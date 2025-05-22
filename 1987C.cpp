#include <bits/stdc++.h>
using namespace std;
vector<int> arr; 
int n; 
int mx = -1; 
void input ()
{
    mx = -1; 
    arr.clear(); cin >> n; 
    for (int i = 0; i < n; i ++) {
        int a; cin >> a; 
        arr.push_back(a); 
        mx = max(a, mx); 
    }
}
void solve ()
{
    int ans = arr[n - 1]; 
    for (int i = n - 2; i >= 0; i --) {
        ans = max(ans + 1, arr[i]); 
    }
    cout << 
}
int main ()
{
    int t;
    while (t--) {
        input ();
        solve (); 
    }
}