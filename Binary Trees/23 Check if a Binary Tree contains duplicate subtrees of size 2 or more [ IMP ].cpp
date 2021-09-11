class Solution {
  public:
  unordered_map<string,int>m;
  string solve(Node* root){
      if(root==NULL){
          return "$";
      }
      string s="";
      if(root->left==NULL and root->right==NULL){
          s=to_string(root->data);
          return s;
      }
      s+=to_string(root->data);
      s+=solve(root->left);
      s+=solve(root->right);
      m[s]++;
      return s;
      
  }
    /*This function returns true if the tree contains 
    a duplicate subtree of size 2 or more else returns false*/
    int dupSub(Node *root) {
         if(root==NULL){
             return 0;
         }
         solve(root);
         for(auto x: m){
             if(x.second>=2){
                 return true;
             }
         }
         return false;
    }
};
