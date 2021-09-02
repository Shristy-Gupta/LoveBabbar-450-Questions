vector<int> ans;
vector<int> reverseLevelOrder(Node *root)
{
    if(root==NULL){
        return ans;
    }
    queue<Node*> q;
    stack<Node*> s;
    q.push(root);
    while(!q.empty()){
        Node* node=q.front();
        q.pop();
        //ans.push_back(node->data);
        s.push(node);
        if(node->right!=NULL){
            q.push(node->right);
        }
        if(node->left!=NULL){
            q.push(node->left);
        }
        
    }
    //reverse(ans.begin(),ans.end());
    while(!s.empty()){
        ans.push_back(s.top()->data);
        s.pop();
    }
    return ans;
}
