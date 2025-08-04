#include <bits/stdc++.h>
using namespace std; 

#define ll long long

ll n; 
vector<ll> p; 
vector<ll> s; 

void input ()
{
    cin >> n; 
    for (ll i = 0;i < n ;i ++) {
        ll a; cin >> a; 
        p.push_back(a); 
    }
    for (ll i = 0;i < n ;i ++) {
        ll a; cin >> a; 
        s.push_back(a); 
    }
}


void solve ()
{
    if (s[0] != p[n - 1]) {
        cout << "NO\n"; 
        return; 
    }
    for (ll i = 1; i < n; i ++) {
        if (p[i - 1] % p[i]) {
            cout << "NO\n"; 
            return; 
        }
    }
    for (ll i = 0; i < n - 1; i ++) {
        if (s[i + 1] % s[i]) {
            cout << "NO\n"; 
            return; 
        }
    }


    vector<ll> ans; 
    for (ll i = 0; i < n; i ++) {
        ans.push_back(lcm(p[i], s[i])); 
    }

    for (ll i = 1; i < n; i ++) {
        
        if (gcd(ans[i]/p[i], p[i - 1]/p[i]) != 1) {
            cout << "NO\n"; 
            return; 
        }
    }
    for (ll i = 0; i < n - 1; i ++) {
        ll y = s[i + 1]/s[i]; 
        if (gcd(ans[i]/s[i], s[i + 1]/s[i]) != 1) {
            cout << "NO\n"; 
            return; 
        }
    }
    cout << "YES\n"; 
    return; 
}

int main ()
{

    ll t;
    cin >> t;
    while (t--) {
        input ();
        solve (); 
        p.clear(); 
        s.clear(); 
    }
}



// A : gcd (A, p_i-1) = pi
// A : gcd (A, s_i+1) = si 

// x = pi-1/pi
// y = si+1/si

// A = pi * w  -> gcd(x, w) = 1
// A = si * z  -> gcd(y, z) = 1 

// A = lcm(pi, si) 

