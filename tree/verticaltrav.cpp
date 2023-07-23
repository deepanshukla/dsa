#include <bits/stdc++.h>
using namespace std;
class treenode{
public:
    int val;
    treenode* left,*right;
    explicit treenode(int x){
        val = x;
        left = nullptr;
        right = nullptr;
    }
};
vector<int> vertical(treenode* root){
    map<int,map<int,multiset<int> > >m;
    queue<pair<treenode*,pair<int,int>>>q;
    q.push({root,{0,0}});
    while (!q.empty()){
        pair<treenode*,pair<int,int>>temp = q.front();
        q.pop();
        int x = temp.second.first;
        int y = temp.second.second;
        m[x][y].insert(temp.first->val);
        if(temp.first->left){
            q.push({temp.first->left,{x-1,y+1}});
        }
        if(temp.first->right){
            q.push({temp.first->right,{x+1,y+1}});
        }
    }
    vector<int>v;
    for (auto i : m ) {
        for (auto ind: i.second) {
            for (auto f : ind.second) {
                v.push_back(f);
            }
        }
    }
    return v;
}
int main(){
    auto *root = new treenode(1);
    root->left = new treenode(2);
    root->right = new treenode(3);
    root->left->left = new treenode(4);
    root->left->right = new treenode(5);
    root->right->left = new treenode(6);
    root->right->right = new treenode(7);
    root->right->left->right = new treenode(8);
    root->right->right->right = new treenode(9);
    vector<int>result = vertical(root);
    for (auto i : result) {
        cout<<i<<" ";
    }
    return 0;
}
