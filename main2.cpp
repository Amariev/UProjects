#include <iostream>
#include <ctime>
#include <cmath>

int main(){
    // presentación
    std::cout << "Juego del tres en raya\n";

    std::string player1, player2, current_player;
    std::cout << "Nombre del jugador 1: ";
    std::cin >> player1;
    player2 = "IA";
    std::cout << "Jugador 1: " << player1 << " " << "jugador 2: " << player2 << std::endl;

    char pieza1, pieza2, current_pieza;

    // elección de piezas 'X' o 'O' 
    // ascii 'X' = 88 y 'O' = 79
    do
    {
        std::cout << "Jugador 1 elija pieza a jugar('X' o 'O'): ";
        std::cin >> pieza1;
    } while (pieza1 != 'X' && pieza1 != 'O');
    
    if (pieza1 == 'X') {pieza2 = 'O';}
    else {pieza2 = 'X';}
    std::cout << player1 << ": " << pieza1 << " " << player2 << ": " << pieza2 << std::endl;

    // ascii del 1 al 9 equivale del 49 al 57
    char c1='1', c2='2', c3='3', c4='4', c5='5', c6='6', c7='7', c8='8', c9='9';

    bool play = true, casilla_repetida = false, ia_juega = true;
    int current = 1;


    while(play){

	    // win
	    if (c1+c2+c3 == 264 || c4+c5+c6 == 264 || c7+c8+c9 == 264 || c1+c4+c7 ==264 || c2+c5+c8 == 264 || c3+c6+c9==264 || c3+c5+c7==264 || c1+c5+c9==264){
		    std::cout << "Felicitaciones " << current_player << ", has ganado\n";
		    play = false;} 
	    if (c1+c2+c3 == 237 || c4+c5+c6 == 237 || c7+c8+c9 == 237 || c1+c4+c7 ==237 || c2+c5+c8 == 237 || c3+c6+c9==237 || c3+c5+c7==237 || c1+c5+c9==237){
		    std::cout << "Felicitaciones " << current_player << ", has ganado\n";
		    play = false;}

	// empate 
	// considerando que siempre va a haber 4'X' y 4'Y' hay dos opciones de empate 
        if ((c1+c2+c3+c4+c5+c6+c7+c8+c9 == 747 || c1+c2+c3+c4+c5+c6+c7+c8+c9 == 756) && play==true){
		std::cout << "\nEl juego a terminado en empate\n";
		play = false;}     			

        //Tablero
        std::cout << " " << c1 << " " << "|" << " " << c2 << " " << "|" << " " << c3 << " \n";
        std::cout << "___|___|___\n";
        std::cout << " " << c4 << " " << "|" << " " << c5 << " " << "|" << " " << c6 << " \n";
        std::cout << "___|___|___\n";
        std::cout << " " << c7 << " " << "|" << " " << c8 << " " << "|" << " " << c9 << " \n";


        // current, para pieza y jugador
        if (current % 2 == 1){
            current_pieza = pieza1;
            current_player = player1;
            current ++;
        } else {
            current_pieza = pieza2;
            current_player = player2;
            current ++;
        }

	// Option es el numero de casilla que elija el jugadora actual
        int option;
	// do while para ver si no repite casilla
	// switch para el seleccionamiento de casilla
    do{
        if(play == true){
               
                if (current_player == player1){
                  std::cout << current_player << " elije el numero de casilla: ";
                std::cin >> option;}

                else 
                {srand(time(NULL));
                 option = rand()% 9 + 1;
		 if(ia_juega){
			std::cout << "turno de IA" << std::endl;
		 }
                 // std::cout << current_player << " elije el numero de casilla: "<<option << std::endl;
                
                }
                
            // revisemos si  "option" se eligio de manera correcta
            while (option >9 or option == 0){
            
                std::cout << "Ingrese una opcion valida. Intente nuevamente: ";
                std::cin >> option;}
              
            switch (option) {
            case 1 :
                if (c1>70){casilla_repetida = true;}
                else{c1 = current_pieza;                
                casilla_repetida=false;}
                break;
            case 2 :
                if (c2>70){casilla_repetida = true;}
                else{c2 = current_pieza; casilla_repetida=false;}
                break;
            case 3 :
                if (c3>70){casilla_repetida = true;}
                else{c3 = current_pieza; casilla_repetida=false;}
                break;
            case 4 :
                if (c4>70){casilla_repetida = true;}
                else{c4= current_pieza; casilla_repetida=false;}
                break;
            case 5 :
                if (c5>70){casilla_repetida = true;}
                else{c5 = current_pieza; casilla_repetida=false;}
                break;
            case 6 :
                if (c6>70){casilla_repetida = true;}
                else{c6 = current_pieza; casilla_repetida=false;}
                break;
            case 7 :
                if (c7>70){casilla_repetida = true;}
                else{c7 = current_pieza; casilla_repetida=false;}
                break;
            case 8 :
                if (c8>70){casilla_repetida = true;}
                else{c8 = current_pieza;casilla_repetida=false;}
                break;
            case 9 :
                if (c9>70){casilla_repetida = true;}
                else{c9 = current_pieza; casilla_repetida=false;}
                break;
            }
	}    
            if (casilla_repetida && current_player == player1){std::cout << "Esa casilla ya fue elejida\n";}
	       else if (casilla_repetida){ia_juega = false;}
    } while (casilla_repetida);

    //nivel 1 random


    }
    return 0;
}

