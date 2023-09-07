        library kernel,'kernel32.dll',\
                msvcrt,'msvcrt.dll'


        import kernel,\
               GetStdHandle,'GetStdHandle',\
               WriteConsole,'WriteConsoleA',\
               ReadConsole,'ReadConsoleA',\
               ExitProcess,'ExitProcess',\
               SetConsoleCursorPosition,'SetConsoleCursorPosition',\
               SetConsoleScreenBufferSize,'SetConsoleScreenBufferSize',\
               SetConsoleTextAttribute,'SetConsoleTextAttribute',\
               SetConsoleWindowInfo,'SetConsoleWindowInfo',\
               GetConsoleScreenBufferInfo,'GetConsoleScreenBufferInfo',\
               WriteConsoleOutputCharacter,'WriteConsoleOutputCharacterA',\
               GetLastError,'GetLastError'

        import msvcrt,\
               printf,'printf',\
               getch,'_getch'   