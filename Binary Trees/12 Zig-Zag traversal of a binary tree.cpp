class Solution{
    public:
    pair<int,bool> isBalancedhelper(Node* root){
        pair<int,bool> ans;
        if(root==NULL){
           ans.first=0;
           ans.second=true;
           return ans;
        }
        if(root->left==NULL && root->right==NULL){
            ans.first=1;
            ans.second=true;
            return ans;
        }
        pair<int,bool> ansleft=isBalancedhelper(root->left);
        pair<int,bool> ansright=isBalancedhelper(root->right);
        ans.first=1+max(ansleft.first,ansright.first);
        if(abs(ansleft.first-ansright.first)>1 || !ansleft.second || !ansright.second){
            ans.second=false;
        }
        else{
            ans.second=true;
        }
        
        return ans;
    }
    //Function to check whether a binary tree is balanced or not.
    bool isBalanced(Node *root)
    {
        if(root==NULL){
            return true;
        }
        if(root->left==NULL && root->right==NULL){
            return true;
        }
        pair<int,bool> ans=isBalancedhelper(root);
        return ans.second;
    }
};
