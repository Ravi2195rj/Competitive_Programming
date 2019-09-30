/*
Link - https://leetcode.com/problems/validate-binary-search-tree
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

bool bstUtil(TreeNode *root, TreeNode* low, TreeNode *high){
    if(root == NULL)
        return true;
    if(low != NULL && root->val <= low->val)
        return false;
    if(high != NULL && root->val >= high->val)
        return false;
    return (bstUtil(root->left, low, root) && bstUtil(root->right, root, high));
}

bool isValidBST(TreeNode* root) {
    if(root == NULL)
        return true;
    return (bstUtil(root, NULL, NULL));
}