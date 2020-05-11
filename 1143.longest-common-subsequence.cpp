/*
 * @lc app=leetcode id=1143 lang=cpp
 *
 * [1143] Longest Common Subsequence
 */

// @lc code=start
class Solution {
public:
    int l1,l2;
    int dp[1001][1001];
    int ans=0;
    int f(const string &s1, const string &s2 , int i1,int i2){
        if(dp[i1][i2]!=-1){
            return dp[i1][i2];
        }
        if(i1 == l1 || i2 == l2){
            return 0;
        }
        if(s1[i1] == s2[i2] ){
            dp[i1][i2] = 1 + f(s1,s2,i1+1,i2+1);
            return dp[i1][i2];
        }
        dp[i1][i2] = max(f(s1,s2,i1+1,i2),f(s1,s2,i1,i2+1));
        return dp[i1][i2];
    }
    int longestCommonSubsequence(string text1, string text2) {
        l1 = text1.size();
        l2 = text2.size();
        memset(dp,-1,sizeof(dp));
        return f(text1,text2,0,0);
    }
};
// @lc code=end

