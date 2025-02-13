#include <bits/stdc++.h>
using namespace std;
bool isPalindrome (string s)
{
    for (int i = 0; i < s.size(); i ++) {
        if(s[i] != s[s.size() - i - 1]) {
            return false; 
        }
    }
    return true; 
}
int countZero (string s)
{
    int cnt = 0; 
    for (int i = 0; i < s.size(); i ++) {
        if (s[i] == '0') {
            cnt ++; 
        }
    }
    return cnt; 
}
void process ()
{   
    int n; 
    cin >> n; 
    string s; 
    cin >> s; 
    int cnt = countZero(s);     
    if (isPalindrome(s)) {
        if (cnt % 2 == 0 || cnt == 1) {
            cout << "BOB\n"; 
            return;  
        }
        else {
            cout << "ALICE\n"; 
            return; 
        }
    }
    else {
        if ((s.size() % 2 == 1) && (cnt == 2) && (s[s.size()/2] == '0')) {
            cout << "DRAW\n"; 
            return;  
        } 
        else {
            cout << "ALICE\n"; 
            return;  
        }
    }
}

int main ()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 

    int t;
    cin >> t;
    while (t--) {
        process(); 
    }
}