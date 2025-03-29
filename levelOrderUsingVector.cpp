#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>

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
vector<vector<int>> levelOrder(Tree * root){
    vector<vector<int>> ans;
    if(!root) return ans;
    queue<Tree*> q;
    q.push(root);
    while(!q.empty()){
        vector<int> temp;
        int t = q.size();
        for(int i = 0;i<t;i++){
            Tree * front = q.front();
            q.pop();
            temp.push_back(front->data);
            if(front->left) q.push(front->left);
            if(front->right) q.push(front->right);
        }
        ans.push_back(temp);
        reverse(ans.begin(),ans.end());
    }
    return ans;
}
int main(){
    Tree* root =createTree();
    vector<vector<int>> ans = levelOrder(root);
    for(auto row:ans){
        for(auto col:row){
            cout<<col<<" ";
        }
        cout<<endl;

    }
}