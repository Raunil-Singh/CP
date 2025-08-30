#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {

    cout << fixed << setprecision(12);

    int n;
    cin >> n;
    vector<double> p(n);
    for(double &x : p) cin >> x;
    sort(p.begin(), p.end());
    
    if(p[n-1] == 1.0) {
        cout << "1\n";
        return 0;
    }

    double P = 1.0, S = 0.0;

    for(int i = n-1 ; i>=0 ; i--) {
        if(S > 1) break;
        S += p[i] / (1-p[i]);
        P *= (1-p[i]);
    }

    cout << P*S << "\n";
    
    return 0;
}