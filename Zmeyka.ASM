format PE console

include 'win32a.inc'
include 'structures.inc'
include 'procedures.inc'
include 'snakeLogic.inc'

entry start

section '.code' code readable writeable executable

        start:
                invoke GetStdHandle, STD_OUTPUT_HANDLE
                mov [stdOutDescriptor], eax
        main:
                invoke printf,strGameStarted
                add esp,4
                call adjustTheConsole
                call drawGameField
                call snakeRun
                call exit

section '.data' data readable writeable
        include 'variables.inc'

section '.idata' data import readable
        include 'winapi.inc'