#include <bits/stdc++.h>
using namespace std;
int n; 
void input ()
{   
    cin >> n; 
}
int ask (int l, int r)
{
    cout << "? " << l << " " << r << endl; 
    int x; 
    cin >> x; 

    return x; 
}
int main ()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 
    input (); 
    int x = ask(1, n); 
    if (x == 1 || ask(1, x) != x) {
        int l = x, r = n; 
        while (l + 1 < r) {
            int m = (l + r) / 2; 
            int a = ask(x, m); 
            if (a == x) {
                r = m;
            }
            else {
                l = m; 
            }
        }
        cout << "! " << r << endl; 
    }
    else{
        int l = 1, r = x; 
        while (l + 1 < r) {
            int m = (l + r) / 2; 
            int a = ask(m, x); 
            if (a == x) {
                l = (m); 
            }
            else {
                r = m ; 
            }
        }
        cout << "! " << l << endl; 
    } 
    return 0; 
}
