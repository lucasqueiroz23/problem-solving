#include <stdio.h>

int euclides(int maior, int menor){
  int resto = 1;
  while(resto != 0){
    resto = maior % menor;
    if(resto == 0)
      return menor;
    maior = menor;
    menor = resto;
  }
}

int obterMDC(int a, int b){
  
  // obter maior e menor
  int maior = 0, menor = 0;
  if(a > b){
    maior = a;
    menor = b;
  }
  else {
    maior = b;
    menor = a;
  }

  return euclides(maior, menor);

}

int main(){
  int a = 0, b = 0;
  scanf("%d",&a);
  scanf("%d",&b);
  
  if(a <= 1 || b<=1){
    printf("Entrada invalida.\n");
    return 0;
  }

  int mdc = obterMDC(a,b);
  int produto = a * b;
  int mmc = produto/mdc;

  printf("%d\n%d\n",mdc,mmc);

  return 0;
}