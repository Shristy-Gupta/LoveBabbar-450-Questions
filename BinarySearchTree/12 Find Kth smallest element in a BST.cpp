class Solution {
  public:
    // Return the Kth smallest element in the given BST
    int level=0;
    int ans=-1;
    void KthSmallestElementHelper(Node *root,int K){
        if(root==NULL){
            return;
        }
        KthSmallestElementHelper(root->left,K);
        level++;
        if(level==K){
            ans=root->data;
            
            return;
        }
       
        KthSmallestElementHelper(root->right,K);
    }
    int KthSmallestElement(Node *root, int K){
      if(root==NULL){
          return -1;
      }
      KthSmallestElementHelper(root,K);
      return ans;
    }
};
