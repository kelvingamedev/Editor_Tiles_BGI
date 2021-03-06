//=================================================
/*Inclua os arquivos da seguinte forma:*/

#include <iostream>
#include <fstream> // E / S de arquivos
#include <iomanip> // Para ler em caracter a caracter
#include <graphics.h>

/*Bibliotecas do projeto TowerDefense*/
#include "header/td_defines.h"
#include "header/sprite.h"
#include "header/cenario.h"
#include "header/grade.h"
#include "header/gui.h"
// �ltima atualiza��o: 18 de set. 2015

//===============================================

/*Estrutura exclusiva do programa editor (GUI para o editor)*/

// Menu de escolha do pincel
void Pincel(Cenario *meuCampo);

// Menu de salvar campo de jogo
void Salva(Cenario meuCampo);

// Procedimento de carregar um arquivo de coordenadas
void Carrega(Cenario *meuCampo, Grade minhaGrd);

// Opc��o de sair do programa
void Sair(int opcao, bool *editLoop);

// Menu principal no console
void MainMenu(int &opcao);

// Menu de edi��o no console
void Edita(Cenario *meuCampo, Grade minhaGrd);

// Mostra campo e grade na tela
void CampoGrad(Cenario *meuCampo, Grade minhaGrd);


int main(){
	
	// Recebe nome do arquivo 
	char *nomeArq;
	
	// Interface com o usu�rio
	GUI minhaGUI;
	
	// Contadores 
	int i, j;
	
	// Confirma se tudo ocorreu corretamente
	bool sucesso;
	
	// Recebe a entrada de dados por meio do teclado
	int tecla = 0;
	
	// Opcao do jogador no console
	int opcao = -1;
		
	// Declara��o de vari�veis
	Grade minhaGrd;
 	Cenario meuCampo;
	
	// Define se o programa continua em execu��o ou n�a
	bool editLoop = true;
	
	// Inicialize a janela do editor (maior em altura do que a janela do jogo)
	initwindow(EDIT_W,EDIT_H);
	
	// Inicializa o campo de jogo
	meuCampo.Init();
	
	// Mostra o campo e a grade na tela
	CampoGrad(&meuCampo,minhaGrd);
	
	// Faz interface com o usu�rio
	minhaGUI.Init("Console");

	// Loop do programa
	while(editLoop == true){
			
			// Menu principal no console
			MainMenu(opcao);
			
			switch(opcao){
				case 1:
					
					//Funcionalidade de carregar um arquivo o campo de jogo
					Carrega(&meuCampo, minhaGrd);
					break;
				case 2:
					
					//Funcionalidade de editar o campo de jogo
					Edita(&meuCampo, minhaGrd);
					break;
				case 3:
					
					// Funcionaidade de salvar o campo de jogo em um arquivo
					Salva(meuCampo);
					break;
				case 4:			
					// Procedimento de s�ida do programa
					Sair(opcao,&editLoop);
					break;
				default:	
					std::cout <<"\n Digite apenas n� de op��es v�lidas (1-4)\n";
					break;
					
				}
	}
	
	closegraph();
	return 0;
}


// Funcionalidade de salvar o campo de jogo em um arquivo de coordenadas
void Salva(Cenario meuCampo){
	
	char nomeArq[20];
	
	std::cout <<"\nSalvar como:\n";

	// Limpa o fluxo de dados
	fflush(stdin);

	// Recebe o nome do arquivo
	std::cin >> nomeArq;
	
	std::cout << nomeArq;

	// Arquiva a matriz 
	meuCampo.Arquiva((char *)nomeArq);
}

void Carrega(Cenario *meuCampo, Grade minhaGrd){

	bool sucesso;
	char nomeArq[8];
	
	// Requere o nome do arquivo com as coord. do campo de jogo e carrega-o
	std::cout << "Digite o nome do arquivo com as coord. do campo de jogo\n";
	
	// Limpa o buffer e recebe o nome do arquivo
	fflush(stdin);
	std::cin >> nomeArq;
	
	// Carrega o arquivo de cooredenadas
	sucesso = meuCampo->PosLoad(nomeArq);
	
	// Verifica se o processo ocorreu corretamente
	if(!sucesso){
		std::cout << "\nFalha na leitura do arquivo\"" << nomeArq << "\".\n"; 
	} 
	else{
		
		// Se tudo ocorreu corretamente, atualize o campo de jogo
		std::cout << "Arquivo carregado com sucesso!";
		meuCampo->Mostrar();
		minhaGrd.Colocar();
	}
	
}

