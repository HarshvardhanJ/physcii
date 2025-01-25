#include <sys/ioctl.h>
#include <stdio.h>
#include <unistd.h>

typedef struct sprite_rectangle{
    int vel_x;
    int vel_y;
    int pos_x;
    int pos_y;
    char name;
}sprite_rectangle;

void create_rectangle( sprite_rectangle *rectangle, int row, int col, int name, int pos_x = 0, int pos_y = 0){
    rectangle->vel_x = row;
    rectangle->vel_y = col;
    rectangle->name = name;
    rectangle->pos_x = pos_x;
    rectangle->pos_y = pos_y;
}

int print_rectangle(sprite_rectangle *rectangle){
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
                printf("#");
            }

        printf("\n");
    }
    return 0;   
}

    

int box(int rows, int cols){

    // Creates a box with the given number of rows and columns

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
