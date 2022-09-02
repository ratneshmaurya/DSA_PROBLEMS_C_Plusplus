class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    
	    //must make initially the indegree of all nodes=0
	    vector<int>indegree(V,0);  // not running if i am not writing 0 here, why ?, in indegree
	    //array,it was not pushing '2' see the first test example on left side
	   
        for(int i=0;i<V;i++){
            for(auto neighbour : adj[i]){
                indegree[neighbour]++;
            }
        }
  
	    
	    queue<int>q;
	    vector<int>ans;
	    
	    for(int i=0;i<V;i++){
	        if(indegree[i]==0){
	            q.push(i);
	            //cout<<i<<" ";
	        }
	    }
	    //cout<<endl;
	    while(!q.empty()){
	        int frontEle=q.front();
	        q.pop();
	        ans.push_back(frontEle);
	        for(auto &i:adj[frontEle]){
	            indegree[i]--;
	            if(indegree[i]==0) q.push(i);
	        }
	    }
	   // for(auto&i:ans){
	   //     cout<<i<<" ";
	   // }
	    //cout<<endl;
	    return ans;
	}
};