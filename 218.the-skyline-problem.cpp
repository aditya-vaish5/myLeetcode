/*
 * @lc app=leetcode id=218 lang=cpp
 *
 * [218] The Skyline Problem
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& building) {
        vector<pair<int,int>> ans;
        priority_queue<pair<int ,int>> m;
        int cur=0,cur_X, cur_H=-1;
        int n = building.size();
        priority_queue<pair<int,int>> all;//height,end time
        while(cur < n || !all.empty()){
            cur_X = all.empty() ? building[cur][0] : all.top().second;
            if(cur >= n || building[cur][0] > cur_X){
                while(!all.empty() && all.top().second <= cur_X){
                    all.pop();
                }
            }
            else{
                cur_X = building[cur][0];
                while(cur<n && building[cur][0] == cur_X){
                    all.push(make_pair(building[cur][2],building[cur][1]));
                    cur++;
                }
            }
            cur_H = all.empty()?0:all.top().first;
            if(ans.empty() || (ans.back().second != cur_H)){
                ans.push_back(make_pair(cur_X,cur_H));
            }
        }
        vector<vector<int>> cool;
        vector<int> t;
        for(auto j:ans){
            t.push_back(j.first);
            t.push_back(j.second);
            cool.push_back(t);
            t.pop_back();
            t.pop_back();
        }
        return cool;
    }
};
// @lc code=end