// Menu principal no console
void MainMenu(int &opcao){
	std::cout << "\nEDITOR DE CAMPO DE JOGO\n\nSelecione uma das op��es dispon�veis\n";
	std::cout << "\n1 - Carregar campo de jogo\n2 - Editar campo de jogo\n";
	std::cout << "3 - Salvar arquivo\n4 - Sair\n\nOpcao: ";	
	
	// Limpa o buffer e recebe a opcao
	fflush(stdin);
	std::cin >> opcao;
}

// Opc��o de sair do programa
void Sair(int opcao, bool *editLoop){

		
	do{
		std::cout << "\nDeseja realmente sair do programa?";
		std::cout << "\n1- Sim \n2- Nao\n";
		
		// Limpa o buffer e recebe a opc�o 
		fflush(stdin);
		std::cin >> opcao;
		
		// Se o usu�rio confirmar a sa�da
		if (opcao == 1)
			*editLoop = false; // Faz o programa sair do la�o e encerrar
	
	} while(opcao != 1 && opcao != 2);
	
}


// Funcionalidade de escolha o pincel de tiles
void Pincel(Cenario *meuCampo, int *pincel){
	
	// Contador
	int i;
	
	// Vari�vel tempor�ria para ind�ces mais compreens�veis
	int tempI;
	
	// Lista os pinceis dispon�veis
	std::cout << "\nSelecione um dos pinceis dispon�veis:\n\n";
	for(i = 0; i < meuCampo->QTD_TILE; i++){
		
		// Calcula o indice compreensivel
		tempI = i + 1;
		
		std::cout << tempI << " - " << meuCampo->tipoTile[i].nome << "\n\n";
	}
	
	// Limpa o buffer e recebe o pincel escolhido
	fflush(stdin);
	std::cin >> tempI;
	
	// Calcula o indice usado pelo computador
	*pincel = tempI - 1; 
	
	// Confirma o pincel escolhido
	std::cout << "\n\nVoc� escolheu o pincel \"" << meuCampo->tipoTile[*pincel].nome <<"\"\nUse-o no modo Desenho\n";

}

