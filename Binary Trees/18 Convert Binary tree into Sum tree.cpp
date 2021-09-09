class Solution {
  public:
   int toSumTreeHelper(Node* node){
       if(node==NULL){
           return 0;
       }
       int ret=0;
       if(node->left==NULL && node->right==NULL){
           ret=node->data;
           node->data=0;
           return ret;
       }
       int left=toSumTreeHelper(node->left);
       int right=toSumTreeHelper(node->right);
       ret=node->data;
       node->data=left+right;
       return node->data+ret;
   }
    // Convert a given tree to a tree where every node contains sum of values of
    // nodes in left and right subtrees in the original tree
    void toSumTree(Node *node)
    {
        if(node==NULL){
            return;
        }
        toSumTreeHelper(node);
    }
};
