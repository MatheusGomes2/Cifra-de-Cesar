#include <stdio.h>
#include <stdlib.h>

void msnDecifrada(char *decifrada){
    FILE *arq2;

    arq2 = fopen("output.txt","w");
    fprintf(arq2, "%s", decifrada);

    fclose(arq2);

}
char **insereMatriz(int n){

    int i;
    char **m = (char**) malloc(n * sizeof(char*));

    for(i=0;i<n;i++){
        m[i] = (char*) malloc(n * sizeof(char));
    }

    return m;
}

int main(){

    FILE *arq;
    char Arquivo[]= "input.txt", a, *vet, **m, *decifrada, aux;
    int tamanho, i, j, mult, aux1 = 0, aux2 = 0;

    arq = fopen(Arquivo,"r"); // Abrir o arquivo
    if(arq == NULL){       //Confere
        printf("Erro");
        return 1;
    }
     while(fscanf(arq, "%c", &a) != EOF){ //Tamanho
        tamanho++;
    }
    rewind(arq);

    for(i=0;i<tamanho;i++){ // Raiz do tamanho
        if(i*i == tamanho){
           mult = i;
        }
    }
    vet = malloc(tamanho * sizeof(char)); //Alocação do vetor
    decifrada = malloc(tamanho * sizeof(char)); //Alocação do vetor resposta
    m = insereMatriz(mult); //função para alocar matriz

    while(fscanf(arq,"%c",&aux) != EOF){  //Ler e passar os caracteres do arquivo para o vetor
        vet[aux1] = aux;
        aux1++;
    }
    fclose(arq);//Fecha o arquivo

    for(i=0;i<mult;i++){   //Passa os caracteres para uma matriz na forma transposta
        for(j=0;j<mult;j++){
            m[j][i] = vet[aux2];
            aux2++;
        }
    }
    aux1=0;
    for(i=0;i<mult;i++){      //Passa a mensagem já decifrada para o vetor resposta
        for(j=0;j<mult;j++){
            if(m[i][j] != '*'){
                decifrada[aux1] = m[i][j];
                aux1++;
            }
        }
        decifrada[aux1]=' ';
        aux1++;
    }
    decifrada[aux1] = '\0';

    for(i=0;i<mult;i++){
        free(m[i]);
    }
    free(m);
    free(vet);

    msnDecifrada(decifrada); //Função para escrever a mensagem decifrada no arquivo de saída

    free(decifrada);

    return 0;
}
