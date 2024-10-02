//#include <bits/stdc++.h>
//using namespace std;
#include<stdio.h>

/*string upperCase(string str)
{
    for (int i = 0; i < str.size();i++)
    {
        //if ((int)str[i] != 20)
        str[i] = toupper(str[i]);
    }
    return str;*
}
int main()
{
    string str;
    getline(cin,str);
    cout<<upperCase(str);
}*/
int main()
{
    char str[10000];
    int n=10000;
    fgets(str,10000,stdin);
    while(n!=0)
    {
    for(int i=0; str[i]!='\0'; i++)
    {
        if(str[i]>='a' && str[i]<='z')
        {
            str[i] = str[i]-32;
        }
    }
    }
    printf("%s",str);

    return 0;
}
