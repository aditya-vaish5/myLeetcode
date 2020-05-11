/*
 * @lc app=leetcode id=1422 lang=cpp
 *
 * [1422] Maximum Score After Splitting a String
 */

// @lc code=start
class Solution {
public:
    int maxScore(string s) {
        int n = s.length();
        int ones = 0,zeros=0;
        for(char c : s) {
            if(c=='1')
                ones++;
        }
        int ans =0;
        int l =0, r= ones;
        for(int i=0;i<n-1;i++){
            char c=s[i];
            if(c=='0'){
                l++;
            }else{
                r--;
            }
            ans = max(ans,l+r);
        } 
        return ans ;
    }
};
// @lc code=end

