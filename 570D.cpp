#include <bits/stdc++.h>
using namespace std;

const int maxn = 5e5 + 5;
int st[maxn], en[maxn], h[maxn], lef[maxn], rig[maxn];
vector<pair<int, int>> lev[maxn];
vector<int> adj[maxn], vec[maxn];
bool ans[maxn];

void dfs(int u = 0, int l = 0)
{
    static int time = 0;
    lev[h[u] = l].push_back({st[u] = time++, u});
    h[u] = l;
    st[u] = time;
    time += 1;
    lev[l].push_back({st[u], u});
    for (auto v : adj[u])
        dfs(v, l + 1);
    en[u] = time;
}

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    for (int i = 1; i < n; i++)
    {
        int u;
        cin >> u;
        adj[u - 1].push_back(i);
    }
    string s;
    cin >> s;

    dfs();
    for (int i = 0; i < m; i++)
    {
        int u, l;
        cin >> u >> l;

        l--;
        u--;
        vec[l].push_back(i);
        ans[i] = true;
        lef[i] = lower_bound(lev[l].begin(), lev[l].end(), make_pair(st[u], -1)) - lev[l].begin();
        rig[i] = lower_bound(lev[l].begin(), lev[l].end(), make_pair(en[u], -1)) - lev[l].begin();
    }

    for (int i = 0; i < n; i++)
    {
        if (!vec[i].empty())
        {
            vector<int> sum[26];
            for (int j = 0; j < 26; j++)
            {
                sum[j] = {0};
            }
            for (auto u : lev[i])
            {
                for (int j = 0; j < 26; j++)
                {
                    sum[j].push_back(sum[j].back() + (s[u.second] - 'a' == j));
                }
            }
            for (auto x : vec[i])
            {
                for (int j = 0, cnt = 0; j < 26; j++)
                {
                    cnt += sum[j][rig[x]] - sum[j][lef[x]];
                    if (cnt >= 2)
                    {
                        ans[x] = false;
                        break;
                    }
                }
            }
        }
    }
    for (int i = 0; i < m; i++)
    {
        if (ans[i])
        {
            cout << "Yes\n";
        }
        else
        {
            cout << "No\n";
        }
    }

    return 0;
}
