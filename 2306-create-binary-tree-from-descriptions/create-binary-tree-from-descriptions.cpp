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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        int n=descriptions.size();
        unordered_map<int, TreeNode*>mpp;
        unordered_map<TreeNode*, TreeNode*>mp1;

        for(int i=0; i<n; i++){
            int parent=descriptions[i][0];
            int child=descriptions[i][1];
            bool isLeft=descriptions[i][2];

            TreeNode *par=NULL, *ch=NULL;
            if(mpp.find(parent)!=mpp.end()){
                    par=mpp[parent];
            }else{
                par= new TreeNode(parent);
                mpp[parent]=par;
            } 
            if(mpp.find(child)!=mpp.end()){
                ch=mpp[child];
            }else{
                ch= new TreeNode(child);
                mpp[child]=ch;
            }
            
            if(isLeft){                
                par->left=ch;
            }else{
                par->right=ch;
            }
            mp1[ch]=par;
        }

        TreeNode* head=NULL;
        for(auto &it:mpp){
            if(mp1.find(it.second)==mp1.end()){
                head=it.second;
                break;
            }
        }

        return head;

    }
};