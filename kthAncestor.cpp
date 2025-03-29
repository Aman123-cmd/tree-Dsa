 #include<iostream>
 #include<queue>
 #include<vector>
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
Tree* KthAncestor(Tree* root,int &k,int data,int& ans){
    if(!root) return NULL ;
 
     if(root->data==data) return root;
    Tree * leftAns = KthAncestor(root->left,k,data,ans);
    Tree * rightAns = KthAncestor(root->right,k,data,ans);
    if(!leftAns && !rightAns) return NULL;
    k--;
    if(k==0 ) ans = root->data;
    if(leftAns && !rightAns) return leftAns;
    else if(!leftAns && rightAns) return rightAns;
    else return root;
}
int main(){
    Tree *root = createTree();
    levelOrder(root);
    int ans = -1;
    int k = 4;
    KthAncestor(root,k,8,ans);
    cout<<"Kth ancestor is ->"<<ans;

}