/*
 * @lc app=leetcode id=1424 lang=cpp
 *
 * [1424] Diagonal Traverse II
 */

// @lc code=start
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        map<int,stack<int>> u;
        for(int i =0;i<nums.size();i++){
            for(int j=0;j<nums[i].size();j++){
                // cout << nums[i][j] << ' ';
                u[i+j].push(nums[i][j]);
            }
        }
        cout << endl;
        vector<int> ans;
        for(auto it = u.begin();it!=u.end();it++){
            while(!it->second.empty()){
                // cout << it->second.top() << ' ';
                ans.push_back(it->second.top());
                it->second.pop();
            }
            cout << endl;
        }
        return ans;
    }
};
// @lc code=end