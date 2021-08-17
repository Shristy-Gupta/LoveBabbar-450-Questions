/****************************************************

    Following is the class structure of the DLLNode class:

    class DLLNode {
    public:
	int data;
	Node *next;

	DLLNode(int data) {
		this->data = data;
		this->next = NULL;
		this->prev = NULL;
	}
}

*****************************************************/
DLLNode* getithnode(DLLNode* head, int k){
    DLLNode* ans=head;
    int i=0;
    while(i!=k &&  ans!=NULL){
        ans=ans->next;
        i++;
    }
    return ans;
}
DLLNode* gettail(DLLNode* head){
    while(head->next!=NULL){
        head=head->next;
    }
    return head;
}
DLLNode* rotateDLL(DLLNode* head, int k) 
{
   if(head==NULL || head->next==NULL){
       return head;
   }
    DLLNode* new_head=getithnode(head,k);
    if(new_head==NULL){
        return NULL;
    }
    DLLNode* tail=gettail(head);
    DLLNode* kth=new_head;
    DLLNode* k_1=new_head->prev;
    
    if(tail!=NULL){
        tail->next=head;
    }
    head->prev=tail;
    new_head->prev=NULL;
    if(k_1!=NULL){
        k_1->next=NULL;
    }
    
    //update new_tail
    return new_head;

}
