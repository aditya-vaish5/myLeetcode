/*
 * @lc app=leetcode id=242 lang=cpp
 *
 * [242] Valid Anagram
 */

// @lc code=start
class Solution {
public:
    bool isAnagram(string s, string t) {
        int arr[1000];
        memset(arr,0,sizeof(arr));
        // for(int i =0;i<1000;i++){
            // cout << arr[i] << ' ' ;
            // if(i%25 ==0 ) cout << endl;
        // }
        for(char i:s){
            arr[i]++;
            // cout <<  arr[i] << ' ';
        }
        // cout << endl;
        for(char i:t){
            arr[i]--;
            // cout << arr[i] << ' ';
        }
        // cout << endl;
        int n = 1000;
        // for(int i =0)
        for(int i=0;i<n;i++){
            // cout  << i << ' ';
            if(arr[i]!=0) return false;
        }
        return true;
    }
};
// @lc code=end

