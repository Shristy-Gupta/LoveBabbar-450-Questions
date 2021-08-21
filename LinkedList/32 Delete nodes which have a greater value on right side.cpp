class Solution
{
    public:
    Node* reverse(Node* head){
        Node* prev=NULL;
        Node* curr=head;
        while(curr){
            Node* fut=curr->next;
            curr->next=prev;
            prev=curr;
            curr=fut;
        }
        return prev;
    }
    Node *compute(Node *head)
    {
       if(head==NULL || head->next==NULL){
           return head;
       }
       head=reverse(head);
       int max_val=head->data;
      
       Node* ans_head=NULL;
       Node* ans_tail=NULL;
       if(ans_head==NULL){
          ans_head=head;
          ans_tail=head;
        }
      head=head->next;
       while(head!=NULL){
           if(head->data>=max_val){
                ans_tail->next=head;
                ans_tail=ans_tail->next;
                max_val=head->data;
           }
            head=head->next;
       }
       if(ans_tail!=NULL){
               ans_tail->next=NULL;
           }
       return reverse(ans_head);
    }
    
};
