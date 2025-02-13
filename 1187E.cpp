#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10; 
long long answer = 0; 
int n; 
vector<int> adj[maxn]; 
vector<long long> ans, siz; 
void input ()
{
    cin >> n; 
    siz = vector<long long>(n); 
    ans = vector<long long>(n); 
    for (int i = 0; i < n - 1; i ++) {
        int u, v; 
        cin >> u >> v; 
        --u; --v; 
        adj[u].push_back(v); 
        adj[v].push_back(u); 
    }
}

void sizeCal (int u, int p) 
{
    siz[u] = 1; 
    for (auto x: adj[u]) {
        if (x == p) {
            continue; 
        }
        sizeCal(x, u); 
        siz[u] += siz[x]; 
    }
    return; 
}

void ansCal (int u, int p)
{
    ans[u] = siz[u]; 
    for (auto x : adj[u]) {
        if (x == p) {
            continue; 
        }
        ansCal(x, u); 
        ans[u] += ans[x]; 
    }
    return; 
}

void DFS (int u, int p)
{
    // answer = max(answer, ans[u]); 
    for (auto x: adj[u]) {
        if (x == p) {
            continue; 
        }
        ans[u] -= ans[x]; 
        ans[u] -= siz[x]; 
        siz[u] -= siz[x]; 
        siz[x] += siz[u]; 
        ans[x] += siz[u]; 
        ans[x] += ans[u]; 
        DFS(x, u);  
    }
}

void printAns ()
{
    for (int i = 0; i < n; i ++) {
        answer = max(answer, ans[i]); 
    }
    cout << answer << endl; 
}


int main ()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 

    input ();  
    sizeCal(0, -1); 
    ansCal(0, - 1); 
    DFS (0, -1); 
    cout << answer << endl; 
}