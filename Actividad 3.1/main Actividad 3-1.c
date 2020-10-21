#include <stdio.h>
#include <stdlib.h>

/*Autora: Regina Damara Orozco Gallardo
Algoritmo: Realizar un programa donde se cree un arreglo de tipo entero. El
programa deberá preguntarle al usuario cuántos valores enteros va a capturar,
esa cantidad será la longitud del arreglo.
Además, se deberá de mostrar un menú con las siguientes opciones:

1. Capturar valores
2. Ordenar valores
3. Imprimir valores originales
4. Imprimir valores ordenados
5. Salir

Cuando el usuario elija la opción de salir, el programa deberá preguntarle al
usuario si desea salir o no antes de salir del programa.
Mientras el usuario no desee salir, deberá de regresar al menú.
*/

int main(int argc, char *argv[]) {
	int longitudArreglo, opcionMenu, opcion = 0, i, j, *valores, *valoresOrdenados, aux, salirDelPrograma;
	printf ("A traves de este programa se creara un arreglo de tipo entero\n");
	printf ("Cuantos valores enteros deseas que tenga el arreglo?\n");
	scanf ("%d", &longitudArreglo);
	valores = (int *)malloc(longitudArreglo * sizeof(int));
	valoresOrdenados = (int *)malloc (longitudArreglo * sizeof(int));
	while (opcion != 5){
		printf ("\nElige una opcion del siguiente menu segun lo que desees hacer\n");
		printf ("1. Capturar valores\n");
		printf ("2. Ordenar valores\n");
		printf ("3. Imprimir valores originales\n");
		printf ("4. Imprimir valores ordenados\n");
		printf ("5. Salir\n");
		scanf ("%d", &opcion);

		switch (opcion){
			case 1:
				printf ("Has escogido la opcion 1. Captura los valores del arreglo:\n");
				for (i = 0; i < longitudArreglo; i++){
					scanf ("%d", &valores[i]);
					valoresOrdenados[i] = valores[i];
				}
				break;
			case 2:
				printf ("Has escogido la opcion 2. Se han ordenado los valores\n");
				for(i = 0; i < longitudArreglo; i++){
					for(j = 0; j < longitudArreglo - 1; j++){
						if (valoresOrdenados[j] > valoresOrdenados[j+1]){
							aux = valoresOrdenados[j+1];
							valoresOrdenados[j+1] = valoresOrdenados[j];
							valoresOrdenados[j] = aux;
						}
					}
				}
				break;
			case 3:
				printf ("Has escogido la opcion 3. A continuacion se muestran los valores originales:\n");
				for (i = 0; i < longitudArreglo; i++){
					printf ("%d\t", valores[i]);
				}
				break;
			case 4:
				printf ("Has escogido la opcion 4. A continuacion se muestran los valores ordenados:\n");
				for (i = 0; i < longitudArreglo; i++){
					printf ("%d\t", valoresOrdenados[i]);
				}
				break;
			case 5:
				printf ("Has escogido la opcion 5. Estas seguro de que quieres salir?\n");
				printf ("1. Si\n");
				printf ("2. No\n");
				scanf ("%d", &salirDelPrograma);
				if (salirDelPrograma == 2){
					opcion = 0;
				}
				break;
			default:
				printf ("Escribe una opcion del 1 al 5 segun sea tu eleccion\n");
			}
	}
	free(valores);
	free (valoresOrdenados);
	system("pause");
	return 0;
}
