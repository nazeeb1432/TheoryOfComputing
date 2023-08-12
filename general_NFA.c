#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

bool result=false;
char input[100];
int len;
int store_state[100];
int path=0;

#define STATE_MAX 26
#define SYMBOL_MAX 20

char states[STATE_MAX],alphabet[SYMBOL_MAX],transition_table[STATE_MAX][SYMBOL_MAX][STATE_MAX],initial_state,final_state;
int num_transitions[STATE_MAX][SYMBOL_MAX];

void state_upgrade(int index){
   if(index ==len && initial_state==final_state){
    result=true;
    return;
   }
   if(index==len && initial_state!=final_state){
        return;
   }
   state_upgrade(index+1);

}

int main(){

    int num_of_states,num_of_symbol;

    printf("Enter the number of states:");
    scanf("%d",&num_of_states);

    printf("Enter number of symbol:");
    scanf("%d",&num_of_symbol);

    getchar();

    //redeclare
    states[num_of_states],alphabet[num_of_symbol],transition_table[num_of_states][num_of_symbol][num_of_states],initial_state,final_state;

    for(int i=0;i<num_of_states;i++){
        printf("Enter %d state:",i+1);
        scanf("%c",&states[i]);
        getchar();
    }

    printf("\n\n");

    for(int i=0;i<num_of_symbol;++i){
        printf("Enter %d symbol of the alphabet:",i+1);
        scanf("%c",&alphabet[i]);
        getchar();
    }

    printf("\n");
    printf("Enter initial state:");
    scanf("%c",&initial_state);
    printf("\n");
    printf("Enter final state:");
    scanf("%c",&final_state);

    for(int i=0;i<num_of_states;i++){
        for(int j=0;j<num_of_symbol;j++){
            for(int k=0;k<num_of_states;k++){
                transition_table[i][j][k] ='*';
            }
        }
    }

     num_transitions[num_of_states][num_of_symbol];

    //taking input in transition table
    for(int i=0;i<num_of_states;i++){
        printf("For %c: \n",states[i]);
            for(int j=0;j<num_of_symbol;j++){
                printf("If the symbol is %c,How many transitions?:",alphabet[j]);
                scanf("%d",&num_transitions[i][j]);
                getchar();
                for(int k=0;k<num_transitions[i][j];k++){
                    scanf("%c",transition_table[i][j][k]);
                    getchar();
                }
            }
    }

    printf("\nEnter input string:");
    scanf("%s",input);
    len=strlen(input);

    state_upgrade(0);
    if(result){
        printf("Accepted");
    }
    else{
        printf("Rejected");
    }



    return 0;
}