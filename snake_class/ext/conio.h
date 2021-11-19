#ifndef CONIO_
#define CONIO_

#include <termios.h>
#include <unistd.h>
#include <cstdio>
#include <sys/ioctl.h>

char getch();
bool kbhit();

inline char getch(){
    termios oldAttr;

    tcgetattr(STDIN_FILENO, &oldAttr);

    termios newAttr = oldAttr;
    newAttr.c_lflag &= ~ (ICANON | ECHO);

    tcsetattr(STDIN_FILENO, TCSANOW, &newAttr);
    char c = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldAttr);

    return c;
}

inline bool kbhit(){
    static bool first=true;
    
    if (first){
        setbuf(stdin, NULL);

        termios newAttr;

        tcgetattr(STDIN_FILENO, &newAttr);

        newAttr.c_lflag &= ~ (ICANON | ECHO);
        tcsetattr(STDIN_FILENO,TCSANOW, &newAttr);

        first = false;
    }
    int bytes;  
    ioctl(STDIN_FILENO, FIONREAD, &bytes);
    return bytes>0;
}
#endif
