#include <stdlib.h>
#include <stdio.h>
#include <time.h>

enum {PEDRA, PAPEL, TESOURA, PCWIN, EMPATE, PLAYERWIN};

int escolhaplayer(){
	int escolha;
	printf("Escolha: 0-PEDRA, 1-PAPEL, 2-TESOURA\n");
	do{
		scanf(" %d", &escolha);
	}while(!(escolha >=PEDRA && escolha <=TESOURA));
	return escolha;
}

int escolhaPC(){
	int computador=rand()%3;
	printf("O computador escolheu ");
	switch(computador){
		case PEDRA: printf("PEDRA\n"); break;
		case PAPEL: printf("PAPEL\n"); break;
		case TESOURA: printf("TESOURA\n"); break;
	}
	return computador;
}

int verificavencedor(){
	int player=escolhaplayer();
	int computador=escolhaPC();
	
	if(computador==player)
		return EMPATE;
		
	if(player==PEDRA && computador==TESOURA)
		return PLAYERWIN;
	if(player==TESOURA && computador==PAPEL)
		return PLAYERWIN;
	if(player==PAPEL && computador==PEDRA)
		return PLAYERWIN;
		
	return PCWIN;
}

void printvencedor(){
		int winner=verificavencedor();
		
		switch(winner){
		case PCWIN: printf("computador venceu"); break;
		case EMPATE: printf("empate"); break;
		case PLAYERWIN:	printf("Player venceu");
	}
}

int main(){
	srand(time(NULL));
	printvencedor();
	return 0;
}

