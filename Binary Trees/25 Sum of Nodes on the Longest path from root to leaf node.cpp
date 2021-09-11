class Solution
{
public:
//first is sum and second is depth
    pair<int,int> sumOfLongRootToLeafPathHelper(Node *root){
        pair<int,int> ans;
        if(root==NULL){
            ans.first=0;
            ans.second=0;
            return ans;
        }
        if(root->left==NULL && root->right==NULL){
            ans.first=root->data;
            ans.second=1;
            return ans;
        }
        //checking the node
        pair<int,int> leftans=sumOfLongRootToLeafPathHelper(root->left);
        pair<int,int> rightans=sumOfLongRootToLeafPathHelper(root->right);
        if(leftans.second>rightans.second){
            ans.second=1+leftans.second;
            ans.first=root->data+leftans.first;
        }
        else if(leftans.second<rightans.second){
            ans.second=1+rightans.second;
            ans.first=root->data+rightans.first;
        }
        else{
            ans.second=1+rightans.second;
            if(rightans.first>leftans.first){
                ans.first=rightans.first+root->data;
            }
            else{
                ans.first=leftans.first+root->data;
            }
        }
        return ans;
    }
    int sumOfLongRootToLeafPath(Node *root)
    {
        if(root==NULL){
            return 0;
        }
        else{
            return sumOfLongRootToLeafPathHelper(root).first;
        }
    }
};
