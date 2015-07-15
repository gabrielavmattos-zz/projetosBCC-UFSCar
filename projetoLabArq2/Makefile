CC=cc -m64
CFLAGS=-c -Wall
LDFLAGS=-m64


SOURCES=converteCinza.c
SOURCES1=projeto_seq.c
SOURCES2=projeto_paralelo.c


OBJECTS=$(SOURCES:.c=.o)
OBJECTS1=$(SOURCES1:.c=.o)
OBJECTS2=$(SOURCES2:.c=.o)

EXEC=./converteCinza
EXEC1=./sequencial
EXEC2=./paralelo

b = Beach.pnm 
d = DC.pnm
f = Flower.pnm 
l = Lion.pnm 
lo = Lorikeet.pnm
t = Torre.pnm 
u = UFSCar.pnm


all: $(SOURCES) $(EXEC) test 

$(EXEC): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.c.o:
	$(CC) $(CFLAGS) $< -o $@

test:
	@echo
	@echo "Convertendo para cinza: "
	@echo
	
	$(EXEC) <in/$(b)> out/$(b)
	$(EXEC) <in/$(d)> out/$(d)
	$(EXEC) <in/$(f)> out/$(f)
	$(EXEC) <in/$(l)> out/$(l)
	$(EXEC) <in/$(lo)> out/$(lo)
	$(EXEC) <in/$(t)> out/$(t)
	$(EXEC) <in/$(u)> out/$(u)

all: $(SOURCES1) $(EXEC1)  $(SOURCES2) $(EXEC2) test1

$(EXEC1): $(OBJECTS1)
	$(CC) $(LDFLAGS) $(OBJECTS1) -o $@


$(EXEC2): $(OBJECTS2)
	$(CC) $(LDFLAGS) $(OBJECTS2) -o $@


