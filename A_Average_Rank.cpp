#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

template <typename T>
using ordered_set =
    tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
// order_of_key (k) : Number of items strictly smaller than k .
// find_by_order(k) : K-th element in a set (counting from zero).
// use less_equal for multiple entries

#define int long long // upto 9.2 * (10^18)
#define uint unsigned long long // upto 1.8 * (10^19)
#define pb(x) push_back(x)
#define ppb(x) pop_back(x)
#define F first
#define S second
#define inp(v) for(auto &temporary_variable : v) cin >> temporary_variable
#define all(x) x.begin(), x.end()
#define mpr(x, y) make_pair(x, y)

mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

const long double eps = 1e-12;
#define MOD

void preprocessing()
{

    // Code here

}

void solve(int tc_no)
{
    
    // cout << "Case #" << tc_no << ": ";
    int n,w; cin >> n >> w;
    ordered_set<int> st;
    for(int i=0;i<n;++i){
        st.insert(0);
    }
    vector<pair<int,int>> increments[n+1]; // weeks of increment for each person
    vector<int> pts(n+1);
    vector<int> sum(n+1);
    vector<pair<int,int>> ranks[n+1]; // for every rank store week and no. of people with increment
    // {week,freq}
    for(int cur_w=1;cur_w<=w;++cur_w){
        int k; cin >> k;
        vector<int> people(k);
        vector<int> rank(k);
        map<int,int> cnt;
        for(int i=0;i<k;++i){
            int p; cin >> p;
            people[i] = p;
            rank[i] = n-st.order_of_key(pts[p]+1)+1;
            cnt[rank[i]]++;
        }
        for(auto [r,f] : cnt){
            ranks[r].push_back({cur_w,f});
        }
        for(int i=0;i<k;++i){
            int p = people[i];
            pts[p]++;
            st.erase(st.upper_bound(pts[p]-1));
            st.insert(pts[p]);
        }
        for(int i=0;i<k;++i){
            int p = people[i];
            int new_rank = n-st.order_of_key(pts[p]+1)+1;
            increments[p].pb(mpr(cur_w,new_rank));
        }
    }

    for(int p=1;p<=n;++p){
        int rank = 1;
        int week = 0;
        int idx = 0;
        while(idx<increments[p].size()){
            auto it = lower_bound(ranks[rank].begin(),ranks[rank].end(),mpr(week+1,0ll));
            if(it==ranks[rank].end()){
                // just go to the increment
                auto [next_week,new_rank] = increments[p][idx++];
                // sum[p] += (next_week-week)*new_rank;
                sum[p] += (next_week-week-1)*rank+new_rank;
                rank = new_rank;
                week = next_week;
                // if(p==1){
                //     cout << week << ' ' << rank << endl;
                // }
            } else {
                int next_week = it->first;
                if(next_week < increments[p][idx].first){
                    int new_rank = rank+it->second;
                    // sum[p] += (next_week-week)*new_rank;
                    sum[p] += (next_week-week-1)*rank+new_rank;
                    rank = new_rank;
                    week = next_week;
                    it = lower_bound(ranks[rank].begin(),ranks[rank].end(),mpr(week,0ll));
                    if(it!=ranks[rank].end() && it->first == week){
                        int new_rank = rank+it->second;
                        sum[p] += it->second;
                    }
                } else {
                    // do increment
                    auto [next_week,new_rank] = increments[p][idx++];
                    // sum[p] += (next_week-week)*new_rank;
                    sum[p] += (next_week-week-1)*rank+new_rank;
                    rank = new_rank;
                    week = next_week;
                }
                // if(p==1){
                //     cout << week << ' ' << rank << endl;
                // }
            }
        }
        // check for any increment with same rank in next weeks
        auto it = lower_bound(ranks[rank].begin(),ranks[rank].end(),mpr(week+1,0ll));
        while(it!=ranks[rank].end()){
            int next_week = it->first;
            int new_rank = rank+it->second;
            // sum[p] += (next_week-week)*new_rank;
            sum[p] += (next_week-week-1)*rank+new_rank;

            rank = new_rank;
            week = next_week;
            // if(p==1){
            //     cout << week << ' ' << rank << endl;
            // }
            it = lower_bound(ranks[rank].begin(),ranks[rank].end(),mpr(week,0ll));
            if(it!=ranks[rank].end() && it->first == week){
                int new_rank = rank+it->second;
                sum[p] += it->second;
                // if(p==1){
                //     cout << week << ' ' << rank << endl;
                // }
            }
            it = lower_bound(ranks[rank].begin(),ranks[rank].end(),mpr(week+1,0ll));
        }
        // for remaining weeks till w just add the current rank to the sum
        // if(p==1){
        //     cout << sum[p] << endl;
        // }
        sum[p] += (w-week)*rank;
    }
    for(int i=1;i<=n;++i){
        double cur = sum[i]/(double)w;
        // cout << sum[i] << ' ';
        cout << cur << '\n';
    }
}

signed main()
{
    auto begin = std::chrono::high_resolution_clock::now();
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    cout << fixed;
    cout << setprecision(10);

    preprocessing();

    int t;
    // cin >> t;
    t = 1;
    for(int i = 1 ; i<=t ; i++)
        solve(i);

    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    // cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
    return 0;
}