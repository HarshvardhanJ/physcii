#include <ncurses.h>
#include <vector>
#include <utility>
#include <unistd.h> 
#include <sys/ioctl.h>

int main() {
    initscr();
    cbreak();
    noecho();
    curs_set(0);


    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);

    int width  = w.ws_col;
    int height = w.ws_row;

    std::vector<std::pair<int,int>> path = {
        {3, 3}, {3, 50}, {3, 20}, {8, 20}, {8, 10}, {8, 3}
    };

    int squareSize = 3;

    int delayUs = 300000;

    for (auto &pos : path) {
        clear();

        for (int x = 0; x < width; x++) {
            mvaddch(0, x, '-');
            mvaddch(height - 1, x, '-');
        }
        for (int y = 0; y < height; y++) {
            mvaddch(y, 0, '|');
            mvaddch(y, width - 1, '|');
        }

        for (int row = 0; row < squareSize; row++) {
            for (int col = 0; col < squareSize; col++) {
                mvaddch(pos.first + row, pos.second + col, '#');
            }
        }

        refresh();

        usleep(delayUs);
    }

    endwin();
    return 0;
}
