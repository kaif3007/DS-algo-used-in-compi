####################################################################################################
LIS in nlogn
###################################################################################################

int LIS(vector<int>& nums)
{
    int n=nums.size();
    if(!n)
        return 0;
    
    int last[n+1];
    int l=1;
    last[l]=nums[0];
    
    for(int i=1;i<n;i++)
    {
        int idx=lower_bound(last+1,last+1+l,nums[i])-last;
        
        if(idx>l)
            l+=1;
    
       last[idx]=nums[i];
        
    }
    
    return l;
}

###########################################################################################################
suffix array
###########################################################################################################

#include<bits/stdc++.h>
#define pb push_back 
#define ff first
#define ss second
#define MOD 1000000007
#define ll long long int
#define P pair<ll,ll>
 
using namespace std;

//digital electronics k trah hai.
//4 4 length ke string k ranking pata h
//to usko use krke 8 length k array k ranking pata kr sakte hain
 
//node starting index, ending index aur uska original index store krega
struct node
{
	int st,en,idx;
};


//comp pahle k hisaab se sort krega
//fist half length and then last half length
bool comp(node n1,node n2)
{
	if(n1.st!=n2.st)
		return n1.st<n2.st;
	else
		return n1.en<n2.en;
}


//table[i][j] index i se starting par (1<<j) ka ranking batayega
int table[1005][13];

//ye function kisi 2 suffix strating at i and j ka lcp(longest common prefix) find krta hai
int lcp(int i,int j,int logn,int n)
{
	int ans=0;

    for(int l=logn-1;l>=0 and i<n and j<n;l--)
    {
    	if(table[i][l]==table[j][l])
    	{
    		ans+=(1<<l);
    		i+=(1<<l);
    		j+=(1<<l);
    	}
    }

	return ans;
}


int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   
    int t=1;
    cin>>t;

    while(t--)
    {
    	
    	string s;
    	cin>>s;

    	int n=s.length();

    	int logn=1,pro=1;
    	while(pro<n)
    	{
    		pro*=2;
    		logn++;
    	}

        //ye temp array hai jo ranking k liye use hoga
        //finally isi se suffix index milega
        vector<node> v(n);

         
         //ek length ka suffix ka index uska ascii value hoga
        for(int i=0;i<n;i++)
        	table[i][0]=s[i]-'A';

        int cnt=1;
  

        for(int i=1;i<logn;i++)
        {
        	for(int j=0;j<n;j++)
        	{
        		v[j].st=table[j][i-1];
        		if(j+cnt<n)
        			v[j].en=table[j+cnt][i-1];
        		else
        			v[j].en=-1;
                //end kuch nahi h to -1 krdo.
        		v[j].idx=j;
        	}

        	sort(v.begin(),v.end(),comp);

        	int l=0;
        	table[v[0].idx][i]=l;

        	for(int j=1;j<n;j++)
        	{
                //dono part k ranking same h to same ranking milega
        		if(v[j-1].st!=v[j].st or v[j-1].en!=v[j].en )
        			l++;

        		table[v[j].idx][i]=l;
        	}

        	cnt*=2;
        }
        
        
//sorted order m sabse jyada common milega.
//jitna milte jyaga minus krte jaao
        
        int sum=0;
        for(int i=1;i<n;i++)
        	sum+=lcp(v[i-1].idx,v[i].idx,logn,n);

        cout<<(n*(n+1))/2-sum<<"\n";

    }
    
    return 0;
}


###########################################################################################
lca using binary lifting
###########################################################################################

#include<bits/stdc++.h>
#define N 1005
#define ll long long int
using namespace std;

int par[N],level[N];
void dfs(int i,int p,int l,vector<int> arr[])
{
	level[i]=l;
	for(int j=0;j<arr[i].size();j++)
	{
		if(arr[i][j]==p)
		continue;
		par[arr[i][j]]=i;
	    dfs(arr[i][j],i,l+1,arr);
	}
}


 int main()
{ 
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
  
  int t;
  cin>>t;
  int casee=1;
  while(t--)
  {  cout<<"Case "<<casee<<":"<<endl;
     casee++;
  	 memset(par,0,sizeof(par));
  	 memset(level,0,sizeof(level));
  	
  int n;
  cin>>n;
  vector<int> arr[n];
  
  for(int i=0;i<n;i++)
  {
  	int p;
  	cin>>p;
  	for(int j=0;j<p;j++)
  	{
  		int t;
  		cin>>t;
  		t--;
  		arr[i].push_back(t);
  		arr[t].push_back(i);
    }
  }
  
  dfs(0,-1,0,arr);
  par[0]=-1;
   
  int i=1;
  while((1<<i)<n)
   i++;
  int p[n][i];
  memset(p,-1,sizeof(p));
  
  for(int j=0;j<n;j++)
   p[j][0]=par[j];
   
   for(int k=1;k<i;k++)
   {
   	 for(int j=0;j<n;j++)
   	  if(p[j][k-1]!=-1)
   	   p[j][k]=p[p[j][k-1]][k-1];
   }
   
   int q;
   cin>>q;
   while(q--)
   {
   	  int a,b;
   	   cin>>a>>b;
   	   a--;
   	   b--;
   	   if(level[a]<level[b])
   	    swap(a,b);
   	    
   	    int raise=level[a]-level[b];
   	    int j=0;
   	    while(raise)
   	    {
   	    	if(raise&1)
   	    	  a=p[a][j];
   	    	  j++;
   	    	  raise>>=1;
	    }
	    
	    if(a!=b)
	    {
	    	for(int j=i-1;j>=0;j--)
	    	{
	    		if(p[a][j]!=p[b][j])
	    		{
	    			a=p[a][j];
	    			b=p[b][j];
				}
			}
			a=par[a];
		}
		cout<<a+1<<endl;
   }
   
}
	return 0;
}




