#include <iostream> 
#include <fstream>
#include <Windows.h> 
#include <commdlg.h>
int main()
{
    int x;
    HWND start = 0;
    HWND send = 0;
    start = FindWindow(NULL, L"Notatnik");
    if (start == NULL)
    {
        std::cout << "Nie znaleziono notatnika\n";
    }
    HWND ser = FindWindowExW(start, NULL, L"NotepadTextBox", NULL);
    HWND edit = FindWindowExW(ser, NULL, L"RichEditD2DPT", NULL);
    HWND saveAsButton = 0;
    HANDLE hFile = 0;
    if (edit == NULL)
    {
        std::cout << "Nie znaleziono pola notatnika by wypelnic nim wartosci\n";
        system("pause");
    }
    else {
        OPENFILENAME ofn;
        wchar_t szFile[MAX_PATH] = { 0 };
        while (true) {
            system("CLS");
            std::cout << "Co chcialbys zrobic w notatniku\n";
            std::cout << "0 - by wyjsc z programu\n";
            std::cout << "1 - dodaj tekst\n";
            std::cout << "2 - zapisz do pliku\n";
            std::cout << "3 - usun zawartosc\n";
            std::cout << "4 - minimalizacja notatnika\n";
            std::cout << "5 - maksymalizacja notatnika\n";
            std::cin >> x;
            if (x == 0) break;
            switch(x)
            {
            case 1:
                SendMessage(edit, WM_SETTEXT, 0, (LPARAM)L"Lorem ipsum");
                break;
            case 2:
                ZeroMemory(&ofn, sizeof(ofn));
                ofn.lStructSize = sizeof(ofn);
                ofn.hwndOwner = GetForegroundWindow();
                ofn.lpstrFilter = L"Text Files (*.txt)\0*.txt\0All Files (*.*)\0*.*\0";
                ofn.lpstrFile = szFile;
                ofn.nMaxFile = sizeof(szFile);
                ofn.Flags = OFN_EXPLORER | OFN_OVERWRITEPROMPT;

                if (GetSaveFileName(&ofn)) {
                    std::wofstream outfile(ofn.lpstrFile);
                    if (outfile.is_open()) {
                        char buffer[1024];
                        GetWindowTextA(edit, buffer, 1024);
                        outfile << buffer;
                        outfile.close();
                    }
                }
                break;
            case 3:
                //clear notepad
                SendMessage(edit, WM_SETTEXT, 0, (LPARAM)L"");
                std::cout << "Window handle: " << std::hex << start << std::endl;

                break;
            case 4:
                ShowWindow(start, SW_MINIMIZE);
                break;
            case 5:
                ShowWindow(start, SW_MAXIMIZE);
                break;
            default:
                std::cout << "";
                break;
            }
        }
    }
    return 0;
}