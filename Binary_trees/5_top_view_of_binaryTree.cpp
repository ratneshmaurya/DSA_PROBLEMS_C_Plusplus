struct Node
{
    int data;
    Node* left;
    Node* right;
};

class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        //Your code here
        int horizontal=0;
        queue<pair<Node*,int>>q;
        map<int,vector<int>>m;
        q.push({root,0});
        pair<Node*,int>p;
        
        //we will do BFS traversal and store the vertical order in map.
        while(!q.empty()){
            int k=q.size();
            while(k--){
                
                //popping every element of the same level ans pushing into map
                p=q.front();
                q.pop();
                m[p.second].push_back(p.first->data);
                
                if(p.first->left){
                    q.push({p.first->left,p.second-1});
                }
                if(p.first->right){
                    q.push({p.first->right,p.second+1});
                }
            }
            
        }
        
        //now top view will be the first element of every field of map;
        vector<int>ans;
        for(auto& i:m){
            ans.push_back(i.second[0]);
        }
        return ans;
    }

};