#include<bits/stdc++.h>
using namespace std;
bool can_put(int i,int j,int n,vector<vector<char>>&board)
{
    int x,y;
    x=i,y=j;
    
    //major diagonal
    while(x>=0 and y>=0)
     if(board[x][y]=='q')
      return false;
     else
      x--,y--;
    
    x=i,y=j;
    //vertical line
    while(x>=0)
     if(board[x][y]=='q')
      return false;
     else
      x--;
    
    // minor diagonal
    while(x>=0 and y<n)
     if(board[x][y]=='q')
      return false;
     else
      x--,y++;
    
    return true;

}
void print_possible_chess_board(int i,int &n,vector<vector<char>>&board,bool &flag)
{
    //base case
    if(i==n)
    {
        flag=true;
        return;
    }
    for(int j=0;j<n;j++)
     if(can_put(i,j,n,board))
     {
        board[i][j]='q';
        print_possible_chess_board(i+1,n,board,flag);
        if(flag)
         return;
        
        board[i][j]='.'; // important step in backtracking
     }
}
int main()
{  
   int n;
   cin>>n;
   vector<vector<char>> board(n,vector<char>(n,'.'));
   bool flag=false;
   print_possible_chess_board(0,n,board,flag);
   if(flag)
    for(int i=0;i<n;i++)
     {
        for(int j=0;j<n;j++)
         cout<<board[i][j]<<" ";
        cout<<endl;
     }
    else
     cout<<"NO"<<endl;
    return 0;
}
