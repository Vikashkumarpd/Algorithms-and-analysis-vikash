#include<bits/stdc++.h>
using namespace std;
void fun(vector<vector<int>>&mat,vector<int>&order,int n){
    for (int i=1 ;i<n;i++){
        mat[i][i]=0;
    }
    for(int l=2;l<n;l++){
        for(int i=1;i<n-l+1;i++){
            int j=i+l-1;
            mat[i][j]= INT_MAX;
            for(int k=i;k<j;k++){
                int q=mat[i][k]+mat[k+1][j]+order[i-1]*order[k]*order[j] ;
              
                if(q < mat[i][j]){
                    mat[i][j]=q;
                }
            }
        }
    }
}
int main(){
    int n=6;
    vector<int>order={2,4,2,5,6,2};
    vector<vector<int>>mat(n,vector<int>(n,INT_MAX));
    fun(mat,order,n);
    cout<<mat[1][5];
}

