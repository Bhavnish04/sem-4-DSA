#include<iostream>
using namespace std;

int main()
{
    int n, m;

    cout<<"Enter No. of Nodes: ";
    cin>>n;
    cout<<"Enter No. of Edges: ";
    cin>>m;

    int graph[n][n];

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            graph[i][j] = 0;


    for(int i = 1; i <= m; i++)
    {
        int source, dest;
        cout<<"Enter Source: ";
        cin>>source;
        cout<<"Enter Destination: ";
        cin>>dest;

        graph[source][dest] = 1;
        graph[dest][source] = 1;

    }


    cout<<endl;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
            cout<<graph[i][j];
        cout<<endl;
    }
        


    return 0;
}