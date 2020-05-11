/*
 * @lc app=leetcode id=67 lang=cpp
 *
 * [67] Add Binary
 */

// @lc code=start
class Solution
{
public:
    string addBinary(string a, string b)
    {
        string ans = "";
        if (b.length() > a.length())
        {
            cout << "yes" << endl;
            return addBinary(b, a);
        }
        int i;
        int as = a.length();
        int bs = b.length();
        bool prev = false;
        for (i = b.size() - 1; i >= 0; i--)
        {
            bool p = a[as - bs + i] == '1';
            bool q = b[i] == '1';
            int count = 0;
            if (p)
                count++;
            if (q)
                count++;
            if (prev)
                count++;
            if (count == 0)
            {
                ans = '0' + ans;
            }
            else if (count == 1)
            {
                ans = '1' + ans;
                prev = false;
            }
            else if (count == 2)
            {
                ans = '0' + ans;
                prev = true;
            }
            else
            {
                prev = true;
                ans = '1' + ans;
            }
        }
        cout << ans << ' ' << prev << ' '<< as<< ' '<< bs<< endl;
        for (int i = as-bs-1; i >=0; i--)
        {
            if (prev)
            {
                if (a[i] == '1')
                {
                    ans = '0' + ans;
                }
                else
                {
                    prev = false;
                    ans = '1' + ans;
                }
            }
            else
            {
                ans = a[i] + ans;
            }
        }
        if (prev)
        {
            ans = '1' + ans;
        }
        return ans;
    }
};
// @lc code=end
