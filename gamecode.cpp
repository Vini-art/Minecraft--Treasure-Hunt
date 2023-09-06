#include <stdio.h>
#include <iostream>
#include <time.h>
#include <windows.h>
#define TAM 25
#define JOG 2
using namespace std;

void vermelho(){
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 91);
}
void red(){
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 31);
}
void azul(){
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 34);
}
void black(){
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 30);
}
void verde(){
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
}
void amarelo(){
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 97);
}

void incrementa(char mapa[TAM][TAM], int cor1[TAM][TAM], int itens[TAM][TAM], char mapa_escondido[TAM][TAM],int cor2[TAM][TAM]){
    int linha,coluna,x,gravetos=0, pedras=0, animais=0, arvores=0;
    for(linha=0;linha<TAM;linha++){
        for(coluna=0;coluna<TAM;coluna++){
            mapa[linha][coluna]=193;
            mapa_escondido[linha][coluna]=255;
            cor1[linha][coluna]=0;
            itens[linha][coluna]=0;
            cor2[linha][coluna]=0;
        }
    }
    mapa[12][12]=65;
    mapa[12][13]=66;
    while(gravetos<15){
        linha = rand()%25;
        coluna = rand()%25;
        if(mapa[linha][coluna]!=65 && mapa[linha][coluna]!=66){
            itens[linha][coluna]=1;
            mapa_escondido[linha][coluna]=47;
            gravetos++;
        }
    }
    while(pedras<15){
        linha = rand()%25;
        coluna = rand()%25;
        if(mapa[linha][coluna]!=65 && itens[linha][coluna]!=1 && mapa[linha][coluna]!=66){
            itens[linha][coluna]=2;
            mapa_escondido[linha][coluna]=4;
            pedras++;
        }
    }
    while(animais<15){
        linha = rand()%25;
        coluna = rand()%25;
        if(mapa[linha][coluna]!=65 && itens[linha][coluna]!=1 && itens[linha][coluna]!=2 && mapa[linha][coluna]!=66){
            itens[linha][coluna]=3;
            mapa_escondido[linha][coluna]=3;
            animais++;
        }
    }
    while(arvores<15){
        linha = rand()%25;
        coluna = rand()%25;
        if(mapa[linha][coluna]!=65 && itens[linha][coluna]!=1 && itens[linha][coluna]!=2 && itens[linha][coluna]!=3 && mapa[linha][coluna]!=66){
            itens[linha][coluna]=4;
            mapa_escondido[linha][coluna]=244;
            arvores++;
        }
    }
}

void mostra(char mapa[TAM][TAM], int cor1[TAM][TAM],int itens[TAM][TAM],char mapa_escondido[TAM][TAM],int cor2[TAM][TAM] , int A, int B, int C, int D, int E, int F, int G, int H){
    int i, j,cont=0;
    char mostra_item[4][4];
    mostra_item[0][0]=47;
    mostra_item[0][1]=4;
    mostra_item[1][0]=3;
    mostra_item[1][1]=244;
    system("cls");
    for(i=0;i<TAM;i++){
        for(j=0;j<TAM;j++){
            if(mapa[i][j]==65){
                cor1[i][j]=2;
            }
            if(mapa[i][j]==66){
                cor1[i][j]=4;
            }
        }
    }
    for(i=0;i<TAM;i++){
        black();
        cout<<"|";
        verde();
        for(j=0;j<TAM;j++){
            if((cor1[i][j]==1 || cor1[i][j]==2) && cor2[i][j]!=5 && cor2[i][j]!=6){
                vermelho();
                cout<< mapa[i][j]<<" ";
                verde();
            }
            else if((cor1[i][j]==3||cor1[i][j]==4) && cor2[i][j]!=5 && cor2[i][j]!=6){
                azul();
                cout<< mapa[i][j]<<" ";
                verde();
            }
            else if(cor2[i][j]==5){
                amarelo();
                cout<< mapa[i][j]<<" ";
                verde();
            }
            else if(cor2[i][j]==6){
                black();
                cout<< mapa[i][j]<<" ";
                verde();
            }
            else{
                cout<< mapa[i][j]<<" ";                    
            }
        }
        printf("\t\t");
		switch(i) {
			case 0:
				printf("## RANKING DO JOGADOR A ##");
			break;
			case 2:
            vermelho();
                cout<<mostra_item[0][0]<<" Gravetos coletados = "<<A<<" ";
			break;
			case 3:
            vermelho();
                cout<<mostra_item[0][1]<<" Pedras coletadas   = "<<B<<" ";
			break;
            case 4:
            vermelho();
                cout<<mostra_item[1][0]<<" Animais capturados = "<<C<<" ";
			break;
            case 5:
            vermelho();
                cout<<mostra_item[1][1]<<" Arvores coletadas  = "<<D<<" ";
			break;
            case 8:
				printf("## RANKING DO JOGADOR B ##");
			break;
			case 10:
            azul();
                cout<<mostra_item[0][0]<<" Gravetos coletados = "<<E<<" ";
			break;
			case 11:
            azul();
                cout<<mostra_item[0][1]<<" Pedras coletadas   = "<<F<<" ";
			break;
            case 12:
            azul();
                cout<<mostra_item[1][0]<<" Animais capturados = "<<G<<" ";
			break;
            case 13:
            azul();
                cout<<mostra_item[1][1]<<" Arvores coletadas  = "<<H<<" ";
			break;
            // verde();
            case 15:
            if(A==JOG && B==JOG && C==JOG && D==JOG){ 
            vermelho();
                cout<<"JOGADOR A WINNER";
            }else if(E==JOG && F==JOG && G==JOG && H==JOG){
            azul();
                cout<<"JOGADOR B WINNER";
            }
			break;
		}
        cout<<"\n";
    }    
    cont=0;
}

