TITLE Assignment 4 Question 1
;Kolby Sarson
;March 16th 2018
INCLUDE Irvine32.inc
.DATA
		print1 BYTE "What do you want to do?: ", 0
		decPrompt BYTE "Enter a 32-bit decimal number: ", 0
		stringPrompt BYTE "Enter a string: ", 0
		error1 BYTE "Get Lost Sweety Honey Bun", 0
		printEnd Byte "Thank you Sweety Honey Bun", 0
		charInput BYTE ?
		decimalNum BYTE 32 DUP(0)
		hexNum BYTE 64 DUP(0)
		buffer BYTE 32 DUP(0)

.CODE
	main PROC
		
		mov edx, OFFSET print1
		call WriteString
		mov edx, OFFSET charInput
		mov ecx, SIZEOF charInput
		call ReadChar
		mov charInput, al
		or charInput, 20h
		cmp charInput, 77h
		je HexOutput
		cmp charInput, 72h
		je HexInput


		mov edx, OFFSET error1
		call WriteString
		call crlf
		exit

		HexOutput:
			mov edx, OFFSET decPrompt
			call WriteString
			call crlf
			mov edx, OFFSET decimalNum
			call ReadInt
			mov ebx, eax
			call crlf
			mov ecx, 8
			START:
				rol ebx, 4
				mov dl, bl
				and dl, 0Fh
				cmp dl, 10
				jge HEX
				add dl, 30h
				jmp CONT
				HEX:
					add dl, 37h
			CONT:
			xor eax,eax
			mov al,dl
			call WriteChar
			LOOP START
			mov al,68h
			call WriteChar
			
			jmp final

		HexInput:
			
			mov edx, OFFSET  stringPrompt
			call WriteString
			call crlf
			mov edx, OFFSET hexNum
			mov ecx, SIZEOF hexNum
			call ReadString
			mov eax, edx
			call CrLf
			xor ebx, ebx
			
					mov ecx,16
					mov esi,OFFSET buffer
					L1:	shl eax,1
					mov BYTE PTR [esi],'0'
				;	call WriteBin
					jnc L2
				;	mov BYTE PTR [esi],'1'
					call WriteBin
					L2:	inc esi
					loop L1
			call WriteBin
			jmp final
		
		final:
			mov edx, OFFSET printEnd
			call CrLf
			call WriteString
			call CrLf
			exit

	exit
	main ENDP  
	END main 