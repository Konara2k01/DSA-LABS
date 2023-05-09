#include <iostream>
using namespace std;

struct node {
    int key;
    struct node *left= nullptr;
    struct node* right= nullptr;
};

// Inorder traversal
void traverseInOrder(struct node* root) {

    if (root == nullptr) return;
    traverseInOrder(root->left);
    cout<<root->key<<" ";
    traverseInOrder(root->right);

}

// Insert a node
struct node* insertNode(struct node* root, int key) {
    if(root == nullptr){
        root = new node;
        root->key=key;
    }

    else{
        if(root->key>key){
            root->left=insertNode(root->left,key);
        }
        else
            root->right=insertNode(root->right,key);
    }
    return root;
}

// Deleting a node
struct node* deleteNode(struct node* root, int key) {

    if(key>root->key) root->right = deleteNode(root->right,key);

    else if(key<root->key) root->left = deleteNode(root->left,key);

    else{
        // leaf node
        if( root->left== nullptr && root->right== nullptr ){
            delete root;
            return nullptr;
        }
            // node has no right child
        else if(root->right== nullptr) {
            auto newLeft = root->left;
            delete root;
            return newLeft;
        }
            // node has no left child
        else if(root->left== nullptr) {
            auto newRight = root->right;
            delete root;
            return newRight;
        }
            // node has both left & right child
        else{

            // find min in right tree
            auto rightMin = root->right;
            while(rightMin->left!= nullptr)
                rightMin=rightMin->left;
            // assign min value to current node and delete rightMinValue node
            root->key = rightMin->key;
            root->right = deleteNode(root->right,rightMin->key);
        }
    }
    return root;
}


// Driver code
int main() {
    struct node *root = NULL;

    int operation;
    int operand;
    cin >> operation;

    while (operation != -1) {
        switch(operation) {
            case 1: // insert
                cin >> operand;
                root = insertNode(root, operand);
                cin >> operation;
                break;
            case 2: // delete
                cin >> operand;
                root = deleteNode(root, operand);
                cin >> operation;
                break;
            default:
                cout << "Invalid Operator!\n";
                return 0;
        }
    }

    traverseInOrder(root);
}