#include <time.h>
#include <stdio.h>
#include <stdlib.h>

void ConverterVermelho(char *R, char *G, char *B)
{

        asm("movzbl %2, %%eax \n"
            "andl $0, %%eax \n"
            "mov %%al, %0 \n"
            "movzbl %3, %%eax \n"
            "andl $0, %%eax\n"
            "mov %%al, %1"
             : "=r"(*G), "=r"(*B)
             : "r"(*G), "r"(*B)
             : "eax");
        
}

void ConverterAmarelo(char *R, char *G, char *B)
{

        asm("movzbl %2, %%eax \n"
            "orl $255, %%eax \n"
            "mov %%al, %0 \n"
            "movzbl %3, %%eax \n"
            "orl $255, %%eax\n"
            "mov %%al, %1"
             : "=r"(*R), "=r"(*G)
             : "r"(*R), "r"(*G)
             : "eax");


}

void ConverterVerde(char *R, char *G, char *B)
{

        asm("movzbl %2, %%eax \n"
            "andl $0, %%eax \n"
            "mov %%al, %0 \n"
            "movzbl %3, %%eax \n"
            "andl $0, %%eax\n"
            "mov %%al, %1"
             : "=r"(*R), "=r"(*B)
             : "r"(*R), "r"(*B)
             : "eax");

//      and al, 0
//      and dl, 0


}

void ConverterAzul(char *R, char *G, char *B)
{

        asm("movzbl %2, %%eax \n"
            "andl $0, %%eax \n"
            "mov %%al, %0 \n"
            "movzbl %3, %%eax \n"
            "andl $0, %%eax\n"
            "mov %%al, %1"
             : "=r"(*R), "=r"(*G)
             : "r"(*R), "r"(*G)
             : "eax");

        
//      and al, 0
//      and bl, 0

}

void ConverterRoxo(char *R, char *G, char *B)
{
        asm("movzbl %1, %%eax \n"
            "andl $0, %%eax \n"
            "mov %%al, %0"
             : "=r"(*G)
             : "r"(*G)
             : "eax");

//      and bl, 0

}

void ConverterOlive(char *R, char *G, char *B)
{

        asm("movzbl %1, %%eax \n"
            "andl $0, %%eax\n"
            "mov %%al, %0"
             : "=r"(*B)
             : "r"(*B)
             : "eax");

//      and dl, 0

}




void ConverterAqua(char *R, char *G, char *B)
{       
        asm("movzbl %1, %%eax \n"
            "andl $0, %%eax \n"
            "mov %%al, %0"
             : "=r"(*R)
             : "r"(*R)
             : "eax");

//      and al, 0
}


int main(int argc, char ** argv)
{
        clock_t start, end;
        double cpu_time_used;
        char filetype[256], *ptri, *ptro, *img;
        char r, g, b;
        int i;
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
        fprintf(stderr,"Filtro:%d\n", opcao);

        for (i = 0; i < pixels; i++)
        {
                r = *ptri++;
                g = *ptri++;
                b = *ptri++;
               

                switch(opcao)
                {
                        case 1:
                                ConverterVermelho(&r, &g, &b);
                                break;
                        case 2:
                                ConverterAmarelo(&r, &g, &b);
                                break;
                        case 3:
                                ConverterVerde(&r, &g, &b);
                                break;
                        case 4:
                                ConverterAzul(&r, &g, &b);
                                break;
                        case 5:
                                ConverterRoxo(&r, &g, &b);
                                break;
                        case 6:
                                ConverterOlive(&r, &g, &b);
                                break;
                        case 7:
                                ConverterAqua(&r, &g, &b);
                                break;  
                }
                
                *ptro++ = (char)r;
                *ptro++ = (char)g;
                *ptro++ = (char)b;
        }
        end = clock();

        fwrite(img, 3, pixels, stdout);

        free(img);

        cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
        fprintf(stderr, "Implementação sequencial. \ntempo = %f segundos\n", cpu_time_used);
        return 0;
}

