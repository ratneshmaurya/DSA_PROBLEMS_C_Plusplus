class Solution {
    private:
    int solve(Node*root,int &result){
        if(root==NULL) return 0;
        int l=solve(root->left,result);
        int r=solve(root->right,result);
        
        int temp=max(l,r)+1;
        int ans=max(temp,l+r+1);
        result=max(ans,result);
        return temp;
    }
  public:
    // Function to return the diameter of a Binary Tree.
    int diameter(Node* root) {
        int result=0;
        solve(root,result);
        return result;
    }
};
