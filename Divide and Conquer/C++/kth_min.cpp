#include<iostream>
#include<vector>
using namespace std;
int partion(vector<int>&num,int st,int end){
    int p=num[st];
    int s=st;
    for(int i=st;i<=end;i++){
        if(p>num[i]){
            s++;
        }
    }
    swap(num[s],num[st]);
    int i=st,j=end;
    while (i<j)
    {
        while (i<s && num[i]<p)
        {
            i++;
        }
        while (j>s && num[j]>p)
        {
            j--;
        }
        if(i<j){
            swap(num[i],num[j]);
            i++,j--;
        }
        
        
    }
    return s;
    
}
int find_kth_min(vector<int>&num,int k,int st,int end){
    if(st>end){
        return -1;
    }
    int pivot=partion(num,st,end);
    if(pivot==k-1){
        return num[k-1];
    }
    else if(pivot>k-1){
       return find_kth_min(num,k,st,pivot-1);
    }
    else{
       return find_kth_min(num,k,pivot+1,end);
    }

}
int main(){
    vector<int>num={8,5,3,1,77,66,44,55,98,23,42,12,22};
    cout<<"enter the value of k"<<endl;
    int k;
    cin>>k;
   cout<<find_kth_min(num,k,0,num.size()-1);
}
