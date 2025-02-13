#include <bits/stdc++.h>
#define pb push_back
#define pf push_front
#define qb pop_back
#define qf pop_front
#define ll long long
using namespace std;
#define IOS ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 
const int maxn = 1e6 + 5; 
int ans = 0; 
int n, q;
int seg[5 * maxn], cnt[maxn]; 
void input ()
{
    cin >> n >> q; 
    for (int i = 0; i < n; i ++) {
        int a; cin >> a; 

        cnt[a] ++; 
    }
}

void build (int l, int r, int pos) 
{
    if (l > r) {
        return; 
    }
    if (l == r) {
        seg[pos] = cnt[l]; 
        return; 
    }
    int m = (l + r) / 2; 
    build (l, m, 2 * pos + 1);
    build (m + 1, r, 2 * pos + 2); 
    seg[pos] = seg[2 * pos + 1] + seg[2 * pos + 2]; 
    return; 
}
int sumQue (int l, int r, int ql, int qr, int pos) 
{
    if (l > r || qr < l || ql > r) {
        return 0; 
    }
    if (ql <= l && r <= qr) {
        return seg[pos]; 
    }
    int m = (l + r) / 2; 
    return (sumQue(l, m, ql, qr, 2 * pos + 1) + sumQue(m + 1, r, ql, qr, 2 * pos + 2)); 
}
void update (int l, int r, int ql, int qr, int pos, int val)
{
    if (l > r || ql > r || qr < l) {
        return; 
    }
    if (ql <= l && r <= qr) {
        seg[pos] += val; 
        return; 
    }
    int m = (l + r) / 2; 
    update (l, m, ql, qr, 2 * pos + 1, val); 
    update (m + 1, r, ql, qr, 2 * pos + 2, val); 
    seg[pos] = seg[2 * pos + 1] + seg[2 * pos + 2]; 
    return; 
}
int query (int l, int r, int val, int pos, int pre)
{
    if (l == r) {
        return l; 
    }
    int m = (l + r) / 2; 
    if (pre + seg[2 * pos + 1] >= val) { 
        return query(l, m, val, 2 * pos + 1, pre); 
    }
    else {
        return query(m + 1, r, val, 2 * pos + 2, pre + seg[2 * pos + 1]); 
    }
}
void process ()
{
    for (int i = 0; i < q; i ++) {
        int a; cin >> a; 
        if (a > 0) {
            cnt[a] ++; 
            update (1, n, a, a, 0, 1); 
        }
        else {
            a *= -1; 
            int p = query(1, n, a, 0, 0); 
            // cout << p << endl; 
            cnt[p] --; 
            update(1, n, p, p, 0, -1); 
        }
    }
}
void output ()
{
    for (int i = 1; i <= n; i ++) {
        if (cnt[i] != 0) {
            cout << i << endl;
            return; 
        }
    }
    cout << 0 << endl; 
    return; 
}
int main ()
{
    IOS; 
    input (); 
    build(1, n, 0); 
    process (); 
    output (); 
}