/*
 * @lc app=leetcode id=144 lang=cpp
 *
 * [144] Binary Tree Preorder Traversal
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
    vector<int> preorderTraversal(TreeNode *root)
    {
        stack<TreeNode *> s;
        s.push(root);
        vector<int> ans;
        TreeNode *temp;
        if (!root)
            return ans;
        while (!s.empty())
        {
            temp = s.top();
            s.pop();
            ans.push_back(temp->val);
            if (temp->right)
                s.push(temp->right);
            if (temp->left)
                s.push(temp->left);
        }
        return ans;
    }
};
// @lc code=end
