#include<bits/stdc++.h>
using namespace std;
void prims(int src,vector<vector<pair<int,int>>>graph,int n){
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    vector<bool>vis(n,false);
    pq.push({0,src});
    int mst=0;
    while(pq.size()>0){
        auto it=pq.top();
        pq.pop();
        int node=it.second;
        int wt=it.first;
        if(vis[node]){
            continue;
        }
        vis[node]=true;
        mst+=wt;
        for(auto adj:graph[node]){
            int adjnode=adj.first;
            int adjwt=adj.second;
            if(!vis[adjnode]){
                pq.push({adjwt,adjnode});
            }

        }
    }
    cout<<"\n MST weight: "<<mst<<endl;
}
int main(){
    cout<<"enter the number of nodes and edges"<<endl;
    int nodes,edges;
    cin>>nodes>>edges;
    vector<vector<pair<int,int>>>graph(nodes);
    for(int i=0;i<edges;i++){
        cout<<"enter the src dst and wt"<<endl;
        int src,dst,wt;
        cin>>src>>dst>>wt;
        graph[src].push_back({dst,wt});
        graph[dst].push_back({src,wt});
    }
    prims(0,graph,nodes);

}