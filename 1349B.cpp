#include <bits/stdc++.h>
using namespace std;
vector<int> arr;
int n, k; 
void input ()
{
    arr.clear(); 
    cin >> n >> k; 
    for (int i = 0; i < n; i ++) {
        int a;
        cin >> a; 
        arr.push_back(a); 
    }
}
void solve ()
{
    bool find = false, match = false; 
    for (int i = 0; i < n; i ++) {
        if(arr[i] == k) {
            find = true; 
            break; 
        }
    }
    if(n == 1 && arr[0] == k ){
        cout << "yes" << endl; 
        return; 
    } 
    for (int i = 0; i < n - 1; i ++) {
        if(arr[i] >= k  && arr[i + 1] >= k) {
            match = true; 
            break; 
        }
    }
    for (int i = 0; i < n - 2; i ++) {
        if(arr[i] >= k && arr[i + 2] >= k) {
            match = true; 
            break; 
        }
    }
    // cout << "find : " << find << " , match :  " << match << "\n";  
    if(match && find) {
        cout << "yes\n"; 
    }
    else {
        cout << "no\n"; 
    }
    return; 
}
int main ()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 
    int t;
    cin >> t;
    while (t--) {
        input (); 
        solve (); 
    }
}