#include<bits/stdc++.h>
using namespace std;
class edges{
    public:
    int src,dst,wt;
    edges(int a,int b,int c){
        src=a;
        dst=b;
        wt=c;
    }
};
class disjoint{
    public:
    vector<int>parent;
    vector<int>rank;
    disjoint(int n){
        rank.resize(n,0);
        parent.resize(n);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
    }
    int find(int n){
        if(n==parent[n]){
            return n;
        }
        return parent[n]=find(parent[n]);
    }
    void union_by_rank(int x,int y){
        int px=find(x);
        int py=find(y);
        if(px==py){
            return;
        }
        if(parent[px]>parent[py]){
            parent[py]=px;
            
        }
       else if(parent[px]<parent[py]){
            parent[px]=py;
            
        }
        else{
            parent[py]=px;
            rank[px]++;
        }
    }

};

int main(){
    cout<<"enter number of nodes and edges"<<endl;
    int nodes,edges;
    cin>>nodes>>edges;
    vector<pair<int,pair<int,int>>>graph;
    disjoint ds(nodes);
    for(int i=0;i<edges;i++){
        cout<<"enter the src dst and wt"<<endl;
        int src,dst,wt;
        cin>>src>>dst>>wt;

       graph.push_back({wt,{src,dst}});


    }
    sort(graph.begin(),graph.end());
    int mstwt=0;
    cout<<"\n edges that form mst"<<endl;
    for(auto it:graph){
        int wt=it.first;
        int src=it.second.first;
        int dst=it.second.second;
        if(ds.find(src)!=ds.find(dst)){
            mstwt+=wt;
            ds.union_by_rank(src,dst);
            cout<<src<<"->"<<dst<<endl;

        }

    }
    cout<<"MST weight"<<mstwt<<endl;
    

}
