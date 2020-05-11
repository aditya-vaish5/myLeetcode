/*
 * @lc app=leetcode id=153 lang=cpp
 *
 * [153] Find Minimum in Rotated Sorted Array
 */

// @lc code=start
class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        if(n==1 || nums[0]<nums[n-1]){
            return nums[0];
        }
        
        int l=0,r=n-1,mid;
        int ans = -1;
        while(l<=r){
            mid = (l+r)/2;
            if(nums[mid]>nums[mid+1]){
                ans = mid;
                break;
            }
            if(nums[mid]>nums[n-1]){
                l = mid+1;
            }else{
                r= mid-1;
            }

        }
        cout << ans;
        return nums[ans+1];
    }
};
// @lc code=end

