
/*
###########################################
cycle in directed graph.
###########################################
*/

int visited[100000];

bool cycledetect(vector<int> kaif[],int root)
{
	visited[root]=1;
	for(int i=0;i<kaif[root].size();i++)
	{
		int temp=0;
		if(visited[kaif[root][i]]==0)
		temp=cycledetect(kaif,kaif[root][i]);
		
		else if(visited[kaif[root][i]]==1)
		return 1;
		
		if(temp==1)
		return 1;
		
	}
	
	visited[root]=2;
	return 0;
}


/*
###########################################
articulation points
###########################################
*/
int discovered[1000],low[1000],mark[1000],parent[1000];
bool ap[1000];
int timee=0;

void dfs(vector<int> arr[],int n)
{
	mark[n]=true;
	discovered[n]=low[n]=++timee;
	int child=0;
	for(int i=0;i<arr[n].size();i++)
	{  
        if(n!=arr[n][i])
        { 
          if(mark[arr[n][i]]==false)
          {  child++;
            parent[arr[n][i]]=n;
            dfs(arr,arr[n][i]);
            low[n]=min(low[n],low[arr[n][i]]);
            if(parent[n]==-1 && child>1)
             ap[n]=true;
            if(parent[n]!=-1 && low[arr[n][i]]>=discovered[n])
             ap[n]=true;
          }
          else if(parent[n]!=arr[n][i])
            low[n]=min(low[n],discovered[arr[n][i]]);
         }
   }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);    
      
     int nodes,edges;
     cin>>nodes>>edges;
     vector<int> arr[nodes+1];
     for(int i=1;i<=edges;i++)
     {
     	int a,b;
     	cin>>a>>b;
     	arr[a].push_back(b);
     	arr[b].push_back(a);
	   }
   
	 for(int i=1;i<=nodes;i++)
	  low[i]=INT_MAX;

    for(int i=1;i<=nodes;i++)
     {
      if(mark[i]==false)
         {
            parent[i]=-1;
            dfs(arr,i);
         }
	   }
	
    return 0;
}

/*
###########################################
bridging-edges
###########################################
*/


int discovered[100000],low[100000],mark[100000];

int timee=0;

vector<pair<int,int> > salman;

void dfs(vector<int> arr[],int n,int p)
{
	mark[n]=true;
	discovered[n]=low[n]=++timee;
	
	for(int i=0;i<arr[n].size();i++)
	{  
	    if(p==arr[n][i])
	    continue;
	    
	    if(mark[arr[n][i]]==false)
		{  
			dfs(arr,arr[n][i],n);
			low[n]=min(low[n],low[arr[n][i]]);
			if( low[arr[n][i]]>discovered[n])
			salman.push_back(make_pair(n,arr[n][i]));
		}
		else 
		 low[n]=min(low[n],discovered[arr[n][i]]);
       
    }
}

/*
###########################################
kruskal-algo
###########################################
*/

void init(int arr[],int n)
{
for(int i=0;i<n;i++)                            
	arr[i]=i;
}

int root(int arr[],int x)
{ 
   return arr[x]==x?arr[x]:arr[x]=root(arr,arr[x]);
}

void unionk(int arr[],int x,int y)
{
 if(x==y)
  return;
  
	arr[root(x)]=arr[root(y)];
}

int kruskal(vector<pair<int , pair<int,ll> > >&p ,int arr[])
{
  int e=p.size();
	ll mincost=0,cost,x,y;
	for(ll i=0;i<e;i++)
	{                                            
		x=p[i].first;
		y=p[i].second.first;
		cost=p[i].second.second;
		
		if(root(arr,x)!=root(arr,y))            
		{
			mincost+=cost;
			unionk(arr,x,y);
		}
	}
	
	return mincost;
}



bool comp(pair<int,pair<int,ll>> p1,pair<int,pair<int,ll>> p2)
{
   return p1.second.second<p2.second.second;
}

int main() 
{
 int n,e;
cin>>n;
cin>>e; 
ll arr[n];
vector<pair<int,pair<int,ll> > > p;                      
init(arr,n);  

                        
for(int i=0;i<e;i++)
{
 int x,y;
 ll z;
 
	cin>>x>>y>>z;                          
	p.push_back(make_pair(x,make_pair(y,z)));
}

sort(p.end(),p.begin(),comp);                  
ll min=kruskal(p,arr);

	return 0;
}


/*
###########################################
Dijkstra-algo
###########################################
*/

#define pair<int,int>P;
void dijkstra(vector<P > arr[],int x,int n)
{
	priority_queue<P,vector<P>,greater<P> > q;                  
	bool marked[n];
	int distance[n], prev[n];            
	
	for(ll i=0;i<n;i++)
	{
		distance[i]=INT_MAX;
		prev[i]=0;
		marked[i]=false;
	}
	
	distance[x]=0;
	
	q.push(make_pair(0,x));
	
	while(q.empty()==false)
	{
	  P	p=q.top();
		q.pop();
		x=p.second;
		
		if(marked[x]==true)                        
		continue;                                
		                        
		marked[x]=true;
		
		for(ll i=0;i<arr[x].size();i++)                               
		{
		    ll w=arr[x][i].first;
			  ll v=arr[x][i].second;
			
			if(distance[v]>w+distance[x])       
			{
				distance[v]=w+distance[x];
				q.push(make_pair(distance[v],v));                        
				prev[v]=x;
			}
			
		}
	}

}


