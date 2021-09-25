// Online C++ compiler to run C++ program online
//Morris Inorder Traversal
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data=val;
        left=right=NULL;
    }
};
Node* insert(Node* root, int val){
    if(root==NULL){
        return new Node(val);
    }
    if(root->data>val){
        root->left=insert(root->left,val);
    }
    else{
        root->right=insert(root->right,val);
    }
    return root;
}
/* Function to count nodes in a  binary search tree
   using Morris Inorder traversal*/
int countNodes(Node* root){
    Node* current,*pre;
    int count=0;
    if(root==NULL){
        return 0;
    }
    current=root;
    while(current!=NULL){
        if(current->left==NULL){
            count++;
            current=current->right;
        }
        else{
            pre=current->left;
            /* Find the inorder predecessor of current */
            while(pre->right!=NULL && pre->right!=current){
                pre=pre->right;
            }
            /* Make current as right child of its
               inorder predecessor */
            if(pre->right==NULL){
                pre->right=current;
                current=current->left;
            }
            else{
                /* Revert the changes made in if part to
               restore the original tree i.e., fix
               the right child of predecssor */
                pre->right=NULL;
                // Increment count if the current
                // node is to be visited
                count++;
                current=current->right;
            }/* End of if condition pre->right == NULL */
        }/* End of if condition current->left == NULL*/
    }/* End of while */
    return count;
    
}
//Morris inorder traversal
int findMedian(Node* root){
    if(root==NULL){
        return 0;
    }
    int n=countNodes(root);
    int k=n/2,k1=(n+1)/2;
    int median=0,val1=0,val2=0,count=0;
    Node* current, *pre;
    current=root;
    while(current!=NULL){
        //two cases if left child is null or pre->right=curr then we count++
        if(current->left==NULL){
            count++;
            if(count==k){
                val1=current->data;
            }
            else if(count==k1){
                val2=current->data;
            }
            current=current->right;
        }
        else{
            pre=current->left;
            //get inoreder predeccessor
            while(pre->right!=NULL && pre->right!=current){
                pre=pre->right;
            }
            if(pre->right==NULL){
                pre->right=current;
                current=current->left;
            }
            else{
                pre->right=NULL;
                count++;
                if(count==k){
                   val1=current->data;
                }
                else if(count==k1){
                    val2=current->data;
                }
                current=current->right;
            }
        }
    }
   if(n%2){
       return val2;
   }
   else{
       return (val1+val2)/2;
   }
    
}
int main() {
    Node* root=NULL;
    root=insert(root,50);
    insert(root,30);
    insert(root,20);
    insert(root,40);
    insert(root,70);
    insert(root,60);
    insert(root,80);
    cout<<"values are inserted successfully"<<endl;
    cout<<findMedian(root);
    return 0;
}
