#include<iostream>
using namespace std;

// For values greater than zero.
int CountSubsetSumDP(vector<int> &nums, int sum, int size) {
    // int dp[size+1][sum+1];
    int dp[2][sum + 1];
    for(int i = 0; i <= sum; i++) dp[0][i] = 0;
    // for(int i = 0; i <= size; i++) dp[i][0] = 1;
    for(int i = 0; i <= 1; i++) dp[i][0] = 1;

    for(int i = 1; i <= size; i++) {
        for(int j = 1; j<= sum; j++) {
            if(nums[i - 1] <= j)
                dp[i % 2][j] = dp[(i - 1) % 2][j - nums[i - 1]] + dp[(i - 1) % 2][j];
                // dp[i][j] = dp[i-1][j-nums[i-1]] + dp[i-1][j]

            else
                dp[i % 2][j] = dp[(i - 1) % 2][j];
                // dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[size % 2][sum];
}
