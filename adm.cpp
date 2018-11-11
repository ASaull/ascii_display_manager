#include <iostream>
#include <ncurses.h>
#include <string>
#include <cstring>
#include <list>

//for the time of day
#include <ctime>
#include <ratio>
#include <chrono>

using namespace std;


WINDOW *create_newwin(int height, int width, int starty, int startx)
{
    WINDOW *local_win;

    local_win = newwin(height, width, starty, startx);
    box(local_win, 0, 0);
    wrefresh(local_win);

    return local_win;
}

int main(void)
{
    //colour stuff
    start_color();
    init_pair(1, COLOR_WHITE, COLOR_BLUE);
    bkgd(COLOR_PAIR(1));

    refresh();

    WINDOW *main;

    int win_startx, win_starty, win_width, win_height;
    int ascii_starty, ascii_startx;
    int ch;
    start_color();
    initscr();
    cbreak();
    
    //window params
    win_height = LINES / 4;
    win_width = COLS / 2;
    win_starty = 2 * (LINES - win_height) / 3;
    win_startx = (COLS - win_width) / 2;
    
    //ascii params
    std::list <string> ascii = {" 8 8888 8 888888888o.    8 8888 8 888888888o.       8 8888 8 8888      88        ,8.       ,8.         ", " 8 8888 8 8888    `88.   8 8888 8 8888    `^888.    8 8888 8 8888      88       ,888.     ,888.", " 8 8888 8 8888     `88   8 8888 8 8888        `88.  8 8888 8 8888      88      .`8888.   .`8888.", " 8 8888 8 8888     ,88   8 8888 8 8888         `88  8 8888 8 8888      88     ,8.`8888. ,8.`8888.", " 8 8888 8 8888.   ,88'   8 8888 8 8888          88  8 8888 8 8888      88    ,8'8.`8888,8^8.`8888.", " 8 8888 8 888888888P'    8 8888 8 8888          88  8 8888 8 8888      88   ,8' `8.`8888' `8.`8888.", " 8 8888 8 8888`8b        8 8888 8 8888         ,88  8 8888 8 8888      88  ,8'   `8.`88'   `8.`8888.", " 8 8888 8 8888 `8b.      8 8888 8 8888        ,88'  8 8888 ` 8888     ,8P ,8'     `8.`'     `8.`8888.", " 8 8888 8 8888   `8b.    8 8888 8 8888    ,o88P'    8 8888   8888   ,d8P ,8'       `8        `8.`8888.", " 8 8888 8 8888     `88.  8 8888 8 888888888P'       8 8888    `Y88888P' ,8'         `         `8.`8888."};
    std::list <string> ascii2 = { "▇▇▇▇▇▇▇▇", "▇▇▇▇▇▇▇▇","  ▇▇▇▇  ", "  ▇▇▇▇  ","  ▇▇▇▇  ", "  ▇▇▇▇  ","▇▇▇▇▇▇▇▇", "▇▇▇▇▇▇▇▇" };
    ascii_starty = (LINES - ascii.size()) / 3;
    ascii_startx = (COLS - ascii.front().length()) / 2;


    refresh();

    main = create_newwin(win_height, win_width, win_starty, win_startx);

    //printing each line of the ascii thing seperately, so they can be centred
    int i = 0;
    for(string line : ascii)
    {
        mvprintw(ascii_starty + i, ascii_startx, line.c_str());
        i++;
    }

    //Welcome message to be "typed" by the computer
    time_t theTime = time(NULL);
    struct tm *aTime = localtime(&theTime);

    int hour = aTime->tm_hour;
    //if (hour == 
    string timeOfDay = "evening";
    string welcome = "Good " + timeOfDay + " saull. Please enter your password to begin.";

    move(win_starty + 1, win_startx + 1);
    refresh();

    printw(welcome.c_str());
    
    // move the cursor down for the user to enter their password
    move(win_starty + (win_height / 2), (COLS / 2) - 4);

    /*
    for (const char letter : welcome.c_str())
    {
        //printw(letter);
    }*/

    while((ch - getch()) != 'q')
    {

    }

    endwin();
    return 0; 
}


