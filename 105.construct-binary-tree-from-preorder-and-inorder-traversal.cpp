/*
 * @lc app=leetcode id=105 lang=cpp
 *
 * [105] Construct Binary Tree from Preorder and Inorder Traversal
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
    TreeNode *f(vector<int> &preorder, vector<int> &inorder, int p1, int p2, int i1, int i2)
    {
        // cout << "preorder ";
        // for (int j = p1; j < p2; j++)
        // {
        //     cout << preorder[j] << ' ';
        // }
        // cout << endl;
        // cout << "inorder ";
        // for (int j = i1; j < i2; j++)
        // {
        //     cout << inorder[j] << ' ';
        // }
        // cout << endl
        //      << endl;
        if (p1 >= p2)
            return NULL;
        if (i1 >= i2)
            return NULL;
        int a1 = 0; // a1 is pointer in preorder
        for (int i = p1; i < p2; i++)
        {
            if (preorder[i] == inorder[i1])
            {
                a1 = i;
                break;
            }
        }
        int a2 = 0; // a2 is pointer in inorder
        a2 = i1 + (a1 - p1);
        TreeNode *ans = new TreeNode(inorder[i1], f(preorder, inorder, p1, a1, i1 + 1, a2 + 1), f(preorder, inorder, a1 + 1, p2, a2 + 1, i2));
        return ans;
    }

    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        int p = preorder.size();
        int i = inorder.size();
        return f(inorder, preorder, 0, p, 0, i);
    }
};
// @lc code=end
