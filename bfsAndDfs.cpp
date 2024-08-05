#include<iostream>
#include<queue>
#include<stack>
using namespace std;

class Node {
    public:
    int data;
    Node *left;
    Node *right;
    Node(int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

void bfs_iterative(Node* root) {
    if (root == NULL) return;
    queue<Node*> q;
    q.push(root);

    while (q.empty() == false) {
        Node* node = q.front();
        cout << node->data << " ";
        q.pop();

        // enqueue
        if (node->left != NULL) {
            q.push(node->left);
        }

        if (node->right != NULL) {
            q.push(node->right);
        }
    }
}

void dfs_iterative(Node* root) {
    if (root == NULL) return;
    stack<Node*> s;
    s.push(root);

    while (!s.empty()) {
        Node* node = s.top();
        cout << node->data << " ";
        s.pop();
        if (node->right != NULL) {
            s.push(node->right);
        }
        if (node->left != NULL) {
            s.push(node->left);
        }
    }
}

void dfs_recursive(Node* node)
{
    if(node==NULL)return ; 
    cout<<node->data<<" ";
    dfs_recursive(node->left);
    dfs_recursive(node->right);
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    bfs_iterative(root);
    cout<<endl;
    dfs_iterative(root);
    cout<<endl; 
    dfs_recursive(root);

}
