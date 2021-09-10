// Should return true if tree is Sum Tree, else false
class Solution
{
    public:
    pair<int,bool> isSumTreeHelper(Node* root){
        pair<int,bool> ans;
        if(root==NULL){
             ans.first=0;
             ans.second=true;
             return ans;
         }
         if(root->left==NULL &&  root->right==NULL){
             ans.first= root->data;
             ans.second=true;
             return ans;
         } 
         pair<int,bool> leftans=isSumTreeHelper(root->left);
         pair<int,bool> rightans=isSumTreeHelper(root->right);
         
         if(root->data==leftans.first+rightans.first && leftans.second && rightans.second){
            ans.second=true; 
         }
         else{
             ans.second=false;
         }
         ans.first=root->data+leftans.first+rightans.first;
         return ans;
    }
    bool isSumTree(Node* root)
    {
         if(root==NULL){
             return true;
         }
         if(root->left==NULL &&  root->right==NULL){
             return true;
         }
         pair<int,bool> ans=isSumTreeHelper(root);
         return ans.second;
    }
};
