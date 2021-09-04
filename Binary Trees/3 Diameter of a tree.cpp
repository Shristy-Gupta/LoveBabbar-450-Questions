#include<utility>
class Solution {
  public:
    // Function to return the diameter of a Binary Tree.
       pair<int,int>diameter_helper(Node* root){
        //first one is height and second one is diamter
        pair<int,int> ans;
        if(root==NULL){
            ans.first=0;
            ans.second=0;
            return ans;
        }
        if(root->left==NULL && root->right==NULL){
            ans.first=1;
            ans.second=1;
            return ans; 
        }
        pair<int,int> leftans=diameter_helper(root->left);
        pair<int,int> rightans=diameter_helper(root->right);
        int new_height=max(leftans.first,rightans.first)+1;
        int left_dia=leftans.second;
        int right_dia=rightans.second;
        ans.first=new_height;
        ans.second=max(leftans.first+rightans.first+1,max(left_dia,right_dia));
        return ans;
        
    } 
    int diameter(Node* root) {
        if(root==NULL){
            return 0;
        }
        pair<int,int> ans=diameter_helper(root);
        return ans.second;
    }
};
