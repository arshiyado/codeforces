#include <bits/stdc++.h>
using namespace std;

int n; 
vector<int> arr; 
vector<int> ans; 
void input ()
{
    arr.clear(); 
    cin >> n; 
    for (int i = 0; i < n; i ++) {
        int a; cin >> a; 
        arr.push_back(a); 
    }
    
}


void solve ()
{
    int dp[n + 1]; 
    dp[n - 1] = 1; 
    dp[n] = 0; 
    for (int i = n - 2; i >= 0; i --) {
        if (arr[i] == (n - 1 - i)) {
            dp[i] = 0; 
        }
        if (arr[i] + i < n) {
            dp[i] = min(dp[i + 1] + 1, dp[arr[i] + i + 1]); 
        }
        else {
            dp[i] = dp[i] = dp[i + 1] + 1; 
        }
    }
    ans.push_back(dp[0]); 
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
    for (auto x: ans) {
        cout << x << "\n"; 
    }
}
