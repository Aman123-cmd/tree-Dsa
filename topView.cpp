#include<iostream>
#include<vector>
#include<queue>
#include<map>
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
void topView(Tree* root){
    map<int,int> hdtoNodemap;
    queue<pair<Tree*,int>>q;
    q.push(make_pair(root,0));
    while(!q.empty()){
        pair<Tree *,int> temp = q.front();
        q.pop();
        Tree * frontnode = temp.first;
        int hd = temp.second;
        if(hdtoNodemap.find(hd)==hdtoNodemap.end()){
            hdtoNodemap[hd]=frontnode->data;
        }
        if(frontnode->left) q.push(make_pair(frontnode->left,hd-1));
        if(frontnode->right) q.push(make_pair(frontnode->right,hd+1));
    }
    for(auto it:hdtoNodemap) {
        cout<<it.second<<" ";
    }
}
int main(){
    Tree * root = createTree();
    levelOrder(root);
    cout<<endl;
    topView(root);
}
