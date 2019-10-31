#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <locale.h>

#define MAX1 10000
#define MAX2 15000
#define MAX3 20000
#define MAX4 25000


#define MAX_EXEC 10

void bubble_sort (int vetor[], int n) {
    int k, j, aux;

    for (k = 1; k < n; k++) {

        for (j = 0; j < n - k - 1; j++) {

            if (vetor[j] > vetor[j + 1]) {
                aux          = vetor[j];
                vetor[j]     = vetor[j + 1];
                vetor[j + 1] = aux;
            }
        }
    }
}

void bubble_sort_upgrade (int vetor[], int n) {
    int i, j, aux, troca=1;
   for (j = 0; (j < n - 1) && (troca == 1); j++) {
            troca = 0;
            for (i = 0; i < n - j - 1; i++) {
                if (vetor[i] > vetor[i + 1]) {
                    troca = 1;
                    aux = vetor[i];
                    vetor[i] = vetor[i + 1];
                    vetor[i + 1] = aux;
                }
            }
        }
}

void quick_inicio(int vetor[], int inicio, int fim){
   
   int pivo, aux, i, j, meio;
   
   i = inicio;
   j = fim;
   pivo = vetor[inicio];
   
   do{
      while (vetor[i] < pivo) i = i + 1;
      while (vetor[j] > pivo) j = j - 1;
      
      if(i <= j){
         aux = vetor[i];
         vetor[i] = vetor[j];
         vetor[j] = aux;
         i = i + 1;
         j = j - 1;
      }
   }while(j > i);
   
   if(inicio < j) quick_inicio(vetor, inicio, j);
   if(i < fim) quick_inicio(vetor, i, fim);   

}

void quick_meio(int vetor[], int inicio, int fim){
   
   int pivo, aux, i, j, meio;
   
   i = inicio;
   j = fim;
   
   meio = (int) ((i + j) / 2);
   pivo = vetor[meio];
   
   do{
      while (vetor[i] < pivo) i = i + 1;
      while (vetor[j] > pivo) j = j - 1;
      
      if(i <= j){
         aux = vetor[i];
         vetor[i] = vetor[j];
         vetor[j] = aux;
         i = i + 1;
         j = j - 1;
      }
   }while(j > i);
   
   if(inicio < j) quick_meio(vetor, inicio, j);
   if(i < fim) quick_meio(vetor, i, fim);   

}

void insertion_sort(int *pVetor, int n)
{
    int vAux;
    int vTemp;
    int vTroca;

    for (vAux=1; vAux < n; vAux++) // vAux começa na posição 1 do vetor e vai até a ultima posição;
    {
        vTemp = vAux; // vTemp recebe a posição que está passando no "for";

        while (pVetor[vTemp] < pVetor[vTemp-1]) // Enquanto o valor que está passando na posição "vTemp" for menor que a posição "vTemp" menos 1, ocorre a troca;
        { // Ocorre a troca;
            vTroca          = pVetor[vTemp];
            pVetor[vTemp]   = pVetor[vTemp-1];
            pVetor[vTemp-1] = vTroca;
            vTemp--; // vTemp decrementa 1;

            if (vTemp == 0) // Quando "vTemp" chegar na posição 0, primeira posição do vetor, o laço while para;
                break;
        }

    }
}

void shell_sort(int *a, int size)
{
 int i , j , value;
 int gap = 1;
  
 do {
  gap = 3*gap+1;
 } while(gap < size);
  
 do {
  gap /= 3;
  for(i = gap; i < size; i++) {
   value = a[i];
   j = i - gap;
    
   while (j >= 0 && value < a[j]) {
    a[j + gap] = a[j];
    j -= gap;
   }
   a[j + gap] = value;
  }
 }while(gap > 1);
}

static void intercala1 (int p, int q, int r, int v[]) 
{
   int *w;                                 //  1
   w = malloc ((r-p) * sizeof (int));     //  2
   int i = p, j = q;                       //  3
   int k = 0;                              //  4

   while (i < q && j < r) {                //  5
      if (v[i] <= v[j])  w[k++] = v[i++];  //  6
      else  w[k++] = v[j++];               //  7
   }                                       //  8
   while (i < q)  w[k++] = v[i++];         //  9
   while (j < r)  w[k++] = v[j++];         // 10
   for (i = p; i < r; ++i)  v[i] = w[i-p]; // 11
   free (w);                               // 12
}

void merge_sort (int v[], int ini, int final)
{
   if (ini < final-1) {                 // 1
      int q = (ini + final)/2;          // 2
      merge_sort (v, ini, q);        // 3
      merge_sort (v, q, final);        // 4
      intercala1 (ini, q, final, v);     // 5
   }
}

int criarHeapRecursao(int v[], int inicio, int aux, int filho, int final) {
    if (filho > final) return inicio;

    // Pai tem 2 filhos? Se sim, qual é o maior?
    if (filho < final && filho + 1 < final && v[filho] < v[filho + 1]) {
        filho++;
    }

    // Troca o filho com o pai se o filho for maior.
    if (aux < v[filho]) {
        v[inicio] = v[filho];
        inicio = filho;
        filho = 2 * inicio + 1;
    } else {
        filho = final + 1;
    }
    return criarHeapRecursao(v, inicio, aux, filho, final);
}

