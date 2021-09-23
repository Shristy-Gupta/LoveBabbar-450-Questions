class Solution{
  public:
    // The given root is the root of the Binary Tree
    // Return the root of the generated BST
    int i=0;
    void insertvalues(Node* root,vector<int>& inordervalues){
        if(root==NULL){
            return;
        }
        insertvalues(root->left,inordervalues);
        root->data=inordervalues[i];
        i++;
        insertvalues(root->right,inordervalues);
    }
    void inorder(Node* root, vector<int>& inordervalues){
        if(root==NULL){
            return;
        }
        inorder(root->left,inordervalues);
        inordervalues.push_back(root->data);
        inorder(root->right,inordervalues);
    }
    Node *binaryTreeToBST (Node *root)
    {
        if(root==NULL){
            return root;
        }
        if(root->left==NULL && root->right==NULL){
            return root;
        }
        vector<int> inordervalues;
        inorder(root,inordervalues);
        sort(inordervalues.begin(),inordervalues.end());
        insertvalues(root,inordervalues);
        return root;
    }
};
