all: schema_Explicite Schema_Implicite

schema_Explicite: Schema_Explicite.c
	gcc -g -Ofast -funroll-loops -finline-functions -ftree-vectorize $< -o $@ -lm -lSDL2
	
Schema_Implicite: Schema_Implicite.c
	gcc -g -Ofast -funroll-loops -finline-functions -ftree-vectorize $< -o $@ -lm -lSDL2
	
clean:
	rm -Rf *~ schema_Explicite Schema_Implicite