void criarHeap(int v[], int inicio, int final) {
    int aux = v[inicio];
    int filho = inicio * 2 + 1;
    inicio = criarHeapRecursao(v, inicio, aux, filho, final);
    v[inicio] = aux; // Pai troca com filho mais profundo mais a direita.
}

void heapSort1(int v[], int i, int tam) {
    if (i < 0) return;
    criarHeap(v, i, tam - 1);
    heapSort1(v, i - 1, tam);
}

void heapSort2(int v[], int i, int tam) {
    if (i <= 0) return;
    int aux = v[0];
    v[0] = v[i];
    v[i] = aux;
    criarHeap(v, 0, i - 1); // Cria o heap sem o maior elemento anterior.
    heapSort2(v, i - 1, tam);
}

void heap_sort(int v[], int tam) {
    heapSort1(v, (tam - 1) / 2, tam);
    heapSort2(v, tam - 1, tam);
}

void selection_sort (int vetor[],int max) {
  int i, j, min, aux;
  
  for (i = 0; i < (max - 1); i++) {
    /* O minimo é o primeiro número não ordenado ainda */
    min = i;
    for (j = i+1; j < max; j++) {
      /* Caso tenha algum numero menor ele faz a troca do minimo*/
      if (vetor[j] < vetor[min]) {
   		min = j;
      }
    }
    /* Se o minimo for diferente do primeiro numero não ordenado ele faz a troca para ordena-los*/
    if (i != min) {
      aux = vetor[i];
      vetor[i] = vetor[min];
      vetor[min] = aux;
    }
  }
}

void exec_bubble_sort (int vetor[], int n) {
	clock_t tini,tfinal;
	float tempo;
    int i=0;
    tini = clock();
    for (i; i<MAX_EXEC; i++) {
        bubble_sort(vetor, n);
    }
    tfinal = clock();
    tempo = (tfinal - tini) * 1000 / CLOCKS_PER_SEC;
    printf("\nO tempo gasto com bubble sort de %d entradas é de: %0.0fms", n,tempo);
}

void exec_bubble_sort_upgrade (int vetor[], int n) {
	clock_t tini,tfinal;
	float tempo;
    int i=0;
    tini = clock();
    for (i; i<MAX_EXEC; i++) {
        bubble_sort_upgrade(vetor, n);
    }
    tfinal = clock();
    tempo = (tfinal - tini) * 1000 / CLOCKS_PER_SEC;
    printf("\nO tempo gasto com bubble sort melhorado de %d entradas é de: %0.0fms", n,tempo);
}

void exec_quick_meio (int vetor[], int ini, int fim) {
	clock_t tini,tfinal;
	float tempo;
    int i=0;
    tini = clock();
    for (i; i<MAX_EXEC; i++) {
        quick_meio(vetor, ini, fim);
    }
    tfinal = clock();
    tempo = (tfinal - tini) * 1000 / CLOCKS_PER_SEC;
    printf("\nO tempo gasto com quick sort (pivô meio) de %d entradas é de: %0.0fms", fim,tempo);
}

void exec_quick_inicio (int vetor[], int ini, int fim) {
	clock_t tini,tfinal;
	float tempo;
    int i=0;
    tini = clock();
    for (i; i<MAX_EXEC; i++) {
        quick_inicio(vetor, ini, fim);
    }
    tfinal = clock();
    tempo = (tfinal - tini) * 1000 / CLOCKS_PER_SEC;
    printf("\nO tempo gasto com quick sort (pivô início) de %d entradas é de: %0.0fms", fim,tempo);
}

void exec_insertion_sort (int vetor[], int n) {
	clock_t tini,tfinal;
	float tempo;
    int i=0;
    tini = clock();
    for (i; i<MAX_EXEC; i++) {
        insertion_sort(vetor, n);
    }
    tfinal = clock();
    tempo = (tfinal - tini) * 1000 / CLOCKS_PER_SEC;
    printf("\nO tempo gasto com insertion sort de %d entradas é de: %0.0fms", n,tempo);;
}

void exec_shell_sort (int vetor[], int n) {
	clock_t tini,tfinal;
	float tempo;
    int i=0;
    tini = clock();
    for (i = 0; i<MAX_EXEC; i++) {
        shell_sort(vetor, n);
    }
    tfinal = clock();
    tempo = (tfinal - tini) * 1000 / CLOCKS_PER_SEC;
    printf("\nO tempo gasto com shell sort de %d entradas é de: %0.0fms", n,tempo);
}

void exec_heap_sort (int vetor[], int n) {
	clock_t tini,tfinal;
	float tempo;
    int i=0,j=0,aux;
    tini = clock();
    for (i; i<MAX_EXEC; i++) {
        heap_sort(vetor, n);
    }
    tfinal = clock();
    tempo = (tfinal - tini) * 1000 / CLOCKS_PER_SEC;
    printf("\nO tempo gasto com heap sort de %d entradas é de: %0.0fms", n,tempo);
}

