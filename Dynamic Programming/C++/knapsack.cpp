#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>knapsack(vector<int>&profit,vector<int>&weight,vector<vector<int>>&matrix,int wt){
    int n=profit.size();
    vector<vector<int>>path(n+1,vector<int>(wt+1,-1));
    for(int i=0;i<=wt;i++){
        matrix[0][i]=0;
    }
    for(int i=0;i<=n;i++){
        matrix[i][0]=0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=wt;j++){
            if(weight[i-1]<=j){
                if(profit[i-1]+matrix[i-1][j-weight[i-1]]>matrix[i-1][j]){
                  matrix[i][j]=profit[i-1]+matrix[i-1][j-weight[i-1]];
                  path[i][j]=1;
                }
                else{
                    matrix[i][j]=matrix[i-1][j];
                }

            }
            
            else{
                matrix[i][j]=matrix[i-1][j];
            }
        }
    }
    return path;
}
void print_path(vector<vector<int>>&path,vector<int>&wt,int i,int j){
    if(i==0 || j==0){
        return;
    }
    if(path[i][j]==1){
        print_path(path,wt,i-1,j-wt[i-1]);
        cout<<i<<" is selected!"<<endl;
    }
    else{
        print_path(path,wt,i-1,j);
    }
}
int main(){
    cout<<"enter size of vector"<<endl;
    int n;
    cin>>n;
    vector<int>profit(n);
    vector<int>weight(n);
    cout<<"enter the profit vector"<<endl;
    for(int i=0;i<n;i++){
        cin>>profit[i];
    }
    cout<<"enter the weight vector"<<endl;
    for(int i=0;i<n;i++){
        cin>>weight[i];
    }
    cout<<"enter the weight"<<endl;
    int wt;
    cin>>wt;
    vector<vector<int>>matrix(n+1,vector<int>(wt+1,INT16_MIN));
    vector<vector<int>>path=knapsack(profit,weight,matrix,wt);
    cout<<"maximum profit: "<<matrix[n][wt]<<endl;
    print_path(path,weight,n,wt);

}