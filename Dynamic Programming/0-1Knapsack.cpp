#include<bits/stdc++.h>
using namespace std;

int RecursiveKnapSack01(int wt[], int val[], int W, int n) {
    // Base Consdition
    if(n == 0 || W == 0)
        return 0;

    // Choice Diagram
    if(wt[n-1] <= W)
        return max(val[n - 1] + RecursiveKnapSack01(wt, val, W - wt[n - 1], n - 1), RecursiveKnapSack01(wt, val, W, n - 1));
    return RecursiveKnapSack01(wt, val, W, n - 1);
}

int TabulationKnapsack01(int wt[], int val[], int W, int n) {
    int dp[n + 1][W + 1];
    // Base condition
    for (int i = 0; i <= W; i++)
        dp[0][i] = 0;
    for (int i = 0; i <= n; i++)
        dp[i][0] = 0;
    
    // Choice Diagram
    // n -> i
    // W -> j
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= W; j++) {
            if(wt[i-1] <= j)
                dp[i][j] = max(val[i - 1] + dp[i - 1][j - wt[i - 1]], dp[i - 1][j]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[n][W];
}

int main(int argc, char const *argv[])
{
    
    return 0;
}
