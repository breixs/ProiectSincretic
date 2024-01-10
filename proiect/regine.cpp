#include <iostream>
#include <vector>
#include <cstdlib>
#include <time.h>

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
                    cout<<s[i*8+j]<<" ";
                }
                cout<<endl;
            }
            cout<<endl;
            contor++;
        }
    }
    cout<<"Numarul de solutii gasite: "<<contor<<endl;
}

void afisareRandom(vector<vector<int>>& solutii, int t[8][8])
{
    srand(time(0));
    int random= rand() % 92;
    cout<<"solutia: "<<random<<endl;
    int contor=0;
    if(solutii.empty())
    {
        cout<<"nu exista solutii"<<endl;
    }
    else{
        for(auto& s: solutii)
        {
            if(contor==random)
            {
                for(int i=0;i<8;i++)
                {
                    for(int j=0;j<8;j++)
                    {
                        cout<<s[i*8+j]<<" ";
                    }
                cout<<endl;
                }
                cout<<endl;
            }
            contor++;
        }
    }
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
    int t[8][8], opt;
    bool ok=false;
    vector<vector<int>> solutii;
    creareTabla(t);
    rezolvare(solutii, t, 0);

    do{
        cout<<" - PROBLEMA REGINELOR - "<<endl;
        cout<<"1. Afiseaza toate solutiile problemei reginelor"<<endl;
        cout<<"2. Afiseaza o solutie aleatorie pentru problema reginelor"<<endl;
        cout<<"0. Iesire"<<endl;
        do{
            try{
                cout<<"Introduceti optiunea: ";
                cin>>opt;
                if(opt<0||opt>2||cin.fail())
                {
                    ok=false;
                    cin.clear();
                    cin.ignore();
                    throw(100);
                }
                else ok=true;
            }
            catch(int x)
            {
                cout<<"Optiune gresita, incercati alta optiune"<<endl;
            }
        }while(ok==false);
       switch(opt)
       {
            case 0:
            break;
            default:
            break;
            case 1:
            afisareTabla(solutii, t);
            break;
            case 2:
            afisareRandom(solutii, t);
            break;
       } 
    }while(opt!=0);

    return 0;
}