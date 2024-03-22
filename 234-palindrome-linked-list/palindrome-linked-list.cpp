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
    bool isPalindrome(ListNode* head) {
        string first="";
        while(head){
            first+=to_string(head->val);
            head=head->next;
        }
        int i=0, j=first.length()-1;
        while(i<=j){
            if(first[i++]!=first[j--]) return 0;
        }
        return 1;
    }
};