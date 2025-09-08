#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for(int i=0;i<n;i++) {
        cin >> a[i].first >> a[i].second;
    }
    int m;
    cin >> m;
    map<int, int> mb;
    vector<int> b(m);
    for(int i=0;i<m;i++) {
        cin >> b[i];
        mb[b[i]]++;
    }
    map<int, int> ma;
    int p = 0;
    for(int i=0;i<n;i++) {
        while(p < m && b[p] < a[i].first) {
            p++;
        }
        while(p < m && b[p] >= a[i].first && b[p] <= a[i].second) {
            ma[i]++;
            if(b[p] < a[i].second) { 
                p++;
            }
            else {
                break;
            }
        }
    }
    int flag = 1;
    vector<int> ans;
    for(int i=0;i<n;i++) {
        if(ma[i] >= 3) {
            flag = 0;
            break;
        }
        if(ma[i] <= 1) {
            if(i < n - 1 && mb[a[i].second] == 0 && ma[i + 1] <= 1 && a[i].second == a[i + 1].first) {
                ma[i]++;
                mb[a[i].second]++;
                ans.push_back(a[i].second);
                ma[i+1]++;
            }
            else {
                if(mb[a[i].second - 1] == 0) {
                    ma[i]++;
                    mb[a[i].second - 1] = 1;
                    ans.push_back(a[i].second - 1);
                }
                else if(mb[a[i].second - 2] == 0) {
                    ma[i]++;
                    mb[a[i].second - 2] = 1;
                    ans.push_back(a[i].second - 2);
                }
            }
        }
        if(ma[i] <= 1) {
            if(mb[a[i].second - 1] == 0) {
                ma[i]++;
                ans.push_back(a[i].second - 1);
            }
            else if(mb[a[i].second - 2] == 0) {
                ma[i]++;
                ans.push_back(a[i].second - 2);
            }
        }
    }
    if(flag) {
        cout << ans.size() << '\n';
        for(int i=0;i<ans.size();i++) {
            cout << ans[i] << " \n"[i==ans.size() - 1];
        }
    }
    else {
        cout << "impossible" << '\n';
    }
    return 0;
}