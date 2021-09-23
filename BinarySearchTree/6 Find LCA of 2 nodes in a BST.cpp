//Function to find the lowest common ancestor in a BST. 
Node* LCA(Node *root, int n1, int n2)
{
   if(root==NULL){
       return root;
   }
   if(n1>n2){
       swap(n1,n2);
   }
   if(root->data==n1 || root->data==n2){
       return root;
   }
   Node* left_ans=LCA(root->left,n1,n2);
   Node* right_ans=LCA(root->right,n1,n2);

       if(left_ans!=NULL && right_ans!=NULL){
           return root;
       }
       else if(left_ans!=NULL){
           return left_ans;
       }
       else if(right_ans!=NULL){
           return right_ans;
       }
       else{
           return NULL;
       }

}
