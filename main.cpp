#include "help.h" //contains shape functions
#include <chrono> //header for timer
#include <iostream>
#include <thread>             // used with the chrono header
void box();                   // grid
void updategridmatch4right(); // updates the grid if 4 blocks match during right
                              // swap
void clsrandupdategridright(); // updates garbage value with shapes if any
void clsrandmatch4left(); // updates garbage value if any for 4 matching blocks
void clsrandsimpleleft();
void updategridsimpleleft();
void updategridmatch4left();
void updategridmatch4leftcir();

void shapes();
using namespace std;
int grid[8][8];
void timer() {
  int minutes = 2;
  int seconds = 0;
  for (; minutes != 0 && seconds != 0;) {
    cout << minutes << ":" << seconds;
    this_thread::sleep_for(chrono::seconds(1));
    cout << "\b\b\b\b";
    seconds--;
    if (seconds == 0) {
      minutes--;
      seconds = 59;
    }
  }
}

void shapex(int i, int j) {
  int x = j * 90, y = i * 90;

  myLinesp11(x + 10, y + 10, x - 5, y + 30, 0, 0, 0, 0, 0, 0); //   left slant
  myLinesp11(x - 5, y + 30, x - 20, y + 30, 0, 0, 0, 0, 0, 0); // left straight
  myLinesp11(x - 20, y + 30, x - 5, y + 50, 0, 0, 0, 0, 0, 0);
  myLinesp11(x - 5, y + 50, x - 20, y + 70, 0, 0, 0, 0, 0, 0);
  myLinesp11(x - 20, y + 70, x - 5, y + 70, 0, 0, 0, 0, 0, 0);
  myLinesp11(x - 5, y + 70, x + 10, y + 90, 0, 0, 0, 0, 0, 0);
  // second half
  myLinesp11(x + 10, y + 10, x + 25, y + 30, 0, 0, 0, 0, 0, 0);
  myLinesp11(x + 25, y + 30, x + 40, y + 30, 0, 0, 0, 0, 0, 0);
  myLinesp11(x + 40, y + 30, x + 25, y + 50, 0, 0, 0, 0, 0, 0);
  myLinesp11(x + 25, y + 50, x + 40, y + 70, 0, 0, 0, 0, 0, 0);
  myLinesp11(x + 40, y + 70, x + 25, y + 70, 0, 0, 0, 0, 0, 0);
  myLinesp11(x + 25, y + 70, x + 10, y + 90, 0, 0, 0, 0, 0, 0);
  //=======================================================

  // special lines
  myLinesp(x - 5, y + 50, x + 25, y + 50, 255, 0, 0, 255, 0, 0);
  myLinesp(x + 10, y + 10, x + 10, y + 90, 255, 201, 14, 255, 201, 14);
  myLinesp(x - 20, y + 30, x + 40, y + 70, 0, 162, 232, 0, 162, 232);
  myLinesp(x + 40, y + 30, x - 20, y + 70, 181, 230, 29, 181, 230, 29);
  //=========================================================
}
void shexa(int i, int j) {
  int x = j * 83, y = i * 83;
  myLine(x + 10, y + 10, x + 20, y, 255, 0, 0, 0, 0, 0);
  myLine(x + 20, y, x + 50, y, 255, 0, 0, 0, 0, 0);
  myLine(x + 50, y, x + 60, y + 10, 255, 0, 0, 0, 0, 0);

  myLine(x + 10, y + 10, x + 10, y + 30, 255, 0, 0, 0, 0, 0);
  myLine(x + 60, y + 10, x + 60, y + 30, 255, 0, 0, 0, 0, 0); // hexa 2

  myLine(x + 10, y + 30, x + 20, y + 40, 255, 0, 0, 0, 0, 0);
  myLine(x + 20, y + 40, x + 50, y + 40, 255, 0, 0, 0, 0, 0);
  myLine(x + 60, y + 30, x + 50, y + 40, 255, 0, 0, 0, 0, 0);
}
void rhombus(int i, int j) {
  int x = j * 83, y = i * 83;
  myLine(x, y + 30, x + 30, y, 128, 0, 225, 128, 0, 225);
  myLine(x + 30, y, x + 61, y + 31, 128, 0, 225, 128, 0, 225);
  myLine(x, y + 30, x + 30, y + 60, 128, 0, 225, 128, 0, 225);
  myLine(x + 30, y + 60, x + 60, y + 30, 128, 0, 225, 128, 0, 225);
  myLinex(x + 30, y + 27, x + 30, y + 29, 128, 0, 225, 128, 0, 225);
}
void scir(int i, int j) {
  int x = j * 83, y = i * 83;
  myEllipse1(x + 50, y + 40, x, y + 30, 255, 0, 0, 255, 255, 0);
  myEllipse1(x + 30, y + 10, x + 20, y + 60, 255, 0, 0, 255, 255, 0);

  myEllipse(x + 10, y + 20, x + 40, y + 50, 255, 0, 0, 250, 250, 0);
}
void hexa(int i, int j) {
  int x = j * 83, y = i * 83;
  myLine(x + 10, y + 30, x + 30, y, 255, 0, 0, 0, 0, 0);
  myLine(x + 30, y, x + 70, y, 255, 0, 0, 0, 0, 0);
  myLine(x + 70, y, x + 91, y + 31, 255, 0, 0, 0, 0, 0);
  myLine(x + 10, y + 30, x + 30, y + 60, 255, 0, 0, 0, 0, 0);
  myLine(x + 30, y + 60, x + 70, y + 60, 255, 0, 0, 0, 0, 0);
  myLine(x + 70, y + 60, x + 91, y + 30, 255, 0, 0, 0, 0, 0);
}
void rect(int i, int j) {
  int x = j * 83, y = i * 83;
  myRect(x, y + 10, x + 55, y + 40, 186, 160, 37, 239, 228, 176);
}

