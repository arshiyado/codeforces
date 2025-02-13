#include <bits/stdc++.h>
using namespace std;
int n; 
vector<int> arr, moves; 
void input () 
{
    arr.clear(); 
    moves.clear(); 
    cin >> n; 
    for (int i = 0; i < n; i ++) {
        int x; 
        cin >> x; 
        arr.push_back(x); 
    }
}
bool check ()
{
    for (int i = 0; i < n - 1; i ++) {
        if(arr[i] > arr[i + 1]) {
            return false; 
        }
    }
    return true; 
}
int findMex() 
{
    bool mark[n + 1]; 
    memset(mark, false, sizeof(mark)); 
    for (auto x: arr) {
        mark[x] = true; 
    }
    for (int i = 0; i <= n; i ++) {
        if(!mark[i]) {
            return i; 
        }
    }
    return n; 
}
void output ()
{
    cout << moves.size() << endl; 
    for (auto x: moves) {
        cout << x + 1 << " " ; 
    }
    cout << endl; 
}
void solve ()
{
    int ind = 0; 
    bool mark[n + 10]; 
    for (int i = 0; i <= n; i ++) {
        mark[i] = false; 
    }
    for (int i = 0; i < n; i ++) {
        mark[arr[i]] = true; 
    }

    while (!check()) {
        
        int mex = findMex(); 
        if(mex == n) {
            for (int i = 0; i < n; i ++) {
                if (arr[i] != i) {
                    arr[i] = n; 
                    moves.push_back(i); 
                    break; 
                }
            }
        }
        else {
            arr[mex] = mex; 
            moves.push_back(mex); 
        }
    }
}
int  main ()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 


    int t;
    cin >> t;
    while (t--) {
        input ();
        solve (); 
        output (); 
    }
    return 0; 
}