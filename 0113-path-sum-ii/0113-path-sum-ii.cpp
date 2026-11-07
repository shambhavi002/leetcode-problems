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
    vector<vector<int>> ans;

    void dfs(TreeNode* root, int targetSum,
             vector<int>& path) {

        if (root == NULL)
            return;

        // Add current node
        path.push_back(root->val);

        // Check if leaf node
        if (root->left == NULL && root->right == NULL) {

            if (targetSum == root->val) {
                ans.push_back(path);
            }

        } else {

            // Explore left and right subtrees
            dfs(root->left, targetSum - root->val, path);
            dfs(root->right, targetSum - root->val, path);
        }

        // Backtrack
        path.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {

        ans.clear();
        vector<int> path;

        dfs(root, targetSum, path);

        return ans;
    }
};
