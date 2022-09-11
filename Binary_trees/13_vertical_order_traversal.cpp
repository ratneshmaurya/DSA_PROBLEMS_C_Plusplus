
//pepcoding solution


class Solution
{
    public:
    //Function to find the vertical order traversal of Binary Tree.
    vector<int> verticalOrder(Node *root)
    {
        //Your code here
        map<int,vector<int>>m;
        queue<pair<Node*,int>>q;
        q.push({root,0});
        while(!q.empty()){
            int n=q.size();
            for(int i=0;i<n;i++){
                pair<Node*,int>front=q.front();
                q.pop();
                m[front.second].push_back(front.first->data);
                if(front.first->left) q.push({front.first->left,front.second-1});
                if(front.first->right) q.push({front.first->right,front.second+1});
            }
            
        }
        
        vector<int>ans;
        
        for(auto&i:m){
            for(auto&j:i.second){
                ans.push_back(j);
            }
        }
        return ans;
    }
};