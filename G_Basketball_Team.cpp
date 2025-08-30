#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    int n, m, h;
    cin >> n >> m >> h;
    vector<int> s(m);
    for(int &num : s) cin >> num;
    
    int x = accumulate(s.begin(), s.end(), 0LL);
    if(x < n) {
        cout << "-1\n";
    } else if(x-s[h-1] < n-1) {
        cout << "1\n";
    } else {
        double ans = 1.0;
        for(int i = 0 ; i<n-1 ; i++)
            ans = (ans * (x-s[h-1]-i)) / (x-i-1);
        cout << fixed << setprecision(10) << (1.0 - ans) << "\n";
    }
    
    return 0;
}