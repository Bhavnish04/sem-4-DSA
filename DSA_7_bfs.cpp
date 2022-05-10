#include<bits/stdc++.h>
using namespace std;
const int N = 5;

vector<int> graph[N];

int visited[N];
int level[N];

void bfs(int vertex)
{
    queue<int> que;
    que.push(vertex);
    visited[vertex] = 1;

    while(!que.empty())
    {   
        int cur_vertex = que.front();
        cout<<cur_vertex<<" ";
        que.pop();
        for(int child : graph[cur_vertex])
        {
            if(!visited[child])
            {
                que.push(child);
                visited[child] = 1;
                level[child] = level[cur_vertex] + 1;
            }
        }
    }
}

int main()
{
    int m;
    cout<<"Enter Number of Edges: ";
    cin>>m;

    cout<<"Enter Source and Destination: "<<endl;

    for(int i = 0; i < m; i++)
    {
        int source, dest;
        cin>>source>>dest;
        graph[source].push_back(dest);
        graph[dest].push_back(source);
    }

    bfs(0);

    return 0;
}