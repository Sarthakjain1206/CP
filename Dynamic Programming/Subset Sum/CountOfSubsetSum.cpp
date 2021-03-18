#include<bits/stdc++.h>
using namespace std;

// For values greater than zero.
int CountSubsetSumDP(vector<int> &nums, int sum, int size) {
    int dp[size+1][sum+1];
    for(int i = 0; i <= sum; i++) dp[0][i] = 0;
    for(int i = 0; i <= size; i++) dp[i][0] = 1;
    
    for(int i = 1; i <= size; i++) {
        for(int j = 1; j<= sum; j++) {
            if(nums[i - 1] <= j)
                dp[i][j] = dp[i-1][j-nums[i-1]] + dp[i-1][j];
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    return dp[size][sum];
}

// If values inside array also contains zero.
int CountSubsetSumDP_Improvised(vector<int> &nums, int sum, int size) {
    int dp[size+1][sum+1];
    // modification -- We are creating a new array to store the total number of zeros seen so far.
    vector <int> zeros(nums.size());
    int count = 0;
    for(int i = 0; i < nums.size(); i++) {
        if(nums[i] == 0)
            count++;
        zeros[i] = count;
    }
    // Base condition for first row.
    for(int i = 0; i <= sum; i++) dp[0][i] = 0;
    // Base condition for first column.
    // Assign dp[i][0] with the 2**(number of zeroes seen till now)
    for(int i = 0; i <= size; i++) dp[i][0] = i == 0 ? 1 : (int)pow(2, zeros[i-1]);

    for(int i = 1; i <= size; i++) {
        for(int j = 1; j <= sum; j++) {
            if(nums[i - 1] <= j)
                dp[i][j] = dp[i-1][j-nums[i-1]] + dp[i-1][j];
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    return dp[size][sum];
}
