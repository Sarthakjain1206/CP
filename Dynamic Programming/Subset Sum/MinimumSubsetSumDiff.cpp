#include<bits/stdc++.h>
using namespace std;

//! https://leetcode.com/problems/last-stone-weight-ii/
int lastStoneWeightII(vector<int>& stones) {
    /*
        S1 + S2 = S
        S1 - S2 = diff
        
        Subtract these two equations
        2*S2 = S - diff
        S2 = (S - diff)/2
        
        We have to minimize diff ==> so, minimum diff can be 0 and maximum diff can be S
        So, diff varies from  0 -> S
        therefore, S2 varies from S/2 -> 0
        This implies we have to maximize S2 within range of 0 -> S/2
    */
    int S = 0;
    for(int i: stones) S += i;
    // bool dp[stones.size() + 1][S/2 + 1];
    bool dp[2][S/2 + 1];                                        // Space Optimized (GFG)
    for(int i = 0; i <= S/2; i++) dp[0][i] = false;
    // for(int i = 0; i <= stones.size(); i++) dp[i][0] = true;
    for(int i = 0; i < 2; i++) dp[i][0] = true;

    
    int maxVal = INT_MIN;
    for(int i = 1; i <= stones.size(); i++) {
        for(int j = 1; j <= S/2; j++) {
            if(stones[i - 1] <= j)
                dp[i%2][j] = dp[(i - 1)%2][j - stones[i - 1]] || dp[(i - 1)%2][j];
            else
                dp[i%2][j] = dp[(i - 1)%2][j];
            if(dp[i%2][j])
            maxVal = max(j, maxVal);
        }
    }
    return maxVal != INT_MIN ? S - 2*maxVal: S;
}

//! Mimium Subset Sum Diff [exact same as above]
int minSubsetSumDiff(vector<int>& nums) {
    /*
        S1 + S2 = S
        S1 - S2 = diff
        
        Subtract these two equations
        2*S2 = S - diff
        S2 = (S - diff)/2
        
        We have to minimize diff ==> so, minimum diff can be 0 and maximum diff can be S
        So, diff varies from  0 -> S
        therefore, S2 varies from S/2 -> 0
        This implies we have to maximize S2 within range of 0 -> S/2
    */
    int S = 0;
    for(int i: nums) S += i;
    // bool dp[nums.size() + 1][S/2 + 1];
    bool dp[2][S/2 + 1];                                        // Space Optimized (GFG)
    for(int i = 0; i <= S/2; i++) dp[0][i] = false;
    // for(int i = 0; i <= nums.size(); i++) dp[i][0] = true;
    for(int i = 0; i < 2; i++) dp[i][0] = true;

    
    int maxVal = INT_MIN;
    for(int i = 1; i <= nums.size(); i++) {
        for(int j = 1; j <= S/2; j++) {
            if(nums[i - 1] <= j)
                dp[i%2][j] = dp[(i - 1)%2][j - nums[i - 1]] || dp[(i - 1)%2][j];
            else
                dp[i%2][j] = dp[(i - 1)%2][j];
            if(dp[i%2][j])
            maxVal = max(j, maxVal);
        }
    }
    return maxVal != INT_MIN ? S - 2*maxVal: S;
}