void cir(int i, int j) {
  int x = j * 83, y = i * 83;
  myEllipse(x, y, x + 50, y + 50, 0, 174, 0, 94, 255, 174);
}
void para(int i, int j) {
  int x = j * 83, y = i * 83;
  myLine(x - 3, y + 15, x + 45, y + 15, 255, 128, 128, 255, 128, 128);
  myLine(x + 7, y + 55, x + 55, y + 55, 255, 128, 128, 255, 128, 128);
  myLine(x + 55, y + 55, x + 45, y + 14, 255, 128, 128, 255, 128, 128);
  myLine(x + 7, y + 55, x - 3, y + 14, 255, 128, 128, 255, 128, 128);
  myLinexs(x + 31, y + 35, x + 21, y + 36, 255, 128, 128, 255, 128, 128);
}
void sq(int i, int j) {
  int x = j * 83, y = i * 83;
  myRect(x, y, x + 50, y + 50, 139, 23, 159, 238, 31, 180);
}
void elements(int a[][8]) // print random numbers in a 8x8 grid
{
  srand(time(NULL));
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      a[i][j] = rand() % 5 + 1; // assign random value from 1-5
    }
  }
}
int r = 0, c = 0; // global value for cursor row and column
void cursorout() {

  int x = 0;
  int y = 0; //
  int key = 0;
  //
  myLinec(x, y, x + 83, y, 121, 249, 94, 121, 249, 94);
  myLinec(x + 83, y, x + 83, y + 83, 121, 249, 94, 121, 249, 94); // cursor
  myLinec(x, y + 83, x + 83, y + 83, 121, 249, 94, 121, 249, 94);
  myLinec(x, y, x, y + 83, 121, 249, 94, 121, 249, 94);
  while (1) {
    if (isCursorKeyPressed(key)) // detect a key
    {
      myLinec(x, y, x + 83, y, 255, 220, 241, 255, 220, 241);
      myLinec(x + 83, y, x + 83, y + 83, 255, 220, 241, 255, 220,
              241); // remove the previous cursor trails
      myLinec(x, y + 83, x + 83, y + 83, 255, 220, 241, 255, 220, 241);
      myLinec(x, y, x, y + 83, 255, 220, 241, 255, 220, 241);

      // then move the cursor
      if (key == 1) // left
      {
        c--;

        if (x >= 0)
          x = x - 80;
      }
      if (key == 2) // up
      {
        r--;
        if (y >= 0)
          y = y - 80;
      }
      if (key == 3) //  right
      {
        c++;
        if (x <= 622)
          x = x + 80;
      }
      if (key == 4) // down
      {
        r++;
        if (y <= 622)
          y = y + 80;
      }
      if (key == 5) // if enter key is pressed
      {
        while (true) {
          if (isCursorKeyPressed(key)) {
            if (key == 1)

            {
              swap(grid[r][c], grid[r][c - 1]); // left

              //================================================================
              //================================================================
              //      4 SHAPES MATCHING SWAP
              //==================================================================
              //=================================================================

              if (grid[r][c - 1] == grid[r][c - 2] &&
                  grid[r][c - 1] == grid[r][c - 3] // update grid
                  && grid[r][c - 1] == grid[r][c - 4] && grid[r][c - 1] == 2 &&
                  grid[r][c - 2] == 2 && grid[r][c - 3] == 2 &&
                  grid[r][c - 4] == 2) {

                updategridmatch4leftcir();
                system("cls");
                shapes();
                //======done==========

              }

              else if (grid[r][c - 1] == grid[r][c - 2] &&
                       grid[r][c - 1] == grid[r][c - 3] // other conditions
                       && grid[r][c - 1] == grid[r][c - 4]) {
                clsrandmatch4left();
                updategridmatch4left();
              }

              //==========================================
              //==========================================
              //     SIMPLE LEFT SWAP
              //=======================================
              //========================================
              else if (grid[r][c - 1] ==
                           grid[r][c - 2] // check if swaps / Simple Left Swap
                       && grid[r][c - 1] == grid[r][c - 3]) {
                clsrandsimpleleft();
                updategridsimpleleft(); // other conditions

              }
              //===============================================================
              else if (grid[r][c - 1] == grid[r + 1][c - 1] &&
                       grid[r][c - 1] ==
                           grid[r + 2][c - 1]) // checks swap with up left
              {
                for (int i = 1; i <= 5; i++) {
                  if (grid[r - i][c - 1] != i) {
                    grid[r - i][c - 1] =
                        rand() % 5 + 1; // removal of garbage value
                  }
                  if (grid[r - 6][c - 1] != i) {
                    grid[r - 6][c - 1] = rand() % 5 + 1;
                  }
                  if (grid[r - 7][c - 1] != i) {
                    grid[r - 7][c - 1] = rand() % 5 + 1;
                  }
                }

                grid[r + 2][c - 1] = grid[r - 1][c - 1];
                grid[r + 1][c - 1] = grid[r - 2][c - 1];
                grid[r][c - 1] = grid[r - 3][c - 1]; // updating grids
                grid[r - 1][c - 1] = grid[r - 4][c - 1];
                grid[r - 2][c - 1] = grid[r - 5][c - 1];
                grid[r - 3][c - 1] = grid[r - 6][c - 1];
              }

              else if (grid[r][c - 1] == grid[r - 1][c - 1] &&
                       grid[r][c - 1] ==
                           grid[r - 2][c - 1]) // checks swap left down
              {

                for (int i = 1; i <= 5; i++) {
                  if (grid[r - i][c - 1] != i) {
                    grid[r - i][c - 1] =
                        rand() % 5 + 1; // removal of garbage value
                  }
                  if (grid[r - 6][c - 1] != i) {
                    grid[r - 6][c - 1] = rand() % 5 + 1;
                  }
                  if (grid[r - 7][c - 1] != i) {
                    grid[r - 7][c - 1] = rand() % 5 + 1;
                  }
                }

                grid[r + 2][c - 1] = grid[r - 1][c - 1];
                grid[r + 1][c - 1] = grid[r - 2][c - 1];
                grid[r][c - 1] = grid[r - 3][c - 1]; // updating grids
                grid[r - 1][c - 1] = grid[r - 4][c - 1];
                grid[r - 2][c - 1] = grid[r - 5][c - 1];
                grid[r - 3][c - 1] = grid[r - 6][c - 1];
              }
              //=======================================================
              else if (grid[r][c - 1] == grid[r + 1][c - 1] &&
                       grid[r][c - 1] == grid[r - 1][c - 1]) {
                for (int i = 1; i <= 5; i++) {
                  if (grid[r - i][c - 1] != i) {
                    grid[r - i][c - 1] =
                        rand() % 5 + 1; // removal of garbage value
                  }
                  if (grid[r - 6][c - 1] != i) {
                    grid[r - 6][c - 1] = rand() % 5 + 1;
                  }
                  if (grid[r - 7][c - 1] != i) {
                    grid[r - 7][c - 1] = rand() % 5 + 1;
                  }
                }

                grid[r + 2][c - 1] = grid[r - 1][c - 1];
                grid[r + 1][c - 1] = grid[r - 2][c - 1];
                grid[r][c - 1] = grid[r - 3][c - 1]; // updating grids
                grid[r - 1][c - 1] = grid[r - 4][c - 1];
                grid[r - 2][c - 1] = grid[r - 5][c - 1];
                grid[r - 3][c - 1] = grid[r - 6][c - 1];

              }

              else {
                cout << "Sorry no swap";
                Sleep(100);
                swap(grid[r][c - 1], grid[r][c]);
                system("cls");
                box();
              } // swap back if no matchaa
              this_thread::sleep_for(100ms);
              system("cls");
              box();

              break;
            }
            if (key == 2) // up
            {
              swap(grid[r][c], grid[r - 1][c]);
              if (grid[r - 1][c] == grid[r - 2][c]     // check if it swaps
                  && grid[r - 1][c] == grid[r - 3][c]) // simple up
              {
                for (int i = 1; i <= 5; i++) {
                  if (grid[r - i][c] != i) {
                    grid[r - i][c] = rand() % 5 + 1;
                  }
                  if (grid[r - 6][c] != i) {
                    grid[r - 6][c] = rand() % 5 + 1;
                  }
                  if (grid[r - 7][c] != i) {
                    grid[r - 7][c] = rand() % 5 + 1;
                  }
                  if (grid[r - 8][c] != i) {
                    grid[r - 8][c] = rand() % 5 + 1;
                  }
                  if (grid[r - 9][c] != i) {
                    grid[r - 9][c] = rand() % 5 + 1;
                  }
                }

                grid[r - 1][c] = grid[r - 4][c];
                grid[r - 2][c] = grid[r - 5][c]; // upper shapes in lower grid
                grid[r - 3][c] = grid[r - 6][c];
                grid[r - 4][c] = grid[r - 7][c];
                grid[r - 5][c] = grid[r - 8][c];
                grid[r - 6][c] = grid[r - 9][c];
                //	==========================

              }
              //===================================

              else if (grid[r - 1][c] == grid[r - 1][c + 1] &&
                       grid[r - 1][c] ==
                           grid[r - 1][c + 2]) // checks swap with up right
              {

                for (int i = 1; i <= 6; i++) {
                  if (grid[r - i][c] != i) {
                    grid[r - i][c] = rand() % 5 + 1;
                  }

                  if (grid[r - i][c + 1] != i) {
                    grid[r - i][c + 1] = rand() % 5 + 1;
                  }
                  if (grid[r - i][c + 2] != i) {
                    grid[r - i][c + 2] = rand() % 5 + 1;
                  }
                }

                grid[r - 1][c] = grid[r - 2][c];
                grid[r - 2][c + 1] = grid[r - 2][c + 1];
                grid[r - 2][c + 2] = grid[r - 2][c + 2];
                grid[r - 2][c] = grid[r - 3][c];
                grid[r - 2][c + 1] = grid[r - 3][c + 1]; // update upper grids
                grid[r - 2][c + 2] = grid[r - 3][c + 2];

                grid[r - 3][c] = grid[r - 4][c];
                grid[r - 3][c + 1] = grid[r - 4][c + 1];
                grid[r - 3][c + 2] = grid[r - 4][c + 2]; // update upper grids

                grid[r - 4][c] = grid[r - 5][c];
                grid[r - 4][c + 1] = grid[r - 5][c + 1]; // update upper grids
                grid[r - 4][c + 2] = grid[r - 5][c + 2];

                grid[r - 5][c] = grid[r - 6][c];
                grid[r - 5][c + 1] = grid[r - 6][c + 1]; // update upper grids
                grid[r - 5][c + 2] = grid[r - 6][c + 2];

              } //======================================
              else if (grid[r - 1][c] == grid[r - 1][c - 1] &&
                       grid[r - 1][c] ==
                           grid[r - 1][c - 2]) // checks swap with up left
              {
                for (int i = 1; i <= 5; i++) {
                  if (grid[r - i][c] != i) {
                    grid[r - i][c] = rand() % 5 + 1;
                  }
                  if (grid[r - i][c - 1] != i) {
                    grid[r - i][c - 1] = rand() % 5 + 1;
                  }
                  if (grid[r - i][c - 2] != i) {
                    grid[r - i][c - 2] = rand() % 5 + 1;
                  }
                }

                grid[r - 1][c] = grid[r - 2][c];
                grid[r - 1][c - 1] = grid[r - 2][c - 1]; // updating grid
                grid[r - 1][c - 2] = grid[r - 2][c - 2];

                grid[r - 2][c] = grid[r - 3][c];
                grid[r - 2][c - 1] = grid[r - 3][c - 1]; // updating grid
                grid[r - 2][c - 2] = grid[r - 3][c - 2];

                grid[r - 3][c] = grid[r - 4][c];
                grid[r - 3][c - 1] = grid[r - 4][c - 1]; // updating grid
                grid[r - 3][c - 2] = grid[r - 4][c - 2];

                grid[r - 4][c] = grid[r - 5][c];
                grid[r - 4][c - 1] = grid[r - 5][c - 1]; // updating grid
                grid[r - 4][c - 2] = grid[r - 5][c - 2];

                grid[r - 5][c] = grid[r - 6][c];
                grid[r - 5][c - 1] = grid[r - 6][c - 1]; // updating grid
                grid[r - 5][c - 2] = grid[r - 6][c - 2];

                //===============================================
              } else if (grid[r - 1][c] ==
                             grid[r - 1][c - 1] // check swap for up middle
                         && grid[r - 1][c] == grid[r - 1][c + 1]) {
                for (int i = 1; i <= 5; i++) {
                  if (grid[r - i][c] != i) {
                    grid[r - i][c] = rand() % 5 + 1;
                  }
                  if (grid[r - i][c - 1] != i) {
                    grid[r - i][c - 1] = rand() % 5 + 1;
                  }
                  if (grid[r - i][c + 1] != i) {
                    grid[r - i][c + 1] = rand() % 5 + 1;
                  }
                }

                grid[r + 1][c] = grid[r][c];
                grid[r + 1][c - 1] = grid[r][c - 1];
                grid[r + 1][c + 1] = grid[r][c + 1];

                grid[r - 1][c] = grid[r - 2][c];
                grid[r - 2][c + 1] = grid[r - 2][c + 1];
                grid[r - 2][c - 1] = grid[r - 2][c - 1];
                grid[r - 2][c] = grid[r - 3][c];
                grid[r - 2][c + 1] = grid[r - 3][c + 1]; // update upper grids
                grid[r - 2][c - 1] = grid[r - 3][c - 1];

                grid[r - 3][c] = grid[r - 4][c];
                grid[r - 3][c + 1] = grid[r - 4][c + 1];
                grid[r - 3][c - 1] = grid[r - 4][c - 1]; // update upper grids

                grid[r - 4][c] = grid[r - 5][c];
                grid[r - 4][c + 1] = grid[r - 5][c + 1]; // update upper grids
                grid[r - 4][c - 1] = grid[r - 5][c - 1];

                grid[r - 5][c] = grid[r - 6][c];
                grid[r - 5][c + 1] = grid[r - 6][c + 1]; // update upper grids
                grid[r - 5][c - 1] = grid[r - 6][c - 1];

              }

              else {
                cout << "Sorry no swap";
                Sleep(100);
                swap(grid[r - 1][c], grid[r][c]);
                system("cls");
                box();
              }

              system("cls");
              box();
              break;
            }
            if (key == 3) // right VK_RIGHT
            {
              swap(grid[r][c], grid[r][c + 1]);

              if (grid[r][c + 1] == grid[r][c + 2] &&
                  grid[r][c + 1] == grid[r][c + 3]) {
                for (int i = 1, k = 1; i <= 5, k <= 3; i++, k++) {
                  if (grid[r - i][c + k] != i) {
                    grid[r - i][c + k] = rand() % 5 + 1;
                  }
                }

                grid[r][c + 1] = grid[r - 1][c + 1];
                grid[r][c + 2] = grid[r - 1][c + 2];
                grid[r][c + 3] = grid[r - 1][c + 3];
                ////////////////////////////////////////
                grid[r - 1][c + 1] = grid[r - 2][c + 1];
                grid[r - 1][c + 2] = grid[r - 2][c + 2];
                grid[r - 1][c + 3] = grid[r - 2][c + 3];
                ///////////////////////////////////////
                grid[r - 2][c + 1] = grid[r - 3][c + 1];
                grid[r - 2][c + 2] = grid[r - 3][c + 2];
                grid[r - 2][c + 3] = grid[r - 3][c + 3];
                ///////////////////////////////////////
                grid[r - 3][c + 1] = grid[r - 4][c + 1];
                grid[r - 3][c + 2] = grid[r - 4][c + 2];
                grid[r - 3][c + 3] = grid[r - 4][c + 3];
                ///////////////////////////////////////
                grid[r - 4][c + 1] = grid[r - 5][c + 1];
                grid[r - 4][c + 2] = grid[r - 5][c + 2];
                grid[r - 4][c + 3] = grid[r - 5][c + 3];
                ///////////////////////////////////////////
                grid[r - 5][c + 1] = grid[r - 6][c + 1];
                grid[r - 5][c + 2] = grid[r - 6][c + 2];
                grid[r - 5][c + 3] = grid[r - 6][c + 3];
                /////////////////////////////////////

              }

              else if (grid[r][c + 1] == grid[r + 1][c + 1] // checks swap with
                                                            // up right vertical
                       && grid[r][c + 1] == grid[r + 2][c + 1]) {

                for (int i = 1; i <= 5; i++) {
                  if (grid[r - i][c + 1] != i) {
                    grid[r - i][c + 1] = rand() % 5 + 1;
                  }
                }
                grid[r][c + 1] = grid[r - 3][c + 1];
                grid[r + 1][c + 1] =
                    grid[r - 2][c + 1]; // bring upper shapes down
                grid[r + 2][c + 1] = grid[r - 1][c + 1];

              } else if (grid[r][c + 1] == grid[r - 1][c + 1] &&
                         grid[r][c + 1] == grid[r - 2][c + 1]) {
                for (int i = 3, k = 1; i <= 5, k <= 5; i++, k++)
                  if (grid[r - i][c + 1] != k) {
                    grid[r - i][c + 1] = rand() % 5 + 1;
                  }

                grid[r][c + 1] = grid[r - 3][c + 1];
                grid[r - 1][c + 1] = grid[r - 1][c + 1];
                grid[r - 2][c + 1] = grid[r - 5][c + 1];
              } //==================================================
              else if (grid[r][c + 1] ==
                           grid[r - 1][c + 1] // checks swap for right middle
                       && grid[r][c + 1] == grid[r + 1][c + 1]) {
                for (int i = 1; i <= 5; i++) {
                  if (grid[r - i][c + 1] != i) {
                    grid[r - i][c + 1] = rand() % 5 + 1;
                  }
                }
                for (int i = 1, k = 3; i <= 5, k <= 7; i++, k++) {
                  if (grid[r - k][c + 1] != i) {
                    grid[r - k][c + 1] = rand() % 5 + 1;
                  }
                }

                grid[r + 1][c + 1] = grid[r - 2][c + 1];
                grid[r][c + 1] = grid[r - 3][c + 1];
                grid[r - 1][c + 1] =
                    grid[r - 4][c + 1]; // updating the upper grids
                grid[r - 2][c + 1] = grid[r - 5][c + 1];
                grid[r - 3][c + 1] = grid[r - 6][c + 1];

              }
              //==============================================================================
              else {
                cout << "Sorry no swap";
                Sleep(100);
                swap(grid[r][c + 1], grid[r][c]);
                system("cls");
                box();
              }

              system("cls");
              box();
              break;
            }
            if (key == 4) // down
            {
              swap(grid[r][c], grid[r + 1][c]);
              if (grid[r + 1][c] == grid[r + 2][c] &&
                  grid[r + 1][c] == grid[r + 3][c]) // check swap
              {
                for (int i = 1; i <= 5; i++)

                {

                  if (grid[r - i][c] != i) {
                    grid[r - i][c] = rand() % 5 + 1;
                  }
                }
                grid[r + 3][c] = grid[r][c];
                grid[r + 2][c] = grid[r - 1][c]; // brings upper shapes down
                grid[r + 1][c] = grid[r - 2][c];
                grid[r][c] = grid[r - 3][c];

                //=============================
              } else if (grid[r + 1][c] == grid[r + 1][c - 1] &&
                         grid[r + 1][c] ==
                             grid[r + 1][c + 1]) // down swap middle
              {
                for (int i = 1; i <= 5;
                     i++) // for removal of garbage value from the virtual grid
                {
                  if (grid[r - i][c] != i) {
                    grid[r - i][c] = rand() % 5 + 1;
                  }
                  if (grid[r - i][c - 1] != i) {
                    grid[r - i][c - 1] = rand() % 5 + 1;
                  }
                  if (grid[r - i][c + 1] != i) {
                    grid[r - i][c + 1] = rand() % 5 + 1;
                  }
                  if (grid[r - 6][c] != i) {
                    grid[r - 6][c] = rand() % 5 + 1;
                  }
                  if (grid[r - 6][c + 1] != i) {
                    grid[r - 6][c + 1] = rand() % 5 + 1;
                  }
                  if (grid[r - 6][c - 1] != i) {
                    grid[r - 6][c - 1] = rand() % 5 + 1;
                  }
                }
                //	================================
                // swapping//
                grid[r][c] = grid[r - 1][c];
                grid[r][c + 1] = grid[r - 1][c + 1];
                grid[r][c - 1] = grid[r - 1][c - 1];

                grid[r + 1][c] = grid[r][c];
                grid[r + 1][c - 1] = grid[r][c - 1];
                grid[r + 1][c + 1] = grid[r][c + 1];

                grid[r - 1][c] = grid[r - 2][c];
                grid[r - 1][c + 1] = grid[r - 2][c + 1];
                grid[r - 1][c - 1] = grid[r - 2][c - 1];

                grid[r - 2][c] = grid[r - 3][c];
                grid[r - 2][c + 1] = grid[r - 3][c + 1];
                grid[r - 2][c - 1] = grid[r - 3][c - 1];

                grid[r - 3][c] = grid[r - 4][c];
                grid[r - 3][c + 1] = grid[r - 4][c + 1];
                grid[r - 3][c - 1] = grid[r - 4][c - 1];

                grid[r - 4][c] = grid[r - 5][c];
                grid[r - 4][c + 1] = grid[r - 5][c + 1];
                grid[r - 4][c - 1] = grid[r - 5][c - 1];

                grid[r - 5][c] = grid[r - 6][c];
                grid[r - 5][c + 1] = grid[r - 6][c + 1];
                grid[r - 5][c - 1] = grid[r - 6][c - 1];

              }

              else if (grid[r + 1][c] ==
                           grid[r + 1][c + 1] // check swap with down left
                       && grid[r + 1][c] == grid[r + 1][c + 2])

              {

                for (int i = 1; i <= 5; i++) {
                  if (grid[r - i][c] != i) {
                    grid[r - i][c] = rand() % 5 + 1;
                  }
                  if (grid[r - i][c + 1] != i) {
                    grid[r - i][c + 1] = rand() % 5 + 1;
                  }
                  if (grid[r - i][c + 2] != i) {
                    grid[r - i][c + 2] = rand() % 5 + 1;
                  }
                }

                grid[r + 1][c] = grid[r][c];
                grid[r][c] = grid[r - 1][c];
                grid[r - 1][c] = grid[r - 2][c];
                grid[r - 2][c] = grid[r - 3][c]; // first col updated
                grid[r - 3][c] = grid[r - 4][c];
                grid[r - 4][c] = grid[r - 5][c];
                grid[r - 5][c] = grid[r - 6][c];

                //=====================================

                grid[r + 1][c + 1] = grid[r][c + 1];
                grid[r][c + 1] = grid[r - 1][c + 1];
                grid[r - 1][c + 1] = grid[r - 2][c + 1];
                grid[r - 2][c + 1] = grid[r - 3][c + 1]; // second col updated
                grid[r - 3][c + 1] = grid[r - 4][c + 1];
                grid[r - 4][c + 1] = grid[r - 5][c + 1];
                grid[r - 5][c + 1] = grid[r - 6][c + 1];

                //==================================================

                grid[r + 1][c + 2] = grid[r][c + 2];
                grid[r][c + 2] = grid[r - 1][c + 2];
                grid[r - 1][c + 2] = grid[r - 2][c + 2];
                grid[r - 2][c + 2] = grid[r - 3][c + 2]; // third col updated
                grid[r - 3][c + 2] = grid[r - 4][c + 2];
                grid[r - 4][c + 2] = grid[r - 5][c + 2];
                grid[r - 5][c + 2] = grid[r - 6][c + 2];

              }

              //=========================================================
              else if (grid[r + 1][c] ==
                           grid[r + 1][c - 1] // check swap with down Right
                       && grid[r + 1][c] == grid[r + 1][c - 2]) {

                for (int i = 1; i <= 5; i++) {
                  if (grid[r - i][c] != i) {
                    grid[r - i][c] = rand() % 5 + 1;
                  }
                  if (grid[r - i][c - 1] != i) {
                    grid[r - i][c - 1] = rand() % 5 + 1;
                  }
                  if (grid[r - i][c - 2] != i) {
                    grid[r - i][c - 2] = rand() % 5 + 1;
                  }
                }

                grid[r + 1][c] = grid[r][c];
                grid[r][c] = grid[r - 1][c];
                grid[r - 5][c] = grid[r - 6][c];

                //=====================================================
                for (int i = 1; i <= 5; i++) {
                  grid[r - i][c] = grid[r - i - 1][c];

                  grid[r - i][c - 1] = grid[r - i - 1][c - 1];
                  grid[r - i][c - 2] = grid[r - i - 1][c - 2];
                }

                grid[r][c - 1] = grid[r - 1][c - 1];
                grid[r + 1][c - 2] = grid[r][c - 2];
                grid[r][c] = grid[r - 1][c];
                grid[r - 1][c] = grid[r - 2][c];
                grid[r][c - 2] = grid[r - 1][c - 2];
                grid[r + 1][c - 1] = grid[r][c - 1];

              } else {
                cout << "no match";
                swap(grid[r + 1][c], grid[r][c]);
                system("cls");
                box();
              }

              Sleep(200);
              system("cls");
              box();
              break;
            }
          }
        }
        shapes();
      }
      myLinec(x, y, x + 83, y, 121, 249, 94, 121, 249, 94);
      myLinec(x + 83, y, x + 83, y + 83, 121, 249, 94, 121, 249, 94);
      myLinec(x, y + 83, x + 83, y + 83, 121, 249, 94, 121, 249,
              94); // displays the cursor in the new position
      myLinec(x, y, x, y + 83, 121, 249, 94, 121, 249, 94);
    }
  }
}
int main() {

  elements(grid); // calling the random number into the grid

  while (1) {

    box(); // displaying the board/grid

    shapes();    // displaying the shapes accrding to the random values
    cursorout(); // display the cursor

    system("cls");

    shapes(); // display the shapes again
  }

  getchar();
  return 0;
}
void shapes() // assign shapes to values
{

  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      if (grid[i][j] == 1) {
        rhombus(i, j);
      }
      if (grid[i][j] == 2) {
        cir(i, j);
      }
      if (grid[i][j] == 3) {
        rect(i, j);
      }
      if (grid[i][j] == 4) {
        para(i, j);
      }
      if (grid[i][j] == 5) {
        sq(i, j);
      }
      if (grid[i][j] == 6) {
        scir(i, j);
      }
    }
  }
}
void box() {
  // creates a grid box for the game
  myRectgrid(0, 0, 662, 662, 255, 220, 241, 255, 220, 241);
  line(0, 1, 662, 1, 128, 128, 128, 128, 128, 128);
  line(0, 77, 662, 77, 128, 128, 128, 128, 128, 128);
  line(0, 158, 662, 158, 128, 128, 128, 128, 128, 128);
  line(0, 242, 662, 242, 128, 128, 128, 128, 128, 128);
  line(0, 326, 662, 326, 128, 128, 128, 128, 128, 128);
  line(0, 410, 662, 410, 128, 128, 128, 128, 128, 128); // Horizontal lines
  line(0, 493, 662, 493, 128, 128, 128, 128, 128, 128);
  line(0, 578, 662, 578, 128, 128, 128, 128, 128, 128);
  line(0, 662, 662, 662, 128, 128, 128, 128, 128, 128);

  //	=================================================
  line(77, 0, 77, 662, 128, 128, 128, 128, 128, 128);
  line(154, 0, 154, 662, 128, 128, 128, 128, 128, 128);
  line(235, 0, 235, 662, 128, 128, 128, 128, 128, 128);
  line(320, 0, 320, 662, 128, 128, 128, 128, 128, 128);
  line(405, 0, 405, 662, 128, 128, 128, 128, 128, 128);
  line(487, 0, 487, 662, 128, 128, 128, 128, 128, 128);
  line(570, 0, 570, 662, 128, 128, 128, 128, 128, 128);
  line(655, 0, 655, 662, 128, 128, 128, 128, 128, 128); // vertical li
}

