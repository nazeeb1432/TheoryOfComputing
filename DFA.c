#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#define max 100

char setOfStates[max],symbols[max],transition[max][max],S,F,input[max],cur_state;
int num_states,num_symbols;

bool dfa_accept(){
    
    int k = 0;
    while(input[k] != '\0'){
        
        // bool flag = false;
        
        if(input[k] == '0'){
            for(int i = 0; i< num_states; ++i){
                
                    if(setOfStates[i]== cur_state){
                        cur_state = transition[i][0];
                        printf("C.S:%c\n", cur_state);
                        // flag = true;
                        break;
                    }
                
                
                // if(flag) break;
            }
            
            
            
        }else{
            for(int i = 0; i< num_states; ++i){
               
                    if(setOfStates[i] == cur_state){
                        cur_state = transition[i][1];
                        printf("C.S:%c\n", cur_state);
                        // flag = true;
                        break;
                    }
                
                // if(flag) break;
            }
            
        }
        k++;    
    }
    
    return (cur_state == F);
    
}

int main(){

    freopen("DFA.txt", "r", stdin);

    printf("Enter number of states and symbols:");
    scanf("%d %d",&num_states,&num_symbols);

    transition[num_states][num_symbols];

    printf("Enter set of states:\n");
    for(int i=0;i<num_states;i++){
        getchar();
        scanf("%c",&setOfStates[i]);
        
    }

    printf("Symbols of the alphabet:\n");
    for(int i=0;i<num_symbols;i++){
        getchar();
        scanf("%c",&symbols[i]);
        
    }
    /*
        0 1
    a   b a
    b   b c
    c   b a
    */

    printf("Enter transition table:\n");
    for(int i=0;i<num_states;i++){
        for(int j=0;j<num_symbols;j++){
             getchar();
            scanf("%c",&transition[i][j]);                     
        }
    }

    for(int i=0;i<num_states;i++){
        for(int j=0;j<num_symbols;j++){
           printf("%c ",transition[i][j]);          
        } printf("\n");
    }

    printf("Enter start state and final state:\n");
    getchar();
    scanf("%c %c",&S,&F);
    

    printf("Enter the input string:\n");
    getchar();
    scanf("%s",input);
    

    int count=0,i=0,flag=1;
    while(input[i]!='\0'){
        count++;
        i++;
    }
    for(int i=0;i<count;i++){
        if(input[i]!='1' && input[i]!='0'){
            flag=0;
        }
    }
    if(flag==1){
        cur_state=S;
        bool b=dfa_accept();
        if(b){
            printf("Accepted\n");
        }
        else{
            printf("Rejected\n");
        }
    }
    else{
        printf("Not in language\n");
    }





   





    return 0;
}