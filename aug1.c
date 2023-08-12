#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>


char setOfStates[3],alphabet[2],transition[3][3],S,F,input[100],cur_state;

bool dfa_accept(){
    
    int k = 0;
    while(input[k] != '\0'){
        
        bool flag = false;
        
        if(input[k] == '0'){
            for(int i = 0; i< 3; ++i){
                for(int j = 0; j < 3; ++j){
                    if(transition[i][0] == cur_state){
                        cur_state = transition[i][1];
                        printf("C.S:%c\n", cur_state);
                        flag = true;
                        break;
                    }
                }
                
                if(flag) break;
            }
            
            k++;
            
        }else{
            for(int i = 0; i< 3; ++i){
                for(int j = 0; j < 3; ++j){
                    if(transition[i][0] == cur_state){
                        cur_state = transition[i][2];
                        printf("C.S:%c\n", cur_state);
                        flag = true;
                        break;
                    }
                }
                if(flag) break;
            }
            k++;
        }    
    }
    
    return (cur_state == F);
    
}

int main(){

    printf("Enter set of states:\n");
    for(int i=0;i<3;i++){
        scanf("%c",&setOfStates[i]);
        getchar();
    }

    printf("Symbols of the alphabet:\n");
    for(int i=0;i<2;i++){
        scanf("%c",&alphabet[i]);
        getchar();
    }

    printf("Enter transition table:\n");
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            scanf("%c",&transition[i][j]);
            getchar();
        }
    }

    printf("Enter start state and final state:\n");
    scanf("%c %c",&S,&F);
    getchar();

    printf("Enter the input string:");
    scanf("%s",input);
    getchar();


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