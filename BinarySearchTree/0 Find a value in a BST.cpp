Node* insert(Node* root, int key) {
    if(root==NULL){
        return new Node(key);
    }
    else if(root->data==key){
        return NULL;
    }
    else if(root->data>key){
        Node* left_ans=insert(root->left,key);
        if(left_ans){
            root->left=left_ans;
        }
        
    }
    else if(root->data<key){
        Node* right_ans=insert(root->right,key);
        if(right_ans){
            root->right=right_ans;
        }
    }
    return root;
}
