#include <bits/stdc++.h>
#define pb push_back
#define pf push_front
#define qb pop_back
#define qf pop_front
#define ll long long
using namespace std;
#define IOS ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 
const int maxn = 2e3 + 10; 
int n; 
int arr[maxn][maxn]; 
ll sum[maxn * 2 + 1][3]; 
void input ()
{
    cin >> n; 
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= n; j ++) {
            cin >> arr[i][j]; 
            sum[i + j][0] += arr[i][j]; 
            sum[i - j + n][1] += arr[i][j]; 
        }
    }
}

void solve ()
{
    int x1, x2, y1, y2; 
    long long ans1 = -1, ans2 = -1; 
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= n; j ++) {
            if ((i + j) % 2 == 0) {
                if (ans1 < sum[i + j][0] + sum[i - j + n][1] - arr[i][j]) {
                    ans1 = sum[i + j][0] + sum[i - j + n][1] - arr[i][j]; 
                    x1 = i; 
                    y1 = j; 
                }   
                
            }
            else {
                if (ans2 < sum[i + j][0] + sum[i - j + n][1] - arr[i][j]) {
                    ans2 = sum[i + j][0] + sum[i - j + n][1] - arr[i][j]; 
                    x2 = i; 
                    y2 = j; 
                }   
                else {
                    continue; 
                }
            }
        }
    }
     
    cout << ans1 + ans2 << endl; 
    cout << x1 << " " <<  y1 << " " << x2 << " " << y2 << endl; 
}
int main ()
{
    IOS; 
    input (); 
    solve ();    
}