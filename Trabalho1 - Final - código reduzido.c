#include <stdio.h>
#include <math.h>
 
//Seno, cosseno, tangente
double Seno(double angulo){
	return sin(angulo);
}

double Cosseno(double angulo){
	return cos(angulo);
}

double Tangente(double angulo){
	return tan(angulo);
}

//Secante, Cossecante, Cotangente
double Secante(double angulo){
	return 1/(cos(angulo));
}

double Cossecante(double angulo){
	return 1/(sin(angulo));
}

double Cotangente(double angulo){ 
	return 1/(tan(angulo));
}

// Arcos
double ArcoSeno(double angulo){
	return asin(angulo);
}

double ArcoCosseno(double angulo){
	return acos(angulo);
}

double ArcoTangente(double angulo){
	return atan(angulo);
}

int main(){

int resposta_razao, resposta_unidade;
char confirmacao_razao, novocalculo;
double angulo;	

//Opcoes razoes trigonometricas c/ reprocessamento 
	do{
	
	do{
  	printf("\n--------------CALCULADORA TRIGONOMETRICA--------------\n\nInsira o numero conforme razao trigonometrica desejada\n1 - Seno\n2 - Cosseno\n3 - Tangente\n4 - Secante\n5 - Cossecante\n6 - Cotangente\n7 - Arco seno\n8 - Arco cosseno\n9 - Arco tangente\n0 - Sair\n\nOpcao: ");
  	scanf("%d%*c", &resposta_razao);
		if(resposta_razao==0){
  			return 0;
		}
		
			if (resposta_razao<0 || resposta_razao>9){
  				printf("\nOpcao invalida. Deseja tentar novamente? (s/n) ");
  				scanf("%c%*c", &confirmacao_razao);
  					if(confirmacao_razao=='N' || confirmacao_razao=='n' ){
  						return 0;
					}
			} 

//Opcoes unidade de medida c/ reprocessamento				
		switch(resposta_razao){

			case 1: 
			printf("\nRazao trigonometrica escolhida: *Seno*");
			printf("\n\nInsira o numero correspondente a unidade de medida desejada para entrada e saida\n1 - Graus\n2 - Radianos\n\nOpcao: ");
	
				do{
					scanf("%d", &resposta_unidade);
					if(resposta_unidade==1){
						printf("\nDigite o angulo em graus: ");
						scanf("%lf", &angulo);
						printf("Seno de %.5lf graus = %.5lf\n", angulo, Seno(angulo * M_PI / 180));
					}
					else if(resposta_unidade==2){
						printf("\nDigite o angulo em rad: ");
						scanf("%lf", &angulo);
						printf("Seno de %.5lf rad = %.5lf\n", angulo, Seno(angulo));	
					} 
					else 
						printf("\nOpcao invalida. Digite novamente: ");
				}while(resposta_unidade!=1 && resposta_unidade!=2);
				
			break;
			
			case 2: 
			printf("\nRazao trigonometrica escolhida: *Cosseno*");
			printf("\n\nInsira o numero correspondente a unidade de medida desejada para entrada e saida\n1 - Graus\n2 - Radianos\n\nOpcao: ");
			
				do{
					scanf("%d", &resposta_unidade);
					if(resposta_unidade==1){
						printf("\nDigite o angulo em graus: ");
						scanf("%lf", &angulo);
						printf("Cosseno de %.5lf graus = %.5lf\n", angulo, Cosseno(angulo * M_PI / 180));
					}
					else if(resposta_unidade==2){
						printf("\nDigite o angulo em rad: ");
						scanf("%lf", &angulo);	
						printf("Cosseno de %.5lf rad = %.5lf\n", angulo, Cosseno(angulo));
					} 
					else 
						printf("\nOpcao invalida. Digite novamente: ");
				}while(resposta_unidade!=1 && resposta_unidade!=2);
			
			break;
					
			case 3: 
			printf("\nRazao trigonometrica escolhida: *Tangente*");
			printf("\n\nInsira o numero correspondente a unidade de medida desejada para entrada e saida\n1 - Graus\n2 - Radianos\n\nOpcao: ");
			
				do{
					scanf("%d", &resposta_unidade);
					if(resposta_unidade==1){
						printf("\nDigite o angulo em graus: ");
						scanf("%lf", &angulo);
						if(fabs(Tangente(angulo * M_PI / 180))>57.2900)
						printf("Valor inserido muito proximo de 90 graus, o qual nao ha existencia de tangente. Comece o calculo novamente");
						else
						printf("Tangente de %.5lf graus = %.5lf\n", angulo, Tangente(angulo * M_PI / 180));
					}
					else if(resposta_unidade==2){
						printf("\nDigite o angulo em rad: ");
						scanf("%lf", &angulo);
						if(fabs(Tangente(angulo))>57.2900)
						printf("Valor inserido muito proximo de 90 graus, o qual nao ha existencia de tangente. Comece o calculo novamente");
						else
						printf("Tangente de %.5lf rad = %.5lf\n", angulo, Tangente(angulo));
					}
					else 
						printf("\nOpcao invalida. Digite novamente: ");
				}while(resposta_unidade!=1 && resposta_unidade!=2);
			
			break;	
			
			case 4: 
			printf("\nRazao trigonometrica escolhida: *Secante*");
			printf("\n\nInsira o numero correspondente a unidade de medida desejada para entrada e saida\n1 - Graus\n2 - Radianos\n\nOpcao: ");
			
				do{
					scanf("%d", &resposta_unidade);
					if(resposta_unidade==1){
						printf("\nDigite o angulo em graus: ");
						scanf("%lf", &angulo);
						if(angulo==90 || angulo==270)
						printf("Nao ha secante no angulo inserido. Comece o calculo novamente.");
						else
						printf("Secante de %.5lf graus = %.5lf\n", angulo, Secante(angulo * M_PI / 180));
					}
					else if(resposta_unidade==2){
						printf("\nDigite o angulo em rad: ");
						scanf("%lf", &angulo);
						if((angulo*M_PI/180)==90 || (angulo*M_PI/180)==270)
						printf("Nao ha secante no angulo inserido. Comece o calculo novamente.");
						else
						printf("Secante de %.5lf rad = %.5lf\n", angulo, Secante(angulo));
					} 
					else 
						printf("\nOpcao invalida. Digite novamente: ");
				}while(resposta_unidade!=1 && resposta_unidade!=2);
			
			break;	
			
			case 5: 
			printf("\nRazao trigonometrica escolhida: *Cossecante*");
			printf("\n\nInsira o numero correspondente a unidade de medida desejada para entrada e saida\n1 - Graus\n2 - Radianos\n\nOpcao: ");
			
				do{
					scanf("%d", &resposta_unidade);
					if(resposta_unidade==1){
						printf("\nDigite o angulo em graus: ");
						scanf("%lf", &angulo);
						if(angulo==0 || angulo==180 || angulo==360)
						printf("Nao ha cossecante no angulo inserido. Comece o calculo novamente.");
						else
						printf("Cossecante de %.5lf graus = %.5lf\n", angulo, Cossecante(angulo * M_PI / 180));
					}
					else if(resposta_unidade==2){
						printf("\nDigite o angulo em rad: ");
						scanf("%lf", &angulo);
						if(angulo==0 || (angulo*M_PI/180)==180 || (angulo*M_PI/180)==360)
						printf("Nao ha cossecante no angulo inserido. Comece o calculo novamente.");
						else
						printf("Cossecante de %.5lf rad = %.5lf\n", angulo, Cossecante(angulo));
					} 
					else 
						printf("\nOpcao invalida. Digite novamente: ");
				}while(resposta_unidade!=1 && resposta_unidade!=2);
				
			break;	
			
			case 6: 
			printf("\nRazao trigonometrica escolhida: *Cotangente*");
			printf("\n\nInsira o numero correspondente a unidade de medida desejada para entrada e saida\n1 - Graus\n2 - Radianos\n\nOpcao: ");
			
				do{
					scanf("%d", &resposta_unidade);
					if(resposta_unidade==1){
						printf("\nDigite o angulo em graus: ");
						scanf("%lf", &angulo);
						if(angulo==0 || angulo==180 || angulo==360)
						printf("Nao ha cotangente no angulo inserido. Comece o calculo novamente.");
						else
						printf("Cotangente de %.5lf graus = %.5lf\n", angulo, Cotangente(angulo * M_PI / 180));
					}
					else if(resposta_unidade==2){
						printf("\nDigite o angulo em rad: ");
						scanf("%lf", &angulo);
						if(angulo==0 || (angulo*M_PI/180)==180 || (angulo*M_PI/180)==360)
						printf("Nao ha cotangente no angulo inserido. Comece o calculo novamente.");
						else
						printf("Cotangente de %.5lf rad = %.5lf\n", angulo, Cotangente(angulo));
					} 
					else 
						printf("\nOpcao invalida. Digite novamente: ");
				}while(resposta_unidade!=1 && resposta_unidade!=2);
			
			break;	
			
			case 7: 
			printf("\nRazao trigonometrica escolhida: *Arco Seno*");
			printf("\n\nDeseja obter a resposta do arco em:\n1 - Graus\n2 - Radianos\n\nOpcao: ");
			
				do{
					scanf("%d", &resposta_unidade);
					if(resposta_unidade==1){
						printf("\nDigite o Arco Seno: ");
						scanf("%lf", &angulo);
						printf("Arco Seno de %.5lf = %.5lf graus\n", angulo, ArcoSeno(angulo) * 180 / M_PI);
					}
					else if(resposta_unidade==2){
						printf("\nDigite o Arco Seno: ");
						scanf("%lf", &angulo);
						printf("Arco Seno de %.5lf = %.5lf rad\n", angulo, ArcoSeno(angulo));
					} 
					else 
						printf("\nOpcao invalida. Digite novamente: ");
				}while(resposta_unidade!=1 && resposta_unidade!=2);
			
			break;	
			
			case 8: 
			printf("\nRazao trigonometrica escolhida: *Arco Cosseno*");
			printf("\n\nDeseja obter a resposta do arco em:\n1 - Graus\n2 - Radianos\n\nOpcao: ");
			
				do{
					scanf("%d", &resposta_unidade);
					if(resposta_unidade==1){
						printf("\nDigite o Arco Cosseno: ");
						scanf("%lf", &angulo);
						printf("Arco Cosseno de %.5lf= %.5lf graus\n", angulo, ArcoCosseno(angulo) * 180 / M_PI);
					}
					else if(resposta_unidade==2){
						printf("\nDigite o Arco Cosseno: ");
						scanf("%lf", &angulo);
						printf("Arco Cosseno de %.5lf = %.5lf rad\n", angulo, ArcoCosseno(angulo));
					} 
					else 
						printf("\nOpcao invalida. Digite novamente: ");
				}while(resposta_unidade!=1 && resposta_unidade!=2);
			
			break;		
			
			case 9: 
			printf("\nRazao trigonometrica escolhida: *Arco Tangente*");
			printf("\n\nDeseja obter a resposta do arco em:\n1 - Graus\n2 - Radianos\n\nOpcao: ");
			
				do{
					scanf("%d", &resposta_unidade);
					if(resposta_unidade==1){
						printf("\nDigite o Arco Tangente: ");
						scanf("%lf", &angulo);
						printf("Arco Tangente de %.5lf = %.5lf graus\n", angulo, ArcoTangente(angulo) * 180 / M_PI);
					}
					else if(resposta_unidade==2){
						printf("\nDigite o Arco Tangente: ");
						scanf("%lf", &angulo);
						printf("Arco Tangente de %.5lf = %.5lf rad\n", angulo, ArcoTangente(angulo));	
					} 
					else 
						printf("\nOpcao invalida. Digite novamente: ");	
				}while(resposta_unidade!=1 && resposta_unidade!=2);
			
			break;		
		}
			
	}while(confirmacao_razao=='S' || confirmacao_razao=='s');
	
	printf("\n\nDeseja realizar novo calculo? (s/n) ");
	scanf("%*c%c%*c", &novocalculo);
	
	}while(novocalculo=='S' || novocalculo=='s');
	
	return 0;
}
