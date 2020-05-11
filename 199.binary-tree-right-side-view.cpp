/*
 * @lc app=leetcode id=199 lang=cpp
 *
 * [199] Binary Tree Right Side View
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int arr[5000];
    int size =-1;
    void dfs(TreeNode *root,int curr){
        if(root == NULL){
            return;
        }
        size = max(size,curr);
        dfs(root->left,curr+1);
        arr[curr] = root->val;
        dfs(root->right,curr+1);
    }
    vector<int> rightSideView(TreeNode* root) {
        dfs(root,0);
        vector<int > ans;
        for(int i=0;i<size+1;i++){
            ans.push_back(arr[i]);
        }
        return ans;
    }
};
// @lc code=end

