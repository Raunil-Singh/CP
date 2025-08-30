
#include <iostream>
#include <set>
#include "testlib.h"

using namespace std;

int main(int argc, char **argv) {
    registerGen(argc, argv, 1);
    
    int t = atoi(argv[2]);  // Number of test cases
    cout << t << endl;

    int total_n = 1e6;  // Ensure total sum of n doesn't exceed 10^6

    while (t--) {
        int n = rnd.next(1, min(100000, total_n));  // 1 ≤ n ≤ 10^5, within limit
        total_n -= n;  // Reduce total remaining sum of n


    return 0;
}
