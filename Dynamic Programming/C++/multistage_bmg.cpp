#include<bits/stdc++.h>
using namespace std;
void bmg(unordered_map<int,vector<pair<int,int>>>&graph,int src,int sink,vector<int>&cost,vector<int>&path){
    cost[src]=0;
    for(int i=src;i<=sink;i++){
        for(auto it:graph[i]){
            int node=it.first;
            int node_cost=it.second;
            if(cost[node]>cost[i]+node_cost){
                cost[node]=cost[i]+node_cost;
                path[node]=i;
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
    vector<int>parent(sink+1,-1);
    int count=fun(graph,src,sink,1);
    cout<<"Number of stages in graph: "<<count<<endl;
    vector<int>cost(sink+1,INT16_MAX);
    bmg(graph,src,sink,cost,parent);
    if(cost[sink]==INT16_MAX){
        cout<<"Path does not exist"<<endl;
    }
    else{
        cout<<"Minimum Cost: "<<cost[sink]<<endl;
        cout<<"Path from Source to Destination"<<endl;
        vector<int>path;
        int i=sink;
        while(i!=-1){
            path.push_back(i);
            i=parent[i];
        }
        reverse(path.begin(),path.end());
        for(int it:path){
            cout<<it<<"->";
        }

    }
    


}