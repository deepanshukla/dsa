#include <bits/stdc++.h>
using namespace std;

class treenode{
    public:
    int val;
    treenode* left,*right;
    treenode(int x){
        val = x;
        left = NULL;
        right = NULL;
    }
};

vector<int>levelorder(treenode* root){
    vector<int>v;
    queue<treenode*>q;
    q.push(root);
    while (!q.empty()){
        treenode* temp = q.front();
        v.push_back(temp->val);
        q.pop();
        if(temp->left){
            q.push(temp->left);
        }
        if(temp->right){
            q.push(temp->right);
        }
    }
    return v;
}
int main(){
    treenode *root = new treenode(1);
    root->left = new treenode(2);
    root->right = new treenode(3);
    vector<int>lvlorder;
    lvlorder = levelorder(root);
    for (auto &&i : lvlorder)
    {
        cout<<i<<" ";
    }   
}
