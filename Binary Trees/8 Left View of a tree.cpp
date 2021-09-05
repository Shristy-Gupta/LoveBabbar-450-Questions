vector<int> leftView(Node *root)
{
   vector<int> ans;
   if(root==NULL){
       return ans;
   }
 
  queue<Node*> st;
  bool flag=true;
  st.push(root);
  st.push(NULL);
  while(!st.empty()){
      Node* curr=st.front();
      st.pop();
      
      if(curr!=NULL){
           if(flag){
             ans.push_back(curr->data); 
             flag=false;
           }      
          
          if(curr->left){
              st.push(curr->left);
          }
          if(curr->right){
              st.push(curr->right);
          }
      }
      else{
          if(!st.empty()){
              st.push(NULL);
              flag=true;
          }
      }
     
  }
   return ans;
}
