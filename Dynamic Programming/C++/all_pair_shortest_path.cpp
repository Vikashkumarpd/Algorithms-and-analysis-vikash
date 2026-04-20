#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> all_pair_sortest_path(vector<vector<int>>&graph,int n){
    vector<vector<int>>path(n,vector<int>(n,-1));
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int q=graph[i][k]+graph[k][j];
                if(q<graph[i][j]){
                    graph[i][j]=q;
                    path[i][j]=k;
                }
            }
        }
    }
    return path;
}
void print_path(int src,int dst,vector<vector<int>>&path){
    if(path[src][dst]==-1){
        return;
    }
    int k=path[src][dst];
    print_path(src,k,path);
    cout<<k<<"->";
    print_path(k,dst,path);
}
int main(){
    cout<<"enter the number of vertex and edges"<<endl;
    int nodes,edges;
    cin>>nodes>>edges;
    vector<vector<int>>graph(nodes,vector<int>(nodes,INT16_MAX));
    for(int i=0;i<nodes;i++){
        graph[i][i]=0;
    }
    for(int i=0;i<edges;i++){
        cout<<"enter src dst and cost"<<endl;
        int src,dst,cost;
        cin>>src>>dst>>cost;
        graph[src][dst]=cost;
        

    }
   vector<vector<int>>path= all_pair_sortest_path(graph,nodes);
   cout<<"\nshortest path between all pair"<<endl;
    for(int j=0;j<nodes;j++){
        for(int i=0;i<nodes;i++){
            cout<<graph[j][i]<<" ";
        }
        cout<<endl;
    }
    cout<<"path matrix"<<endl;
    for(int i=0;i<nodes;i++){
        for(int j=0;j<nodes;j++){
            cout<<path[i][j]<<" ";
        }
        cout<<endl;

    }
    cout<<"Enter the source and destination"<<endl;
    int src,dst;
    cin>>src>>dst;
    if(graph[src][dst]==INT16_MAX){
        cout<<"path does not exist"<<endl;
    }
    else{
        cout<<"Shortest cost: "<<graph[src][dst]<<endl;
        cout<<"Shortest path from "<<src<<" to "<<dst<<endl;

        cout<<src<<"->";
        print_path(src,dst,path);
        cout<<dst;
    }

    
}