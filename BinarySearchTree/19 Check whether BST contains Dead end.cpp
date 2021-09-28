bool solve(Node *root, int min, int max){
    if(root==NULL){
        return false;
    }
    if(min==max){return true;}
    return solve(root->left,min,root->data-1) or solve(root->right,root->data+1,max);
}
/*You are required to complete below method */
bool isDeadEnd(Node *root)
{
    return solve(root,1,INT_MAX);
}
