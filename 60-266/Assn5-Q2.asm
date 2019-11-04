TITLE Assignment 5 Question 2
;Kolby Sarson
;March 30th 2018
INCLUDE Irvine32.inc

.data
	num1 DWORD ?
	p1 BYTE "Factorial of ",0
	p2 BYTE " is ",0

.code

fac PROC
	mov ecx, eax
	dec ecx
	LOOP_main:

		mul ecx

	LOOP LOOP_main
	done:
	ret
fac ENDP

main proc
	
	mov num1, 5d

	mov edx, OFFSET p1
	call WriteString
	mov eax, num1
	call writedec

	mov eax, num1
	call fac

	mov edx, OFFSET p2
	call WriteString
	call writedec
	call crlf

	exit
main endp
end main