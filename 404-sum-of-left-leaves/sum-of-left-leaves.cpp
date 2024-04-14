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

    int solve(TreeNode* root, TreeNode* parent){
        if(root==NULL) return 0;

        int lft=solve(root->left, root);
        int rgt=solve(root->right, root);

        if(parent!=NULL && parent->left==root && root->left==NULL && root->right==NULL){
            return root->val+lft+rgt;
        }else return lft+rgt;
    }

    int sumOfLeftLeaves(TreeNode* root) {
        return solve(root, NULL);
    }
};