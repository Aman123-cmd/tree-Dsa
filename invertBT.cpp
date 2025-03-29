#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class Node{
public:
int data;
Node *left;
Node *right;
Node(int data):data(data),left(NULL),right(NULL){};

};
Node *createTree(){
    
    int data;
    cout<<"Enter the value of the Node->";
    cin>>data;
    if(data==-1) return NULL;
    Node * root = new Node(data);
    cout<<"Enter the left value of the node->"<<root->data<<endl;
    root->left = createTree();
    cout<<"Enter the right value of the node->"<<root->data<<endl;
    root->right = createTree();
    return root;

}
void leveleOrder(Node * root){
    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        Node * front = q.front();
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
Node * invertBT(Node * root){
    if(!root){
        return root;
    }
    Node * temp = root->left;
    root->left = root->right;
    root->right = temp;
    invertBT(root->left);
    invertBT(root->right);
    return root;
}
int main(){
    Node * root = createTree();
    leveleOrder(root);
    root =  invertBT(root);
    leveleOrder(root);
}