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
    vector<vector<int>>ans;
void helper(TreeNode* root, int sum, vector<int>& temp, int targetSum){
    if(!root) return;
    sum += root->val;
    temp.push_back(root->val);
    if(!root->left && !root->right){
        if(sum == targetSum) ans.push_back(temp);
        temp.pop_back();   // backtrack before returning too
        return;
    }
    helper(root->left, sum, temp, targetSum);
    helper(root->right, sum, temp, targetSum);
    temp.pop_back();   // <-- the missing line
}
vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
    if(!root)return {};
    int sum=0;
    vector<int>temp;
    helper(root,sum,temp,targetSum);
    return ans;
}
};