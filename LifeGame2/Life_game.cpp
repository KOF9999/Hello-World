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
    FILE *Sourse=fopen("1.txt","r");
    if(NULL==Sourse)
    {
        cout<<"This file is not exist!!!"<<endl;
        return false;
    }
    while(!feof(Sourse))
    {
        memset(Cube[line],0,sizeof(Cube[line]));
        fgets(Cube[line],sizeof(Cube[line])-1,Sourse);
        line++;
    }
     fclose(Sourse);
    while(1)
    {
        row++;
        if(Cube[0][row]=='\0')
        {
            row=row-1;
            break;
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
 //==================打印到屏幕，对比结果=====================
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
 //====================================================

    for(numL=0;numL<line;numL++)
    {
         for(numR=0;numR<row;numR++)
        {
            if('1'==CubeCmp[numL][numR])
            {
                CubeCmp[numL][numR]='$';
            }
            else
            {
                CubeCmp[numL][numR]=' ';
            }
        }
    }
   cout<<"change times="<<times<<endl;
   FILE *Result=fopen("Result.txt","w");
   for(numL=0;numL<line;numL++)
   {
       fprintf(Result,"%s\n",CubeCmp[numL]);
   }
   fclose(Result);

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
