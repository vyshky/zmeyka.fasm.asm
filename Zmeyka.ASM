format PE console

include 'win32a.inc'
include 'structures.inc'
include 'procedures.inc'

entry start

section '.code' code readable writeable executable

        start:
                invoke GetStdHandle, STD_OUTPUT_HANDLE
                mov [stdOutDescriptor], eax
        main:
                ;; TODO :: �������� �������� ����
                ;; TODO :: �������� ��� ��������������. �������������� ������, �� ��� ����������
                ;invoke SetConsoleScreenBufferSize, [stdOutDescriptor], [commonCoord] ; ������� ����� � �������
                ;invoke GetConsoleScreenBufferInfo, [stdOutDescriptor], outBufferInfo
                invoke printf,strGameStarted
                add esp,4
                call adjustTheConsole
                call drawGameField
                call exit

section '.data' data readable writeable
        include 'variables.inc'

section '.idata' data import readable
        include 'winapi.inc'