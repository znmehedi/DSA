#include<bits/stdc++.h>
using namespace std;
struct Edge{
    int src, dest;
};
class Graph{
public:
    vector<vector<int>>adjlist;
    Graph(vector<Edge> &edges, int N){
        adjlist.resize(N+1);

        for(auto edge:edges){
            adjlist[edge.src].push_back(edge.dest);
           // adjlist[edge.dest].push_back(edge.src);
        }
    }
};
class DisjointSet{
    unordered_map<int, int>parent;
public:
    void makeSet(int N){
        for(int i=1;i<=N;i++)
            parent[i]=i;
    }
    int Find(int i){
        return (parent[i]==i)?i:Find(parent[i]);
    }
    void Union(int x, int y){
        parent[Find(x)]=Find(y);
    }

};
bool FindCycle(Graph &graph, int N);

int main(){
    vector<Edge>edges={
        {1, 2}, {1, 7}, {1, 8},
        {2, 3}, {2, 6}, {8, 9}, {8, 12},
        {3, 4}, {3, 5}, {9, 10}, {9, 11}
        // ,{12, 11}

    };
    int N=12;
    Graph graph(edges, N);
    FindCycle(graph, N)?cout<<"Cycle Found"<<endl:cout<<"Cycle not found"<<endl;
    return 0;
}
bool FindCycle(Graph &graph, int N){
    DisjointSet ds;
    ds.makeSet(N);

    int x, y;
    for(int i=1;i<=N;i++){
        for(auto u:graph.adjlist[i]){
            x=ds.Find(i);
            y=ds.Find(u);

            if(x==y)
                return true;
            else ds.Union(x, y);
        }
    }
    return false;
}
