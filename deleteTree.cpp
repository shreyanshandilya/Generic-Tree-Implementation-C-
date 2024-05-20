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
    cout << "Enter value of root node : ";
    int rootValue;
    cin >> rootValue;
    TreeNode<int>* root = new TreeNode<int>(rootValue);

    queue<TreeNode<int>*> q;
    q.push(root);

    while(!q.empty()) {
        TreeNode<int>* f = q.front();
        q.pop();

        int n;
        cout << "Enter number of children of " << f->data << " : ";
        cin >> n;

        for(int i=0; i<n; i++) {
            cout << "Enter value of " << i+1 << " child of " << f->data << " : ";
            int value;
            cin >> value;
            TreeNode<int>* temp = new TreeNode<int>(value);
            f->children.push_back(temp);
            q.push(temp);
        }
    }

    return root;
}

void deleteTree(TreeNode<int>* root) {
    if(root==NULL) return;
    for(auto it: root->children) deleteTree(it);
    delete root;
}

int main() {
    TreeNode<int>* root = takeInput();
    deleteTree(root);
    return 0;
}