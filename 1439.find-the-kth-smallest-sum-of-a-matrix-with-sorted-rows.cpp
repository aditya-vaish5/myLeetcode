/*
 * @lc app=leetcode id=1439 lang=cpp
 *
 * [1439] Find the Kth Smallest Sum of a Matrix With Sorted Rows
 */

// @lc code=start
class Solution
{
public:
    int kthSmallest(vector<vector<int>> &mat, int k)
    {
        if (k == 0)
            return 0;
        vector<int> prev = mat[0];
        int m = mat.size();
        if (m == 0)
            return 0;
        int n = mat[0].size();
        cout  << m << ' ' << n;
        if(m==1) return mat[0][k-1];
        vector<int> fresh;
        for (int i = 1; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                for (int kt : prev)
                {
                    fresh.push_back(kt + mat[i][j]);
                }
            }
            sort(fresh.begin(), fresh.end());
            int q = k < fresh.size() ? k : fresh.size();
            fresh.resize(q);
            for (int x : fresh)
                cout << x << ' ';
            cout << endl;
            // vector<int> :: iterator it = fresh.begin();
            prev.assign(fresh.begin(), fresh.end());
            fresh.clear();
        }
        return fresh[k - 1];
    }
};
// @lc code=end
