#include <bits/stdc++.h>
using namespace std;

#define IOS ios:: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 
#define ll long long 
#define ld long double 
#define pb push_back
#define pf push_front
#define qf pop_front
#define qb pop_back
#define S second 
#define F first


const int maxn = 2e5 + 5;
ll n; 
vector<ll> a; 
vector<ll> b; 
vector<ll> adj[maxn]; 
deque<int> pos, neg; 
void input ()
{
    cin >> n; 
    for (int i = 0; i < n; i ++) {
        ll p; cin >> p; 
        a.push_back(p); 
    }
    for (int i = 0; i < n; i ++) {
        ll p; cin >> p; 
        b.push_back(p); 
    }
}
void solve ()
{
    ll cnt[n + 1];
    memset(cnt, 0, sizeof(cnt)); 
    for (int i = 0; i < n; i ++) {
        if (b[i] != -1) {
            adj[i + 1].pb(b[i]); 
            cnt[b[i]] += 1; 
        }
    }
    set<pair<ll, ll>> node; 
    for (int i = 1; i <= n; i ++) {
        node.insert({cnt[i], i}); 
    }
    for (auto it = node.rbegin(); it != node.rend(); ++it) {
        
    }
    // cout << node.size() << endl; 
    ll ans = 0; 
    for (int i = 0; i < n; i ++) {
        auto it = node.begin(); 
        // cout << a[it->second - 1] << " " << it->second << endl; 
        ll c = it->F, p = it->S; 
        ans += a[p - 1]; 
        // cout << "ans : " << ans << "\n"; 
        node.erase(*it); 
        if (adj[p].size() == 1) {
            node.erase({cnt[adj[p][0]], adj[p][0]}); 
            cnt[adj[p][0]]--; 
            // cout << "next: " << adj[p][0] << endl; 
            node.insert({cnt[adj[p][0]], adj[p][0]}); 
            if (a[p - 1] >= 0) {
                a[adj[p][0] - 1] += a[p - 1];    
                pos.pb(p); 
            }
            else {
                neg.pb(p); 
            }
        }
        else {
            if (a[p - 1] >= 0) {
                
                pos.pb(p); 
            }
            else {
                neg.pb(p); 
            }
        }
        // cout << "---------------------\n"; 
    }
    cout << ans << endl; 
    for (auto x: pos) {
        cout << x << " " ; 
    }
    reverse(neg.begin(), neg.end()); 
    for (auto x: neg) {
        cout << x << " " ; 
    }
    cout << "\n"; 
}

int main ()
{
    IOS; 
    input ();
    solve (); 
}