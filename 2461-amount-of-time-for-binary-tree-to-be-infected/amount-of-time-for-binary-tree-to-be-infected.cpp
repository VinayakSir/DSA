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
    int burn(TreeNode *root, int start, int &timer){
        if(root == NULL) return 0;
        if(root->val == start) return -1;

        int left = burn(root->left, start, timer);
        int right = burn(root->right, start, timer);

        if(left < 0){
            timer = max(timer, abs(left) + right);
            return left-1;
        }
        if(right < 0){
            timer = max(timer, abs(right) + left);
            return right - 1;
        }

        return 1 + max(left, right);
    }

    void positionOfStart(TreeNode *root, int start, TreeNode* &pos){
        if(root == NULL) return; 
        if(root->val == start){
            pos = root;
            return;
        }
        if(root->left) positionOfStart(root->left, start, pos);
        if(root->right) positionOfStart(root->right,start, pos);
    }

    int heightOfStart(TreeNode *pos){
        if(pos == NULL) return 0;
        return 1 + max(heightOfStart(pos->left), heightOfStart(pos->right));
    }

    int amountOfTime(TreeNode* root, int start) {
        int timer = 0;
        burn(root, start, timer);
        TreeNode *pos = NULL;
        positionOfStart(root, start, pos);
        int height = heightOfStart(pos) - 1;
        return max(timer, height);
    }
};