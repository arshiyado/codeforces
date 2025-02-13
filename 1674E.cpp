#include <bits/stdc++.h>
using namespace std;

int n; 
vector <int> arr; 

void input ()
{
    cin >> n; 
    for (int i = 0; i < n; i ++) {
        int a; 
        cin >> a; 
        arr.push_back(a); 
    }
    // cout << "ENDED\n"; 
}

int binarySearch(int x, int y) 
{
    int l = 0, r = x + y; 
    int ans; 
    while (l < r) {
        cout << l << " " << r << endl; 
        int m = (l + r) / 2; 
        int q = (x - 2 * m), p = y - m;
        int t = (p + 1) / 2; 
        q -= t; 
        if (q > 0) {
            l = m + 1; 
        } 
        else {
            r = m; 
        }

    }
    cout << r << "\n---\n"; 
    return r; 
}

int notAdj ()
{
    int m1 = 1e6 + 1, m2 = 1e6 + 1; 
    for (auto x: arr) {
        if (x <= m1) {
            swap(m1, m2); 
            m1 = x; 
        }
        else if (x < m2) {
            m2 = x; 
        }
    }
    // cout <<"NOTADJ\n";  
   return (m1 + 1)/2 + (m2 + 1)/2;  
}

int oneAdj ()
{
    int ret = 100000000; 
    for (int i = 0 ; i < n - 2; i ++) {
        int q = arr[i] + arr[i + 2]; 
        ret = min(ret, (q + 1)/2); 
    }
    return ret; 
}

int isAdj ()
{
    int ans = 2e6 + 1; 
    for (int i = 0; i < n - 1; i ++) {
        ans = min(ans, binarySearch(arr[i], arr[i + 1])); 
    }
    cout << "---\n"; 
    for (int i = n - 1; i >= 1; i --) {
        ans = min(ans, binarySearch(arr[i], arr[i - 1])); 
    }
    // cout << "ISADJ()\n"; 
    return ans; 
}

void solve ()
{
    cout << min(min(notAdj(), isAdj()), oneAdj()) << "\n"; 
    
}
int main ()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL); 

    input (); 
    solve (); 
}