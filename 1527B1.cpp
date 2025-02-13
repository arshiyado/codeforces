#include <bits/stdc++.h>
using namespace std;
void solve ()
{
    int n; 
    cin >> n; 
    string s; 
    cin >> s; 
    int cnt = 0; 
    for (int i = 0; i < n; i ++) {
        if(s[i] == '0') {
            cnt ++; 
        }
    }
    if (cnt == 1 || cnt % 2 == 0) {
        cout << "BOB\n"; 
    }
    else {
        cout << "ALICE\n"; 
    }
    return; 
}
int main ()
{
    int t;
    cin >> t;
    while (t--) {
        solve (); 
    }
}