class Solution {
  public:
    vector <int> bottomView(Node *root) {
        // Your Code Here
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
        
        //now top view will be the last element of every field of map;
        //now think how do u fetch last element from every vector field of map.
        vector<int>ans;
        for(auto& i:m){
            ans.push_back(i.second[i.second.size()-1]);
        }
        return ans;
    }
};