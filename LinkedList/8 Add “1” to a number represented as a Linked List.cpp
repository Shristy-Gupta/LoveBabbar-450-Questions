//Initial template for C++

#include <bits/stdc++.h> 
using namespace std; 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data; 
        node = node->next; 
    }  
    cout<<"\n";
} 


 // } Driver Code Ends
//User function template for C++

/* 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    Node* reverse(Node *head){
        Node *Previous=NULL;
        Node *Present=head;
        Node *upcoming=head->next;
        while(Present!=NULL){
            Present->next=Previous;
            Previous=Present;
            Present=upcoming;
            if(upcoming!=NULL)
            upcoming=upcoming->next;
        }
        return Previous;
    }
        
    
    Node* addOne(Node *head) 
    {
        if(head==NULL){
            return new Node(1);
        }
       //reverse the linked list
       Node *reversed_head=reverse(head);
       
       //Add one to the head
      Node* tail=reversed_head;
      int carry=0;
      int sum=tail->data+carry+1;
      while(tail!=NULL){
          tail->data=sum%10;
          carry=sum/10;
          tail=tail->next;
          if(tail!=NULL)
          sum=tail->data+carry;
      }
      if(carry!=0){
          Node *_carry=new Node(carry);
          if(head!=NULL){
          head->next=_carry;
          head=_carry;
          }
      }
       // Reverse the linked list
      
       return reverse(reversed_head);
    }
};

// { Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        
        Node* head = new Node( s[0]-'0' );
        Node* tail = head;
        for(int i=1; i<s.size(); i++)
        {
            tail->next = new Node( s[i]-'0' );
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head); 
    }
    return 0; 
} 
  // } Driver Code Ends
