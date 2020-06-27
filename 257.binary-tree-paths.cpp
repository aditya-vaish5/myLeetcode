/*
 * @lc app=leetcode id=257 lang=cpp
 *
 * [257] Binary Tree Paths
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
class Solution
{
public:
    vector<string> arr;
    void f(TreeNode *root, string curr)
    {
        if (root->left == NULL && root->right == NULL)
        {
            arr.push_back(curr);
        }
        else
        {
            if (root->left != NULL)
                f(root->left, curr + "->" + to_string(root->left->val));
            if (root->right != NULL)
                f(root->right, curr + "->" + to_string(root->right->val));
        }
    }
    vector<string> binaryTreePaths(TreeNode *root)
    {
        if(root == NULL) return arr;
        string t = to_string(root->val);
        if (root->left == NULL && root->right == NULL)
        {
            arr.push_back(t);
            return arr;
        }
        f(root,t);
        // if (root->left != NULL)
        //     f(root->left, t);
        // if (root->right != NULL)
        //     f(root->right, t);
        return arr;
    }
};
// @lc code=end
