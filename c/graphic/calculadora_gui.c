#include <windows.h>
#include <stdio.h>
#include <stdlib.h>

#define ID_NUM1 101
#define ID_NUM2 102
#define ID_BTN_MAIS 201
#define ID_BTN_MENOS 202
#define ID_BTN_VEZES 203
#define ID_BTN_DIVIDIR 204
#define ID_RESULTADO 301

HWND hNum1, hNum2, hResultado;

LRESULT CALLBACK WindowProcedure(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp) {
    switch (msg) {
        case WM_CREATE:
            CreateWindow("Static", "Número 1:", WS_VISIBLE | WS_CHILD, 20, 20, 80, 20, hWnd, NULL, NULL, NULL);
            hNum1 = CreateWindow("Edit", "", WS_VISIBLE | WS_CHILD | WS_BORDER, 110, 20, 150, 20, hWnd, (HMENU)ID_NUM1, NULL, NULL);

            CreateWindow("Static", "Número 2:", WS_VISIBLE | WS_CHILD, 20, 50, 80, 20, hWnd, NULL, NULL, NULL);
            hNum2 = CreateWindow("Edit", "", WS_VISIBLE | WS_CHILD | WS_BORDER, 110, 50, 150, 20, hWnd, (HMENU)ID_NUM2, NULL, NULL);

            CreateWindow("Button", "+", WS_VISIBLE | WS_CHILD, 20, 90, 50, 30, hWnd, (HMENU)ID_BTN_MAIS, NULL, NULL);
            CreateWindow("Button", "-", WS_VISIBLE | WS_CHILD, 80, 90, 50, 30, hWnd, (HMENU)ID_BTN_MENOS, NULL, NULL);
            CreateWindow("Button", "*", WS_VISIBLE | WS_CHILD, 140, 90, 50, 30, hWnd, (HMENU)ID_BTN_VEZES, NULL, NULL);
            CreateWindow("Button", "/", WS_VISIBLE | WS_CHILD, 200, 90, 50, 30, hWnd, (HMENU)ID_BTN_DIVIDIR, NULL, NULL);

            hResultado = CreateWindow("Static", "Resultado: ", WS_VISIBLE | WS_CHILD, 20, 140, 240, 40, hWnd, (HMENU)ID_RESULTADO, NULL, NULL);
            break;

        case WM_COMMAND:
            if (wp >= ID_BTN_MAIS && wp <= ID_BTN_DIVIDIR) {
                char txt1[20], txt2[20], buffer[100];
                GetWindowText(hNum1, txt1, 20);
                GetWindowText(hNum2, txt2, 20);

                double n1 = atof(txt1);
                double n2 = atof(txt2);
                double res = 0;

                if (wp == ID_BTN_MAIS) {
                    res = n1 + n2;
                    sprintf(buffer, "Resultado: %.2f", res);
                } else if (wp == ID_BTN_MENOS) {
                    res = n1 - n2;
                    sprintf(buffer, "Resultado: %.2f", res);
                } else if (wp == ID_BTN_VEZES) {
                    res = n1 * n2;
                    sprintf(buffer, "Resultado: %.2f", res);
                } else if (wp == ID_BTN_DIVIDIR) {
                    if (n2 == 0) {
                        sprintf(buffer, "Erro: Divisão por zero!");
                    } else {
                        res = n1 / n2;
                        sprintf(buffer, "Resultado: %.2f", res);
                    }
                }
                SetWindowText(hResultado, buffer);
            }
            break;

        case WM_DESTROY:
            PostQuitMessage(0);
            break;

        default:
            return DefWindowProc(hWnd, msg, wp, lp);
    }
    return 0;
}

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR args, int ncmdshow) {
    WNDCLASS wc = {0};
    wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hInstance = hInst;
    wc.lpszClassName = "CalculadoraC";
    wc.lpfnWndProc = WindowProcedure;

    if (!RegisterClass(&wc)) return -1;

    CreateWindow("CalculadoraC", "Calculadora em C", WS_OVERLAPPEDWINDOW | WS_VISIBLE, 100, 100, 300, 230, NULL, NULL, NULL, NULL);

    MSG msg = {0};
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return 0;
}
