#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 5; 
vector<int> arr; 
pair<int,int> ind[maxn]; 
int q;
int rep[maxn]; 
vector<pair<int,int>> vec; 
void input ()
{
    cin >> q; 
    for (int i = 0; i < maxn; i ++) {
        rep[i] = i; 
    }
    for (int i = 0; i < q; i ++ ) {
        int p; 
        cin >> p; 
        if (p == 1) {
            int a; 
            cin >> a; 
            vec.push_back({-1, a}); 
        }
        else {
            int x, y; 
            cin >> x >> y; 
            vec.push_back({x, y}); 
        }
    }
}
void solve ()
{
    reverse(vec.begin(), vec.end()); 
    // cout << "\n\n\n"; 
    deque<int> deq; 

    // for (int i = 0; i < 10; i ++) {
    //     cout << i << " : " << rep[i] << "\n"; 
    // }
    for (auto p: vec) {
        int x = p.first, y = p.second; 
        // cout << x << " " << y << endl; 
        if (x == -1) {
            // cout << "printing : " << y << " : " << rep[y] << endl; 
            deq.push_front(rep[y]); 
            continue; 
        }
        else {
            // cout << x << " is changing to " << rep[y] <<"\n";  
            rep[x] = rep[y]; 
        }
    }
    for (auto x: deq) {
        cout << x << " " ; 
    }
    cout << "\n"; 
}   
int main ()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 
    input (); 
    solve (); 
}