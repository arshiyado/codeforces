#include <bits/stdc++.h>
using namespace std;

long long k; 
void input ()
{
    cin >> k; 
}

long long integerSqrt(long long n) {
    if (n < 0) return -1;  
    if (n == 0 || n == 1) return n;

    long long low = 1, high = n, ans = 0;

    while (low <= high) {
        long long mid = low + (high - low) / 2;
        if (mid <= n / mid) { 
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return ans;
}

void solve ()
{
    // m - q = k
    // r l
    // m - q = k --->   r = m
    // m - q > k ---> r = m - 1
    long long l = 1ll, r = 4e18; 
    while (l < r) {
        long long m = (l + r) / 2;
        
        long long q = integerSqrt(m); 
        if (m - q > k) {
            r = m - 1;
        }
        else if(m - q == k) {
            r = m; 
        }
        else if (m - q < k) {
            l = m + 1; 
        }
        
    }
    cout << l << endl; 
}

int main ()
{
    // cout << integerSqrt(854258780613619262) << endl; 
    // long long q = sqrt(854258780613619262); 
    // cout << q << endl; 
    // cout << integerSqrt(2000) << endl; 
    // cout << integerSqrt(123456) << endl; 
    int t;
    cin >> t; 
    while (t--) {
        input ();
        solve (); 
    }
}