// Menu de edi��o no console
void Edita(Cenario *meuCampo, Grade minhaGrd){
	
	// Primeira "cor" do pincel de tiles
	const int TILE_EUA = 5;
	
	// Interface com o usu�rio
	GUI minhaGUI;
	
	// Para trabalhar com coordenadas...
	int x, y;
	
	// Contadores
	int i, j;
	
	// Indica que o usu�rio est� pressionando o bot�o esquerdo do mouse
	bool pressing = false;
	
	// Tile aonde se deu um click com o mouse
	int tMouseX0;
	int tMouseY0;
	
	// Tile aonde se soltou o click
	int tMouseXF;
	int tMouseYF;
	
	// Recebe o tipo de altera��o entre indices
	int alteraI, alteraJ;
	
	
	// Pagina��o
	int pg = 1;
	
	// Indica se est� no modo desenho ou n�o
	bool desenho = false;
	
	// Indice do tile que o mouse est� sendo em cima
	int tMouseX = 0, tMouseY = 0;
	
	// Pincel de tile
	int pincel = TILE_EUA;
	
	// Armazena a escolha feita 
 	int opcao = -1;
	
	while(opcao != 3){
		// Mostre as op��es dispon�veis
		std::cout << "\n\nSelecione uma das opcoes disponiveis:\n\n";
		std::cout << "1-Escolher pincel de desenho\n2-Desenhar\n3-Sair do menu Edicao\n\nOpcao: ";
		
		// Limpa o buffer e recebe a escolha
		fflush(stdin);
		std::cin >> opcao;
		
		switch(opcao){
			case 1: 
			
				// Funcionalidade de escolher o pincel
				Pincel(meuCampo, &pincel);
				break;
			case 2:
				
				// Funcionalidade de desenhar (editar) campo de jogo
				
				// Confirma a entrada no modo desenho
				desenho = true;
				std::cout << "MODO DESENHO\n";
				
				// Enquanto estiver no modo desenho
				while(desenho == true){
					
					
					/*
								Comandos que N�O geram mudan�as gr�ficas diretas
					*/
					
					// Verifica se o usu�rio deseja sair do modo editor
					if(GetKeyState(VK_F5)& 0x80){
						
						// Confirma a sa�da do modo desenho
						desenho = false;
					}
					
					
					// Calcula o tile aonde est� o mouse 
					tMouseX = mousex() / TILE_W;
					tMouseY = mousey() / TILE_H;
					
					// Calcula aonde colocar o tile com base no indice dele
					x = tMouseX * TILE_W;
					y = tMouseY * TILE_H;					
					
					// Verifica se o usu�rio deu um click com o bot�o esquerdo
					if (ismouseclick(WM_LBUTTONDOWN )){
						
						// Processsa o click
						clearmouseclick(WM_LBUTTONDOWN);
						
						//Calcula o tile aonde foi dado o click
						tMouseX0 = tMouseX;
						tMouseY0 = tMouseY;
						
						// Confirma o pressionamento
						pressing = true;
						
						// Teste
						//std::cout << "\npressing =" << pressing << "\n";
					}
					
					// Verifica se o usu�rio soltou o bot�o esquerdo
					if(ismouseclick(WM_LBUTTONUP )){
						
						// Processsa o soltar do bot�o
						clearmouseclick(WM_LBUTTONUP);
						
						// Retira o pressionamento
						pressing = false;
						
						// Teste
						//std::cout << "\npressing =" << pressing << "\n";
						
						// Calcula o indice do tile no fim do click
						tMouseXF = tMouseX;
						tMouseYF = tMouseY;
						
						// A posi��o inicial dos contadores deve come�ar a partir
						// do primeiro tile de �rea de click
						
						// Verifica os tipos de altera��es
						if(tMouseX0 < tMouseXF)
							alteraJ = 1;
						else
							alteraJ = -1;
							
						if(tMouseY0 < tMouseYF)
							alteraI = 1;
						else
							alteraI = -1;
							
						// Percorra toda �rea de click e altere os valores da matriz  posTiles
						for( i = tMouseY0; i != (tMouseYF + alteraI); i+= alteraI){
							
							for(j = tMouseX0; j!= (tMouseXF + alteraJ); j+= alteraJ){
								
								// Troque o tipo de tile
								meuCampo->posTile[j][i] = pincel;
								
								//TESTE
								//std::cout << "Trocando posTile[" << j << "][" << i << "]\n";
							}
						}
					}
					
					// Troca a p�gina e deixa ela em modo desenho
					if(pg == 1){
						pg = 2;
					} else{
						pg = 1;
					}
					setactivepage(pg);
					
					/*
								Comandos que GERAM mudan�as gr�ficas diretas
					*/
					
					// Apaga a tela e mostra o campo e a grade
					CampoGrad(meuCampo, minhaGrd);
					
					// Mostra GUI
					minhaGUI.Init("Desenho");
					
					// Verifica o pressionamento e age conforme isso
					if(!pressing){
						
						// Mostra um tile tempor�rio na posi��o atual
						putimage(x,y,meuCampo->tipoTile[pincel].image,0);
						
						/*TESTE*/
						//std::cout<< "\nTile tempor�rio\n";
							
					} else{
						
						// Comece a partir do primeiro tile da �rea de click do mouse

						
						// Verifica os tipos de altera��es
						if(tMouseX0 < tMouseX)
							alteraJ = 1;
						else
							alteraJ = -1;
							
						if(tMouseY0 < tMouseY)
							alteraI = 1;
						else
							alteraI = -1;
						
						// Enquanto n�o percorrer toda a �rea de sele��o
						for(i = tMouseY0; i != (tMouseY + alteraI); i += alteraI){
							
							/// Calcula a coordenada y do tile
							y = i * TILE_H;
							
							for(j = tMouseX0 ; j!= (tMouseX + alteraJ) ; j+= alteraJ){
								
								// Calcula a coordenada x do tile
								x = j * TILE_W;

								// Coloca os tiles na tela
								putimage(x,y,meuCampo->tipoTile[pincel].image,0);
								
								/*TESTE*/
								//std::cout<< "\nColocando tile| pos[ " << j << "][" <<i <<"]\n"; 							
									
							}
						}						
					}
					// Deixa a p�gina visual
					setvisualpage(pg);

					// Atualize os gr�ficos com uma boa taxa de FPS
					delay(FPS);
				}
				
				// Limpa a tela mostra o campo novamente
				// (para retirar os tiles tempor�rios)
				CampoGrad(meuCampo, minhaGrd);
				
				// Mostra a GUI no modo console
				minhaGUI.Init("Console");
				 
				break;
			case 3:
				std::cout << "\nVoltando para o menu principal...\n\n";
				break;	
				
			default:
				std::cout << "\nDigite apenas opcoes validas (1-3)\n";
				break; 		
		}
	}

}

// Mostra o campo e a grade na tela
void CampoGrad(Cenario *meuCampo, Grade minhaGrd){
	
	// Limpa a tela
	cleardevice();
	
	// Mostra o campo de jogo
	meuCampo->Mostrar();
		
	// Coloca a grade
	minhaGrd.Colocar();
	
}





