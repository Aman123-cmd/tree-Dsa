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
int diameter(Tree * root){
    if(!root) return 0;
    int option1 = diameter(root->left);
    int option2 = diameter(root->right);
    int option3 = height(root->left)+height(root->right);
    return max(option1,max(option2,option3));
}
int main(){
    Tree* root = createTree();
    levelOrder(root);
    int ans = diameter(root);
    cout<<"ans-> "<<ans;
}