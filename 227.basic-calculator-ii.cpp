/*
 * @lc app=leetcode id=227 lang=cpp
 *
 * [227] Basic Calculator II
 */

// @lc code=start
class Solution
{
public:
    int calculate(string s)
    {
        istringstream in('+' + s + '+');
        long long total = 0, term = 0, n;
        char op;
        while (in >> op)
        {
            if (op == '+' or op == '-')
            {
                total += term;
                in >> term;
                term *= 44 - op;
            }
            else
            {
                in >> n;
                if (op == '*')
                    term *= n;
                else
                    term /= n;
            }
        }
        return total;
    }
};
// @lc code=end
