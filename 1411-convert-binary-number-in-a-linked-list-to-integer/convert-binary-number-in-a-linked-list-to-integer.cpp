/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:

    pair<int, int>solve(ListNode* node){
        if(!node->next){
            return {node->val, 1};
        }
        pair<int, int>a=solve(node->next);
        return {a.first+pow(2, a.second)*node->val, a.second+1};
    }

    int getDecimalValue(ListNode* head) {
        return solve(head).first;
        
    }
};