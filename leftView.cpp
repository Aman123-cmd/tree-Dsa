#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class Tree {
    public:
    int data;
    Tree *left, *right; 
    Tree(int data):data(data),left(nullptr),right(nullptr){};   
};

Tree * createTree(){
    int data;
    cout<<"Enter the vakue of the node->"<<endl;
    cin>>data;
    if(data==-1) return NULL;   
    Tree* root = new Tree(data);
    cout<<"enter the left value of the node ->"<<data<<endl;
    root->left = createTree();
    cout<<"enter the right balue of the node ->"<<data<<endl;
    root->right = createTree();
    return root;
}
void levelOrder(Tree* root){
    queue<Tree*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        Tree* front = q.front();
        q.pop();
        if(front==NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<front->data<<" ";
            if(front->left) q.push(front->left);
            if(front->right) q.push(front->right);
        }
    }   
}
void leftView(Tree * root,int lvl,vector<int>&ans){
    if(!root) return ;
   if(ans.size()==lvl) ans.push_back(root->data);
   leftView(root->left,lvl+1,ans);
   leftView(root->right,lvl+1,ans);

}
int main(){
    Tree * root = createTree();
    cout<<"Printing level order->"<<endl;
    levelOrder(root);
    cout<<endl;
    vector<int> ans;
    leftView(root,0,ans);
    for(auto it :ans) cout<<it<<" ";
}