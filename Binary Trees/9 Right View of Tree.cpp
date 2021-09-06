class Solution
{
    public:
    //Function to return list containing elements of right view of binary tree.
    vector<int> rightView(Node *root)
    {
      vector<int> ans;
      if(root==NULL){
          return ans;
      }
      queue<Node*> q;
      q.push(root);
      q.push(NULL);
      while(!q.empty()){
          Node* node=q.front();
          q.pop();
          if(node!=NULL && q.front()==NULL){
             ans.push_back(node->data); 
          }
          if(node!=NULL){
              if(node->left){
                  q.push(node->left);
               }
              if(node->right){
                  q.push(node->right);
               }
          }
          else{
              if(!q.empty()){
                  q.push(NULL);
              }
          }
          
      }
      return ans;
      
    }
};