void updategridsimpleleft() // updating the grid
{

  grid[r][c - 1] = grid[r - 1][c - 1];

  grid[r][c - 2] = grid[r - 1][c - 2];

  grid[r][c - 3] = grid[r - 1][c - 3];

  grid[r - 1][c - 1] = grid[r - 2][c - 1];

  grid[r - 1][c - 2] = grid[r - 2][c - 2];

  grid[r - 1][c - 3] = grid[r - 2][c - 3];

  grid[r - 2][c - 1] = grid[r - 3][c - 1];

  grid[r - 2][c - 2] = grid[r - 3][c - 2];

  grid[r - 2][c - 3] = grid[r - 3][c - 3];

  grid[r - 3][c - 1] = grid[r - 4][c - 1];

  grid[r - 3][c - 2] = grid[r - 4][c - 2];

  grid[r - 3][c - 3] = grid[r - 4][c - 3];

  grid[r - 4][c - 2] = grid[r - 5][c - 2];

  grid[r - 4][c - 3] = grid[r - 5][c - 3];

  grid[r - 5][c - 1] = grid[r - 6][c - 1];

  grid[r - 5][c - 2] = grid[r - 6][c - 2];

  grid[r - 5][c - 3] = grid[r - 6][c - 3];

  grid[r - 6][c - 1] = grid[r - 7][c - 1];

  grid[r - 6][c - 2] = grid[r - 7][c - 2];

  grid[r - 6][c - 3] = grid[r - 7][c - 3];
}

