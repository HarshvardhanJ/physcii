#include <ncurses.h>
#include <vector>
#include <utility>
#include <unistd.h> 
#include <sys/ioctl.h>

int main() {
    // Initialize ncurses
    initscr();
    cbreak();
    noecho();
    curs_set(0);

    // Dimensions of the box on the screen

    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);

    int width  = w.ws_col;
    int height = w.ws_row;

    // Define the path for the square (y,x) positions
    std::vector<std::pair<int,int>> path = {
        {3, 3}, {3, 10}, {3, 20}, {8, 20}, {8, 10}, {8, 3}
    };

    // Size of the moving square
    int squareSize = 3;

    // Time delay between frames (microseconds)
    int delayUs = 300000;

    // Go through the array once
    for (auto &pos : path) {
        clear();

        // Draw a simple box border
        for (int x = 0; x < width; x++) {
            mvaddch(0, x, '-');
            mvaddch(height - 1, x, '-');
        }
        for (int y = 0; y < height; y++) {
            mvaddch(y, 0, '|');
            mvaddch(y, width - 1, '|');
        }

        // Draw the square in the new position
        for (int row = 0; row < squareSize; row++) {
            for (int col = 0; col < squareSize; col++) {
                mvaddch(pos.first + row, pos.second + col, '#');
            }
        }

        // Refresh to display changes
        refresh();

        usleep(delayUs);
    }

    // Terminate ncurses mode
    endwin();
    return 0;
}
