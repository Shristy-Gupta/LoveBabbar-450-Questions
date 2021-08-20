class Solution{
public:
    Node* divide(int N, Node *head){
        Node* evenhead=NULL;
        Node* eventail=NULL;
        Node* oddhead=NULL;
        Node* oddtail=NULL;
        while(head!=NULL){
            if(head->data%2==0){
                if(evenhead==NULL){
                    evenhead=head;
                    eventail=evenhead;
                }
                else{
                    eventail->next=head;
                    eventail=eventail->next;
                }
            }
            else{
                if(oddhead==NULL){
                    oddhead=head;
                    oddtail=oddhead;
                }
                else{
                    oddtail->next=head;
                    oddtail=oddtail->next;
                }
            }
            head=head->next;
        }
        if(oddtail!=NULL)
        oddtail->next=NULL;
        if(eventail!=NULL){
            eventail->next=oddhead;
            return evenhead;
        }
        else{
            return oddhead;
        }
    }
};
