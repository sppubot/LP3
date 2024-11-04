#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
bool compare(pair<int,int>p1, pair<int,int>p2){
    double v1=(double)p1.first/p1.second;
    double v2=(double)p2.first/p2.second;
    return  v1>v2;
}
int main(){
    int n;
    cout<<"enter n:";
    cin>>n;
   vector< pair<int,int>>a(n);
    cout<<"enter value, weight:"<<endl;

    for(int i=0;i<n;i++)    {
        cin>>a[i].first>>a[i].second;
    }
    int w;
    cout<<"enter maximum weight:";
    cin>>w;
    int ans=0;
        sort(a.begin(),a.end(),compare);

    for(int i=0;i<n;i++){
        if(a[i].second<w){
            ans+=a[i].first;
            w-=a[i].second;
        }
        else{
            double vw=(double) a[i].first/ a[i].second;
            ans+=vw*w;
            w=0;
            break;
        }
    }
    cout<<ans;
}
//3
// value weight
// 60      10
// 100     20
// 120     30
// w=50
// ans=240