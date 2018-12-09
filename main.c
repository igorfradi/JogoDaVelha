#include <stdio.h>
#include <stdlib.h>

/* Prot�tipo de Fun��es */
void limparConsole();
void tabuleiro();

/* Fun��o Principal */
int main() {
  
  /* Definindo Vari�veis */
  char territorio[3][3];            // Matriz do Tabuleiro
  char jogador1[20], jogador2[20];  // Guarda o nome do jogador
  int numeroJogadas;                // Conta o n�mero de jogadas
  int l,c;                          // Linha e Coluna, para localiza��o no Tabuleiro
  int vez = 0;                      // Define o jogador da vez


  /* Introdu��o ao game */
  printf("Bem vindo ao jogo da velha!\n\nSomente dois jogadores podem jogar ao mesmo tempo. E � bem simples: apenas digite a linha e coluna onde voc� quer marcar territ�rio e aperte ENTER.\n");
  printf("\n--//--\n\n");
  printf("Qual o nome dos jogadores? (AT� 20 CARACTERES)\n");
  fgets(jogador1, 20, stdin);
  fgets(jogador2, 20, stdin);
  
  numeroJogadas=0; // Inicializa o game
  
  // Limpa a Matriz
  for(int i=0; i<=2; i++){
    for(int j=0; j<=2; j++){
      territorio[i][j] = ' ';
    }
  }
  do{
    // Inicia o game mostrando o tabuleiro
    tabuleiro(territorio);

    /* Verifica qual � o jogador atual e informa */
    if(vez%2==0){
      printf("Vez do %s", jogador1);
    }else(printf("Vez do %s", jogador2));

    /* Solicita uma coordenada para o jogador */
    printf("Digite a linha: ");
    scanf("%d", &l);
    printf("Digite coluna: ");
    scanf("%d", &c);

    /* Verifica se a casa � inv�lida */
    if(l < 1 || c < 1 || l > 3 || c > 3){
      l = 0;
      c = 0;
      printf("Voc� informou uma casa que n�o existe!\n");
    }else 
    /* Verifica se a casa est� ocupada */
    if(territorio[l-1][c-1] != ' '){
      l = 0;
      c = 0;
      printf("Voc� informou uma casa que j� est� ocupada!\n");
    }else{
      /* Marca o territ�rio || Sempre -1 pois a matriz come�a em 0 */
      if(vez%2==0){
        territorio[l-1][c-1] = 'X';
      }else{
        territorio[l-1][c-1] = 'O';
      }
      vez++;            // Passa a vez
      numeroJogadas++;  // Aumenta em 1 as jogadas
    }

        // Condi��es de vit�ria
        // linha X
        if(territorio[0][0]=='X' && territorio[0][1]=='X' && territorio[0][2]=='X'){numeroJogadas = 11;}
        if(territorio[1][0]=='X' && territorio[1][1]=='X' && territorio[1][2]=='X'){numeroJogadas = 11;}
        if(territorio[2][0]=='X' && territorio[2][1]=='X' && territorio[2][2]=='X'){numeroJogadas = 11;}
        // coluna X
        if(territorio[0][0]=='X' && territorio[1][0]=='X' && territorio[2][0]=='X'){numeroJogadas = 11;}
        if(territorio[0][1]=='X' && territorio[1][1]=='X' && territorio[2][1]=='X'){numeroJogadas = 11;}
        if(territorio[0][2]=='X' && territorio[1][2]=='X' && territorio[2][2]=='X'){numeroJogadas = 11;}
        // diagonais X
        if(territorio[0][0]=='X' && territorio[1][1]=='X' && territorio[2][2]=='X'){numeroJogadas = 11;}
        if(territorio[0][2]=='X' && territorio[1][1]=='X' && territorio[2][0]=='X'){numeroJogadas = 11;}

        // linha O
        if(territorio[0][0]=='O' && territorio[0][1]=='O' && territorio[0][2]=='O'){numeroJogadas = 12;}
        if(territorio[1][0]=='O' && territorio[1][1]=='O' && territorio[1][2]=='O'){numeroJogadas = 12;}
        if(territorio[2][0]=='O' && territorio[2][1]=='O' && territorio[2][2]=='O'){numeroJogadas = 12;}
        // coluna O
        if(territorio[0][0]=='O' && territorio[1][0]=='O' && territorio[2][0]=='O'){numeroJogadas = 12;}
        if(territorio[0][1]=='O' && territorio[1][1]=='O' && territorio[2][1]=='O'){numeroJogadas = 12;}
        if(territorio[0][2]=='O' && territorio[1][2]=='O' && territorio[2][2]=='O'){numeroJogadas = 12;}
        // diagonais O
        if(territorio[0][0]=='O' && territorio[1][1]=='O' && territorio[2][2]=='O'){numeroJogadas = 12;}
        if(territorio[0][2]=='O' && territorio[1][1]=='O' && territorio[2][0]=='O'){numeroJogadas = 12;}
  }while(numeroJogadas < 9);  // O n�mero m�ximo de partidas � 9!
  tabuleiro(territorio);      // Mostra o tabuleiro no fim da jogada.

  // Informa o fim de jogo
  if(numeroJogadas==9){
    printf("Deu velha!\n");
  }else if(numeroJogadas==11){
    printf("Vit�ria do jogador %s", jogador1);
  }else if(numeroJogadas==12){
    printf("Vit�ria do jogador %s", jogador2);
  }

  return 0;

}

/* Fun��o que limpa o console */
void limparConsole(){
  system("cls || clear"); // Limpa a tela (Windows/Linux)
}

/* Fun��o que exibe o tabuleiro atual */
void tabuleiro(char territorio[3][3]){
  limparConsole();
  printf("\t %c | %c | %c \n", territorio[0][0], territorio[0][1], territorio[0][2]);
  printf("\t-----------\n");
  printf("\t %c | %c | %c \n", territorio[1][0], territorio[1][1], territorio[1][2]);
  printf("\t-----------\n");
  printf("\t %c | %c | %c \n", territorio[2][0], territorio[2][1], territorio[2][2]);
}