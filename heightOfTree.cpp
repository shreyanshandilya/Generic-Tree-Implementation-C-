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

void levelOrderPrint(TreeNode<int>* root) {
    queue<TreeNode<int>*> q;
    q.push(root);

    while(!q.empty()) {

        TreeNode<int>* f = q.front();
        q.pop();
        
        cout << f->data << " : ";
        for(int i=0; i<f->children.size(); i++) {
            cout << f->children[i]->data << " ";
            q.push(f->children[i]);
        }
        cout << endl;

    }
}

int heightOfTree(TreeNode<int>* root) {
    if(root==NULL) return 0;

    int answer = 1;
    int temp = 0;

    for(auto it: root->children) {
        temp = max(temp, heightOfTree(it));
    }
    answer += temp; 

    return answer;
}

int main() {
    TreeNode<int>* root = takeInput();
    levelOrderPrint(root);
    cout << heightOfTree(root);
    return 0;
}