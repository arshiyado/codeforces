#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10, inf = 1e9 + 7; 
int seg[maxn * 5], rmq[maxn * 5]; 
int n, t; 
vector<int> arr; 
unordered_map <int, vector<int>> vec; 
void input ()
{
    for (int i = 0; i < maxn * 5; i ++){
        rmq[i] = inf; 
    }
    cin >> n; 
    for (int i = 0; i < n; i ++ ) {
        int a; 
        cin >> a; 
        arr.push_back(a); 
        vec[a].push_back(i); 
    }

}
int occurrences(int l, int r, int x) 
{
    return lower_bound(vec[x].begin(), vec[x].end(), r + 1) - lower_bound(vec[x].begin(), vec[x].end(), l);
}
void buildSeg (int l, int r, int pos)
{
    if (l > r) {
        return; 
    }
    if (l == r) {
        seg[pos] = arr[l]; 
        return; 
    }
    int m = (l + r) / 2; 
    buildSeg(l, m, 2 * pos + 1); 
    buildSeg(m + 1, r, 2 * pos + 2); 
    seg[pos] = gcd(seg[2 * pos + 1], seg[2 * pos + 2]); 
    return; 
}
void buildRmq (int l, int r, int pos)
{
    if (l > r) {
        return; 
    }
    if (l == r) {
        rmq[pos] = arr[l]; 
        return; 
    }
    int m = (l + r) / 2; 
    buildRmq(l, m, 2 * pos + 1); 
    buildRmq(m + 1, r, 2 * pos + 2); 
    rmq[pos] = min(rmq[2 * pos + 1], rmq[2 * pos + 2]); 
    return; 
}

int segQue (int l, int r, int ql, int qr, int pos) 
{
    if (l > r || ql > r || qr < l) {
        return 0; 
    }
    if (ql <= l && r <= qr) {
        return seg[pos]; 
    }
    int m = (l + r) / 2; 
    return (gcd(segQue(l, m, ql, qr, 2 * pos + 1), segQue(m + 1, r, ql, qr, 2 * pos + 2))); 
}
int rmqQue (int l, int r, int ql, int qr, int pos)
{
    if(l > r || ql > r || qr < l) {
        return inf; 
    }
    if (ql <= l && r <= qr) {
        return rmq[pos]; 
    }
    int m = (l + r) / 2; 
    return min(rmqQue(l, m, ql, qr, 2 * pos + 1), rmqQue(m + 1, r, ql, qr, 2 * pos + 2)); 
}

void solve ()
{
    cin >> t; 
    for (int i = 0; i < t; i++) {
        int l, r; 
        cin >> l >> r; 
        l--; r --; 
        int g = segQue(0, n - 1, l, r, 0); 
        int m = rmqQue(0, n - 1, l, r, 0); 
        // cout << "gcd : " << g << "\nminimum : " << m << endl; 
        if (g != m) {
            cout << r - l + 1 << endl; 
            continue; 
        }
        else { 
            int o = occurrences(l, r , m);
            cout << r - l + 1 - o << endl; 
        }
    }
    return; 
}
int main ()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 
    input (); 
    buildRmq(0, n - 1, 0);
    buildSeg(0, n - 1, 0); 
    solve (); 
    return 0; 
}