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
    pair<int, int> solveforavg(TreeNode* root,int &result) {
    if(!root)
        return {0, 0};
    
    pair<int, int> l = solveforavg(root->left,result);
    pair<int, int> r = solveforavg(root->right,result);
    
    int leftSum   = l.first;
    int leftCount = l.second;
    
    int rightSum   = r.first;
    int rightCount = r.second;
    
    int SUM   = leftSum + rightSum + root->val;
    int COUNT = leftCount + rightCount + 1;
    
    int avg = SUM/COUNT;
    
    if(avg == root->val) {
        result++;
    }
    
    return {SUM, COUNT};
}

int averageOfSubtree(TreeNode* root) {
   int  result = 0;
    
    solveforavg(root,result);
    
    return result;
}

};