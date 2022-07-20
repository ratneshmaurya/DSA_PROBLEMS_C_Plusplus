class Solution {
    private:
    pair<int,int> helper(TreeNode* root){
    if(root==NULL){
            pair<int,int>p;
            p.first=0;
            p.second=0;
            return p;
        }
        pair<int,int>left=helper(root->left);
        pair<int,int>right=helper(root->right);
        
        int height=1+(max(left.first , right.first));
        int diameter=max(left.first + right.first, max(left.second,right.second));
        pair<int,int>p;
        p.first=height;
        p.second=diameter;
        return p;
}
public:
    int diameterOfBinaryTree(TreeNode* root) {
        pair<int,int>p=helper(root);
        return p.second;
    }
};
