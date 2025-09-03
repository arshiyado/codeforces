#include <bits/stdc++.h>
using namespace std;

#define IOS                      \
    ios::sync_with_stdio(false); \
    cin.tie(NULL);               \
    //.tie(NULL);
#define ll long long
#define ld long double
#define pb push_back
#define pf push_front
#define qf pop_front
#define qb pop_back
#define S second
#define F first

const int maxn = 510;
ll dp[maxn][maxn];
int n, k, l;
vector<pair<int, int>> signs;

void input()
{
    cin >> n >> l >> k;
    signs.resize(n + 2);
    for (int i = 0; i < n; i++)
    {
        int d;
        cin >> d;
        signs[i].F = d;
    }
    for (int i = 0; i < n; i++)
    {
        int s;
        cin >> s;
        signs[i].S = s;
    }
    signs[n] = {l, 0}; 
    //  signs.pb({l, 0}); 
    // 10 11
    // << "finished input\n";
}

void solve()
{
    for (int i = 0; i <= n + 1; i++)
    {
        for (int j = 0; j <= n + 1; j++)
        {
            dp[i][j] = 100000000000000;
        }
    }
    // if (n == 1) {
    //     cout << 1ll * l * signs[0].S << endl; 
    //     return; 
    // }
    // << "ended big\n";
    dp[0][0] = 0;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 0; j <= min(i - 1, k); ++j)
        {
            for (int z = 0; z < i; ++z)
            {
                // << i << " " << j << " " << z << endl; 
                int removed = i - z - 1;
                if (removed > j){
                    // // << "par\n"; 
                    continue;
                }
                // << "!par\n"; 
                dp[i][j] = min(dp[i][j], dp[z][j - removed] + 1LL * (signs[i].F - signs[z].F) * signs[z].S);
                // cout << dp[i][j] << " " << signs[i].F << " -- " << signs[z].F << " " << signs[z].S << "\n"; 
            }
        }
    }

    
    ll ans = 10000000000000;
    for (int j = 0; j <= k; j++)
    {
        ans = min(ans, dp[n][j]);
        // << n << " " << j << " " << dp[n][j] << "\n"; 
    }
    // << n << "\n";
    cout << ans << "\n";
}

int main()
{
    IOS;
    input();
    solve();
}
