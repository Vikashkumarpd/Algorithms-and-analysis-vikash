#include<bits/stdc++.h>
using namespace std;
void fmg(unordered_map<int,vector<pair<int,int>>>&graph,int src,int sink,vector<int>&cost,vector<int>&path){
    cost[sink]=0;
    for(int i=sink-1;i>=src;i--){
        for(auto it:graph[i]){
            int node=it.first;
            int node_cost=it.second;
            if(cost[node]!=INT16_MAX && cost[node] + node_cost < cost[i]){
                cost[i]=min(cost[node]+node_cost,cost[i]);
                path[i]=node;
            }
        }
    }
    
}
int fun(unordered_map<int,vector<pair<int,int>>>&graph,int src,int sink,int count){
    if(src==sink){
        return count;
    }
    auto it=graph[src];
    int v=it[0].first;
    return fun(graph,v,sink,count+1);

}
int main(){
    unordered_map<int,vector<pair<int,int>>>graph;
    cout<<"enter the number of edges"<<endl;
    int n;
    cin>>n;
    int src,sink;
    cout<<"enter the src and sink"<<endl;
    cin>>src>>sink;
    for(int i=0;i<n;i++){
        cout<<"enter src,dst,cost"<<endl;
        int src,dst,cost;
        cin>>src>>dst>>cost;
        graph[src].push_back({dst,cost});
    }
    vector<int>path(sink+1,-1);
    int count=fun(graph,src,sink,1);
    cout<<"Number of stages in graph: "<<count<<endl;
    vector<int>cost(sink+1,INT16_MAX);
    fmg(graph,src,sink,cost,path);
    if(cost[src]==INT16_MAX){
        cout<<"Path does not exist"<<endl;
    }
    else{
        cout<<"Minimum Cost: "<<cost[src]<<endl;
        cout<<"Path from Source to Destination"<<endl;
        int i=src;
        while(path[i]!=sink){
            cout<<path[i]<<"->";
            i=path[i];
        }
        cout<<path[sink];

    }
    


}