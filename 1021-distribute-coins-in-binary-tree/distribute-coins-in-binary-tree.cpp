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
    int solveCoins(TreeNode*root,int &moves)
{
     if(root == NULL)         return 0;
    
        
        int l = solveCoins(root->left, moves);
        int r = solveCoins(root->right, moves);
        
        int total_extra_candies = (l + r + root->val) - 1;
        
        moves += abs(l) + abs(r);
        
        return total_extra_candies;
}



int distributeCoins(TreeNode* root) 
{
    if(!root)return 0;
    if(!root->left && !root->right)return 0;
    int moves=0;
    solveCoins(root,moves);
    return moves;        

}
};