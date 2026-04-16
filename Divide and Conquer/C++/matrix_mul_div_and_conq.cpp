#include <iostream>
#include<vector>
#include <random>
#include <cmath>
#include<chrono>
#include<fstream>
#include<string>
using namespace std;
int findnextpower(int n){
    int p=1;
    while (p<n)
    {
        p*=2;
    }
    return p;
    
}

void mul(vector<vector<int>>&v1,vector<vector<int>>&v2,vector<vector<int>>&v3,int order,int v1i,int v1j,int v2i,int v2j,int v3i,int v3j){
    if(order==1){
        v3[v3i][v3j]+=v1[v1i][v1j]*v2[v2i][v2j];
        return;
    }
    int half=order/2;
    //c00
    mul(v1,v2,v3,half,v1i,v1j,v2i,v2j,v3i,v3j);
    mul(v1,v2,v3,half,v1i,v1j+half,v2i+half,v2j,v3i,v3j);
    //c01
    mul(v1,v2,v3,half,v1i,v1j,v2i,v2j+half,v3i,v3j+half);
    mul(v1,v2,v3,half,v1i,v1j+half,v2i+half,v2j+half,v3i,v3j+half);
    //c10
    mul(v1,v2,v3,half,v1i+half,v1j,v2i,v2j,v3i+half,v3j);
    mul(v1,v2,v3,half,v1i+half,v1j+half,v2i+half,v2j,v3i+half,v3j);
    //c11
    mul(v1,v2,v3,half,v1i+half,v1j,v2i,v2j+half,v3i+half,v3j+half);
    mul(v1,v2,v3,half,v1i+half,v1j+half,v2i+half,v2j+half,v3i+half,v3j+half);
    

}
int main(){
    cout<<"enter the size of matrix"<<endl;
    int n;
    cin>>n;
    vector<vector<int>>v1(n,vector<int>(n));
    vector<vector<int>>v2(n,vector<int>(n));
    cout<<"enter the element in mat1"<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>v1[i][j];
        }
    }
    cout<<"enter the element in mat2"<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>v2[i][j];
        }
    }
    int m=findnextpower(n);
    vector<vector<int>>a(m,vector<int>(m,0));
    vector<vector<int>>b(m,vector<int>(m,0));
    vector<vector<int>>c(m,vector<int>(m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            a[i][j]=v1[i][j];
            b[i][j]=v2[i][j];
        }
    }
    
    mul(a,b,c,m,0,0,0,0,0,0);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<c[i][j]<<" ";
        }
        cout<<endl;
    }


}


