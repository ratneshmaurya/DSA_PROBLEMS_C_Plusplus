
//concept of love babbar

class Solution{
    public:
    //Function to store the zig zag order traversal of tree in a list.
    vector <int> zigZagTraversal(Node* root)
    {
    	// Code here
    	vector<int>res;
    	if(root==NULL)return res;
    	queue<Node*>q;
    	q.push(root);
    	int index;
    	bool ltor=true;
    	while(!q.empty()){
    	    int size=q.size();
    	    vector<int>ans(size);
    	    for(int i=0;i<size;i++){
    	        Node*front=q.front();
        	    q.pop();
        	    if(ltor) index=i;
        	    else index=size-i-1;
        	    ans[index]=front->data;
        	    if(front->left)q.push(front->left);
        	    if(front->right)q.push(front->right);
    	    }
    	    ltor=!ltor;
    	    for(auto&i:ans) res.push_back(i);
    	}
    	return res;
    }
};