#include <windows.h>
#include <tchar.h>
#include "resource.h"
#include <iostream>
#include <fstream>
using namespace std;

BOOL CALLBACK DlgProc(HWND, UINT, WPARAM, LPARAM);


int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInst, LPTSTR lpszCmdLine, int nCmdShow)
{
    return DialogBox(hInstance, MAKEINTRESOURCE(IDD_DIALOG1), NULL, (DLGPROC)DlgProc);
}

DWORD WINAPI ThreadProc1(LPVOID lp)
{
    ofstream file;
    file.open("Task1.txt");
    for (int i = 0; i < 200; i++)
    {
        file << "information1\n";
        Sleep(10);
    }
    file.close();
    MessageBox(0, TEXT("����� ��������"), TEXT(""), MB_OK | MB_ICONINFORMATION);
    return 0;
}

DWORD WINAPI ThreadProc2(LPVOID lp)
{
    ofstream file;
    file.open("Task2.txt");
    for (int i = 0; i < 10; i++)
    {
        file << "information2\n";
        Sleep(1);
    }
    file.close();
    return 0;
}

DWORD WINAPI ThreadProc3(LPVOID lp)
{
    ofstream file;
    file.open("Task3.txt");
    for (int i = 0; i < 10; i++)
    {
        file << "information3\n";
        Sleep(1);
    }
    file.close();
    return 0;
}

BOOL CALLBACK DlgProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_COMMAND:
        if (wParam == IDC_BUTTON1)
        {
            EndDialog(hWnd, 0);
        }
        else if (wParam == IDC_BUTTON2)
        {
            CreateThread(NULL, 0, ThreadProc1, 0, 0, NULL);
            CreateThread(NULL, 0, ThreadProc2, 0, 0, NULL);
            CreateThread(NULL, 0, ThreadProc3, 0, 0, NULL);
        }
        return TRUE;
    case WM_CLOSE:
        EndDialog(hWnd, 0);
        return TRUE;
    }
    return FALSE;
}