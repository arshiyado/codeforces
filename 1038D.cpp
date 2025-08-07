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
const int maxn = 5e5 + 5; 
ll m[maxn], M[maxn]; 
vector<ll> arr; 
int n; 

void input ()
{
    cin >> n; 
    for(int i = 0; i < n; i ++) {
        int a; cin >> a; 
        arr.pb(a); 
    }
}


void solve ()
{
    m[0] = arr[0]; M[0] = arr[0]; 
    ll s = arr[0]; 
    for (int i = 1; i < n; i ++) {
        m[i] = min(m[i - 1] - arr[i], arr[i] - M[i - 1]);
        M[i] = max(arr[i] - m[i - 1], M[i - 1] - arr[i]); 

        M[i] = max(M[i], s - arr[i]); 
        M[i] = max(M[i], arr[i] - s); 
        m[i] = min(m[i], arr[i] - s); 
        m[i] = min(m[i], s - arr[i]); 

        s += arr[i]; 
    }

    cout << M[n - 1] << endl; 
}



int main ()
{
    IOS; 
    input (); 
    solve (); 
    return 0; 
}