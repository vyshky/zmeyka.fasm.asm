proc adjustTheConsole
     ;push ebp
     ;mov ebp,esp
     enter 0,0
     invoke SetConsoleTextAttribute,[stdOutDescriptor], 4
     invoke GetConsoleScreenBufferInfo, [stdOutDescriptor], outBufferInfo
     mov bx, word [width]
     add ebx,2
     mov [outBufferInfo.srWindow.right], bx
     mov bx, word [heght]
     add ebx,10
     mov [outBufferInfo.srWindow.bottom], bx
     invoke SetConsoleWindowInfo, [stdOutDescriptor], TRUE, outBufferInfo.srWindow
     leave
     ;mov esp,ebp
     ;pop ebp
     ret
endp

proc drawGameField
     enter 0,0
     mov [outBufferInfo.dwCursorPosition.x],1
     mov [outBufferInfo.dwCursorPosition.y],1
     invoke SetConsoleCursorPosition,[stdOutDescriptor],[outBufferInfo.dwCursorPosition]

     xor ebx,ebx
     @topSide:
        invoke WriteConsoleOutputCharacter, [stdOutDescriptor], dogSumbol, 1, [outBufferInfo.dwCursorPosition], result
        add ebx,1
        call coordinate_X_Inc
        cmp ebx,[width]
        jne @topSide

     xor ebx,ebx
     @rightSide:
        invoke WriteConsoleOutputCharacter, [stdOutDescriptor], dogSumbol, 1, [outBufferInfo.dwCursorPosition], result
        add ebx,1
        call coordinate_Y_Inc
        cmp ebx,[heght]
        jne @rightSide

     xor ebx,ebx
     @bottomSide:
        invoke WriteConsoleOutputCharacter, [stdOutDescriptor], dogSumbol, 1, [outBufferInfo.dwCursorPosition], result
        add ebx,1
        call coordinate_X_Dec
        cmp ebx,[width]
        jne @bottomSide

     xor ebx,ebx
     @leftSide:
        invoke WriteConsoleOutputCharacter, [stdOutDescriptor], dogSumbol, 1, [outBufferInfo.dwCursorPosition], result
        add ebx,1
        call coordinate_Y_Dec
        cmp ebx,[heght]
        jne @leftSide

     ; Переводим курсор в конец игрового поля
     movzx ebx, word [width]
     add ebx,1
     mov [outBufferInfo.dwCursorPosition.x],bx
     movzx ebx, word [heght]
     add ebx,1
     mov [outBufferInfo.dwCursorPosition.y],bx
     invoke SetConsoleCursorPosition,[stdOutDescriptor],[outBufferInfo.dwCursorPosition]
     leave
     ret
endp

proc coordinate_X_Inc
     enter 0,0
     add [outBufferInfo.dwCursorPosition.x],1
     leave
     ret
endp

proc coordinate_X_Dec
     enter 0,0
     sub [outBufferInfo.dwCursorPosition.x],1
     leave
     ret
endp

proc coordinate_Y_Inc
     enter 0,0
     add [outBufferInfo.dwCursorPosition.y],1
     leave
     ret
endp

proc coordinate_Y_Dec
     enter 0,0
     sub [outBufferInfo.dwCursorPosition.y],1
     leave
     ret
endp

proc exit
     invoke SetConsoleTextAttribute,[stdOutDescriptor], 4
     invoke printf,strPressAnyKey
     invoke getch
     invoke ExitProcess,0
endp