class Solution
{
    public:
    //Function to sort a linked list of 0s, 1s and 2.
    Node* write_values(Node* head, int count, int val){
        Node* tail=head;
        while(count>0){
          tail->data=val;
          tail=tail->next;
          count--;
        }
        return tail;
    }
    Node* segregate(Node *head) {
        
        int count0=0;
        int count1=0;
        int count2=0;
        Node* tail=head;
        while(tail!=NULL){
            int x=tail->data;
            switch(x){
                case 0: count0++; break;
                case 1: count1++; break;
                case 2: count2++; break;
            }
            tail=tail->next;
        }
      tail=write_values(head,count0,0);
      tail=write_values(tail,count1,1);
      tail=write_values(tail,count2,2);
      return head; 
        
    }
};
