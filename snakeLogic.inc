proc snakeInit
     ;; создаем координаты старта змеки
     mov [outBufferInfo.dwCursorPosition.x],5
     mov [outBufferInfo.dwCursorPosition.y],2
     call pushTail
     mov [outBufferInfo.dwCursorPosition.x],4
     mov [outBufferInfo.dwCursorPosition.y],2
     call pushTail
     mov [outBufferInfo.dwCursorPosition.x],3
     mov [outBufferInfo.dwCursorPosition.y],2
     call pushTail
     mov [outBufferInfo.dwCursorPosition.x],2
     mov [outBufferInfo.dwCursorPosition.y],2
     call pushTail
     ret
endp

proc snakeRun
     enter 0,0
     call snakeInit
     call snakeDraw
     invoke Sleep,[snakeSpeed]
     @start:
             ;;; Если все хорошо делаем шаг
             call snakeMov
             call snakeDraw
             invoke Sleep,[snakeSpeed]
             ;; Если зажата кнопка rightBtn то делаем проверку есть ли с права стенка
             mov eax,[snakeStackBasePointer]
             add eax,1
             ;mov [outBufferInfo.dwCursorPosition],eax
             ;add [outBufferInfo.dwCursorPosition.x],1
             invoke ReadConsoleOutputCharacter,[stdOutDescriptor], charBuf, 1, eax,result
             movzx ax,BYTE[charBuf]
             movzx cx,BYTE[dogSumbol]
             cmp ax,cx
             je @stop
             ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
     jmp @start

     @stop:
        leave
        ret
endp


proc snakeMov
     enter 0,0
     ;; Очищение последнего элемента хвоста
     mov ebx, [snakeSize]
     sub ebx, 1
     mov eax, [snakeStackBasePointer + ebx * 4]
     invoke WriteConsoleOutputCharacter, [stdOutDescriptor], NULLSumbol , 1, eax, result
     ;; Передвижение всех элементов на +1 в том направлении куда нажали кнопку
     ;; TODO реализовать для каждой кнопки разную логику по ++X,--X,++Y,--Y
     ;; перемещять координаты с левой части в правую, при этом голова перезапысывается новой координатой

     ;;;; Shift Stack all coord. left -> right
     mov ebx,[snakeSize]
     sub ebx,1
     @loopMov:
        mov eax,[snakeStackBasePointer + (ebx - 1) * 4] ;; Получаем предпоследний элеммент
        mov [snakeStackBasePointer + ebx * 4], eax ;; и записываем в последнии
        sub ebx,1
        cmp ebx,0
     jne @loopMov

     ;; change Head Coord rightBtn ++X
        mov eax,[snakeStackBasePointer]
        add eax,1
        mov [snakeStackBasePointer],eax
     leave
     ret
endp


proc pushTail
     enter 0,0
     mov ebx, [snakeSize]
     cmp ebx,0
     jne @push
        mov eax,snakeStackBasePointer
        mov ecx, [outBufferInfo.dwCursorPosition]
        mov [eax],ecx
        add [snakeSize],1
        leave
        ret
     @push:
        mov eax,snakeStackBasePointer
        mov ecx, [outBufferInfo.dwCursorPosition]
        mov [eax + ebx * 4],ecx
        add [snakeSize],1
     leave
     ret
endp



proc snakeDraw
     enter 0,0
     ;; Нарисовать голову
     xor ebx,ebx
     invoke WriteConsoleOutputCharacter, [stdOutDescriptor], strSnakeHead, 1, DWORD [snakeStackBasePointer], result
     add ebx,1
     ;;;;;;;;;;;;;;;;;;;;

     @loopRedraw:
        mov eax,[snakeStackBasePointer + ebx * 4]  ;; Получаем координату из стека и рисуем ее
        invoke WriteConsoleOutputCharacter, [stdOutDescriptor], strSnakeTail, 1, eax, result
        add ebx,1
        cmp ebx,[snakeSize]
     jne @loopRedraw
     leave
     ret
endp