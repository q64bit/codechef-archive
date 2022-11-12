#include<bits/stdc++.h>
using namespace std;
using ll = long long;

string solve() {
    int n; cin >> n;
    
    vector<int> v(n);
    for(int& i: v) cin >> i;
    
    if(n <= 2) return "YES";
    if(v[0] == v[n-1]) return "YES";
    
    for(int i=0; i<n; i++) {
        if(v[0] == v[i] && v[i+1] == v[n-1])
            return "YES";
    }
    
    return "NO";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    #ifndef ONLINE_JUDGE
        freopen("input", "r", stdin);
        freopen("output", "w", stdout);
    #endif
    
    int tst; cin >> tst;
    while(tst--)
        cout << solve() << '\n';
    
    return 0;
}
