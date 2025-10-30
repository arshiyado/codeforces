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

const int maxc = 18; 
ll cho[maxc + 2][maxc + 2]; 

ll power (ll b, ll e) 
{
    ll ret = 1; 
    for (int i = 0; i < e; i ++) {
        ret *= b; 
    }
    return ret; 
}

void prepro ()
{
    cho[0][0] = 1; 
    for (int i = 1; i <= maxc; i ++) {
        cho[i][0] = 1; 
        cho[i][1] = i; 
    }
    for (int i = 0; i <= maxc; i ++) {
        for (int j = i + 1; j <= maxc; j ++) {
            cho[i][j] = 0; 
        }
    }
    for (int i = 2; i <= maxc; i ++) {
        for (int j = 2; j <= i; j ++) {
            cho[i][j] = cho[i - 1][j - 1] + cho[i - 1][j]; 
        }
    }
    
}


void test ()
{
    for (int i = 0; i <= 10 ; i ++) {
        for (int j = 0; j <= 10; j ++) {
            cout << cho[i][j] << " " ; 
        }
        cout << endl; 
    }

    for (int i = 0; i <= 4; i ++) {
        cout << power(5, i) << endl; 
    }
}

ll calc (ll val) 
{
    string s = to_string(val); 
    // cout << "string : " << s << "\n"; 
    int k = 0; 
    ll ans = 0; 
    ll sum = 0; 
    for (int i = 0; i < s.size(); i ++) {
        if (s[i] == '0') {
            continue; 
        }
        int d = int(s[i] - '0'); 
        int x = s.size() - i - 1;
        // cout << i << ": " << x << endl;  
        for (int j = 0; j <= 3 - k; j ++) {
            sum += cho[x][j] * power(9, j); 
            // cout << "1- " << j << " " << cho[x][j] << " " << sum << endl; 
        }
        ans += sum; 
        sum = 0; 
        for (int j = 0; j <= 3 - k - 1; j ++) {
            sum += cho[x][j] * power(9, j); 
            // cout << "2 - " << sum << endl; 
        }
        sum *= (d - 1); 
        // cout << "2 -- " << sum << endl; 
        ans += sum; 
        sum = 0; 
        k++; 
    }
    int cnt = 0; 
    for (int i = 0; i < s.size(); i ++) {
        if (s[i] != '0') {
            cnt += 1; 
        }
    }
    if (cnt <= 3) {
        ans += 1; 
    }
    return ans; 
}

ll l, r; 

void input ()
{
    cin >> l >> r; 
}

void solve ()
{
    cout << calc(r) - calc(l - 1) << endl; 
    return; 
}


int main ()
{
    IOS; 
    int t; cin >> t; 
    prepro (); 
    // test (); 
    while (t--) {
        input (); 
        solve (); 
    }
}