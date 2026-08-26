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
   int solveForDiameter(TreeNode*root,int &diameter){
    if(!root)return 0;
    int left=solveForDiameter(root->left,diameter);
    int right=solveForDiameter(root->right,diameter);
    diameter=max(diameter,left+right);
    return 1+max(left,right);
}
int diameterOfBinaryTree(TreeNode* root) {
  int diameter=0;
  solveForDiameter(root,diameter);
  return diameter;      
}
};