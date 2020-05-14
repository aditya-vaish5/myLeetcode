/*
 * @lc app=leetcode id=85 lang=cpp
 *
 * [85] Maximal Rectangle
 */

// @lc code=start
class Solution
{
public:
    int maximalRectangle(vector<vector<char>> &matrix)
    {
        int m = matrix.size();
        if (m == 0)
            return 0;
        int n = matrix[0].size();
        int l[n], r[n], h[n];
        for (int i = 0; i < n; i++)
        {
            h[i]=0;
            l[i]=0;
            r[i] = n - 1;
        }
        int ans = 0;
        //left bound ,right bound , height of the rectangle
        for (int i = 0; i < m; i++)
        {
            //height of current row histogram
            cout << "height = ";
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][j] == '0')
                {
                    h[j] = 0;
                }
                else
                {
                    h[j]++;
                }
                cout << h[j] << ' ';
            }
            cout << endl;
            cout << "left   = ";
            int curr_l = 0;
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][j] == '1')
                {
                    l[j] = max(l[j], curr_l);
                }
                else
                {
                    curr_l = j + 1;
                    l[j] = 0;
                }
                cout << l[j] << ' ';
            }
            cout << endl;
            cout << "right  = ";
            int curr_r = n - 1;
            for (int j = n - 1; j >= 0; j--)
            {
                if (matrix[i][j] == '1')
                {
                    r[j] = min(r[j], curr_r);
                }
                else
                {
                    curr_r = j - 1;
                    r[j] = n - 1;
                }
            }
            for (int j = 0; j < n; j++)
            {
                ans = max(ans, h[j] * (r[j] - l[j] + 1));
                cout << r[j] << ' ';
            }
            cout << endl;
            cout << endl;
        }
        return ans;
    }
};
// @lc code=end
