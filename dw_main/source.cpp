#include "func.h"
#pragma comment(lib, "pdh.lib")
#define M_PI 3.14159265358979323846
#include "mathlogic.h"
#include "offsets.h"

/*

개인 공부용

스파게티코드 ㅆㅇㅈ


*/

void addrptrToValue(DWORD pmvar) {
    std::cout << std::hex << pmvar << std::endl;
}
class dw_f {
public:
    virtual dw_f* place_alt() {
        return new dw_f(*this);
    }

    void getUserInfo() { // 뭔지 모름 
        std::string username;
        std::string homeDir;

#ifdef _WIN32
        char user[UNLEN + 1];
        DWORD userLen = UNLEN + 1;
        if (GetUserNameA(user, &userLen)) {
            username = user;
        }
        else {
            username = "Unknown";
        }

        char home[MAX_PATH];
        if (GetEnvironmentVariableA("USERPROFILE", home, MAX_PATH)) {
            homeDir = home;
        }
        else {
            homeDir = "Unknown";
        }
#endif _WIN32
        std::cout << "유저네임: " << username << std::endl;
        std::cout << "바탕화면 경로: " << homeDir << std::endl;
    }

    DWORD check_info() {
        std::cout << "[info] " << std::endl;
        getUserInfo();
        std::cout << "현재 CPU사용 점유율: " << getCurrentValue() << "0x71 extern ret" << std::endl; Sleep(1000);
        return 0;
    }
}; dw_f di_function;

class mAlloc {
    DWORD GetPointerAddress(HWND hwnd, DWORD address, std::vector<DWORD> offsets)
    {
        DWORD pID = NULL;
        GetWindowThreadProcessId(hwnd, &pID);
        HANDLE phandle = NULL;
        phandle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pID);
        if (phandle == INVALID_HANDLE_VALUE || phandle == NULL);

        DWORD offset_null = NULL;
        ReadProcessMemory(phandle, (LPVOID*)address, &offset_null, sizeof(offset_null), 0);
        DWORD pointeraddress = offset_null;
        for (int i = 0; i < offsets.size() - 1; i++)
        {
            ReadProcessMemory(phandle, (LPVOID*)(pointeraddress + offsets.at(i)), &pointeraddress, sizeof(pointeraddress), 0);
        }
        return pointeraddress += offsets.at(offsets.size() - 1);
    }
    int getValueInt(HWND hwnd, DWORD address) {
        int ref = 1234;
        DWORD pID = NULL; // Game process ID
        GetWindowThreadProcessId(hwnd, &pID);
        HANDLE phandle = NULL;
        phandle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pID);
        ReadProcessMemory(phandle, (void*)address, &ref, sizeof(int), 0);
        return ref;
    }

    float getValueFloat(HWND hwnd, DWORD address) {
        float ref = 1234;
        DWORD pID = NULL; // Game process ID
        GetWindowThreadProcessId(hwnd, &pID);
        HANDLE phandle = NULL;
        phandle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pID);
        ReadProcessMemory(phandle, (void*)address, &ref, sizeof(float), 0);
        return ref;
    }
}; mAlloc ma;

class process_find { // void
};

int main() {
    std::string window_name; std::cout << "enter Process name: " << std::endl;
    std::string str_names = window_name;
    std::cin >> window_name; LPCSTR w_name = window_name.c_str();

    HWND wind = FindWindowA(NULL, w_name); // 멀티바이트 기반으로 바꿔야함 아마도
    GetWindowThreadProcessId(wind, &VAR.pid);
    HANDLE handler = OpenProcess(PROCESS_ALL_ACCESS, false, VAR.pid);
    std::cout << "[현재 프로세스 점유율]\n -> " << std::endl;
    di_function.check_info(); 
    if (VAR.pid != 1) {
        std::cout << str_names << " -> " << VAR.pid << " 이므로 존재하지 않는 프로세스" << std::endl;
        exit(1);
    }
    else {
        pVar matrix_array;
        memeory_base playerLocal;
        std::vector<DWORD> bot_array = { PLPP.enitity_bot[1] };


        system("cls");
        while (GetAsyncKeyState(0x01) & 0x8000) {

        } // mathlogic.h 쪽에서 함수 정의하고 끝내면 될거 같긴 한데 
    }
     
}