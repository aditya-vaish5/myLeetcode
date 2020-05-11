/*
 * @lc app=leetcode id=79 lang=cpp
 *
 * [79] Word Search
 */

// @lc code=start
class Solution
{
public:
    int m, n;
    int x[201][201];
    bool f(vector<vector<char>> &board, string &word, int i, int j, int curr)
    {
        if (x[i][j] != -1)
        {
            // cout <<  'h' << ' '<<i << ' '<< j <<endl;
            return false;
        }
        // cout << "making " << i << ' ' << j << " to " << 1 << endl; 
        if (word[curr] != board[i][j])
        {
            // cout << 'i' <<endl;
            return false;
        }
        x[i][j] = 1;
        // cout << word << " " << board[i][j]<<' '<< i << ' '<< j << ' '<<curr<<endl;

        if (curr == word.length()-1)
        {
            return true;
        }
        bool ans = false;
        if (i + 1 < m && f(board, word, i + 1, j, curr + 1))
        {
            return true;
        }
        if (i - 1 >= 0 && f(board, word, i - 1, j, curr + 1))
        {
            return true;
        }
        if (j + 1 < n && f(board, word, i, j + 1, curr + 1))
        {
            return true;
        }
        if (j - 1 >= 0 && f(board, word, i, j - 1, curr + 1))
        {
            return true;
        }
        x[i][j] = -1;
        // cout << "cooled" <<endl;
        return false;
    }
    bool exist(vector<vector<char>> &board, string word)
    {
        m = board.size();
        if (m == 0)
            return false;
        n = board[0].size();
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] == word[0])
                {
                    memset(x, -1, sizeof(x));
                    if (f(board, word, i, j, 0))
                        return true;
                }
            }
        }
        return false;
    }
};
// @lc code=end
