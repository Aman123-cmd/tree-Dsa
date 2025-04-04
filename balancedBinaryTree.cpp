#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
class Tree{
public:
int data;
Tree*left;
Tree *right;
Tree(int data):data(data),left(NULL),right(NULL){};

};
Tree* createTree(){
    
    int data;
    cout<<"Enter the value of the node->";
    cin>>data;
    if(data==-1) return NULL;

    Tree *root = new Tree(data);
  
   cout<<"Enter the left value of the node:"<<root->data<<endl;
   root->left = createTree();
   cout<<"enter the right value of the node:"<<root->data<<endl;
   root->right = createTree();
   return root;
}
void levelOrder(Tree*root){
    queue<Tree*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        Tree* front = q.front();
        q.pop();
       if(front==NULL){
           cout<<endl;
           if(!q.empty()) q.push(NULL);
       }
       else{
  
        cout<<front->data<<" ";
        if(front->left) q.push(front->left);
        if(front->right) q.push(front->right);
       }

       
    }

}
int height(Tree * root){
    if(!root) return 0;
    int leftSubTree = height(root->left);
    int rightSubTree = height(root->right);
    int ans = max(leftSubTree,rightSubTree)+1;
    return ans;
}
bool isBalanced(Tree* root){
    if(!root) return true;
    int lh = height(root->left);
    int rh = height(root->right);
    bool diff = abs(lh-rh)<=1;
    bool la = isBalanced(root->left);
    bool ra = isBalanced(root->right);
    return (la&& ra && diff);
}
int main(){
    Tree * root = createTree();
    levelOrder(root);
    bool ans = isBalanced(root);
    if(ans) cout<<"Balanced Binary tree";
    else cout<<"not a Balanced binary tree";

}