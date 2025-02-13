#include <bits/stdc++.h>
using namespace std;
int n; 
vector<int> arr; 
void input ()
{
    cin >> n; 
    for (int i = 0; i < n; i ++) {
        int a;
        cin >> a; 
        arr.push_back(a); 
    }
    for (int i = 0; i < n; i ++) {
        arr.push_back(arr[i]); 
    }
}
void solve ()
{
    
}
int main ()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 

    input (); 
}