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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL){
            return root;
        }
        if(root->val==key){
            if(root->left==NULL && root->right==NULL){
                delete root;
                return NULL;
            }
            if(root->right==NULL){
                TreeNode* left_node=root->left;
                delete root;
                return left_node;
            }
            if(root->left==NULL){
                TreeNode* right_node=root->right;
                delete root;
                return right_node;
            }
            else{
                //leftmost greatest element
               TreeNode* right=root->right;
               while(right->left){
                   right=right->left;
               } 
               swap(right->val,root->val);
                
            }
            
            
        }
        root->left = deleteNode(root->left, key);
        root->right = deleteNode(root->right, key);
        return root;
        
    }
};
