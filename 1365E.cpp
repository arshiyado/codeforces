#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e2 + 10, maxp = 60; 
int n; 

vector<long long> arr; 
bool mark[maxn]; 
void input ()
{
    cin >> n;
    for (int i = 0; i < n; i ++) {
        long long a; 
        cin >> a; 
        arr.push_back(a); 
    }
}
void solve ()
{
    long long ans = 0ll; 
    for (int i = 0; i < n; i ++) {
        ans = max(arr[i], ans); 
    }
    for (int i = 0; i < n; i ++) {
        for (int j = i + 1; j < n; j ++) {
            ans = max(ans, arr[i] | arr[j]); 
        }
    }
    for (int i = 0; i < n; i ++) {
        for (int j = i + 1; j < n; j ++) {
            for (int k = j + 1; k < n; k ++) {
                ans = max(ans, arr[i] | arr[j] | arr[k]); 
            }
        }
    }
    cout << ans << endl; 
}
int main ()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL); 
    input (); 
    solve (); 
    return 0;  
}