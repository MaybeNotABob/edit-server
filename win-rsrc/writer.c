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
const char * szFilename[] ={"reader.exe\0"};


void writeSettings(_config *config) {
    HANDLE hRes = BeginUpdateResource( *szFilename, 0);
    if (NULL != hRes) {
        if (    UpdateResource( 
                    hRes, 
                    RT_RCDATA,
                    *resName,
                    MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
                    config,
                    sizeof(_config)
                )
            )
        {
            EndUpdateResource(hRes, 0);
        }
    }
}

int main(int argc, char* argv[]) {


    _config * cfg = (_config *) malloc(sizeof(_config));
    memset(cfg, 0, sizeof(_config));
    strcpy(cfg->hostname, "github.com\0");
    cfg->port = 6666;

    writeSettings(cfg);
    free(cfg); 
    

}