/*
 * @lc app=leetcode id=241 lang=cpp
 *
 * [241] Different Ways to Add Parentheses
 */

// @lc code=start
class Solution
{
public:
    vector<int> arr;
    vector<int> sign;
    vector<int> merge(vector<int> a, vector<int> b, int d)
    {
        vector<int> res;
        if (d == 0)
        {
            for (auto i : a)
            {
                for (auto j : b)
                {
                    res.push_back(i + j);
                }
            }
        }
        if (d == 1)
        {
            for (auto i : a)
            {
                for (auto j : b)
                {
                    res.push_back(i - j);
                }
            }
        }
        if (d == 2)
        {
            for (auto i : a)
            {
                for (auto j : b)
                {
                    res.push_back(i * j);
                }
            }
        }
        return res;
    }
    vector<int> f(int l, int r)
    {
        // cout << l << " and " << r << endl;
        vector<int> ans, temp;
        if (l == r)
        {
            // cout << "here" << l <<endl;
            ans.push_back(arr[l]);
            return ans;
        }
        for (int i = l; i < r; i++)
        {
            cout << i << endl;
            temp = merge(f(l, i), f(i + 1, r), sign[i]);
            for (int k : temp)
            {
                ans.push_back(k);
            }
        }
        return ans;
    }
    vector<int> diffWaysToCompute(string input)
    {
        int num = 0;
        input = input + ' ';
        for (int i = 0; i < input.length(); i++)
        {
            char c = input[i];
            int num = 0;
            while (c <= '9' && c >= '0')
            {
                num = num * 10 + (c - '0');
                i++;
                c = input[i];
            }
            arr.push_back(num);
            if (c == '+')
            {
                sign.push_back(0);
            }
            if (c == '-')
            {

                sign.push_back(1);
            }
            if (c == '*')
            {
                sign.push_back(2);
            }
        }
        for (int j : arr)
        {
            cout << j << ' ';
        }
        cout << endl;
        for (int j : sign)
        {
            cout << j << ' ';
        }
        cout << endl;
        return f(0, arr.size() - 1);
    }
};
// @lc code=end
