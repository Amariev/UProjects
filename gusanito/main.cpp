#include <iostream>
#include <conio.h>
#include <windows.h>

bool GameOver = false;

const int W = 60, H = 15;

int caracter_presionado = 0;
const int ARRIBA  = 72;
const int ABAJO  = 80;
const int IZQUIERDA  = 75;
const int DERECHA  = 77;
const int ESC = 27;

int movimiento;

int Pos_player[2];

char tablero;

void dibujar() // dibujar el juego(tablero, gusano, comida)
{
    std::cout << "movimiento: " << movimiento << std::endl; 
    for (int i = 0; i < H + 2 ; ++i) {
        for (int j = 0; j < W + 2; ++j) {
            if (i==0 || i == H+1) {
                std::cout << "#";
            }
            else if (j==0 || j == W+1)
            {
                std::cout << "#";
            }
            else {
                // std::cout << " ";
                if (i == Pos_player[0] && j == Pos_player[1]) {
                    std::cout << "S";
                } else { std::cout << " ";}
            }
        }
        std::cout << std::endl;
    }
}

void input() // entrada 
{
    if (kbhit()) {
        caracter_presionado = getch();
        switch (caracter_presionado) {
            case ARRIBA:
                movimiento = ARRIBA;
                break;
            case ABAJO:
                movimiento = ABAJO;
                break;
            case IZQUIERDA:
                movimiento = IZQUIERDA;
                break;
            case DERECHA:
                movimiento = DERECHA;
                break;
        }
    } 
}
void game_logic() // la logica del juego
{
    // movimiento
    /* switch (movimiento) {
        case ARRIBA:
            Pos_player[] 
            break;
    } */
    // comida
    // cola del gusano
    //
}

int main(){

    Pos_player[0] = H / 2;
    Pos_player[1] = W / 2;
    while(!GameOver)
    {
        // Sleep(100);
        input();
        dibujar();
    }
}
