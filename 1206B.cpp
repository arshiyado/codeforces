#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3; 
const int inf = 4e9; 
int n, m; 

vector<int> adj[maxn]; 
bool mark[maxn]; 
void input ()
{
    cin >> n >> m; 
    for (int i = 0; i < m;i  ++) {
        int u, v; 
        cin >> u >> v; 
        adj[u].push_back(v); 
        adj[v].push_back(u); 
    }
}


void BFS (int s)
{
    int dist[n]; // distance  
    // memset(dist, 0, sizeof(dist)); 
    // vector deque queue stack   
    for (int i = 0; i < n; i ++) {
        dist[i] = inf; 
    }
    dist[s] = 0; 
    queue<int> que; 
    que.push(s); 
    mark[s] = true; 

    while (!que.empty()) {
        int u = que.front(); 
        que.pop();         
        for (auto x : adj[u]) {
            if (mark[x]) {
                continue; 
            }
            else {
                dist[x] = dist[u] + 1; 
                que.push(x); 
            }
        }
    }

}

int main ()
{

}