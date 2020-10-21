/*
#######################
kmp
#######################
*/
vector<int> lps(string & pat)
{
   vector<int> v(pat.length(),0);
   for(int i=1;i<pat.length();i++)
   {
   	  int j=v[i-1];
   	  while(j>0 && pat[j]!=pat[i])
   	    j=v[j-1];
   	    
   	    if(pat[i]==pat[j])
   	     j++;
   	    
   	    v[i]=j;
   }
   return v;
}

/*
#######################
z-algorithm
#######################
*/


void zstring(string &s,int z[])
{
	int n=s.length();
	int l=0,r=0;
    memset(z,0,sizeof(z));
    
    for(int i=1;i<n;i++)
    {
    	if(i<=r)
    	z[i]=min(r-i+1,z[i-l]);
    	
    	while(i+z[i]<n && s[z[i]]==s[z[i]+i])
    	 z[i]++;
    	 
    	 if(r<i+z[i]-1)
    	 {
    	 	l=i;
    	 	r=i+z[i]-1;
		   }
	}
}


/*
#######################
manachar algo
#######################
*/

string convert(string& s1)
{
string kaif="@";

for(int i=0;i<s1.length();i++)
kaif+=("#"+s1.substr(i,1));         

kaif+="#@";
return kaif;
}                           

int manachar(string& s)
{ 
string kaif=convert(s);
int p[kaif.length()]={0};
int c=0,r=0;

for(int i=1;i<kaif.length()-1;i++)
{
	int mirror=c-(i-c);
	
	if(i<r)
	  p[i]=min(r-i,p[mirror]);              
	  
	while(kaif[i+1+p[i]]==kaif[i-1-p[i]])
	p[i]++;                                         
	
	if(i+p[i]>r)
	{
		c=i;                          
		r=i+p[i];
	}
	
}


