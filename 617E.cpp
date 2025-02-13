#include <bits/stdc++.h>
using namespace std;
const long long maxn = 2e5 + 10; 
const long long inf = 1e18 + 10; 
long long arr[maxn][8]; 
int d[maxn], f[maxn];
long long ans[maxn], cost[maxn]; 
long long fir[maxn][2]; 
long long dif[maxn][2][2]; 
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
        dif[u][d[u]][0] ++; 
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
        dif[u][0][0] += dif[x][0][0]; 
        dif[u][1][0] += dif[x][1][0];  

    }
}


void DFSTwo (int u, int p) 
{
    for (auto x: adj[u]) {
        if (x == p) {
            continue; 
        }
        DFSTwo(x, u); 
        dif[u][0][1] -= dif[x][0][0] - dif[x][0][1]; 
        dif[u][1][1] -= dif[x][1][0] - dif[x][1][1]; 
    }   
    if (dif[u][0][1] != dif[u][1][1]) {
        int m = min(dif[u][0][1], dif[u][1][1]); 
        if (m <= 0) {
            return; 
        }
        answer += (2 * m * cost[u]); 
        dif[u][0][1] -= m; 
        dif[u][1][1] -= m; 
        // cout << u << " " << m << " finished\n";  
        return; 
    }
    // cout << "for " << u << " .. " << arr[u][5] - arr[u][4] << endl; 
    answer += cost[u] * dif[u][0][1] * 2;
    dif[u][0][1] = 0; 
    dif[u][1][1] = 0; 
    // cout << u << " " << ans[u] << endl; 
    return;   
}


void solve ()
{
    DFSOne(1, 0); 
    
    // cout << "###### " << dif[1][0] << " " << dif[1][0] << endl;
    // for (int i = 1; i <= n; i ++) {
    //     cout << i << " : " << cost[i] << " "; 
    //     for (int j = 0; j < 5; j ++) {
    //         cout << arr[i][j] << " "; 
    //     }
    //     cout << endl; 
    // }
    // cout << "\n\n"; 
    if (dif[1][0][0] != dif[1][1][0]) {
       cout << -1 << endl; exit(0); 
        // return; 
    }
    for (int i = 1; i <= n; i ++) {
        dif[i][0][1] = dif[i][0][0]; 
        dif[i][1][1] = dif[i][1][0]; 
    }
    DFSTwo(1, 0); 
}

void output ()
{
    // for (int i = 1; i <= n; i ++) {
    //     cout << i << " : " << cost[i] << " " ; 
    //     for (int j = 0 ; j < 6; j ++) {
    //         cout << arr[i][j] << " " ; 
    //     }
    //     cout << " --> " << ans[i]; 
    //     cout << endl; 
    // }
    // if (ans[1] == inf){ 
    //     cout << -1 << endl; 
    //     return; 
    // }
    // cout << ans[1] << endl; 
    
    cout << answer << endl; 
}

int main ()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 

    input ();
    solve (); 
    output (); 
}