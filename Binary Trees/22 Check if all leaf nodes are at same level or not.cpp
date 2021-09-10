class Solution{
  public:
    /*You are required to complete this method*/
    bool checkhelper(Node* root, int depth, int &leaf_depth){
       if(root==NULL){
            return true;
        }
        if(root->left==NULL && root->right==NULL){
            if(leaf_depth==0){
                leaf_depth=depth;
                return true;
            }
            else{
                if(depth==leaf_depth){
                    return true;
                }
                else{
                    return false;
                }
            }
        }
        return checkhelper(root->left,depth+1,leaf_depth) &&
               checkhelper(root->right,depth+1,leaf_depth);
    }
    bool check(Node *root)
    {
        if(root==NULL){
            return true;
        }
        if(root->left==NULL && root->right==NULL){
            return true;
        }
        int depth=0;
        int leaf_depth=0;
        return checkhelper(root,depth,leaf_depth);
    }
};
