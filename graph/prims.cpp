#include<bits/stdc++.h>
using namespace std;
struct Edge{
    int src, dest, weight;
};
class Graph{
    //create graph
    vector<vector<pair<int, int>>>edges;//second for weight
    Graph(vector<Edge> &edges, int N){
        edges.resize(N);
        for(auto edge:edges){
            edges[edge.src].push_back({edge.dest, edge.weight});
            edges[edge.dest].push_back({edge.src, edge.weight});
        }
    }
};
int main(){
    vector<Edge>edges={
        {0, 1, 2}, {0, 2, 5}, {0, 3, 2},
        {1, 3 0}, {0, 1, 2}, {3, 2, 1},
        {4, 0, 3}, {2, 4, 6}, {0, 1, 2},
        {3, 4, 4}, {3, 5, 8}
    };


    return 0;
}
