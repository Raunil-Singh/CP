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

    stack<char> st;
    string s;
    int n;
    cin >> n;
    cin >> s;

    for(int i = 0 ; i<n ; i++)
    {
        if(st.size()%2 == 0)
            st.push(s[i]);
        else if(st.top() != s[i])
            st.push(s[i]);
    }

    if(st.size()%2 == 1) st.pop();

    string temp = "";
    while(!st.empty())
    {
        temp.push_back(st.top());
        st.pop();
    }

    reverse(temp.begin(), temp.end());

    cout << s.size() - temp.size() << "\n";
    cout << temp << "\n";

	return 0;
}