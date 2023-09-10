;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; common variables
stdOutDescriptor dd ?
outBufferInfo CONSOLE_SCREEN_BUFFER_INFO

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; variables
result dd ?
width dd 50
heght dd 25
charBuf db ?

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; Messages
strGameStarted db " Game started...",10,0
strPressAnyKey db 10," Press 'Esc' key for exit...",0
dogSumbol db '@'

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; Snake
NULLSumbol db 0
strSnakeTail db 'o'
strSnakeHead db 'O'
strSnakeHeadTest db '!'
snakeSize dd 0
snakeSpeed dd 500

snakeStack rb 100
snakeStackBasePointer dd ?
