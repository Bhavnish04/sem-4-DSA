#include<iostream>
#include<vector>
using namespace std;

const int N = 5;
vector<int> graph[N];
bool visited[N];

void dfs(int vertex)
{
    if(visited[vertex]) return;

    visited[vertex] = true;
    cout<<"Vertex: "<<vertex<<" ";

    for(int child : graph[vertex])
    {
        dfs(child);
    }
}

int main()
{
    int n, m;
    cout<<"Enter Nodes and Edges: ";
    cin>>n>>m;

    for(int i=0; i < m; i++)
    {
        int source, dest;
        cin>>source>>dest;

        graph[source].push_back(dest);
        graph[dest].push_back(source);
    }

    dfs(0);


    return 0;
}