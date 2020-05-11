/*
 * @lc app=leetcode id=58 lang=cpp
 *
 * [58] Length of Last Word
 *
 * https://leetcode.com/problems/length-of-last-word/description/
 *
 * algorithms
 * Easy (32.48%)
 * Likes:    574
 * Dislikes: 2234
 * Total Accepted:    352.5K
 * Total Submissions: 1.1M
 * Testcase Example:  '"Hello World"'
 *
 * Given a string s consists of upper/lower-case alphabets and empty space
 * characters ' ', return the length of last word (last word means the last
 * appearing word if we loop from left to right) in the string.
 * 
 * If the last word does not exist, return 0.
 * 
 * Note: A word is defined as a maximal substring consisting of non-space
 * characters only.
 * 
 * Example:
 * 
 * 
 * Input: "Hello World"
 * Output: 5
 * 
 * 
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    void f(string &s){
        int n= s.length();
        for(int i=n-1;i>=0;i--){
            if(s[i]==' '){
                s.erase(i);
            }
            else{
                break;
            }
        }
    }
    int lengthOfLastWord(string s) {
        
        f(s);
        if(s.length()==0)
            return 0;
        int n=s.length();
        int curr = -1;
        for(int i=n-1;i>=0;i--){
            if(s[i]==' '){
                curr =i;
                break;
                
            }
        }
        return n-curr-1;
    }
};
// @lc code=end