void updategridmatch4left() // removal of garbage vakue
{
  for (int i = 1; i <= 5; i++) {
    for (int j = 1; j <= 4; j++) {
      if (grid[r - i][c - j] != i) {
        grid[r - i][c - j] = rand() % +1;
      }
    }
  }
  grid[r][c - 1] = grid[r - 1][c - 1];
  grid[r][c - 2] = grid[r - 1][c - 2]; // bring upper shapes down
  grid[r][c - 3] = grid[r - 1][c - 3];
  grid[r][c - 4] = grid[r - 1][c - 4];
  grid[r - 1][c - 1] = grid[r - 2][c - 1];
  grid[r - 1][c - 2] = grid[r - 2][c - 2];
  grid[r - 1][c - 3] = grid[r - 2][c - 3];
  grid[r - 1][c - 4] = grid[r - 2][c - 4]; // bring upper shapes down
  grid[r - 2][c - 1] = grid[r - 3][c - 1];
  grid[r - 2][c - 2] = grid[r - 3][c - 2];
  grid[r - 2][c - 3] = grid[r - 3][c - 3];
  grid[r - 2][c - 4] = grid[r - 3][c - 4];
  grid[r - 3][c - 1] = grid[r - 4][c - 1];
  grid[r - 3][c - 2] = grid[r - 4][c - 2]; // bring upper shapes down
  grid[r - 3][c - 3] = grid[r - 4][c - 3];
  grid[r - 3][c - 4] = grid[r - 4][c - 4];
  grid[r - 4][c - 1] = grid[r - 5][c - 1];
  grid[r - 4][c - 2] = grid[r - 5][c - 2];
  grid[r - 4][c - 3] = grid[r - 5][c - 3];
  grid[r - 4][c - 4] = grid[r - 5][c - 4];
  grid[r - 5][c - 1] = grid[r - 6][c - 1]; // bring upper shapes down
  grid[r - 5][c - 2] = grid[r - 6][c - 2];
  grid[r - 5][c - 3] = grid[r - 6][c - 3];
  grid[r - 5][c - 4] = grid[r - 6][c - 4];
  grid[r - 6][c - 1] = grid[r - 7][c - 1];
  grid[r - 6][c - 2] = grid[r - 7][c - 2]; // bring upper shapes down
  grid[r - 6][c - 3] = grid[r - 7][c - 3];
  grid[r - 6][c - 4] = grid[r - 7][c - 4];
}
void clsrandsimpleleft() // removal of garbage value
{
  for (int i = 1; i <= 5; i++) {
    if (grid[r - i][c - 1] != i) {
      grid[r - i][c - 1] = rand() % 5 + 1;
    }

    if (grid[r - i][c - 2] != i) {
      grid[r - i][c - 2] = rand() % 5 + 1;
    }

    if (grid[r - i][c - 3] != i) {
      grid[r - i][c - 3] = rand() % 5 + 1;
    }
  }
}
void clsrandmatch4left() // removal of garbage value
{
  for (int i = 1; i <= 5; i++) {
    if (grid[r - i][c - 1] != i) {
      grid[r - i][c - 1] = rand() % 5 + 1;
    }

    if (grid[r - i][c - 2] != i) {
      grid[r - i][c - 2] = rand() % 5 + 1;
    }

    if (grid[r - i][c - 3] != i) {
      grid[r - i][c - 3] = rand() % 5 + 1;
    }

    if (grid[r - i][c - 4] != i) {
      grid[r - i][c - 4] = rand() % 5 + 1;
    }
  }
}
void updategridmatch4leftcir() // updating the grid
{
  grid[r][c - 1] == 6;
  grid[r][c - 2] = grid[r - 1][c - 2]; // bring upper shapes down
  grid[r][c - 3] = grid[r - 1][c - 3];
  grid[r][c - 4] = grid[r - 1][c - 4];
  grid[r - 1][c - 1] = grid[r - 2][c - 1];
  grid[r - 1][c - 2] = grid[r - 2][c - 2];
  grid[r - 1][c - 3] = grid[r - 2][c - 3];
  grid[r - 1][c - 4] = grid[r - 2][c - 4]; // bring upper shapes down
  grid[r - 2][c - 1] = grid[r - 3][c - 1];
  grid[r - 2][c - 2] = grid[r - 3][c - 2];
  grid[r - 2][c - 3] = grid[r - 3][c - 3];
  grid[r - 2][c - 4] = grid[r - 3][c - 4];
  grid[r - 3][c - 1] = grid[r - 4][c - 1];
  grid[r - 3][c - 2] = grid[r - 4][c - 2]; // bring upper shapes down
  grid[r - 3][c - 3] = grid[r - 4][c - 3];
  grid[r - 3][c - 4] = grid[r - 4][c - 4];
  grid[r - 4][c - 1] = grid[r - 5][c - 1];
  grid[r - 4][c - 2] = grid[r - 5][c - 2];
  grid[r - 4][c - 3] = grid[r - 5][c - 3];
  grid[r - 4][c - 4] = grid[r - 5][c - 4];
  grid[r - 5][c - 1] = grid[r - 6][c - 1]; // bring upper shapes down
  grid[r - 5][c - 2] = grid[r - 6][c - 2];
  grid[r - 5][c - 3] = grid[r - 6][c - 3];
  grid[r - 5][c - 4] = grid[r - 6][c - 4];
  grid[r - 6][c - 1] = grid[r - 7][c - 1];
  grid[r - 6][c - 2] = grid[r - 7][c - 2]; // bring upper shapes down
  grid[r - 6][c - 3] = grid[r - 7][c - 3];
  grid[r - 6][c - 4] = grid[r - 7][c - 4];
}

