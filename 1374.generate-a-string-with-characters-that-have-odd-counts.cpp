/*
 * @lc app=leetcode id=1374 lang=cpp
 *
 * [1374] Generate a String With Characters That Have Odd Counts
 *
 * https://leetcode.com/problems/generate-a-string-with-characters-that-have-odd-counts/description/
 *
 * algorithms
 * Easy (76.11%)
 * Likes:    46
 * Dislikes: 215
 * Total Accepted:    17.6K
 * Total Submissions: 23.2K
 * Testcase Example:  '4'
 *
 * Given an integer n, return a string with n characters such that each
 * character in such string occurs an odd number of times.
 * 
 * The returned string must contain only lowercase English letters. If there
 * are multiples valid strings, return any of them.  
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: n = 4
 * Output: "pppz"
 * Explanation: "pppz" is a valid string since the character 'p' occurs three
 * times and the character 'z' occurs once. Note that there are many other
 * valid strings such as "ohhh" and "love".
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: n = 2
 * Output: "xy"
 * Explanation: "xy" is a valid string since the characters 'x' and 'y' occur
 * once. Note that there are many other valid strings such as "ag" and "ur".
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: n = 7
 * Output: "holasss"
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= n <= 500
 * 
 */

// @lc code=start
class Solution {
public:
    string generateTheString(int n) {
        string k = "";
        if(n==0) return k;
        string s(n,'a');
        if(n%2==0){
            s[0]='b';
        }
        return s;
    }
};
// @lc code=end

