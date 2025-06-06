#include <windows.h>

void gotoxy(int x, int y) {
  COORD coord;
  coord.X = x;
  coord.Y = y;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void myLine(int x1, int y1, int x2, int y2, int R, int G, int B, int a, int b,
            int c) // use three 3 integers if you want colored lines.
{
  HWND console_handle = GetConsoleWindow();
  HDC device_context = GetDC(console_handle);

  // change the color by changing the values in RGB (from 0-255)
  HPEN pen = CreatePen(PS_SOLID, 10, RGB(R, G, B));
  SelectObject(device_context, pen);
  HBRUSH brush = ::CreateSolidBrush(
      RGB(a, b, c)); // Fill color is passed as parameter to the function!!!

  SelectObject(device_context, brush);
  MoveToEx(device_context, x1, y1, NULL);
  LineTo(device_context, x2, y2);
  ReleaseDC(console_handle, device_context);
  DeleteObject(pen);
}
void myLinec(int x1, int y1, int x2, int y2, int R, int G, int B, int a, int b,
             int c) // use three 3 integers if you want colored lines.
{
  HWND console_handle = GetConsoleWindow();
  HDC device_context = GetDC(console_handle);

  // change the color by changing the values in RGB (from 0-255)
  HPEN pen = CreatePen(PS_SOLID, 5, RGB(R, G, B));
  SelectObject(device_context, pen);
  HBRUSH brush = ::CreateSolidBrush(
      RGB(a, b, c)); // Fill color is passed as parameter to the function!!!

  SelectObject(device_context, brush);
  MoveToEx(device_context, x1, y1, NULL);
  LineTo(device_context, x2, y2);
  ReleaseDC(console_handle, device_context);
  DeleteObject(pen);
}
void myLinesp(int x1, int y1, int x2, int y2, int R, int G, int B, int a, int b,
              int c) // use three 3 integers if you want colored lines.
{
  HWND console_handle = GetConsoleWindow();
  HDC device_context = GetDC(console_handle);

  // change the color by changing the values in RGB (from 0-255)
  HPEN pen = CreatePen(PS_SOLID, 10, RGB(R, G, B));
  SelectObject(device_context, pen);
  HBRUSH brush = ::CreateSolidBrush(
      RGB(a, b, c)); // Fill color is passed as parameter to the function!!!

  SelectObject(device_context, brush);
  MoveToEx(device_context, x1, y1, NULL);
  LineTo(device_context, x2, y2);
  ReleaseDC(console_handle, device_context);
  DeleteObject(pen);
}

// This function checks if any of the 4 cursor keys are pressed.
// If any cursor key is pressed, then the function returns true, and whichKey
// identifies which of the 4 cursor keys is pressed. whichkey is assigned
// following values if any cursor key is pressed. 1 for left, 2 for up, 3 for
// right and 4 for left.
bool isCursorKeyPressed(int &whichKey) // whichKey passed as reference....
{
  char key;
  key = GetAsyncKeyState(37);
  if (key == 1) {
    whichKey = 1; // 1 if left key is pressed
    return true;
  }
  key = GetAsyncKeyState(38);
  if (key == 1) {

    whichKey = 2; // 2 if up key is pressed
    return true;
  }

  key = GetAsyncKeyState(39);
  if (key == 1) {

    whichKey = 3; // 3 if right key is pressed
    return true;
  }
  key = GetAsyncKeyState(40);
  if (key == 1) {

    whichKey = 4; // 4 if down key is pressed
    return true;
  }
  key = GetAsyncKeyState(VK_RETURN);
  if (key == 1) {
    whichKey = 5;
    return true;
  }
  return false;
}

void myRect(int x1, int y1, int x2, int y2, int R, int G, int B, int a, int b,
            int c) {
  HWND console_handle = GetConsoleWindow();
  HDC device_context = GetDC(console_handle);

  // change the color by changing the values in RGB (from 0-255)
  HPEN pen = CreatePen(PS_SOLID, 5, RGB(R, G, B));
  SelectObject(device_context, pen);
  HBRUSH brush = ::CreateSolidBrush(
      RGB(a, b, c)); // Fill color is passed as parameter to the function!!!

  SelectObject(device_context, brush);

  Rectangle(device_context, x1, y1, x2, y2);
  ReleaseDC(console_handle, device_context);
  DeleteObject(pen);
  DeleteObject(brush);
}
void myEllipse(int x1, int y1, int x2, int y2, int R, int G, int B, int a,
               int b, int c) {
  HWND console_handle = GetConsoleWindow();
  HDC device_context = GetDC(console_handle);
  // change the color by changing the values in RGB (from 0-255)
  HPEN pen = CreatePen(PS_SOLID, 6, RGB(R, G, B));
  SelectObject(device_context, pen);
  HBRUSH brush = ::CreateSolidBrush(RGB(a, b, c)); // Fill color is black
  SelectObject(device_context, brush);
  Ellipse(device_context, x1, y1, x2, y2);
  ReleaseDC(console_handle, device_context);
  DeleteObject(pen);
  DeleteObject(brush);
}

void myLine2(int x1, int y1, int x2, int y2, int R, int G,
             int B) // use three 3 integers if you want colored lines.
{
  HWND console_handle = GetConsoleWindow();
  HDC device_context = GetDC(console_handle);

  // change the color by changing the values in RGB (from 0-255)
  HPEN pen = CreatePen(PS_SOLID, 2, RGB(R, G, B));
  SelectObject(device_context, pen);
  HBRUSH brush = ::CreateSolidBrush(
      RGB(0, 0, 0)); // Fill color is passed as parameter to the function!!!

  SelectObject(device_context, brush);
  MoveToEx(device_context, x1, y1, NULL);
  LineTo(device_context, x2, y2);
  ReleaseDC(console_handle, device_context);
  DeleteObject(pen);
}

void myLinexs(int x1, int y1, int x2, int y2, int R, int G, int B, int a, int b,
              int c) // use three 3 integers if you want colored lines.
{
  HWND console_handle = GetConsoleWindow();
  HDC device_context = GetDC(console_handle);

  // change the color by changing the values in RGB (from 0-255)
  HPEN pen = CreatePen(PS_SOLID, 47, RGB(R, G, B));
  SelectObject(device_context, pen);
  HBRUSH brush = ::CreateSolidBrush(
      RGB(a, b, c)); // Fill color is passed as parameter to the function!!!

  SelectObject(device_context, brush);
  MoveToEx(device_context, x1, y1, NULL);
  LineTo(device_context, x2, y2);
  ReleaseDC(console_handle, device_context);
  DeleteObject(pen);
}
void myLinex(int x1, int y1, int x2, int y2, int R, int G, int B, int a, int b,
             int c) // use three 3 integers if you want colored lines.
{
  HWND console_handle = GetConsoleWindow();
  HDC device_context = GetDC(console_handle);

  // change the color by changing the values in RGB (from 0-255)
  HPEN pen = CreatePen(PS_SOLID, 47, RGB(R, G, B));
  SelectObject(device_context, pen);
  HBRUSH brush = ::CreateSolidBrush(
      RGB(a, b, c)); // Fill color is passed as parameter to the function!!!

  SelectObject(device_context, brush);
  MoveToEx(device_context, x1, y1, NULL);
  LineTo(device_context, x2, y2);
  ReleaseDC(console_handle, device_context);
  DeleteObject(pen);
}
void myEllipse1(int x1, int y1, int x2, int y2, int R, int G, int B, int a,
                int b, int c) {
  HWND console_handle = GetConsoleWindow();
  HDC device_context = GetDC(console_handle);
  // change the color by changing the values in RGB (from 0-255)
  HPEN pen = CreatePen(PS_SOLID, 2, RGB(R, G, B));
  SelectObject(device_context, pen);
  HBRUSH brush = ::CreateSolidBrush(RGB(a, b, c)); // Fill color is black
  SelectObject(device_context, brush);
  Ellipse(device_context, x1, y1, x2, y2);
  ReleaseDC(console_handle, device_context);
  DeleteObject(pen);
  DeleteObject(brush);
}

void myLinesp1(int x1, int y1, int x2, int y2, int R, int G, int B, int a,
               int b, int c) // use three 3 integers if you want colored lines.
{
  HWND console_handle = GetConsoleWindow();
  HDC device_context = GetDC(console_handle);

  // change the color by changing the values in RGB (from 0-255)
  HPEN pen = CreatePen(PS_SOLID, 10, RGB(R, G, B));
  SelectObject(device_context, pen);
  HBRUSH brush = ::CreateSolidBrush(
      RGB(a, b, c)); // Fill color is passed as parameter to the function!!!

  SelectObject(device_context, brush);
  MoveToEx(device_context, x1, y1, NULL);
  LineTo(device_context, x2, y2);
  ReleaseDC(console_handle, device_context);
  DeleteObject(pen);
}
void myLinesp11(int x1, int y1, int x2, int y2, int R, int G, int B, int a,
                int b, int c) // use three 3 integers if you want colored lines.
{
  HWND console_handle = GetConsoleWindow();
  HDC device_context = GetDC(console_handle);

  // change the color by changing the values in RGB (from 0-255)
  HPEN pen = CreatePen(PS_SOLID, 15, RGB(R, G, B));
  SelectObject(device_context, pen);
  HBRUSH brush = ::CreateSolidBrush(
      RGB(a, b, c)); // Fill color is passed as parameter to the function!!!

  SelectObject(device_context, brush);
  MoveToEx(device_context, x1, y1, NULL);
  LineTo(device_context, x2, y2);
  ReleaseDC(console_handle, device_context);
  DeleteObject(pen);
}

void line(int x1, int y1, int x2, int y2, int R, int G, int B, int a, int b,
          int c) // use three 3 integers if you want colored lines.
{
  HWND console_handle = GetConsoleWindow();
  HDC device_context = GetDC(console_handle);

  // change the color by changing the values in RGB (from 0-255)
  HPEN pen = CreatePen(PS_SOLID, 10, RGB(R, G, B));
  SelectObject(device_context, pen);
  HBRUSH brush = ::CreateSolidBrush(
      RGB(a, b, c)); // Fill color is passed as parameter to the function!!!

  SelectObject(device_context, brush);
  MoveToEx(device_context, x1, y1, NULL);
  LineTo(device_context, x2, y2);
  ReleaseDC(console_handle, device_context);
  DeleteObject(pen);
}
void cursorline(int x1, int y1, int x2, int y2, int R, int G, int B, int a,
                int b, int c) // use three 3 integers if you want colored lines.
{
  HWND console_handle = GetConsoleWindow();
  HDC device_context = GetDC(console_handle);

  // change the color by changing the values in RGB (from 0-255)
  HPEN pen = CreatePen(PS_SOLID, 4, RGB(R, G, B));
  SelectObject(device_context, pen);
  HBRUSH brush = ::CreateSolidBrush(
      RGB(a, b, c)); // Fill color is passed as parameter to the function!!!

  SelectObject(device_context, brush);
  MoveToEx(device_context, x1, y1, NULL);
  LineTo(device_context, x2, y2);
  ReleaseDC(console_handle, device_context);
  DeleteObject(pen);
}

void myRectgrid(int x1, int y1, int x2, int y2, int R, int G, int B, int a,
                int b, int c) {
  HWND console_handle = GetConsoleWindow();
  HDC device_context = GetDC(console_handle);

  // change the color by changing the values in RGB (from 0-255)
  HPEN pen = CreatePen(PS_SOLID, 16, RGB(R, G, B));
  SelectObject(device_context, pen);
  HBRUSH brush = ::CreateSolidBrush(
      RGB(a, b, c)); // Fill color is passed as parameter to the function!!!

  SelectObject(device_context, brush);

  Rectangle(device_context, x1, y1, x2, y2);
  ReleaseDC(console_handle, device_context);
  DeleteObject(pen);
  DeleteObject(brush);
}
