#include<stdio.h>
#include<string.h>
#include <iostream>
using namespace std;

int find_substr(string a,string b)
{
    int i=0,j=0;
    while(i<a.size() && j<b.size())
    {
        if(a[i]!=b[j])
        {
            i=0;
        }
        else
        {
            i++;
            j++;
        }
    }
    if(i==a.size())
        return 1;
    else
        return -1;
}
int main()
{
    string a,b;
    cin>>a>>b;
    // find_substr(a,b);
    printf("%d\n",find_substr(a,b));
    return 0;
}