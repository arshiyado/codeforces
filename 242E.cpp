#include <bits/stdc++.h>
#define pb push_back
#define pf push_front
#define qb pop_back
#define qf pop_front
#define ll long long
using namespace std;
#define IOS ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 
const int maxn = 1e5 + 10, maxb = 21; 
int seg[10 * maxn][maxb + 3]; 
int lazy[10 * maxn]; 
void build (int l, int r, int pos) 
{
    if (l > r) {
        return; 
    }
    if (l == r) {
        int p; 
        cin >> p; 
        for (int i = 0; i < 20; i ++) {
            
            seg[pos][i] = (((1<<i) & p) ? 1 : 0); 
            
        }
        return; 
    }
    int m = (l + r) / 2; 
    build (l, m, 2 * pos + 1); 
    build (m + 1, r, 2 * pos + 2);
    for (int i = 0; i < 20; i ++) {
        seg[pos][i] = (seg[2 * pos + 1][i] + seg[2 * pos + 2][i]); 
    } 
    // cout << endl; 
    return;  

}
void update (int l, int r, int ql, int qr, int pos, int val)
{
    
    if (l > r) {
        return; 
    }
    else if ((ql > r || qr < l)) {
        if (lazy[pos] == 0) {
            return; 
        }
        lazy[2 * pos + 1] ^= lazy[pos]; 
        lazy[2 * pos + 2] ^= lazy[pos]; 
        for (int i = 0; i < 20; i ++) {
            if ((1<<i) & lazy[pos]) {
                seg[pos][i] = (r - l + 1 - seg[pos][i]); 
            }
        }
        lazy[pos] = 0; 
        return; 
    }
    
    if (ql <= l && r <= qr) {
        
        lazy[pos] ^= val; 
        lazy[2 * pos + 1] ^= lazy[pos]; 
        lazy[2 * pos + 2] ^= lazy[pos]; 
        for (int i = 0; i < 20; i ++) {
            if ((1<<i) & lazy[pos]) {
                seg[pos][i] = (r - l + 1 - seg[pos][i]); 
            }

        }
        lazy[pos] = 0; 
        return; 
    }
    int m = (l + r) / 2; 
    lazy[2 * pos + 1] ^= lazy[pos]; 
    lazy[2 * pos + 2] ^= lazy[pos]; 
    lazy[pos] = 0;     
    update (l, m, ql, qr, 2 * pos + 1, val); 
    update (m + 1, r, ql, qr, 2 * pos + 2, val); 
    for (int i = 0; i < 20; i ++) {
        seg[pos][i] = (seg[2 * pos + 1][i] + seg[2 * pos + 2][i]); 
    }
    return; 
}

long long query (int l, int r, int ql, int qr, int pos)
{
    if (l > r || ql > r || qr < l) {
        return 0 ; 
    }
    if (ql <= l && r <= qr) {
        long long ret = 0ll; 
        for (int i = 0; i < 20; i ++) {
            
            ret += 1ll * ((1<<i) * 1ll * seg[pos][i]); 

        }
        return ret; 
    }
    int m = (l + r) / 2; 
    return query (l, m, ql, qr, 2 * pos + 1) + query (m + 1, r, ql, qr, 2 * pos + 2); 
}
int main ()
{
    IOS; 
    int n;
    cin >> n; 
    build(0, n - 1, 0); 
    int m; cin >> m; 
    
    for (int i = 0; i < m; i ++) {
        int t; cin >> t; 
        if(t == 1) {
            int ql, qr; 
            cin >> ql >> qr; 
            ql--; qr--;
            update(0, n - 1, ql, qr, 0, 0); 
            cout << query(0, n - 1, ql, qr, 0) << endl; 
        }
        else if (t == 2) {
            int ql, qr, val; 

            cin >> ql >> qr >> val; 
            ql--; qr--;
            update (0, n - 1, ql, qr, 0, val); 
        }
    }
}