#include<bits/stdc++.h>
using namespace std;
int LCS(string str1,string str2,vector<vector<int>>&p){
    int m=str1.size();
    int n=str2.size();
    
    vector<vector<int>>mat(m+1,vector<int>(n+1,0));
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(str1[i-1]==str2[j-1]){
                mat[i][j]=1+mat[i-1][j-1];
                p[i][j]=1;  //1 for diagonal move;
            }
            else if(mat[i][j-1]>mat[i-1][j]){
                mat[i][j]=mat[i][j-1];
                p[i][j]=2; //2 for left move
            }
            else{
                mat[i][j]=mat[i-1][j];
                p[i][j]=3;  //3 for up move;
            }
        }
        
    }
    return mat[m][n];

    
}
void path(vector<vector<int>>&p,string str1,int i,int j){
    if(i==0 || j==0){
        return;
    }
    if(p[i][j]==1){
        path(p,str1,i-1,j-1);
        cout<<str1[i-1];
    }
    else if(p[i][j]==2){
        path(p,str1,i,j-1);
    }
    else{
        path(p,str1,i-1,j);
    }
}
int main(){
    cout<<"enter the two string"<<endl;
    string str1,str2;
    cin>>str1>>str2;
    int m=str1.size();
    int n=str2.size();
    vector<vector<int>>p(m+1,vector<int>(n+1,0));
    cout<<"Length of longest common subsequences: "<<LCS(str1,str2,p)<<endl;
    cout<<"Longest subsequence: ";
    path(p,str1,m,n);
    cout<<endl;
}