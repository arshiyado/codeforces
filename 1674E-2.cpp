#include <bits/stdc++.h>
using namespace std;

int n; 
vector<long long> arr; 
void input ()
{
    cin >> n; 
    for (int i = 0; i < n; i ++) {
        long long a; cin >> a; 
        arr.push_back(a); 
    }
}

long long oneDif ()
{
    long long ret = 100000000; 
    for (int i = 0 ; i < n - 2; i ++) {
        long long q = arr[i] + arr[i + 2]; 
        ret = min(ret, (q + 1)/2); 
    }
    return ret; 
}
long long moreDif ()
{
    long long ret = 100000000; 

    sort(arr.begin(), arr.end()); 
    ret = (arr[1] + 1)/2; 
    ret += (arr[0] + 1)/2; 
    return ret; 
}
long long noDif()
{
    long long ret = 10000000; 
    for (int i = 0; i < n - 1; i ++) {
        if (arr[i] >= 2 * arr[i + 1]) {
            ret = min(ret, (arr[i] + 1)/2); 
        }
        else if (arr[i + 1] >= 2 * arr[i]) {
            ret = min(ret, (arr[i + 1] + 1)/2); 
        }
        else {
            ret = min(ret, (arr[i] + arr[i + 1] + 2)/3); 
        }
    }
    return ret; 

}
void solve ()
{
    long long x = oneDif(), y = noDif(), z = moreDif(); 

    long long ans = min(x, y); 
    ans = min(ans, z); 
    cout << ans << endl; 
}

int main ()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 

    input (); 
    solve (); 
 
    return 0; 
}