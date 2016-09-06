#include<iostream>
using namespace std;
#define maxLine 20
#define maxRow 20
int Cube[maxLine][maxRow];
int line,row;
int numL,numR;
int main()
{
    cin>>line>>row;
    if(line>maxLine||row>maxRow)
       {
           cout<<"log:too big"<<endl;
           return false;
       }
    for(numL=0;numL<line;numL++)
        for(numR=0;numR<row;numR++)
        {
            cin>>Cube[numL][numR];
        }

    return 0;
}
