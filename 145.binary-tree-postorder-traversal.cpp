/*
 * @lc app=leetcode id=145 lang=cpp
 *
 * [145] Binary Tree Postorder Traversal
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
    vector<int> postorderTraversal(TreeNode *root)
    {
        if (!root)
            return {};
        vector<int> v;
        stack<TreeNode *> stk;
        stack<int> postOrdervals;
        stk.push(root);
        while (!stk.empty())
        {
            TreeNode *temp = stk.top();
            stk.pop();
            if (temp->left)
                stk.push(temp->left);
            if (temp->right)
                stk.push(temp->right);
            postOrdervals.push(temp->val);
        }
        while (!postOrdervals.empty())
        {
            v.push_back(postOrdervals.top());
            postOrdervals.pop();
        }
        return v;
    }
};
// @lc code=end
