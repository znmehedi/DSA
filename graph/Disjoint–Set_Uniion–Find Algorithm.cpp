#include<bits/stdc++.h>
using namespace std;
class DisjointSet{
    unordered_map<int, int>parent;

public:
    void makeSet(vector<int> &universalSet){
        for(int i:universalSet)
            parent[i]=i;
    }
    int Find(int i){
        return (parent[i]==i)?i:Find(parent[i]);
    }
    void Union(int u, int v){
        parent[Find(u)]=Find(v);
    }
    bool match(int i){
        return parent[i]==i;
    }
};
void printSet(vector<int> &universalSet, DisjointSet &ds){
    for(int i:universalSet)
        cout<<ds.Find(i)<<" ";
    cout<<endl;
}
void findNumberOfSet(vector<int> &universalSet, DisjointSet &ds){
    unordered_map<int, int>freq;

    for(int i:universalSet){
        freq[ds.Find(i)]+=1;

    }
    cout<<freq.size()<<endl;
    vector<vector<int>>countS(freq.size());
    for(int i:universalSet){

    }


}
int main(){
    vector<int>universalSet={1, 7, 5, 8, 9, 13};
    DisjointSet ds;
    ds.makeSet(universalSet);
    printSet(universalSet, ds);

    for(int i=1;i<4;i++){
        ds.Union(universalSet[0], universalSet[i]);
        printSet(universalSet, ds);
    }
    cout<<endl;
    findNumberOfSet(universalSet, ds);

//    ds.Union(1, 7);
//    printSet(universalSet, ds);
//
//    ds.Union(9, 13);
//    printSet(universalSet, ds);
//
//    ds.Union(1, 13);
//    printSet(universalSet, ds);
//
//    ds.Union(5, 8);
//    printSet(universalSet, ds);



    return 0;
}
