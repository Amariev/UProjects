#include <iostream>
#include <time.h>
#include <conio.h>
#include <windows.h>

#define NC "\e[0m" // resetear colores
#define BLACK "\e[0;30m"
#define RED "\e[0;31m"
#define GREEN "\e[0;32m"
#define YELLOW "\e[0;33m"
#define BLUE "\e[0;34m"
#define MAGENTA "\e[0;35m"
#define CIAN "\e[0;36m"
#define WHITE "\e[0;37m"
//background
#define REDB "\e[41m"
#define YELLOWB "\e[0;43m"

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
char corazon = 3;

int movimiento;

int Pos_player[2], Pos_food[2];

char tablero;

int num_bucle = 1;

int enemy_life = 6;
int player_life = 3;

int cant_bloques=18, blocksX[23], blocksY[23];

//cola
int taillenght;
int tailX[150];
int tailY[150];

int puntaje_para_enemigo = 20;

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
    // std::cout << "\033[2J\033[1;1H";
    std::cout << YELLOW << "score: " << score << std::endl; 
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
                if (score > puntaje_para_enemigo)
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
    std::cout << "VIDA:" << std::endl;
    for (int i = 0; i < player_life; i++) {
        std::cout << WHITE << REDB << corazon << " " << NC;
    }
    std::cout << std::endl;
    if(score > puntaje_para_enemigo)
    {
        std::cout << "VIDAS DEL ENEMIGO:\n";
        for (int i = 0; i < enemy_life; i++) {
            std::cout << BLACK << REDB << corazon << " " << NC;
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
void loser()
{
    std::cout << BLUE;
    std::cout << "     _|_" << std::endl;
    std::cout << "    `-|-`" << std::endl;
    std::cout << "      |" << std::endl;
    std::cout << "  .-'~^~`-." << std::endl;
    std::cout << ".' _     _ `." << std::endl;
    std::cout << "| |_) | |_) |" << std::endl;
    std::cout << "| | \\ | |   |" << std::endl;
    std::cout << "|           |"<< std::endl;
    std::cout << "|           |" << std::endl;
    std::cout << "`=.........=`" << std::endl;
}
void victory()
{
    std::cout << "                      __    __    __    __" << std::endl;
    std::cout << "                     /  \\  /  \\  /  \\  /  \\" << std::endl;
    std::cout << "____________________/  __\\/  __\\/  __\\/  __\\_____________________________" << std::endl;
    std::cout << "____FELICIDADES____/  /__/  /__/  /__/  /______________GANASTE___________" << std::endl;
    std::cout << "                   | / \\   / \\   / \\   / \\  \\____" << std::endl;
    std::cout << "                   |/   \\_/   \\_/   \\_/   \\    o \\" << std::endl;
    std::cout << "                                           \\_____/--<" << std::endl;
}

void posicion_food()
{
    Pos_food[0] = rand() % H + 1;
    Pos_food[1] = rand() % W + 1;
}
void reset()
{
    Pos_player[0] = H / 2;
    Pos_player[1] = W / 2;
    posicion_food();
    taillenght = 0;

    if (player_life == 0) {
        GameOver = true;
    }
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
        if (score > puntaje_para_enemigo) {
            posicion_bloques();
            enemy_life--;
            if (enemy_life == 0) {
                GameOver = true;
            }
        }
    }

    //colisiones
    if (Pos_player[1] > W || Pos_player[1] <= 0 || Pos_player[0] > H || Pos_player[0] <= 0) {
        player_life--;
        reset();
    }

    for (int i = 0; i < taillenght; i++) {
        if (tailX[i] == Pos_player[0] && tailY[i] == Pos_player[1]) {
            player_life--;
            reset();
        }
    }
    
    for (int i = 0;  i < cant_bloques; i++) {
        if (blocksX[i] == Pos_player[0] && blocksY[i] == Pos_player[1]) {
            player_life--;
            reset();
        }
    }
}

int main(){

    std::cout << "\033[2J\033[1;1H";
    srand(time(0));
    Pos_player[0] = H / 2;
    Pos_player[1] = W / 2;
    posicion_food();
    while(!GameOver)
    {
        delay (1);
        input();
        fisicas();
        std::cout << "\033[2J\033[1;1H";
        if (score > puntaje_para_enemigo) {
            enemy();
        }
        dibujar();

        if (num_bucle % 300 == 0){
            posicion_food();
        }
        num_bucle++;
    }
    if (player_life == 0)
    {
        loser();
    }
    else if (enemy_life == 0) {
        victory();
    }
}