test1:
	@echo Imagem $(b) 
	@echo
	$(EXEC1) 1 <out/$(b)> out/Seq_1_$(b)
	@echo
	$(EXEC2) 1 <out/$(b)> out/Par_1_$(b)
	@echo
	$(EXEC1) 2 <out/$(b)> out/Seq_2_$(b)
	@echo
	$(EXEC2) 2 <out/$(b)> out/Par_2_$(b)
	@echo
	$(EXEC1) 3 <out/$(b)> out/Seq_3_$(b)
	@echo
	$(EXEC2) 3 <out/$(b)> out/Par_3_$(b)
	@echo
	$(EXEC1) 4 <out/$(b)> out/Seq_4_$(b)
	@echo
	$(EXEC2) 4 <out/$(b)> out/Par_4_$(b)  
	@echo
	$(EXEC1) 5 <out/$(b)> out/Seq_5_$(b)
	@echo
	$(EXEC2) 5 <out/$(b)> out/Par_5_$(b)
	@echo
	$(EXEC1) 6 <out/$(b)> out/Seq_6_$(b)
	@echo
	$(EXEC2) 6 <out/$(b)> out/Par_6_$(b)
	@echo
	$(EXEC1) 7 <out/$(b)> out/Seq_7_$(b)
	@echo
	$(EXEC2) 7 <out/$(b)> out/Par_7_$(b)



	@echo Imagem $(d) 

	@echo
	$(EXEC1) 1 <out/$(d)> out/Seq_1_$(d)
	@echo
	$(EXEC2) 1 <out/$(d)> out/Par_1_$(d)
	@echo
	$(EXEC1) 2 <out/$(d)> out/Seq_2_$(d)
	@echo
	$(EXEC2) 2 <out/$(d)> out/Par_2_$(d)
	@echo
	$(EXEC1) 3 <out/$(d)> out/Seq_3_$(d)
	@echo
	$(EXEC2) 3 <out/$(d)> out/Par_3_$(d)
	@echo
	$(EXEC1) 4 <out/$(d)> out/Seq_4_$(d) 
	@echo
	$(EXEC2) 4 <out/$(d)> out/Par_4_$(d) 
	@echo
	$(EXEC1) 5 <out/$(d)> out/Seq_5_$(d)
	@echo
	$(EXEC2) 5 <out/$(d)> out/Par_5_$(d)
	@echo
	$(EXEC1) 6 <out/$(d)> out/Seq_6_$(d)
	@echo
	$(EXEC2) 6 <out/$(d)> out/Par_6_$(d)
	@echo
	$(EXEC1) 7 <out/$(d)> out/Seq_7_$(d)
	@echo
	$(EXEC2) 7 <out/$(d)> out/Par_7_$(d)





	@echo Imagem $(f) 
	@echo
	$(EXEC1) 1 <out/$(f)> out/Seq_1_$(f)
	@echo
	$(EXEC2) 1 <out/$(f)> out/Par_1_$(f)
	@echo
	$(EXEC1) 2 <out/$(f)> out/Seq_2_$(f)
	@echo
	$(EXEC2) 2 <out/$(f)> out/Par_2_$(f)
	@echo
	$(EXEC1) 3 <out/$(f)> out/Seq_3_$(f)
	@echo
	$(EXEC2) 3 <out/$(f)> out/Par_3_$(f)
	@echo
	$(EXEC1) 4 <out/$(f)> out/Seq_4_$(f) 
	@echo
	$(EXEC2) 4 <out/$(f)> out/Par_4_$(f) 
	@echo
	$(EXEC1) 5 <out/$(f)> out/Seq_5_$(f)
	@echo
	$(EXEC2) 5 <out/$(f)> out/Par_5_$(f)
	@echo
	$(EXEC1) 6 <out/$(f)> out/Seq_6_$(f)
	@echo
	$(EXEC2) 6 <out/$(f)> out/Par_6_$(f)
	@echo
	$(EXEC1) 7 <out/$(f)> out/Seq_7_$(f)
	@echo
	$(EXEC2) 7 <out/$(f)> out/Par_7_$(f)



	@echo Imagem $(l) 
	@echo
	$(EXEC1) 1 <out/$(l)> out/Seq_1_$(l)
	@echo
	$(EXEC2) 1 <out/$(l)> out/Par_1_$(l)
	@echo
	$(EXEC1) 2 <out/$(l)> out/Seq_2_$(l)
	@echo
	$(EXEC2) 2 <out/$(l)> out/Par_2_$(l)
	@echo
	$(EXEC1) 3 <out/$(l)> out/Seq_3_$(l)
	@echo
	$(EXEC2) 3 <out/$(l)> out/Par_3_$(l)
	@echo
	$(EXEC1) 4 <out/$(l)> out/Seq_4_$(l)
	@echo
	$(EXEC2) 4 <out/$(l)> out/Par_4_$(l) 
	@echo
	$(EXEC1) 5 <out/$(l)> out/Seq_5_$(l)
	@echo
	$(EXEC2) 5 <out/$(l)> out/Par_5_$(l)
	@echo
	$(EXEC1) 6 <out/$(l)> out/Seq_6_$(l)
	@echo
	$(EXEC2) 6 <out/$(l)> out/Par_6_$(l)
	@echo
	$(EXEC1) 7 <out/$(l)> out/Seq_7_$(l)	
	@echo
	$(EXEC2) 7 <out/$(l)> out/Par_7_$(l)


	@echo Imagem $(lo) 
	@echo
	$(EXEC1) 1 <out/$(lo)> out/Seq_1_$(lo)
	@echo
	$(EXEC2) 1 <out/$(lo)> out/Par_1_$(lo)
	@echo
	$(EXEC1) 2 <out/$(lo)> out/Seq_2_$(lo)
	@echo
	$(EXEC2) 2 <out/$(lo)> out/Par_2_$(lo)
	@echo
	$(EXEC1) 3 <out/$(lo)> out/Seq_3_$(lo)
	@echo
	$(EXEC2) 3 <out/$(lo)> out/Par_3_$(lo)
	@echo
	$(EXEC1) 4 <out/$(lo)> out/Seq_4_$(lo)
	@echo
	$(EXEC2) 4 <out/$(lo)> out/Par_4_$(lo) 
	@echo
	$(EXEC1) 5 <out/$(lo)> out/Seq_5_$(lo)
	@echo
	$(EXEC2) 5 <out/$(lo)> out/Par_5_$(lo)
	@echo
	$(EXEC1) 6 <out/$(lo)> out/Seq_6_$(lo)
	@echo
	$(EXEC2) 6 <out/$(lo)> out/Par_6_$(lo)
	@echo
	$(EXEC1) 7 <out/$(lo)> out/Seq_7_$(lo) 
	@echo
	$(EXEC2) 7 <out/$(lo)> out/Par_7_$(lo)


	@echo Imagem $(t) 
	@echo
	$(EXEC1) 1 <out/$(t)> out/Seq_1_$(t)
	@echo
	$(EXEC2) 1 <out/$(t)> out/Par_1_$(t)
	@echo
	$(EXEC1) 2 <out/$(t)> out/Seq_2_$(t)
	@echo
	$(EXEC2) 2 <out/$(t)> out/Par_2_$(t)
	@echo
	$(EXEC1) 3 <out/$(t)> out/Seq_3_$(t)
	@echo
	$(EXEC2) 3 <out/$(t)> out/Par_3_$(t)
	@echo
	$(EXEC1) 4 <out/$(t)> out/Seq_4_$(t)
	@echo
	$(EXEC2) 4 <out/$(t)> out/Par_4_$(t)  
	@echo
	$(EXEC1) 5 <out/$(t)> out/Seq_5_$(t)
	@echo
	$(EXEC2) 5 <out/$(t)> out/Par_5_$(t)
	@echo
	$(EXEC1) 6 <out/$(t)> out/Seq_6_$(t)
	@echo
	$(EXEC2) 6 <out/$(t)> out/Par_6_$(t)
	@echo
	$(EXEC1) 7 <out/$(t)> out/Seq_7_$(t)
	@echo
	$(EXEC2) 7 <out/$(t)> out/Par_7_$(t)



	@echo Imagem $(u) 
	@echo
	$(EXEC1) 1 <out/$(u)> out/Seq_1_$(u)
	@echo
	$(EXEC2) 1 <out/$(u)> out/Par_1_$(u)
	@echo
	$(EXEC1) 2 <out/$(u)> out/Seq_2_$(u)
	@echo
	$(EXEC2) 2 <out/$(u)> out/Par_2_$(u)
	@echo
	$(EXEC1) 3 <out/$(u)> out/Seq_3_$(u)
	@echo
	$(EXEC2) 3 <out/$(u)> out/Par_3_$(u)
	@echo
	$(EXEC1) 4 <out/$(u)> out/Seq_4_$(u)
	@echo
	$(EXEC2) 4 <out/$(u)> out/Par_4_$(u)  
	@echo
	$(EXEC1) 5 <out/$(u)> out/Seq_5_$(u)
	@echo
	$(EXEC2) 5 <out/$(u)> out/Par_5_$(u)
	@echo
	$(EXEC1) 6 <out/$(u)> out/Seq_6_$(u)
	@echo
	$(EXEC2) 6 <out/$(u)> out/Par_6_$(u)
	@echo
	$(EXEC1) 7 <out/$(u)> out/Seq_7_$(u)	
	@echo
	$(EXEC2) 7 <out/$(u)> out/Par_7_$(u)


clean: 
	rm -rf *.o $(EXEC) 
	rm -rf *.o $(EXEC1) 
	rm -rf *.o $(EXEC2)
