class Solution {
    //Time complecity O(nlogn) because of insertion in map
  public:
    vector <int> bottomView(Node *root) {
        vector<int> ans;
        if(root==NULL){
            return ans;
        }
        map<int,int> m;
        queue<pair<Node*,int>> q;
        q.push({root,0});
        while(!q.empty()){
            Node* node=q.front().first;
            int h=q.front().second;
            q.pop();
            m[h]=node->data;
            if(node->left){
                q.push({node->left,h-1});
            }
            if(node->right){
                q.push({node->right,h+1});
            }
        }
        for(auto it:m){
            ans.push_back(it.second);
        }
    }
};
