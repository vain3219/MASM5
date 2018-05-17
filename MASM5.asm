;----------------------------------------------------------------------------------------------------
;	FILE NAME :		MASM5.asm
;----------------------------------------------------------------------------------------------------
;
;		Program Name	:	MASM5
;		Programmer		:	Cody Thompson 
;		Class			:	CS 3B || Asm Lang
;		Date			:	5/13/2018
;		Purpose			:	
;		Build a bubble sort function in assembly that will be called form a c++ program.
;
;----------------------------------------------------------------------------------------------------

	.486

	;Includes
	include ..\..\Irvine\Irvine32.inc
	include ..\..\Irvine\Macros.inc

	;Prototypes
	ExitProcess PROTO, dwExitCode:dword

	;Constants

	;Struct definitions
	
	;Macro definitions
	
	;Data segment
	.data
strSample 		BYTE 20 DUP(0), 0

	;Code segment
	.code
main proc												;start of main ;start of program
	CALL	BubbleSort1

	INVOKE ExitProcess,0								;terminate program
main ENDP												;end of main procedure



;-------------------------------------------------------
BubbleSort1 PROC 	USES 	eax ecx esi,
	pArray:PTR DWORD, 									; pointer to array
	Count:DWORD 										; array size
; Sort an array of 32-bit signed integers in ascending
; order, using the bubble sort algorithm.
; Receives: pointer to array, array size
; Returns: nothing
;-------------------------------------------------------
	mov ecx,Count
	dec ecx 											; decrement count by 1
L1: 
	push ecx 											; save outer loop count
	mov esi,pArray 										; point to first value
L2: 
	mov eax,[esi] 										; get array value
	cmp [esi+4],eax 									; compare a pair of values
	jg L3 												; if [ESI] <= [ESI+4], no exchange	
	xchg eax,[esi+4] 									; exchange the pair
	mov [esi],eax
L3: 
	add esi,4 											; move both pointers forward
	loop L2 											; inner loop
	pop ecx 											; retrieve outer loop count
	loop L1 											; else repeat outer loop
L4: 

	ret
BubbleSort1 ENDP


end main												;end of main










