/*
 * @lc app=leetcode id=166 lang=cpp
 *
 * [166] Fraction to Recurring Decimal
 */

// @lc code=start
class Solution {
public:
    string fractionToDecimal(int n, int d) {
        long numerator = n;
        long denominator = d;
        bool sign = (numerator < 0 ^ denominator < 0)?true: false;
        numerator =abs(numerator);
        denominator = abs(denominator);
        long k = numerator/denominator;
        long rem = numerator % denominator;
        string ans = to_string(k);
        if(sign && numerator != 0) {
            ans = '-' + ans;
        }
        if(rem == 0){
            return ans;
        }
        unordered_map<int,int> u;
        bool isRep = false;
        long num;
        string after = "";
        string t ="";
        while(rem != 0){
            rem*=10;
            
            num = rem/denominator;
            rem = rem % denominator;
            if(u.find(rem)!=u.end()){
                t = t + to_string(num); 
                after = t.substr(u[rem]);
                t = t.substr(0,u[rem]);

                cout << t << ' ' << after <<  ' ' <<u[rem];
                isRep = true;
                break;
            }


            t = t + to_string(num);
            u[rem] = t.size();
        }
        if(isRep){
            return ans + "." + t +"(" + after + ")";
        }else{
            return ans + "." +t;
        }
    }
};
// @lc code=end