void jogadas(char mapa[TAM][TAM], int cor1[TAM][TAM], int itens[TAM][TAM],char mapa_escondido[TAM][TAM],int cor2[TAM][TAM], int A, int B, int C, int D, int E, int F, int G, int H){
    int linha=0, coluna=0,l=0, cont=0, pgravetos=0, ppedras=0, panimais=0, parvores=0;
    int pgravetos2=0, ppedras2=0, panimais2=0, parvores2=0;
    char m[1];
    while((pgravetos<JOG || ppedras<JOG || panimais<JOG || parvores2<JOG)&&(pgravetos2<JOG || ppedras2<JOG || panimais2<JOG || parvores<JOG)){
        while(cont<1){
        cout<<"vez do jogador A: ";
        cin>>m[0];
        for(linha=0;linha<TAM;linha++){
            for(coluna=0;coluna<TAM;coluna++){
                if(mapa[linha][coluna]==65){             
                    if(m[0] =='w' && linha>0 && cor1[linha-1][coluna]!=4){
                        cont=1;
                        cor1[linha][coluna]=1;
                        if(itens[linha-1][coluna]==1){
                            mapa[linha-1][coluna]=65;
                            mapa[linha][coluna]=mapa_escondido[linha][coluna];
                            if(pgravetos<JOG){
                                pgravetos+=1;
                                cor2[linha-1][coluna]=5;
                                A=pgravetos;
                                itens[linha-1][coluna]=10;
                            }
                        }
                        else if(itens[linha-1][coluna]==2){
                            mapa[linha-1][coluna]=65;
                            mapa[linha][coluna]=mapa_escondido[linha][coluna];
                            if(ppedras<JOG){
                                ppedras+=1;
                                cor2[linha-1][coluna]=5;
                                B = ppedras;
                                itens[linha-1][coluna]=10;
                            }
                            
                        }
                        else if(itens[linha-1][coluna]==3){
                            mapa[linha-1][coluna]=65;
                            mapa[linha][coluna]=mapa_escondido[linha][coluna];
                            
                            if(panimais<JOG){
                                panimais+=1;
                                cor2[linha-1][coluna]=5;
                                C=panimais;
                                itens[linha-1][coluna]=10;
                            }
                        }
                        else if(itens[linha-1][coluna]==4){
                            mapa[linha-1][coluna]=65;
                            mapa[linha][coluna]=mapa_escondido[linha][coluna];
                            if(parvores2<JOG){
                                parvores2++;
                                cor2[linha-1][coluna]=5;
                                D=parvores2;
                                itens[linha-1][coluna]=10;
                            }
                            
                        }else{
                            mapa[linha-1][coluna]=65;
                            mapa[linha][coluna]=mapa_escondido[linha][coluna];
                        }
                    }
                    else if(m[0] =='s' && linha<24 && cor1[linha+1][coluna]!=4){
                        cont=1;
                        cor1[linha][coluna]=1;
                        if(itens[linha+1][coluna]==1){
                            mapa[linha+1][coluna]=65;
                            mapa[linha][coluna]=mapa_escondido[linha][coluna];
                            if(pgravetos<JOG){
                                pgravetos+=1;
                                cor2[linha+1][coluna]=5;
                                itens[linha+1][coluna]=10;
                            }
                        }
                        else if(itens[linha+1][coluna]==2){
                            mapa[linha+1][coluna]=65;
                            mapa[linha][coluna]=mapa_escondido[linha][coluna];
                           if(ppedras<JOG){
                                ppedras+=1;
                                cor2[linha+1][coluna]=5;
                                itens[linha+1][coluna]=10;
                            }
                        }
                        else if(itens[linha+1][coluna]==3){
                            mapa[linha+1][coluna]=65;
                            mapa[linha][coluna]=mapa_escondido[linha][coluna];
                            if(panimais<JOG){
                                panimais+=1;
                                cor2[linha+1][coluna]=5;
                                itens[linha+1][coluna]=10;
                            }
                        }
                        else if(itens[linha+1][coluna]==4){
                            mapa[linha+1][coluna]=65;
                            mapa[linha][coluna]=mapa_escondido[linha][coluna];
                            if(parvores2<JOG){
                                parvores2++;
                                cor2[linha+1][coluna]=5;
                                itens[linha+1][coluna]=10;
                            }
                        }else{
                            mapa[linha+1][coluna]=65;
                            mapa[linha][coluna]=mapa_escondido[linha][coluna];
                        }
                    }
                    else if(m[0] =='a' && coluna>0 && cor1[linha][coluna-1]!=4){
                        cont=1;
                        cor1[linha][coluna]=1;
                        if(itens[linha][coluna-1]==1){
                            mapa[linha][coluna-1]=65;
                            mapa[linha][coluna]=mapa_escondido[linha][coluna];
                            if(pgravetos<1){
                                pgravetos+=JOG;
                                cor2[linha][coluna-1]=5;
                                itens[linha][coluna-1]=10;
                            }
                        }
                        else if(itens[linha][coluna-1]==2){
                            mapa[linha][coluna-1]=65;
                            mapa[linha][coluna]=mapa_escondido[linha][coluna];
                            if(ppedras<JOG){
                                ppedras+=1;
                                cor2[linha][coluna-1]=5;
                                itens[linha][coluna-1]=10;
                            }
                        }
                        else if(itens[linha][coluna-1]==3){
                            mapa[linha][coluna-1]=65;
                            mapa[linha][coluna]=mapa_escondido[linha][coluna];
                            if(panimais<JOG){
                                panimais+=1;
                                cor2[linha][coluna-1]=5;
                                itens[linha][coluna-1]=10;
                            }
                        }
                        else if(itens[linha][coluna-1]==4){
                            mapa[linha][coluna-1]=65;
                            mapa[linha][coluna]=mapa_escondido[linha][coluna];
                            if(parvores2<JOG){
                                parvores2++;
                                cor2[linha][coluna-1]=5;
                                itens[linha][coluna-1]=10;
                            }
                        }else{
                            mapa[linha][coluna-1]=65;
                            mapa[linha][coluna]=mapa_escondido[linha][coluna];
                        }
                    }
                    else if(m[0] =='d' && coluna<24 && cor1[linha][coluna+1]!=4){
                        cont=1;
                        cor1[linha][coluna]=1;
                        if(itens[linha][coluna+1]==1){
                            mapa[linha][coluna+1]=65;
                            mapa[linha][coluna]=mapa_escondido[linha][coluna];
                            if(pgravetos<JOG){
                                pgravetos+=1;
                                cor2[linha][coluna+1]=5;
                                itens[linha][coluna+1]=10;
                            }
                            
                        }
                        else if(itens[linha][coluna+1]==2){
                            mapa[linha][coluna+1]=65;
                            mapa[linha][coluna]=mapa_escondido[linha][coluna];
                            if(ppedras<JOG){
                                ppedras+=1;
                                cor2[linha][coluna+1]=5;
                                itens[linha][coluna+1]=10;
                            }
                        }
                        else if(itens[linha][coluna+1]==3){
                            mapa[linha][coluna+1]=65;
                            mapa[linha][coluna]=mapa_escondido[linha][coluna];
                            panimais+=1;
                            if(panimais<JOG){
                                panimais+=1;
                                cor2[linha][coluna+1]=5;
                                itens[linha][coluna+1]=10;
                            }
                        }
                        else if(itens[linha][coluna+1]==4){
                            mapa[linha][coluna+1]=65;
                            mapa[linha][coluna]=mapa_escondido[linha][coluna];
                            if(parvores2<JOG){
                                parvores2++;
                                cor2[linha][coluna+1]=5;
                                itens[linha][coluna+1]=10;
                            }
                        }else{
                            mapa[linha][coluna+1]=65;
                            mapa[linha][coluna]=mapa_escondido[linha][coluna];
                        }
                    }
                    m[0]=0;
                }
            }
        }
        A=pgravetos;B=ppedras;C=panimais;D=parvores2;
        mostra(mapa,cor1,itens,mapa_escondido,cor2,A,B,C,D,E,F,G,H);
        }
        cont=0;
        while(cont<1){
        cout<<"vez do jogador B: ";
        cin>>m[1];
        for(linha=0;linha<TAM;linha++){
            for(coluna=0;coluna<TAM;coluna++){
                if(mapa[linha][coluna]==66){
                    if(m[1] =='w' && linha>0 && cor1[linha-1][coluna]!=2){
                        cont=1;
                        cor1[linha][coluna]=3;
                        if(itens[linha-1][coluna]==4){
                            mapa[linha-1][coluna]=66;
                            mapa[linha][coluna]=mapa_escondido[linha][coluna];
                            if(parvores<JOG){
                                parvores+=1;
                                cor2[linha-1][coluna]=6;
                                itens[linha-1][coluna]=10;
                            }
                        }
                        else if(itens[linha-1][coluna]==1){
                            mapa[linha-1][coluna]=66;
                            mapa[linha][coluna]=mapa_escondido[linha][coluna];
                            if(pgravetos2<JOG){
                                pgravetos2+=1;
                                cor2[linha-1][coluna]=6;
                                itens[linha-1][coluna]=10;
                            }
                        }
                        else if(itens[linha-1][coluna]==2){
                            mapa[linha-1][coluna]=66;
                            mapa[linha][coluna]=mapa_escondido[linha][coluna];
                            if(ppedras2<JOG){
                                ppedras2+=1;
                                cor2[linha-1][coluna]=6;
                                itens[linha-1][coluna]=10;
                            }
                        }
                        else if(itens[linha-1][coluna]==3){
                            mapa[linha-1][coluna]=66;
                            mapa[linha][coluna]=mapa_escondido[linha][coluna];
                            if(panimais2<JOG){
                                panimais2+=1;
                                cor2[linha-1][coluna]=6;
                                itens[linha-1][coluna]=10;
                            }
                        }
                        else{
                            mapa[linha-1][coluna]=66;
                            mapa[linha][coluna]=mapa_escondido[linha][coluna];
                        }
                    }
                    else if(m[1] =='s' && linha<24 && cor1[linha+1][coluna]!=2){
                        cont=1;
                        cor1[linha][coluna]=3;
                        if(itens[linha+1][coluna]==1){
                            mapa[linha+1][coluna]=66;
                            mapa[linha][coluna]=mapa_escondido[linha][coluna];
                            if(pgravetos2<JOG){
                                pgravetos2+=1;
                                cor2[linha+1][coluna]=6;
                                itens[linha+1][coluna]=10;
                            }
                        }
                        else if(itens[linha+1][coluna]==2){
                            mapa[linha+1][coluna]=66;
                            mapa[linha][coluna]=mapa_escondido[linha][coluna];
                            if(ppedras2<JOG){
                                ppedras2+=1;
                                cor2[linha+1][coluna]=6;
                                itens[linha+1][coluna]=10;
                            }
                        }
                        else if(itens[linha+1][coluna]==3){
                            mapa[linha+1][coluna]=66;
                            mapa[linha][coluna]=mapa_escondido[linha][coluna];
                            if(panimais2<JOG){
                                panimais2+=1;
                                cor2[linha+1][coluna]=6;
                                itens[linha+1][coluna]=10;
                            }
                        }
                        else if(itens[linha+1][coluna]==4){
                            mapa[linha+1][coluna]=66;
                            mapa[linha][coluna]=mapa_escondido[linha][coluna];
                            if(parvores<JOG){
                                parvores+=1;
                                cor2[linha+1][coluna]=6;
                                itens[linha+1][coluna]=10;
                            }
                        }
                        else{
                            mapa[linha+1][coluna]=66;
                            mapa[linha][coluna]=mapa_escondido[linha][coluna];
                            
                        }
                    }
                    else if(m[1] =='a' && coluna>0 && cor1[linha][coluna-1]!=2){
                        cont=1;
                        cor1[linha][coluna]=3;
                        if(itens[linha][coluna-1]==4){
                            mapa[linha][coluna-1]=66;
                            mapa[linha][coluna]=mapa_escondido[linha][coluna];
                            if(parvores<1){
                                parvores+=1;
                                cor2[linha][coluna-1]=6;
                                itens[linha][coluna-1]=10;
                            }
                        }
                        else if(itens[linha][coluna-1]==1){
                            mapa[linha][coluna-1]=66;
                            mapa[linha][coluna]=mapa_escondido[linha][coluna];
                            if(pgravetos2<JOG){
                                pgravetos2+=1;
                                cor2[linha][coluna-1]=6;
                                itens[linha][coluna-1]=10;
                            }
                        }
                        else if(itens[linha][coluna-1]==2){
                            mapa[linha][coluna-1]=66;
                            mapa[linha][coluna]=mapa_escondido[linha][coluna];
                            if(ppedras2<JOG){
                                ppedras2+=1;
                                cor2[linha][coluna-1]=6;
                                itens[linha][coluna-1]=10;
                            }
                        }
                        else if(itens[linha][coluna-1]==3){
                            mapa[linha][coluna-1]=66;
                            mapa[linha][coluna]=mapa_escondido[linha][coluna];
                            if(panimais2<JOG){
                                panimais2+=1;
                                cor2[linha][coluna-1]=6;
                                itens[linha][coluna-1]=10;
                            }
                        }
                        else{
                            mapa[linha][coluna-1]=66;
                            mapa[linha][coluna]=mapa_escondido[linha][coluna];
                        }
                    }
                    else if(m[1] =='d' && coluna<24 && cor1[linha][coluna+1]!=2){
                        cont=1;
                        cor1[linha][coluna]=3;
                        if(itens[linha][coluna+1]==4){
                            mapa[linha][coluna+1]=66;
                            mapa[linha][coluna]=mapa_escondido[linha][coluna];
                            if(parvores<JOG){
                                parvores+=1;
                                cor2[linha][coluna+1]=6;
                                itens[linha][coluna+1]=10;
                            }
                        }
                        else if(itens[linha][coluna+1]==1){
                            mapa[linha][coluna+1]=66;
                            mapa[linha][coluna]=mapa_escondido[linha][coluna];
                            if(pgravetos2<JOG){
                                pgravetos2+=1;
                                cor2[linha][coluna+1]=6;
                                itens[linha][coluna+1]=10;
                            }
                        }
                        else if(itens[linha][coluna+1]==2){
                            mapa[linha][coluna+1]=66;
                            mapa[linha][coluna]=mapa_escondido[linha][coluna];
                            if(ppedras2<JOG){
                                ppedras2+=1;
                                cor2[linha][coluna+1]=6;
                                itens[linha][coluna+1]=10;
                            }
                        }
                        else if(itens[linha][coluna+1]==3){
                            mapa[linha][coluna+1]=66;
                            mapa[linha][coluna]=mapa_escondido[linha][coluna];
                            if(panimais2<JOG){
                                panimais2+=1;
                                cor2[linha][coluna+1]=6;
                                itens[linha][coluna+1]=10;
                            }
                        }
                        else{
                            mapa[linha][coluna+1]=66;
                            mapa[linha][coluna]=mapa_escondido[linha][coluna];
                        }
                    }       
                    m[1]=0;
                }
            }
        }
        E=pgravetos2;F=ppedras2;G=panimais2;H=parvores;
        mostra(mapa,cor1,itens,mapa_escondido,cor2,A,B,C,D,E,F,G,H);
    }
    cont=0;
    }
}
int main(){
    char mapa[TAM][TAM], mapa_escondido[TAM][TAM];
    int cor1[TAM][TAM], itens[TAM][TAM],cor2[TAM][TAM];
    int A=0,B=0,C=0,D=0,E=0,F=0,G=0,H=0;
    srand(time(NULL));
    incrementa(mapa,cor1,itens,mapa_escondido,cor2);
    mostra(mapa,cor1,itens,mapa_escondido,cor2,A,B,C,D,E,F,G,H);
    jogadas(mapa,cor1,itens,mapa_escondido,cor2,A,B,C,D,E,F,G,H);
}