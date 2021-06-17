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


const char * szFilename ={"reader.exe\0"};


 _config* readSettings() {

    _config * config = (_config *) malloc(sizeof(_config));
    

    FILE *fp = fopen(szFilename, "rb");
    if (NULL == fp) {
        printf("failed to open file\n");
        return NULL;
    }

    // set the file pointer to 
    // (file size - the size of the settings)
    if (0 != fseek(fp, (long) - sizeof(_config), SEEK_END)) {
        printf("failed to set file pointer within file\n");
        return NULL;
    }

    // read the settings back
    fread(&*config, sizeof(_config), 1, fp);

    // clean up
    fclose(fp);
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
    printf("Any error occured trying to access the file.");
}


// pause the terminal by waiting for a char.
getchar();

}
