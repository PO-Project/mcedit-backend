
#include "MceditBackend.hpp"

#include <ncurses.h>
#include <panel.h>

enum menu { bar , file , edit };

namespace backends{

    void MceditBackend::operator()(){
        
        //zmienne
        WINDOW* my_windows[3];
        PANEL* my_panels[3];

        initscr();

        my_windows[bar] = newwin(3,20,0,0);
        my_windows[file] = newwin(10,10,2,0);
        my_windows[edit] = newwin(10,10,2,9);

        for(int i = 0; i<3; i++)
            box(my_windows[i],0,0);
        
        my_panels[bar] = new_panel(my_windows[bar]); 

        update_panels();
        doupdate();

        getch();
        my_panels[file] = new_panel(my_windows[file]);
        update_panels();
        doupdate();

        getch();
        my_panels[edit] = new_panel(my_windows[edit]);
        update_panels();
        doupdate();

        getch();

        endwin();
    }
}
