// Problem: Find Bottom Left Tree Value
// Difficulty: medium
// Runtime: 0 ms
// Memory: 24.8 MB

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
    int ans = -1;
    int maxDepth = 0;
    int findBottomLeftValue(TreeNode* root) {
        if(root == NULL) return 0;
        if(root->left == NULL and root->right == NULL) return root->val;
        return solve(root, 0);
    }

    int solve(TreeNode* root, int depth){
        if(root == NULL) return 0;
        if(depth>maxDepth){
            ans = root->val;
            maxDepth = depth;
        }

        int left = 0;
        int right = 0;

        if(root->left) left = solve(root->left, depth+1);
        if(root->right) right = solve(root->right, depth+1);

        return ans;

    }
};