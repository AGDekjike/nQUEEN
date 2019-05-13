#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;

int READ_TEXT_SIZE(char *filename,int SIZE)//READ TEXT SIZE
{
    ifstream file;
    file.open(filename,ios::in);
    file>>SIZE;
    return SIZE;
}

void READ_TEXT(char *filename,int a[])//READ FILE
{
    int i=0;
    int SIZE;
    ifstream file;
    file.open(filename,ios::in);
    file>>SIZE;
    while(!file.eof()&&i<SIZE)
    {
        file>>a[i];
        i++;
    }
}

int VALIDATE(int i,int Q[],int m)//TO JUDGE IF THE PLACE TO INSERT IS PERMITTABLE
{
    if(Q[i]>=m)
    {
        return -1;
    }
    else if(i==0)
    {
        return Q[i];
    }
    else
    {
        for(int k=0;k<i;k++)
        {
            if(Q[k]==Q[i] || abs(i-k)==abs(Q[i]-Q[k]))
            {
                Q[i]++;
                return VALIDATE(i,Q,m);
            }
        }
    }
    return Q[i];
}

int MOVE(int Q[],int m,int n,int j)//FROM LINE TO LINE TO PLACE THE QUEEN
{
    ofstream ANSWER;
    ANSWER.open("D:\\ANSWER",ios::app);
    int i=0;
L:  while(i<m)
    {
        int e=VALIDATE(i,Q,m);
        if(e==-1)
        {
            Q[i]=0;
            i--;
            if(i<0 && j==0)
            {
                return -1;
            }
            else if(i<0 && j!=0)
            {
                return 1;
            }
            Q[i]++;
        }
        else
        {
            i++;
        }
    }
    int s=0;
    if(j==0)
    {
        ANSWER<<m<<"\n";
    }
    for(int k=0;k<m;k++)
    {
        ANSWER<<Q[k]<<" ";
        s=s+Q[k];
    }
    ANSWER<<"\n";
    j++;
    if(s<m*(m-1))
    {
        i--;
        Q[i]=0;
        i--;
        Q[i]++;
        goto L;
    }
}

int main()
{
    cout<<"PLEASE INDICATE YOUR FILE'S LOCATION:\n";
    char filename[100];
    cin>>filename;
    int SIZE=READ_TEXT_SIZE(filename,100);
    int a[SIZE];
    READ_TEXT(filename,a);
    ofstream ANSWER;
    ANSWER.open("D:\\ANSWER",ios::app);
    for(int n=0;n<SIZE;n++)
    {
        int m=a[n];
        int j=0;
        int Q[m]={0};
        int e=MOVE(Q,m,n,j);
        if(e==-1)
        {
            ANSWER<<"NO SOLUTION!";
        }
    }
    getchar();getchar();
}
