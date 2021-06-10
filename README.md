# Examples of how C2 settings are hidden within malware.

The malware builder (aka edit-server) is typically responsible for writing settings to a malware payload (Trojan, RAT, Bot and so forth).
The aim of the project is to demonstrate possible ways in which Command and Control (C2) settings are stored within executable files, so that they can be extracted by security researchers. 

## Windows PE resources (.rsrc)
Directory: win-rsrc/

The following has been compiled and tested on Windows 7 with Clang 10.0.1

Compile writer.exe

``` clang writer.c -o writer.exe ```

Compile reader.exe

``` clang reader.c -o reader.exe ```

