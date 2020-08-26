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
int a[mxn];
int t[4*mxn];
int lazy[4*mxn];
int n;
//in this implementation if lazy node has a value then 
//it means corresponding node in segment tree is updated to latest value 
//but children are not updated hence 
//if we find any value in the lazy node no need to change it
//only change its children nodes lazy and segment tree values



void build(int v,int tl,int tr){
	
	if(tl==tr)
		t[v]=a[tl];
	else{
		int tm=(tl+tr)/2;
		build(2*v,tl,tm);
		build(2*v+1,tm+1,tr);
		t[v]=t[2*v]+t[2*v+1];
		
	}
	
	
}
void push(int v){
	//cout<<"inside push " << v<<endl;
	
	//for(int i=1;i<=15;i++)cout<<lazy[i]<<" ";
	//cout<<endl;
	//for(int ii=1;ii<=15;ii++)cout<<t[ii]<<" ";
	//cout<<endl;
	t[2*v]+=lazy[v];
	lazy[2*v]+=lazy[v];
	t[2*v+1]+=lazy[v];
	lazy[2*v+1]+=lazy[v];	
	lazy[v]=0;
}
void updateRange(int v,int tl,int tr,int l,int r,int addend){
	
	//cout<<endl;
	//cout<<tl<<" "<<tr<<" "<<l<<" "<<r<<endl;
	//for(int i=1;i<=15;i++)cout<<lazy[i]<<" ";
	//cout<<endl;
	//for(int i=1;i<=15;i++)cout<<t[i]<<" ";
	//cout<<endl;
	if(l>r)
		return;
	if(l<=tl&&r>=tr){
		t[v]+=addend*(r-l+1);
		lazy[v]+=addend;
	}else{
		push(v);
		int tm=(tl+tr)/2;
		updateRange(2*v,tl,tm,l,min(r,tm),addend);
		updateRange(2*v+1,tm+1,tr,max(l,tm+1),r,addend);
		t[v]=t[2*v]+t[2*v+1];
	}	
}
int get(int v,int tl,int tr,int pos){
	//cout<<"inside get "<<v<<" "<<tl<< " "<<tr<<endl;

	
	//for(int i=1;i<=15;i++)cout<<lazy[i]<<" ";
	//cout<<endl;
	//for(int ii=1;ii<=15;ii++)cout<<t[ii]<<" ";
	//cout<<endl;
	if(tl==tr)
		return t[v];
	push(v);
	int tm=(tl+tr)/2;
	
	if(pos<=tm)
			return get(2*v,tl,tm,pos);
	else
		return get(2*v+1,tm+1,tr,pos);
	
}

signed main(){
	int q;
	cin>>n>>q;
	for(int i=0;i<n;i++)
		cin>>a[i];
	build(1,0,n-1);
	while(q--){
		int p,pos,val,u;
		cin>>p;
		if(p==1){
			cin>>pos>>val>>u;
			updateRange(1,0,n-1,--pos,--val,u);	
		}else{
			cin>>pos;
			cout<<get(1,0,n-1,--pos)<<endl;
		}
			//cout<<endl;
	
	//for(int i=1;i<=15;i++)cout<<lazy[i]<<" ";
	//cout<<endl;
	//for(int ii=1;ii<=15;ii++)cout<<t[ii]<<" ";
	//cout<<endl;
	}	
	

}
