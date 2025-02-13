#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10; 
vector<int> adj[maxn]; 
int n; 
char ans[maxn]; 
int sze[maxn]; 
bool flag[maxn]; 
void input ()
{
    cin >> n; 
    for (int i = 0; i < n - 1; i ++) {
        int u, v; 
        cin >> u >> v; 
        adj[u].push_back(v); 
        adj[v].push_back(u); 
    }
    // cout << "finished\n"; 
}


int getSize (int u, int p)
{
    if(flag[u]) {
        sze[u] = 0; 
        return 0; 
    }
    sze[u] = 1; 
    for (auto x: adj[u]) {
        if (x == p || flag[x]) {
            continue; 
        }
        sze[u] += getSize(x, u); 
    }
    return sze[u]; 
}


int getCentroid (int u, int p, int subSize)
{
    for (auto x : adj[u]) {
        if (flag[x]) {
            continue;
        }
        if(x != p && sze[x] > subSize/2) {
            return getCentroid(x, u, subSize); 
        }
    }
    return u; 
}


void action (int u, int sz, char c)
{
    // cout << "ON : " << u << endl; 
    getSize(u, -1); 
    int v = getCentroid(u, -1, sz); 
    flag[v] = true; 
    // cout << v << endl; 
    ans[v] = c; 

    for (auto x: adj[v]) {
        if(flag[x]) {
            continue; 
        }
        action(x, sze[x], c + 1); 
    }

}
int main ()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 

    input (); 
    action(1, n, 'A'); 
    for (int i = 1; i <= n; i ++) {
        cout << ans[i] << " " ; 
    }
    cout <<endl; 
}