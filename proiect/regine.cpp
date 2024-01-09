#include <iostream>
#include <string>

using namespace std;

void creareTabala(int t[8][8])
{
    int i, j;
     for(i=0;i<8;i++)
        for(j=0;j<8;j++)
           t[i][j]=0;
}

void afisareTabla(int t[8][8])
{
    int i, j;
    for(i=0;i<8;i++)
    {
        for(j=0;j<8;j++)
            cout<<t[i][j];
        cout<<endl;
    }
}

int main()
{
    int t[8][8];
    creareTabala(t);
    afisareTabla(t);
    return 0;
}