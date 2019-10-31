#include <stdio.h>
#include <stdlib.h>

typedef struct texto_matrix{
	int grafo;
	int vertice;
	int peso;
	int tipo;
}tm;

typedef struct matriz {
	int m[50][50];
	int tamanho;
}ma;

/*
void busca_largura(int matrix[][]) {

}
*/
int main(int argc, char const *argv[])
{
	FILE *f1, *f2;
	int i = 0;
	int j = 0;
	char flag;

	struct texto_matrix node;
	struct matriz matriz_node;

	if((f1 = fopen("arq_digrafo1.txt", "r+")) != NULL){
		fscanf(f1,"%c",&flag);
		printf("Flag: %c\n",flag);
		// if(flag == '#'){}
		// else {
		fscanf(f1,"%d", &node.tipo);
		printf("tipo: %d\n", node.tipo);
		fscanf(f1, "%d", &matriz_node.tamanho);
		printf("tamanho: %d\n", matriz_node.tamanho);

		for(i = 0; i < matriz_node.tamanho; i++) {
			for (j = 0; j < matriz_node.tamanho; j++) {
				matriz_node.m[i][j] = 0;
				printf("L:%d C:%d V:%d\n",i,j,matriz_node.m[i][j]);
			}
		}

		fscanf(f1,"%d %d %d\n",&node.grafo, &node.vertice, &node.peso);
		matriz_node.m[node.grafo][node.vertice] = 1;
		printf("Grafo:%d vertice:%d valor:%d\n",node.grafo,node.vertice);

		fscanf(f1,"%d %d %d\n",&node.grafo, &node.vertice, &node.peso);
		matriz_node.m[node.grafo][node.vertice] = 1;
		printf("Grafo:%d vertice:%d valor:%d\n",node.grafo,node.vertice);

		fscanf(f1,"%d %d %d\n",&node.grafo, &node.vertice, &node.peso);
		matriz_node.m[node.grafo][node.vertice] = 1;
		printf("Grafo:%d vertice:%d valor:%d\n",node.grafo,node.vertice);

		fscanf(f1,"%d %d %d\n",&node.grafo, &node.vertice, &node.peso);
		matriz_node.m[node.grafo][node.vertice] = 1;
		printf("Grafo:%d vertice:%d valor:%d\n",node.grafo,node.vertice);

		fscanf(f1,"%d %d %d\n",&node.grafo, &node.vertice, &node.peso);
		matriz_node.m[node.grafo][node.vertice] = 1;
		printf("Grafo:%d vertice:%d valor:%d\n",node.grafo,node.vertice);

		fscanf(f1,"%d %d %d\n",&node.grafo, &node.vertice, &node.peso);
		matriz_node.m[node.grafo][node.vertice] = 1;
		printf("Grafo:%d vertice:%d valor:%d\n",node.grafo,node.vertice);
	
		// }

		for(i = 0; i < matriz_node.tamanho; i++) {
			for (j = 0; j < matriz_node.tamanho; j++) {
				printf("L:%d C:%d V:%d\n",i,j,matriz_node.m[i][j]);
			}
		}
	} else {
		printf("\n		-> **error, could not open text file...\n\n");
	}
	
	printf("\nAperte enter para sair do programa . . .\n");
	
	fflush(stdin);
	getch();
	fflush(stdin);

	return 0;
}
