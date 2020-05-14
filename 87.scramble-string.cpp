/*
 * @lc app=leetcode id=87 lang=cpp
 *
 * [87] Scramble String
 */

// @lc code=start
class Solution
{
public:
    bool isScramble(string s1, string s2)
    {
        if (s1 == s2)
            return true;
        if (s1.length() != s2.length())
            return false;
        int a[26] = {0};
        for (int i = 0; i < s1.length(); i++)
        {
            a[s1[i] - 'a']--;
            a[s2[i] - 'a']++;
        }
        for (int i = 0; i < 26; i++)
            if (a[i] != 0)
                return false;
        for (int i = 1; i < s1.length(); i++)
        {
            // cout << i << ' ';
            if (isScramble(s1.substr(0, i), s2.substr(0, i)) && isScramble(s1.substr(i), s2.substr(i)))
            {
                cout << s1.substr(0, i) << ' ' << s2.substr(0, i) << ' ' << s1.substr(i) << ' ' << s2.substr(i) << endl;
                return true;
            }
            if (isScramble(s1.substr(0, i), s2.substr(s1.length() - i)) && isScramble(s1.substr(i), s2.substr(0, s1.length() - i)))
            {
                cout << s1.substr(0, i) << ' ' << s2.substr(s1.length() - i) << ' ' << s1.substr(i) << ' ' << s2.substr(0, s1.length() - i) << endl;
                return true;
            }
        }
        // cout << endl;
        return false;
    }
};
// @lc code=end
