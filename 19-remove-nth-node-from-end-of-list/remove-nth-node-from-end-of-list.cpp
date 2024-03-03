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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==NULL) return head;
        if(head->next==NULL && n==1) return NULL;
        ListNode* node=head;
        int total=0;
        while(node!=NULL){
            total++;
            node=node->next;
        }
        int N=total-n+1;
        if(N<=0) return NULL;
        if(N==1){
            ListNode* dummy=head;
            head=head->next;
            dummy->next=NULL;
            return head;
        }
        ListNode* prev=NULL;
        node=head;
        while(N!=1){
            N--;
            prev=node;
            node=node->next;
        }
        prev->next=node->next;
        node->next=NULL;
        return head;
    }
};