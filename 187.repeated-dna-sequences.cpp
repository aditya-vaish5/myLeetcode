/*
 * @lc app=leetcode id=187 lang=cpp
 *
 * [187] Repeated DNA Sequences
 */

// @lc code=start
class Solution
{
public:
    int ax(string x)
    {
        int re = 0;
        int num;
        for (int i = 0; i < 10; i++)
        {
            if (x[i] == 'A')
            {
                num = 0;
            }
            else if (x[i] == 'G')
            {
                num = 1;
            }
            else if (x[i] == 'C')
            {
                num = 2;
            }
            else if (x[i] == 'T')
            {
                num = 3;
            }
            re = re * 4;
            re += num;
        }

        return re;
    }
    char g(int x)
    {
        if (x == 0)
        {
            return 'A';
        }
        if (x == 1)
        {
            return 'G';
        }
        if (x == 2)
        {
            return 'C';
        }
        if (x == 3)
        {
            return 'T';
        }
        return 0;
    }
    string b(int x)
    {
        string t = "";
        for (int i = 0; i < 10; i++)
        {
            char c = g(x % 4);
            t = c + t;
            x /= 4;
        }
        return t;
    }
    vector<string> findRepeatedDnaSequences(string s)
    {
        unordered_map<int, bool> u, x;
        vector<string> ans;
        int n = s.length();
        string t = "";
        for (int i = 0; i < n - 9; i++)
        {
            t = s.substr(i, 10);
            int k = ax(t);
            if (u.find(k) != u.end())
            {
                x[k] = true;
            }
            u[k] = true;
            cout << t << ' ' << k << ' ' << b(k) << endl;
        }
        for (auto j : x)
        {
            ans.push_back(b(j.first));
        }
        return ans;
    }
};
// @lc code=end
