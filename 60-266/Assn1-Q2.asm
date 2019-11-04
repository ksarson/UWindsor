TITLE Assignment 1 Question 2
;Kolby Sarson
;February 7th 2018

INCLUDE Irvine32.inc

.data
bigEndian BYTE ?,?,?,?
littleEndian DWORD 12345678h
space byte "  ,  ",0

.code
main PROC
	mov al, bigEndian+4
	mov bigEndian, al

	mov al, bigEndian+5
	mov bigEndian+1, al

	mov al, bigEndian+6
	mov bigEndian+2, al

	mov al, bigEndian+7
	mov bigEndian+3, al

	movzx eax, bigEndian		; printing each array value
	call WriteHex
	mov edx, offset space		; space out the variables
	call WriteString
	mov al, bigEndian+1
	call WriteHex
	call WriteString
	mov al, bigEndian+2
	call WriteHex
	call WriteString
	mov al, bigEndian+3
	call WriteHex
	call WriteString

	exit
main ENDP
END main
