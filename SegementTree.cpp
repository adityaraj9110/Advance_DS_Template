#include<bits/stdc++.h>
using namespace std;

class Seg{
    vector<int>seg;

    public:
    Seg(int n){
        seg.resize(n*n);
    }
    
    void build(int ind,int low,int high,int arr[]){
        if(low==high) {
            seg[ind] = arr[low];
        }

        int mid = (low+high)>>1;

        // left
        build(2*ind+1,low,mid,arr);
        // right
        build(2*ind+2,mid,high,arr);
        seg[ind] = min(seg[2*ind+1],seg[ind*2+2]);
    }

    int query(int ind,int low,int high,int arr[],int l,int r){
        // no overlap
        // l r low high || low high l r
        if(r<low || high<l) return INT_MAX;

        // complete overlap
        // l low high r
        if(l<low && high<r) return seg[ind];

        // partial
        int mid = (low+high)>>1;

        int leftOp = query(2*ind+1,low,mid,arr,l,r);
        int rightOp = query(2*ind+2,mid,high,arr,l,r);
        return min(leftOp,rightOp);
    }
    void update(int ind,int low,int high,int arr[],int i,int val){
        if(low==high){
            seg[ind]=val;
            return;
        }

        int mid = (low+high)>>1;
        if(i<=mid){
            update(ind*2+1,low,mid,arr,i,val);
        }
        else update(ind*2+2,low,high,arr,i,val);

        seg[ind] = min(seg[ind*2+1],seg[ind*2+2]);
    }
};

int main(){
    int n;
    cin>>n;
    int *arr = new int[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    return 0;
}