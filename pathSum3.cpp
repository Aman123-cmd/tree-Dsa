#include<iostream>
#include<queue>
#include<limits.h>
using namespace std;
int ans = 0;
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
void helper(Tree * root,int targetSum){
    if(!root) return ;
    if(targetSum==root->data){
        ans++;
    }
    helper(root->left,targetSum-root->data);
    helper(root->right,targetSum-root->data);
}
int pathSum(Tree * root,int targetSum){
    if(root){
        helper(root,targetSum);
        pathSum(root->left,targetSum);
        pathSum(root->right,targetSum);
    }
    return ans;
}
int main(){
    Tree * root = createTree();
    cout<<"printing level order->"<<endl;
    cout<<"Total no of paths ->"<<pathSum(root,8);
}