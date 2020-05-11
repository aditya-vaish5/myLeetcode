/*
 * @lc app=leetcode id=150 lang=cpp
 *
 * [150] Evaluate Reverse Polish Notation
 */

// @lc code=start
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        int a ,b;
        for(string i:tokens){
            if(i.length()==1){
                    if(i[0] =='+'){
                    a= s.top();
                    s.pop();
                    b= s.top();
                    s.pop();
                    s.push(b+a);
                }else if(i[0] =='-'){
                    a= s.top();
                    s.pop();
                    b= s.top();
                    s.pop();
                    s.push(b-a);
                }else if(i[0] =='*'){
                    a= s.top();
                    s.pop();
                    b= s.top();
                    s.pop();
                    s.push(b*a);
                }else if(i[0] =='/'){
                    a= s.top();
                    s.pop();
                    b= s.top();
                    s.pop();
                    s.push(b/a);
                }else{
                    a = stoi(i);
                    s.push(a);
                }
            }else{
                a = stoi(i);
                // cout << a<<endl;
                s.push(a);
            }
            // cout << i << ' '<<s.top()<<endl;
        }
        return s.top();
    }
};
// @lc code=end

