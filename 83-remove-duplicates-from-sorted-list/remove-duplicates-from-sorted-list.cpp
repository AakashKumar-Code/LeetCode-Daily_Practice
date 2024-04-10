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
        ListNode* node=head, *prev=NULL;
        ListNode* d=new ListNode(-1e9);
        d->next=head;
        prev=d;

        while(node){
            while(node && prev->val==node->val){
                node=node->next;
            }
            prev->next=node;
            prev=node;
            if(node) node=node->next;
        }

        return d->next;        
    }
};