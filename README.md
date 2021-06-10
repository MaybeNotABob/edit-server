# Examples of how C2 settings are hidden within malware.

The malware builder (aka edit-server) is typically responsible for writing settings to a malware payload (Trojan, RAT, Bot and so forth).
The aim of the project is to demonstrate possible ways in which Command and Control (C2) settings are stored within executable files, so that they can be extracted by security researchers. 

## Index
- Windows PE resources (.rsrc)
-
-


## Windows PE resources (.rsrc)

**Description**: Store a fixed size struct containing a hostname (github.com) and port (6666) within the resource section of a portable executable (PE / EXE).
More information about Windows resources: https://docs.microsoft.com/en-gb/windows/win32/menurc/resources-overviews

**Directory**: [win-rsrc/](https://github.com/MaybeNotABob/edit-server/tree/main/win-rsrc)
  
The following has been compiled and tested on Windows with Clang 10.0.1

Compile writer.exe

``` clang writer.c -o writer.exe ```

Compile reader.exe

``` clang reader.c -o reader.exe ```

**Test**

Both writer and reader should be compiled and within the same directory to perform the test.
Execute the writer which will update the resource section of the reader. The below screenshots show the resource section using Resource Hacker before and after execution of the writer.

Before:

![NoRsrc](https://github.com/MaybeNotABob/edit-server/blob/main/win-rsrc/01-reader-exe%20before%20executing%20writer-exe.png)

After:

![WithRsrc](https://github.com/MaybeNotABob/edit-server/blob/main/win-rsrc/02-reader-exe%20after%20executing%20writer-exe.png) 
