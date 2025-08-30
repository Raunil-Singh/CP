#include <bits/stdc++.h>
using namespace std;

#define int long long

int comp(int a, int b) {
    if(a == b) return 0;
    else if(a < b) {
        int ans  = 0;
        while(a <= b) {
            a*=2;
            ans++;
        }
        ans--;
        return -ans;
    } else  {
        int ans = 0;
        while(a > b) {
            b *= 2;
            ans++;
        }
        return ans;
    }
}

void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    for(int & num : v) cin >> num;
    vector<int> del(n);
    for(int i = 1 ; i<n ; i++) {
        del[i] = comp(v[i-1], v[i]);
    }
    // for(int num : del) cout << num << " ";
    // cout << "\n";
    for(int i = 1 ; i<n ; i++) {
        del[i] = max(del[i-1] + del[i], 0LL);
    }
    // for(int num : del) cout << num << " ";
    // cout << "\n";
    cout << accumulate(del.begin(), del.end(), 0LL) << "\n";
}

signed main() {
    int t;
    cin >> t;
    while(t--)
        solve();
    return 0;
}


/*

3 -> 0 -> 0
1 -> 2 -> 2
5 -> -2 -> 0
3 -> 1 -> 1
6 -> -1 -> 0

3 4 5 6 6

*/