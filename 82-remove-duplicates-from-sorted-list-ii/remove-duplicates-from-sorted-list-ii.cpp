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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* node=head, *prev;
        ListNode* dummy=new ListNode(-1);
        dummy->next=head;
        prev=dummy;
        while(node){
            if(node->next && node->next->val==node->val){
                while(node->next && node->next->val==node->val){
                    node=node->next;
                }
                prev->next=node->next;
            }else{
                prev=prev->next;
            }         
            node=node->next;
        }
        return dummy->next;               
    }
};