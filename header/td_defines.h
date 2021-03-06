/*Constantes*/

/*Dimens�es da tela de jogo*/
#define TELA_W 1280
#define TELA_H 704

/*Quantidade de novas torres (fila de espera)*/
#define QTD_NOVATORRE 5


/*Posi��o do Roosevelt*/
#define ROOSEVELT_X TILE_W * 38
#define ROOSEVELT_Y TILE_H * 19

#define STALIN_X 0
#define STALIN_Y TILE_H * 19


/*Caminho para as imagens dos soldados*/
#define CHARA "/Soldado/Chara/Chara"
#define EUA  "/Soldado/Eua/Eua"
#define URSS  "/Soldado/Urss/Urss"
#define NAZI "/Soldado/Nazi/Nazi"

/*Caminho para as imagens das torres e dos canh�es delas*/
#define TORRE_EUA "/Torre/Eua/Eua"
#define CANHAO_EUA "/Torre/Eua/EuaTiro"
#define TORRE_URSS "/Torre/Urss/Urss"
#define CANHAO_URSS "/Torre/Urss/UrssTiro"


/*Caminho para as imagens dos l�deres*/
#define PATH_HITLER "/Lider/Hitler/Hitler"
#define PATH_ROOSEVELT "/Lider/Roosevelt/Roosevelt"
#define PATH_STALIN "/Lider/Stalin/Stalin"

/*Vida dos soldados e dos generais*/
#define VIDA 100

/*Ponto cego dos EUA 
(local onde as tropas da URSS n�o podem ser visualizadas)*/
#define ENTRADAURSSX TILE_W * 15
#define ENTRADAURSSY -64 // Corrigir esses valores

/*Ponto cego da URSS
(local onde as tropas do EUA n�o podem ser visualizadas)*/
#define ENTRADAEUAX 768
#define ENTRADAEUAY -64

// Indentifica o alvo na fun��o DefesaTorre()
#define EIXO_ID "E"
#define OUTROJOG_ID "O"


/*Simboliza algo que est� para ser definido*/
#define UNDEFINED -1

/*Tile de caminho*/
#define CAMINHO 8

/*Tile de cor preta*/
#define T_PRETO 0

/*Dimens�es da tela do editor de sprites*/
#define EDIT_W 1280
#define EDIT_H 736

/*Dimens�es dos tiles*/
#define TILE_W 32
#define TILE_H 32

/*Qtd. de tiles (Dimens�o da tela / Dimens�o dos tiles)*/
#define TILE_QTDX 40
#define TILE_QTDY 22

/*Tile de inicio do Seek Of Peace (Y) na vers�o menu*/
#define LOGOY1 TILE_H * 5

/*Tile de inicio do Seek Of Peace (Y) na vers�o splitscreen*/
#define LOGOY2 TILE_H * 3

/*Port�o padr�o de acesso ao servidor*/
#define PORTA_PADRAO 20131

/*FPS do jogo*/
#define FPS 60

// FPS alternativo
#define FPS2 30

/*Delay para carregar uma tela de jogo*/
#define DELAY_TELA 100

/*Teclado*/
#define ESC 27


/*Base num�rica decimal (para uso no itoa() e outras fun��es que necessitam desta constante)*/
#define DECIMAL 10

/*Caminho para encontrar a pasta assets*/
#define ASSETS "Assets/"

/*=======================================================*/
/*Caminho para encontrar arquivos de idioma*/
#define PTBR_PATH "txt/pt-br.txt"
#define EN_PATH "txt/en.txt"
/*=========================================================*/


/*Camiho, a partir da pasta Assets, para encontrar as imagens das cutscenes*/
#define CUTSCENES "/Cutscenes/Img"

/*Extens�o bitmap*/
#define BITMAP ".bmp"

/*Extens�o jpeg*/
#define JPEG ".jpg"

/*Destino dos soldados da URSS (em tile)*/
#define DEST_URSS_TX 35
#define DEST_URSS_TY 2

/*Destino dos soldados do EUA (em tile)*/
#define DEST_EUA_TX 4
#define DEST_EUA_TY 2


/*Qtd. de soldados nas tropas*/
#define MAXTROPA 4

/*Delay de envio de soldados (10 s)*/
#define S_DELAY 1.5

/*Delay de fila de espera dos soldados*/
#define ESPERA_DELAY 2


// Define o inicio e o fim do jogo
#define BEGIN 0 // 0 s 
#define END 92 // 1 m 30 s

/*Hor�rio das ondas de soldados*/
#define ONDA1 7 
#define ONDA2 17 
#define ONDA3 32   
#define ONDA4 47
#define ONDA5 62 

