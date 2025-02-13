#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10; 
int n, m; 
long long seg[4 * maxn], mex[4 * maxn];

void pound (int pos) 
{
    seg[pos] = seg[2 * pos + 1] + seg[2 * pos + 2]; 
    mex[pos] = max(mex[2 * pos + 1], mex[2 * pos + 2]); 
}

void build (int l, int r, int pos)
{
    if (l > r) {
        return; 
    }
    if (l == r) {
        cin >> seg[pos]; 
        mex[pos] = seg[pos]; 
        return; 
    }
    int m = (l + r) / 2; 
    build (l, m, 2 * pos + 1); 
    build (m + 1, r, 2 * pos + 2); 

    pound(pos); 
    return; 
}   

void update (int l, int r, int ql, int qr, int pos, long long mod)
{
    if (l > r || ql > r || qr < l || mex[pos] < mod) {
        return; 
    }   

    if (l == r) {
        seg[pos] = (mex[pos] %= mod); 
        
        return; 
    }

    int m = (l + r) / 2; 
    update(l, m, ql, qr, 2 * pos + 1, mod); 
    update(m + 1, r, ql, qr, 2 * pos + 2, mod); 

    pound (pos); 
}

void change (int l, int r, int pos, int ind, long long val)
{
    if (l > r || ind > r || ind < l) {
        return; 
    }

    if (l == r && l == ind) {
        seg[pos] = val; 
        mex[pos] = val; 
        return; 
    }
    int m = (l + r) / 2; 
    change (l, m, 2 * pos + 1, ind, val); 
    change (m + 1, r, 2 * pos + 2, ind, val); 

    pound(pos); 
    

    return; 


}      

long long getSum (int l, int r, int ql, int qr, int pos)
{
    if (l > r || ql > r || qr < l) {
        return 0; 
    }
    if (ql <= l && r <= qr) {
        return seg[pos]; 
    }
    int m = (l + r) / 2; 
    return (getSum(l, m, ql, qr, 2 * pos + 1) + getSum(m + 1, r, ql, qr, 2 * pos + 2)); 
}

int main ()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 
    cin >> n >> m; 

    build(0, n - 1, 0); 

    for (int i = 0; i < m; i ++) {
        int t; 
        cin >> t; 
        if (t == 1) {
            int l, r; 
            cin >> l >> r; 
            l --, r --; 
            cout << getSum(0, n - 1, l, r, 0) << endl; 
        }
        else if (t == 2) {
            int l, r, x; 
            cin >> l >> r >> x; 
            l -- , r --; 
            update(0, n - 1, l, r, 0, x); 
        }
        else if (t == 3) {
            int ind, x; 
            cin >> ind >> x; 
            ind --; 
            change(0, n - 1, 0, ind, x); 
        }
    }   

}