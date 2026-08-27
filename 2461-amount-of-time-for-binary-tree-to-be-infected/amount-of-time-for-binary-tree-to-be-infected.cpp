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
    unordered_map<TreeNode*, TreeNode*> par; // har node ka parent store karega
TreeNode* startNode = NULL;

void findParents(TreeNode* node, TreeNode* p, int start) {
    if (!node) return;

    findParents(node->left, node, start);  

    par[node] = p;                         
    if (node->val == start) startNode = node;

    findParents(node->right, node, start); 
}

int amountOfTime(TreeNode* root, int start) {
    findParents(root, NULL, start);

    queue<TreeNode*> q;
    unordered_set<TreeNode*> seen;

    q.push(startNode);
    seen.insert(startNode);

    int time = -1;

    while (!q.empty()) {
        int size = q.size();
        time++; // ek minute pura hua

        for (int i = 0; i < size; i++) {
            TreeNode* curr = q.front();
            q.pop();

            // teeno directions check karo: left, right, parent
            TreeNode* left = curr->left;
            TreeNode* right = curr->right;
            TreeNode* up = par[curr];

            if (left  && seen.find(left) == seen.end()) {
                seen.insert(left);
                q.push(left);
            }
            if (right && seen.find(right) == seen.end()) {
                seen.insert(right);
                q.push(right);
            }
            if (up  && seen.find(up) == seen.end()) {
                seen.insert(up);
                q.push(up);
            }
        }
    }

    return time;
}
};