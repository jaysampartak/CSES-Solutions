#include<bits/stdc++.h>
//#define int long long
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
using namespace std;

const int mx1=2e5+5;
const int mx=4*mx1;
int tc[mx];
int tmi[mx];
int tma[mx];
int a[mx1];
int n;
void build(int v=1,int tl=0,int tr=n-1){
	if(tl==tr){
		tma[v]=tmi[v]=a[tl];
		tc[v]=1;
	}else{
		int tm=(tl+tr)>>1;
		build(2*v,tl,tm);
		build(2*v+1,tm+1,tr);
		tma[v]=max(tma[2*v+1],tma[2*v]);
		tmi[v]=min(tmi[2*v+1],tmi[2*v]);
		tc[v]=(tc[2*v+1]+tc[2*v]);
	}
	
}

void update(int v,int tl,int tr, int pos,int val){
	//cout<<"\n "<<v<<" "<<tl<< " "<<tr;
	if(tl==tr){
	//	cout<<"\nhaiya ho "<<v<<" "<<tl;
		tma[v]=tmi[v]=val;
	}else{
		int tm=(tl+tr)>>1;
		if(pos<=tm)
			update(2*v,tl,tm,pos,val);
		else
			update(2*v+1,tm+1,tr,pos,val);
		tma[v]=max(tma[2*v],tma[2*v+1]);
		tmi[v]=min(tmi[2*v],tmi[2*v+1]);	
		
	}
	
	
}
int query(int v,int tl,int tr,int mini,int maxi){
	if((tmi[v]<=mini&&mini<=tma[v])||
		(tmi[v]<=maxi&&maxi<=tma[v])||
		(mini<=tmi[v]&&tmi[v]<=maxi)||
		(mini<=tma[v]&&tma[v]<=maxi)
		);  
	else	
		return 0;
		
		
	if(tmi[v]>=mini&&tma[v]<=maxi)
		return tc[v];
	int tm=(tl+tr)>>1;
		
	return (	query(2*v,tl,tm,mini,maxi)+
				query(2*v+1,tm+1,tr,mini,maxi)			
	 );	
			
}

signed main(){
	boost;
	int q;
	cin>>n>>q;
	for(int i=0;i<n;i++)cin>>a[i];
	build();
	//for(int i=1;i<=19;i++)cout<<tc[i]<<" "<<tmi[i]<<" "<<tma[i]<<endl;
	while(q--){
		char sym;
		int c,d;
		cin>>sym>>c>>d;
		if(sym=='!'){
			c--;
			//cout<<"fu";for(int i=1;i<=25;i++)cout<<i<<" "<<tc[i]<<" "<<tmi[i]<<" "<<tma[i]<<endl;
			update(1,0,n-1,c--,d);
			//cout<<"fu";for(int i=1;i<=25;i++)cout<<i<<" " <<tc[i]<<" "<<tmi[i]<<" "<<tma[i]<<endl;
			
		}else{
			cout<<query(1,0,n-1,c,d)<<endl;
		}
	}
}
