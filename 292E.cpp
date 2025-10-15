#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long
#define ld long double
#define pb push_back
#define pf push_front
#define qf pop_front
#define qb pop_back
#define S second
#define F first

vector<int> arr; 
vector<int> brr; 
int n, m; 
const int maxn = 3e5 + 10; 
vector<int> seg(4 * maxn); 
vector<int> lazy(4 * maxn); 


void update (int l, int r, int ql, int qr, int pos, int val)
{
    if (l > r || ql > r || qr < l) {
        return; 
    }
    if (l >= ql && r <= qr) {
        // cout << "updating the segment : " << l << ", " << r << "\n"; 
        seg[pos] = val; 
        lazy[pos] = val; 
        
        return; 
    }
    int m = (r + l) / 2; 
    if (lazy[pos] != -1) {
        lazy[2 * pos + 1] = lazy[pos]; 
        lazy[2 * pos + 2] = lazy[pos]; 
        lazy[pos] = -1; 
    }
    update(l, m, ql, qr, 2 * pos + 1, val); 
    update(m + 1, r, ql, qr, 2 * pos + 2, val); 
    return; 
}


int query (int l, int r, int ql, int qr, int pos) {
    // cout << "on segment: " << l << ", " << r << " @@ " << lazy[pos] << " - " << seg[pos] << "\n"; 
    if (l > r || ql > r || qr < l) {
        return -1; 
    }
    if (ql <= l && r <= qr) {
        // cout << "query on segment : " << l << ", " << r << " ## " << lazy[pos] << endl; 
        if (lazy[pos] != -1) {
            seg[pos] = lazy[pos]; 
            lazy[2 * pos + 1] = lazy[pos]; 
            lazy[2 * pos + 2] = lazy[pos]; 
            lazy[pos] = -1; 
        }

        return seg[pos]; 
    }

    if (lazy[pos] != -1) {
        lazy[2 * pos + 1] = lazy[pos]; 
        lazy[2 * pos + 2] = lazy[pos]; 
        lazy[pos] = -1; 
    }

    int m = (l + r)/2; 
    int q = query(l, m, ql, qr, 2 * pos + 1); 
    int p = query(m + 1, r, ql, qr, 2 * pos + 2); 

    return max(p, q); 
}
 
void input ()
{
    cin >> n >> m; 
    
    for (int i = 0; i < n; i ++) {
        int x; cin >> x; 
        arr.pb(x); 
    } 

    for (int i = 0; i < n; i ++) {
        int x; cin >> x; 
        brr.pb(x); 
    }


}
struct quest {
    int x; 
    int y;
    int k; 
}; 

void solve ()
{
    for (int i = 0; i < 4 * maxn; i ++) {
        lazy[i] = -1; 
        seg[i] = 0; 
    }
    vector<quest> que; 
    int c = 1; 
    for (int i = 0; i < m; i ++) {
        int t; cin >> t; 
        if (t == 2) {
            int x; 
            cin >> x; 
            x --; 
            int p = query(0, n - 1, x, x, 0); 
            // cout << p << " $ "; 
            if (p < 1) {
                cout << brr[x] << endl; 
                continue; 
            }
            // cout << x << " " << que[p - 1].y << " " << que[p - 1].x << " " << que[p - 1].k << " " << x << "\n"; 
            int a = x - que[p - 1].y; 
            cout << arr[que[p - 1].x + a] << "\n"; 
            continue; 
        }
        else {
            int x, y, k; 
            cin >> x >> y >> k; 
            x --; y --; 
            update(0, n - 1, y, y + k - 1, 0, c);
            c ++; 
            quest q; 
            q.x = x; q.y = y; q.k = k; 
            que.pb(q);  
        }
    }
    return; 
}

int main ()
{
    IOS; 
    input ();
    solve (); 
}