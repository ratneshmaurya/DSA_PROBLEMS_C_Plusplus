vector<int> diagonal(Node *root)
{
   queue<Node*>q;// to store the nodes,mainly left node of all diagonal line, for next traversal
   //basically we will be pushing a component of every diagonal in queue, so that we can go all 
   //possible right from him in a diagonal
   
   q.push(root);
   vector<int>ans;
   
   while(!q.empty())
   {
       
       int k=q.size();
       
       //now for one diagonal line, here k denotes number of components in a diagonal 
       //that we have stored
       while(k--)
       {
           Node* component=q.front();
           q.pop();
           
           //now we traverse till we can go to right from this node in a diagonal.
           while(component!=NULL)
           {
               
               //if we get any left component we will store it in our queue
               if(component->left) q.push(component->left);
               ans.push_back(component->data);
               component=component->right;
           }
       }
   }
   return ans;
   
}