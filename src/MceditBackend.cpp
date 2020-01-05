
#include "MceditBackend.hpp

#include <ncurses.h>

namespace backends{

    void MceditBackend::operator()(){
        initscr();
        printw("Hello world!\n");
        refresh();
        getchar();
        endwin();
    }
}
