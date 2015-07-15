#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <mmintrin.h>
#include <xmmintrin.h>

void ConverterVermelho(char *ptri, char *ptro, int loop)
{

	char masc[] = {255, 0, 0, 255, 0, 0, 255, 0}; 

	asm("mov %0, %%rax \n"
		"mov %1, %%rbx \n"
		"movl %3, %%ecx \n"
		"movl $0, %%edx \n"
		"movq %2, %%mm1 \n"
		"L1: movq (%%rax), %%mm0 \n"
		"pand %%mm1, %%mm0 \n"
		"movq %%mm0, (%%rbx) \n"
		"add $6, %%rax \n"
		"add $6, %%rbx \n"
		"add $6, %%edx \n"
		"cmp %%edx, %%ecx \n"
		"ja L1\n"
		:
		: "g"(ptri), "g" (ptro), "m" (*(__m64*)masc), "r" (loop)
		: "mm0", "rax", "rbx", "ecx", "edx");
}

void ConverterAmarelo(char *ptri, char *ptro, int loop)
{
	char masc[] = {255, 255, 0, 255, 255, 0, 255, 255}; 

	asm("mov %0, %%rax \n"
		"mov %1, %%rbx \n"
		"movl %3, %%ecx \n"
		"movl $0, %%edx \n"
		"movq %2, %%mm1 \n"
		"L2: movq (%%rax), %%mm0 \n"
		"por %%mm1, %%mm0 \n"
		"movq %%mm0, (%%rbx) \n"
		"add $6, %%rax \n"
		"add $6, %%rbx \n"
		"add $6, %%edx \n"
		"cmp %%edx, %%ecx \n"
		"ja L2\n"
		:
		: "g"(ptri), "g" (ptro), "m" (*(__m64*)masc), "r" (loop)
		: "mm0", "rax", "rbx", "ecx", "edx");



}

void ConverterVerde(char *ptri, char *ptro, int loop)
{

	char masc[] = {0, 255, 0, 0, 255, 0, 0, 255}; 
	asm("mov %0, %%rax \n"
		"mov %1, %%rbx \n"
		"movl %3, %%ecx \n"
		"movl $0, %%edx \n"
		"movq %2, %%mm1 \n"
		"L3: movq (%%rax), %%mm0 \n"
		"pand %%mm1, %%mm0 \n"
		"movq %%mm0, (%%rbx) \n"
		"add $6, %%rax \n"
		"add $6, %%rbx \n"
		"add $6, %%edx \n"
		"cmp %%edx, %%ecx \n"
		"ja L3\n"
		:
		: "g"(ptri), "g" (ptro), "m" (*(__m64*)masc), "r" (loop)
		: "mm0", "rax", "rbx", "ecx", "edx");


//	and al, 0
//	and dl, 0


}

void ConverterAzul(char *ptri, char *ptro, int loop)
{

	char masc[] = {0, 0, 255, 0, 0, 255, 0, 0}; 
	asm("mov %0, %%rax \n"
		"mov %1, %%rbx \n"
		"movl %3, %%ecx \n"
		"movl $0, %%edx \n"
		"movq %2, %%mm1 \n"
		"L4: movq (%%rax), %%mm0 \n"
		"pand %%mm1, %%mm0 \n"
		"movq %%mm0, (%%rbx) \n"
		"add $6, %%rax \n"
		"add $6, %%rbx \n"
		"add $6, %%edx \n"
		"cmp %%edx, %%ecx \n"
		"ja L4\n"
		:
		: "g"(ptri), "g" (ptro), "m" (*(__m64*)masc), "r" (loop)
		: "mm0", "rax", "rbx", "ecx", "edx");



	
//	and al, 0
//	and bl, 0

}

