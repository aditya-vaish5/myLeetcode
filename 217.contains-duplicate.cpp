/*
 * @lc app=leetcode id=217 lang=cpp
 *
 * [217] Contains Duplicate
 */

// @lc code=start
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int ,int> u;
        for(int i : nums){
            if(u.find(i) != u.end()) return true;
            u[i] =1;
        }
        return false;
    }
};
// @lc code=end

