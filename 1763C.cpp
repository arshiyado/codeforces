#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10; 
long long n; 
vector<long long> arr; 
void input ()
{
    cin >> n; 
    arr.clear(); 
    for (int i = 0; i < n; i ++) {
        int a; 
        cin >> a;
        arr.push_back(a); 
    }
}

void solve ()
{
    long long ans = 0; 
    if (n == 2) {
        ans = max(arr[0] + arr[1], abs(arr[0] - arr[1]) * 2); 
    }
    else if (n == 3) {
        ans =  max({3 * (abs(arr[0] - arr[1])), 3 * (abs(arr[2] - arr[1])), 3 * arr[0], 3 * arr[2], arr[0] + arr[1] + arr[2]});
    }
    else {
        ans = *max_element(arr.begin(), arr.end()) * n; 
    }
    cout << ans << endl; 
}

int main ()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 
    int t;
    cin >> t; 
    while (t--) {
        input (); 
        solve (); 
    }
}