void ConverterRoxo(char *ptri, char *ptro, int loop)
{
	char masc[] = {255, 0, 255, 255, 0, 255, 255, 0}; 
	asm("mov %0, %%rax \n"
		"mov %1, %%rbx \n"
		"movl %3, %%ecx \n"
		"movl $0, %%edx \n"
		"movq %2, %%mm1 \n"
		"L5: movq (%%rax), %%mm0 \n"
		"pand %%mm1, %%mm0 \n"
		"movq %%mm0, (%%rbx) \n"
		"add $6, %%rax \n"
		"add $6, %%rbx \n"
		"add $6, %%edx \n"
		"cmp %%edx, %%ecx \n"
		"ja L5\n"
		:
		: "g"(ptri), "g" (ptro), "m" (*(__m64*)masc), "r" (loop)
		: "mm0", "rax", "rbx", "ecx", "edx");



//	and bl, 0

}

void ConverterOlive(char *ptri, char *ptro, int loop)
{
	char masc[] = {255, 255, 0, 255, 255, 0, 255, 255}; 
	asm("mov %0, %%rax \n"
		"mov %1, %%rbx \n"
		"movl %3, %%ecx \n"
		"movl $0, %%edx \n"
		"movq %2, %%mm1 \n"
		"L6: movq (%%rax), %%mm0 \n"
		"pand %%mm1, %%mm0 \n"
		"movq %%mm0, (%%rbx) \n"
		"add $6, %%rax \n"
		"add $6, %%rbx \n"
		"add $6, %%edx \n"
		"cmp %%edx, %%ecx \n"
		"ja L6\n"
		:
		: "g"(ptri), "g" (ptro), "m" (*(__m64*)masc), "r" (loop)
		: "mm0", "rax", "rbx", "ecx", "edx");


//	and dl, 0

}




void ConverterAqua(char *ptri, char *ptro, int loop)
{	

	char masc[] = {0, 255, 255, 0, 255, 255, 0, 255}; 
	asm("mov %0, %%rax \n"
		"mov %1, %%rbx \n"
		"movl %3, %%ecx \n"
		"movl $0, %%edx \n"
		"movq %2, %%mm1 \n"
		"L8: movq (%%rax), %%mm0 \n"
		"pand %%mm1, %%mm0 \n"
		"movq %%mm0, (%%rbx) \n"
		"add $6, %%rax \n"
		"add $6, %%rbx \n"
		"add $6, %%edx \n"
		"cmp %%edx, %%ecx \n"
		"ja L8\n"
		:
		: "g"(ptri), "g" (ptro), "m" (*(__m64*)masc), "r" (loop)
		: "mm0", "rax", "rbx", "ecx", "edx");



//	and al, 0
}



int main(int argc, char ** argv)
{
	clock_t start, end;
	double cpu_time_used;
	char filetype[256], *ptri, *ptro, *img;
	int width, height, depth, pixels;
        int opcao;
        opcao = atoi(argv[1]);
	fscanf(stdin, "%s\n", filetype);
	fprintf(stdout, "%s\n", filetype);

	fscanf(stdin, "%d %d %d\n", &width, &height, &depth);
	fprintf(stdout, "%d %d %d\n", width, height, depth);

	pixels = width * height;
	ptri = ptro = img = (char *) malloc(pixels * 3);
	fprintf(stderr, "tamanho = %d x %d = %d pixels\n", width, height, pixels);
	
	fread(img, 3, pixels, stdin);
	start = clock();

	int loop = pixels * 3;
        fprintf(stderr,"Filtro:%d\n", opcao);

	switch(opcao)
	{
		case 1:
			ConverterVermelho(ptri, ptro, loop);
			break;
		case 2:
			ConverterAmarelo(ptri, ptro, loop);
			break;
		case 3:
			ConverterVerde(ptri, ptro, loop);
			break;
		case 4:
			ConverterAzul(ptri, ptro, loop);
			break;
		case 5:
			ConverterRoxo(ptri, ptro, loop);
			break;
		case 6:
			ConverterOlive(ptri, ptro, loop);
			break;
		case 7:
			ConverterAqua(ptri, ptro, loop);
			break;	
	}
	
	end = clock();

	fwrite(img, 3, pixels, stdout);

	free(img);

	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	fprintf(stderr, "Implementação SIMD. \ntempo = %f segundos\n", cpu_time_used);
	return 0;
}

