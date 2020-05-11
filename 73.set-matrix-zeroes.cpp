/*
 * @lc app=leetcode id=73 lang=cpp
 *
 * [73] Set Matrix Zeroes
 */

// @lc code=start
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if(m==0) return ;
        int n = matrix[0].size();
        bool isRow1 =false,isCol1 =false;
        for(int i =0 ;i<n;i++){
            if(matrix[0][i] == 0) {
                isRow1 =true;
                break;
            }
        }
        for(int i =0 ;i<m;i++){
            if(matrix[i][0] == 0) {
                isCol1 =true;
                break;
            }
        }
        
        for(int i = 1;i<m;i++){
            for(int j =1;j< n;j++){
                if(matrix[i][j] == 0){
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        for(int i=1;i<n;i++){
            if(matrix[0][i]==0){
                for(int j =0;j<m;j++){
                    matrix[j][i] = 0;
                }
            }
        }
        for(int i=1;i<m;i++){
            if(matrix[i][0]==0){
                for(int j =0;j<n;j++){
                    matrix[i][j] = 0;
                }
            }
        }
        if(isCol1){
            for(int i=0;i<m;i++){
                matrix[i][0] =0 ;
            }
        }
        if(isRow1){
            for(int i=0;i<n;i++){
                matrix[0][i] =0 ;
            }
        }
    }
};
// @lc code=end

