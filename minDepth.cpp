#include<iostream>
#include<queue>
#include<limits.h>
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
int height(Tree* root){
    if(!root  ) return 0;
    return max(height(root->left),height(root->right))+1;
}
int minDepth(Tree* root){
    if(!root)return INT_MAX;

    int lh = height(root->left);
    int rh = height(root->right);
    return min (lh,rh);

}
int minHeight(Tree* root){
    return  minDepth(root)+1;
}
int main(){
    Tree * root = createTree();
    cout<<" min depth is ->"<<minHeight(root);
}