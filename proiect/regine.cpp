#include <iostream>
#include <string>

using namespace std;

void creareTabla(int t[8][8])
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

bool esteValid(int t[8][8], int rand, int col)
{
    int i, j;
    for(i=0;i<col;i++)
    {
        if(t[rand][i])
            return false;
    }
    for(i=rand, j=col;i>=0&&j>=0;i--,j--)
    {
        if(t[rand][col])
        return false;
    }
    for(i=rand, j=col; j>=0&&i<8;i++,j--)
    {
        if(t[i][j])
        return false;
    }
    return true;
}

bool rezolvare(int t[8][8], int col) 
{ 
    if (col >= 8) 
        return true; 
    for (int i = 0; i < 8; i++) { 
        if (esteValid(t, i, col)) { 
            t[i][col] = 1; 
            if (rezolvare(t, col + 1)) 
                return true; 
            t[i][col] = 0; 
        } 
    } 
    return false; 
} 


int main()
{
    int t[8][8];
    creareTabla(t);

    if (rezolvare(t, 0) == false) { 
        printf("Solution does not exist"); 
        return 0; 
    } 

    afisareTabla(t);
    return true;

    return 0;
}