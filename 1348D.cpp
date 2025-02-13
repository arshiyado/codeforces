#include <bits/stdc++.h>
#define pb push_back
#define pf push_front
#define qb pop_back
#define qf pop_front
#define ll long long
using namespace std;
#define IOS ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 


ll n; 
void input ()
{
    cin >> n; 
}
void solve ()
{
    vector<int> arr; 
    for (int i = 1; i <= n; i += i) {
        arr.push_back(i); 
        n -= i; 
    }
    if (n > 0) {
        arr.pb(n); 
        sort(arr.begin(), arr.end()); 
    }
    cout << arr.size() - 1 << endl; 
    for (int i = 1; i < arr.size(); i ++) {
        cout << arr[i] - arr[i - 1] << " "; 
    }
    cout << "\n"; 
}
int main ()
{   
    IOS; 
    int t;
    cin >> t;
    while (t--) {
        input (); 
        solve (); 
    }
    return 0; 
}
