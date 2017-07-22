#include<stdio.h>
int fast_pow(long long base, long long n,long long M)
{
    if(n==0)
       return 1;
    if(n==1)
    return base;
    long long halfn=fast_pow(base,n/2,M);
    if(n%2==0)
        return ( halfn * halfn ) % M;
    else
        return ( ( ( halfn * halfn ) % M ) * base ) % M;
}
int findMMI_fermat(int n,int M)
{
    return fast_pow(n,M-2,M);
}
int main()
{
    long long fact[100001];
    fact[0]=1;
    int i=1;
    int MOD=1000000007;
    while(i<=100000)
    {
        fact[i]=(fact[i-1]*i)%MOD;
        i++;
    }
    
        int n,k;
        
        scanf("%d%d",&n,&k);
        if(k%2!=0)
        {
        	k=k-1;
		}
		
         long long numerator,denominator,mmi_denominator,ans=0;
        for(i=0;i<=k;i=i+2)
       
        //I declared these variable as long long so that there is no need to use explicit typecasting
     {   numerator=fact[n];
        denominator=(fact[i]*fact[n-i])%MOD;
        mmi_denominator=findMMI_fermat(denominator,MOD);
        ans=ans+(numerator*mmi_denominator)%MOD;
        
    }
    printf("%lld\n",ans);
    return 0;
}
