#include <cstdio>
#include <cmath>
#include <windows.h>

int main(void)
{
    const COLORREF yellow = RGB(255, 255, 0);
    const COLORREF lightblue = RGB(173, 216, 230);

    const HWND hWnd = GetConsoleWindow();
    const HDC hDC = GetDC(hWnd);

    const int width(700);
    const int height(400);
    const double scale(50);

    for (int x = 0; x < width; x++) {
        SetPixel(hDC, x, height / 2, lightblue);
    }

    for (int y = 0; y < height; y++) {
        SetPixel(hDC, width / 2, y, lightblue);
    }

    for (int x = 0; x < width / 2; x++) {
        int y = (int)(tan(x / scale) * scale);
        SetPixel(hDC, width / 2 - x, y + height / 2, yellow);
        y = (int)(tan(-x / scale) * scale);
        SetPixel(hDC, width / 2 + x, y + height / 2, yellow);
    }

    ReleaseDC(hWnd, hDC);
    DeleteDC(hDC);

    getchar();
    return 0;
}