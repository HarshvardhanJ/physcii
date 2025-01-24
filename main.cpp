#include <sys/ioctl.h>
#include <stdio.h>
#include <unistd.h>

int box(int rows, int cols){
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            if (i == 0 || i == rows - 1){
                if (j == 0 || j == cols - 1){
                    printf("+");
                } else {
                    printf("-");
                }
            } else {
                if (j == 0 || j == cols - 1){
                    printf("|");
                } else {
                    printf(" ");
                }
            }
        }
        printf("\n");
    }
    return 0;
}






int main (int argc, char **argv)
{
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);

    box(w.ws_row-5, w.ws_col-5);

    return 0; 
}
