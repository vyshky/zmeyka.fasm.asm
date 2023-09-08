proc snakeRun
     enter 0,0
     mov [outBufferInfo.dwCursorPosition.x],2
     mov [outBufferInfo.dwCursorPosition.y],2

     @run:
         invoke Sleep,50
         invoke WriteConsoleOutputCharacter, [stdOutDescriptor], snakeTail, 1, [outBufferInfo.dwCursorPosition], result
         call coordinate_X_Inc
         invoke ReadConsoleOutputCharacter,[stdOutDescriptor], charBuf, 1, [outBufferInfo.dwCursorPosition],result
         movzx ax,BYTE[charBuf]
         movzx cx,BYTE[dogSumbol]
         cmp ax,cx

         ;; запись символа происходит в буфер

         jne @run

     leave
     ret
endp

proc delTail

endp