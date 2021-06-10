/*
    - desciption: 
        Windows edit-Server example using resource section of a EXE.
        A server will read settings stored within its own .rsrc section using WinAPI.

    - date:
        04 June 2021

    - author:
         MaybeNotABob

    - licence:
        GPL

*/


#include <stdio.h>
#include <windows.h>

typedef struct {
    char hostname [11];
    int port;
} _config;

const char* resName[] = {"RESCONFIG\0"};
const char * szFilename ={"reader.exe\0"};


 _config* readSettings() {

    _config * config = (_config *) malloc(sizeof(_config));

    HRSRC hResInfo = FindResourceA(NULL, *resName, RT_RCDATA);
    if (NULL == hResInfo) {
        free(config);
        return NULL;
    }

    HANDLE hRes = LoadResource(NULL, hResInfo);

    if (NULL == hRes) {
        free(config);
        return NULL;
    }    


    DWORD dwSize = SizeofResource(NULL, hResInfo);
    LPVOID pResData = LockResource(hRes);
    memset(config, 0, dwSize);
    memcpy(config, pResData, dwSize);
    FreeResource(hRes); 
    return config;
} 


int main(int argc, char* argv[]) {

_config *cfg;
cfg = readSettings();

if (NULL != cfg) {
    printf("%s\n", cfg->hostname);
    printf("%d\n", cfg->port);
    free(cfg);
} 
else {
    printf("No resources detected or an error occured.");
}


// pause the terminal by waiting for a char.
getchar();

}
