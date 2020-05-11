/*
 * @lc app=leetcode id=162 lang=cpp
 *
 * [162] Find Peak Element
 */

// @lc code=start
class Solution
{
public:
    int findPeakElement(vector<int> &nums)
    {
        int n =nums.size();
        if(n==1){
            return 0;
        }
        int l = 0,r= n-1;
        int mid;
        bool check;
        while(l<=r){
            if(l==r){
                return l;
            }
            mid = (l+r)/2;
            if(nums[mid] < nums[mid+1])
                l = mid+1;
            else r = mid;
        }
        return -1;
    }
};
// @lc code=end
