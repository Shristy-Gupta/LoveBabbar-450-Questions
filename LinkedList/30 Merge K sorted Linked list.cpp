struct compare{
    bool operator()(Node* a, Node* b){
        return a->data>b->data;
    }
};
class Solution{
  public:
    //Function to merge K sorted linked list.
    Node * mergeKLists(Node *arr[], int k)
    {
           // using heap
           priority_queue<Node*,vector<Node*>,compare> pq;
           //push the head nodes of all the linked list
           for(int i=0;i<k;i++){
               if(arr[i]!=NULL)
               pq.push(arr[i]);
           }
           if(pq.empty()){
               return NULL;
           }
           Node* head=new Node(0);
           Node* tail=head;
           while(!pq.empty()){
               Node* curr=pq.top();
               pq.pop();
               tail->next=curr;
               tail=tail->next;
               if(curr->next!=NULL){
                   pq.push(curr->next);
               }
           }
           return head->next;
    }
    
};
