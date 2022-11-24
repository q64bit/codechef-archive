#include <bits/stdc++.h>
using namespace std;
using ll =  long long;

void solve() {
    string s; cin >> s;
    
    int n10 = 0, n01 = 0;
    
    for(int i=0; i<s.size()-1; i++) {
        n10 += ((s[i] == '1') && (s[i+1] == '0'));
        n01 += ((s[i] == '0') && (s[i+1] == '1'));
    }
    
    int ans = 0;
    int t10 = n10, t01 = n01;
    
    for(int i=0; i<s.size(); i++) {
        t10 = n10;
        t01 = n01;
        
        if(i == 0) {
            if(s[i] == '0') {
                if(s[i+1] == '1') --t01;
                else ++t10;
            }
            else {
                if(s[i+1] == '0') --t10;
                else ++t01; 
            }
        }
        
        else if(i == s.size() - 1) {
            if(s[i] == '0') {
                if(s[i-1] == '1') --t10;
                else ++t01;
            }
            else {
                if(s[i-1] == '0') --t01;
                else ++t10;
            }
        }
        
        else {
            if(s[i] == '0') {
                if(s[i-1] == '1') --t10;
                else ++t01;
                
                if(s[i+1] == '1') --t01;
                else ++t10;
            }
            
            else {
                if(s[i-1] == '0') --t01;
                else ++t10;
                
                if(s[i+1] == '0') --t10;
                else ++t01;
            }
        }
        
        ans += (t10 == t01);
    }
    
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    #ifndef ONLINE_JUDGE
        freopen("input", "r", stdin);
        freopen("output", "w", stdout);
    #endif
    
    int tst; cin >> tst;
    while(tst--)
        solve();
        
    return 0;
}
