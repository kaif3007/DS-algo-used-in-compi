########################################################################
segment-tree
########################################################################

#include<bits/stdc++.h>
#define N 100005

using namespace std;

int arr[N];
int tree[4*N];

void build(int idx,int s,int e)
{
	if(s>e)
	return;
	if(s==e)
	{
		tree[idx]=arr[s];
		return;
	}
	int mid=(s+e)/2;
	build(2*idx+1,s,mid);
	build(2*idx+2,mid+1,e);
	
	int l=tree[2*idx+1];
	int r=tree[2*idx+2];
	tree[idx]=l+r ;      //merging function.
}

void update(int idx,int s,int e,int p,int v) //point update.
{
	if(s>e || p<s || p>e)
	 return;
	 if(s==e)
	 {
	 	tree[idx]=v;
	 	return;
	 }
	 
	 int mid=(s+e)/2;
	 update(2*idx+1,s,mid,p,v);
	 update(2*idx+2,mid+1,e,p,v);
	 int l=tree[2*idx+1];
	 int r=tree[2*idx+2];
	 tree[idx]=l+r;               //merging function
}

int query(int idx,int s,int e,int rs,int re)
{
	if(s>e || rs>e || re<s)
	  return 0;
    if(s>=rs && e<=re)
      return tree[idx];
      
    int mid=(s+e)/2;
    int l=query(2*idx+1,s,mid,rs,re);
    int r=query(2*idx+2,mid+1,e,rs,re);
    return l+r    ;     //merge function.
}

int main()
{
	
	return 0;
}

########################################################################
merge-sort-tree
########################################################################

#include<bits/stdc++.h>
#define N 1000001
#define ll long long int
using namespace std;

vector<int> tree[1200005];
int pre[300003],suff[300003];

void built(int idx,int s,int e)
{
	 if(s==e)
	 {
	 	tree[idx]=vector<int>(1,suff[e]);
	 	return;
	 }
	 else
	 {
	 	int mid=(s+e)/2;
	 	built(2*idx+1,s,mid);
	 	built(2*idx+2,mid+1,e);
	 	merge(tree[2*idx+1].begin(),tree[2*idx+1].end(),tree[2*idx+2].begin(),tree[2*idx+2].end(),
	    back_inserter(tree[idx]));
	 }
}

int query(int idx,int ql,int qr,int l,int r,int val)
{
      if(l>r || ql>r || qr<l)
	     return 0;
	  
	  if(l>=ql && r<=qr)
	  return upper_bound(tree[idx].begin(),tree[idx].end(),val)-tree[idx].begin();
	  
	  int mid=(l+r)/2;
	  return query(2*idx+1,ql,qr,l,mid,val)+query(2*idx+2,ql,qr,mid+1,r,val);
}


int main()
{

	return 0;
}

