#include <bits/stdc++.h>
using namespace std;
int n; 
int k; 
deque<int> p1, p2; 
void input ()
{
    cin >> n; 
    cin >> k; 
    for (int i = 0; i < k; i ++) {
        int a; cin >> a;
        p1.push_back(a); 
    }
    cin >> k; 
    for (int i = 0; i < k; i ++) {
        int a; cin >> a;
        p2.push_back(a); 
    }
}
void solve ()
{
    int cnt = 0; 
    for (int i = 0; i < n * (n + 1); i ++) {
        if (p1.size() == 0) {
            cout << cnt << " " << 2 << endl; 
            return; 
        }
        else if(p2.size() == 0){
            cout << cnt << " " << 1 << endl; 
            return; 
        }

        int a1 = p1.front(), a2 = p2.front();
        p1.pop_front(); p2.pop_front(); 
        if (a1 > a2){
            p1.push_back(a2); p1.push_back(a1); 
        } 
        else{
            p2.push_back(a1); p2.push_back(a2); 
        } 
        cnt += 1; 
    }
    cout << -1 << endl; 
}
int main ()
{
    input ();
    solve (); 
}