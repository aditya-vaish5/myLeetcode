/*
 * @lc app=leetcode id=207 lang=cpp
 *
 * [207] Course Schedule
 */

// @lc code=start
class Solution {
public:
    set<int> st;
    vector<int> edge[10000];
    set<int> havedone;
    bool dfs(int i){
        havedone.insert(i);
        cout << i << ' ';
        bool res =true;
        for(int x :edge[i]){
            if(st.find(x) != st.end()){
                return false;
            }
            st.insert(x);
            res = dfs(x);
            if(res == false) {
                return false;
            }
            st.erase(x);
        }
        return res;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        for(auto pre : prerequisites){
            edge[pre[0]].push_back(pre[1]);
        }
        bool ans = true;
        for(int i = 0 ; i<numCourses ; i++){
            if(havedone.find(i)!=havedone.end()){
                continue;
            }
            st.clear();
            bool curr = dfs(i);
            cout <<'\n'<< "After running above dfs "<<  i << ' ' <<curr << '\n';
            if(curr == false){
                return curr;
            }
        }
        return true;
    }
};
// @lc code=end

