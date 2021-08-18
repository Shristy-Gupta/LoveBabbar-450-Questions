Node* merge(Node* head1, Node* head2){
    if(head1==NULL){
        return head2;
    }
    if(head2==NULL){
        return head1;
    }
    Node* head;
    Node* tail;
    if(head1->data<head2->data){
        head=head1;
        head1=head1->bottom;
    }
    else{
        head=head2; 
        head2=head2->bottom;
    }
    tail=head;
    while(head1!=NULL && head2!=NULL){
          if(head1->data<head2->data){
            tail->bottom=head1;
            head1=head1->bottom;
        }
        else{
            tail->bottom=head2; 
            head2=head2->bottom;
        } 
        tail=tail->bottom;
    }
    while(head1!=NULL){
        tail->bottom=head1;
        head1=head1->bottom;
        tail=tail->bottom;
    }
    while(head2!=NULL){
        tail->bottom=head2; 
        head2=head2->bottom;
        tail=tail->bottom;
    }
    return head;
}
/*  Function which returns the  root of 
    the flattened linked list. */
Node *flatten(Node *root)
{
   if(root==NULL || root->next==NULL){
       return root;
   }
   root->next=flatten(root->next);
   //Merge
   root=merge(root,root->next);

   return root;
}
