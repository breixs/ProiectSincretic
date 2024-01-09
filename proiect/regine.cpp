#include <iostream>
#include <vector>

using namespace std;

void creareTabla(int t[8][8])
{
    int i, j;
     for(i=0;i<8;i++)
        for(j=0;j<8;j++)
           t[i][j]=0;
}

void afisareTabla(vector<vector<int>>& solutii, int t[8][8])
{
    int contor=0;
    if(solutii.empty())
    {
        cout<<"nu exista solutii"<<endl;
    }
    else{
        for(auto& s: solutii)
        {
            for(int i=0;i<8;i++)
            {
                for(int j=0;j<8;j++)
                {
                    cout<<s[i*8+j];
                }
                cout<<endl;
            }
            cout<<endl;
            contor++;
        }
    }

    cout<<"Numarul de solutii gasite: "<<contor;
}

bool esteValid(int t[8][8], int rand, int col)
{
    int i, j;
    for(i=0;i<col;i++)
    {
        if(t[rand][i]==1)
            return false;
    }
    for(i=rand, j=col;i>=0&&j>=0;i--,j--)
    {
        if(t[i][j]==1)
        return false;
    }
    for(i=rand, j=col; j>=0&&i<8;i++,j--)
    {
        if(t[i][j]==1)
        return false;
    }
    return true;
}

void rezolvare(vector<vector<int>>& solutii, int t[8][8], int col) 
{ 
    int i, j;
    if(col>=8)//daca s-au parcurs toate coloanele
    {
        vector<int> sol;
        for(i=0;i<8;i++)
        {
            for(j=0;j<8;j++)
            {
                sol.push_back(t[i][j]);
            }
        }
        solutii.push_back(sol);
        return;
    }
    for(i=0;i<8;i++)
    {
        if(esteValid(t,i,col))
        {
            t[i][col]=1;
            rezolvare(solutii, t, col+1);
            t[i][col]=0;
        }
    }
} 

int main()
{
    int t[8][8], contor=0;
    vector<vector<int>> solutii;
    creareTabla(t);

    rezolvare(solutii, t, 0);
    afisareTabla(solutii, t);

    return 0;
}