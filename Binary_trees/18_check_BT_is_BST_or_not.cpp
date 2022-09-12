class Solution
{
    public:
    //Function to check whether a Binary Tree is BST or not.
    bool help(Node*root,int min,int max){
        if(root==NULL)return true;
        if(root->data<min||root->data>max)return false;
        return help(root->left,min,root->data-1)&&help(root->right,root->data+1,max);
    }
    bool isBST(Node* root) 
    {
        // Your code here
        int max=INT_MAX;
        int min=INT_MIN;
        return help(root,min,max);
    }
};