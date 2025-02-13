#include <bits/stdc++.h>
using namespace std;
const int maxn = 510; 
long long dp[maxn][maxn]; 
string s, p = ""; 
int n; 
void input ()
{
    cin >> n; 
    cin >> s; 
}
void solve ()
{
    p.push_back(s[0]); 
    for (int i = 0; i < n - 1; i ++) {
        if (s[i] == s[i + 1]) {
            continue; 
        }
        else {
            p.push_back(s[i + 1]); 
        }
    }
    n = p.size(); 

    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < n; j ++) {
            dp[i][j] = n + 2; 
        }
    }
    
    for (int i = 0; i < n; i ++) {
        dp[i][i] = 1; 
    }
    // cout << "----\n"; 
    for (int l = 1; l < n; l ++) {
        // cout << "para one : " << l << endl; 
        for (int i = 0; i < n - l; i ++) {
            int j = i + l; 
            if (l == 1) {
                dp[i][j] = 2; 
                continue; 
            }
            if (l == 2) {
                if (p[i] == p[j]) {
                    dp[i][j] = 2; 
                }
                else {
                    dp[i][j] = 3; 
                }
                continue; 
            }
            // cout << "para two : " << i << " , " << j << endl ; 
            dp[i][j] = dp[i][j - 1] + 1; 
            for (int k = j - 1; k >= i; k --) {
                // cout << "para three : " << k << endl; 
                if (p[k] == p[j]) {
                    // cout << " -- > " << dp[i][j] << " . . . " << dp[i][k] + dp[k + 1][j - 1] << endl; 
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j - 1]); 
                }
            }
            
        }
    }

    // cout << dp[0][n - 1] << endl; 
     
    // cout << n << endl << "  " ; 
    // for (int i = 0; i < n; i ++) {
    //     cout << i << " "; 
    // }
    // cout << endl; 
    // for (int i = 0; i < n; i ++) {
    //     cout << i << " "; 
    //     for (int j = 0; j < n; j ++) {
    //         if (dp[i][j] > 20) {
    //             cout << "- "; 
    //         }
    //         else cout << dp[i][j] << " " ; 
    //     }
    //     cout << endl; 
    // }
    // cout << endl << endl; 
    cout << dp[0][n - 1];
}
int main ()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 

    input (); 
    solve (); 

    return 0; 
}