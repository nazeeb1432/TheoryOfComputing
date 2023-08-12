#include<stdio.h>
#include<stdbool.h>
#include<string.h>
bool result = false;
char input_string[100];
int len;
int p = 0;
int store[100];
char looping;
void stateUpgrade(int num_states,int num_symbol,char *setofstate,char *alphabet,char initialstate,char finalstate,char transition[num_states][num_symbol][10],int num_transition[num_states][num_symbol],int index){
    if(index==len && initialstate == finalstate){
        result = true;
        store[p++] = initialstate;
        for(int j=0; j<p; j++)printf("%c ",store[j]);
        printf("\n");
        return;
    }
    if(index==len && initialstate != finalstate){
        p--;
        looping = initialstate;
        return;
    }
    int i;
    for(i=0; i<num_symbol; i++){
        if(alphabet[i]==input_string[index])break;
    }
    if(num_transition[initialstate-'a'][i]==0)return;
    int k=0;
    store[p++] = initialstate;
    while(k<num_transition[initialstate-'a'][i] && !result){
        stateUpgrade(num_states,num_symbol,setofstate,alphabet,transition[initialstate-'a'][i][k],finalstate,transition,num_transition,index+1);
        k++;
    }
    return;
}
int main(){
    int num_states,num_symbol,num_final;
    printf("Enter the number of states: ");
    scanf("%d",&num_states);
    printf("Enter the number of symbol in alphabet: ");
    scanf("%d",&num_symbol);
    printf("Enter the number of final state: ");
    scanf("%d",&num_final);
    getchar();
    char set_of_state[num_states],alphabet[num_symbol],initial_state,final_states[num_final],transition_table[num_states][num_symbol][10],steps[100];
    for(int i=0; i<num_states; i++){
        printf("Enter %dth state: ",i+1);
        scanf("%c",&set_of_state[i]);
        getchar();
    }
    printf("\n\n");
    for(int i=0; i<num_symbol; i++){
        printf("Enter %dth symbol of alphabet: ",i+1);
        scanf("%c",&alphabet[i]);
        getchar();
    }
    printf("Enter the initial state: ");
    scanf("%c",&initial_state);
    getchar();
    for(int i=0; i<num_final; i++){
        printf("Enter %dth final state: ",i+1);
        scanf("%c",&final_states[i]);
        getchar();
    }
    for(int i=0; i<num_states; i++){
        for(int j=0; j<num_symbol; j++){
            for(int k=0; k<10; k++){
                transition_table[i][j][k] = '*';
            }
        }
    }
    int num_transition[num_states][num_symbol];
    for(int i=0; i<num_states; i++){
        printf("For %c: \n",set_of_state[i]);
        for(int j=0; j<num_symbol; j++){
            printf("If the input is %c : \n",alphabet[j]);
            printf("How many transition? : ");
            scanf("%d",&num_transition[i][j]);
            getchar();
            for(int k=0; k<num_transition[i][j]; k++){
                scanf("%c",&transition_table[i][j][k]);
                getchar();
            }
        }
    }
    printf("Enter the string: ");
    scanf("%s",input_string);
    len = strlen(input_string);
    stateUpgrade(num_states,num_symbol,set_of_state,alphabet,initial_state,final_states[0],transition_table,num_transition,0);
    if(result)printf("Accepted\n");
    else printf("Rejected because looping in %c\n",looping);
    return 0;
}