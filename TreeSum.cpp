#include "bits/stdc++.h" 


using namespace std; 

class TreeNode{
    public :
    int data;
    TreeNode * left;
    TreeNode * right;
    TreeNode(int data)
    {
        this->data=data;
        this->left=nullptr;
        this->right=nullptr;
    }
    ~TreeNode()
    {
        delete left;
        delete right;
        delete this;
    }
};

TreeNode * input(int &n)
{
    queue<TreeNode *>q;
    int x;
    cin>>x;
    TreeNode * root = new TreeNode(x);
    n--;
    q.push(root);
    while(!q.empty())
    {
        TreeNode * frnt=q.front();
        q.pop();
        int a,b;
        cin>>a>>b;
        if(a!=-1)
        {
            TreeNode * tm1 = new TreeNode(a);
            frnt->left=tm1;
            q.push(tm1);
            n--;
        }
        if(b!=-1)
        {
            TreeNode * tm1 = new TreeNode(b);
            frnt->right=tm1;
            q.push(tm1);
            n--;
        }
        if(!n)break;
    }
    return root;
}


void show(TreeNode * root)
{
    queue<TreeNode *> q;
    q.push(root);
    while(!q.empty())
    {
        TreeNode * frnt=q.front();
        cout<<frnt->data<<" ";
        q.pop();
        if(frnt->left)q.push(frnt->left);
        if(frnt->right)q.push(frnt->right);
    }
    cout<<"\b\n";
}


bool TreeSum(TreeNode * root,int target)
{
    if(target==0)return 1;
    if(root==nullptr)return 0;
    target-=root->data;
    return  TreeSum(root->left,target) || TreeSum(root->right,target);
}

int main(void) 
{ 
    ios_base::sync_with_stdio(0); 
    cin.tie(0); 
    #ifndef ONLINE_JUDGE 
        freopen("input.txt", "r", stdin); 
        freopen("output.txt", "w", stdout); 
    #endif 
    int n;
    cin>>n;
    TreeNode * root = input(n);
    show(root);
    cout<<TreeSum(root,8);
    return 0; 
} 