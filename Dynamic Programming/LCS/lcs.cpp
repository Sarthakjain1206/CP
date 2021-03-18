#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int RecursiveLCS(string s1, string s2, int n, int m) {
    if(n == 0 || m == 0) return 0;
    
    if(s1[n - 1] == s2[m - 1])
        return 1 + RecursiveLCS(s1, s2, n - 1, m - 1);
    else
        return max(RecursiveLCS(s1, s2, n - 1, m), RecursiveLCS(s1, s2, n, m - 1));
}

int MemoizationLCS(string s1, string s2, int n, int m, vector<vector<int>> &memo) {
    if(n == 0 || m == 0) return 0;
    
    if(memo[n][m] != -1)
        return memo[n][m];
    
    if(s1[n - 1] == s2[m - 1]){
        memo[n][m] = 1 + RecursiveLCS(s1, s2, n - 1, m - 1);
        return memo[n][m];
    }
    else{
        memo[n][m] = max(RecursiveLCS(s1, s2, n - 1, m), RecursiveLCS(s1, s2, n, m - 1));
        return memo[n][m];
    }
}

int TabulationLCS(string s1, string s2, int n, int m) {
    int dp[n + 1][m + 1];
    for(int i = 0; i <= n; i++) dp[i][0] = 0;
    for(int i = 0; i <= m; i++) dp[0][i] = 0;
    
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(s1[i-1] == s2[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    // Printing DP array ===========
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    // =============================
    
    // Printing LCS ================
    int i = n, j = m;
    string lcs = "";
    while(i > 0 && j > 0) {
        if(s1[i-1] == s2[j-1]) {
            lcs.push_back(s1[i-1]);
            i--;
            j--;
        }
        else {
            if(dp[i-1][j] > dp[i][j-1])
                i--;
            else
                j--;
        }
    }
    cout<<lcs<<"\n";
    // =============================
    return dp[n][m];
}
int longestCommonSubsequence(string text1, string text2) {
    int n = text1.length();
    int m = text2.length();
    
    // return RecursiveLCS(text1, text2, n, m);
    // vector<vector<int>> memo (n + 1, vector<int>(m + 1, -1));
    // return MemoizationLCS(text1, text2, n, m, memo);
    
    return TabulationLCS(text1, text2, n, m);
}

int main(int argc, char const *argv[])
{
    string X = "AGGTAB"; 
    string Y = "GXTXAYB";

    cout << longestCommonSubsequence(X, Y);
    return 0;
}
