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

    cfg->hostname[0] = 'g';
    cfg->hostname[1] = 'i';
    cfg->hostname[2] = 't';
    cfg->hostname[3] = 'h';
    cfg->hostname[4] = 'u';
    cfg->hostname[5] = 'b';
    cfg->hostname[6] = '.';
    cfg->hostname[7] = 'c';
    cfg->hostname[8] = 'o';
    cfg->hostname[9] = 'm';
    cfg->hostname[10] = '\0';
    cfg->port = 6666;

    writeSettings(cfg);
    free(cfg); 
    

}