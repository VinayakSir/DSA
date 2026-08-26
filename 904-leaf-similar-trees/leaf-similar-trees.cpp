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
    
void fillLeaf(TreeNode*root,vector<int>&v){
    if(!root)return ;
    if(!root->left && !root->right){
        v.push_back(root->val);
    }
    fillLeaf(root->left,v);
    fillLeaf(root->right,v);
}


bool leafSimilar(TreeNode *root1, TreeNode *root2)
{
    if(!root1 && !root2)return true;
    if(!root1 || !root2)return false;
    vector<int>a,b;
    fillLeaf(root1,a);
    fillLeaf(root2,b);
    if(a.size()!=b.size())return false;
    for (int i = 0; i < a.size(); i++)
    {
        if(a[i]!=b[i])return false;
    }
    return true;
    
}
};