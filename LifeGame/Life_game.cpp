#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
#define maxLine 100
#define maxRow 100
char Cube[maxLine][maxRow];
char CubeCmp[maxLine][maxRow];
int line,row;
int numL,numR;
int Round;
int times;
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

 while(1)
 {

    for(numL=0;numL<line;numL++)
    {
         for(numR=0;numR<row;numR++)
        {
            if(0==numL&&0==numR)
            {
                Round=0;
                Round=Cube[0][1]+Cube[1][0]+Cube[1][1]-48*3;
                CubeCmp[numL][numR]=CellStatus(Cube[numL][numR],Round);
                continue;
            }
            if(0==numL&&0!=numR&&(row-1)!=numR)
            {
                Round=0;
                Round=Cube[numL][numR-1]+Cube[numL][numR+1]+Cube[numL+1][numR-1]+Cube[numL+1][numR]+Cube[numL+1][numR+1]-48*5;
                CubeCmp[numL][numR]=CellStatus(Cube[numL][numR],Round);
                continue;
            }
            if(0==numL&&(row-1)==numR)
            {
                Round=0;
                Round=Cube[numL][numR-1]+Cube[numL+1][numR-1]+Cube[numL+1][numR]-48*3;
                CubeCmp[numL][numR]=CellStatus(Cube[numL][numR],Round);
                continue;
            }
            if(0!=numL&&(line-1)!=numL&&0==numR)
            {
                Round=0;
                Round=Cube[numL-1][numR]+Cube[numL-1][numR+1]+Cube[numL][numR+1]+Cube[numL+1][numR]+Cube[numL+1][numR+1]-48*5;
                CubeCmp[numL][numR]=CellStatus(Cube[numL][numR],Round);
                continue;
            }
            if((line-1)==numL&&0==numR)
            {
                Round=0;
                Round=Cube[numL-1][numR]+Cube[numL-1][numR+1]+Cube[numL][numR+1]-48*3;
                CubeCmp[numL][numR]=CellStatus(Cube[numL][numR],Round);
                continue;
            }
            if((line-1)==numL&&0!=numR&&(row-1)!=numR)
            {
                Round=0;
                Round=Cube[numL-1][numR-1]+Cube[numL-1][numR]+Cube[numL-1][numR+1]+Cube[numL][numR-1]+Cube[numL][numR+1]-48*5;
                CubeCmp[numL][numR]=CellStatus(Cube[numL][numR],Round);
                continue;
            }
            if((line-1)==numL&&(row-1)==numR)
            {
                Round=0;
                Round=Cube[numL-1][numR-1]+Cube[numL-1][numR]+Cube[numL][numR-1]-48*3;
                CubeCmp[numL][numR]=CellStatus(Cube[numL][numR],Round);
                continue;
            }
            if((line-1)!=numL&&0!=numL&&(row-1)==numR)
            {
                Round=0;
                Round=Cube[numL-1][numR-1]+Cube[numL-1][numR]+Cube[numL][numR-1]+Cube[numL+1][numR-1]+Cube[numL+1][numR]-48*5;
                CubeCmp[numL][numR]=CellStatus(Cube[numL][numR],Round);
                continue;
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
    if(strcmp(Cube[numL],CubeCmp[numL])!=0)
        {
            break;
        }
    }
    if(numL==line)
    {
        break;
    }
    else
    {
        for(numL=0;numL<line;numL++)
        {
            strcpy(Cube[numL],CubeCmp[numL]);
        }
    }
    times++;
 }

    for(numL=0;numL<line;numL++)
    {
         for(numR=0;numR<row;numR++)
        {
            if('1'==CubeCmp[numL][numR])
            {
                cout<<"$";
            }
            else
            {
                cout<<" ";
            }

            if ((row-1) == numR)
            {
                cout<<endl;
            }
        }
    }
   cout<<"change times="<<times<<endl;

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
