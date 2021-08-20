Node* reverse(Node* head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    Node* tail=head->next;
    Node* small_head=reverse(head->next);
    head->next=NULL;
    if(tail!=NULL){
        tail->next=head;
    }
    if(small_head!=NULL){
        return small_head;
    }
    else{
        head;
    }
    
}
int getNthFromLast(Node *head, int n)
{
       if(head==NULL){
           return -1;
       }
       if(head->next==NULL && n==1){
           return head->data;
       }
       if(head->next==NULL && n>1){
           return -1;
       }
       head=reverse(head);
       int count=1;
      while(count<n && head!=NULL){
          count++;
          head=head->next;
      }
       if(head==NULL){
           return -1;
       }
       else{
           return head->data;
       }
       
}
