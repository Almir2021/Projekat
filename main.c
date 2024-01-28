/*#include <stdio.h>




int main(void) {

  for(int i=0;i<32;i++){
    for(int j=0;j<24;j++){
     
      if (j>7 && j<16  ){
        printf("#");
      }
      
      else { printf(".");} 
    }
    printf("\n");
  }
  
  printf("Hello World\n");
  return 0;
}  */
#include <stdio.h>
#include <ncurses.h>

int main(void) {
    initscr();  // Initialize ncurses
    raw();      // Disable line buffering
    keypad(stdscr, TRUE);  // Enable special keys (like arrows)

    int x = 0;  // Initial X position
    int y = 0;  // Initial Y position

    while (1) {
        clear();  // Clear the screen

        for (int i = 0; i < 32; i++) {
            for (int j = 0; j < 24; j++) {
                if (i == y && j == x) {
                    printw("$");  // Print the movable character at its current position
                } else if (j > 7 && j < 16) {
                    printw("#");
                } else {
                    printw(".");
                }
            }
            printw("\n");
        }

        refresh();  // Refresh the screen

        int ch = getch();  // Get the pressed key
        switch (ch) {
            case KEY_UP:
                y = (y - 1 + 32) % 32;  // Move up
                break;
            case KEY_DOWN:
                y = (y + 1) % 32;  // Move down
                break;
            case KEY_LEFT:
                x = (x - 1 + 24) % 24;  // Move left
                break;
            case KEY_RIGHT:
                x = (x + 1) % 24;  // Move right
                break;
            case 'q':
                endwin();  // End ncurses
                return 0;
        }
    }

    endwin();  // End ncurses
    return 0;}