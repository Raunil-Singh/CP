#include <bits/stdc++.h>
using namespace std;

#define int unsigned long long

bool check(vector<int>&n, vector<int>&p, vector<int>&c, int r, int mid)
{
    int cost = 0;
    for(int i = 0 ; i<3 ; i++)
    {
        if(c[i]*mid < n[i]) continue;
        int x = max(c[i]*mid - n[i], 0ULL);
        cost += x * p[i];
    }
    return cost <= r;
}

int32_t main()
{
    string str;
    cin >> str;
    vector<int> n(3), p(3), c(3);
    cin >> n[0] >> n[1] >> n[2];
    cin >> p[0] >> p[1] >> p[2];
    int r; cin >> r;

    for(char x : str)
    {
        if(x == 'B') c[0]++;
        if(x == 'S') c[1]++;
        if(x == 'C') c[2]++;
    }

    int left = 0, right = 1000000000000000ULL;
    while(left+1 < right)
    {
        int mid = (left+right)/2;
        if(check(n, p, c, r, mid)) left = mid;
        else right = mid;
    }

    cout << left << "\n";

    return 0;
}