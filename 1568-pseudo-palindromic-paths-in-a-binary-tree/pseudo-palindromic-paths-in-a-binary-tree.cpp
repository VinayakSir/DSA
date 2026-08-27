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
    
    
void solvePalindrome(TreeNode* root, int temp,int &result) {
    if(root != NULL) {
        
        temp = temp ^ (1 << root->val);
        
        if(!root->left && !root->right ) {
            if((temp & (temp - 1)) == 0)                 result++;
            
        }
        
        
        solvePalindrome(root->left, temp,result);
        solvePalindrome(root->right, temp,result);


    }
}

int pseudoPalindromicPaths (TreeNode* root) {

    int result=0;
    solvePalindrome(root, 0,result);
    return result;
}



};