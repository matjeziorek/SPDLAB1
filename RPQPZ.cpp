#include <cstdlib>
#include<iostream>
#include<fstream>
#include<string.h>
#include<conio.h>
#include<algorithm>

using namespace std;
int iloscPermutacji=0;
int RPQ[4][3] = {{1,2,3},{4,5,6},{7,8,9},{5,2,8}};

int max(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}

void swap(int x, int y)
{
    int temp = RPQ[x][0];
    int tmp = RPQ[x][1];
    int tmp1 = RPQ[x][2];
    RPQ[x][0] = RPQ[y][0];
    RPQ[x][1] = RPQ[y][1];
    RPQ[x][2] = RPQ[y][2];
    RPQ[y][0]=temp;
    RPQ[y][1]=tmp;
    RPQ[y][2]=tmp1;


    return;
}

void printRPQ(int size)
{
    int i;
    cout<<"Permutacja nr: "<<iloscPermutacji+1<<endl;
    for (i=0; i<size; i++)
    {
        cout << RPQ[i][0] << ":"<< RPQ[i][1]<< ":"<<RPQ[i][2]<<endl;

    }
    iloscPermutacji++;
    cout << endl;

    return;
}

void C_max()
{
    int t = 0;
    int c_max = 0;

    for (int i = 0; i < 4; i++)
    {
        t = max(RPQ[i][0], t) + RPQ[i][1];
        c_max = max(c_max,t+RPQ[i][2]);
    }
    cout << "C_max " << c_max << " t:" << t << endl<<endl;
}


void permute(int k,int size)
{


    int i;

    if (k==0)
    {
        printRPQ(size);
        C_max();


    }

    else
    {

        for (i=k-1; i>=0; i--)
        {

            swap(i,k-1);
            permute(k-1,size);
            swap(i,k-1);


        }


    }


    return;
}

int main()
{

    permute(4,4);


    return 0;
}

