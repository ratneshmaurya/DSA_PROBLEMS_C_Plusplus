
// LOVE BABBAR SOLUTION
class Solution
{
    public:
    //Function to return the lowest common ancestor in a Binary Tree.
    Node* lca(Node* root ,int n1 ,int n2 )
    {
       //Your code here 
       if(root==NULL)return NULL;
       if(root->data==n1 || root->data==n2){
           return root;
       }
       Node*left=lca(root->left,n1,n2);
       Node*right=lca(root->right,n1,n2);
       
       if(left!=NULL && right!=NULL)return root;
       if(left!=NULL && right==NULL)return left;
       if(left==NULL && right!=NULL)return right;
       else return NULL;
    }
};

//-------------------------------------------------------------------------------------------------
//below solution done by me (myself), after some months

// class Solution {
// public:  
//     TreeNode*ans;
//     bool helper(TreeNode* root, TreeNode* p, TreeNode* q){
//         if(root==NULL) return false;
        
//         //agar p and q mil jaaye then this node may be answer for lca.
//         if(root==p||root==q){
//             ans=root;
//             return true;
//         }
//         bool leftans=helper(root->left,p,q);
//         bool rightans=helper(root->right,p,q);
        
//         //agar laft and right dono trf se true aa rha it means this node is lca, store it in ans and return false so that no further become right condition for true;
//         if(leftans&&rightans){
//             ans=root;
//             return false;
//         }
        
//         //if we got only one true then return true becoz abhi second node search krna
//         if(leftans||rightans){
//             return true;
//         }
        
//         //if we don't get any node from any side return false;
//         return false;
//     }
//     TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//         helper(root,p,q);
//         return ans;
//     }
// };


//-----------------------------------------------------------------------------------------------------

//below solution is also running fine -- pepcoding

// class Solution {
    
// public:
//     TreeNode*LCA;
//     bool helper(TreeNode* root, TreeNode* p, TreeNode* q){
//         if(root==NULL) return 0;
//         bool current=root->val==p->val || root->val==q->val;
        
//         bool left=helper(root->left,p,q);
//         if(LCA)return 1;
        
//         bool right=helper(root->right,p,q);
//         if(LCA)return 1;
        
//         if(left&&right|| left&&current ||right&&current) LCA=root;
        
//         return left||right||current;
        
//     }
//     TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//         bool check=helper(root,p,q);
//         if(check) return LCA;
//         else return NULL;
//     }
// };