
//solution for gfg

void klevelDown(Node *root,int k,Node* block,vector<int>&ans){
        if(root==NULL||root==block||k<0){
            return;
        }
        if(k==0){
            ans.push_back(root->data);
            return;
        }
        klevelDown(root->left,k-1,block,ans);
        klevelDown(root->right,k-1,block,ans);
        
    }
    bool rootToNode(Node* root,int target,vector<Node*>&path){
        if(root==NULL) return false;
        if(root->data==target){
            path.push_back(root); 
            return true;
        }
        if(rootToNode(root->left,target,path)){
            path.push_back(root);
            return true;
        }
        if(rootToNode(root->right,target,path)){
            path.push_back(root);
            return true;
        }
        return false;
    }
    vector <int> KDistanceNodes(Node* root, int target , int k)
    {
        //first making the vector that stores root to node path
        vector<Node*>path;
        rootToNode(root,target,path);
        
        //vector to store answer
        vector<int>ans;
        
        //now doing kleveldown from each element of vector
        klevelDown(path[0],k,NULL,ans);
        for(int i=1;i<path.size();i++){
            klevelDown(path[i],k-i,path[i-1],ans);
        }
        
        //at last sorting the result as stated in question
        sort(ans.begin(),ans.end());
        return ans;
    }
};