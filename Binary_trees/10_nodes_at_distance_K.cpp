class Solution
{
private:
    void kleveldown(Node* root, int k, int blocknode,vector<int>&ans){
        if(root==NULL||k<0||root->data==blocknode) return ;
        
        if(k==0){
            ans.push_back(root->data);
            return;
        }
        kleveldown(root->left,k-1,blocknode,ans);
        kleveldown(root->right,k-1,blocknode,ans);
    }
    
    int helper(Node* root, int target , int k,vector<int>&ans){
        if(root==NULL) return -1;
        if(root->data==target){
            kleveldown(root,k,NULL,ans);
            return 1;
        }
        int l=helper(root->left,target,k,ans);
        if(l!=-1){
            kleveldown(root,k-l,root->left->data,ans);
            return l+1;
        }
        int r=helper(root->right,target,k,ans);
        if(r!=-1){
            kleveldown(root,k-r,root->right->data,ans);
            return r+1;
        }
        return -1;
    }
public:
    
    vector <int> KDistanceNodes(Node* root, int target , int k)
    {
        // return the sorted vector of all nodes at k dist
        vector<int>ans;
        helper(root,target,k,ans);
        return ans;
    }
};