//#include<bits/stdc++.h>
//using namespace std;
//#define ll long long


//void __print(int x) {cerr << x;}
//void __print(long x) {cerr << x;}
//void __print(long long x) {cerr << x;}
//void __print(unsigned x) {cerr << x;}
//void __print(unsigned long x) {cerr << x;}
//void __print(unsigned long long x) {cerr << x;}
//void __print(float x) {cerr << x;}
//void __print(double x) {cerr << x;}
//void __print(long double x) {cerr << x;}
//void __print(char x) {cerr << '\'' << x << '\'';}
//void __print(const char *x) {cerr << '\"' << x << '\"';}
//void __print(const string &x) {cerr << '\"' << x << '\"';}
//void __print(bool x) {cerr << (x ? "true" : "false");}
//template<typename T, typename V>
//void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
//template<typename T>
//void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
//void _print() {cerr << "]\n";}
//template <typename T, typename... V>
//void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
//#ifndef ONLINE_JUDGE
//#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
//#else
//#define debug(x...)
//#endif


//#define all(x) x.begin(),x.end()
//#define ip vector<pair<int,pair<int,int>>>
//#define vii vector<pair<int,int>>
//#define vi  vector<int>
//#define pb push_back
//#define eb emplace_back
//#define mp make_pair
//#define fi first
//#define se second
//#define tt int t; cin>>t;while(t--)
//#define FOR(i,j,k) for(int i=j;i<k;i++)
//#define endl "\n"
//#define pb push_back
//#define boost ios_base::sync_with_stdio(false);cin.tie(NULL);



//const int BLOCK=555;
//int n,q;
//const int mx=2e5+5;
//int x[mx];
//int ans;
//int cnt[mx];
//int qw[mx];



//bool comp(pair<int,pair<int,int>> a ,pair<int,pair<int,int>> b){
	//if((a.se.fi/BLOCK)==(b.se.fi/BLOCK)){
		//return a.se.se<b.se.se;
	//}
	//return (a.se.fi/BLOCK)<(b.se.fi/BLOCK);
//}

//void add(int pos){
	//cnt[x[pos]]++;
	//if(cnt[x[pos]]==1)
		//ans++;
		
//}
//void remove(int pos){
	//cnt[x[pos]]--;
	//if(cnt[x[pos]]==0)
		//ans--;
//}


//signed main(){
	//boost;
	//scanf(&d,n);
	//scanf(&d,m);
	//unordered_map<int,int> cordinateCompress;
	//int compressed_num=1;
	
	//for(int i=0;i<n;i++){
			//x[i];
			//if(cordinateCompress.find(x[i])!=cordinateCompress.end()){
				//x[i]=cordinateCompress[x[i]];
			//}else{
				//cordinateCompress[x[i]]=compressed_num;
				//x[i]=compressed_num++;
			//}
	//}
	
	//ip vp;
	//FOR(i,0,q){
		//int a,b;
		//cin>>a>>b;
		//a--;
		//b--;
		//vp.pb({i,{a,b}});
	//}
	
	//sort(all(vp),comp);
	
	//int l=vp[0].se.fi;
	//int r=vp[0].se.fi;
	//add(l);
	
	//FOR(i,0,q){
		
		//int left=vp[i].se.fi;
		//int right=vp[i].se.se;
		
		//while(l>left)
			//add(--l);
		//while(r<right)
			//add(++r);
		//while(l<left)
			//remove(l++);
		//while(r>right)
			//remove(r--);
			
		//qw[vp[i].fi]=ans;		
		
	//}
	//FOR(i,0,q)cout<<qw[i]<<endl;
	

//}

#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define fr(a,b) for(ll i = a; i < b; i++)
#define mod 1000000007
#define inf (1LL<<60)
#define all(x) (x).begin(), (x).end()
#define prDouble(x) cout << fixed << setprecision(10) << x
#define triplet pair<ll,pair<ll,ll>>
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;
const int rootN = 555;
 
int freq[200000];
int distinct;
int ar[200000];
 
struct query
{
    int L;
    int R;
    int q_no;
    int block_no;
    bool operator < (query& q2)
    {
        if(block_no < q2.block_no)
            return 1;
        else if(block_no > q2.block_no)
            return 0;
        else return R < q2.R;
    }
};
 
void Add(int& elem)
{
    if(!freq[elem])distinct++;
    freq[elem]++;
}
void Remove(int& elem)
{
    freq[elem]--;
    if(!freq[elem])
        distinct--;
}
 
void adjust(int& curr_l, int& curr_r, query& q)
{
    while(curr_l > q.L)
    {
        curr_l--;
        Add(ar[curr_l]);
    }
    while(curr_r < q.R)
    {
        curr_r++;
        Add(ar[curr_r]);
    }
	while(curr_l < q.L)
    {
        Remove(ar[curr_l]);
        curr_l++;
    }
    while(curr_r > q.R)
    {
        Remove(ar[curr_r]);
        curr_r--;
    }
 
}
 
void solve(vector<query>& queries)
{
    vector<int> answer(queries.size());
    sort(queries.begin(), queries.end());
    memset(freq, 0, sizeof freq);
    distinct = 1;
 
    int curr_l = queries[0].L;
    int curr_r = queries[0].L;
 
    freq[ar[curr_l]]++;
 
    for(query& qr : queries)
    {
        adjust(curr_l, curr_r, qr);
        answer[qr.q_no] = distinct;
    }
 
    for(int x : answer)
            cout<<x<<'\n';
}
 
int main() {
   fast_io;
   int n,q;
   cin >> n >> q;
 
   map<int,int> coordinateCompress;
   int compressed_Num = 1;
 
   for(int i = 0; i < n; i++)
   {
       cin >> ar[i];
       if(coordinateCompress.find(ar[i]) != coordinateCompress.end()){
        ar[i] = coordinateCompress[ar[i]];
       }
       else{
        coordinateCompress[ar[i]] = compressed_Num;
        ar[i] = compressed_Num++;
       }
   }
 
   vector<query> queries(q);
   for(int i = 0; i < q; i++)
   {
       int u,v;
       cin >> u >>v;
       queries[i].L = u-1;
       queries[i].R = v-1;
       queries[i].q_no = i;
       queries[i].block_no = u/rootN;
   }
   solve(queries);
   return 0;
}

