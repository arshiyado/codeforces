#include <bits/stdc++.h>
#define pb push_back
#define pf push_front
#define qb pop_back
#define qf pop_front
using namespace std;
#define IOS ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 
int a, b, c; 
void input ()
{
    cin >> a >> b >> c; 
}
void solve ()
{
    vector<int> nums; 
    int ans = 1e9 + 7; 
    for (int A = 1; A <= a + a; A ++) {
        for (int B = A; B <= b + b; B += A) {
            for (int i = 0; i < 2; i ++) {

                int C = (c/B) * B + i * B;
                int p = abs(a - A) + abs(b - B) + abs(c - C);  
                if (p < ans) {
                    nums.clear(); 
                    nums.pb(A); 
                    nums.pb(B); 
                    nums.pb(C); 
                    ans = p; 
                }
            }
            
        }
    }
    cout << ans << endl; 
    for (auto x: nums) cout << x << " " ; 
    cout << endl; 
}
int main ()
{
    IOS; 
    int t;
    cin >> t; 
    while (t --) {
        input (); 
        solve (); 
    }
    return 0; 
}