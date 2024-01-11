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

    int solve(TreeNode* root, int mini, int maxi){
        if(root==NULL) return maxi-mini;
        maxi=max(maxi, root->val);
        mini=min(mini, root->val);
        int left=solve(root->left, mini, maxi);
        int right=solve(root->right, mini, maxi);
        return max({left, right, maxi-mini});
    }

    int maxAncestorDiff(TreeNode* root) {
        return solve(root, 1e9, -1e9);
    }
};