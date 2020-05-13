/*
 * @lc app=leetcode id=80 lang=cpp
 *
 * [80] Remove Duplicates from Sorted Array II
 */

// @lc code=start
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int j=0,curr =0 ,count =0,total =0;
        for(int i =0;i<n;i++){
            curr = nums[i];
            count =1;
            while(i+1<n && curr == nums[i+1]){
                count++;
                i++;
            }
            if(count){ nums[j++] =curr;count--;total++;}
            if(count){ nums[j++] =curr;count--; total++;}
        }
        nums.resize(j);
        return nums.size();
    }
};
// @lc code=end
