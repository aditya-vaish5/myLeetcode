/*
 * @lc app=leetcode id=60 lang=cpp
 *
 * [60] Permutation Sequence
 */

// @lc code=start
class Solution {
public:
    vector<int> reverse(vector<int> x){
        vector<int> k;
        for(int i= x.size()-1;i>=0;i--){
            k.push_back(x[i]);

        }return k;
    }
    string getPermutation(int n, int num) {
        string ans = "";
        string temp = "";
        for(int i=1;i<=n;i++){

            char ch = '0' + i;
            temp = temp + ch;
        }
        cout << ans << ' ' << temp  << endl;
        int k = num;
        k--;
        vector<int> arr;
        int t=1;
        for(int i =1; i<n;i++){
            t*=i;
            cout << t << ' ' ;
            arr.push_back(t);
        }
        arr=reverse(arr);
        cout <<endl;

        for(int i : arr){
            int curr = k/i;
            char c = temp.at(curr);
            cout << curr << "=" << c  << ' ';
            ans.push_back(c);
            temp.erase(curr,1);
            k = k%i;
        }
        cout << endl ;
        cout << ans << ' ' << temp  << endl;
        ans.push_back(temp[0]);
        return ans;
    }
};
// @lc code=end

