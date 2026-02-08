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

    pair<int, bool> check(TreeNode* node){
        if(!node) return {0, true};
        else if(!node->right && !node->left) return {1, true};
        auto [lh, lv]=check(node->left);
        auto [rh, rv]=check(node->right);
        if(!lv || !rv) return {1e9, false};
        else if(abs(lh-rh)>1) return {1e9, false};
        else return {max(lh, rh)+1, true};
    }

    bool isBalanced(TreeNode* root) {
        return check(root).second;        
    }
};