class Solution {
    private:
    
    int help(TreeNode* root,int depth,int &sum, int &maxDepth){
        if(root==NULL) return 0;
        if(depth==maxDepth) sum+=root->val;
        else if(depth>maxDepth){
            sum=root->val;
            maxDepth=depth;;
        }
        help(root->left,depth+1,sum,maxDepth);
        help(root->right,depth+1,sum,maxDepth);
        return sum;
    }
public:
    int deepestLeavesSum(TreeNode* root) {
        int sum=0,maxDepth=-1,depth=0;
        return help(root,depth,sum,maxDepth);
    }
};