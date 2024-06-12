#include<bits/stdc++.h>
using namespace std;

#define max_State 20
int Ninput;



char input[10];
string DFA[max_State][10];
string Final_States[max_State];
char Table[max_State][max_State];

void print_Table(int n)
{
    cout<<"Table using Table filling Algorithm\n    ";
    for(int i=1; i<n; i++)
        cout<<DFA[i][0]<<"  ";
    cout<<"\n--------------";
    for(int i =1; i <= n; i++)
    {
        if(i>1)
            cout<<DFA[i][0]<<" | ";
        for(int j = 1; j < i; j++)
        {
            cout<<Table[i][j]<<"  ";
        }
        cout<<endl;
    }
    cout<<"\n\n";
}

void initial_Table()
{
    for(int i = 0; i < max_State; i++)
    {
        for(int j = 0; j < max_State; j++)
        {
            Table[i][j] = '=';
        }
    }
}
bool isFinal_State(string str, int size)
{
    for(int i = 1; i <= size; i++)
    {
        if(Final_States[i] == str)
            return true;
    }
    return false;
}

int findDFA(string str, int size)
{
    for(int i = 1; i <= size; i++)
    {
        if(DFA[i][0] == str)
            return i;
    }
    return -1;
}


void Dfa_Minimization(int numOfStates)
{
    for(int i = 1; i <= numOfStates; i++)
    {
        for(int j = 1; j < i; j++)
        {
            if(isFinal_State(DFA[i][0], numOfStates) && !isFinal_State(DFA[j][0], numOfStates))
            {
                Table[i][j] = 'x';
            }
            else if(!isFinal_State(DFA[i][0], numOfStates) && isFinal_State(DFA[j][0], numOfStates))
            {
                Table[i][j] = 'x';
            }
        }
    }

    bool check = true;
    while(check)
    {
        check= false;
        for(int i = 1; i <= numOfStates; i++)
        {
            for(int j = 1; j < i; j++)
            {
                if(Table[i][j]=='=')
                {
                    int row_state, col_state;

                    for(int input=1; input<=Ninput; input++)
                    {
                        row_state = findDFA(DFA[i][input],numOfStates);
                        col_state= findDFA(DFA[j][input],numOfStates);

                        if(Table[row_state][col_state] =='x')
                        {
                            Table[i][j] = 'x';
                            check = true;
                        }
                    }
                }
            }
        }
    }
}

void print_equavilent_states(int size)
{
    cout << "Equivalent states are : \n";
    bool flag = true;
    for(int i = 1; i <= size; i++)
    {
        for(int j = 1; j < i; j++)
        {
            if(Table[i][j]=='=')
            {
                cout << "" << DFA[i][0] <<"=" << DFA[j][0] << "\n";
                flag = false;
            }
        }
    }

    if(flag)
    {
        cout << "No equivalent state path_way!\n";
    }
}
int main()
{
    int numOfStates;
    printf("Enter Number of Input\n");
    cin>>Ninput;
    printf("Enter inputes\n");
    for(int i=1; i<=Ninput; i++)
        cin>>input[i];
    cin >> numOfStates;
    for(int i = 1; i <= numOfStates; i++)
    {
        for(int j=0; j<=Ninput; j++)
            cin >> DFA[i][j];
    }


    int numOfFinalstate;
    cin >> numOfFinalstate;
    for(int i = 1; i <= numOfFinalstate; i++)
    {
        cin >> Final_States[i];
    }


    initial_Table();
    Dfa_Minimization(numOfStates);
    print_Table(numOfStates);
    print_equavilent_states(numOfStates);

    return 0;
}

/*
2
0 1
5
A B C
B B D
C B C
D B E
E B C
1
E


*/