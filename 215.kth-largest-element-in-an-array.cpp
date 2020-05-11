/*
 * @lc app=leetcode id=215 lang=cpp
 *
 * [215] Kth Largest Element in an Array
 */

// @lc code=start
class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        map<int, int> st;
        int n = nums.size();
        int size = 0;
        int high = INT_MIN, low = INT_MAX;
        for (int i = 0; i < k; i++)
        {
            cout << "pushing" << nums[i] << endl; 
            if (st.find(nums[i]) != st.end())
                st[nums[i]]++;
            else
                st[nums[i]] = 1;
            high = max(high, nums[i]);
            low = min(low, nums[i]);
        }
        for (int i = k; i < n; i++)
        {
            if (nums[i] > low)
            {
                cout << "popping" << low << endl;
                if (st[low] > 1)
                    st[low]--;
                else
                    st.erase(low);
                cout << "pushing" << nums[i] <<endl;
                if (st.find(nums[i]) != st.end())
                    st[nums[i]]++;
                else
                    st[nums[i]] = 1;
                low = st.cbegin()->first;
                // cout << "new low = " <<low << endl;
            }
        }
        cout << low;
        return low;
    }
};
// @lc code=end
