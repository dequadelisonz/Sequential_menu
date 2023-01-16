#ifndef HMI_hpp
#define HMI_hpp

/*STL includes*/
#include <iostream>
#include <ncursesw/ncurses.h>

/*ESP-IDF includes*/

/*This project includes*/
#include "Menu.hpp"

class HMI
{

private:
    const char *TAG = "HMI";

    MenuNS::MenuEntry<HMI> me1;
    MenuNS::MenuEntry<HMI> me2;
    MenuNS::MenuEntry<HMI> me3;
    MenuNS::MenuEntry<HMI> me4;
    MenuNS::MenuEntry<HMI> me5;

    MenuNS::MenuEntry<HMI> sme1;
    MenuNS::MenuEntry<HMI> sme2;
    MenuNS::MenuEntry<HMI> sme3;

    MenuNS::Menu _menu;
    MenuNS::Menu _subMenu1;
    MenuNS::MenuNavigator _menuNavigator;

    char _statusBar[128] = {0};

public:
    HMI() : _menu("Main", true),
            _subMenu1("Sub menu 1", false),
            _menuNavigator(&_menu)
    {
        me1.init(this, "voce 1");
        me2.init(this, "voce 2");
        me3.init(this, "voce 3");
        me4.init(this, "voce 4");
        me5.init(this, "voce 5");

        sme1.init(this, "sub voce 1");
        sme2.init(this, "sub voce 2");
        sme3.init(this, "sub voce 3");

        // me1.setActionUp(&HMI::action1up);
        me2.setActionUp(&HMI::action2up);
        me3.setActionUp(&HMI::action3up);
        me4.setActionUp(&HMI::action4up);
        me5.setActionUp(&HMI::action5up);

        // me1.setActionDown(&HMI::action1down);
        me2.setActionDown(&HMI::action2down);
        me3.setActionDown(&HMI::action3down);
        me4.setActionDown(&HMI::action4down);
        me5.setActionDown(&HMI::action5down);

        me1.setActionOK(&HMI::action1OK);
        me2.setActionOK(&HMI::actionEmpty);
        me3.setActionOK(&HMI::actionEmpty);
        me4.setActionOK(&HMI::actionEmpty);
        me5.setActionOK(&HMI::actionEmpty);

        sme1.setActionUp(&HMI::actionSub1up);
        sme2.setActionUp(&HMI::actionSub2up);
        sme3.setActionUp(&HMI::actionSub3up);

        sme1.setActionDown(&HMI::actionSub1down);
        sme2.setActionDown(&HMI::actionSub2down);
        sme3.setActionDown(&HMI::actionSub3down);

        sme1.setActionOK(&HMI::actionEmpty);
        sme2.setActionOK(&HMI::actionEmpty);
        sme3.setActionOK(&HMI::actionEmpty);

        _subMenu1.pushEntry(&sme1);
        _subMenu1.pushEntry(&sme2);
        _subMenu1.pushEntry(&sme3);

        _menu.pushEntry(&me1);
        _menu.pushEntry(&me2);
        _menu.pushEntry(&me3);
        _menu.pushEntry(&me4);
        _menu.pushEntry(&me5);
        _menu.pushEntry(&_subMenu1);

        print();
    };

    void print()
    {
        clear();
        printw("%s", _menuNavigator.getPrintout());
        printw("\n%s", _statusBar);
    }

    void setStatus(const char *str)
    {
        _statusBar[0] = '\0';
        strcat(_statusBar, "Ultimo comando: ");
        strcat(_statusBar, str);
    }

    void up()
    {
        _menuNavigator.up();
        print();
        setStatus("");
    }

    void down()
    {
        _menuNavigator.down();
        print();
        setStatus("");
    }

    void ok()
    {
        _menuNavigator.ok();
        print();
    }

    void action1up()
    {
        setStatus("voce 1 up!");
    }

    void action2up()
    {
        setStatus("voce 2 up!");
    }

    void action3up()
    {
        setStatus("voce 3 up!");
    }

    void action4up()
    {
        setStatus("voce 4 up!");
    }

    void action5up()
    {
        setStatus("voce 5 up!");
    }

    void action1down()
    {
        setStatus("voce 1 down!");
    }

    void action2down()
    {
        setStatus("voce 2 down!");
    }

    void action3down()
    {
        setStatus("voce 3 down!");
    }

    void action4down()
    {
        setStatus("voce 4 down!");
    }

    void action5down()
    {
        setStatus("voce 5 down!");
    }

    void action1OK()
    {
        me2.isActive() = !me2.isActive();
        setStatus(me2.isActive() ? "voce 2 attiva!" : "voce 2 non attiva!");
    }

    void actionSub1up()
    {
        setStatus("voce sub 1 up!");
    }

    void actionSub2up()
    {
        setStatus("voce sub 2 up!");
    }

    void actionSub3up()
    {
        setStatus("voce sub 3 up!");
    }

    void actionSub1down()
    {
        setStatus("voce sub 1 down!");
    }

    void actionSub2down()
    {
        setStatus("voce sub 2 down!");
    }

    void actionSub3down()
    {
        setStatus("voce sub 3 down!");
    }

    void actionEmpty()
    {
        setStatus("");
    }
};

#endif