#include <time.h>
#include <stdio.h>
#include <stdlib.h>


void ConverterCinza(char *R, char *G, char *B)
{
        char m;
        asm("movzbl %1, %%eax \n"
	    "movzbl %2, %%ebx \n"
	    "movzbl %3, %%ecx \n"
	    "addl %%ebx, %%eax \n"
            "addl %%ebx, %%eax \n"
            "addl %%ecx, %%eax \n"
            "shrl $2, %%eax\n"
            "mov %%al, %0"
             : "=r"(m)
             : "r"(*R), "r"(*G), "r"(*B)
             : "eax");
        
        *R = *G = *B = m;
}


int main()
{
        char filetype[256], *ptri, *ptro, *img;
        char r, g, b;
        int i;
        int width, height, depth, pixels;
        fscanf(stdin, "%s\n", filetype);
        fprintf(stdout, "%s\n", filetype);

        fscanf(stdin, "%d %d %d\n", &width, &height, &depth);
        fprintf(stdout, "%d %d %d\n", width, height, depth);

        pixels = width * height;
        ptri = ptro = img = (char *) malloc(pixels * 3);
        fprintf(stderr, "tamanho = %d x %d = %d pixels\n", width, height, pixels);
        
        fread(img, 3, pixels, stdin);
        for (i = 0; i < pixels; i++)
        {
                r = *ptri++;
                g = *ptri++;
                b = *ptri++;
                
                ConverterCinza(&r, &g, &b);

       		*ptro++ = (char)r;
                *ptro++ = (char)g;
                *ptro++ = (char)b;
        }


        fprintf(stderr,"Convertido em cinza!\n");
        fwrite(img, 3, pixels, stdout);

        free(img);
        return 0;
}

