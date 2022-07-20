class Solution {
private:
    TreeNode* helper(vector<int>& inorder, vector<int>& postorder, int &postorderIndex,int inStart,int inEnd,unordered_map<int,int>&m){
        
        if(inStart>inEnd)return NULL;
        
        //fetching root from preorder index
        int element=postorder[postorderIndex--];
        TreeNode*root=new TreeNode(element);
        
        //fetching the mid position in inorder
        int mid=m[root->val];
        
        //calling on both side, calling first right side
        root->right=helper(inorder,postorder,postorderIndex,mid+1,inEnd,m);
        root->left=helper(inorder,postorder,postorderIndex,inStart,mid-1,m);
        
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
        //storing inorder elements in map
        unordered_map<int,int>m;
        int postorderIndex=postorder.size()-1;
        for(int i=0;i<inorder.size();i++) m[inorder[i]]=i;
        return helper(inorder,postorder,postorderIndex,0,inorder.size()-1,m);
    }
};