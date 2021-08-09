#include <bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};

void print(Node *root)
{
Node *temp = root;
while(temp!=NULL)
{
cout<<temp->data<<" ";
temp=temp->next;
}
}


 // } Driver Code Ends
/*
The structure of linked list is the following

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/


class Solution
{
    public:
    //Function to remove duplicates from unsorted linked list.
    Node * removeDuplicates(Node *head) 
    {
        
    unordered_map<int,int> nodes;
    Node* tail=head;
    while(tail!=NULL){
        nodes[tail->data]++;
        tail=tail->next;
    }
    
     tail=head;
     while(tail!=NULL){
         if(tail->next!=NULL && (tail->next->data == tail->data || nodes[tail->next->data]==-1)){
             Node * save_node=tail->next->next;
             tail->next->next=NULL;
             tail->next=save_node;
             continue;
         }
         if(tail->next!=NULL && nodes[tail->data]>1){
             nodes[tail->data]=-1;
         }
         tail=tail->next;
     }
     return head;
    }
};


// { Driver Code Starts.

int main() {
	// your code goes here
	int T;
	cin>>T;
	
	while(T--)
	{
		int K;
		cin>>K;
		struct Node *head = NULL;
        struct Node *temp = head;
 
		for(int i=0;i<K;i++){
		int data;
		cin>>data;
			if(head==NULL)
			head=temp=new Node(data);
			else
			{
				temp->next = new Node(data);
				temp=temp->next;
			}
		}
		
	    Solution ob;
		Node *result  = ob.removeDuplicates(head);
		print(result);
		cout<<endl;
		
	}
	return 0;
}  // } Driver Code Ends
