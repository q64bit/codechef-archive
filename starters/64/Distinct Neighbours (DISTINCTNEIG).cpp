#include<bits/stdc++.h>
using namespace std;
using ll = long long;

string solve() {
    int n; cin >> n;
    
    vector<int> a(2*n);
    for(int& i: a) cin >> i;
    
    sort(a.begin(), a.end());
    
    vector<int> b;
    b.push_back(a[0] - a[2*n - 1]);
    int p = 1, q = 2*n - 2;
    
    while(p < q){
        if(a[p] - a[q] == b.back())
            b.push_back(a[q] - a[p]);
        else
            b.push_back(a[p] - a[q]);
        ++p;
        --q;
    }
    
    int md = (n & 1) ? (n + 1)/2 : n/2;
    int mx = 0;
    unordered_map<int, int> mp;
    
    for(int i: b) {
        mp[i] += 1;
        mx = max(mx, mp[i]);
    }
    
    return (mx <= md) ? "YES" : "NO";
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
