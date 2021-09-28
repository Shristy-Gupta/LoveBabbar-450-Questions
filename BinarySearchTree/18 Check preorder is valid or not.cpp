Node* constructBST(int pre[], int prestart, int preend, int in[], int instart, int inend, int size){
    if(prestart>preend || instart>inend ||inend>=size ||preend>=size ||prestart<0 ||instart<0){
        return NULL;
    }
    Node* root=newNode(pre[prestart]);
    int index=-1,s=0;
    for(int i=instart;i<=inend;i++){
        if(in[i]==pre[prestart]){
            index=i;
            break;
        }
    }
    if(index==-1){
        return NULL;
    }
    s=index-instart;
    root->left=constructBST(pre,prestart+1,prestart+s,in,instart,index-1,size);
    root->right=constructBST(pre,prestart+s+1,preend,in,index+1,inend,size);
    return root;
}

Node* constructBSTfrompreandpost(int pre[],int in[],int size){
    return constructBST(pre,0,size-1,in,0,size-1,size);
}
//Function that constructs BST from its preorder traversal.
Node* constructTree(int pre[], int size)
{
    if(size==0){
        return NULL;
    }
    if(size==1){
        return newNode(pre[0]);
    }
    int in[size];
    copy(pre,pre+size,in);
    sort(in,in+size);
    //create bst from pre and in
    return constructBSTfrompreandpost(pre,in,size);
}
