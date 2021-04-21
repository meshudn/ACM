// C++ program to demonstrate insert operation in binary
// search tree.
#include <bits/stdc++.h>
using namespace std;

struct node {
    int key;
    int c = 0;
    struct node *left, *right;
};

// A utility function to create a new BST node
struct node* newNode(int item)
{
    struct node* temp
        = (struct node*)malloc(sizeof(struct node));
    temp->key = item;
    temp->c = 1;
    temp->left = temp->right = NULL;
    return temp;
}

// A utility function to insert a new node with given key in
// BST
struct node* insert(struct node* node, int key, int& ma)
{
    // If the tree is empty, return a new node
    if (node == NULL) {
        if (ma == 0)
            ma = 1;

        return newNode(key);
    }

    // Otherwise, recur down the tree
    if (key < node->key)
        node->left = insert(node->left, key, ma);
    else if (key > node->key)
        node->right = insert(node->right, key, ma);
    else
        node->c++;

    // find the max count
    ma = max(ma, node->c);

    // return the (unchanged) node pointer
    return node;
}

// A utility function to do inorder traversal of BST
void inorder(struct node* root, int s)
{
    if (root != NULL) {
        inorder(root->left, s);

        if (root->c > (s / 2))
            printf("%d \n", root->key);

        inorder(root->right, s);
    }
}
// Driver Code
int main()
{
    int a[] = { 1, 3, 3, 3, 2 };
    int size = (sizeof(a)) / sizeof(a[0]);

    struct node* root = NULL;
    int ma = 0;

    for (int i = 0; i < size; i++) {
        root = insert(root, a[i], ma);
    }

    // Function call
    if (ma > (size / 2))
        inorder(root, size);
    else
        cout << "No majority element\n";
    return 0;
}
