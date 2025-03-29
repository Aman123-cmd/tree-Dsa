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
void leftBoundary(Tree * root){
    if(!root) return ;
    if(root->left==NULL && root->right==NULL){
        return ;
    }
    cout<<root->data<<" ";
    if(root->left!=NULL) leftBoundary(root->left);
    else leftBoundary(root->right);
}
void rightBoundary(Tree * root){
    if(!root) return ;
    if(root->left==NULL && root->right==NULL) return ;
   
    if(root->right!=NULL) rightBoundary(root->right);
    else rightBoundary(root->left);
    cout<<root->data<<" ";
}
void leafBoundary(Tree * root){
    if(!root) return;
    if(root->left==NULL && root->right==NULL) {
        cout<<root->data<<" ";
        return;
    }
    leafBoundary(root->left);
    leafBoundary(root->right);


}
void boundaryTraversal(Tree * root){
    if(!root) return ;
    leftBoundary(root->left);
    leafBoundary(root->left);
    leafBoundary(root->right);
    rightBoundary(root->left);
}
int main(){
    Tree * root = createTree();
    cout<<"printing level order:->"<<endl;
    levelOrder(root);
    cout<<"printinf boundary traversal:->"<<endl;
    boundaryTraversal(root);
}