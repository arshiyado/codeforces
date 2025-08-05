#include <bits/stdc++.h>
using namespace std;
#define IOS ios:: sync_with_stdio(false); cin.tie(NULL); //.tie(NULL); 
#define ll long long 
#define ld long double 
#define pb push_back
#define pf push_front
#define qf pop_front
#define qb pop_back
#define S second 
#define F first

int n; 


void input ()
{
    cin >> n; 
}

void solve ()
{
    string s; 
    if (n == 1) {
        cout << "a\n"; 
        return;  
    }
    s = ""; 
    if (n % 2 == 0) {
        for (int i = 0; i < n/2; i ++) {
            s += 'a'; 
        }
        s += 'b'; 
        for (int i = 0; i < n/2 - 1; i ++) {
            s += 'a'; 
        }
    }
    else {
        for (int i = 0; i < n/2; i ++) {
            s += 'a'; 
        }
        s += 'b'; 
        for (int i = 0; i < n/2 - 1; i ++) {
            s += 'a'; 
        }
        s += 'c'; 
    }
    cout << s << "\n"; 
}

int main ()
{
    IOS; 
    int t; cin >> t; 

    while (t--) {
        input ();
        solve (); 
    }
}