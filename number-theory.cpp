/*
###################
Totient-function
###################
*/


//  no. of numbers before n having gcd d with it if phi[n/d];   very very important;

long long int phi[10000];

void totient(long long int n)
{
	
	for(int i=0;i<=n;i++)
	phi[i]=i;
	
	for(int i=2;i<=n;i++)
	{
		if(phi[i]==i)
		{
			for(int j=i;j<=n;j+=i)
			phi[j]=(phi[j]/i)*(i-1);
		}
	}
}

/*
################
seive-algorithm
################
*/

bool isprime[10000000];

void seive(long int n)
{
	for(int i=0;i<=n;i++)
	isprime[i]=true;

isprime[0]=false;
isprime[1]=false;

for(int i=2;i*i<=n;++i)
{
	if(isprime[i]==true)
	{
		for(int j=i*i;j<=n;j+=i)
		isprime[j]=false;
	}
}
}

/*
################
segmented-seive-algorithm
################
*/


vector<ll> segmented(ll l,ll r)
{
       vector<bool> prime(r-l+1,true);
       long long int p=sqrt(r);

       for(ll i=2;i*i<=p;i++)
       {
       	  for(ll j=max(i*i,(l+i-1)/(i*i));j<=r;j+=i)
       	  	prime[j-l]=true;
       }

       if(l==1)
       	prime[0]=false;

       vector<long long int > sol;
       for(int i=l;i<=r;i++)
       	 if(prime[i-l])
       	 	sol.push_back(i);
          
          return sol;
}


/*
################
Factorise
################
*/



int minprime[10000000];

void makemodified()
{
	for(int i=2;i*i<=10000000;i++)
	{
		if(minprime[i]==0)
		{
			for(int j=i*i;j<=10000000;j+=i)
			if(minprime[j]==0)
			minprime[j]=i;
		}
	}
	
	for(int i=0;i<=10000000;i++)
	if(minprime[i]==0)
	minprime[i]=i;
}

set<ll> factorise(ll n)
{
	set<ll> salman;
	while(n!=1)
	{
		salman.insert(minprime[n]);
		n/=minprime[n];
	}
	
	return salman;
}

vector<ll> singlefactorise(ll a)
{
	vector<ll> salman;
	for(int i=2;i*i<=a;i++)
	{
		while(a%i==0)
		{
			salman.push_back(i);
			a/=i;
		}
		
	
	}
	
		if(a!=1)
		salman.push_back(a);
		
		return salman;
}


/*
################
Extended-euclid
################
*/


pair< ll,pair<ll,ll> >  extendedeuclid(ll a,ll b)
{
	pair<ll,pair<ll,ll> > p,q;
	if(b==0)
	{
		p.first=a;
		p.second.first=1;
		p.second.second=0;
		return p;
	}

	    p=extendedeuclid(b,a%b);
	    q.first=p.first;
		q.second.first=p.second.second;
		q.second.second=p.second.first-(a/b)*p.second.second;
	    return q;
}


