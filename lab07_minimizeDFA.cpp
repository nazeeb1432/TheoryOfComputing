#include<bits/stdc++.h>
#define max 100
#define CROSS 1
#define EQUAL 0
using namespace std;

int num_states,states[max], num_symbols,alphabet[max], start_state, final_state, transition_table[max][max]; 
int distinguishability_table[max][max],equivalent_states[max], minimum_state_dfa_table[max][max];
set<pair<int, int>> st; 
vector<vector<int>> min_dfa;
map<int,pair<int, int>> minimized_dfa;

int main(){

    freopen("lab07_minimizaDFA.txt", "r", stdin);
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

    cout << "Given DFA : "<< endl;
    for(int i = 0; i < num_states; ++i){
        printf("%c -->" , i + 'A');
        for(int j = 0; j < num_symbols; ++j){
            printf(" %c ", transition_table[i][j] + 'A');
        }
        cout << endl;
    }

    cout << endl;

    //init distinguishability_table
    for(int i = 1; i < num_states; ++i){
        for(int j = 0; j < i; ++j){
            if(i == final_state or j == final_state){
                distinguishability_table[i][j] = CROSS;
            }
        }
    }
/*                                              METHOD-01                                     */
    for(int k = 0; k < 3; ++k){
        for(int i = 0; i < num_states; ++i){
            for(int j = 0; j < num_states; ++j){
                int transitionUsingZero_i = transition_table[i][0];
                int transitionUsingZero_j = transition_table[j][0];
                int transitionUsingOne_i = transition_table[i][1];
                int transitionUsingOne_j = transition_table[j][1]; 
                if(distinguishability_table[transitionUsingZero_i][transitionUsingZero_j] ==  CROSS){
                    distinguishability_table[i][j] = CROSS;
                }else if(distinguishability_table[transitionUsingOne_i][transitionUsingOne_j] ==  CROSS){
                    distinguishability_table[i][j] = CROSS;
                }
            }    
        }
    }

    equivalent_states[num_states];
    
    for(int i = 1; i < num_states; ++i){
        printf("%c ", i + 'A');
        for(int j = 0; j < i; ++j){
            if(distinguishability_table[i][j] == EQUAL){
                equivalent_states[i] = i;
                st.insert({j,i});
            }   
            (distinguishability_table[i][j] == EQUAL) ? cout << "=" << " " : cout << "X" << " ";
        }
        cout << endl;
    }
    printf("  ");
    for(int i = 0; i < num_states - 1 ; ++i) printf("%c ", i + 'A');
    cout << endl;
    /*
        A = G // 0 = 6
        B = F // 1 = 5
        C = E // 2 = 4
    */
    cout << "Eq States:" << endl;
    // for(int i = 0; i < num_states; ++i){
    //     cout << equivalent_states[i] << " ";
    // }   
    // cout << endl; 
    

    /*
       { {A,G}, {B,F}, {C,E} }
    */

    for(auto s : st){
        printf("%c = %c\n",s.first+'A', s.second+'A');
    }

    minimum_state_dfa_table[num_states][num_symbols];

    min_dfa.resize(num_states, vector<int> (num_symbols));
    
    for(int i = 0; i < num_states; ++i){
        for(int j = 0; j < num_symbols; ++j){
            minimum_state_dfa_table[i][j] = transition_table[i][j];
            for(int k = 0; k < num_states; ++k){
                if(i == equivalent_states[k] and i != start_state){
                    minimum_state_dfa_table[i][j] = -1;
                }
            }
        }
    }

    for(int i = 0; i < num_states; ++i){
        for(int j = 0; j < num_symbols; ++j){
            for(auto s: st)
                if(minimum_state_dfa_table[i][j] == s.second){
                    minimum_state_dfa_table[i][j] = s.first;
                }
        }
    }    
    
    cout << "MIN DFA TABLE" << endl;

    for(int i = 0; i < num_states; ++i){
        int x,y;
        for(int j = 0; j < num_symbols; ++j){
            if(minimum_state_dfa_table[i][j] != -1){
                x = minimum_state_dfa_table[i][j];// row , 0
                y = minimum_state_dfa_table[i][j+1];//row, 1
                j++; 
                minimized_dfa.insert({i,{x,y}});
            }
        }
    }

    for(auto s : minimized_dfa){
        printf("%c %c %c\n", s.first+'A' , s.second.first+'A', s.second.second+'A');
    }
    return 0;
}