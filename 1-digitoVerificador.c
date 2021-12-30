#include <stdio.h>

void multiVector(int number[], int sizeNumber){
	int auxMult = 2;
	int i = sizeNumber-1;
	for(i; i >=0; i--){
		number[i]*= ++auxMult;
	} 
} 

int somaVet(int number[], int sizeNumber){
	int soma = 0;
	int i = 0;
	for(i; i < sizeNumber; i++){
		soma+= number[i];
	}
	return soma;
}

int getResto(int number){
	return number % 11;
}

int getId(int number){
	if(number == 11 || number == 10){
		return 0;
	}else{
		return number;
	}
}
int main(){
	/*Utilizando vetor*/
	int sizeNumber = 0;
	printf("Quantos numeros deseja inserir? ");
	scanf("%d", &sizeNumber);
	int number[sizeNumber];
	int i=0;
	printf("Insira o numero inteiro (com espaco entre eles): ");
	for(i; i < sizeNumber; i++){
		scanf("%d",&number[i]);
	}

	/*Utilizando inteiro*/
	/*int numberInt;
	scanf("%d", &numberInt);
	int modulo = 10;
	while(numberInt % modulo != numberInt){
		sizeNumber++;
		modulo*=10;
	}
	sizeNumber++;
	int number[sizeNumber];
	for(int i = sizeNumber - 1; i >= 0; i--){
		number[i] = numberInt % 10;
		numberInt /= 10;
	}*/

	multiVector(number, sizeNumber);
	int soma = somaVet(number, sizeNumber);
	int resto = getResto(soma);
	int subResto = 11 - resto;
	int id = getId(subResto);
	printf("O digito verificador eh %d", id);
	return 0;
}
