#include <bits/stdc++.h>
using namespace std;

#define int long long

vector<int> seg(400000);
int build(const vector<int> &v, int l, int r, int node) {
    if(l == r) return 0;
    if(r-l == 1) return seg[node] = v[l];
    return seg[node] = build(v, l, (l+r)/2, node*2) + build(v, (l+r)/2, r, node*2 + 1);
}

int sett(int i, int num, int l, int r, int node) {
    if(l >= r) return 0;
    if(l == i && r == i+1) return seg[node] = num;
    if(r <= i || i < l) return seg[node];
    return seg[node] = sett(i, num, l, (l+r)/2, node*2) + sett(i, num, (l+r)/2, r, node*2+1);
}

int sum(int l, int r, int L, int R, int node) {
    if(R <= l || r <= L || R <= L) return 0;
    if(l <= L && R <= r) return seg[node];
    return sum(l, r, L, (L+R)/2, node*2) + sum(l, r, (L+R)/2, R, node*2 + 1);
}

signed main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for(int &num : a) cin >> num;
    build(a, 0, n, 1);
    while(m--) {
        int a, b, c;
        cin >> a >> b >> c;
        if(a == 1) sett(b, c, 0, n, 1);
        else cout << sum(b, c, 0, n, 1) << "\n";
    }
    return 0;
}
