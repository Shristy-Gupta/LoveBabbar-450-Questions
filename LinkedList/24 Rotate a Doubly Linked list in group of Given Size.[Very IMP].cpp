/*********************************************************

    Following is the class structure of the Node class:

    class Node
	{
	public:
	    int data;
	    Node *next;
	    Node *prev;
	    Node(int data)
	    {
	        this->data = data;
	        this->next = NULL;
	        this->prev = NULL;
	    }
	};

************************************************************/

Node* reverseDLLInGroups(Node* head, int k)
{	
    if(head==NULL ){
        return head;
    }
    int count=0;
    head->prev=NULL;
    Node* past;
    Node* future;
    Node* new_head;
    Node* current=head;
    while(current!=NULL && count<k){
        new_head=current;
        //rotating the current node
        past=current->prev;
        future=current->next;
        current->prev=future;
        current->next=past;
        if(current!=NULL)
        {
            current=future;
        }
        else break;
        count++;
    }
    if(count>=k){
        Node* smallans=reverseDLLInGroups(current,k);
        head->next=smallans;
        if(smallans!=NULL){
            smallans->prev=head;
        } 
    }
    return new_head;
    
}

