#include<bits/stdc++.h>
using namespace std;
struct Edge{
    int src, dest, weight;
};
bool cmp(struct Edge a, struct Edge b);
vector<pair<int, int>> krusKal_s_Algo(vector<Edge> &edges, int N);
void makeSet(vector<int> &parent, int N);
int Find(vector<int> &parent, int i);
void Union(vector<int> &parent, int x, int y);
int main(){
    vector<Edge>edges={
        {0, 1, 7}, {0, 3, 5}, {1, 2, 8}, {1, 4, 7}, {1, 3, 9},
        {2, 4, 5}, {3, 4, 15}, {3, 5, 6}, {4, 5, 8}, {4, 6, 9},
        {5, 6, 11}
        };


    vector<pair<int, int>>mst=krusKal_s_Algo(edges, 7);

    cout<<"MST is="<<endl<<endl;
    for(auto i:mst)
        cout<<i.first<< " " <<i.second<<endl;
    return 0;
}
vector<pair<int, int>> krusKal_s_Algo(vector<Edge> &edges, int N){
    //sort edges
    sort(edges.begin(), edges.end(), cmp);
//    for(auto i:edges)
//        cout<<i.src<<" "<<i.dest<<" "<<i.weight<<endl;
    vector<pair<int, int>>result;
    //make disjoint-set
    vector<int>parent;
    makeSet(parent, N);
    int x, y;
    for(auto i:edges){
        x=Find(parent, i.src);
        y=Find(parent, i.dest);
        if(x==y)
            continue;
        Union(parent, x, y);
        result.push_back({i.src, i.dest});
    }
    return result;
}
void Union(vector<int> &parent, int x, int y){
    parent[x]=y;
}
int Find(vector<int> &parent, int i){
    return parent[i]=(i==parent[i])?i:Find(parent, parent[i]);
}
void makeSet(vector<int> &parent, int N){
    parent.resize(N);
    for(int i=0;i<N;i++)
        parent[i]=i;
}
bool cmp(struct Edge a, struct Edge b){
    return a.weight<b.weight;
}
