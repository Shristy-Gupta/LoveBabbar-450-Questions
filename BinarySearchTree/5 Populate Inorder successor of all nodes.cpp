
//https://www.youtube.com/watch?v=W25l6evkk_U
class Solution
{
public:
    void solve(Node* root, Node* &prev){
      if(root==NULL){
           return;
       }
      solve(root->left,prev); 
      if(prev!=NULL){
          prev->next=root;
      }
      prev=root;
      solve(root->right,prev);  
        
    }
    void populateNext(Node *root)
    {
       if(root==NULL){
           return;
       }
       Node* prev=NULL;
       solve(root,prev);
    }
};
