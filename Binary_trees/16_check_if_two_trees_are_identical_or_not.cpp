class Solution
{
    public:
    //Function to check if two trees are identical.
    bool isIdentical(Node *r1, Node *r2)
    {
        //Your Code here
        if(r1==nullptr&&r2==nullptr)return true;
        
        //anyone is null and one is not null
        if(r1==nullptr||r2==nullptr)return false;
        
        return (r1->data==r2->data&&isIdentical(r1->left,r2->left)&&(isIdentical(r1->right,r2->right)));
        
    }
};


//------------------------------------
//remember code is same for check if 2 binary trees are mirror or not 
//just one difference is we call one tree to right and other tree to left and vice versa

// class Solution
// {
//     public:
//     //Function to check if two trees are identical.
//     bool isIdentical(Node *r1, Node *r2)
//     {
//         //Your Code here
//         if(r1==nullptr&&r2==nullptr)return true;
        
//         //anyone is null and one is not null
//         if(r1==nullptr||r2==nullptr)return false;
        
//         return (r1->data==r2->data&&isIdentical(r1->left,r2->right)&&(isIdentical(r1->right,r2->leftt)));
        
//     }
// };