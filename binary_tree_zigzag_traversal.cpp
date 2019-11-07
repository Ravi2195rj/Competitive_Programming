/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    
    vector<vector<int>> ans;
    if(root==NULL)
        return ans;
   
    queue<TreeNode *> q1; 
    q1.push(root);
    int zigzag=0;
    while (1) 
    { 
     
        int n1 = q1.size();
 
        // If level order traversal is over   
        if (n1 == 0) 
            break; 
  
        // Dequeue all Nodes of current level and 
        // Enqueue all Nodes of next level 
        vector<int> curr_level;
        while (n1 > 0) 
        { 
            TreeNode *node1 = q1.front();
            q1.pop(); 
            
            curr_level.push_back(node1->val);
            
            if (node1->left != NULL) 
                q1.push(node1->left); 
            if (node1->right != NULL) 
                q1.push(node1->right); 
            n1--; 
  
        } 
        if(zigzag==1)
        {
            reverse(curr_level.begin(),curr_level.end());
                zigzag=0;
        }
        else
        {
            zigzag=1;
        }
        ans.push_back(curr_level);
    } 
    return ans;
    }
};
