string solve(Node* root,unordered_map<string,int>& m,bool &f,vector<Node*> &res){
    if(root==NULL){
       return ""; 
    }
    string s="(";
  
    s+=solve(root->left,m,f,res);
    s+=to_string(root->data);
    s+=solve(root->right,m,f,res);
    s+=")";
    //cout<<s<<endl;
    if(m[s]==1){
        f=true;
        //because we are inserting root only
        res.push_back(root);
    }
    m[s]++;
    return s;
}
vector<Node*> printAllDups(Node* root)
{
    bool f=false;
    unordered_map<string,int>m;
    vector<Node*>res;
    solve(root,m,f,res);
    if(!f){
       vector<Node*>res;
       return res;
    }
    else{
        //sort(res.begin(),res.end());
        return res;
    }
}
