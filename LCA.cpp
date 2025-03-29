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
Tree * LCA(Tree* root,Tree* p,Tree* q){
    if(!root) return NULL;
    if(root->data==p->data) return p;
    if(root->data==q->data) return q;
    Tree* leftAns = LCA(root->left,p,q);
    Tree* rightAns = LCA(root->right,p,q);
    if(!leftAns && !rightAns) return NULL;
    else if(leftAns && !rightAns) return leftAns;
    else if (!leftAns && rightAns) return rightAns;
     return root;
}
int main(){
    Tree* root = createTree();
    levelOrder(root);
    Tree* p = new Tree(40);
    Tree *q = new Tree(65);
    Tree* ans = LCA(root,p,q);
    cout<<"Ans = "<<ans->data;
}