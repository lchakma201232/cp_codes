#include<bits/stdc++.h>
using namespace std;
int check(int a, int k )
{
    if(a<=k)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int main()
{
    // There are n pillars. Given a number x find the largest pi

    int n,k;   // n = total pillars       k = selected pillar

    cin>>n>>k;

    int lowestPillar = 1, higgestPillar = n;

    while(lowestPillar < higgestPillar && lowestPillar!=k)
    {
        if(check((lowestPillar+higgestPillar)/2,k))
        {
            lowestPillar=(lowestPillar+higgestPillar)/2;
        }
        else
        {
            higgestPillar=(lowestPillar+higgestPillar)/2;
        }
    }

    cout<<lowestPillar;

    return 0;
}