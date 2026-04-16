#include<bits/stdc++.h>
using namespace std;
vector<int> dijkastra(int st,vector<vector<pair<int,int>>>&graph,int n){
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    vector<bool>vis(n,false);
    vector<int>dist(n,INT16_MAX);
    vector<int>path(n,-1);
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
                path[neighbour_node]=node;
            }

        }

    }
    return path;
    
    
}
bool print_path(vector<int>&path,int src,int dst,vector<int>&ans){

    while(dst!=-1){

        ans.push_back(dst);

        if(dst==src) return true;

        dst=path[dst];
    }

    return false;
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
    cout<<"enter the starting node and ending node"<<endl;
    int st,dst;
    cin>>st>>dst;
    vector<int>path=dijkastra(st,graph,nodes);
    vector<int>ans;

    if(!print_path(path,st,dst,ans)){

        cout<<"path doesnot exist"<<endl;
        return 0;
    }

    reverse(ans.begin(),ans.end());

    for(int it:ans){

        cout<<it<<" ";
    }
}