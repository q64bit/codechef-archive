#include <bits/stdc++.h>
using namespace std;
using ll =  long long;

ll solve() {
    int n; cin >> n;
    
    vector<int> v(n);
    for(int& i: v) cin >> i;
    
    if(n == 1) return 0;
    
    int l = (n & 1) ? n/2 - 1: n/2 - 1;
    int r = (n & 1) ? n/2 - 1: n/2;
    
    vector<int> u(n, 0);
    for(int i=0, j=n-1; i<=l && r<=j; i++, j--) {
        u[i] = max(v[i], v[j]) - v[i];
        u[j] = max(v[i], v[j]) - v[j];
    }
    
    for(int x: u)
        cout << x << ' ';
    
    ll st1 = 0;
    for(int i=1; i<n; i++) {
        st1 += (u[i] > u[i-1]) ? u[i] - u[i-1] : 0;
    }
    ll st2=0;
    for(int i=0; i<n-1; i++) {
        st2 += (u[i] > u[i+1]) ? u[i] - u[i+1] : 0;
    }
    
    return max(st1, st2);
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
        cout << solve() << '\n';
        
    return 0;
}
