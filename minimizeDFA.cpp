#include<bits/stdc++.h>
#define max 100
#define CROSS 1
#define EQUAL 0
using namespace std;

int num_states,states[max], num_symbols,alphabet[max], start_state, final_state, transition_table[max][max]; 
int distinguishability_table[max][max],equivalent_states[max], minimum_state_dfa_table[max][max];


void print_equavilent_states(int size)
{
    cout << "Equivalent states are : \n";
    bool flag = true;
    for(int i = 1; i <= size; i++)
    {
        for(int j = 0; j < i; j++)
        {
            if(distinguishability_table[i][j]==0)
            {
                cout << "" << transition_table[i][0] <<"=" << transition_table[j][0] << "\n";
                flag = false;
            }
        }
    }

    if(flag)
    {
        cout << "No equivalent state path_way!\n";
    }
}

int main(){

    freopen("minimize_dfa.txt", "r", stdin);
    cin >> num_states;
    states[num_states];
    for(int i = 0; i < num_states; ++i) cin >> states[i];
    cin >> num_symbols;
    alphabet[num_symbols];
    for(int i = 0; i < num_symbols; ++i) cin >> alphabet[i];

    cin >> start_state;
    cin >> final_state;
    
    transition_table[num_states][num_symbols];
    for(int i = 0; i < num_states; ++i){
        for(int j = 0; j < num_symbols; ++j){
            cin >> transition_table[i][j];
        }
    }

    //init distinguishability_table
    for(int i = 1; i < num_states; ++i){
        for(int j = 0; j < i; ++j){
            if(i == final_state or j == final_state){
                distinguishability_table[i][j] = CROSS;
            }
        }
    }

    // for(int k = 0; k < 2; ++k){
    //     for(int i = 0; i < num_states; ++i){
    //         for(int j = 0; j < num_symbols; ++j){
    //             if()
    //         }    
    //     }
    // }

    for(int i = 1; i < num_states; ++i){
        for(int j = 0; j < i; ++j){
            if((transition_table[i][0] == final_state and transition_table[j][0] != final_state) or (transition_table[i][0] != final_state and transition_table[j][0] == final_state)){
                distinguishability_table[i][j] = CROSS;
            }else if((transition_table[i][1] == final_state and transition_table[j][1] != final_state) or (transition_table[i][1] != final_state and transition_table[j][1] == final_state)){
                distinguishability_table[i][j] = CROSS;
            }else if((transition_table[transition_table[i][0]][0] == final_state and transition_table[transition_table[j][0]][0] != final_state) or (transition_table[transition_table[i][0]][0] != final_state and transition_table[transition_table[j][0]][0] == final_state)){
                distinguishability_table[i][j] = CROSS;
            }else if((transition_table[transition_table[i][0]][1] == final_state and transition_table[transition_table[j][0]][1] != final_state) or (transition_table[transition_table[i][0]][1] != final_state and transition_table[transition_table[j][0]][1] == final_state)){
                distinguishability_table[i][j] = CROSS;
            }else if((transition_table[transition_table[i][1]][0] == final_state and transition_table[transition_table[j][1]][0] != final_state) or (transition_table[transition_table[i][1]][0] != final_state and transition_table[transition_table[j][1]][0] == final_state)){
                distinguishability_table[i][j] = CROSS;
            }else if((transition_table[transition_table[i][1]][1] == final_state and transition_table[transition_table[j][1]][1] != final_state) or (transition_table[transition_table[i][1]][1] != final_state and transition_table[transition_table[j][1]][1] == final_state)){
                distinguishability_table[i][j] = CROSS;
            }
        }
    }
    equivalent_states[num_states];
    for(int i = 1; i < num_states; ++i){
        for(int j = 0; j < i; ++j){
            if(distinguishability_table[i][j] == 0) equivalent_states[i] = i;
            (distinguishability_table[i][j] == 0) ? cout << "=" << " " : cout << "x" << " ";
        }
        cout << endl;
    }

    /*
        A = G // 0 = 6
        B = F // 1 = 5
        C = E // 2 = 4
    */
    minimum_state_dfa_table[num_states][num_symbols];
    for(int i = 0; i < num_states; ++i){
        for(int j = 0; j < num_symbols; ++j){
            for(int k = 0; k < num_states; ++k){
                if(i == equivalent_states[k]){
                    minimum_state_dfa_table[i][j] = -1;
                }else minimum_state_dfa_table[i][j] = transition_table[i][j];
            }
        }
    }

    for(int i = 0; i < num_states; ++i){
        for(int j = 0; j < num_symbols; ++j){
            cout << minimum_state_dfa_table[i][j] << " ";
        }
        cout << endl;
    }

    print_equavilent_states(num_states);

    

    return 0;
}