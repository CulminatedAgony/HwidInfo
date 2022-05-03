#include <iostream>
#include <windows.h>
#include <string>

using namespace std;

int main()
{
    string input;
    HW_PROFILE_INFO hwProfileInfo;

    GetCurrentHwProfile(&hwProfileInfo);

    cout << "Made by: Culminated\n" <<"Docked: " << hwProfileInfo.szHwProfileName << "\n" << "HWID: " << hwProfileInfo.szHwProfileGuid << "\n";
    cout << "\nDo you want to copy your HWID?\n" << "\nY/N\n";
    cin >> input;

    const char* output = hwProfileInfo.szHwProfileGuid;
    const size_t len = strlen(output) + 1;

    HGLOBAL hMem =  GlobalAlloc(GMEM_MOVEABLE, len);
    memcpy(GlobalLock(hMem), output, len);
    GlobalUnlock(hMem);

    OpenClipboard(0);

    if(input == "Y" || input == "y"){
        EmptyClipboard();
        SetClipboardData(CF_TEXT, hMem);
    }
}
