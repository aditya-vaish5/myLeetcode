/*
 * @lc app=leetcode id=66 lang=cpp
 *
 * [66] Plus One
 */

// @lc code=start
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        int carry =1;
        for(int i=n-1;i>=0;i--){
            if(carry == 0){
                return digits;
            }
            int t = digits[i]+carry; 
            digits[i] = t%10;
            carry = t/10;
        }
        if(carry){
            digits.emplace(digits.begin(),1);
        }
        return digits;
    }
};
// @lc code=end

