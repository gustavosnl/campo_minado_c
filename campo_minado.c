#include <stdio.h>
#include <string.h>
#include "lib_campo_minado.h"

int main(){
	int campo_minado[DIM][DIM];
	int total_minas;
	int dicas=0;
	int opcao, disparo_valido;
	char posicao[3];
	int dicas_utilizadas=0;
	int jogar_novamente;

	FILE *arquivo_minas;
	arquivo_minas = fopen("minas.txt","r");
	
	do{
		do {
			printf("Escolha o modo de jogo\n1-AUTOMATICO\n2-MANUAL\n");
			scanf("%d",&opcao);		
			if (opcao != 1 && opcao !=2){
				printf("OPCAO INVALIDA\n");
			}	
		} while(opcao!=1 && opcao!=2);

		iniciar_campo(campo_minado[0]);
		switch(opcao){
			case 1:
				printf("informe a quantidade de minas desejada. [MIN:5 | MAX:40]\n");
				scanf ("%d",&total_minas);
				if (total_minas>40 || total_minas<5) {
					total_minas = 40;
				}

				srand(time(NULL));
				inserir_minas(campo_minado[0],total_minas);
				imprimir_campo(campo_minado[0]);
				break;
			case 2: 
				inserir_minas_de_arquivo(campo_minado[0],arquivo_minas);
				imprimir_campo(campo_minado[0]);
				break;			
		}

		/*opcao = exibir_menu();
		while (opcao != SAIR){
			switch(opcao){
				case DISPARO:
				do{
					printf("insira a posicao que deseja atacar: ");
					scanf("%s",posicao);					
					disparo_valido = realizar_disparo(posicao, tabela_computador[0]);
				} while(disparo_valido == FALSO);
				realizar_disparo_computador(campo_minado[0]);
				contar_navios(campo_minado[0],&navios_jogador);
				contar_navios(tabela_computador[0],&navios_computador);
				imprimir_tabelas(campo_minado[0], tabela_computador[0],navios_jogador,navios_computador);
				break;

				case DICA:
				if (dicas_utilizadas<TOTAL_DICAS){
					do{
						printf("insira uma posicao para obter uma dica: ");
						scanf("%s",posicao);					
					}while(validar_posicao(posicao)==FALSO);
					fornecer_dica(posicao, tabela_computador[0]);
					dicas_utilizadas++;
				}
				break;

				case SAIR:
				printf("FIM DE JOGO\n");
				break;
			}

			if(navios_jogador==0){
				printf("JOGADOR PERDEU\n");
				opcao=SAIR;
			} else if (navios_computador == 0){
				printf("JOGADOR VENCEU\n");
				opcao=SAIR;
			}else{
				opcao=exibir_menu();				
			}
		}
		printf("\nGostaria de jogar novamente? (0- terminar | qualquer numero para continuar)");
		scanf("%d",&jogar_novamente);
	
	}
}
*/	}while(jogar_novamente!=0);
	return 0;
}