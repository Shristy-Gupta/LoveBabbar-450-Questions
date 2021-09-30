class Solution{
    public:
    //vector<int>// leftmax,rightmin,size,isBST 
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    vector<int> largestBstHelper(Node *root){
        vector<int> ans;
        if(root==NULL){
            ans={INT_MIN,INT_MAX,0,1};
            return ans;
        }
        if(root->left==NULL && root->right==NULL){
            return {root->data,root->data,1,1};
        }
        vector<int> left=largestBstHelper(root->left);
        vector<int> right=largestBstHelper(root->right);
        if(root->data>left[0] && root->data<right[1] && left[3] && right[3]){
            int left_max=right[0],right_min=left[1];
            if(left[1]==INT_MAX){
                right_min=root->data;
            }
            else if(right[0]==INT_MIN){
                left_max=root->data;
            }
            return {left_max,right_min,1+left[2]+right[2],1};
        }
        return{0,0,max(left[2],right[2]),0};
    }
    int largestBst(Node *root)
    {
       vector<int> ans=largestBstHelper(root);
       return ans[2];
    }
};
