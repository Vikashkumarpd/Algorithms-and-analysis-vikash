#include <bits/stdc++.h>
using namespace std;

struct point{
    int x;
    int y;

};

int area(point a,point b,point c){

     return abs(
        a.x*(b.y - c.y) + b.x*(c.y - a.y) + c.x*(a.y - b.y)
    );

}

bool islies(point a,point b,point c,point pt){

    return (area(a,b,c)==(area(a,b,pt))+area(b,c,pt)+area(a,c,pt));


}

void Convex_hull(vector<point>&points,vector<bool>&lies_inside){

    int n=points.size();

    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int k=j+1;k<n;k++){

                 if(area(points[i],points[j],points[k]) == 0)
                continue;
              for(int p=0;p<n;p++){

                if(p==i||p==j||p==k) continue; 

                if(islies(points[i],points[j],points[k],points[p])){

                    lies_inside[p]=true;
                }
                

              }


            }
        }
    }



}


int main() {

    vector<point> points = {
    {1,1},
    {2,5},
    {5,6},
    {7,4},
    {6,1},
    {4,0},
    {3,3},
    {4,2},
    {5,3},
    {3,2}
    };
    int n=points.size();

    vector<bool>islies_inside(n,false);


    Convex_hull(points,islies_inside);

    cout<<"convex hull "<<endl;

    for(int i=0;i<n;i++){

        if(!islies_inside[i]){
            cout<<"("<<points[i].x<<","<<points[i].y<<") ";
        }

    

    }



    
    return 0;
}