#include "Graph.h"
#include <stdio.h>

void Graph::Cetak() {
    printf("Hao sebe\n");
    printf("Hao %c\n",this->simpangan[0][0]);
//    this->simpangan[1][2]='B';
}

Graph::Graph(int n, char **simpangan_)
{
    sp=0;
    this->nodes=n;
    adj=new vector<int>[n*n];
    simpangan = simpangan_;
}

void Graph::redef_graph(int n1)
{
    sp=0;
    nodes=n1;
    adj=new vector<int>[nodes*nodes];

}

void Graph::init()
{
    adj=new vector<int>[nodes*nodes];
}

void Graph::checkEdge()
{
    for(int i=0;i<nodes;i++)
    {
        for(int j=0;j<nodes;j++)
        {
            edge(i,j);
        }
    }
}

void Graph::add_edge(int org,int dest)
{
    adj[org].push_back(dest);
}

void Graph::edge(int i,int j)
{
    if(simpangan[i][j]!='X')
    {
        if(i>0 && simpangan[i-1][j]!='X')
        {
            add_edge((i*nodes)+j,(i-1)*nodes+j);
        }

        if(i<nodes-1 && simpangan[i+1][j]!='X')
        {
            add_edge((i*nodes)+j,(i+1)*nodes+j);
        }

        if(j>0 && simpangan[i][j-1]!='X')
        {
            add_edge((i*nodes)+j,(i*nodes)+(j-1));
        }

        if(j<nodes-1 && simpangan[i][j+1]!='X')
        {
            add_edge((i*nodes)+j,(i*nodes)+(j+1));
        }
    }
}

int Graph::minEdge(int a, int b)
{
    vector<bool> visited(nodes*nodes, false);
    vector<int> distance(nodes*nodes, 0);
    queue <int> Q;
    distance[a] = 0;
    Q.push(a);
    visited[a] = true;

    while (!Q.empty())
    {
        int x = Q.front();
        Q.pop();
        for (int i=0; i<adj[x].size(); i++)
        {
            if (visited[adj[x][i]])
                continue;

            distance[adj[x][i]] = distance[x] + 1;
            Q.push(adj[x][i]);
            visited[adj[x][i]] = 1;
        }
    }
    return distance[b];
}
