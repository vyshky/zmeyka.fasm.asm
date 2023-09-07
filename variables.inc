;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; common variables
stdOutDescriptor dd ?
stdErrorDescriptor dd ?
cursorCoord COORD


;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; variables
;coordBuffer COORD 30000,30000;0x6FFF,0x1000   ;; 0x7FFE - ìàêñèìàëüíûé ðàçìåð áóôåðà ïîêà íå ïîíÿë ïî÷åìó â êîíöå íå ïîëó÷àåòñÿ ââåñòè F
;rect RECT 0,0, 50,30  ; Ýòî 2 êîîðäèíàòû, a,b è c,d.  a è ñ - ýòî X êîîðäèíàòà,  b è d - Y êîîðäèíàòà
outBufferInfo CONSOLE_SCREEN_BUFFER_INFO
result dd ?
width dd 50
heght dd 25

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; Messages
strGameStarted db ' Game started...',0
strPressAnyKey db 10,' Press any key for exit...',0
dogSumbol db '@'
customSumbol2 db '!'  