void updategridmatch4right() // updating the grid
{
  grid[r][c + 1] = grid[r - 1][c + 1];
  grid[r][c + 2] = grid[r - 1][c + 2]; // after swap
  grid[r][c + 3] = grid[r - 1][c + 3];

  grid[r - 2][c + 1] = grid[r - 3][c + 1];
  grid[r - 2][c + 2] = grid[r - 3][c + 2];
  grid[r - 2][c + 3] = grid[r - 3][c + 3];
  grid[r - 3][c + 1] = grid[r - 4][c + 1];
  grid[r - 3][c + 2] = grid[r - 4][c + 2];
  grid[r - 3][c + 3] = grid[r - 4][c + 3];
  grid[r - 4][c + 1] = grid[r - 5][c + 1];
  grid[r - 4][c + 2] = grid[r - 5][c + 2];
  grid[r - 4][c + 3] = grid[r - 5][c + 3];
  grid[r - 5][c + 1] = grid[r - 6][c + 1];
  grid[r - 5][c + 2] = grid[r - 6][c + 2];
  grid[r - 5][c + 3] = grid[r - 6][c + 3]; // bring down upper shapes
}
void clsrandupdategridright() // remove garbage value
{

  for (int i = 1; i <= 5; i++) {
    if (grid[r][c + 1] != i) {
      grid[r][c + 1] = rand() % 5 + 1;
    }
    if (grid[r - i][c + 1] != i) {
      grid[r - i][c + 1] = rand() % 5 + 1;
    }
    if (grid[r - i][c + 2] != i) {
      grid[r - i][c + 2] = rand() % 5 + 1;
    }

    if (grid[r - i][c + 3] != i) {
      grid[r - i][c + 3] = rand() % 5 + 1;
    }
  }
}

