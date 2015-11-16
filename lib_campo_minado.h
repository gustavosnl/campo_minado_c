#include <time.h>
//tamanho do campo minado
#define DIM 8

//falsos booleanos
#define VERDADEIRO 1
#define FALSO 0

//valores para ceulas
#define CELULA_VAZIA 0
#define CELULA_MINA 1
#define CELULA_BANDEIRA 2
#define CELULA_NAO_JOGADA 3

//opções de jogada
#define MARCAR 1
#define BANDEIRA 2
#define SAIR 3

void iniciar_campo(int *campo);
void inserir_minas(int *campo, int total_minas);
void inserir_minas_de_arquivo(int *campo, FILE *arquivo);
int linha_arquivo(char *linha);
int coluna_arquivo(char *coluna);
void imprimir_campo(int *campo);
// void traduzir_coordenada(int *campo, char *coordenada);
// int realizar_disparo(char *coordenada,int *campo);
// int validar_posicionamento_navio(char *coordenada);
// void fornecer_dica(char* posicao, int *campo);
// int acertou_navio(int linha,int coluna, int *campo);
// int exibir_menu();
// void contar_navios(int *campo,int *qtd_navios);
// void realizar_disparo_computador(int *campo);

void iniciar_campo(int *campo){
	int i,j;
	for (i = 0 ; i < DIM ; i++){
		for (j = 0 ; j < DIM ; j++){
			*campo++ = CELULA_VAZIA;
		}
	}
}

void inserir_minas(int *campo, int total_minas){
	int i, linha, coluna;
	
	for(i=0 ; i<total_minas ; i++){
		do{
			linha=rand()%DIM;
			coluna=rand()%DIM;

			printf("l: %d, c: %d\n",linha,coluna);
	   	} while(*(campo+(linha*DIM+coluna))!= CELULA_VAZIA); //impede que uma mina seja posicionada na mesma posição de uma já existente

	   	*(campo+(linha*DIM+coluna))=CELULA_MINA;
	}
}

void inserir_minas_de_arquivo(int *campo, FILE *arquivo){
	char coord1[3], coord2[3];
	while (fscanf(arquivo, "%s %s", coord1, coord2) != EOF){
		//if ( validar_posicionamento_navio(coord1) == VERDADEIRO) {
			*(campo+(linha_arquivo(coord1)*DIM + coluna_arquivo(coord1)))=CELULA_MINA;
		//}
	}
}

int caractere(int codigo){
	switch(codigo){
		case CELULA_VAZIA:
			return 32; //espaço
		case CELULA_MINA:
			return 35; // #
		case CELULA_BANDEIRA:
			return 79; // O
		case CELULA_NAO_JOGADA:
			return 35; // #
	}
}

void imprimir_campo(int *campo){
	int i, j;

	printf("  ");
	for(j = 0 ; j < DIM; j++){			
		printf(" %4d", j+1);	
	}

	for (i = 0 ; i < DIM ; i++){

		printf("\n %c ",i+65);
		for (j = 0 ; j < DIM ; j++){						
			printf("| %c  ",caractere(*campo));
			campo++;	
		}
		printf("|");

	}
	printf("\n\n" );
}

int linha_arquivo(char *linha){
	return linha[0] - 65;
}

int coluna_arquivo(char *coluna){
	return coluna[1] - 49;
}

// int validar_posicionamento_navio(char *coordenada){
// 	if (coordenada[0]<'A' || coordenada[0] >= ('A'+DIM)) return FALSO;
// 	if (coordenada[1]<'1' || coordenada[1] >= ('1'+DIM-1)) return FALSO;
// 	return VERDADEIRO;
// }



// int validar_coordenada(char *coordenada){
// 	if (coordenada[0]<'A' || coordenada[0] >= ('A'+DIM)){
// 		printf("COORDENADA INVALIDA\n" ); 
// 		return FALSO;
// 	} 
// 	if (coordenada[1]<'1' || coordenada[1] >= ('1'+DIM)){
// 		printf("COORDENADA INVALIDA\n" ); 
// 		return FALSO;
// 	} 
// 	return VERDADEIRO;
// }

// int acertou_navio(int linha,int coluna, int *campo){
// 	if (*(campo+(linha*DIM+coluna))==NAVIO) return VERDADEIRO;
// 	return FALSO;
// }

