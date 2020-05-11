/*
 * @lc app=leetcode id=165 lang=cpp
 *
 * [165] Compare Version Numbers
 */

// @lc code=start
class Solution {
public:
    string f(string k){
        string ans = k;
        int len = ans.length();
        deque<string> arr;
        
        string t ="";
        for(int i =len-1;i>=0;i--){
            if(ans[i] == '.'){
                arr.push_front(t);
                t ="";
            }else{
                t = ans[i] + t;
            }
        }
        int l = arr.size();
        for(int i =l-1;i>=0;i--){
            if(stoi(arr[i]) == 0){
                arr.pop_back();
            }else{
                break;
            }
        }
        string res = t;
        for(string h : arr){
            res = res + "." + h;
        }
        return res;
    }
    int compareVersion(string version1, string version2) {
        string ver1 = f(version1) + '.';
        string ver2 = f(version2) + '.';
        cout << ver1 << ' ' << ver2 << endl;
        int i1 =0,i2 =0;
        int len1 = ver1.length(),len2 =ver2.length();   
        string t1;
        string t2;
        int x, y;
        while(true){
            if(i1 == len1 && i2 ==len2){
                return 0;
            }
            if(i1 == len1){
                return -1;
            }
            if(i2 == len2){
                return 1;
            }
            t1 = "0";
            t2 = "0";
            bool xx = true;
            while(ver1[i1] != '.'){
                // if(xx && ver1[i1]=='0'){
                //     i1++;
                //     continue;
                // }
                // xx =false;
                t1 = t1 + ver1[i1]; 
                i1++;
            }
            i1++;
            xx =true;
            while(ver2[i2] != '.'){
                // if(xx && ver2[i2] == '0'){
                //     i2++;
                //     continue;
                // }
                // xx =false;
                t2 = t2 + ver2[i2]; 
                i2++;
            }
            i2++;
            cout << t1 << "    " << t2 << endl;
            x = stoi(t1);
            y = stoi(t2);
            if(x>y) return 1;
            if(y>x) return -1;
        }
        return 0;
    }
};
// @lc code=end

