#include<bits/stdc++.h>
using namespace std;

#define z 'z'

int num_states, num_alphabets;
char x, current_state;
vector<char> states, alphabets, stack_alphabets;
stack<char> s;
char start_state, final_state;
string input;

char pda(string input, char current_state);
char transition(char curr_symbol,char top_of_stack,char current_state);
bool is_accepted(char current_state);

int main(){

    freopen("pda.txt", "r", stdin);
    /*
        state symbol stack transition  stack_op
        a       0       z0    a         push(0)
        a       0       0     a         push(0)
        a       1       0     b         pop(0)
        b       1       0     b         pop(0)
        b       epsilon z0    c         nothing        
          
    */
    cin >> num_states >> num_alphabets;

    getchar();

    cout << num_states << "   " << num_alphabets << endl;
    
    for(int i = 0; i < num_states; ++i){
        cin >> x;
        states.push_back(x);
    }

    for(int i = 0; i < num_states; ++i){
        cout << states[i] << " ";
    }
    cout << endl;

    stack_alphabets.push_back(z);

    getchar();
    
    for(int i = 0; i < num_alphabets; ++i){
        cin >> x;
        alphabets.push_back(x);
        stack_alphabets.push_back(x);
    }

    for(int i = 0; i < num_alphabets; ++i){
        cout << alphabets[i] <<  " ";
    }
    s.push(z);
    cout << endl;

    getchar();

    cin >> start_state >> final_state;
    
    getchar();
    
    cout << start_state << " " << final_state << endl;

    cin >> input;

    cout << "Input : " << input << endl;    
    
    current_state = start_state;
    cout << current_state << endl;
    current_state = pda(input,current_state);
    cout << current_state << endl;
    (is_accepted(current_state)) ? cout << "The string is accepted by the PDA" << endl : cout << "The string is not accepted by the PDA" << endl;

    return 0;
}

char pda(string input, char current_state){
    
    for(int i = 0; i < input.size(); ++i){
        char curr_symbol = input[i];
        //cout << curr_symbol << endl;
        char top_of_stack = s.top();
        //cout << top_of_stack << endl;
        cout << current_state << " --> ";
        current_state = transition(curr_symbol, top_of_stack,current_state);
        cout << current_state << endl;
        // if(current_state == 'd') return 'd';
    }
    return current_state;
}


char transition(char curr_symbol,char top_of_stack,char current_state){
    //cout << "TESTING" << endl;
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
    }else if(curr_symbol == '0' and top_of_stack == '0' and current_state == 'b'){
        current_state = 'b';
        s.pop();
        // return 'd';   
    }else if(curr_symbol == 'e' and top_of_stack == z and current_state == 'b'){
        current_state = 'c';   
    }

    return current_state;
}

bool is_accepted(char current_state){
    return (current_state == final_state and s.top() == z);
}