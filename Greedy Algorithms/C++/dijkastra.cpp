#include<bits/stdc++.h>
using namespace std;
void dijkastra(int st,vector<vector<pair<int,int>>>&graph,int n){
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    vector<bool>vis(n,false);
    vector<int>dist(n,INT16_MAX);
    pq.push({0,st});
    dist[st]=0;
    while(pq.size()>0){
        auto it=pq.top();
        pq.pop();
        int node=it.second;
        if(vis[node]) continue;
        vis[node]=true;
        for(auto neighbour:graph[node]){
            int neighbour_node=neighbour.first;
            int cost =neighbour.second;
            if(dist[neighbour_node]>cost+dist[node]){
                
                dist[neighbour_node]=cost+dist[node];
                pq.push({dist[neighbour_node],neighbour_node});
            }

        }

    }
    cout<<"\n minimum distance to each node from: "<<st<<" node"<<endl;
    for(int it:dist){
        cout<<it<<" ";
    }
    
}
int main(){
    cout<<"enter the number of nodes and edges"<<endl;
    int nodes,edges;
    cin>>nodes>>edges;
    vector<vector<pair<int,int>>>graph(nodes);
    for(int i=0;i<edges;i++){
        cout<<"enter src dst and wt"<<endl;
        int src,dst,wt;
        cin>>src>>dst>>wt;
        graph[src].push_back({dst,wt});
        graph[dst].push_back({src,wt});
    }
    cout<<"enter the starting node"<<endl;
    int st;
    cin>>st;
    dijkastra(st,graph,nodes);
}