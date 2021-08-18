class Solution{
  public:
    Node* merge(Node* head1, Node* head2){
        Node* head;
        Node* tail;
        if(head1==NULL){
            return head2;
        }
        if(head2==NULL){
            return head1;
        }
        if(head1->data<head2->data){
            head=head1;
            head1=head1->next;
        }
        else{
            head=head2;
            head2=head2->next; 
        }
        tail=head;
        while(head1!=NULL && head2!=NULL){
        if(head1->data<head2->data){
            tail->next=head1;
            head1=head1->next;
        }
        else{
            tail->next=head2;
            head2=head2->next; 
        }
        tail=tail->next;
        }
        
        while(head1!=NULL){
            tail->next=head1;
            head1=head1->next;
            tail=tail->next;
        }
        
        while(head2!=NULL){
            tail->next=head2;
            head2=head2->next;
            tail=tail->next;
        }
        return head;
    }
    Node* middle(Node* head){
        if(head==NULL){
            return NULL;
        }
        Node* fast=head->next;
        Node* slow=head;
        while(slow!=NULL && fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    //Function to sort the given linked list using Merge Sort.
    Node* mergeSort(Node* head) {
        if(head==NULL|| head->next==NULL){
            return head;
        }
        Node* mid_node=middle(head);
        Node* head1=head;
        Node* head2=mid_node->next;
        mid_node->next=NULL;
        
        return merge(mergeSort(head1),mergeSort(head2));
    }
};
