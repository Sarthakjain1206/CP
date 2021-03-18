#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

// Longest Common Substring is a slight variation of LCS problem

int TabulationLCS(string s1, string s2, int n, int m) {
    // We need only previous row to calculate LCS ======= (observe filling of traditional LCS dp array)
    int dp[2][m + 1];
    for(int i = 0; i <= 1; i++) dp[i][0] = 0;
    for(int i = 0; i <= m; i++) dp[0][i] = 0;
    int maxLen = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(s1[i-1] == s2[j-1]) {
                dp[i % 2][j] = 1 + dp[(i - 1) % 2][j - 1];
                maxLen = max(maxLen, dp[i % 2][j]);             //INFO: Changed w.r.t LCS
            }
            else
                dp[i % 2][j] = 0;           //INFO: Changed w.r.t LCS
        }
    }
    return maxLen;
}
int longestCommonSubstring(string text1, string text2) {
    int n = text1.length();
    int m = text2.length();
        
    return TabulationLCS(text1, text2, n, m);
}

int main(int argc, char const *argv[])
{
    string X = "OldSite:GeeksforGeeks.org"; 
    string Y = "NewSite:GeeksQuiz.com";

    cout << longestCommonSubstring(X, Y);
    return 0;
}
