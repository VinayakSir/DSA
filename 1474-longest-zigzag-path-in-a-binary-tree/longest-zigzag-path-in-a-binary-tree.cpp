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
  int pathLength = 0;
void dfsZigZag(TreeNode* node, bool goLeft, int steps) {
    if (node == nullptr) {
        return;
    }
    pathLength = max(pathLength, steps);
    if (goLeft) {
        dfsZigZag(node->left, false, steps + 1);
        dfsZigZag(node->right, true, 1);
    } else {
        dfsZigZag(node->left, false, 1);
        dfsZigZag(node->right, true, steps + 1);
    }
}

int longestZigZag(TreeNode* root) {
    dfsZigZag(root, false, 0);
    dfsZigZag(root, true, 0);
    return pathLength;
}


};