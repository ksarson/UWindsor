TITLE Assignment 1 Question 1
;Kolby Sarson
;February 7th 2018
;Z = (A - B) + (C - D)

INCLUDE Irvine32.inc

.data
A SDWORD -210
B SDWORD 10
C1 SDWORD ?
D SDWORD ?
Z SDWORD ?

str1 BYTE "What is the value of C? ",0
str2 BYTE "What is the value of D? ",0
str3 BYTE "Z = (A - B) + (C - D)",0
space BYTE "   ;   ",0

.code
main PROC
	mov edx,OFFSET str1		;write the string for C
	call WriteString

	call ReadInt
	mov C1,eax

	mov edx,OFFSET str2		;write next string for D
	call WriteString

	call ReadInt
	mov D,eax

	mov edx,OFFSET str3		;write full statement
	call WriteString
	call Crlf

	mov eax, A			;write the values of the variables
	call WriteInt
	mov edx, offset space
	call WriteString
	mov eax, B
	call WriteInt
	call WriteString
	mov eax, C1
	call WriteInt
	call WriteString
	mov eax, D
	call WriteInt
	call Crlf

	mov eax,A		;A-B
	sub eax,B
	mov Z,eax

	mov eax,C1		;(A-B) + (C-D)
	sub eax,D
	add Z,eax

	mov eax,Z ;display results
	call WriteInt
	call crlf
	
	exit
main ENDP
END main 