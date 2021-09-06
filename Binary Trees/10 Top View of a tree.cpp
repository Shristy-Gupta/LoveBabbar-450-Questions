class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        //https://www.youtube.com/watch?v=c3SAvcjWb1E
        //Time complexity O(n) space
        //TIme complexity O(nlogn) because of map
       vector<int> ans;
       if(root==NULL){
           return ans;
       }
       queue<pair<Node*,int>>q;
       map<int,int> m;
       q.push({root,0});
       while(!q.empty()){
               Node* node=q.front().first;
               int h=q.front().second;
               q.pop();
               if(!m[h])m[h]=node->data;
               if(node->left){
                   q.push({node->left,h-1});
               }
               if(node->right){
                   q.push({node->right,h+1});
               }
           
       }
       //travserse the list
       for(auto it:m){
           ans.push_back(it.second);
       }
       return ans;
    }

};
