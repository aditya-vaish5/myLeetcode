/*
 * @lc app=leetcode id=216 lang=cpp
 *
 * [216] Combination Sum III
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> temp;
    int t;
    void f(int k,int n,int curr_sum,int curr_max){
        if(curr_sum == n && k == 0){
            ans.push_back(temp);
        }
        if(curr_sum >=n) return;
        if(k == 0 )return;
        for(int i =curr_max+1;i<10;i++){
            // if(i <=curr_max) continue;
            int x = 1 << i;
            if(!(t & x)){
                t += x;
                temp.push_back(i);
                f(k-1,n,curr_sum +i,i);
                temp.pop_back();
                t-=x;
            }
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        t=0;
        f(k,n,0,0);
        return ans;
    }
};
// @lc code=end

