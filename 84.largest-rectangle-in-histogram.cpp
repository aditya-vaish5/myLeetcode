/*
 * @lc app=leetcode id=84 lang=cpp
 *
 * [84] Largest Rectangle in Histogram
 */

// @lc code=start
class Solution
{
public:
void p(stack<pair<int,int>> stk){
    cout <<endl;
    while(!stk.empty()){
        cout << stk.top().first<<' ' << stk.top().second << endl;
        stk.pop();
    }
    cout << endl;
}
    int largestRectangleArea(vector<int> &heights)
    {
        // The question in done by using monotonic stack continuous
        // stack { index of current , value of at that index}
        stack<pair<int, int>> stk; // 1 5 6          1 2 3
        int ans = 0;
        int n = heights.size();
        if (n == 0)
            return 0;
        int lowest = heights[0];
        int left = 0;
        for (int i = 0; i < n; i++)
        {
            left = i;
            lowest = min(lowest, heights[i]);

            // cout << "running for value of " << heights[i] << ' ' << ans << endl;
            while (!stk.empty() && stk.top().second >= heights[i])
            {
                ans = max(ans, stk.top().second * (i - stk.top().first ));
                ans = max(ans, heights[i] * (i - stk.top().first + 1));
                left = stk.top().first;
                stk.pop();
            }
            if (!stk.empty())
            {
                ans = max(ans, stk.top().second * (i - stk.top().first + 1));
            }
            else
            {
                ans = max(ans, heights[i] * (i + 1));
            }
            ans = max(ans, heights[i]);
            // cout << "pushing " << left << ' ' << heights[i] << endl;
            stk.push(make_pair(left, heights[i]));
            // p(stk);
        }
        while (!stk.empty())
        {
            ans = max(ans, stk.top().second * (n - stk.top().first));
            // if(stk.size)
            stk.pop();
        }
        ans = max(ans, lowest * n);
        return ans;
    }
};
// @lc code=end
