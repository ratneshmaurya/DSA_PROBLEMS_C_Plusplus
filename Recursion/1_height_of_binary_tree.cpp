class Solution{
    public:
    int maxh=INT_MIN;
    void help(struct Node* root,int h){
        if(root==NULL) return;
        if(h>maxh)maxh=h;
        help(root->left,h+1);
        help(root->right,h+1);
    }
    //Function to find the height of a binary tree.
    int height(struct Node* node){
        // code here 
        help(node,1);
        return maxh;
    }
};