/*
 * @lc app=leetcode id=137 lang=cpp
 *
 * [137] Single Number II
 */

// @lc code=start
// [43,16,45,89,45,-2147483648,45,2147483646,-2147483647,-2147483648,43,2147483647,-2147483646,-2147483648,89,-2147483646,89,-2147483646,-2147483647,2147483646,-2147483647,16,16,2147483646,43]
class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        vector<long> arr(20, 0);
        int curr;
        int sign = 0;
        for (int x : nums)
        {
            if(x>0)
                sign++;
            long long i = abs(x);
            // cout << i << " = " << endl;
            curr = 0;
            while (i != 0)
            {
                arr[curr] += i % 3;
                curr++;
                i /= 3;
                // cout << i << ' ' << arr[i] << ' ' << endl;
            }
            // cout << endl;
        }
        sign %=3;

        long long ans = 0;
        long long t = 1;
        for (int i = 0; i < 20; i++)
        {
            arr[i] = arr[i] % 3;
            // cout << arr[i] << ' ' << ans << endl;
            ans = ans + arr[i] *t;
            t*=3;
        }
        cout << sign;
        if(sign == 1)
            return ans;
        return -ans;
    }
};
// @lc code=end
