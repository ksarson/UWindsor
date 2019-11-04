TITLE Assignment 5 Question 1
;Kolby Sarson
;March 30th 2018
INCLUDE Irvine32.inc

.data
	num1 DWORD ?
	num2 DWORD ?
	count DWORD ?
	p1 BYTE "GCD of ",0
	p2 BYTE " and ",0
	p3 BYTE " is ",0

.code

gcd PROC
	cmp ecx, 0  
	jle done	; b==0
		sub edx, edx
		div ecx 
		mov eax, ecx	; a=b
		mov ecx, edx	; b = a%b
		call gcd
	done:
	ret
gcd ENDP

main proc
	mov count, 1

	mov num1, 5d
	mov num2, 20d
	jmp output

	pair2:
		mov num1, 24d
		mov num2, 18d
		jmp output

	pair3:
		mov num1, 11d
		mov num2, 7d
		jmp output

	pair4:
		mov num1, 432d
		mov num2, 226d
		jmp output

	pair5:
		mov num1, 0d
		mov num2, 0d
		jmp output

	output:
		mov edx, OFFSET p1
		call WriteString
		mov eax, num1
		call writedec

		mov edx, OFFSET p2
		call WriteString
		mov eax, num2
		call writedec

		mov eax, num1
		mov ecx, num2
		call gcd

		mov edx, OFFSET p3
		call WriteString
		call writedec
		call crlf

		add count, 1
		cmp count, 2
		je pair2
		cmp count, 3
		je pair3
		cmp count, 4
		je pair4
		cmp count, 5
		je pair5

	exit
main endp
end main