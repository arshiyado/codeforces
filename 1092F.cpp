#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long
#define ld long double
#define pb push_back
#define pf push_front
#define qf pop_front
#define qb pop_back
#define S second
#define F first

const long long maxn = 2e5 + 10;
vector<ll> val(maxn); 
vector<ll> adj[maxn]; 
vector<ll> sub(maxn); 
vector<ll> sum(maxn); 
ll ans[maxn]; 
ll n; 

void input ()
{
    cin >> n; 
    for (ll i = 0; i < n; i ++) {
        ll a; cin >> a; 
        val[i + 1] = a;  
    }
    for (ll i = 0; i < n - 1; i ++) {
        ll u, v; cin >> u >> v; 
        adj[u].pb(v); 
        adj[v].pb(u); 
    }

}
bool mark[maxn]; 

void DFS (ll u)
{
    mark[u] = true; 
    if (adj[u].size() == 1) {
        sub[u] = 1; 
        sum[u] = val[u]; 
        return; 
    }
    for (auto x: adj[u]) {
        if (!mark[x]) {
            mark[x] = true; 
            DFS(x); 
            sub[u] += sub[x]; 
            sum[u] += sum[x]; 
        }

    }
    sub[u] += 1; 
    sum[u] += val[u]; 
    return; 

}

void cal (ll s)
{

    queue<ll> que; 
    que.push(s); 
    ll dist[n + 1]; 
    for (ll i = 0; i <= n; i ++) {
        mark[i] = false; 
        dist[i] = n + 2; 
    }
    mark[s] = true; 
    dist[s] = 0; 
    while (!que.empty()) {
        ll u = que.front(); 
        que.pop(); 
        ans[s] += (val[u]) * dist[u]; 
        for (auto x: adj[u]) {
            if (!mark[x]) {
                que.push(x); 
                mark[x] = true; 
                dist[x] = dist[u] + 1; 
            }
        }
    }
}

void dfs (ll u)
{
    mark[u] = true; 
    for (auto x: adj[u]) {
        
        if (!mark[x]) {
            mark[x] = true; 
            ans[x] = ans[u]; 
            ans[x] -= sum[x]; 
            ans[x] += (sum[u] - sum[x]); 
            sum[x] = sum[u]; 
            
            dfs(x); 
        }
    }
    return; 
}

void solve ()
{
    if (n == 2 ){
        cout << max(val[1], val[2]) << "\n"; 
        return; 
    }
    ll s = 1; 
    for (ll i = 1; i <= n; i ++) {
        if (adj[i].size() != 1) {
            s = i; break; 
        }
    }
    DFS(s); 
    
    
    cal(s); 
    
    for (ll i = 0; i <= n; i ++) {
        mark[i] = false; 
    }
    dfs(s); 
    ll res = -1; 
    for (ll i = 1; i <= n; i ++) {
        res = max(res, ans[i]); 
    }
    cout << res << "\n"; 

}

int main ()
{
    IOS; 
    input ();
    solve (); 
}