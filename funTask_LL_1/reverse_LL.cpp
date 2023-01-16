class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev=NULL;
        ListNode* curr=head;

        while(curr!=NULL){
            ListNode* ocn=curr->next;
            curr->next= prev;
            prev=curr;
            curr=ocn;
        } 
        head=prev;
        return prev;
    }
};