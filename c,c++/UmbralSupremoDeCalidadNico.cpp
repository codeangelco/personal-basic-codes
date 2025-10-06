#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, l, k;
    cin >> n >> l >> k;
    
    vector<int> a(n);
    
    for (int i = 0; i < n; i++) 
        cin >> a[i];

    multiset<int> window;
    
    for (int i = 0; i < l; i++) {
        window.insert(a[i]);
    }

    int ans = 0;
    for (int i = l; i <= n; i++) {
        
        auto it = window.end();
        it--;
        for (int x = 1; x < k; x++) 
            it--;
            
        ans = max(ans, *it);

        if (i < n) {
           
            auto del = window.find(a[i - l]);
            window.erase(del);
            window.insert(a[i]);
        }
    }

    cerr << ans << endl;
    return 0;
}
