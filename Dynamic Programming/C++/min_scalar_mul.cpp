#include<bits/stdc++.h>
using namespace std;
void min_scalar_mul(vector<vector<int>>&mat,vector<int>&order,int n,vector<vector<int>>&path){
    for(int l=2;l<n;l++){
        for(int i=1;i<n-l+1;i++){
           int j=i+l-1;
           mat[i][j]=INT16_MAX;
           for(int k=i;k<j;k++){
            int q=mat[i][k]+mat[k+1][j]+order[i-1]*order[k]*order[j];
            if(q<mat[i][j]){
                mat[i][j]=q;
                path[i][j]=k;
            }
           }
        }
    }
}
void print_optimal(int i,int j,vector<vector<int>>&path){
    if(i == j){
        cout<<"A"<<i;
        return;
    }
    cout<<"(";
    print_optimal(i, path[i][j], path);
    print_optimal(path[i][j]+1, j, path);
    cout<<")";
}

int main(){
    int n=6;
    vector<int>order={2,4,2,5,6,2};
    vector<vector<int>>mat(n,vector<int>(n,0));
    vector<vector<int>>path(n,vector<int>(n,-1));
    min_scalar_mul(mat,order,n,path);
    cout<<"Multiplication Matrix"<<endl;
    for(int i=0;i<6;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<mat[i][j]<<" ";
        }
        cout<<" \n";
    }
    cout<<"\n"<<"Minimum scalar multiplication: "<<mat[1][5]<<endl;
    cout<<"Path Matrix"<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<path[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"\n Optimal path"<<endl;
    print_optimal(1, n-1, path);
}