void updategridmatch4rightcir() // update grid for cir macthing of 4 blocks //
                                // not used in program
{
  grid[r][c + 1] = 6;
  grid[r][c + 2] = grid[r - 1][c + 2]; // after swap
  grid[r][c + 3] = grid[r - 1][c + 3];
  grid[r][c + 4] = grid[r - 1][c + 4];
  grid[r - 2][c + 1] = grid[r - 3][c + 1];
  grid[r - 2][c + 2] = grid[r - 3][c + 2];
  grid[r - 2][c + 3] = grid[r - 3][c + 3];
  grid[r - 2][c + 4] = grid[r - 3][c + 4];
  grid[r - 3][c + 1] = grid[r - 4][c + 1];
  grid[r - 3][c + 2] = grid[r - 4][c + 2];
  grid[r - 3][c + 3] = grid[r - 4][c + 3];
  grid[r - 3][c + 4] = grid[r - 4][c + 4];
  grid[r - 4][c + 1] = grid[r - 5][c + 1];
  grid[r - 4][c + 2] = grid[r - 5][c + 2];
  grid[r - 4][c + 3] = grid[r - 5][c + 3];
  grid[r - 4][c + 4] = grid[r - 5][c + 4];
  grid[r - 5][c + 1] = grid[r - 6][c + 1];
  grid[r - 5][c + 2] = grid[r - 6][c + 2];
  grid[r - 5][c + 3] = grid[r - 6][c + 3];
  grid[r - 5][c + 4] = grid[r - 6][c + 4]; // bring down upper shapes
}