void exec_merge_sort (int vetor[], int ini, int fim) {
	clock_t tini,tfinal;
	float tempo;
    int i=0;
    tini = clock();
    for (i; i<MAX_EXEC; i++) {
        merge_sort(vetor, ini, fim);
    }
    tfinal = clock();
    tempo = (tfinal - tini) * 1000 / CLOCKS_PER_SEC;
    printf("\nO tempo gasto com merge sort de %d entradas é de: %0.0fms", fim,tempo);
}

void exec_selection_sort (int vetor[], int n) {
	clock_t tini,tfinal;
	float tempo;
    int i=0;
    tini = clock();
    for (i; i<MAX_EXEC; i++) {
        selection_sort(vetor, n);
    }
    tfinal = clock();
    tempo = (tfinal - tini) * 1000 / CLOCKS_PER_SEC;
    printf("\nO tempo gasto com selection sort de %d entradas é de: %0.0fms", n,tempo);
}

int main (void) {

    setlocale(LC_ALL, "Portuguese");

    int n = 0,i = 0, j=0;
    int vector1[MAX1], vector2[MAX2], vector3[MAX3], vector4[MAX4];
    
    //RANDOMICO
    /*
	for (i = 0; i<MAX1; i++) {
    	vector1[i] = rand()%MAX1;
	}
	*/
	
	//ORDENADO
	/*
	for (i = 0; i<MAX1; i++) {
		vector1[i] = i;
	}
	*/
	
	//DESORDENADO
	
	j = MAX1;
	for (i = 0; i<MAX1; i++) {
		vector1[i] = j;
		j--;
	}
	
	
	exec_insertion_sort(vector1, MAX1);
	exec_shell_sort(vector1, MAX1);
	exec_merge_sort(vector1, 0, MAX1);
	exec_selection_sort(vector1, MAX1);
	exec_heap_sort(vector1, MAX1);
    exec_bubble_sort (vector1, MAX1);
    exec_bubble_sort_upgrade (vector1, MAX1);
    exec_quick_inicio(vector1, 0, MAX1);
    exec_quick_meio(vector1, 0, MAX1);
    
    //RANDOMICO
    /*
    for (i = 0; i<MAX2; i++) {
    	vector2[i] = rand()%MAX2;
	}
	*/
	
	//ORDENADO
	/*
	for (i = 0; i<MAX2; i++) {
		vector2[i] = i;
	}
	*/
	//DESORDENADO
	
	j = MAX2;
	for (i = 0; i<MAX2; i++) {
		vector2[i] = j;
		j--;
	}
	
	printf("\n\n");
	
	
	exec_insertion_sort(vector2, MAX2);
	exec_shell_sort(vector2, MAX2);
	exec_merge_sort(vector2, 0, MAX2);
	exec_selection_sort(vector2, MAX2);
	exec_heap_sort(vector2, MAX2);
	exec_bubble_sort (vector2, MAX2);
	exec_bubble_sort_upgrade (vector2, MAX2);
	exec_quick_inicio(vector2, 0, MAX2);
	exec_quick_meio(vector2, 0, MAX2);
	
	//RANDOMICO
	/*
	for (i = 0; i<MAX3; i++) {
    	vector3[i] = rand()%MAX3;
	}
	*/
	
	//ORDENADO
	/*
	for (i = 0; i<MAX3; i++) {
		vector3[i] = i;
	}
	*/
	
	//DESORDENADO
	
	j = MAX3;
	for (i = 0; i<MAX3; i++) {
		vector3[i] = j;
		j--;
	}
	
	printf("\n\n");
	
	
	exec_insertion_sort(vector3, MAX3);
	exec_shell_sort(vector3, MAX3);
	exec_merge_sort(vector3, 0, MAX3);
	exec_selection_sort(vector3, MAX3);
	exec_heap_sort(vector3, MAX3);
	exec_bubble_sort (vector3, MAX3);
	exec_bubble_sort_upgrade (vector3, MAX3);
	exec_quick_inicio(vector3, 0, MAX3);
	exec_quick_meio(vector3, 0, MAX3);
	
	//RANDOMICO
	/*
	for (i = 0; i<MAX4; i++) {
    	vector4[i] = rand()%MAX4;
	}
	*/
	
	//ORDENADO
	/*
	for (i = 0; i<MAX4; i++) {
		vector4[i] = i;
	}
	*/
	//DESORDENADO
	
	j = MAX4;
	for (i = 0; i<MAX4; i++) {
		vector4[i] = j;
		j--;
	}
	
	printf("\n\n");
	
	
	exec_insertion_sort(vector4,MAX4);
	exec_shell_sort(vector4,MAX4);
	exec_merge_sort(vector4, 0,MAX4);
	exec_selection_sort(vector4,MAX4);
	exec_heap_sort(vector4,MAX4);
	exec_bubble_sort (vector4,MAX4);
	exec_bubble_sort_upgrade (vector4,MAX4);
	exec_quick_inicio(vector4, 0,MAX4);
	exec_quick_meio(vector4, 0,MAX4);
    return 0;
}
