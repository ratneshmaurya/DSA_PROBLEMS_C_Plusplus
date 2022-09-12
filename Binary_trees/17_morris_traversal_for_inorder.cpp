
//for inorder_traversal
//striver method

vector<int> helper(Node *root){
    vector<int>inorder;
    Node*cur=root;
    while(curr!=NULL){

        //if left s null then take this node and move to right, simple as done in inorder;
        if(cur->left==NULL){
            inorder.push_back(cur->data);
            cur=cur->right;
        }

        //when left node is there
        else{

            //move to left subtree and make the thread from right most node to our current node so that path 
            //formed for coming back
            Node* next=cur->left;
            while(next->right && next->right!=curr){
                next=next->right;
            }

            //then two option formed, our next reaches to rightmost node of left subtree, that is thread was 
            //not there initially, second it happens like our next pointer's right is pointing back to our cur
            //i.e a thread is already there
            

            //if next reaches to rightmost and thread is not there then make thread and move to left
            if(next->right==NULL){
                next->right=cur;
                cur=cur->left;
            }

            //next pointer's right is pointing back to our cur i.e a thread is already there
            //then remove that thread and move to right, becoz you have already covered that left subtree part
            else{
                next->right=NULL;
                inorder.push_back(cur->data);
                cur=cur->right;
            }
        }
    }
    return inorder;
}