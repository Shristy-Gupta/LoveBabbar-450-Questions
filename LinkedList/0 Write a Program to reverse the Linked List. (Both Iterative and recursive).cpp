//Initial Template for C++// C program to find n'th Node in linked list
#include <stdio.h>
#include <stdlib.h>
#include<iostream>
using namespace std;

/* Link list Node */
struct Node {
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};



 // } Driver Code Ends
/* Linked List Node structure:
struct Node
{
    int data;
    struct Node *next;
}
*/

class Solution
{
    public:
    //Function to reverse a linked list.
    struct Node* reverseList(struct Node *head)
    {
        //Recursion
        // if(head==NULL || head->next==NULL){
        //     return head;
        // }
        // struct Node* new_tail=head->next;
        // struct Node* smallhead=reverseList(head->next);
        // head->next=NULL;
        // new_tail->next=head;
        // return smallhead;
        
        //Iteration
          if(head==NULL || head->next==NULL){
            return head;
          }
          struct Node* present=head; 
          struct Node* previous=NULL;
          struct Node* next_node=head->next;

             while(present!=NULL){
                 present->next=previous;
                 previous=present;
                 present=next_node;
                 if(next_node!=NULL)
                 next_node=next_node->next;
             }
        
        return previous;
    }
    
};
    


// { Driver Code Starts.

void printList(struct Node *head)
{
    struct Node *temp = head;
    while (temp != NULL)
    {
       printf("%d ", temp->data);
       temp  = temp->next;
    }
}

/* Driver program to test above function*/
int main()
{
    int T,n,l,firstdata;
    cin>>T;

    while(T--)
    {
        struct Node *head = NULL,  *tail = NULL;

        cin>>n;
        
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        
        for (int i=1; i<n; i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }
        
        Solution ob;
        head = ob. reverseList(head);
        
        printList(head);
        cout << endl;
    }
    return 0;
}

  // } Driver Code Ends
