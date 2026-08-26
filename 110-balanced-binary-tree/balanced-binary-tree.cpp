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
int SolveIsBalanced(TreeNode*root,bool & valid){
    if(!root)return 0;
    int left=SolveIsBalanced(root->left,valid);
    int right=SolveIsBalanced(root->right,valid);
    if(abs(left-right)>1) valid=0;
    return 1+max(left,right);
}
bool isBalanced(TreeNode* root) 
{
    bool valid=1;
    SolveIsBalanced(root,valid);    
    return valid;   
}
};