/**********************************************************************************************
EP1 DE MAC0329 - ALGEBRA BOOLEANA E SUAS APLICACOES
PRIMEIRO SEMESTRE DE 2013

PROFESSOR: JUNIOR BARRERA

GRUPO:

 GERVASIO PROTASIO DOS SANTOS NETO - NUSP:7990996
 VINICIUS JORGE VENDRAMINI - NUSP:
 MATEUS BARROS RODRIGUES - NUSP:
 VICTOR SANCHES PORTELLA - NUSP:

EP1 - MONTADOR
***********************************************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 32


int main(int argc, char* argv[]){
  FILE *entrada, *saida; /*ponteiros para os arquivos de entrada e de saida*/
  int size, linha, i;
  char arquivoSaida[128], buffer[BUFFER_SIZE], comando[6], mnemonico[4]; /*nomes do arquivos e um buffer, a ser usado para armazenar os caracteres contidas no arquivoFonte e a traducao do comando*/

  printf("Nome do arquivo de entrada: %s\n", argv[1]);
  size = strlen(argv[1]);

  entrada = fopen(argv[1], "r");

  if( entrada == NULL ){
    printf("Nao foi possivel ler o arquivo de entrada\n");
    exit(-1);
  } /*encerra o programa caso o arquivo passado como argumento nao exista*/

  else printf("Arquivo lido com sucesso.\n");

  /*constroi o nome do arquivo de saida baseando-se no nome do arquvio de entrada do formato nomeDoArquivo.asm*/

  strcpy(arquivoSaida, argv[1]);
  arquivoSaida[size-3] = 'h';
  arquivoSaida[size-2] = 'i';
  arquivoSaida[size-1] = 'p';

  saida = fopen(arquivoSaida, "w"); /*abre o arquivo de saida para escrita*/
  
  while( fgets(buffer, BUFFER_SIZE, entrada) != NULL ){ /*le strings do arquivo de entrada ate encontrar o final do arquivo*/
    /*buffer[0] e buffer[1] sao o endereco de memmoria*/
    /*se ha algo depois de buffer[10] sao, teoricamente, comentarios*/
    /*vamos assumir que mnemonicos comecao com o caracter '{'*/

    if( buffer[0] == '+' || buffer[0] == '-' ){
      for(i = 0; i < 5; i++)
	comando[i] = buffer[i];
      comando[5] = '\0';
      
      fprintf(saida, "%s\n", comando);
    }
    
    else if( buffer[3] == '{' ){
      for(i = 0; i < 3; i++)
	mnemonico[i] = buffer[4+i];
      mnemonico[3] = '\0';

      if(strcmp(mnemonico, "LDA") == 0){
	comando[0] = '+';
	comando[1] = '1';
	comando[2] = '1';
	comando[3] = buffer[9];
	comando[4] = buffer[10];

	fprintf(saida, "%s\n", comando);
      }
      
      else if(strcmp(mnemonico, "STA") == 0){
	comando[0] = '+';
	comando[1] = '1';
	comando[2] = '2';
	comando[3] = buffer[9];
	comando[4] = buffer[10];

	fprintf(saida, "%s\n", comando);
      }
      
       else if(strcmp(mnemonico, "ADD") == 0){
	comando[0] = '+';
	comando[1] = '2';
	comando[2] = '1';
	comando[3] = buffer[9];
	comando[4] = buffer[10];

	fprintf(saida, "%s\n", comando);
      }

       else if(strcmp(mnemonico, "SUB") == 0){
	comando[0] = '+';
	comando[1] = '2';
	comando[2] = '2';
	comando[3] = buffer[9];
	comando[4] = buffer[10];

	fprintf(saida, "%s\n", comando);
      }

       else if(strcmp(mnemonico, "MUL") == 0){
	comando[0] = '+';
	comando[1] = '2';
	comando[2] = '3';
	comando[3] = buffer[9];
	comando[4] = buffer[10];

	fprintf(saida, "%s\n", comando);
      }

       else if(strcmp(mnemonico, "DIV") == 0){
	comando[0] = '+';
	comando[1] = '2';
	comando[2] = '4';
	comando[3] = buffer[9];
	comando[4] = buffer[10];

	fprintf(saida, "%s\n", comando);
      }

       else if(strcmp(mnemonico, "REM") == 0){
	comando[0] = '+';
	comando[1] = '2';
	comando[2] = '5';
	comando[3] = buffer[9];
	comando[4] = buffer[10];

	fprintf(saida, "%s\n", comando);
      }

       else if(strcmp(mnemonico, "REV") == 0){
	comando[0] = '+';
	comando[1] = '2';
	comando[2] = '9';
	comando[3] = buffer[9];
	comando[4] = buffer[10];

	fprintf(saida, "%s\n", comando);
      }

       else if(strcmp(mnemonico, "INN") == 0){
	comando[0] = '+';
	comando[1] = '3';
	comando[2] = '1';
	comando[3] = buffer[9];
	comando[4] = buffer[10];

	fprintf(saida, "%s\n", comando);
      }

       else if(strcmp(mnemonico, "PRN") == 0){
	comando[0] = '+';
	comando[1] = '4';
	comando[2] = '1';
	comando[3] = buffer[9];
	comando[4] = buffer[10];

	fprintf(saida, "%s\n", comando);
      }

       else if(strcmp(mnemonico, "NOP") == 0){
	comando[0] = '+';
	comando[1] = '5';
	comando[2] = '0';
	comando[3] = buffer[9];
	comando[4] = buffer[10];

	fprintf(saida, "%s\n", comando);
      }

       else if(strcmp(mnemonico, "JMP") == 0){
	comando[0] = '+';
	comando[1] = '5';
	comando[2] = '1';
	comando[3] = buffer[9];
	comando[4] = buffer[10];

	fprintf(saida, "%s\n", comando);
      }

       else if(strcmp(mnemonico, "JLE") == 0){
	comando[0] = '+';
	comando[1] = '5';
	comando[2] = '2';
	comando[3] = buffer[9];
	comando[4] = buffer[10];

	fprintf(saida, "%s\n", comando);
      }

       else if(strcmp(mnemonico, "JDZ") == 0){
	comando[0] = '+';
	comando[1] = '5';
	comando[2] = '3';
	comando[3] = buffer[9];
	comando[4] = buffer[10];

	fprintf(saida, "%s\n", comando);
      }

       else if(strcmp(mnemonico, "JGT") == 0){
	comando[0] = '+';
	comando[1] = '5';
	comando[2] = '4';
	comando[3] = buffer[9];
	comando[4] = buffer[10];

	fprintf(saida, "%s\n", comando);
      }

       else if(strcmp(mnemonico, "JEQ") == 0){
	comando[0] = '+';
	comando[1] = '5';
	comando[2] = '5';
	comando[3] = buffer[9];
	comando[4] = buffer[10];

	fprintf(saida, "%s\n", comando);
      }

       else if(strcmp(mnemonico, "JLT") == 0){
	comando[0] = '+';
	comando[1] = '5';
	comando[2] = '6';
	comando[3] = buffer[9];
	comando[4] = buffer[10];

	fprintf(saida, "%s\n", comando);
      }

       else if(strcmp(mnemonico, "JGE") == 0){
	comando[0] = '+';
	comando[1] = '5';
	comando[2] = '7';
	comando[3] = buffer[9];
	comando[4] = buffer[10];

	fprintf(saida, "%s\n", comando);
      }

       else if(strcmp(mnemonico, "STP") == 0){
	comando[0] = '+';
	comando[1] = '7';
	comando[2] = '0';
	comando[3] = '0';
	comando[4] = '0';

	fprintf(saida, "%s\n", comando);
      }

    }
  }
  

  fclose(entrada);
  printf("Arquivo em 'codigo-maquina' salvo em %s.\n", arquivoSaida);
  

  return 0;
}
