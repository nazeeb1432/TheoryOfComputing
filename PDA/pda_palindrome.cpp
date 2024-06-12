#include<bits/stdc++.h>
using namespace std;

#define z 'z' // z -> z0

int num_states, num_alphabets;
char x, current_state;
vector<char> states, alphabets, stack_alphabets;
stack<char> s;
vector<pair<string, pair<char, string>>> pda_transition_table;
char start_state, final_state;
string input;

void read_input();
void process_input();
void initialize_stack();
char pda(string input, char current_state);
void create_pda_transition_table();
char transition(char curr_symbol,char top_of_stack,char current_state);
bool is_accepted(char current_state);

int main(){

    read_input();   
    create_pda_transition_table(); 
    process_input();
    (is_accepted(current_state)) ? cout << "The string is accepted by the PDA" << endl : cout << "The string is not accepted by the PDA" << endl;

    return 0;
}

void read_input(){
    freopen("pda_pal.txt", "r", stdin);
    cin >> num_states >> num_alphabets;
    getchar();
    
    cout << "Number of States: " << num_states << endl << "Number of alphabets: " << num_alphabets << endl;
    
    for(int i = 0; i < num_states; ++i){
        cin >> x;
        states.push_back(x);
    }
    
    cout << "States: ";
    for(int i = 0; i < num_states; ++i){
        cout << states[i] << " ";
    }
    cout << endl;
    
    stack_alphabets.push_back(z);
    getchar();
    
    for(int i = 0; i < num_alphabets; ++i){
        cin >> x;
        alphabets.push_back(x);
        stack_alphabets.push_back(x); // z 0 1
    }
    stack_alphabets.pop_back(); // z 0
    
    cout << "Alphabets: ";
    for(int i = 0; i < num_alphabets; ++i){
        cout << alphabets[i] <<  " ";
    }
    
    initialize_stack();
    cout << endl;
    
    getchar();
    cin >> start_state >> final_state;
    getchar();
    
    cout << "Start State: " << start_state << endl << "Final State: " << final_state << endl;
    
    cin >> input;
    cout << "Input string: " << input << endl;    

}

void process_input(){
    current_state = start_state;// a
    cout << "At the start, Current State: " << current_state << endl;

    cout << "Transitions: " << endl;
    current_state = pda(input,current_state); // finally, curr_state,
    
    cout << "Current state after string traversal: ";
    cout << current_state << endl;
}

void initialize_stack(){
    s.push(z);
}

char pda(string input, char current_state){
    // cur_sym, top, curr_state -> transition
    char curr_symbol;
    for(int i = 0; i <= input.size(); ++i){
        if(i == input.size()/2 or i == input.size()) curr_symbol = 'e';
        else curr_symbol = input[i];
        char top_of_stack = s.top();
        cout << current_state << " --> ";
        current_state = transition(curr_symbol, top_of_stack,current_state); // transition
        cout << current_state << endl;
    }
    
    return current_state;
}

void create_pda_transition_table(){
    pda_transition_table.push_back({"a0z", {'a', "push"}});
    pda_transition_table.push_back({"a00", {'a', "push"}});
    pda_transition_table.push_back({"a01", {'a', "push"}});
    pda_transition_table.push_back({"aez", {'b', ""}});
    pda_transition_table.push_back({"ae0", {'b', ""}});
    pda_transition_table.push_back({"ae1", {'b', ""}});
    pda_transition_table.push_back({"b00", {'b', "pop"}});
    pda_transition_table.push_back({"b01", {'b', "pop"}});
    pda_transition_table.push_back({"b10", {'b', "pop"}});
    pda_transition_table.push_back({"b11", {'b', "pop"}});
    pda_transition_table.push_back({"bez", {'c', ""}});
    
}

char transition(char curr_symbol,char top_of_stack,char current_state){

/*
  state   symbol  stack  transition stack_operation
    a      0,1    z,0,1     a           push(sym)
    a       e       z       b           -------  
    a       e      0,1      b           ------- 
    b      0,1     0,1      b           pop
    b       e      z        c           -------
*/

/*
    0101e0e
s->z
t ->aabbbbc
*/
    string st = "";
    st.push_back(current_state);
    st.push_back(curr_symbol);
    st.push_back(top_of_stack);

    for(auto sp : pda_transition_table){
        if(sp.first == st){
            current_state = sp.second.first;
            if(sp.second.second == "push") s.push(curr_symbol);
            else if(sp.second.second == "pop") s.pop(); 
        }
    }

    return current_state;
}

bool is_accepted(char current_state){
    return (current_state == final_state and s.top() == z);
}