class Solution{
    public:
    //Function to store the zig zag order traversal of tree in a list.
    vector <int> zigZagTraversal(Node* root)
    {
        vector<int> ans;
        if(root==NULL){
            return ans;
        }
        stack<Node*> q;
        stack<Node*> qinv;
        q.push(root);
        bool left_to_right=true;
        while(!q.empty()){
            Node* node=q.top();
            q.pop();
           
                ans.push_back(node->data);
                if(left_to_right){
                    //left to right
                    if(node->left)
                    qinv.push(node->left);
                    if(node->right)
                    qinv.push(node->right);
                }
                else{
                    //right to left;
                    if(node->right)
                    qinv.push(node->right);
                    if(node->left)
                    qinv.push(node->left);
                }
            
           
                if(q.empty()){
                    left_to_right=!left_to_right;
                    swap(q,qinv);
                   
                }
            
        }
        return ans;
    }
};
