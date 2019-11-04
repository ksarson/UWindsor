TITLE Program Assn2 (Assn2-Q1.asm)
;Vector Array Program
;Kolby Sarson
;February 16th 2018
INCLUDE Irvine32.inc
 
.data
Vector DWORD 50 DUP(?)
N DWORD ?
SumNumbers DWORD 0
PosCounter DWORD 0
PosI DWORD ?
PosJ DWORD ?
IJDiff DWORD ?
MinNum DWORD ?
repeat_ BYTE ?
 
str1 BYTE "What is the size N of Vector?> ",0
str2 BYTE "What are the values in Vector?> ",0
str3 BYTE "Size of Vector is N = ",0
str4 BYTE "Vector = ",0
str5 BYTE "The sum of all the negative values in Vector is: Sum = ",0
str6 BYTE "The number of all the positive values in Vector is: Count = ",0
str7 BYTE "Please give me two values I and J such that 1 <= I <= J <= N : ",0
str8 BYTE "I = ",0
str9 BYTE " and J = ",0
str10 BYTE "The minimum value between positions I and J of Vector is: Minimum = ",0
str11 BYTE "Vector is a palindrome because it reads the same way in both directions.",0
str12 BYTE "Vector is NOT a palindrome.",0
str13 BYTE "Repeat with a new Vector of different size and/or content? > ",0
IJinvalid BYTE "Invalid I or J.",0
space BYTE "  ",0
 
.code
main PROC
    start:
		mov N, 0
		mov SumNumbers, 0
		mov PosCounter, 0
		mov PosI, 0
		mov PosJ, 0
		mov IJDiff, 0
		mov MinNum, 0
		
        L1: mov edx,OFFSET str1     ;write the string for size
            call WriteString
            call ReadInt
            cmp eax, 0
            jle L1
        next: mov N,eax
 
        mov edx,OFFSET str2     ;write the string for vectors
        call WriteString
 
        LEA esi, Vector
        CALL ReadVector
 
        mov edx,OFFSET str3     ;write the string for N size
        call WriteString
        mov eax,N
        call WriteInt
        call crlf
 
        mov edx,OFFSET str4
        call WriteString
 
        LEA esi, Vector
        call WriteVector
        call crlf
 
        mov edx,OFFSET str5
        call WriteString
        Call SumNegative
        mov eax, SumNumbers
        call WriteInt
        call crlf
 
        mov edx,OFFSET str6
        call WriteString
        mov eax, PosCounter
        call WriteInt
        call crlf
 
        L0: mov edx,OFFSET str7     ; asking for I and J and displaying them
            call WriteString
            call ReadInt
            mov PosI, eax
            call ReadInt
            mov PosJ, eax
            cmp PosI, 1
            jl L00
            cmp PosJ,1
            jl L00
            cmp eax,PosI
            jl L00
            cmp N,eax
            jl L00
			jmp skip
		L00:
			mov edx, OFFSET IJInvalid
			call WriteString
			call crlf
			jmp L0
		skip:
        call crlf

        mov edx, OFFSET str8
        call WriteString
        mov eax, PosI
        call WriteInt
        mov edx, OFFSET str9
        Call WriteString
        mov eax, PosJ
        call WriteInt
        call crlf
;;;;;
		;MinValue Determinance
		mov eax, PosI   ;getting difference between i and j
		sub PosJ, eax
		mov eax, PosJ
		add eax, 1
		call WriteInt
		mov IJDiff, eax
		call crlf

		mov ecx, PosI	;Loop to the starting position, I
		LEA esi, Vector
		mov eax, [esi]
		ToI:
			add esi, 4
			Loop ToI

		mov ecx, IJDiff	;Loop from I to J
		mov eax, [esi]
		mov MinNum, eax
		NextMin:
			mov eax, [esi]
			cmp eax, MinNum
			jl if_true	;if next element is less than current min
			comeBackTrue:	;allows us to return from jump
				add esi, 4
				call WriteInt
				Loop NextMin
				ret
			add esi, 4
			call WriteInt
			Loop NextMin

			if_true:	;next element is less than current min
				mov MinNum, eax
				call comeBackTrue
			end_if:
;;;;;
		mov edx, OFFSET str10
        call WriteString
        mov eax, MinNum
        call WriteInt
 
        call crlf
        LEA esi, Vector
        CALL Palindrome
        call crlf

        mov edx,OFFSET str13
        call WriteString
        call ReadChar
        cmp al,79h          ; comparing entered value to y = 79h
        jne end_
        call crlf
        jmp start
    end_:	; ends if it is not y
	invoke ExitProcess, 0
main ENDP
 
ReadVector PROC     ; reading in the array
    mov ecx, N      ; N iterations
    NextDec:
        CALL ReadInt
        MOV [esi], eax
        add esi, 4
        Loop NextDec
    ret
ReadVector ENDP
 
WriteVector PROC        ; writing the array
    mov ecx, N
    NextVec:
        mov eax, [esi]
        call WriteInt
        add esi, 4
        mov edx, offset space
        Call WriteString
        Loop NextVec
    ret
WriteVector ENDP
 
SumNegative PROC        ; adding negative numbers and counting positives
    mov ecx, N
    LEA esi, Vector
    NextNum:
        mov eax, [esi]
        cmp eax, 0
        jl Negative
        inc PosCounter
        jmp Next
        Negative: add SumNumbers, eax
        Next:
        add esi, 4
        Loop NextNum
    ret
SumNegative ENDP
  
Palindrome PROC
    mov edi, esi
    mov edx, N
    dec edx
    shl edx, 2
    add edi, edx
    mov ecx, N
    shr ecx, 1
    mov eax, 1
    CheckPal: mov ebx, [esi]
        mov edx, [edi]
        cmp ebx, edx
        jne NotPalindrome
        add esi, 4
        sub edi, 4
        Loop CheckPal
        mov edx,OFFSET str11
        call WriteString
    ret
    NotPalindrome: mov eax, 0
        mov edx,OFFSET str12
        call WriteString
        ret
Palindrome ENDP
 
END main