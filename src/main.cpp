#include <windows.h>
#include <tchar.h>
#include <cstring>
#include <iomanip>
#include <iostream>
#include "resource.h"
#include <memory>
#include <commctrl.h>
const TCHAR Class_Name[] = TEXT("myWindowClass");
int selectindx = 0;
HINSTANCE hInstanced;

INT_PTR CALLBACK DlgaboutProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
  switch (msg)
  {
    case WM_COMMAND:
    {
      WORD id = LOWORD(wParam);

      switch (id)
      {
        case IDOK:
        {
          EndDialog(hwnd, (INT_PTR)id);
          return (INT_PTR)TRUE;
        }
      }
      break;
    }

    case WM_INITDIALOG:
    {
      return (INT_PTR)TRUE;
    }

    case WM_DESTROY:
    {
        EndDialog(hwnd, (INT_PTR)0);
        return (INT_PTR)TRUE;
    }
  }

  return (INT_PTR)FALSE;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    HWND button1;
    HWND textbox1;
    HWND textbox2;
    HWND textboxpass;
    HWND textboxpass2;
    HWND checkbox1;
    HWND hdlgnd;
    HMENU hmenu, subhmenu, subh2menu;
    int scnt;
    int scnt2;
    char keypass[MAX_PATH];
    char keypass2[MAX_PATH];
    char inputtext[MAX_PATH];
    LPCSTR clients[2] = {
        "Encrypt",
        "Decrypt"
    };
    switch(msg)
    {
        case WM_CREATE:
            hmenu = CreateMenu();
            subhmenu = CreatePopupMenu();
            subh2menu = CreatePopupMenu();

            AppendMenu(subh2menu, MF_STRING | BM_SETCHECK, ID_FILE_SAVETOFILE, TEXT("&Save result to file"));
            AppendMenu(hmenu, MF_STRING | MF_POPUP, (UINT_PTR) subh2menu, TEXT("&File"));
            AppendMenu(subhmenu, MF_STRING, ID_HELP_ABOUT, TEXT("&About"));
            AppendMenu(hmenu, MF_STRING | MF_POPUP, (UINT_PTR) subhmenu, TEXT("&Help"));
            
            button1 = CreateWindow(TEXT("button"), TEXT("Enter"), WS_VISIBLE | WS_CHILD, 10, 65, 55, 25, hwnd, (HMENU) 2, NULL, NULL);  
            textbox1 = CreateWindow(TEXT("Edit"), NULL, WS_CHILD | WS_VISIBLE | WS_BORDER | ES_AUTOHSCROLL | ES_AUTOVSCROLL, 10, 5, 180, 25, hwnd, (HMENU) 5, NULL, NULL);
            textboxpass = CreateWindow(TEXT("Edit"), NULL, WS_CHILD | WS_VISIBLE | WS_BORDER | ES_AUTOHSCROLL | ES_AUTOVSCROLL, 10, 35, 125, 25, hwnd, (HMENU) 6, NULL, NULL);
            textboxpass2 = CreateWindow(TEXT("Edit"), NULL, WS_CHILD | WS_VISIBLE | WS_BORDER | ES_AUTOHSCROLL | ES_AUTOVSCROLL, 135, 35, 55, 25, hwnd, (HMENU) 7, NULL, NULL);
            textbox2 = CreateWindow(TEXT("ComboBox"), NULL, WS_CHILD | WS_VISIBLE | CBS_DROPDOWNLIST, 70, 65, 120, 150, hwnd, (HMENU) 4, NULL, NULL);

            SetMenu(hwnd, hmenu);
            // SendMessage(GetDlgItem(hwnd, 4), CB_SETCURSEL, (WPARAM) 1, 0);

            for (int i = 0; i < 2; i++)
            {
                SendMessage(textbox2, CB_ADDSTRING, 1, (LPARAM) clients[i]);
            }

            SendMessage(textbox2, CB_SETCURSEL, (WPARAM)0, 0 );

        break;
        case WM_COMMAND:
            if (LOWORD(wParam) == 2)
            {
                GetWindowTextA(GetDlgItem(hwnd, 5), inputtext, MAX_PATH);
                GetWindowTextA(GetDlgItem(hwnd, 6), keypass, MAX_PATH);
                GetWindowTextA(GetDlgItem(hwnd, 7), keypass2, MAX_PATH);
                if (GetWindowTextLength(GetDlgItem(hwnd, 5)) <= 0)
                {
                    MessageBox(NULL, TEXT("Please enter a message"),TEXT("Error"), MB_OK | MB_ICONERROR);
                    std::cout << "Please enter a message" << std::endl;
                }
                scnt2 = atoi(keypass2);
                scnt = atoi(keypass);
                printf("\nexCrypter ver0.4exdbgbld\n");
                printf("\nYou need enter or create key for security\nWrite they in safe place\nFormat of key looks like <1234567890 12345>\nDEBUG BUILD VERSION EX4");
                printf("\nPlease enter a string:\t");
                std::cout << inputtext;
                printf("\nPlease choose following options:\n");
                printf("1 = Encrypt the string.\n");
                printf("2 = Decrypt the string.\n");
                std::cout << selectindx << std::endl;
                printf("Create or Provide Exist Key:\n");
                std::cout << scnt << " " << scnt2;
                // std::cout << keypass << std::endl;
                // std::cout << keypass2 << std::endl;
                switch(selectindx)
                {
                case 0:
                    for(int i = 0; (i < MAX_PATH && inputtext[i] != '\0'); i++)
                        inputtext[i] = inputtext[i] + scnt - scnt2 + 25 - 213 - 1 + 2 + scnt; //the key for encryption is 3 that is added to ASCII value
                    printf("\nYou Encrypted String! You now in safe");
                    printf("\nEncrypted string: %s\n", inputtext);
                    printf("\naddr %p | %p | %p", inputtext, scnt2, scnt);
                    break;

                case 1:
                    for(int i = 0; (i < MAX_PATH && inputtext[i] != '\0'); i++)
                        inputtext[i] = inputtext[i] - scnt + scnt2 - 25 + 213 + 1 - 2 - scnt; //the key for encryption is 3 that is subtracted to ASCII value
                    printf("\nYou Decrypted String!\n");
                    printf("\nDecrypted string: %s\n", inputtext);
                    printf("\naddr %p | %p | %p", inputtext, scnt2, scnt);
                    break;

                default:
                    printf("\nYou entered wrong number Select from 1 to 2\n");
                }
                SetDlgItemTextA(hwnd, 5, inputtext);
            }
            else if (HIWORD(wParam) == CBN_SELCHANGE)
            { 
                selectindx = SendMessage(GetDlgItem(hwnd, 4), CB_GETCURSEL, (WPARAM) 0, (LPARAM) 0);  
                std::cout << selectindx << std::endl;          
            }
            else if (LOWORD(wParam) == ID_HELP_ABOUT)
            {
                std::cout << "Show About DialogBox" << std::endl;
                hdlgnd = CreateDialog(hInstanced, MAKEINTRESOURCE(IDD_ABOUT), NULL, NULL);
                DialogBox(hInstanced, MAKEINTRESOURCE(IDD_ABOUT), hdlgnd, DlgaboutProc);
            }
            else if (LOWORD(wParam) == ID_FILE_SAVETOFILE)
            {
                std::cout << "saving" << std::endl;
            }
        break;
        case WM_CLOSE:
            DestroyWindow(hwnd);
        break;
        case WM_DESTROY:
            PostQuitMessage(0);
        break;
        default:
            return DefWindowProc(hwnd, msg, wParam, lParam);
    }
    return 0;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    WNDCLASSEX wc;
    HWND hwnd;
    MSG Msg;

    hInstanced = hInstance;

    ShowWindow(GetConsoleWindow(), SW_HIDE);

    wc.cbSize = sizeof(WNDCLASSEX);
    wc.cbClsExtra = 0;
    wc.cbWndExtra = 0;
    wc.lpszMenuName = NULL;
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_MYICON));
    wc.hIconSm = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_MYICON));
    wc.hInstance = hInstance;
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wc.lpfnWndProc = WndProc;
    wc.lpszClassName = Class_Name;
    wc.style = 0;

    if (!RegisterClassEx(&wc))
    {
        OutputDebugString(TEXT("CreateWindow FAILED"));
    }

    hwnd = CreateWindow(Class_Name, TEXT("Crypter WIN32"), WS_CAPTION | WS_SYSMENU, CW_USEDEFAULT, CW_USEDEFAULT, 210, 150, NULL, NULL, hInstance, NULL);

    if (hwnd == NULL)
    {
        OutputDebugString(TEXT("CreateWindow FAILED"));
    }

    ShowWindow(hwnd, nCmdShow);
    UpdateWindow(hwnd);

    while (GetMessage(&Msg, NULL, 0, 0) > 0)
    {
        TranslateMessage(&Msg);
        DispatchMessage(&Msg);
    }
    return Msg.wParam;
}