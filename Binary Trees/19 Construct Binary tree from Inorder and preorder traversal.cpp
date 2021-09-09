class Solution{
    public:
    Node* buildTree(int in[],int instart, int inend,int pre[], int prestart, int preend, int n){
       if(inend==n || preend==n || instart>inend || prestart>preend ||instart<0 ||prestart<0){
           return NULL;
       } 
       
       Node* root=new Node(pre[prestart]);
       //root->data=pre[prestart];
       int index=-1;
       for(int i=instart;i<=inend;i++){
           if(in[i]==pre[prestart]){
               index=i;
           }
       }
       int len=index-instart;
       root->left=buildTree(in,instart,index-1,pre,prestart+1,prestart+len,n);
       root->right=buildTree(in,index+1,inend,pre, prestart+len+1,preend,n);
       return root;
        
    }
    Node* buildTree(int in[],int pre[], int n)
    {
        if(n==0){
            return NULL;
        }
        return buildTree(in, 0,n-1,pre,0,n-1,n);
    }
};
