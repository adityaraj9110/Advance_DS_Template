#include<bits/stdc++.h>
using namespace std;
// Time Complxity 4alpha i.e., constant
class DSU{
    vector<int>par;
    vector<int>rank;
    vector<int>size;

    public:
    DSU(int n){
        par.resize(n+1);
        rank.resize(n+1,0);
        size.resize(n+1,1);

        for(int i=0;i<=n;i++){
            par[i]=i;
        }

    }

    int findPar(int u){
        if(par[u]==u) return u;
        else return par[u]=findPar(par[u]);
    }

    void unionByrank(int u,int v){
        int parU = findPar(u);
        int parV = findPar(v);
        
        if(parU==parV) return;

        if(rank[parU]>rank[parV]){
            par[parV]= parU;
        }
        else if(rank[parU]<rank[parV]){
            par[parU]=parV;
        }else{
            par[parU]=parV;
            rank[parV]++;
        }

    }

    void unionBySize(int u,int v){
        int parU = findPar(u);
        int parV = findPar(v);
        if(parU==parV) return;

        if(size[parU]>size[parV]){
            par[parV]=parU;
            size[parU]+=size[parV];
        }
        else{
            par[parU]=parV;
            size[parV]+=size[parU];
        }
    }
};
int main(){
    DSU ds(7);
    ds.unionBySize(1,2);
    ds.unionBySize(2,3);
    ds.unionBySize(4,5);
    ds.unionBySize(6,7);
    ds.unionBySize(5,6);
    if(ds.findPar(3)==ds.findPar(7)){
        cout<<"Same"<<"\n";
    }else{
        cout<<"Not Same"<<"\n";
    }
    ds.unionByrank(3,7);
    if(ds.findPar(3)==ds.findPar(7)){
        cout<<"Same"<<"\n";
    }else{
        cout<<"Not Same"<<"\n";
    }
    return 0;
}