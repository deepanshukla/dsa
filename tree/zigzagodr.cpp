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

vector<vector<int>>zigzagodr(treenode* root){
    vector<vector<int>>result;
    queue<treenode*>q;
    q.push(root);
    bool ltor = true;
    while(!q.empty()){
        int size = q.size();
        vector<int>row(size);
        for (int i = 0; i < size; i++){
            treenode *temp = q.front();
            q.pop();
            int index = (ltor) ? i : (size - i -1);
            row[index] = temp->val;
            if (temp->left){
                q.push(temp->left);
            } 
            if (temp->right){
                q.push(temp->right);
            }
        }
        ltor = !ltor;
        result.push_back(row);
    }
    return result;
}
int main(){
    treenode *root = new treenode(1);
    root->left = new treenode(2);
    root->left->left = new treenode(4);
    root->left->right = new treenode(5);
    root->right = new treenode(3);
    root->right->left = new treenode(6);
    vector<vector<int>>zzorder;
    zzorder = zigzagodr(root);
    for (auto &&i : zzorder){
        for (auto &&in : i){
            cout<<in<<" ";
        }
        cout<<endl;
    }   
}
