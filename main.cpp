#include "HMI.hpp"

int main()
{
    int ch;

    initscr();
    raw();
    keypad(stdscr, TRUE);
    noecho();

    HMI hmi;
    while ((ch = getch()) != '#') // type 2 times '#' to exit the loop
    {
        switch (ch)
        {
        case KEY_UP:
            hmi.up();
            break;

        case KEY_DOWN:
            hmi.down();
            break;

        case KEY_RIGHT:
        case KEY_LEFT: // both used as "OK"
            hmi.ok();
            break;

        default:
            printw("%c", ch);
        }
    }
    refresh();
    getch();
    endwin();
}