/*
    - desciption: 
        Windows edit-Server example using EOF (end of file) setitngs contained within a EXE file.


    - date:
        17 June 2021

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


const char * szFilename[] ={"reader.exe\0"};


void writeSettings(_config *config) {
    // open the reader file and get a file pointer
    FILE *fp = fopen(*szFilename, "ab");

    // write the settings
    fwrite(& (*config), sizeof(_config), 1, fp);

    // clean up
    fclose(fp);

}

int main(int argc, char* argv[]) {


    _config * cfg = (_config *) malloc(sizeof(_config));
    memset(cfg, 0, sizeof(_config));
    strcpy(cfg->hostname, "github.com\0");
    cfg->port = 6666;

    writeSettings(cfg);
    free(cfg); 
    
    // pause the terminal by waiting for a char.
    //getchar();
}