class Solution
{
    public:
    int ans; int counter;
    void find_kthlargest(Node *root, int K){
        if(root==NULL){
            return;
        }
        find_kthlargest(root->right,K);
        if(counter==K){
           ans=root->data;
           counter++;
           return;
        }
        counter++;
        find_kthlargest(root->left,K);
    }
    int kthLargest(Node *root, int K)
    {
        if(root==NULL){
            return -1;
        }
        counter=1;
        find_kthlargest(root,K);
        return ans;
    }
};
