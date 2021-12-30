/* 1) Para evitar erros de digitação de sequencias de números de importância fundamental, como a matrícula de um aluno, o C.P.F. do Imposto de Renda, o número da conta bancária, geralmente se adiciona ao número um dígito verificador. Por exemplo, o número de matrícula 811057 é usado como 8110573, onde 3 é o dígito verificador calculado da seguinte maneira:
a)cada algarismo do número é multiplicado por um peso começando por 2 e crescendo de 1 da direita para a esquerda;
Exemplo: 8*7, 1*6, 1*5, 0*4, 5*3, 7*2
b)somam-se as parcelas obtidas;
Exemplo: 56 + 6 + 5 + 0 + 15 + 14 = 96
c)obtém-se o resto da divisão desta soma por 11;
Exemplo: 96 dividido por 11 dá resto 8.
d)subtrai-se de 11 o resto obtido;
Exemplo: 11 - 8 = 3
e)se o valor encontrado for 10 ou 11, o dígito verificador será 0, nos outros casos o dígito verificador é o próprio valor encontrado.
Escreva uma função que retorne o dígito verificador de um número inteiro.
2)Faça uma função que dado uma matriz real de ordem 10 x 10, retorne a localização (linha e a coluna) do menor e do maior valor.
Escreva um programa, com reprocessamento, que utilize as duas funções desenvolvidas. A leitura dos dados deve ser feita no programa principal, assim como a validação dos mesmos, quando necessário. A impressão dos resultados não deve ser feita dentro das funções, apenas no programa principal.*/
#include <stdio.h>
#define lin 10
#define col 10

void multVet(int num[], int tNum){
	int auxMult = 2;
	int i = tNum-1;

	for(i;i>=0;i--){
		num[i]*= ++auxMult;
	}
}

int somaVet(int num[], int tNum){
	int soma = 0;
	int i = 0;

	for(i;i<tNum;i++){
		soma+=num[i];
	}
	return soma;
}

int getResto(int num){
	return num % 11;
}

int getDigito(int num){
	if(num == 11 || num == 10){
		return 0;
	}
	else{
		return num;
	}
}


void printMatriz (float matriz[][col]) {
    int i, j;

    for (i=0;i<lin;i++){
        for (j=0;j<col;j++){
        	printf("%6.2f",matriz[i][j]);
        }
    printf("\n");
    }
}

void scanfMatriz(float matriz[][col], int *i_maior, int *j_maior, int *i_menor, int *j_menor){
	int i, j;
	float maior, menor;

    for (i=0;i<lin;i++){
		for (j=0;j<col;j++){
        scanf("%f", &matriz[i][j]);

    		if(j==0 && i==0){
    			menor=matriz[i][j];
    			maior=matriz[i][j];
				*i_menor = 0;
				*i_maior = 0;
				*j_maior = 0;
				*j_menor = 0;
			}

			if(matriz[i][j]>maior){
				maior = matriz[i][j];
				*i_maior = i;
				*j_maior = j;
			}

			if(matriz[i][j]<menor){
				menor = matriz[i][j];
				*i_menor = i;
				*j_menor = j;
			}
		}
	}
}

int main(){

	char resp1, resp2;

	printf("Questao 1");
	int tamanho = 0;

	do{

	do{
		printf("\n\nQuantos numeros deseja inserir? (3 digitos ou mais) ");
		scanf("%d", &tamanho);
	}while(tamanho<3); //validacao para ser digitado pelo menos 3 numeros

	printf("Insira o numero inteiro de identificacao (com espaco entre eles): ");

	int i=0, numero[tamanho];
	for(i;i<tamanho;i++){
		scanf("%d",&numero[i]);
	}

	multVet(numero, tamanho);
	int soma = somaVet(numero, tamanho);
	int resto = getResto(soma);
	int subResto = 11 - resto;
	int dig = getDigito(subResto);

	printf("O digito verificador eh %d", dig);

	//reprocessamento questao 1
	printf("\n\nDeseja executar novamente a questao 1(s/n)? ");
    do{
      resp1 = tolower(getche());
	}while(resp1!='n' && resp1!='s');

  	}while(resp1!='n');

	//2
	printf("\n\nQuestao 2");

	do{

	printf("\n\nInsira valores da matriz %d x %d:\n", lin, col);
	float matriz[lin][col];
	int i_maior, j_maior, i_menor, j_menor;
	scanfMatriz(matriz, &i_maior, &j_maior, &i_menor, &j_menor);
	printf("\nMatriz %d x %d:\n", lin, col);
    printMatriz(matriz);
	printf("\n\nMaior numero na posicao %d x %d (linha %d, coluna %d)\n", i_maior, j_maior, i_maior+1, j_maior+1);
	printf("Menor numero na posicao %d x %d (linha %d, coluna %d)", i_menor, j_menor, i_menor+1, j_menor+1);

	//reprocessamento questao 2
	printf("\n\nDeseja executar novamente a questao 2(s/n)? ");
	do{
      resp2 = tolower(getche());
	}while(resp2!='n' && resp2!='s');

  	}while(resp2!='n');

	return 0;
}
