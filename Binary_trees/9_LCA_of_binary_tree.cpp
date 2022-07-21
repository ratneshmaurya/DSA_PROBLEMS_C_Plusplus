class Solution {
    
public:
    TreeNode*LCA;
    bool helper(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root==NULL) return 0;
        bool current=root->val==p->val || root->val==q->val;
        
        bool left=helper(root->left,p,q);
        if(LCA)return 1;
        
        bool right=helper(root->right,p,q);
        if(LCA)return 1;
        
        if(left&&right|| left&&current ||right&&current) LCA=root;
        
        return left||right||current;
        
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        bool check=helper(root,p,q);
        if(check) return LCA;
        else return NULL;
    }
};