#include <bits/stdc++.h>
using namespace std;

class treenode{
    public:
    int val;
    treenode* left,*right;
    treenode(int x){
        val = x;
        left = nullptr;
        right = nullptr;
    }
};
bool isleaf(treenode* root ){
    if (!root->left && !root->right)return true;
    return false;
}
void leftside(treenode* root,vector<int>&result){
    treenode* cur = root->left;
    while (cur){
        if(!isleaf(cur))result.push_back(cur->val);
        if(cur->left != nullptr)cur=cur->left;
        else cur = cur->right;
    }
}
void rightside(treenode* root,vector<int>&result){
    treenode* cur = root->right;
    stack<int>st;
    while (cur){
        if(!isleaf(cur))st.push(cur->val);
        if(cur->right != nullptr)cur=cur->right;
        else cur = cur->left;
    }
    while (!st.empty()){
        result.push_back(st.top());
        st.pop();
    }
}
void addleaves(treenode* root,vector<int>&result){
    if(!root)return;
    if(isleaf(root))result.push_back(root->val);
    addleaves(root->left,result);
    addleaves(root->right,result);
}
vector<int> boundary(treenode *root){
    vector<int>res;
    if(!root)return res;
    if(!isleaf(root))res.push_back(root->val);
    leftside(root,res);
    addleaves(root,res);
    rightside(root,res);
    return res;
}
int main(){
    treenode *root = new treenode(1);
    root->left = new treenode(2);
    root->left->left = new treenode(3);
    root->left->left->right = new treenode(4);
    root->left->left->right->left = new treenode(5);
    root->left->left->right->right = new treenode(6);
    root->right = new treenode(7);
    root->right->right = new treenode(8);
    root->right->right->left = new treenode(9);
    root->right->right->left->left = new treenode(10);
    root->right->right->left->right = new treenode(11);
    vector<int>preorder;
    preorder = boundary(root);
    // leaf(root,preorder);
    for (auto &&i : preorder){
        cout<<i<<" ";
    }
}