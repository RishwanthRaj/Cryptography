#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int inverse(int a)
{
    int inv;
    for(int i=1; i<62; i++)
    {
        if(((a*i)%62)==1)
        {
            inv = i;
            break;
        }
    }
    return inv;
}
vector<int> toVec(string s)
{
    vector <int> a;
    int l=s.length();
    int z;
    for(int i=0; i<l; i++)
    {
        z=(int)(s[i]);
        if(z>=65 && z<=90)
        {
            z=z-65;
        }
        else if(z>=97 && z<=122)
        {
            z=z-71;
        }
        else if(z>=48 && z<=57)
        {
            z=z+4;
        }
        a.push_back(z);
    }
    return a;
}
string to_String(vector <int> a)
{
    string s="";
    char c;
    int y;
    int d;
    for(int i=0; i<a.size(); i++)
    {
        if(a[i]>=0 && a[i]<=25)
            d=a[i]+65;
        else if(a[i]>=26 && a[i]<=51)
            d=a[i]+71;
        else if(a[i]>=52 && a[i]<=61)
            d=a[i]-4;
        c=(char)d;
        s=s+c;
    }
    return s;
}
string encrypt(int a,int b,string s)
{
    vector <int> x;
    vector <int> y;
    int d;
    x=toVec(s);
    string s1="";
    for(int i=0; i<x.size(); i++)
    {
        d=(a*x[i]+b)%62;
        y.push_back(d);
    }
    s1=to_String(y);
    return s1;
}
string decrypt(int a,int b,string s)
{
    vector <int> x;
    vector <int> y;
    int d;
    x=toVec(s);
    string s1="";
    for(int i=0; i<x.size(); i++)
    {
        int z;
        if(x[i]-b<0)
            z=62+x[i]-b;
        else
            z=x[i]-b;
        d=(inverse(a)*(z))%62;
        y.push_back(d);
    }
    s1=to_String(y);
    return s1;
}
void attack(string c,string p)
{
    for(int i=0;i<61;i++)
    {
        for(int j=0;j<61;j++)
        {
            if(decrypt(i,j,c)==p)
            {
                cout<<"("<<i<<","<<j<<")"<<endl;
                cout<<"plain text : "<<p<<endl;
                cout<<"key inverse : "<<"("<<inverse(i)<<","<<inverse(j)<<")";
                break;
            }
        }
    }

}
int main()
{
    int a,c,b;
    fstream file;
    string s,s1,p,c1,word;
    string filename = "plaintext.txt";
    cout<<"1.encrypt  2.decrypt  3.attack?"<<endl;
    cin>>c;
    if(c==1)
    {
        cout<<"enter the string"<<endl;
        cin>>s;
        cout<<"enter the key"<<endl;
        cin>>a;
        while(__gcd(a,62)!=1)
        {
            cout<<"enter a valid key";
            cin>>a;
        }
        cin>>b;
        s1=encrypt(a,b,s);
        cout<<endl;
        cout<<"encrypted string :"<<endl;
        cout<<s1;
    }
    else if(c==2)
    {
        cout<<"enter the string"<<endl;
        cin>>s;
        cout<<"enter the key"<<endl;
        cin>>a;
        while(__gcd(a,62)!=1)
        {
            cout<<"enter a valid key";
            cin>>a;
        }
        cin>>b;
        s1=decrypt(a,b,s);
        cout<<endl;
        cout<<"decrypted string :"<<endl;
        cout<<s1;
    }
    else
    {
        cout<<"enter the cipher text"<<endl;
        cin>>c1;
        file.open(filename.c_str());
        cout<<"key value";
        while (file >> word)
        {
            attack(c1,word);
        }
    }
}

