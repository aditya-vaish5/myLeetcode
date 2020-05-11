/*
 * @lc app=leetcode id=560 lang=cpp
 *
 * [560] Subarray Sum Equals K
 */

// @lc code=start
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> m;
        int sum = 0,count=0;
        m[0] =1;
        for(int i=0;i<n;i++){
            sum += nums[i];
            if(m.find(sum-k) != m.end()){
                count += m[sum-k];
            }
            if(m.find(sum) != m.end()){
                m[sum] ++;
            }
            else{
                m[sum] =1;
            }
            // cout << i << ' ' << count << ' ' << sum << endl;
        }
        return count;
    }
};
// @lc code=end

