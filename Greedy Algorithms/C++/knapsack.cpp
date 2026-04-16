#include<bits/stdc++.h>
using namespace std;
int bywt(vector<int>&wt,vector<int>&profit,int maxwt){
        vector<pair<int,int>>wt_index;
        for(int j=0;j<wt.size();j++){
            wt_index.push_back({wt[j],j});
        }
        sort(wt_index.begin(),wt_index.end());
        
        float ans=0;
        for(int i=0;i<wt_index.size();i++){
            int tempidx=wt_index[i].second;
            int w=wt_index[i].first;
            int prof=profit[tempidx];
            if(w<maxwt){
                ans+=prof;
                maxwt=maxwt-w;
            }
            else{
                float ratio=(float)prof/w;
                ans+=ratio*maxwt;
                break;


            }
        }
        return ans;
}

bool compare(pair<int,int>p1,pair<int,int>p2){
    return p1.first>p2.first;
}
int byprofit(vector<int>&wt,vector<int>&profit,int maxwt){
        vector<pair<int,int>>pro_index;
        for(int j=0;j<wt.size();j++){
            pro_index.push_back({profit[j],j});
        }
        sort(pro_index.begin(),pro_index.end(),compare);
        
        
        float ans=0;
        for(int i=0;i<pro_index.size();i++){
            int tempidx=pro_index[i].second;
            int p=pro_index[i].first;
            int w=wt[tempidx];
            if(w<maxwt){
                ans+=p;
                maxwt=maxwt-w;
            }
            else{
                float ratio=(float)p/w;
                ans+=ratio*maxwt;
                break;


            }
        }
        return ans;
}
int byratio(vector<int>&wt,vector<int>&value,int w){
    vector<pair<int,int>>pair_of_ratio_and_index;
    for(int i=0;i<wt.size();i++){
        int ratio=value[i]/wt[i];
        pair_of_ratio_and_index.push_back({ratio,i});
    }
    sort(pair_of_ratio_and_index.begin(),pair_of_ratio_and_index.end(),compare);
    
    int ans=0;
    for(int i=0;i<pair_of_ratio_and_index.size();i++){
        int tempidx=pair_of_ratio_and_index[i].second;
        if(w>wt[tempidx]){
            ans+=value[tempidx];
            w=w-wt[tempidx];
        }
        else{
            ans+=w*pair_of_ratio_and_index[i].first;
            break;
        }

    }
    return ans;
}
int main(){
    ofstream file1("bywt.csv");
    ofstream file2("by_profit.csv");
    ofstream file3("by_ratio.csv");
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    
    for(int i=10;i<=100;i+=10){
        vector<int>wt;
        vector<int>profit;
      
        uniform_int_distribution<int> dist(1, i);
        int j=0;
        while (j<i)
        {
            wt.push_back(dist(rng));
            profit.push_back(dist(rng));
            j++;
        }
       
            file1<<i<<","<<bywt(wt,profit,i)<<endl;
        
            file2<<i<<","<<byprofit(wt,profit,i)<<endl;
            file3<<i<<","<<byratio(wt,profit,i)<<endl;

        
        
        
    }
    file1.close();
    file2.close();
    file3.close();
    cout<<"file created!"<<endl;
}