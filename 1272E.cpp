#include <bits/stdc++.h>
#include <vector>
using namespace std;
const int maxn = 2e5 + 10; 
vector<int> adj[maxn]; 
bool mark[maxn]; 
vector <int> arr; 
int n; 
int dist[maxn], lent[maxn]; 
void input ()
{   
    arr.push_back(0); 
    cin >> n; 
    for (int i = 0; i < n; i ++) {
        int a; 
        cin >> a; 
        arr.push_back(a); 
    }
}
deque<int> deq; 
void BFS (int m)
{
    deq.clear(); 
    for (int i = 1; i <= n; i ++) {
        dist[i] = 1e9; 
    }
    memset(mark, false, sizeof(mark)); 
    for (int i = 1; i <= n; i ++) {
        if(arr[i] % 2 == m) {
            deq.push_front(i);
            mark[i] = true;  
            dist[i] = 0; 
        }
    }
    // for (auto x: deq) {
    //     cout << x << " "; 
    // }
    // cout << endl; 
    while (!deq.empty()) {
        int a = deq[0]; 
        mark[a] = true; 
        // cout << a << " : " ; 
        deq.pop_front(); 
        for (auto x: adj[a]) {
            if (mark[x]) {
                dist[x] = min(dist[x], dist[a] + 1); 
                continue; 
            }
            else if(!mark[x]) {
                // cout << x << " " ; 
                deq.push_back(x); 
                dist[x] = dist[a] + 1; 
                mark[x] = true; 
            }
            else {
                continue; 
            }
        }
        // cout << endl; 
    }
}
void preSolve ()
{
    for (int i = 1; i <= n; i ++) {
        if ((i) - arr[i] >= 1) {
            adj[i - arr[i]].push_back(i); 
        }
        if ((i) + arr[i] <= n) {
            adj[arr[i] + i].push_back(i); 
        }
    }
    // for (int i = 1; i <= n; i ++) {
    //     cout << i << ", " << arr[i] <<  " : " ; 
    //     for (auto x: adj[i]) {
    //         cout << x << " " ; 
    //     }
    //     cout << endl; 
    // }
    BFS(1); 
    // for (int i = 1; i <= n; i ++) {
    //     cout << i << ", " << arr[i] << " : " << dist[i] << endl; 
    // }
    for (int i = 1; i <= n; i ++) {
        if (arr[i] % 2 == 0) {
            lent[i] = dist[i]; 
        }
    }

    BFS(0); 
    for (int i = 1; i <= n; i ++) {
        if(arr[i] % 2 == 1) {
            lent[i] = dist[i]; 
        }
    }
}
void output ()
{
    for (int i = 1; i <= n; i ++) {
        // cout << i << " : " << arr[i] << " --> "; 
        if(lent[i] == (1e9)) {
            cout << -1 << " " ;
        }
        else {
            cout << lent[i] << " " ; 
        }
    }
    cout << endl; 
}
int main () 
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 

    input (); 
    preSolve (); 
    output (); 
    return 0; 
}