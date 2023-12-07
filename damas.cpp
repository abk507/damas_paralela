#include <bits/stdc++.h>
using namespace std;

void printTabuleiro(int tabuleiro[8][8]){
    string letras = "abcdefgh";
    for(int i = 0; i < 8; i++){
        cout << letras[i];
        for(int j = 0; j < 8; j++){
            cout << "[ ";
            if (tabuleiro[j][i] != 0){

                if (tabuleiro[j][i] != 1){
                    cout << 'X';
                }
                else{
                    cout << 'O';
                }
            }
            else{
                cout << " ";
            }
            cout << " ] ";
        }
        cout << endl;
    }
    for(int j = 0; j < 8; j++){
        cout << "   " << j+1 << "  ";
    }
    cout << "\n\n";
}

int main(){
    int aux_tabuleiro[8][8] = {
        1, 0, 1, 0, 1, 0, 1, 0, 
        0, 1, 0, 1, 0, 1, 0, 1,
        1, 0, 1, 0, 1, 0, 1, 0, 
        0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0,
        0, -1, 0, -1, 0, -1, 0, -1,
        -1, 0, -1, 0, -1, 0, -1, 0, 
        0, -1, 0, -1, 0, -1, 0, -1  
    }, tabuleiro[8][8];
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            tabuleiro[i][j] = aux_tabuleiro[j][i];
        }
    }

    printTabuleiro(tabuleiro);

    int vez = -1;
    int over = false;
    string vencedor = "empate";

    while (!over){
        string jogada;
        cin >> jogada;
        int y = jogada[0] - 'a';
        int x = jogada[1] - '0' - 1;
        cout << x+1 << ", " << y+1 << " " << tabuleiro[x][y] << endl;
        if (tabuleiro[x][y] == vez){
            if (jogada[2] == 'e' && x > 0){
                if (tabuleiro[x-1][y+vez] == 0){
                    cout << "andei" << endl;
                    tabuleiro[x][y] = 0;
                    tabuleiro[x-1][y+vez] = vez;
                    vez *= -1;
                }
                else if ((tabuleiro[x-1][y+vez] == vez * -1) && (x > 1) && (tabuleiro[x-2][y+vez*2] == 0)){
                    cout << "tomei" << endl;
                    tabuleiro[x][y] = 0;
                    tabuleiro[x-1][y+vez] = 0;
                    tabuleiro[x-2][y+vez*2] = vez;
                    vez *= -1;
                }
            }
            else if (jogada[2] == 'd' && x < 7){
                if (tabuleiro[x+1][y+vez] == 0){
                    tabuleiro[x][y] = 0;
                    tabuleiro[x+1][y+vez] = vez;
                    vez *= -1;
                }
                else if ((tabuleiro[x+1][y+vez] == vez * -1) && (x < 6) && (tabuleiro[x+2][y+vez*2] == 0)){
                    tabuleiro[x][y] = 0;
                    tabuleiro[x+1][y+vez] = 0;
                    tabuleiro[x+2][y+vez*2] = vez;
                    vez *= -1;
                }
            }
            else{
                cout << "Direção inválida\n\n";
            }
        }
        else{
            cout << "Casa inválida\n\n";
        }
        printTabuleiro(tabuleiro);
        cout << "Vez do " << vez << endl;
    }
}