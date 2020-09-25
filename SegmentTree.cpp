#include<bits/stdc++.h>
#define ll long long
#define int long long
#define mod1 1000000007
using namespace std;

ll add1(ll x,ll y){
    ll res=(x%mod1+y%mod1)%mod1;
    return res;
}

ll sub(ll x,ll y){
    ll res=0;
    res=(x%mod1-y%mod1+mod1)%mod1;
    return res;
}

ll mul(ll x,ll y){
    ll res=0;
    x=x%mod1;
    while(y){
        if(y&1)
            res=(res+x)%mod1;
        x=(x+x)%mod1;
        y=y>>1;
    }
    return res;
}

ll power(ll x,ll y){
    ll res=1;
    x=x%mod1;
    while(y){
        if(y&1)
            res=(res*x)%mod1;
        x=(x*x)%mod1;
        y=y>>1;
    }
    return res;
}

ll invflt(ll x){
    return power(x,mod1-2);
}

ll div1(ll x,ll y){
    ll y=inv(y);
    return (x*y)%mod1;
}

void build(ll node,ll start,ll end,ll tree[],ll arr[]){
    if(start==end){
        tree[node]=arr[start];
    }
    else{
        ll mid=(start+end)/2;
        build(2*node,start,mid,tree,arr);
        build(2*node+1,mid+1,end,tree,arr);
        tree[node]=tree[2*node]+tree[2*node+1];
    }
}

void update(ll node,ll start,ll end,ll tree[],ll arr[],ll idx,ll val){
    if(start==end){
        arr[start]+=val;
        tree[node]+=val;
    }
    else{
        ll mid=(start+end)/2;
        if(start<=idx && idx<=mid){
            update(2*node,start,mid,tree,arr,idx,val);
        }
        else if(end>=idx && idx>mid){
            update(2*node+1,mid+1,end,tree,arr,idx,val);
        }
        tree[node]=tree[2*node]+tree[2*node+1];
    }
}

ll query(ll node,ll start,ll end,ll l,ll r){
    if(r<start || end<l){
        return 0;
    }
    else if(l<=start && r>=end){
        return tree[node];
    }
    ll mid=(start+end)/2;
    ll left=query(2*node,start,mid,l,r);
    ll right=query(2*node+1,mid+1,end,l,r);
    return left+right;
}

void solve(){

}

signed main(){
	ll t;
	cin>>t;
	while(t--){
        solve();
    }
}
