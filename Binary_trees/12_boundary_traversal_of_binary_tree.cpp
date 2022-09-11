class Solution {
public:
    void leftPart(Node*root,vector<int>&ans){
        if((root==NULL)||(root->left==NULL && root->right==NULL)) return ;
        ans.push_back(root->data);
        if(root->left!=nullptr)leftPart(root->left,ans);
        else leftPart(root->right,ans);
    }
    void rightPart(Node*root,vector<int>&ans){
        if((root==NULL)||(root->left==NULL && root->right==NULL)) return ;
        if(root->right)rightPart(root->right,ans);
        else rightPart(root->left,ans);
        ans.push_back(root->data);
    }
    void leafNodes(Node * root,vector<int>&ans){
        if(root==NULL)return ;
        if(root->left==NULL && root->right==NULL) ans.push_back(root->data);
        leafNodes(root->left,ans);
        leafNodes(root->right,ans);
    }
    vector <int> boundary(Node *root)
    {
        //traverse left
        vector<int>ans;
        if(root==NULL)return ans;
        ans.push_back(root->data);
        
        //important to call from left, becoz if left part ho hi na tree me
        leftPart(root->left,ans);
        
        //must call for both left and right becoz if input me ek hi node hoga then leaf node na chle
        leafNodes(root->left,ans);
        leafNodes(root->right,ans);
        
        //for right part
        rightPart(root->right,ans);
        return ans;
    }
};