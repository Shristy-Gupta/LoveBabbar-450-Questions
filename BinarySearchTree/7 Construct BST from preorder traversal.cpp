/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int index=0;
    TreeNode* createBST(vector<int>& preorder, int left_max, int right_min){
       int n=preorder.size();
        if(n==0){
            return NULL;
        }
        if(index>=n|| preorder[index]<left_max || preorder[index]>right_min){
            return NULL;
        }
        if(preorder[index]>left_max && preorder[index]<right_min){
            TreeNode* root=new TreeNode(preorder[index]);
            index++;
             root->left=createBST(preorder,left_max,root->val);
             root->right=createBST(preorder,root->val,right_min);
            return root;
        }
       return NULL;    
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int n=preorder.size();
        if(n==0){
            return NULL;
        }
       
        if(n==1){
            TreeNode* root=new TreeNode(preorder[index]);
            return root;
        }
        if(index>=n){
            return NULL;
        }
        
        return createBST(preorder,INT_MIN, INT_MAX);
       
        
    }
};
