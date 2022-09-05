
//use of 3 pointers---- prev,current,right

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head==NULL) return NULL;
        ListNode * current=head;
        ListNode *prev=NULL;
        ListNode* right=head->next;
        
        //if atleast 2 nodes there
        if(right!=NULL){
            while(right!=NULL){
                current->next=prev;
                prev=current;
                current=right;
                right=right->next;
            }
            current->next=prev;
        }
        return current;
    }
};