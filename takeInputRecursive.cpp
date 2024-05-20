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

TreeNode<int>* takeInput() {

    cout << "Enter value : ";

    int rootValue;
    cin >> rootValue;

    TreeNode<int>* root = new TreeNode<int>(rootValue);

    int children;

    cout << "Enter number of children of " << rootValue << " : ";
    cin >> children;

    for(int i=0; i<children; i++) {
        TreeNode<int>* child = takeInput();
        root->children.push_back(child);
    }

    return root;
}

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
    TreeNode<int>* root = takeInput();
    printTree2(root);
    return 0;
}