// int realizar_disparo(char *coordenada, int *campo){
// 	int linha,coluna;
// 	if  (validar_coordenada(coordenada)==VERDADEIRO){
// 		linha=traduzir_linha(coordenada);
// 		coluna=traduzir_coluna(coordenada);
// 		if (acertou_navio(linha,coluna,campo)==VERDADEIRO){
// 			printf("Navio Atingido!\n");
// 			*(campo+(linha*DIM+coluna))=ACERTO;
// 		}else{
// 			printf("Errou o disparo!\n");
// 			*(campo+(linha*DIM+coluna))=ERRO;
// 		}
// 		return VERDADEIRO;		
// 	}
// 	return FALSO;
// }

// void fornecer_dica(char *coordenada, int *campo){
// 	int linha,coluna,i,tem_navio=0;
// 	linha=traduzir_linha(coordenada);
// 	coluna=traduzir_coluna(coordenada);
// 	//procurar pelas linhas
// 	for (i=0;i<DIM;i++){
// 		if (*(campo+(linha*DIM+i))==1) {
// 			tem_navio=1;
// 		}
// 	}
// 	for (i = 0; i < DIM; i++) {
// 		if (*(campo+(i*DIM+coluna))==1) {
// 			tem_navio=1;
// 		}
// 	}
// 	if (tem_navio == 1) {
// 		printf("Navio Inimigo a vista!!!\n");
// 	}
// 	else {
// 		printf("Nada além de um mar tranquilo\n");
// 	}
// }


// int exibir_menu(){
// 	int opcao;
// 	do {
// 		printf("OPCOES:\n[1]-Marcar Posicao\n[2]-Colocar uma Bandeira\n[3]-Finalizar\n");
// 		scanf("%d",&opcao);
// 		if (opcao!=DISPARO && opcao!=DICA && opcao!=SAIR){
// 			printf("OPCAO ESCOLHIDA INVALIDA\n");
// 		}
// 	}while (opcao!=1 && opcao!=2 && opcao!=3);

// 	return opcao;
// }

// void contar_navios(int *campo,int *qtd_navios){
// 	int i, j, cont = 0;

// 	for (i = 0 ; i < DIM ; i++){
// 		for (j = 0 ; j < DIM-1 ; j++){
// 			if (*(campo+(i*DIM+j))==ACERTO && *(campo+(i*DIM+j+1))==ACERTO){
// 				cont++;
// 				j++; // impede que 2 navios que estejam um ao lado do outro contem como 3
// 			}
// 		}
// 	}
// 	*qtd_navios=TOTAL_NAVIOS- cont;
// }
/*

void revelar(int x, int y){
    revelar_adjacencias(x - 1, y - 1);
    revelar_adjacencias(x - 1, y);
    revelar_adjacencias(x - 1, y + 1);

    revelar_adjacencias(x, y - 1);
    revelar_adjacencias(x, y + 1);

    revelar_adjacencias(x + 1, y);
    revelar_adjacencias(x + 1, y - 1);
    revelar_adjacencias(x + 1, y + 1);
}

void revelar_adjacencias(int x, int y){
    var coordinate = GetCoordinate(x, y, mappedCoordinates);
    if (coordinate == null) return;
    if (coordinate.State == State.Revealed) return;

    if (IsBlank(coordinate))
    {
        coordinate.State = State.Revealed;
        coordinates[x, y].Cell.Background = Brushes.LightGreen;
        Reveal(x, y);
    }
    else
    { 
        coordinate.State = State.Revealed;
        coordinates[x, y].Cell.Child = new TextBlock() { Text = coordinate.Counter.ToString() };
        coordinates[x, y].Cell.Background = Brushes.Goldenrod;
    }
}

*/


void board_reveal(int *campo, int linha, int col)
{
    if (row < 0 || row >= ROWS) return;     /* skip off-board tiles */
    if (col < 0 || col >= COLS) return;

    if (board[row][col] < 10) return;       /* already revealed, skip */
    if (board[row][col] >= 20) return;      /* must remove flag first, skip */

    if (board[row][col] % 10 == BOMB) {
        int i, j;

        printf("Bang!\n");

        for (j = 0; j < ROWS; j++) {
            for (i = 0; i < COLS; i++) {
                if (board[j][i] % 10 == BOMB) board[j][i] = BOMB;
            }
        }     
    } else {
        board[row][col] %= 10;
        if (board[row][col] == 0) {
            board_reveal(board, row - 1, col);
            board_reveal(board, row, col - 1);
            board_reveal(board, row, col + 1);
            board_reveal(board, row + 1, col);
        }
    }
}
