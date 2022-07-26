class Solution {
    private:
    int solve(Node*root,int &result){
        if(root==NULL)return 0;
        int l=solve(root->left,result);
        int r=solve(root->right,result);
        
        int temp=max(max(l,r)+root->data, root->data);
        int ans=max(temp,l+r+root->data);
        result=max(result,ans);
        return temp;
    }
  public:
    int findMaxSum(Node* root)
    {
        // Your code goes here
        int result=INT_MIN;
        solve(root,result);
        return result;
    }
};