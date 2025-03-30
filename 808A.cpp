#include <bits/stdc++.h>
using namespace std;

int main ()
{
    long long n, a, b; 
    cin >> n; a = n; 
    int r = 0, l = 0; 
    while (n) {
        if (n <= 9) {
            r = n; 
        }
        l += 1; 
        n /= 10; 
    }
    if (r <= 8) {
        b = r + 1;  
        for (int i = 0; i < l - 1; i ++) {
            b *= 10; 
        }
    }
    else {
        b = 1; 
        for (int i = 0; i < l; i ++) {
            b *= 10; 
        }
    }
    // cout << b << " " << a << endl; 
    cout << b - a << endl; 
}