class Solution
{
    public:
    bool isBST(Node* root, Node* left_max, Node* right_min){
        if(root==NULL){
            return true;
        }
        if(left_max!=NULL && root->data<=left_max->data){
            return false;
        }
        if(right_min!=NULL && root->data>=right_min->data){
            return false;
        }
        return isBST(root->left,left_max,root) and isBST(root->right,root,right_min);
    }
    //Function to check whether a Binary Tree is BST or not.
    bool isBST(Node* root) 
    {
        return isBST(root,NULL,NULL);
    }
};
