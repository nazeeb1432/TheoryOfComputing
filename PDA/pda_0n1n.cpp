#include<bits/stdc++.h>
using namespace std;

#define z 'z' // z -> z0
    
/*
  state   symbol  stack  transition stack_operation
    a       0       z        a         push(0)
    a       0       0        a         push(0)
    a       1       0        b         pop(0)
    b       1       0        b         pop(0)
    b       0       0        b         pop(0)
    b      eps(e)   z        c         do nothing        
*/

/*
    0011e
s->z
t ->aabbc          
*/                    

/*
    0011e
while 0, push, stay at state a
once 1, start popping, move to state b
e -> b-> c

    0011e
s->z
t ->aabbc
*/

int num_states, num_alphabets;
char x, current_state;
vector<char> states, alphabets, stack_alphabets;
stack<char> s;
char start_state, final_state;
string input;

void read_input();
void process_input();
void initialize_stack();
char pda(string input, char current_state);
char transition(char curr_symbol,char top_of_stack,char current_state);
bool is_accepted(char current_state);

int main(){

    read_input();    
    process_input();
    (is_accepted(current_state)) ? cout << "The string is accepted by the PDA" << endl : cout << "The string is not accepted by the PDA" << endl;

    return 0;
}

void read_input(){
    freopen("pda_0n1n.txt", "r", stdin);
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
    for(int i = 0; i < input.size(); ++i){
        char curr_symbol = input[i];
        char top_of_stack = s.top();
        cout << current_state << " --> ";
        current_state = transition(curr_symbol, top_of_stack,current_state); // transition
        cout << current_state << endl;
        if(current_state == 'b' and top_of_stack == z) break; //
    }
    
    return current_state;
}

char transition(char curr_symbol,char top_of_stack,char current_state){
    
    if(curr_symbol == '0' and top_of_stack == z and current_state == 'a'){
        current_state = 'a';
        s.push(curr_symbol);
    }else if(curr_symbol == '0' and top_of_stack == '0' and current_state == 'a'){
        current_state = 'a';
        s.push(curr_symbol);   
    }else if(curr_symbol == '1' and top_of_stack == '0' and current_state == 'a'){
        current_state = 'b';
        s.pop();   
    }else if(curr_symbol == '1' and top_of_stack == '0' and current_state == 'b'){
        current_state = 'b';
        s.pop();   
    }else if(curr_symbol == '0' and top_of_stack == z and current_state == 'b'){
        current_state = 'b';
        s.pop(); 
    }else if(curr_symbol == 'e' and top_of_stack == z and current_state == 'b'){
        current_state = 'c';   
    }

    return current_state;
}

bool is_accepted(char current_state){
    return (current_state == final_state and s.top() == z);
}