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

vector<string> arr; 
int n; 
string res; 
int LPS(const string& pat) {
    int s = (int)pat.size();
    vector<int> lps(s, 0);

    int len = 0;
    int idx = 1;

    while (idx < s) {
        if (pat[idx] == pat[len]) {
            
            lps[idx] = ++len;
            ++idx;
        } else if (len != 0) {
            
            len = lps[len - 1];
        } else {
            
            lps[idx] = 0;
            ++idx;
        }
    }
    return max(len, 0); 
}


void input ()
{   
    cin >> n; 
    for (int i = 0; i < n; i ++) {
        string a; cin >> a; 
        arr.pb(a); 
    }
}

void solve ()
{
    res = arr[0]; 
    for (int i = 0; i < n - 1; i ++) {
        if (arr[i] == arr[i + 1]) {
            continue; 
        }
        string k = arr[i + 1]; 
        if (arr[i + 1].size() <= res.size()) {
            
            k += "$"+res.substr(res.size() - arr[i + 1].size(), arr[i + 1].size()); 
            
        }
        else 
            k += ("$" + res);
        
        int l = LPS(k); 
        if (l == 0) {
            res += arr[i + 1]; 
        }
        else {
            string s = arr[i + 1].substr(l, arr[i + 1].size()  - l); 
            res += s;  
        }
    }
    cout << res << endl; 
}


int main ()
{
    IOS; 

   
    input ();
    solve (); 
    res = ""; 
    arr.clear(); 
    
}