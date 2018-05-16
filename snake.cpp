#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

void gotoxy(int x, int y)
{
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),(COORD){x,y});
}

void printcobra(int posx[50],int posy[50]){
    for(int i=0;i<50;i++){
        if(posx[i]!=0&&posy[i]!=0){
            gotoxy(posx[i],posy[i]);
            printf("%c",219);
        }
    }


}

void apagarcobra(int posx[50],int posy[50]){
    for(int i=0;i<50;i++){
        if(posx[i]!=0&&posy[i]!=0){
            gotoxy(posx[i],posy[i]);
            printf(" ");
        }
    }


}

int main(){
    srand(time(NULL));
    int posx[50]={0};
    int posy[50]={0};
    int macax,macay,mov=100,i=5,d=2,pontuacao=0;
    char tecla='P';
    //Menu
    printf("Snake em C\n\n");
    printf("Lembre de deixar o jogo em tela cheia\n\n");
    system("pause");
    system("cls");
    //Barras de contorno da tela
    for(int x=0;x<=100;x++){ //Horizontal superior
        gotoxy(x,0);
        printf("%c",219);
    }
    for(int x=0;x<=100;x++){ //Horizontal inferior
        gotoxy(x,50);
        printf("%c",219);
    }
    for(int y=0;y<51;y++){ //Vertical anterior
        gotoxy(0,y);
        printf("%c",219);
    }
    for(int y=0;y<51;y++){ //Vertical posterior
        gotoxy(100,y);
        printf("%c",219);
    }
    //Cobrinha inicial
    for(int i=0;i<6;i++){
        posx[i]=i+5;
        posy[i]=8;
    }
    //Posicao inicial da maca
    macax=rand()%75+3;
    macay=rand()%45+3;
    gotoxy(macax,macay);
    printf("*");
    printcobra(posx,posy);
    //Movimentacao
    do
    {
    apagarcobra(posx,posy);
     if(d==0)posx[i]--;
     if(d==1)posy[i]--;
     if(d==2)posx[i]++;
     if(d==3)posy[i]++;
    if(posx[i]==macax&&posy[i]==macay){
        if(posx[i]==posx[i-1]){
            posx[i+1]=posx[i];
            if(posy[i]>posy[i-1]){
                posy[i+1]=posy[i]+1;
            }
            else{
                posy[i+1]=posy[i]-1;
            }
        }
        if(posy[i]==posy[i-1]){
            posy[i+1]=posy[i];
            if(posx[i]>posx[i-1]){
                posx[i+1]=posx[i]+1;
            }
            else{
                posx[i+1]=posx[i]-1;
            }
        }
        i++;
        pontuacao++;
    macax=rand()%75+3;
    macay=rand()%45+3;
    gotoxy(macax,macay);
    printf("*");
    printcobra(posx,posy);
     }
     else{
        for(int p=0;p<i;p++){
        posx[p]=posx[p+1];
        posy[p]=posy[p+1];
    }
     }
    printcobra(posx,posy);
    gotoxy(20,50);
    printf("Pontuacao: %d",pontuacao);
     Sleep(mov);
    if (kbhit()){
     tecla=getch();
     if(tecla=='K')d=0;
     if(tecla=='H')d=1;
     if(tecla=='M')d=2;
     if(tecla=='P')d=3;
     }

     for(int p=0;p<(i-1);p++){
        if(posx[i]==posx[p]&&posy[i]==posy[p]){
            tecla='s';
        }
     }
     if(posx[i]==0||posx[i]==100||posy[i]==0||posy[i]==50){
        tecla='s';
    }
     }while(tecla!='s');


system("cls");
printf("Cabou o jogo");


getchar();
    return 0;
}
