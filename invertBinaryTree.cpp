#include<iostream>
#include<queue>
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
 Tree * invert(Tree* root){
    if(!root) return root;
    Tree * temp = root->left;
    root->left = root->right;
    root->right = temp;
    invert(root->left);
    invert(root->right);
    return root;
 }
 int main(){
    Tree * root = createTree();
    levelOrder(root);
    invert(root);
    cout<<"After inverting binary tree->"<<endl;
    levelOrder(root);
 }