.486
.model flat, stdcall
.data
DataString DB 'AGIJKSZ', 0FFH ; definicja ciagu znakow
.code

FindChar PROC NEAR
 MOV EBX, OFFSET DataString ; zaladuj offset zmiennej 'String' do rej. ESI
 XOR ESI, ESI ; wyzeruj indeks lancucha 'String' w ESI
 MOV AH, 'J' ; zaladuj kod litery 'J' do rej. AH
Check_End:
 CMP BYTE PTR [EBX+ESI], 0FFH ; czy koniec lancucha (znak specjalny FF)?
 JE Not_Find ; znaleziono znak konca (wartownik)
 CMP AH, BYTE PTR [EBX+ESI] ; porownaj znak z elementem lancucha 'String'
 JE Got_Equal ; znaleziono znak!
 INC ESI ; inkrementuj indeks
 JMP Check_End ; petla wyszukiwania
Got_Equal:
 MOV DL, [EBX+ESI] ; zaladuj znaleziony znak do DL
 JMP Done
Not_Find:
 MOV EAX,0 ; nie znaleziono znaku
 RET
Done:
 MOV EAX,1 ; znaleziono znak
 RET ; powrot z procedury
FindChar ENDP ; koniec FindChar
 END