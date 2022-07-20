class Solution {
private:
    TreeNode* helper(vector<int>& preorder, vector<int>& inorder, int &preorderIndex,int inStart,int inEnd,unordered_map<int,int>&m){
        
        if(inStart>inEnd)return NULL;
        
        //fetching root from preorder index
        int element=preorder[preorderIndex++];
        TreeNode*root=new TreeNode(element);
        
        //fetching the mid position in inorder
        int mid=m[root->val];
        
        //calling on both side, calling first left side remember
        root->left=helper(preorder,inorder,preorderIndex,inStart,mid-1,m);
        root->right=helper(preorder,inorder,preorderIndex,mid+1,inEnd,m);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        //storing inorder elements in map
        unordered_map<int,int>m;
        int preorderIndex=0;
        for(int i=0;i<inorder.size();i++) m[inorder[i]]=i;
        return helper(preorder,inorder,preorderIndex,0,preorder.size()-1,m);
    }
};