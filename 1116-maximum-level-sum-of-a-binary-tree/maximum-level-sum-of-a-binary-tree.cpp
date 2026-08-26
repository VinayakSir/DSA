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
    int maxLevelSum(TreeNode* root) {
    if(!root)return 0;
    queue<TreeNode*>q;
    q.push(root);    
    int ans=1;    
    int maxsum=INT_MIN;
    int depth=0;              // naya counter
    while (!q.empty())
    {
        depth++;               // har level pe increment
        int level=q.size();
        int currentsum=0;
        for (int i = 0; i < level; i++)
        {
            TreeNode*node=q.front();
            q.pop();
            if(node->left)q.push(node->left);
            if(node->right)q.push(node->right);
            currentsum+=node->val;
        }

        if(maxsum<currentsum){
            maxsum=currentsum;
            ans=depth;          // depth store kar, level (node count) nahi
        }
    }
    return ans;
}
};