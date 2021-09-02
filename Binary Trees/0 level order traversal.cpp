#include<queue>
class Solution
{
    public:
    //Function to return the level order traversal of a tree.
    vector<int> ans;
    vector<int> levelOrder(Node* node)
    {
      if(node==NULL){
          return ans;
      }        
      queue<Node*> q;
      q.push(node);
      while(!q.empty()){
          Node* root=q.front();
          q.pop();
          ans.push_back(root->data);
          if(root->left!=NULL){
              q.push(root->left);
          }
          if(root->right!=NULL){
              q.push(root->right);
          }
      }
      return ans;
    }
};
