#include <bits/stdc++.h>
using namespace std;
const long long maxn = 2e5 + 10; 
const long long inf = 1e18 + 10; 
long long arr[maxn][8]; 
int d[maxn], f[maxn];
long long ans[maxn], cost[maxn]; 
vector<int> adj[maxn]; 
long long answer; 
long long n; 
void input ()
{
    cin >> n; 
    for (int i = 1; i <= n; i ++) {
        long long a, b, c; 
        cin >> a >> b >> c; 
        cost[i] = a; 
        d[i] = b; 
        f[i] = c; 
    }
    for (int i = 0; i < n - 1; i ++) {
        int u, v; 
        cin >> u >> v; 
        adj[u].push_back(v); 
        adj[v].push_back(u); 
    }
}

void DFSOne (int u, int p)
{
    arr[u][d[u]] ++; 
    arr[u][f[u] + 2] ++; 
    if (d[u] != f[u]) {
        arr[u][4] ++;    
        arr[u][5] ++; 
    }
    for (auto x: adj[u]) {
        if (x == p) {
            continue; 
        }
        if (cost[u] < cost[x]) {
            cost[x] = cost[u]; 
        }
        DFSOne(x, u); 
        for (int i = 0; i < 6; i ++) {
            arr[u][i] += arr[x][i]; 
        }
    }
}


void DFSTwo (int u, int p) 
{
    
    if (arr[u][0] - arr[u][2] != arr[u][1] - arr[u][3]) {
        cout << u << " : " << inf << endl; 
        ans[u] = inf; 
        // return; 
    }
    for (auto x: adj[u]) {
        if (x == p) {
            continue; 
        }
        DFSTwo(x, u); 
        // if(ans[x] < inf && ans[u] < inf) {
        cout << u << " is added by " << x << " : " << ans[x] << endl;   
        arr[u][4] -= (arr[x][5] - arr[x][4]); 
        // arr[u][0] += arr[x][2] - arr[x][0];
        // arr[u][1] += arr[x][3] - arr[x][1]; 
        
    }   
    if (arr[u][0] - arr[u][2] != arr[u][1] - arr[u][3]) {
        cout << u << " " << arr[u][5] - arr[u][4] << " finished\n";  
        return; 
    }
    cout << "for " << u << " .. " << arr[u][4] << endl; 

    ans[u] += cost[u] * arr[u][4];
    answer += cost[u] * arr[u][4];
    arr[u][4] = 0; 
    cout << u << " " << ans[u] << endl; 
    return;   
}


void solve ()
{
    DFSOne(1, 0); 
    if (arr[1][0] - arr[1][2] != arr[1][1] - arr[1][3]) {
       cout << -1 << endl; exit(0); 
        // return; 
    }
    for (int i = 1; i <= n; i ++) {
        cout << i << " : "; 
        for (int j = 0; j < 5; j ++) {
            cout << arr[i][j] << " "; 
        }
        cout << endl; 
    }
    cout << "\n\n"; 

    DFSTwo(1, 0); 
}

void output ()
{
    for (int i = 1; i <= n; i ++) {
        cout << i << " : " << cost[i] << " " ; 
        for (int j = 0 ; j < 6; j ++) {
            cout << arr[i][j] << " " ; 
        }
        cout << " --> " << ans[i]; 
        cout << endl; 
    }
    if (ans[1] == inf){ 
        cout << -1 << endl; 
        return; 
    }
    cout << ans[1] << endl; 
    
    cout << answer << endl; 
}

int main ()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 

    input ();
    solve (); 
    output (); 
}
