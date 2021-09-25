class Solution
{
public:
    bool find_val(Node* root, int x){
        if(root==NULL){
            return false;
        }
        if(root->data>x){
            return find_val(root->left,x);
        }
        if(root->data==x){
            return true;
        }
        if(root->data<x){
            return find_val(root->right,x);
        }
    }
    int countPairs(Node* root1, Node* root2, int x)
    {
       if(root1==NULL || root2==NULL){
           return -1;
       }
       int count_pair=0;
       queue<Node*> q;
       q.push(root1);
       while(!q.empty()){
           Node* curr=q.front();
           q.pop();
           if(curr->left){
               q.push(curr->left);
           }
           if(curr->right){
               q.push(curr->right);
           }
           if(curr->data<=x){
               if(find_val(root2,x-curr->data)){
                   count_pair++;
               }
           }
       }
       return count_pair;
    }
};
