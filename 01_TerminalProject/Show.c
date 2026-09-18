#include <curses.h>
#include <stdlib.h>
#include <string.h>

#define DX 7
#define DY 3

int main(int argc, char *argv[]) {
        WINDOW *frame, *win;
        FILE *file;
        file = fopen(argv[1], "r");

        char str[512];
        char c = 0;

        initscr();
        noecho();
        cbreak();

        frame = newwin(LINES - 2*DY, COLS - 2*DX, DY, DX);
        box(frame, 0, 0);
        mvwaddstr(frame, 0, (int)((COLS - 2*DX - 5) / 2), argv[1]);
        wrefresh(frame);

        win = newwin(LINES - 2*DY - 2, COLS - 2*DX-2, DY+1, DX+1);
        keypad(win, TRUE);
        scrollok (win, TRUE);

        int line_cnt = 0;

        while(fgets(str, sizeof(str), file) != NULL && line_cnt < LINES - 2*DY - 2){
            str[strcspn(str, "\n")] = '\0';
            str[strcspn(str, "\r")] = '\0';
            wprintw(win, "\n%d: %s", line_cnt + 1, str);
            line_cnt++;
        }
        while((c = wgetch(win)) != 27){
            if(c == 32 && fgets(str, sizeof(str), file) != NULL){
                str[strcspn(str, "\n")] = '\0';
                str[strcspn(str, "\r")] = '\0';
                wprintw(win, "\n%d: %s", line_cnt + 1, str);
                line_cnt++;
            }
        }
        delwin(win);
        delwin(frame);
        endwin();
        fclose(file);
        return 0;
}
