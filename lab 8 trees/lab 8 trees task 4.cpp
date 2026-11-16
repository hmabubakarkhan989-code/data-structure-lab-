#include <iostream>
#include <algorithm>
using namespace std;

class Node {
public:
    int token;
    Node* left;
    Node* right;
    int height;

    Node(int t) {
        token = t;
        left = NULL;
        right = NULL;
        height = 1;
    }
};

int getHeight(Node* root) {
    if (root == NULL) {
        return 0;
    }

    return root->height;
}

int getBalance(Node* root) {
    if (root == NULL) {
        return 0;
    }

    return getHeight(root->left) - getHeight(root->right);
}

Node* rightRotation(Node* y) {

    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = 1 + max(getHeight(y->left), getHeight(y->right));
    x->height = 1 + max(getHeight(x->left), getHeight(x->right));

    return x;
}

Node* leftRotation(Node* x) {

    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = 1 + max(getHeight(x->left), getHeight(x->right));
    y->height = 1 + max(getHeight(y->left), getHeight(y->right));

    return y;
}

Node* insert(Node* root, int token) {

    if (root == NULL) {
        return new Node(token);
    }

    if (token < root->token) {
        root->left = insert(root->left, token);
    }
    else if (token > root->token) {
        root->right = insert(root->right, token);
    }
    else {
        return root;
    }

    root->height = 1 + max(getHeight(root->left), getHeight(root->right));

    int balance = getBalance(root);

    if (balance > 1 && token < root->left->token) {
        return rightRotation(root);
    }

    if (balance < -1 && token > root->right->token) {
        return leftRotation(root);
    }

    if (balance > 1 && token > root->left->token) {
        root->left = leftRotation(root->left);
        return rightRotation(root);
    }

    if (balance < -1 && token < root->right->token) {
        root->right = rightRotation(root->right);
        return leftRotation(root);
    }

    return root;
}

void Inorder(Node* root) {

    if (root == NULL) {
        return;
    }

    Inorder(root->left);
    cout << root->token << " ";
    Inorder(root->right);
}

void displayTree(Node* root, int space = 0) {

    if (root == NULL) {
        return;
    }

    space += 5;

    displayTree(root->right, space);

    cout << endl;

    for (int i = 5; i < space; i++) {
        cout << " ";
    }

    cout << root->token << endl;

    displayTree(root->left, space);
}

int main() {

    Node* root = NULL;

    int tokens[] = {15, 25, 35, 45, 55, 65, 75};

    for (int i = 0; i < 7; i++) {
        root = insert(root, tokens[i]);
    }

    cout << "Inorder Traversal: ";
    inorder(root)
    Inorder(root);

    cout << endl;

    cout << "\nFinal Balanced AVL Tree:" << endl;
    displayTree(root);

    return 0;
}

