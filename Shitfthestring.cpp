#include<iostream>
#include<cstring>
using namespace std;
//using KMP
struct {
    int len;
    int Idx;
}var;
int posJ(int i,int j,string s,string t,int arr[])
{   
    j=arr[j];
    if(s[i]==t[j+1])
    {  if(var.len<j+1)
           {  
               var.len=j+1;
               var.Idx=i-(j+1);
           }      
      return j+1;
    }
      else if(j==-1)
       return -1;
    return posJ(i,j,s,t,arr);
}
void KMP(string s,string t)
{ 
    //t in s
    //t may have repeating subststrings
    int lt=t.length();
    int ls=s.length();

    int arr[lt+1];
    memset(arr,-1,sizeof(arr));
    int j=0;
    for(int i=1;i<lt;i++)
     if(t[i]==t[j])
      {
          
          arr[i]=j;
          j++;
      }
      else
      j=0;
    
   var.Idx=ls;var.len=0;
   int i=0;
   j=-1;
   for(i=0;i<ls;i++)
   { 
       if(s[i]==t[j+1])
        { if(var.len<j+1)
           {
               var.len=j+1;
               var.Idx=i-(j+1);
           }
           j++;
        }    
       else if(j!=-1)
        {   if(i>=lt)
            break;
            j=posJ(i,j,s,t,arr);
        }
       if(j==lt-1)
       break;
    }
  
}
int main()
{   int N;
    string t,s;
    cin>>N;
    cin>>t>>s;
    s=s.append(s);
    KMP(s,t);
    cout<<var.Idx<<endl; 
    return 0;
}