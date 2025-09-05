#include <bits/stdc++.h>
using namespace std;

#define IOS                      \
    ios::sync_with_stdio(false); \
    cin.tie(NULL);               \
    cout.tie(NULL);
#define ll long long
#define ld long double
#define pb push_back
#define pf push_front
#define qf pop_front
#define qb pop_back
#define S second
#define F first
int n, m; 
int k; 
const int maxn = 510; 
char tab[maxn][maxn]; 

int p, q; 
deque<pair<int, int>> cells; 
bool mark[maxn][maxn]; 
void input ()
{
    cin >> n >> m >> k; 
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < m; j ++) {
            cin >> tab[i][j]; 
            if (tab[i][j] != '#'){
                p = i; q = j; 
            }
        }
    }
    // cout << "end\n"; 
}

bool inside (int x, int y) 
{
    if (x < 0 || x >= n || y < 0 || y >= m) {
        return false; 
    }   
    return true; 
}
int xs[4] = {1, -1, 0, 0}; 
int ys[4] = {0, 0,  1, -1}; 

void DFS (int x, int y)
{
    cells.pf({x, y}); 
    // cout << x << " " << y << "\n"; 
    mark[x][y] = true; 
    for (int i = 0; i < 4; i ++) {
        int a, b; 
        a = x + xs[i]; 
        b = y + ys[i]; 
        if (inside(a, b) && tab[a][b] != '#' && !mark[a][b]) {
            DFS(a, b); 
        }
    }
}

void solve ()
{
    DFS(p, q); 
    for (int i = 0; i < k; i ++) {
        tab[cells[i].F][cells[i].S] = '#';    
    }
    // cout << "end DFS\n"; 
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < m; j ++) {
            cout << tab[i][j]; 
        }
        cout << "\n"; 
    }
}

int main ()
{
    IOS; 
    input ();
    solve (); 
}