#define ONDA_IA1 42 
#define ONDA_IA2 57
#define ONDA_IA3 77

#define QTD_ONDA 8

// Caminho relativo para acessar a pasta dos arquivos .txt
#define TXT_PATH "txt/"

// Representa que n�o h� onda h� serem enviadas
#define SEM_ONDA '?'

// Dano que o soldado infrige quando chega na base inimiga
#define DANO_CHEGOU 10



// Tempo de f�ria dos lideres
#define TEMPOFURIA 2000 // 2 s

// Tempo de reload da torre
#define TORRE_RELOAD 2

// Pre�o de enviar um soldado
#define PRECO_SOLDADO 10

// Pre�o de colocar uma torre
#define PRECO_TORRE 50

// Bonus por matar soldado atacante
#define BONUS_SOLD 10



// Posi��o da GUI do soldado EUA
#define GUI_EUA_X  TILE_W * 33
#define GUI_EUA_Y  TILE_H * 20

// Posi��o da GUI do soldado URSS
#define GUI_URSS_X TILE_W * 6 
#define GUI_URSS_Y TILE_H * 20

// Posi��o do texto do soldado da URSS
#define URSS_TEXT_X TILE_W * 6
#define URSS_TEXT_Y TILE_H * 21

// Posi��o do texto do soldado dos EUA
#define EUA_TEXT_X TILE_W * 33
#define EUA_TEXT_Y TILE_W * 21

// Posi��o da palavra soldado na URSS 
#define SOLD_URSS_X TILE_W * 4
#define SOLD_URSS_Y TILE_H * 19

// Posi��o da palavra soldado nos EUA
#define SOLD_EUA_X TILE_W * 32
#define SOLD_EUA_Y TILE_H * 19

// Delay para torre trocar a posi��o quando 
//no modo Sem Alvo
#define TEMPO_TROCAPOS 1


// Posi��o do texto da torre
#define TORRE_TEXT_X TILE_W * 18
#define TORRE_TEXT_Y TILE_H * 18

// Posi��o da torre acima do texto de torre
#define TORRE1_X TILE_W * 19 + 16
#define TORRE1_Y TILE_H * 15

// Posi��o do Pre�o dos Itens
#define PRECO_ITENS_X TILE_W * 18 
#define PRECO_ITENS_Y TILE_H * 8
#define PRECO_TORRE_X TILE_W * 18 
#define PRECO_TORRE_Y TILE_H * 9
#define PRECO_SOLD_X TILE_W * 18 
#define PRECO_SOLD_Y TILE_H * 10

// Posi��o do dinheiro do jogador
#define MONEY_EUA_X 22 * TILE_W 
#define MONEY_EUA_Y 21 * TILE_H 
#define MONEY_URSS_X 14 * TILE_W - 22
#define MONEY_URSS_Y 21 * TILE_H 	

// Raio de alacance padr�o para as torres
#define TORRE_RAIO 100


// Posi��o do bot�o "jogar"
#define BOTAO_JOGAR_X TILE_W * 19
#define BOTAO_JOGAR_Y TILE_H * 18

// Bot�o do cliente
#define BOTAO_CLIENTE_X TILE_W * 9 
#define BOTAO_CLIENTE_Y TILE_H * 13

// Bot�o do multiplayer local
#define LOCALMULTI_X TILE_W * 19
#define LOCALMULTI_Y TILE_H * 13


// Bot�o do servidor
#define BOTAO_SERV_X TILE_W * 29
#define BOTAO_SERV_Y TILE_H * 13

// Posi��o do bot�o "voltar"
#define BOTAO_VOLTAR_X TILE_W * 14
#define BOTAO_VOLTAR_Y TILE_H * 18

// Posi��o do logo de jogo (X)
#define LOGO_X TILE_W * 11

#define LOGO2_X TILE_W * 14

// IP do localhost
#define LOCALHOST "127.0.0.1"



// Posi��o dos bot�es de menu de jogo
#define BOTAO1_X 9 * TILE_W
#define BOTAO1_Y 13 * TILE_H

#define BOTAO2_X 19 * TILE_W
#define BOTAO2_Y 13 * TILE_H

#define BOTAO3_X 29 * TILE_W
#define BOTAO3_Y 13 * TILE_H


// Op��es para lado do jogador
#define LADOEUA "Eua"
#define LADOURSS "Urss"
#define LADONAZI "Eixo"

// Dimens�es das imagens dos lideres
#define LIDER_TILEW 64
#define LIDER_TILEH 96

// Dimens�es das imagens das torres
#define TORRE_W 32
#define TORRE_H 64







