// TuningDrone.cpp : Defines the entry point for the application.
//

using namespace std;
#include "framework.h"
#include "TuningDrone.h"

#define MAX_LOADSTRING 100

// Global Variables:
HINSTANCE hInst;                                // current instance
WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name

// Forward declarations of functions included in this code module:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // Initialize global strings
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_TUNINGDRONE, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Perform application initialization:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_TUNINGDRONE));

    MSG msg;

    // Main message loop:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int) msg.wParam;
}



//
//  FUNCTION: MyRegisterClass()
//
//  PURPOSE: Registers the window class.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_TUNINGDRONE));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = CreateSolidBrush(RGB(0, 204, 204));//CreatePatternBrush(LoadBitmap(hInstance, MAKEINTRESOURCEW(L"Image.bmp")));
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_TUNINGDRONE);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   FUNCTION: InitInstance(HINSTANCE, int)
//
//   PURPOSE: Saves instance handle and creates main window
//
//   COMMENTS:
//
//        In this function, we save the instance handle in a global variable and
//        create and display the main program window.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // Store instance handle in our global variable

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PURPOSE: Processes messages for the main window.
//
//  WM_COMMAND  - process the application menu
//  WM_PAINT    - Paint the main window
//  WM_DESTROY  - post a quit message and return
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_COMMAND:
        {
            switch (LOWORD(wParam)) 
            {
            case 1:
                PlaySound(TEXT("C:\\Users\\realt\\Drones\\FDrone.wav"), NULL, SND_FILENAME | SND_ASYNC);
                break;
            case 2:
                PlaySound(TEXT("C:\\Users\\realt\\Drones\\BbDrone.wav"), NULL, SND_FILENAME | SND_ASYNC);
                break;
            case 3:
                PlaySound(NULL, NULL, SND_FILENAME | SND_ASYNC);
                break;
            case 4:
                exit(1);
                break;
            case 5:
                PlaySound(TEXT("C:\\Users\\realt\\Drones\\ADrone.wav"), NULL, SND_FILENAME | SND_ASYNC);
                break;
            }
            int wmId = LOWORD(wParam);
            // Parse the menu selections:
            switch (wmId)
            {
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HFONT hFont = CreateFont(36, 0, 0, 0, 1000, FALSE, TRUE, FALSE, DEFAULT_CHARSET, OUT_OUTLINE_PRECIS,
                CLIP_DEFAULT_PRECIS, CLEARTYPE_QUALITY, VARIABLE_PITCH, TEXT("Times New Roman"));
            HFONT hFont2 = CreateFont(24, 0, 0, 0, 1000, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_OUTLINE_PRECIS,
                CLIP_DEFAULT_PRECIS, CLEARTYPE_QUALITY, VARIABLE_PITCH, TEXT("Times New Roman"));
            HDC hdc = BeginPaint(hWnd, &ps);
            TCHAR greeting[] = _T("Trombone Drone");
            TCHAR copyright[] = _T("© Tommy Harris 2022");
            
            SelectObject(hdc, hFont);
            SetTextColor(hdc, RGB(0, 0, 128));
            SetBkMode(hdc, TRANSPARENT);
            TextOut(hdc,
                460, 150,
                greeting, _tcslen(greeting));
            SelectObject(hdc, hFont2);
            SetTextColor(hdc, RGB(0, 0, 0));
            TextOut(hdc,
                5, 5,
                copyright, _tcslen(copyright));

            HWND hwndButton = CreateWindow(
                L"BUTTON",  // Predefined class; Unicode assumed 
                L"F",      // Button text 
                WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,  // Styles 
                500,         // x position 
                200,         // y position 
                50,        // Button width
                50,        // Button height
                hWnd,     // Parent window
                (HMENU)1,       // Menu ID
                (HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE),
                NULL);      // Pointer not needed.

            HWND hwndButton2 = CreateWindow(
                L"BUTTON",  // Predefined class; Unicode assumed 
                L"Bb",      // Button text 
                WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,  // Styles 
                600,         // x position 
                200,         // y position 
                50,        // Button width
                50,        // Button height
                hWnd,     // Parent window
                (HMENU)2,       // Menu ID.
                (HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE),
                NULL);      // Pointer not needed.

            HWND stopButton = CreateWindow(
                L"BUTTON",  // Predefined class; Unicode assumed 
                L"STOP",      // Button text 
                WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,  // Styles 
                525,         // x position 
                300,         // y position 
                100,        // Button width
                50,        // Button height
                hWnd,     // Parent window
                (HMENU)3,       // Menu ID.
                (HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE),
                NULL);      // Pointer not needed.

            HWND exitButton = CreateWindow(
                L"BUTTON",  // Predefined class; Unicode assumed 
                L"EXIT",      // Button text 
                WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,  // Styles 
                1028,         // x position 
                470,         // y position 
                100,        // Button width
                50,        // Button height
                hWnd,     // Parent window
                (HMENU)4,       // Menu ID.
                (HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE),
                NULL);      // Pointer not needed.

            HWND hwndButton3 = CreateWindow(
                L"BUTTON",  // Predefined class; Unicode assumed 
                L"A",      // Button text 
                WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,  // Styles 
                700,         // x position 
                200,         // y position 
                50,        // Button width
                50,        // Button height
                hWnd,     // Parent window
                (HMENU)5,       // Menu ID.
                (HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE),
                NULL);      // Pointer not needed.

            HWND hwndButton4 = CreateWindow(
                L"BUTTON",  // Predefined class; Unicode assumed 
                L"C",      // Button text 
                WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,  // Styles 
                400,         // x position 
                200,         // y position 
                50,        // Button width
                50,        // Button height
                hWnd,     // Parent window
                (HMENU)6,       // Menu ID.
                (HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE),
                NULL);      // Pointer not needed.

            EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// Message handler for about box.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}
