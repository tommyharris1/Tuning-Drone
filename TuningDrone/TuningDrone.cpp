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
LRESULT CALLBACK    WndProc2(HWND, UINT, WPARAM, LPARAM);
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

   HWND hWnd2 = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU,
       CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd || !hWnd2)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   //ShowWindow(hWnd2, nCmdShow);
   UpdateWindow(hWnd2);

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
    case WM_CREATE:
    {
        HWND hwndButton = CreateWindowEx(
            0,
            L"BUTTON",  // Predefined class; Unicode assumed 
            NULL,      // Button text 
            WS_CHILD | BS_OWNERDRAW,  // Styles 
            800,         // x position 
            200,         // y position 
            50,        // Button width
            50,        // Button height
            hWnd,     // Parent window
            (HMENU)1,       // Menu ID
            (HINSTANCE)GetWindowLong(hWnd, GWL_HINSTANCE),
            NULL);      // Pointer not needed.
        ShowWindow(hwndButton, SW_SHOW);

        HWND hwndButton2 = CreateWindowEx(
            0,
            L"BUTTON",  // Predefined class; Unicode assumed 
            NULL,      // Button text 
            WS_CHILD | BS_OWNERDRAW,  // Styles 
            650,         // x position 
            300,         // y position 
            50,        // Button width
            50,        // Button height
            hWnd,     // Parent window
            (HMENU)2,       // Menu ID.
            (HINSTANCE)GetWindowLong(hWnd, GWL_HINSTANCE),
            NULL);      // Pointer not needed.
        ShowWindow(hwndButton2, SW_SHOW);

        HWND stopButton = CreateWindowEx(
            0,
            L"BUTTON",  // Predefined class; Unicode assumed 
            NULL,      // Button text 
            WS_CHILD | BS_OWNERDRAW,  // Styles 
            525,         // x position 
            400,         // y position 
            100,        // Button width
            50,        // Button height
            hWnd,     // Parent window
            (HMENU)3,       // Menu ID.
            (HINSTANCE)GetWindowLong(hWnd, GWL_HINSTANCE),
            NULL);      // Pointer not needed.
        ShowWindow(stopButton, SW_SHOW);

        HWND exitButton = CreateWindowEx(
            0,
            L"BUTTON",  // Predefined class; Unicode assumed 
            NULL,      // Button text 
            WS_CHILD | BS_OWNERDRAW,  // Styles 
            1028,         // x position 
            470,         // y position 
            100,        // Button width
            50,        // Button height
            hWnd,     // Parent window
            (HMENU)4,       // Menu ID.
            (HINSTANCE)GetWindowLong(hWnd, GWL_HINSTANCE),
            NULL);      // Pointer not needed.
        ShowWindow(exitButton, SW_SHOW);

        HWND hwndButton3 = CreateWindowEx(
            0,
            L"BUTTON",  // Predefined class; Unicode assumed 
            NULL,      // Button text 
            WS_CHILD | BS_OWNERDRAW,  // Styles 
            550,         // x position 
            300,         // y position 
            50,        // Button width
            50,        // Button height
            hWnd,     // Parent window
            (HMENU)5,       // Menu ID.
            (HINSTANCE)GetWindowLong(hWnd, GWL_HINSTANCE),
            NULL);      // Pointer not needed.
        ShowWindow(hwndButton3, SW_SHOW);

        HWND hwndButton4 = CreateWindowEx(
            0,
            L"BUTTON",  // Predefined class; Unicode assumed 
            NULL,      // Button text 
            WS_CHILD | BS_OWNERDRAW,  // Styles 
            300,         // x position 
            200,         // y position 
            50,        // Button width
            50,        // Button height
            hWnd,     // Parent window
            (HMENU)6,       // Menu ID.
            (HINSTANCE)GetWindowLong(hWnd, GWL_HINSTANCE),
            NULL);      // Pointer not needed.
        ShowWindow(hwndButton4, SW_SHOW);

        HWND hwndButton5 = CreateWindowEx(
            0,
            L"BUTTON",  // Predefined class; Unicode assumed 
            NULL,      // Button text 
            WS_CHILD | BS_OWNERDRAW,  // Styles 
            400,         // x position 
            200,         // y position 
            50,        // Button width
            50,        // Button height
            hWnd,     // Parent window
            (HMENU)7,       // Menu ID.
            (HINSTANCE)GetWindowLong(hWnd, GWL_HINSTANCE),
            NULL);      // Pointer not needed.
        ShowWindow(hwndButton5, SW_SHOW);

        HWND hwndButton6 = CreateWindowEx(
            0,
            L"BUTTON",  // Predefined class; Unicode assumed 
            NULL,      // Button text 
            WS_CHILD | BS_OWNERDRAW,  // Styles 
            500,         // x position 
            200,         // y position 
            50,        // Button width
            50,        // Button height
            hWnd,     // Parent window
            (HMENU)8,       // Menu ID.
            (HINSTANCE)GetWindowLong(hWnd, GWL_HINSTANCE),
            NULL);      // Pointer not needed.
        ShowWindow(hwndButton6, SW_SHOW);

        HWND hwndButton7 = CreateWindowEx(
            0,
            L"BUTTON",  // Predefined class; Unicode assumed 
            NULL,      // Button text 
            WS_CHILD | BS_OWNERDRAW,  // Styles 
            600,         // x position 
            200,         // y position 
            50,        // Button width
            50,        // Button height
            hWnd,     // Parent window
            (HMENU)9,       // Menu ID.
            (HINSTANCE)GetWindowLong(hWnd, GWL_HINSTANCE),
            NULL);      // Pointer not needed.
        ShowWindow(hwndButton7, SW_SHOW);

        HWND hwndButton8 = CreateWindowEx(
            0,
            L"BUTTON",  // Predefined class; Unicode assumed 
            NULL,      // Button text 
            WS_CHILD | BS_OWNERDRAW,  // Styles 
            700,         // x position 
            200,         // y position 
            50,        // Button width
            50,        // Button height
            hWnd,     // Parent window
            (HMENU)10,       // Menu ID.
            (HINSTANCE)GetWindowLong(hWnd, GWL_HINSTANCE),
            NULL);      // Pointer not needed.
        ShowWindow(hwndButton8, SW_SHOW);

        HWND hwndButton9 = CreateWindowEx(
            0,
            L"BUTTON",  // Predefined class; Unicode assumed 
            NULL,      // Button text 
            WS_CHILD | BS_OWNERDRAW,  // Styles 
            250,         // x position 
            300,         // y position 
            50,        // Button width
            50,        // Button height
            hWnd,     // Parent window
            (HMENU)11,       // Menu ID.
            (HINSTANCE)GetWindowLong(hWnd, GWL_HINSTANCE),
            NULL);      // Pointer not needed.
        ShowWindow(hwndButton9, SW_SHOW);

        HWND hwndButton10 = CreateWindowEx(
            0,
            L"BUTTON",  // Predefined class; Unicode assumed 
            NULL,      // Button text 
            WS_CHILD | BS_OWNERDRAW,  // Styles 
            350,         // x position 
            300,         // y position 
            50,        // Button width
            50,        // Button height
            hWnd,     // Parent window
            (HMENU)12,       // Menu ID.
            (HINSTANCE)GetWindowLong(hWnd, GWL_HINSTANCE),
            NULL);      // Pointer not needed.
        ShowWindow(hwndButton10, SW_SHOW);

        HWND hwndButton11 = CreateWindowEx(
            0,
            L"BUTTON",  // Predefined class; Unicode assumed 
            NULL,      // Button text 
            WS_CHILD | BS_OWNERDRAW,  // Styles 
            450,         // x position 
            300,         // y position 
            50,        // Button width
            50,        // Button height
            hWnd,     // Parent window
            (HMENU)13,       // Menu ID.
            (HINSTANCE)GetWindowLong(hWnd, GWL_HINSTANCE),
            NULL);      // Pointer not needed.
        ShowWindow(hwndButton11, SW_SHOW);

        HWND hwndButton12 = CreateWindowEx(
            0,
            L"BUTTON",  // Predefined class; Unicode assumed 
            NULL,      // Button text 
            WS_CHILD | BS_OWNERDRAW,  // Styles 
            750,         // x position 
            300,         // y position 
            50,        // Button width
            50,        // Button height
            hWnd,     // Parent window
            (HMENU)14,       // Menu ID.
            (HINSTANCE)GetWindowLong(hWnd, GWL_HINSTANCE),
            NULL);      // Pointer not needed.
        ShowWindow(hwndButton12, SW_SHOW);

        HWND hwndButton13 = CreateWindowEx(
            0,
            L"BUTTON",  // Predefined class; Unicode assumed 
            NULL,      // Button text 
            WS_CHILD | BS_OWNERDRAW,  // Styles 
            850,         // x position 
            300,         // y position 
            50,        // Button width
            50,        // Button height
            hWnd,     // Parent window
            (HMENU)15,       // Menu ID.
            (HINSTANCE)GetWindowLong(hWnd, GWL_HINSTANCE),
            NULL);      // Pointer not needed.
        ShowWindow(hwndButton13, SW_SHOW);

        HWND dropDown = CreateWindowEx(
            0, 
            L"BUTTON", NULL,
            WS_CHILD | BS_SPLITBUTTON,
            1000, 20, 120, 50,
            hWnd, (HMENU)100, (HINSTANCE)GetWindowLong(hWnd, GWL_HINSTANCE), NULL);
        ShowWindow(dropDown, SW_SHOW);
        break;
    }
    case WM_DRAWITEM:
        {
        LPDRAWITEMSTRUCT lpdis = (DRAWITEMSTRUCT*)lParam;
        SIZE size;
            switch ((UINT)wParam)
            {
            case 1:
                GetTextExtentPoint32(lpdis->hDC, L"F", strlen("F"), &size);
                SetTextColor(lpdis->hDC, RGB(204, 0, 102));
                SetBkColor(lpdis->hDC, RGB(0, 204, 102));
                ExtTextOut(lpdis->hDC,
                    ((lpdis->rcItem.right - lpdis->rcItem.left) - size.cx) / 2,
                    ((lpdis->rcItem.bottom - lpdis->rcItem.top) - size.cy) / 2,
                    ETO_OPAQUE | ETO_CLIPPED, &lpdis->rcItem, L"F", strlen("F"), NULL);
                DrawEdge(lpdis->hDC, &lpdis->rcItem,
                    (lpdis->itemState & ODS_SELECTED ?
                        EDGE_SUNKEN : EDGE_RAISED), BF_RECT);
                break;
            case 2:
                GetTextExtentPoint32(lpdis->hDC, L"A#/Bb", strlen("A#/Bb"), &size);
                SetTextColor(lpdis->hDC, RGB(204, 0, 102));
                SetBkColor(lpdis->hDC, RGB(0, 204, 102));
                ExtTextOut(lpdis->hDC,
                    ((lpdis->rcItem.right - lpdis->rcItem.left) - size.cx) / 2,
                    ((lpdis->rcItem.bottom - lpdis->rcItem.top) - size.cy) / 2,
                    ETO_OPAQUE | ETO_CLIPPED, &lpdis->rcItem, L"A#/Bb", strlen("A#/Bb"), NULL);
                DrawEdge(lpdis->hDC, &lpdis->rcItem,
                    (lpdis->itemState & ODS_SELECTED ?
                        EDGE_SUNKEN : EDGE_RAISED), BF_RECT);
                break;
            case 3:
                GetTextExtentPoint32(lpdis->hDC, L"STOP", strlen("STOP"), &size);
                SetTextColor(lpdis->hDC, RGB(0, 255, 255));
                SetBkColor(lpdis->hDC, RGB(0, 0, 255));
                ExtTextOut(lpdis->hDC,
                    ((lpdis->rcItem.right - lpdis->rcItem.left) - size.cx) / 2,
                    ((lpdis->rcItem.bottom - lpdis->rcItem.top) - size.cy) / 2,
                    ETO_OPAQUE | ETO_CLIPPED, &lpdis->rcItem, L"STOP", strlen("STOP"), NULL);
                DrawEdge(lpdis->hDC, &lpdis->rcItem,
                    (lpdis->itemState & ODS_SELECTED ?
                        EDGE_SUNKEN : EDGE_RAISED), BF_RECT);
                break;
            case 4:
                GetTextExtentPoint32(lpdis->hDC, L"EXIT", strlen("EXIT"), &size);
                SetTextColor(lpdis->hDC, RGB(0, 255, 255));
                SetBkColor(lpdis->hDC, RGB(0, 0, 255));
                ExtTextOut(lpdis->hDC,
                    ((lpdis->rcItem.right - lpdis->rcItem.left) - size.cx) / 2,
                    ((lpdis->rcItem.bottom - lpdis->rcItem.top) - size.cy) / 2,
                    ETO_OPAQUE | ETO_CLIPPED, &lpdis->rcItem, L"EXIT", strlen("EXIT"), NULL);
                DrawEdge(lpdis->hDC, &lpdis->rcItem,
                    (lpdis->itemState & ODS_SELECTED ?
                        EDGE_SUNKEN : EDGE_RAISED), BF_RECT);
                break;
            case 5:
                GetTextExtentPoint32(lpdis->hDC, L"A", strlen("A"), &size);
                SetTextColor(lpdis->hDC, RGB(204, 0, 102));
                SetBkColor(lpdis->hDC, RGB(0, 204, 102));
                ExtTextOut(lpdis->hDC,
                    ((lpdis->rcItem.right - lpdis->rcItem.left) - size.cx) / 2,
                    ((lpdis->rcItem.bottom - lpdis->rcItem.top) - size.cy) / 2,
                    ETO_OPAQUE | ETO_CLIPPED, &lpdis->rcItem, L"A", strlen("A"), NULL);
                DrawEdge(lpdis->hDC, &lpdis->rcItem,
                    (lpdis->itemState & ODS_SELECTED ?
                        EDGE_SUNKEN : EDGE_RAISED), BF_RECT);
                break;
            case 6:
                GetTextExtentPoint32(lpdis->hDC, L"C", strlen("C"), &size);
                SetTextColor(lpdis->hDC, RGB(204, 0, 102));
                SetBkColor(lpdis->hDC, RGB(0, 204, 102));
                ExtTextOut(lpdis->hDC,
                    ((lpdis->rcItem.right - lpdis->rcItem.left) - size.cx) / 2,
                    ((lpdis->rcItem.bottom - lpdis->rcItem.top) - size.cy) / 2,
                    ETO_OPAQUE | ETO_CLIPPED, &lpdis->rcItem, L"C", strlen("C"), NULL);
                DrawEdge(lpdis->hDC, &lpdis->rcItem,
                    (lpdis->itemState & ODS_SELECTED ?
                        EDGE_SUNKEN : EDGE_RAISED), BF_RECT);
                break;
            case 7:
                GetTextExtentPoint32(lpdis->hDC, L"C#/Db", strlen("C#/Db"), &size);
                SetTextColor(lpdis->hDC, RGB(204, 0, 102));
                SetBkColor(lpdis->hDC, RGB(0, 204, 102));
                ExtTextOut(lpdis->hDC,
                    ((lpdis->rcItem.right - lpdis->rcItem.left) - size.cx) / 2,
                    ((lpdis->rcItem.bottom - lpdis->rcItem.top) - size.cy) / 2,
                    ETO_OPAQUE | ETO_CLIPPED, &lpdis->rcItem, L"C#/Db", strlen("C#/Db"), NULL);
                DrawEdge(lpdis->hDC, &lpdis->rcItem,
                    (lpdis->itemState & ODS_SELECTED ?
                        EDGE_SUNKEN : EDGE_RAISED), BF_RECT);
                break;
            case 8:
                GetTextExtentPoint32(lpdis->hDC, L"D", strlen("D"), &size);
                SetTextColor(lpdis->hDC, RGB(204, 0, 102));
                SetBkColor(lpdis->hDC, RGB(0, 204, 102));
                ExtTextOut(lpdis->hDC,
                    ((lpdis->rcItem.right - lpdis->rcItem.left) - size.cx) / 2,
                    ((lpdis->rcItem.bottom - lpdis->rcItem.top) - size.cy) / 2,
                    ETO_OPAQUE | ETO_CLIPPED, &lpdis->rcItem, L"D", strlen("D"), NULL);
                DrawEdge(lpdis->hDC, &lpdis->rcItem,
                    (lpdis->itemState & ODS_SELECTED ?
                        EDGE_SUNKEN : EDGE_RAISED), BF_RECT);
                break;
            case 9:
                GetTextExtentPoint32(lpdis->hDC, L"D#/Eb", strlen("D#/Eb"), &size);
                SetTextColor(lpdis->hDC, RGB(204, 0, 102));
                SetBkColor(lpdis->hDC, RGB(0, 204, 102));
                ExtTextOut(lpdis->hDC,
                    ((lpdis->rcItem.right - lpdis->rcItem.left) - size.cx) / 2,
                    ((lpdis->rcItem.bottom - lpdis->rcItem.top) - size.cy) / 2,
                    ETO_OPAQUE | ETO_CLIPPED, &lpdis->rcItem, L"D#/Eb", strlen("D#/Eb"), NULL);
                DrawEdge(lpdis->hDC, &lpdis->rcItem,
                    (lpdis->itemState & ODS_SELECTED ?
                        EDGE_SUNKEN : EDGE_RAISED), BF_RECT);
                break;
            case 10:
                GetTextExtentPoint32(lpdis->hDC, L"E", strlen("E"), &size);
                SetTextColor(lpdis->hDC, RGB(204, 0, 102));
                SetBkColor(lpdis->hDC, RGB(0, 204, 102));
                ExtTextOut(lpdis->hDC,
                    ((lpdis->rcItem.right - lpdis->rcItem.left) - size.cx) / 2,
                    ((lpdis->rcItem.bottom - lpdis->rcItem.top) - size.cy) / 2,
                    ETO_OPAQUE | ETO_CLIPPED, &lpdis->rcItem, L"E", strlen("E"), NULL);
                DrawEdge(lpdis->hDC, &lpdis->rcItem,
                    (lpdis->itemState & ODS_SELECTED ?
                        EDGE_SUNKEN : EDGE_RAISED), BF_RECT);
                break;

            case 11:
                GetTextExtentPoint32(lpdis->hDC, L"F#/Gb", strlen("F#/Gb"), &size);
                SetTextColor(lpdis->hDC, RGB(204, 0, 102));
                SetBkColor(lpdis->hDC, RGB(0, 204, 102));
                ExtTextOut(lpdis->hDC,
                    ((lpdis->rcItem.right - lpdis->rcItem.left) - size.cx) / 2,
                    ((lpdis->rcItem.bottom - lpdis->rcItem.top) - size.cy) / 2,
                    ETO_OPAQUE | ETO_CLIPPED, &lpdis->rcItem, L"F#/Gb", strlen("F#/Gb"), NULL);
                DrawEdge(lpdis->hDC, &lpdis->rcItem,
                    (lpdis->itemState & ODS_SELECTED ?
                        EDGE_SUNKEN : EDGE_RAISED), BF_RECT);
                break;

            case 12:
                GetTextExtentPoint32(lpdis->hDC, L"G", strlen("G"), &size);
                SetTextColor(lpdis->hDC, RGB(204, 0, 102));
                SetBkColor(lpdis->hDC, RGB(0, 204, 102));
                ExtTextOut(lpdis->hDC,
                    ((lpdis->rcItem.right - lpdis->rcItem.left) - size.cx) / 2,
                    ((lpdis->rcItem.bottom - lpdis->rcItem.top) - size.cy) / 2,
                    ETO_OPAQUE | ETO_CLIPPED, &lpdis->rcItem, L"G", strlen("G"), NULL);
                DrawEdge(lpdis->hDC, &lpdis->rcItem,
                    (lpdis->itemState & ODS_SELECTED ?
                        EDGE_SUNKEN : EDGE_RAISED), BF_RECT);
                break;

            case 13:
                GetTextExtentPoint32(lpdis->hDC, L"G#/Ab", strlen("G#/Ab"), &size);
                SetTextColor(lpdis->hDC, RGB(204, 0, 102));
                SetBkColor(lpdis->hDC, RGB(0, 204, 102));
                ExtTextOut(lpdis->hDC,
                    ((lpdis->rcItem.right - lpdis->rcItem.left) - size.cx) / 2,
                    ((lpdis->rcItem.bottom - lpdis->rcItem.top) - size.cy) / 2,
                    ETO_OPAQUE | ETO_CLIPPED, &lpdis->rcItem, L"G#/Ab", strlen("G#/Ab"), NULL);
                DrawEdge(lpdis->hDC, &lpdis->rcItem,
                    (lpdis->itemState & ODS_SELECTED ?
                        EDGE_SUNKEN : EDGE_RAISED), BF_RECT);
                break;
            case 14:
                GetTextExtentPoint32(lpdis->hDC, L"B", strlen("B"), &size);
                SetTextColor(lpdis->hDC, RGB(204, 0, 102));
                SetBkColor(lpdis->hDC, RGB(0, 204, 102));
                ExtTextOut(lpdis->hDC,
                    ((lpdis->rcItem.right - lpdis->rcItem.left) - size.cx) / 2,
                    ((lpdis->rcItem.bottom - lpdis->rcItem.top) - size.cy) / 2,
                    ETO_OPAQUE | ETO_CLIPPED, &lpdis->rcItem, L"B", strlen("B"), NULL);
                DrawEdge(lpdis->hDC, &lpdis->rcItem,
                    (lpdis->itemState & ODS_SELECTED ?
                        EDGE_SUNKEN : EDGE_RAISED), BF_RECT);
                break;

            case 15:
                GetTextExtentPoint32(lpdis->hDC, L"C", strlen("C"), &size);
                SetTextColor(lpdis->hDC, RGB(204, 0, 102));
                SetBkColor(lpdis->hDC, RGB(0, 204, 102));
                ExtTextOut(lpdis->hDC,
                    ((lpdis->rcItem.right - lpdis->rcItem.left) - size.cx) / 2,
                    ((lpdis->rcItem.bottom - lpdis->rcItem.top) - size.cy) / 2,
                    ETO_OPAQUE | ETO_CLIPPED, &lpdis->rcItem, L"C", strlen("C"), NULL);
                DrawEdge(lpdis->hDC, &lpdis->rcItem,
                    (lpdis->itemState & ODS_SELECTED ?
                        EDGE_SUNKEN : EDGE_RAISED), BF_RECT);
                break;
            case 100:
                GetTextExtentPoint32(lpdis->hDC, L"TEST", strlen("TEST"), &size);
                SetTextColor(lpdis->hDC, RGB(204, 0, 102));
                SetBkColor(lpdis->hDC, RGB(0, 204, 102));
                ExtTextOut(lpdis->hDC,
                    ((lpdis->rcItem.right - lpdis->rcItem.left) - size.cx) / 2,
                    ((lpdis->rcItem.bottom - lpdis->rcItem.top) - size.cy) / 2,
                    ETO_OPAQUE | ETO_CLIPPED, &lpdis->rcItem, L"TEST", strlen("TEST"), NULL);
                DrawEdge(lpdis->hDC, &lpdis->rcItem,
                    (lpdis->itemState & ODS_SELECTED ?
                        EDGE_SUNKEN : EDGE_RAISED), BF_RECT);
                break;
            }
        }
        break;
    case WM_COMMAND:
        {
            switch (LOWORD(wParam)) 
            {
            case 1:
                PlaySound(TEXT("Drones\\FDrone.wav"), NULL, SND_FILENAME | SND_ASYNC);
                break;
            case 2:
                PlaySound(TEXT("Drones\\BbDrone.wav"), NULL, SND_FILENAME | SND_ASYNC);
                break;
            case 3:
                PlaySound(NULL, NULL, SND_FILENAME | SND_ASYNC);
                break;
            case 4:
                exit(1);
                break;
            case 5:
                PlaySound(TEXT("Drones\\ADrone.wav"), NULL, SND_FILENAME | SND_ASYNC);
                break;
            case 6:
                PlaySound(TEXT("Drones\\CDrone.wav"), NULL, SND_FILENAME | SND_ASYNC);
                break;
            case 7:
                PlaySound(TEXT("Drones\\DbDrone.wav"), NULL, SND_FILENAME | SND_ASYNC);
                break;
            case 8:
                PlaySound(TEXT("Drones\\DDrone.wav"), NULL, SND_FILENAME | SND_ASYNC);
                break;
            case 9:
                PlaySound(TEXT("Drones\\EbDrone.wav"), NULL, SND_FILENAME | SND_ASYNC);
                break;
            case 10:
                PlaySound(TEXT("Drones\\EDrone.wav"), NULL, SND_FILENAME | SND_ASYNC);
                break;
            case 11:
                PlaySound(TEXT("Drones\\GbDrone.wav"), NULL, SND_FILENAME | SND_ASYNC);
                break;
            case 12:
                PlaySound(TEXT("Drones\\GDrone.wav"), NULL, SND_FILENAME | SND_ASYNC);
                break;
            case 13:
                PlaySound(TEXT("Drones\\AbDrone.wav"), NULL, SND_FILENAME | SND_ASYNC);
                break;
            case 14:
                PlaySound(TEXT("Drones\\BDrone.wav"), NULL, SND_FILENAME | SND_ASYNC);
                break;
            case 15:
                PlaySound(TEXT("Drones\\HighCDrone.wav"), NULL, SND_FILENAME | SND_ASYNC);
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

LRESULT CALLBACK WndProc2(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
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
