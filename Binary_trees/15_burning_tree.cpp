

class Solution {
  public:
    void klevelDown(Node *root,int k,Node* block,int &maxTime){
        if(root==NULL||root==block){
            return;
        }
        if(k>maxTime){
            maxTime=k;
        }
        klevelDown(root->left,k+1,block,maxTime);
        klevelDown(root->right,k+1,block,maxTime);
        
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
     int minTime(Node* root, int target)
    {
        //first making the vector that stores root to node path
        vector<Node*>path;
        rootToNode(root,target,path);
        
        int maxTime=0;
        
        //now doing kleveldown from each element of vector
        //remember initially the first ever node takes 0 time to burn, becoz we are 
        //setting up fire to it at 0th time
        klevelDown(path[0],0,NULL,maxTime);
        
        //and from 1st index of rootToNodePath vector we pass i as the start time for burning
        for(int i=1;i<path.size();i++){
            klevelDown(path[i],i,path[i-1],maxTime);
        }
        return maxTime;
    }
};