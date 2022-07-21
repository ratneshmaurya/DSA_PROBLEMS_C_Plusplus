
// Given a binary tree and an integer K. Find the number of paths in the tree which have their sum equal to K.
//A path may start from any node and end at any node in the downward direction.

class Solution{
    private:
    void helper(Node *root,int k,vector<int>&v,int & count){
        if(root==NULL){
            return;
        }
        //at every step, store the path in vector
        v.push_back(root->data);
        helper(root->left,k,v,count);
        helper(root->right,k,v,count);
        
        //now calculate the sum from our traversed path;
        int sum=0;
        for(int i=v.size()-1;i>=0;i--){
            sum+=v[i];
            if(sum==k){
                count++;
            }
        }
        
        //remove the element which we are leaving,so to maintain the path covered
        v.pop_back();
    }
  public:
    int sumK(Node *root,int k)
    {
        // code here 
        vector<int>v;
        int count=0;
        helper(root,k,v,count);
        return count;
    }
};