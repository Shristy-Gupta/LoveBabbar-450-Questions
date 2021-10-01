#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
	struct Node{
	    int val;
	    Node* left;
	    Node* right;
	    Node(int num){
	        val=num;
	        left=NULL;
	        right=NULL;
	    }
	};
	void inorder(Node* root,vector<string> &ans, string result){
	    if(root==NULL){
	        return;
	    }
	    if(root->left==NULL && root->right==NULL){
	        ans.push_back(result);
	        return;
	    }
	    //if(root->left)
	     inorder(root->left,ans,result+"0");
	     //if(root->right)
	     inorder(root->right,ans,result+"1");
	}

	 struct compare{
	    
    	 bool operator()(Node* n1, Node* n2){
    	    return n1->val>n2->val;
    	}
	 };
		vector<string> huffmanCodes(string S,vector<int> f,int n)
		{
		    vector<string> ans;
		    if(n==1){
		        return {"0"};
		    }
		    priority_queue<Node*,vector<Node*>,compare>huffman;
		    for(int i=0;i<n;i++){
		        Node* new_node=new Node(f[i]);
		        huffman.push(new_node);
		    }
		    while(huffman.size()>1){
		        Node* left_node=huffman.top();
		        huffman.pop();
		        Node* right_node=huffman.top();
		        huffman.pop();
		        Node* new_node=new Node(left_node->val+right_node->val);
		        new_node->left=left_node;
		        new_node->right=right_node;
		        huffman.push(new_node);
		    }
		    string result="";
		    inorder(huffman.top(),ans,result);
		    return ans;
		    
		}
};
