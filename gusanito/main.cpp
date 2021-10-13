#include <iostream>
#include <time.h>
#include <conio.h>
#include <windows.h>

#define BLACK "\e[0;30m"
#define RED "\e[0;31m"
#define GREEN "\e[0;32m"
#define YELLOW "\e[0;33m"
#define BLUE "\e[0;34m"
#define MAGENTA "\e[0;35m"
#define CIAN "\e[0;36m"
#define WHITE "\e[0;37m"

bool GameOver = false;
int score = 0;

const int W = 30, H = 15;

int caracter_presionado = 0;
const int ARRIBA  = 72;
const int ABAJO  = 80;
const int IZQUIERDA  = 75;
const int DERECHA  = 77;
const int ESC = 27;

char barra = 219;
char head = 223;
char down = 220;
char bloque = 176;

int movimiento;

int Pos_player[2], Pos_food[2];

char tablero;

int num_bucle = 1;

int cant_bloques=18, blocksX[23], blocksY[23];

//cola
int taillenght;
int tailX[150];
int tailY[150];

void delay (int a)
{
    int add;
    int time;
    
    time = a * 100000000;

    for (int i = 0; i < time; i++)
    {
        add *= i;
        add++;
        add++;
    }
    
}
void enemy()
{
    std::cout << RED << "             " << down << "   " << down << "\n";
    std::cout <<"         "<<down<<barra<<down<<" "<<barra<<head<<barra<<head<<barra<<" "<<down<<barra<<down<<"\n";
    std::cout <<"        "<<head<<head<<barra<<barra<<barra<<barra<<down<<barra<<down<<barra<<barra<<barra<<barra<<head<<head<<"\n";
    std::cout << "             " << head << barra << head << barra << head <<"\n";
}

void posicion_bloques()
{
    for (int i = 0;  i< 7; i+=3) {
        blocksX[i] = rand() % (H-2) + 1;
        blocksY[i] = rand() % (W-2) + 1;
    
        blocksX[i+1] = blocksX[i];
        blocksX[i+2] = blocksX[i];

        blocksY[i+1] = blocksY[i] + 1;
        blocksY[i+2] = blocksY[i+1] + 1;
        
    }
    for (int i = 9; i < 16 ; i+=3) {
        blocksX[i] = rand() % (H-2) + 1;
        blocksY[i] = rand() % (W-2) + 1;
    
        blocksY[i+1] = blocksY[i];
        blocksY[i+2] = blocksY[i];

        blocksX[i+1] = blocksX[i] + 1;
        blocksX[i+2] = blocksX[i+1] + 1;
        
    }

}

void dibujar() // dibujar el juego(tablero, gusano, comida)
{
    // std::cout << "movimiento: " << movimiento << std::endl; 
    std::cout << YELLOW << "score: " << score << std::endl; 
    std::cout << "tail lenght: " << taillenght << std::endl; 
    for (int i = 0; i < H + 2 ; ++i) {
        for (int j = 0; j < W + 2; ++j) {
            if (i == Pos_player[0] && j == Pos_player[1]) 
            {
                std::cout << YELLOW << head;
            }
            else if (i==0 || i == H+1) 
            {
                std::cout << CIAN << barra;
            }
            else if (j==0 || j == W+1)
            {
                std::cout << CIAN << barra;
            }
            else if (i == Pos_food[0] && j == Pos_food[1])
            {
                 std::cout << RED "O";
            } 
            else{
                bool draw_tail = false;
                for(int k = 0; k < taillenght; k++)
                {
                    if (tailX[k] == i && tailY[k] == j) 
                    {
                        std::cout << YELLOW "@";
                        draw_tail = true;
                    }
                }
                bool draw_blocks = false;
                if (score > 20)
                {
                    for (int k = 0; k < cant_bloques; k++) 
                    {
                        if (blocksX[k] == i && blocksY[k] == j) {
                            std::cout << WHITE << bloque;
                            draw_blocks = true;
                        }    
                    }
                }
                if (!draw_tail && !draw_blocks) {
                    std::cout << " ";
                }
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

void posicion_food()
{
    Pos_food[0] = rand() % H + 1;
    Pos_food[1] = rand() % W + 1;
}

void fisicas() // la logica del juego
{
    // cola del gusano
    int TailPosX = tailX[0];
    int TailPosY = tailY[0];
    int TailPosX2, TailPosY2;

    tailX[0] = Pos_player[0];
    tailY[0] = Pos_player[1];

    for(int i = 1; i < taillenght; ++i){
        TailPosX2 = tailX[i];
        TailPosY2 = tailY[i];

        tailX[i] = TailPosX;
        tailY[i] = TailPosY;

        TailPosX = TailPosX2;
        TailPosY = TailPosY2;
    }

    // movimiento
    switch (movimiento) {
        case ARRIBA:
            Pos_player[0]--; 
            break;
        case ABAJO:
            Pos_player[0]++; 
            break;
        case IZQUIERDA:
            Pos_player[1]--; 
            break;
        case DERECHA:
            Pos_player[1]++; 
            break;
    }
    // comida
    if (Pos_player[0] == Pos_food[0] && Pos_player[1] == Pos_food[1]) {
        score += 10;
        posicion_food();
        taillenght++;
        if (score > 20) {
            posicion_bloques();
        }
    }

    //colisiones
    if (Pos_player[1] > W || Pos_player[1] <= 0 || Pos_player[0] > H || Pos_player[0] <= 0) {
        GameOver = true;
    }

    for (int i = 0; i < taillenght; i++) {
        if (tailX[i] == Pos_player[0] && tailY[i] == Pos_player[1]) {
           GameOver = true; 
        }
    }
    
    for (int i = 0;  i < cant_bloques; i++) {
        if (blocksX[i] == Pos_player[0] && blocksY[i] == Pos_player[1]) {
            GameOver = true;
        }
    }
}

int main(){

    srand(time(0));
    Pos_player[0] = H / 2;
    Pos_player[1] = W / 2;
    posicion_food();
    while(!GameOver)
    {
        // if(num_bucle % 10000 == 0)
        {
            delay (1);
            input();
            fisicas();
            // tail();
            if (score > 20) {
                enemy();
            }
            dibujar();
            std::cout << "X: " << Pos_food[0] << " Y: " << Pos_food[1] << std::endl;

            if (num_bucle % 300 == 0){
                posicion_food();
            }
        }
        num_bucle++;
    }
}

