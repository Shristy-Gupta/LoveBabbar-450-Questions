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
    ListNode* findHalf(ListNode* head){
        ListNode* fastNode=head->next->next;
        ListNode* slowNode=head;
        while(fastNode!=NULL){
            slowNode=slowNode->next;
            fastNode=fastNode->next;
            if(fastNode!=NULL){
                fastNode=fastNode->next;
            }   
        }
        return slowNode;
    }
    ListNode* reverse(ListNode* head){
        if(head==NULL){
            return NULL;
        }
        if(head->next==NULL){
            return head;
        }
        ListNode* tail=head->next;
        ListNode* smallhead=reverse(head->next);
        head->next=NULL;
        tail->next=head;
        return smallhead;
    }
    bool isPalindrome(ListNode* head) {
        if(head==NULL){
            return true;
        }
        if(head->next==NULL){
            return true;
        }
        //1) find half
        ListNode* middle=findHalf(head);
        //cout<<middle->val<<endl;
        //2) Reverse right half
        middle=reverse(middle);
        //cout<<middle->val<<endl;
        //3)  Travserse and check both the chains
        while(head!=NULL && middle!=NULL){
            if(head->val==middle->val){
                head=head->next;
                middle=middle->next;
            }
            else{
                return false;
            }
        }
       return true; 
    }
};
