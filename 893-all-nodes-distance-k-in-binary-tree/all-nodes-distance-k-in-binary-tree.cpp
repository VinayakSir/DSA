/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    unordered_map<TreeNode*, TreeNode*> parent;

void markParents(TreeNode* root)
{
    if (!root)
        return;

    if (root->left)
    {
        parent[root->left] = root;
        markParents(root->left);
    }

    if (root->right)
    {
        parent[root->right] = root;
        markParents(root->right);
    }
}

vector<int> distanceK(TreeNode* root, TreeNode* target, int k)
{
    // Step 1: Store parent of every node
    markParents(root);

    // Step 2: BFS starting from target
    queue<TreeNode*> q;
    unordered_map<TreeNode*, bool> visited;

    q.push(target);
    visited[target] = true;

    int distance = 0;

    while (!q.empty())
    {
        int size = q.size();

        // We have reached distance K
        if (distance == k)
        {
            vector<int> ans;

            while (!q.empty())
            {
                ans.push_back(q.front()->val);
                q.pop();
            }

            return ans;
        }

        // Process current level
        for (int i = 0; i < size; i++)
        {
            TreeNode* node = q.front();
            q.pop();

            // Left child
            if (node->left && !visited[node->left])
            {
                visited[node->left] = true;
                q.push(node->left);
            }

            // Right child
            if (node->right && !visited[node->right])
            {
                visited[node->right] = true;
                q.push(node->right);
            }

            // Parent
            if (parent.count(node) && !visited[parent[node]])
            {
                visited[parent[node]] = true;
                q.push(parent[node]);
            }
        }

        distance++;
    }

    return {};
}
};