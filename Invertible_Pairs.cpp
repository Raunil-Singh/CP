#include <bits/stdc++.h>
using namespace std;

// Function to calculate maximum subarray sum using Kadane's algorithm
long long maxSubarraySum(const vector<long long>& arr) {
    long long max_so_far = arr[0];
    long long max_ending_here = arr[0];

    for (long long i = 1; i < arr.size(); ++i) {
        max_ending_here = max(arr[i], max_ending_here + arr[i]);
        max_so_far = max(max_so_far, max_ending_here);
    }
    
    return max_so_far;
}

int main() {
    long long T;
    cin >> T; // Number of test cases
    
    while (T--) {
        long long N;
        cin >> N; // Length of the array (even number)
        
        vector<long long> A(N);
        for (long long i = 0; i < N; ++i) {
            cin >> A[i]; // Input array elements
        }
        
        // To maximize the subarray sum, we can negate pairs (A[2k-1], A[2k])
        // We'll do this for all pairs to get the best outcome.
        for (long long i = 0; i < N; i += 2) {
            // Choose to negate the pair if it increases the overall sum
            if (A[i] < 0) {
                A[i] = -A[i];
            }
            if (A[i + 1] < 0) {
                A[i + 1] = -A[i + 1];
            }
        }
        
        // Calculate the maximum subarray sum after possible negations
        long long result = maxSubarraySum(A);
        cout << result << endl; // Prlong long the result for this test case
    }

    return 0;
}
