// Problem: Diameter of Binary Tree
// Difficulty: easy
// Runtime: 0 ms
// Memory: 23.6 MB

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
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL) return 0;
        int maxi = 0;
        int h = height(root, maxi);
        return maxi;
    }

    int height(TreeNode* root, int& maxi){
        if(root == NULL) return 0;

        int left = height(root->left, maxi);
        int right = height(root->right, maxi);

        maxi = max(maxi, left+right);

        return 1+max(left, right);
    }
};