class Solution {
public:
    void leftBoundary(Node *root,vector<int>& left_boundary){
        if(root==NULL){
            return;
        }
        if(root->left==NULL && root->right==NULL){
            return;
        }
        left_boundary.push_back(root->data);
        if(root->left){
            leftBoundary(root->left,left_boundary);
        }
        else if(root->right){
            leftBoundary(root->right,left_boundary);
        }
    }
    void rightBoundary(Node *root,vector<int>& right_boundary){
        if(root==NULL){
            return;
        }
        if(root->left==NULL && root->right==NULL){
            return;
        }
         if(root->right){
            rightBoundary(root->right,right_boundary);
        }
         else if(root->left){
            rightBoundary(root->left,right_boundary);
        }
        right_boundary.push_back(root->data);
    }
    void leaves(Node *root,vector<int>& leaf_nodes){
        if(root==NULL){
            return;
        }
         leaves(root->left,leaf_nodes);
        if(root->left==NULL && root->right==NULL){
          leaf_nodes.push_back(root->data);
         return;
        }
        leaves(root->right,leaf_nodes);
        
    }
    vector <int> printBoundary(Node *root)
    {
       vector<int> ans;
       if(root==NULL){
           return ans;
       }
       ans.push_back(root->data);
       leftBoundary(root->left,ans);
       leaves(root,ans);
       rightBoundary(root->right,ans);
 
       return ans;
    }
};
