/*
 * @lc app=leetcode id=152 lang=cpp
 *
 * [152] Maximum Product Subarray
 */

// @lc code=start
class Solution
{
public:
    int find(const vector<int> &nums, int l, int r)
    {
        if (l == r)
        {
            return 0;
        }
        vector<int> arr;
        int neg = 0;
        int prod = 1;
        if (l == r - 1)
        {
            return nums[l];
        }
        int k = 1;
        int curr = INT_MIN;
        for (int i = l; i < r; i++)
        {
            if (nums[i] < 0)
            {
                curr = max(prod, curr);
                arr.push_back(prod);
                arr.push_back(nums[i]);
                prod = 1;
                neg++;
            }else{
                prod *= nums[i];
            }
            k *= nums[i];

        }
        curr = max(curr,prod);
        cout  << "l = " << l << " r = " << r <<endl ;
        cout << "k = " << k << endl;
        cout << "curr = " << curr << endl << endl;
        arr.push_back(prod);
        for(int j : arr) {
            cout << j << ' ' ;
        }
        if (k > 0)
        {
            return k;
        }
        else
        {
            return max(curr, max(k / (arr[0] * arr[1]), k / (arr[arr.size() - 1] * arr[arr.size() - 2])));
        }
    }
    int maxProduct(vector<int> &nums)
    {
        int big = INT_MIN;
        for (int i : nums)
        {
            big = max(big, i);
        }
        // if (big == 0)
        // {
        //     return 0;
        // }
        nums.push_back(0);
        int n = nums.size();
        int prod = 1;
        int prev = 0;
        int ans = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            prod = nums[i];
            if (prod == 0)
            {
                ans = max(ans, find(nums, prev, i));
                prev = i + 1;
            }
        }
        return max(big,ans);
    }
};
// @lc code=end
