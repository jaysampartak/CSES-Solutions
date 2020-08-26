#include<bits/stdc++.h>
#define int long long
#define all(x) x.begin(),x.end()
#define vii vector<pair<int,int>>
#define vi  vector<int>
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define tt int t; cin>>t;while(t--)
#define endl "\n"
#define pb push_back
#define boost ios_base::sync_with_stdio(false);cin.tie(NULL);
#define FOR(i,j,k) for(int i=j;i<k;i++ )
using namespace std;

const int mxn=2e5+5;
int t[4*mxn];
int h[mxn],r[mxn];
int n,ans;

void build(int v=1,int tl=0,int tr=n-1){
	if(tl==tr){
		t[v]=1;
	}else{
		int tm=(tl+tr)>>1;
		build(2*v,tl,tm);
		build(2*v+1,tm+1,tr);
		t[v]=(t[2*v]+t[2*v+1]);
	}
}

void update(int v,int tl,int tr,int pos){
	
	
	if(tl==tr){
		if(t[v])t[v]--;
		cout<<h[tl]<<" ";
		
	}else{
		int tm=(tl+tr)/2;
		if(t[2*v]<pos)
			update(2*v+1,tm+1,tr,pos-t[2*v]);
		else 
			update(2*v,tl,tm,pos);
		t[v]=(t[2*v]+t[2*v+1]);	
		
	}
}

signed main(){
	
	cin>>n;
	FOR(i,0,n)cin>>h[i];
	FOR(i,0,n)cin>>r[i];
	build();
	FOR(i,0,n){
		
		update(1,0,n-1,r[i]);
		
	}

		
}
