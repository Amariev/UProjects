#include <iostream>

int main(){
    std::cout << "Juego del tres en raya\n";

    std::string player1, player2, current_player;
    std::cout << "Nombre del jugador 1: ";
    std::cin >> player1;
    std::cout << "Nombre del jugador 2: ";
    std::cin >> player2;

    char pieza1, pieza2, current_pieza;
    do
    {
        std::cout << "Jugador 1 elija pieza a jugar('X' o 'O'): ";
        std::cin >> pieza1;
    } while (pieza1 != 'X' && pieza1 != 'O');
    
    if (pieza1 == 'X') {pieza2 = 'O';}
    else {pieza2 = 'X';}

    char c1='1', c2='2', c3='3', c4='4', c5='5', c6='6', c7='7', c8='8', c9='9';

    bool play = true;
    int current = 1;


    while(play){

	    if (c1+c2+c3 == 264 || c4+c5+c6 == 264 || c7+c8+c9 == 264 || c1+c4+c7 ==264 || c2+c5+c8 == 264 || c3+c6+c9==264 || c3+c5+c7==264 || c1+c3+c9==264){
		    std::cout << "Felicitaciones " << current_player << "has ganado\n";
		    play = false;} 
	    if (c1+c2+c3 == 237 || c4+c5+c6 == 237 || c7+c8+c9 == 237 || c1+c4+c7 ==237 || c2+c5+c8 == 237 || c3+c6+c9==237 || c3+c5+c7==237 || c1+c3+c9==237){
		    std::cout << "Felicitaciones " << current_player << "has ganado\n";
		    play = false;}


        //Tablero
        std::cout << " " << c1 << " " << "|" << " " << c2 << " " << "|" << " " << c3 << " \n";
        std::cout << "___|___|___\n";
        std::cout << " " << c4 << " " << "|" << " " << c5 << " " << "|" << " " << c6 << " \n";
        std::cout << "___|___|___\n";
        std::cout << " " << c7 << " " << "|" << " " << c8 << " " << "|" << " " << c9 << " \n";


        // current
        if (current % 2 == 1){
            current_pieza = pieza1;
            current_player = player1;
            current ++;
        } else {
            current_pieza = pieza2;
            current_player = player2;
            current ++;
        }

        char option;
	if(play == true){
        	std::cout << current_player << " elije el numero de casilla: ";
        	std::cin >> option;}

        switch (option) {
        case '1':
            c1 = current_pieza;
            break;
        case '2':
            c2 = current_pieza;
            break;
        case '3':
            c3 = current_pieza;
            break;
        case '4':
            c4 = current_pieza;
            break;
        case '5':
            c5 = current_pieza;
            break;
        case '6':
            c6 = current_pieza;
            break;
        case '7':
            c7 = current_pieza;
            break;
        case '8':
            c8 = current_pieza;
            break;
        case '9':
            c9 = current_pieza;
            break;
        }
	// win

    }
    return 0;
}
