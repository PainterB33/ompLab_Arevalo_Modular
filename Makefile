GCC = gcc
FLAGS = -fopenmp

PROGRAMA = ompLab_Arevalo

$(PROGRAMA):
	$(GCC) func_lab_omp.c main.c -o $@ $(FLAGS)
clear:
	$(RM) $(PROGRAMA)
