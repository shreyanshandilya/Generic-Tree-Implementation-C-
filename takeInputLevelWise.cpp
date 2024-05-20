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

TreeNode<int>* takeInputLevelWise() {

    int rootData;
    cin >> rootData;

    TreeNode<int>* root = new TreeNode<int>(rootData);

    queue<TreeNode<int>*> q;
    q.push(root);

    while(!q.empty()) {
        TreeNode<int>* f = q.front();
        q.pop();

        cout << "Enter number of children of " << f->data << " : ";
        int n;
        cin >> n;
        for(int i=0; i<n; i++) {
            int v;
            cout << "Enter value of child " << i+1 << " of " << f->data << " : ";
            cin >> v;
            TreeNode<int>* newNode = new TreeNode<int>(v);
            f->children.push_back(newNode); 
            q.push(newNode);
        }
    }

    return root;
}

void printTree2(TreeNode<int>* root) {
    cout << root->data << " : ";
    for(auto it: root->children) cout << it->data << " ";
    cout << endl;
    for(auto it: root->children) {
        printTree2(it);
    }
}

int main() {
    TreeNode<int>* root = takeInputLevelWise();
    printTree2(root);
    return 0;
}