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

    int cnt;
    void solve(TreeNode* root, vector<int>&freq){
        if(root==NULL) return;
        freq[root->val]++;
        if(root->left==NULL && root->right==NULL){
            bool flag=0, isP=1;
            for(int i=1; i<=9; i++){
                if(freq[i]%2==1){
                    if(flag==0){
                        flag=1;
                    }else{
                        isP=0;
                        break;
                    }
                }
            }
            if(isP) cnt++;
        }
        solve(root->left, freq);
        solve(root->right, freq);
        freq[root->val]--;
    }

    int pseudoPalindromicPaths (TreeNode* root) {
        cnt=0;
        vector<int>freq(10, 0);
        solve(root, freq);
        return cnt;
    }
};