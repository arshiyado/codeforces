#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3 + 5; 
int n, m; 
bool mark[maxn][maxn]; 
string tab[maxn]; 
int arr[4] = {0, 0, 1, -1};
int brr[4] = {1, -1, 0, 0}; 

void input ()
{
    cin >> n >> m; 
    for (int i = 0; i < n; i ++) {
        cin >> tab[i]; 
    }
}

bool inside (int x, int y)
{
    if (x >= 0 && x < n && y >= 0 && y < m) {
        return true; 
    }
    return false; 
}

void DFS (int a, int b)
{
    // cout << "going as " << a << " " << b << endl; 
    mark[a][b] = true; 
    for (int i = 0; i < 4; i ++) {
        int x = a + arr[i], y = b + brr[i]; 
        // cout << "checking " << x << " " << y << endl; 
        if(inside(x, y) && tab[x][y] == '#') {
            if(!mark[x][y]) {
                DFS(x, y); 
            }
        }
        
    }
}

void solve ()
{
    bool whiteRow = true, whiteCol = true; 
    for (int i = 0; i < n; i ++) {
        whiteRow = true; 
        for (int j = 0; j < m; j ++) {
            if (tab[i][j] != '.') {
                whiteRow = false; 
                break; 
            }
        }
        if (whiteRow) {
            break; 
        }
    }
    for (int j = 0; j < m; j ++) {
        whiteCol = true; 
        for (int i = 0; i < n; i ++) {
            if (tab[i][j] != '.') {
                whiteCol = false; 
                break; 
            }
        }
        if(whiteCol) {
            break; 
        }
    }
    
    // cout << "WHITE ROW : " << whiteRow << "\nwhiteCol : " << whiteCol << endl; 
    if ((whiteCol ^ whiteRow) != false) {
        cout << -1 << endl; 
        return; 
    }

    for (int i = 0; i < n; i ++) {
        int cnt = 0; 
        if (tab[i][0] == '#') {
            cnt ++; 
        }
        for (int j = 0; j < m - 1; j ++) {
            if (tab[i][j] != tab[i][j + 1] && tab[i][j + 1] == '#') {
                cnt ++; 
            }
        }
        // cout << "row " << i << " : " << cnt << endl; 
        if (cnt >= 2) {
            cout << -1 << endl; 
            return; 
        }
    }
    // cout << "---\n"; 
    for (int j = 0; j < m; j ++) {
        int cnt = 0; 
        if(tab[0][j] == '#') {
            cnt ++; 
        }
        for (int i = 0; i < n - 1; i ++) {
            if (tab[i][j] != tab[i + 1][j] && tab[i + 1][j] == '#') {
                cnt ++; 
            }
        }
        // cout << "col " << j << " : " << cnt << endl; 
        if (cnt >= 2) {
            cout << -1 << endl; 
            return; 
        }
    }
    // cout << "---\n"; 
    int compCount = 0; 
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < m; j ++) {
            if (!mark[i][j] && tab[i][j] == '#') {
                DFS(i, j);
                compCount ++; 
            }
        }
    }
    cout << compCount << endl; 
}

int main ()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 

    input (); 
    solve (); 
    return 0; 
}