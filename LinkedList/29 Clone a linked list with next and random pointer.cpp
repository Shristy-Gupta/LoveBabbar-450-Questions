//138 Leetcode solution
class Solution {
public:
    unordered_map<Node*,Node*> dict;
    Node* copyRandomList(Node* head) {
       if(head==NULL){
           return head;
       }
      //create the node and new node pair
        int count=0;
        Node* tail=head;
        Node* new_head=new Node(tail->val);
        Node* new_tail=new_head;
        dict[tail]=new_head;
        tail=tail->next;
        count++;
        while(tail!=NULL){
            new_tail->next=new Node(tail->val);
            dict[tail]=new_tail->next;
            tail=tail->next;
            new_tail=new_tail->next;
            count++;
        }
        //Now mapping the random nodes
        tail=head;
        new_tail=new_head;
        while(tail!=NULL){
            if(dict.find(tail->random)!=dict.end()){
               new_tail->random=dict[tail->random]; 
            }
            tail=tail->next;
            new_tail=new_tail->next;
            
        }
        return new_head;
    }
};
