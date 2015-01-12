INCLUDE Irvine32.inc

.data
    ;colocar o nome como o usuario digita
	fileInput BYTE "DC.pnm",0
	dataInput DWORD 100000 DUP(?)

	fileOutput BYTE "DCG.pnm",0
	dataOutput DWORD 100000 DUP(?)

.code

IdentificarPixel PROC USES ESI EDI,
 pixel: byte, totalpixel: dword
mov esi, offset dataInput

L2: inc esi
	mov eax, 0
	mov al, [esi]
	cmp al, 0Ah
	jne L2
	
	inc esi
	mov ebx, 0
	mov totalpixel, 1
	
	lea edi, pixel

L1: 
	mov al, [esi]
	mov [edi], al
	inc esi
	inc edi
	mov al, [esi]
	cmp al, 20h
	jne L1
	
	
	lea edx, pixel
	mov ecx, sizeof pixel
	call ParseInteger32

	imul totalpixel
	mov totalpixel, eax

	lea edi, pixel
	inc ebx
	inc esi

	cmp ebx, 2
	jne L1

	mov eax, totalpixel
	ret

IdentificarPixel ENDP

ConverterCor PROC

	mov ecx, eax
	dec edi
	mov ebx, 0

; ir por pixels aqui PARCE INT PARCE HEX
L1:	
	inc edi
	mov al, [esi]  ; al = R
 	inc esi
	mov bl, [esi]
	add eax, ebx  ; al = R + G
	add eax, ebx ; al = R + 2*G
	inc esi
	mov bl, [esi]
	add eax, ebx  ; al = R + 2*G + B
	shr eax, 2
	mov [edi], al
	inc edi
	mov [edi], al
	inc edi
	mov [edi], al
	inc esi
	loop L1

	; salvar o 0A
	inc edi
	dec esi
	mov al, [esi]
	mov [edi], al
	
	ret
ConverterCor ENDP


main PROC
	
	; abre o arquivo para entrada

	mov edx, OFFSET fileInput
	call OpenInputFile
	
	; leitura do arquivo
		
	mov edx, offset dataInput
	mov ecx, sizeof dataInput
	call ReadFromFile
	jc erro					;caso ocorra erro na leitura do arquivo
		
	; apontando para o inicio do dataInput e dataOuput

	mov esi, offset dataInput 
	mov edi, offset dataOutput
	
	; movendo os dados iniciais do arquivo
	mov ecx, 0
L1:	
	mov al, [esi]
	mov [edi], al
	inc edi
	inc esi
	inc ecx
	cmp ecx, 3
	jbe L1
	cmp al, 0Ah
	jne L1

	; identificando a quantidade de pixels

	call IdentificarPixel

	;;; convertendo para gray

	call ConverterCor
	 
	; calculando o tamanho do arquivo de saida
	
	inc edi
	mov edx, offset dataOutput
	mov ebx, edi
	sub ebx, edx
	
	; criando o arquivo de saída
		
	mov edx, offset fileOutput
	call CreateOutputFile
	jc erro
	; escrevendo no arquivo de saída

	mov edx, offset dataOutput
	mov ecx, ebx
	call WriteToFile
	jc erro
	cmp eax, 0
	;fechar o arquivo


erro:
	exit
main ENDP
END main


