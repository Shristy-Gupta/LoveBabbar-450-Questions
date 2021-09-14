/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> paths;
    int count=0;
    void evaluate_pathsum(TreeNode* root, int targetSum){
        if(root==NULL){
            return;
        }
        paths.push_back(root->val);
        evaluate_pathsum(root->left,targetSum);
        evaluate_pathsum(root->right,targetSum);
        int sum=0;
        int n=paths.size();
        for(int i=n-1;i>=0;i--){
            sum+=paths[i];
            if(sum==targetSum){
                count++;
                //sum=0;
            }
        }
        paths.pop_back();
    }
    int pathSum(TreeNode* root, int targetSum) {
       if(root==NULL){
           return 0;
       } 
       evaluate_pathsum(root,targetSum);
       return count; 
        
    }
};
