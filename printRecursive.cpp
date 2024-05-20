#include<bits/stdc++.h>
using namespace std;

template<typename T>
class TreeNode {
    public:
        T data;
        vector<TreeNode<T>*> children;

        TreeNode(T data) {
            this->data = data;
        }
};

//Method 1
void printTree(TreeNode<int>* root) {
    cout << root->data << endl;
    for(auto it: root->children) {
        printTree(it);
    }
}

//Method2
void printTree2(TreeNode<int>* root) {
    cout << root->data << " : ";
    for(auto it: root->children) {
        cout << it->data << " ";
    }
    cout << endl;
    for(auto it: root->children) {
        printTree2(it);
    }
}

int main() {
    TreeNode<int>* root = new TreeNode<int>(1);
    TreeNode<int>* child1 = new TreeNode<int>(2);
    TreeNode<int>* child2 = new TreeNode<int>(3);
    root->children.push_back(child1);
    root->children.push_back(child2);
    cout << "Method 1" << endl;
    printTree(root);
    cout << "Method 2" << endl;
    printTree2(root);
    return 0;
}