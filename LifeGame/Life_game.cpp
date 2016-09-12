#include<iostream>
#include<stdio.h>
using namespace std;
#define maxLine 20
#define maxRow 20
char Cube[maxLine][maxRow];
char CubeCmp[maxLine][maxRow];
int line,row;
int numL,numR;
int Round;
char CellStatus(char origincube,int round);
int main()
{
    cin>>line>>row;
    if(line>maxLine||row>maxRow)
       {
           cout<<"log:too big"<<endl;
           return false;
       }
    for(numL=0;numL<line;numL++)
    {
         for(numR=0;numR<row;numR++)
        {
            cin>>Cube[numL][numR];
        }
    }


    for(numL=0;numL<line;numL++)
    {
         for(numR=0;numR<row;numR++)
        {
            if(0==numL&&0==numR)
            {
                Round=0;
                Round=Cube[0][1]+Cube[1][0]+Cube[1][1]-48*3;
                CubeCmp[numL][numR]=CellStatus(Cube[numL][numR],Round);
            }
            if(0==numL&&0!=numR&&(row-1)!=numR)
            {
                Round=0;
                Round=Cube[numL][numR-1]+Cube[numL][numR+1]+Cube[numL+1][numR-1]+Cube[numL+1][numR]+Cube[numL+1][numR+1]-48*5;
                CubeCmp[numL][numR]=CellStatus(Cube[numL][numR],Round);
            }
            if(0==numL&&(row-1)==numR)
            {
                Round=0;
                Round=Cube[numL][numR-1]+Cube[numL+1][numR-1]+Cube[numL+1][numR]-48*3;
                CubeCmp[numL][numR]=CellStatus(Cube[numL][numR],Round);
            }
            if(0!=numL&&(line-1)!=numL&&0==numR)
            {
                Round=0;
                Round=Cube[numL-1][numR]+Cube[numL-1][numR+1]+Cube[numL][numR+1]+Cube[numL+1][numR]+Cube[numL+1][numR+1]-48*5;
                CubeCmp[numL][numR]=CellStatus(Cube[numL][numR],Round);
            }
            if((line-1)==numL&&0==numR)
            {
                Round=0;
                Round=Cube[numL-1][numR]+Cube[numL-1][numR+1]+Cube[numL][numR+1]-48*3;
                CubeCmp[numL][numR]=CellStatus(Cube[numL][numR],Round);
            }
            if((line-1)==numL&&0!=numR&&(row-1)!=numR)
            {
                Round=0;
                Round=Cube[numL-1][numR-1]+Cube[numL-1][numR]+Cube[numL-1][numR+1]+Cube[numL][numR-1]+Cube[numL][numR+1]-48*5;
                CubeCmp[numL][numR]=CellStatus(Cube[numL][numR],Round);
            }
            if((line-1)==numL&&(row-1)==numR)
            {
                Round=0;
                Round=Cube[numL-1][numR-1]+Cube[numL-1][numR]+Cube[numL][numR-1]-48*3;
                CubeCmp[numL][numR]=CellStatus(Cube[numL][numR],Round);
            }
            if((line-1)!=numL&&0!=numL&&(row-1)==numR)
            {
                Round=0;
                Round=Cube[numL-1][numR-1]+Cube[numL-1][numR]+Cube[numL][numR-1]+Cube[numL+1][numR-1]+Cube[numL+1][numR]-48*5;
                CubeCmp[numL][numR]=CellStatus(Cube[numL][numR],Round);
            }
            else
            {
                Round=0;
                Round=Cube[numL-1][numR-1]+Cube[numL-1][numR]+Cube[numL-1][numR+1]+Cube[numL][numR-1]+Cube[numL][numR+1]+Cube[numL+1][numR-1]+Cube[numL+1][numR]+Cube[numL+1][numR+1]-48*8;
                CubeCmp[numL][numR]=CellStatus(Cube[numL][numR],Round);
            }
        }
    }


    for(numL=0;numL<line;numL++)
    {
         for(numR=0;numR<row;numR++)
        {
            cout<<CubeCmp[numL][numR];
            if ((row-1) == numR)
            {
                cout<<endl;
            }
        }
    }


    return 0;
}
char CellStatus(char origincube,int round)
{
    char newcube=origincube;
     if(origincube=='0'&&3==round)
    {
        newcube='1';
    }
    if(origincube=='1'&&(round<2||round>3))
    {
        newcube='0';
    }
    return newcube;
}
