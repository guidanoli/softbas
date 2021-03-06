/*
Aluno: Guilherme Dantas	Matrícula: 1713155
Aluno: Rafael Damazio   Matrícula: 1712990
*/

#include "gera_codigo.h"

int main(int argc, char *argv[]) {
  FILE *fp;
  void *code;
  funcp funcSBF;
  int res = 0, argint = 0, s = 1;
  char *p = argv[2];
  
  if( argc != 3 )
  {
  	printf("Numero invalido de parametros\n");
    return 0;
  }
  
  /* Abre o arquivo para leitura */
  fp = fopen(argv[1], "r");
  
  if( fp == NULL )
  {
  	printf("Erro ao abrir o arquivo\n");
    return 0;
  }
  
  printf("************************\n");
  printf("%s\n",argv[1]);
  printf("************************\n");
  
  /* Gera o codigo */
  gera_codigo(fp, &code, &funcSBF);
  if ((code == NULL) || (funcSBF == NULL)) {
    printf("Erro na geracao\n");
    return 0;
  }
  
  fclose(fp);
  
  if( *p == '-' )
  {
    s = -1;
    p++;
  }
  
  while( *p != '\0' ) {
    argint *= 10;
    if( *p < '0' || *p > '9' ) {
      printf("Argumento nao-numerico!\n");
      return 0;
    }
    argint += *p - '0';
    p++;
  }
  
  /* Chama a função gerada */
  res = (*funcSBF)(argint*s);
  
  printf("************************\n");
  printf("Retorno = %d\n",res);
  printf("************************\n");
  
  /* Libera a memória utilizada */
  libera_codigo(code);
  
  return 0;  
}
