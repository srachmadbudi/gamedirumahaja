#ifndef GRAPH_H
#define GRAPH_H

#include<bits/stdc++.h>

using namespace std;

class Graph
{
public:
    int nodes;
    vector<int>*adj;
    int sp;
    int lp;
    int mod;
    char** simpangan;
    char*** simpangan_ptr;
    Graph(int, char***);

    void Cetak();
    void redef_graph(int n1);
    void init();
    void checkEdge();
    void add_edge(int org,int dest);
    void edge(int i,int j);
    int minEdge(int a, int b);

};

#endif