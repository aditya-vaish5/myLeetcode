/*
 * @lc app=leetcode id=167 lang=cpp
 *
 * [167] Two Sum II - Input array is sorted
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        int l=0, r =n-1,sum;
        vector<int> ans;
        while(l<=r){
            sum = numbers[l] + numbers[r];
            if(sum  == target){
                ans.push_back(l+1);
                ans.push_back(r+1);
                return ans;                
            }
            if(sum > target){
                r--;
            }else{
                l++;
            }
        }
        return ans;

    }
};
// @lc code=end

