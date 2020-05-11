/*
 * @lc app=leetcode id=205 lang=cpp
 *
 * [205] Isomorphic Strings
 */

// @lc code=start
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char,char> m;
        map<char,char> left;
        if(s.length()!=t.length()) return false;
        char c1,c2;
        for(int i =0;i<s.length();i++){
            c1 = s[i];
            c2 = t[i];
            auto it = m.find(c1);
            if(it != m.end()){
                if(it->second != c2){
                    return false;
                }
            }else{
                if(left.find(c2) == left.end()){
                    m[c1] =c2;
                    left[c2] =c2;
                }
                else{
                    return false;
                }
            }
        }
        return true;
    }
};
// @lc code=end

