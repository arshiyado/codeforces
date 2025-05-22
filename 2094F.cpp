#include <bits/stdc++.h>
using namespace std;
int n, m, k; 
void input ()
{
    cin >> n >> m >> k; 
}
void solve ()
{
    if (m % k == 0) {
        int x; 
        for (int i = 0; i < n; i ++) {
            if (i % 2 == 0) {
                x = 1; 
            } 
            else {
                x = 2; 
            }
            for (int j = 0; j < m; j ++) {
                cout << x << " " ; 
                x += 1; 
                if (x == k + 1) {
                    x = 1; 
                } 
            }
        }
        return; 
    }
    int x = 1; 
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < m; j ++) {
            cout << x << " " ; 
            x += 1; 
            if (x == k + 1) {
                x = 1; 
            }
        }
        cout << "\n"; 
    }
}
int main ()
{
    int t;
    cin >> t; 
    while (t--) {
        input ();
        solve (); 
    }   
}