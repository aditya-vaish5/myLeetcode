/*
 * @lc app=leetcode id=139 lang=cpp
 *
 * [139] Word Break
 */

// @lc code=start
class Solution
{
public:
    int n;
    unordered_map<string, bool> u;
    int dp[1001];
    bool f(const string &s, int index)
    {
        if(dp[index]!=-1){
            return dp[index]==1 ? true : false;
        }
        if (index == n)
        {
            return true;
        }
        bool ans = false;
        for (int i = 1; i <= n - index; i++)
        {
            cout << index << ' ' << i << ' ' << s.substr(index, i) << endl;
            if (u.find(s.substr(index, i)) != u.end())
            {
                ans |= f(s, index + i);
            }
            if (ans == true)
            {
                dp[index] =1;
                return true;
            }
        }
        dp[index] = ans ?1 :0;
        return ans;
    }
    bool wordBreak(string s, vector<string> &wordDict)
    {
        for (string st : wordDict)
        {
            u[st] = true;
        }
        n = s.length();
        memset(dp,-1,sizeof(dp));
        return f(s, 0);
    }
};
// @lc code=end
