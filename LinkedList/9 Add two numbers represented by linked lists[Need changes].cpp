// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


 // } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    struct Node* reverse(struct Node* head){
        if(head==NULL || head->next==NULL){
            return head;
        }
        struct Node* past=NULL;
        struct Node* present=head;
        struct Node* future=head->next;
        while(present!=NULL){
            present->next=past;
            past=present;
            present=future;
            if(future!=NULL){
                future=future->next;
            }
        }
        return past;
    }
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
         if(first==NULL && second==NULL){
             return NULL;
         }
         if(first!=NULL && second==NULL){
             return first;
         }
         if(first ==NULL && second!=NULL){
             return second;
         }
         struct Node* last1=reverse(first);
         struct Node* last2=reverse(second);
         printList(last1);
         printList(last2);
         
         struct Node* anshead;  
         struct Node* anstail;
         int sum=0,carry=0;
         while(last1!=NULL && last2!=NULL){
             sum=last1->data + last2->data + carry;
             carry=sum/10;
             sum=sum%10;
             last2=last2->next;
             last1=last1->next;
             if(anshead==NULL){
                 anshead=new Node(sum);
                 anstail=anshead;
             }
             else{
                 struct Node* new_node=new Node(sum);
                 anstail->next=new_node;
                 anstail=new_node;
                 
             }
         }
        
         while(last1!=NULL){
             sum=last1->data+carry;
             carry=sum/10;
             sum=sum%10;
             last1=last1->next;
             anstail->next=new Node(sum);
             anstail=anstail->next;
             
         }
         
       
         while(last2!=NULL){
             sum=last2->data+carry;
             carry=sum/10;
             sum=sum%10;
             last2=last2->next;
             anstail->next=new Node(sum);
             anstail=anstail->next;
             
         }
         if(carry!=0){
             anstail->next=new Node(carry);
             anstail=anstail->next;
         }
        
         return reverse(anshead);
         
    }
};


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(first,second);
        printList(res);
    }
    return 0;
}
  // } Driver Code Ends
