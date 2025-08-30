#include <bits/stdc++.h>
using namespace std;

#define ll long long // upto 9.2 * (10^18)
#define ull unsigned long long // upto 1.8 * (10^19)

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	// For IO in txt file
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

	ll n;
    cin >> n;
    string s;
    cin >> s;

    ll count[] = {0,0};
    for(char c : s)
    {
        if(c == 'X') count[1]++;
        if(c == 'x') count[0]++;
    }

    if(count[0] == count[1])
    {
        cout << "0\n" << s << "\n";
    }
    else if(count[0] < count[1])
    {
        cout << n/2 - count[0] << "\n";
        for(char c : s)
        {
            if(c == 'x') cout << c;
            else if(count[0] < count[1]){
                cout << 'x';
                count[0]++;
                count[1]--;
            }
            else cout << 'X';
        }
        cout << "\n";
    }
    else if(count[0] > count[1])
    {
        cout << n/2 - count[1] << "\n";
        for(char c : s)
        {
            if(c == 'X') cout << c;
            else if(count[0] > count[1]){
                cout << 'X';
                count[0]--;
                count[1]++;
            }
            else cout << 'x';
        }
        cout << "\n";
    }

	return 0;
}