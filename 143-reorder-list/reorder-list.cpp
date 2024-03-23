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

    ListNode* rev(ListNode* head){
        if(head==NULL || head->next==NULL) return head;
        ListNode* node=head, *prev=NULL;
        while(node){
            ListNode* temp=node->next;
            node->next=prev;
            prev=node;
            node=temp;
        }
        return prev;
    }

    void reorderList(ListNode* head) {
        if(head==NULL || head->next==NULL) return;
        ListNode *slow=head, *fast=head, *prev=NULL;
        while(fast && fast->next){
            prev=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* head2=slow->next;
        slow->next=NULL;
        head2=rev(head2);
        ListNode* node=head, *node2=head2;
        while(node && node2){
            ListNode* temp=node->next;
            node->next=node2;
            ListNode* temp2=node2->next;
            node2->next=temp;
            node=temp;
            node2=temp2;
        }
    }
};