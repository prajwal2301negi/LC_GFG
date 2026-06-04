// Problem: Maximum Product of Splitted Binary Tree
// Difficulty: medium
// Runtime: 4 ms
// Memory: 92.2 MB

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right)
 *         : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    const int MOD = 1e9 + 7;

    long long findTotal(TreeNode* root) {
        if (root == NULL)
            return 0;

        return root->val + findTotal(root->left) + findTotal(root->right);
    }

    long long solve(TreeNode* root, long long totalSum, long long& ans) {
        if (root == NULL)
            return 0;

        long long left = solve(root->left, totalSum, ans);
        long long right = solve(root->right, totalSum, ans);

        long long subtreeSum = root->val + left + right;

        long long onePiece = subtreeSum;
        long long otherPiece = totalSum - subtreeSum;

        ans = max(ans, onePiece * otherPiece);
        return subtreeSum;
    }

    int maxProduct(TreeNode* root) {

        long long totalSum = findTotal(root);
        long long ans = 0;
        solve(root, totalSum, ans);
        return ans % MOD;
    }
};