class Solution {
public:
    void inorder_wrec(TreeNode* root, vector<int>* output){
        if(root==NULL){
            return;
        }
        stack<TreeNode*> st;
        while(!st.empty() or root!=NULL){
            if(root!=NULL){
                st.push(root);
                root=root->left;
            }
            else{
             TreeNode* curr=st.top();
             st.pop();
             output->push_back(curr->val);
             root=curr->right;   
            }
            
        }
    }
    void inorder(TreeNode* root, vector<int>* output){
        if(root==NULL){
            return;
        }
        inorder(root->left,output);
        output->push_back(root->val);
        inorder(root->right,output);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>* output=new vector<int>();
        if(root==NULL){
            return *output;
        }
        //inorder(root,output);
        inorder_wrec(root,output);
        return *output;
        
    }
};
