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
using namespace std;


const int mxn=2e5+5;
int t[4*mxn];
vi a;
int n,q;
void build(int v,int tl,int tr){
	
	if(tl==tr)
		t[v]=a[tl];
	else{
		int tm=(tl+tr)/2;
		build(2*v,tl,tm);
		build(2*v+1,tm+1,tr);
		t[v]=min(t[2*v],t[2*v+1]);
	}	
}
int mini(int v,int tl ,int tr,int l,int r){
	if(l>r)
		return INT_MAX;
	if(l==tl&&r==tr)
		return t[v];

	int tm=(tl+tr)/2;
	return min(mini(2*v,tl,tm,l,min(tm,r)),
			mini(2*v+1,tm+1,tr,max(l,tm+1),r));	

		
}
//void build(int v,int tl,int tr){
	//cout<<tl<<" "<<tr<<endl;
	//if(tl==tr)
		//t[v]=a[tl];
	//else{
		//int tm=(tl+tr)/2;
		//build(2*v,tl,tm);
		//build(2*v+1,tm+1,tr);
		//t[v]=t[2*v]+t[2*v+1];
		
	//}
//}
//int sum(int v,int tl,int tr,int l,int r ){
	//if(l>r)
		//return 0;
	//if(l==tl&&r==tr)
		//return t[v];
	//int tm=(tl+tr)/2;
	//return sum(v*2,tl,tm,l,min(r,tm))
			//+ sum(v*2+1,tm+1,tr,max(l,tm+1),r);		
//}

void update(int v,int tl,int tr,int pos,int new_val){
	if(tl==tr)
		t[v]=new_val;
	else{
		int tm=(tl+tr)/2;
		if(pos<=tm)
			update(2*v,tl,tm,pos,new_val);
		else
			update(2*v+1,tm+1,tr,pos,new_val);
		t[v]=min(t[2*v],t[2*v+1]);	
		
	}	
	
}

signed main(){
	cin>>n>>q;
	a.resize(n);
	for(int i=0;i<n;i++)	
		cin>>a[i];
		
	build(1,0,n-1);
		
	while(q--){
		int t,pos,val;
		cin>>t>>pos>>val;
		if(t==1){
			pos--;
			update(1,0,n-1,pos,val);
		}else{
			pos--;
			val--;
			cout<<mini(1,0,n-1,pos,val)<<endl;
		}
	}		

}
