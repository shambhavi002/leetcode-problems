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

    unordered_map<int, int> mp;
    int preIndex = 0;

    TreeNode* solve(vector<int>& preorder,
                    vector<int>& inorder,
                    int start, int end) {

        if(start > end)
            return NULL;

        // Create root node
        int rootVal = preorder[preIndex];
        preIndex++;

        TreeNode* root = new TreeNode(rootVal);

        // Find root position in inorder
        int pos = mp[rootVal];

        // Build left subtree
        root->left = solve(preorder, inorder,
                           start, pos - 1);

        // Build right subtree
        root->right = solve(preorder, inorder,
                            pos + 1, end);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder,
                        vector<int>& inorder) {

        preIndex = 0;

        for(int i = 0; i < inorder.size(); i++) {
            mp[inorder[i]] = i;
        }

        return solve(preorder, inorder,
                     0, inorder.size() - 1);
    }
};