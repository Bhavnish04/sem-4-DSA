#include<iostream>
using namespace std;

struct Node
{
    int airport_no;
    struct Node* next;
};

void add_route(struct Node *head, int dest)
{
    Node *new_node = new Node();
    new_node->airport_no = dest;
    

    Node *ptr = head;

    while(ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = new_node;
    new_node->next = NULL;

}

void print_all_paths(struct Node **heads, int nodes)
{
    struct Node *ptr;

    for(int i = 0; i < nodes; i++)
    {
        ptr = heads[i];

        while(ptr->next != NULL)
        {
            cout<<ptr->airport_no<<" --> ";
            ptr = ptr->next;
        }
        cout<<ptr->airport_no<<endl;
    }
}


int main()
{
    int n, m;
    cout<<"Enter No. of Nodes: ";
    cin>>n;
    cout<<"Enter No. of Edges: ";
    cin>>m;

    struct Node *heads[n];

    for(int i = 0; i < n; i++)
    {
        heads[i] = new Node();
        heads[i]->airport_no = i;
        heads[i]->next = NULL;
    }

    for(int i = 0; i < m; i++)
    {
        int source, dest;
        cout<<"Enter Source: ";
        cin>>source;
        cout<<"Enter Destination: ";
        cin>>dest;

        add_route(heads[source], dest);
        add_route(heads[dest], source);
    }

    print_all_paths(heads, n);

    return 0;
}