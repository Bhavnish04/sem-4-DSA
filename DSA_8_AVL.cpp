#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int data;
    Node *left;
    Node *right;
    int height;

    Node(int key)
    {
        data = key;
        left = NULL;
        right = NULL;
        height = 1;
    }
};

int getHeight(Node *node)
{
    if(node == NULL)
        return 0;
    
    return node->height;
}

int balanceFactor(Node *node)
{
    if(node == NULL)
        return 0;

    return (getHeight(node->left) - getHeight(node->right));
}

Node * rightRotation(Node * y)
{
    Node * x = y->left;
    Node * T2 = x->right;

    // Perform Rotation
    x->right = y;
    y->left = T2;

    // Update Height
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

    //Return New Root
    return x;
}

Node * leftRotation(Node *x)
{
    Node *y = x->right;
    Node *T2 = y->left;

    // Perform Rotation
    y->left = x;
    x->right = T2;

    // Update Height
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

    // Return New Root
    return y;
}


struct Node* insert(Node *node, int key)
{
    if(node == NULL)
    {
        Node *new_node = new Node(key);
        return new_node;
    }

    if(key < node->data)
        node->left = insert(node->left, key);
    else if(key > node->data)
        node->right = insert(node->right, key);
    else // Duplicate keys not allowed in BST
        return node;

    node->height = 1 + max(getHeight(node->left), getHeight(node->right));

    int bf = balanceFactor(node);

    if(bf > 1 && key < node->left->data) // Left Left
        return rightRotation(node);

    if(bf > 1 && key > node->left->data) // Left Right
    {
        node->left = leftRotation(node->left);
        return rightRotation(node);
    }

    if(bf < -1 && key > node->right->data) // Right Right
        return leftRotation(node);

    if(bf < -1 && key < node->right->data) // Right Left
    {
        node->right = rightRotation(node->right);
        return leftRotation(node);
    }

    return node;
}

void preorder(Node * root)
{
    if(root == NULL)
        return;
    cout<<root->data<<" "; 
    preorder(root->left);
    preorder(root->right);
    // cout<<root->data<<" ";
}


int main()
{
    Node *root = NULL;

    root = insert(root, 63);
    root = insert(root, 9);
    root = insert(root, 19);
    root = insert(root, 27);
    root = insert(root, 18);
    root = insert(root, 108);
    root = insert(root, 99);
    root = insert(root, 81);
    

    cout<<"Root is: "<<root->data<<endl;

    preorder(root);

    return 0;
}