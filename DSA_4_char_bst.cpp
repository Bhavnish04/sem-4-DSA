#include<iostream>
#include<string.h>
using namespace std;

class Node
{   
    public:
    Node *left = nullptr;
    Node *right = nullptr;
    string data;

    Node(string name)
    {
        data = name;
    }
};

void insert_in_tree(Node *root, string name)
{
    Node *new_Node = new Node(name);

    bool small = 0;

    int ch = 0;
    while(name[ch] != '\0')
    {
        if(name[ch] < root->data[ch])
        {
            small = 1;
            break;
        }
        else if(name[ch] > root->data[ch])
        {
            small = 0;
            break;
        }
        else
            ch++;
    }

    if(small)
    {
        if(root->left == nullptr)
            root->left = new_Node;
        else
            insert_in_tree(root->left, name);
    }
    else
    {
        if(root->right == nullptr)
            root->right = new_Node;
        else
            insert_in_tree(root->right, name);
    }
}

void inorder_traversal(Node *root)
{
    if(root == NULL)
        return;

    inorder_traversal(root->left);
    cout<<root->data<<"   ";
    inorder_traversal(root->right);
}

int main()
{
    Node *root = new Node("harshal");

    bool toggle = 1;

    while(toggle)
    {
        string name;
        cout<<"Enter Name: ";
        cin>>name;

        insert_in_tree(root, name);

        cout<<"Do You Want to Continue? 1/0: ";
        cin>>toggle;
    }

    inorder_traversal(root);

    return 0;
}