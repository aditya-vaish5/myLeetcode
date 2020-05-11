/*
 * @lc app=leetcode id=71 lang=cpp
 *
 * [71] Simplify Path
 */

// @lc code=start
class Solution
{
public:
    string simplifyPath(string path)
    {
        stack<string> s;
        path += '/';
        string t = "";
        int dots = 0;
        for (char c : path)
        {
            if (!s.empty())
                cout << s.top() << endl;
            if (c == '/')
            {
                if (dots == 1 && t.length() == dots)
                {
                    dots = 0;
                    t = "";
                }
                else if (dots == 2 && t.length() == dots)
                {
                    if (!s.empty())
                        s.pop();
                    t = "";
                    dots = 0;
                }
                else
                {
                    if (t.length() != 0)
                        s.push(t);
                    dots = 0;
                    t = "";
                }
            }
            else if (c == '.')
            {
                t += c;
                dots++;
            }
            else
            {
                t += c;
            }
        }
        t = "";
        while (!s.empty())
        {
            if (s.top().length() == 0)
            {
                s.pop();
                continue;
            }
            t = '/' + s.top() + t;
            s.pop();
        }
        if (t.length() == 0)
            return "/";
        return t;
    }
};
// @lc code=end
