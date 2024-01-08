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

    int sum;
    int L, R;
    void solve(TreeNode* root){
        if(root==NULL) return;
        solve(root->left);
        if(root->val>=L && root->val<=R) sum+=root->val;
        solve(root->right);
    }

    int rangeSumBST(TreeNode* root, int low, int high) {
        L=low;
        R=high;
        sum=0;
        solve(root);
        return sum;
    }
};