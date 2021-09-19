// This function finds predecessor and successor of key in BST.
// It sets pre and suc as predecessor and successor respectively
void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
{
    if(root==NULL){
        return;
    }
    if(root->key==key){
          //predecessor--> one step left and extreme right
       if(root->left){
           Node* lft=root->left;
           while(lft->right){
               lft=lft->right;
           }
           pre=lft;
       }
         //successor--> one step right and then extreme left
       if(root->right){
           Node* rht=root->right;
           while(rht->left){
               rht=rht->left;
           }
           suc=rht;
       }
       return;
    }
  if(key>root->key){
      pre=root;
      findPreSuc(root->right,pre,suc,key);
      return;
  }
   
  if(key<root->key){
      suc=root;
      findPreSuc(root->left,pre,suc,key);
      return;
  }  
}
