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

class DSU {

    
    public: 
    vector<int> par; 
    vector<int> rnk; 
    
    DSU (int n) {
        par.resize(n); 
        rnk.resize(n); 
        for (int i = 0; i < n; i ++) {
            par[i] = i; 
            rnk[i] = 1; 
        }
    }


    int findP (int u) {
        if (par[u] == u) {
            return u; 
        }
        return par[u] = findP(par[u]); 
    }


    void unite (int u, int v) {
        int p = findP(u); 
        int q = findP(v); 

        if (p == q) {
            // already in same cmp 
            return; 
        }
        if (rnk[p] < rnk[q]) 
            swap(p, q); 

        rnk[p] += rnk[q]; 
        par[q] = p; 
    }

    bool same (int u, int v) {
        return findP(u) == findP(v);
    }

    

}; 

int n; 
DSU *dsu; 
vector<pair<int,int>> edge; 
void input ()
{
    cin >> n; 
    dsu = new DSU(n); 
    for (int i = 0; i < n - 1; i ++) {
        int a, b; 
        cin >> a >> b; 
        a --, b --; 
        if (dsu->same(a, b)) {
            edge.pb({a, b}); 
        }
        else {
            dsu->unite(a, b); 
        }
    }
}

void solve ()
{
    vector<int> roots; 
    for (int i = 0; i < n; i ++) {
        if (dsu->par[i] == i) {
            roots.pb(i); 
        }
    }
    cout << edge.size() << "\n"; 
    
    for (int i = 0; i < edge.size(); i ++) {
        cout << edge[i].first + 1 << " " << edge[i].second + 1 << " " << roots[0] + 1 << " " << roots[i + 1] + 1 << " " << endl; 
    }
}

int main ()
{
    IOS; 

    input (); 
    solve (); 
}