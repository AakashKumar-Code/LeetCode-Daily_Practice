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

    vector<int>l1, l2;
    void solve(TreeNode* root, bool l){
        if(!root) return;
        solve(root->left, l);
        if(root->left==NULL && root->right==NULL){
            if(l==1) l1.push_back(root->val);
            else l2.push_back(root->val);
        }
        solve(root->right, l); 
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        solve(root1, 1);
        solve(root2, 0);
        return l1==l2;
    }
};