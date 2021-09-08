void diagonalHelper(Node *root, int d, map<int,vector<int>> &digonal_print){
    if(root==NULL){
        return;
    }
    digonal_print[d].push_back(root->data);
    diagonalHelper(root->left,d+1,digonal_print);
    diagonalHelper(root->right,d,digonal_print);
    
    
    
}
vector<int> diagonal(Node *root)
{
  vector<int> ans;
  if(root==NULL){
      return ans;
  }
  map<int,vector<int>> digonal_print;
  diagonalHelper(root,0,digonal_print);
  for(auto it:digonal_print){
      vector<int> v=it.second;
      for(auto k:v){
          ans.push_back(k);
      }
  }
  return ans;
}



vector<int> diagonal(Node *root)
{
   vector<int> ans;
   if(root==NULL){
       return ans;
   }
   queue<Node*> q;
   q.push(root);
   vector<vector<int>> smallans;
   while(!q.empty()){
       int n=q.size();
       vector<int> sans;
       for(int i=0;i<n;i++){
           Node* node=q.front();
           q.pop();
           while(node){
               sans.push_back(node->data);
               if(node->left){
                   q.push(node->left);
               }
           node=node->right;
           }
       }
       
      smallans.push_back(sans); 
   }
   for(int i=0;i<smallans.size();i++){
       for(int j=0;j<smallans[i].size();j++){
           ans.push_back(smallans[i][j]);
       }
   }
   return ans;
}
