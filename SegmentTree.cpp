/* Written by Shubhankit Bansal
  Segment Tree Code for update range 
  query for l to r sum and update a single value
*/

#include<bits/stdc++.h>
#define int long long
#define ll long long
using namespace std;

ll build(ll a[],ll l,ll u,ll node,ll seg[]){
    if(l==u){
        seg[node]=a[l];
        return seg[node];
    }
    else{
        ll mid=(l+u)/2;
        ll x=build(a,l,mid,2*node,seg);
        ll y=build(a,mid+1,u,2*node+1,seg);
        seg[node]=x+y;
        return seg[node];
    }
}

ll query(ll seg[],ll l,ll u,ll node,ll start,ll end){
    if(u<start  || l>end){
        return 0;
    }
    else if(l<=start && u>=end){
        return seg[node];
    }
    else{
        ll mid;
        mid=(start+end)/2;
        ll x=query(seg,l,u,2*node,start,mid);
        ll y=query(seg,l,u,2*node+1,mid+1,end);
        return x+y;
    }
}

ll update(ll index,ll value,ll seg[],ll node,ll l,ll u){
    if(index<l || index>u){
        return seg[node];
    }
    else if(l==index && u==index){
        seg[node]=value;
        return seg[node];
    }
    else{
        ll mid=(l+u)/2;
        ll x=update(index,value,seg,2*node,l,mid);
        ll y=update(index,value,seg,2*node+1,mid+1,u);
        seg[node]=x+y;
        return seg[node];
    }
}

// void print(ll seg[]){
//     for(ll i=1;i<20;i++){
//         cout<<seg[i]<<" ";
//     }
//     cout<<endl;
// }

signed main(){
    ll t;
    cin>>t;
    while(t--){
        ll n,q;
        cin>>n>>q;
        ll a[n+1],seg[1000000];
        for(ll i=1;i<=n;i++){
            cin>>a[i];
        }
        build(a,1,n,1,seg);
        for(ll i=0;i<q;i++){
            ll type,l,u;
            cin>>type>>l>>u;
            if(type==1){
                cout<<query(seg,l,u,1,1,n)<<endl;
            }
            else{
                update(l,u,seg,1,1,n);
            }
        }
    }
}