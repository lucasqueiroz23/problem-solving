#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

void printar_funcao_nao_implementada(){
  printf("nao implementado\n");
}

int main(int argc, char **argv){
  void *handler = dlopen(argv[1], RTLD_LAZY);
  if(handler == NULL){
    printf("nao disponivel\n");
    return 0;
  }

  int (*imprime) (void) = dlsym(handler, "imprime");
  int (*calcula) (int, int) = dlsym(handler, "calcula");
  int (*trigo) (double, double*) = dlsym(handler, "trigo");

  if(imprime == NULL){
    printar_funcao_nao_implementada();
  }
  else printf("%d\n", imprime());

  if(calcula == NULL){
    printar_funcao_nao_implementada();
  }
  else printf("%d\n", calcula(atoi(argv[2]), atoi(argv[3])));
  
  double x = atof(argv[4]);
  if(trigo == NULL){
    printar_funcao_nao_implementada();
  }
  else printf("%d\n", trigo(x, &x));

  dlclose(handler);
  return 0;
}