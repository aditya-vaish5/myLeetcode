/*
 * @lc app=leetcode id=151 lang=cpp
 *
 * [151] Reverse Words in a String
 */

// @lc code=start
class Solution
{
public:
    string reverseWords(string s)
    {
        s = s + " ";
        int n = s.length();
        string t = "";
        string ans = "";
        for (char c : s)
        {
            if (c != ' ')
            {
                t = t + c;
            }
            else
            {
                if (t.length())
                {
                    ans =  " " + t + ans;
                    t = "";
                }
            }
        }
        if (ans.length() > 1)
        {
            ans.erase(0,1);

        }
        return ans;
    }
};
// @lc code=end
