#include <bits/stdc++.h>
using namespace std;
int n, m; 
char tab[100][100]; 
void input ()
{
    cin >> n >> m; 
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < m; j ++) {
            cin >> tab[i][j]; 
        }
    }
}

void solve ()
{
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < m; j ++) {
            if (tab[i][j] == '-') {
                continue; 
            }
            if ((i + j) % 2) {
                tab[i][j] = 'B'; 
            }
            else {
                tab[i][j] = 'W'; 
            }
        }
    }
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < m; j ++) {
            cout << tab[i][j]; 
        }
        cout <<"\n"; 
    }
}

int main ()
{
    input ();
    solve (); 
}