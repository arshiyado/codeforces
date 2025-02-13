#include <bits/stdc++.h>
using namespace std;

template <typename A, typename B, typename C>  
class trip {
public : 
    A first; 
    B second; 
    C third;
    friend std::ostream& operator<<(std::ostream& os, const trip& trp) {
        // Output operator
        os << trp.first << " " << trp.second << " " << trp.third << endl; 
        return os;
    }
}; 
const int maxn = 1e4 + 10; 
vector<int> arr; 
vector<trip<int, int, int>> opr; 
int n; 
void input ()
{
    arr.clear(); opr.clear(); 
    cin >> n; 
    arr.push_back(0); 
    for (int i = 0; i < n; i ++) {
        int a; cin >> a; 
        arr.push_back(a); 
    }
}

void change (int i, int j, int x) 
{
    trip<int,int,int> ope; 
    arr[i] -= i * x; 
    arr[j] += i * x; 
    ope.first = i; 
    ope.second = j;     
    ope.third = x; 
    opr.push_back(ope);   
}

void solve ()
{
    // first part adding all to 1
    long long sum = 0; 
    for (auto x : arr) {
        sum += x; 
    }
    if (sum % n) {
        cout << "-1" << endl; 
        arr.clear(); 
        return; 
    }
    for (int i = 2; i <= n; i ++) {
        if (arr[i] % i) {
            change(1, i, i - (arr[i] % i)); 
        }
        change(i, 1, arr[i] / i); 
        
    }

    // second part add sum/n to all 
    for (int i = 2; i <= n; i ++) {
        change(1, i, sum/n); 
    }

    cout << opr.size() << endl; 
    for (auto x: opr) {
        cout << x; 
    }
    return; 
}

int main ()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL); 

    int t;
    cin >> t; 
    while (t--) {
        input (); 
        solve (); 
    }
}