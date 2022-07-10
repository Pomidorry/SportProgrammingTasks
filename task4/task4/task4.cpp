
#include <iostream>
using namespace std;
struct binaryTree {
    int key;
    binaryTree* left, * right;
    binaryTree() {
        cin >> key;
        this->key = key;
        this->left = nullptr;
        this->right = nullptr;
    }
};
bool Identical(binaryTree* a, binaryTree* b)
{
    if (a == nullptr && b == nullptr) {
        return true;
    }

    return (a && b) && (a->key == b->key) &&
        Identical(a->left, a->left) &&
        Identical(b->right, b->right);
}
int main()
{
    binaryTree* x = nullptr;
    x = new binaryTree();
    x->left = new binaryTree();
    x->right = new binaryTree();
    x->left->left = new binaryTree();
    x->left->right = new binaryTree();
    x->right->left = new binaryTree();
    x->right->right = new binaryTree();
    binaryTree* y = nullptr;
    y = new binaryTree();
    y->left = new binaryTree();
    y->right = new binaryTree();
    y->left->left = new binaryTree();
    y->left->right = new binaryTree();
    y->right->left = new binaryTree();
    y->right->right = new binaryTree();
    if (Identical(x, y)) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
}

