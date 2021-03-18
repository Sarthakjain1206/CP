// #include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;
/*
! These functions works for only values greater than zero. 
!       Constraints: 
!           arr[i] > 0
*/

/*
* subset sum problem is a variation of 0-1 knapsack problem--
*       1) Because we have a choice over an element to whether select that element or not
*       2) Total capacity is also given i.e "Sum" in this case.
*/

bool subsetSum(vector<int> &nums, int sum, int size) {
    
    // Base conditions with backtracking steps.
    if(sum == 0) return true;
    if(size == 0 || sum < 0) return false;
    
    return subsetSum(nums, sum - nums[size-1], size-1) || subsetSum(nums, sum, size-1);
}
bool subsetSumMemoization(vector<int> &nums, int sum, int size, vector<vector<int>>&memo) {
    
    if(sum == 0) return true;
    if(size == 0 || sum < 0) return false;
    
    if(memo[size][sum] != -1)
        return memo[size][sum] == 1 ? true : false;
    
    bool ans = subsetSumMemoization(nums, sum - nums[size-1], size-1, memo) || subsetSumMemoization(nums, sum, size-1, memo);
    memo[size][sum] = ans == true ? 1 : 0;
    return ans;
}

bool subsetSumDP(vector<int> &nums, int sum, int size) {
    bool dp[size+1][sum+1];
    for(int i = 0; i <= sum; i++) dp[0][i] = false;
    for(int i = 0; i <= size; i++) dp[i][0] = true;
    
    for(int i = 1; i <= size; i++) {
        for(int j = 1; j<= sum; j++) {
            if(nums[i - 1] <= j)
                dp[i][j] = dp[i-1][j-nums[i-1]] || dp[i-1][j];
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    for(int i = 1; i <= size; i++) {
            for(int j = 1; j <= sum; j++) {
                cout<<dp[i][j]<<" ";
            }
            cout<<endl;
    }
    return dp[size][sum];
}

int main() 
{ 
    // vector<int> nums {1, 2, 3, 4, 5};
    vector<int> nums{2, 3, 5, 6, 8, 10};
    int n = nums.size();
    int sum = 10;
    cout<<subsetSumDP(nums, sum, n); 
    return 0; 
} 