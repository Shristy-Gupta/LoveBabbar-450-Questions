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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(root==NULL){
            return ans;
        }
        stack<TreeNode*> input;
        stack<TreeNode*> output;
        input.push(root);
        /*
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        cout<<root<<endl;
        
        */
        while(!input.empty()){
            TreeNode* curr=input.top();
            output.push(curr);
            input.pop();
            if(curr->left!=NULL){
                input.push(curr->left);
            }
            if(curr->right!=NULL){
                input.push(curr->right);
            }
            
        }
        while(!output.empty()){
            TreeNode* curr=output.top();
            if(curr!=NULL)
            ans.push_back(curr->val);
            output.pop(); 
        }
        return ans;
    }
};
