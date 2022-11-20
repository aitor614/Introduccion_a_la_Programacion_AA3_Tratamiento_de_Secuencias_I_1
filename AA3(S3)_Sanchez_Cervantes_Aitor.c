
#define _CRT_SECURE_NO_WARNINGS
//Linkamos las librerías
#include <stdio.h>
#include <stdbool.h>

// Declaracion de funciones
void mostrarArray(int arreglo[10], int numerosIntroducidos);
void mostrarMedia(int arreglo[10], float* media, int* sumaArray);
void tolerancia(int arreglo[10], float* tol, float* tolMin, float* tolMax, float* media);
void segundoArray(float* tol, float* tolMax, float* tolMin, int arreglo2[10], int arreglo[10], float* media);


int main(void) {

	//Declaración de Variables
	int   arreglo2[10], tolMax, tolMin, tol, arreglo[10], media, numerosIntroducidos, sumaArray;


	//Inicializamos variables
	numerosIntroducidos = 0;
	sumaArray = 0;
	media = 0;
	tol = 0;
	tolMin = 0;
	tolMax = 0;


	for (int i = 0; i < 10; i++) {


		//Pedimos al usuario que introduzca los números que contendrá el array
		printf("Introduce el numero entero %d: ", i + 1);

		scanf("%d", &arreglo[i]);

		printf("\n");

		// Si el usuario introduce el numero -1 finalizara el array
		if (arreglo[i] == -1) {
			break;
		}
		numerosIntroducidos = i + 1;
		sumaArray = sumaArray + arreglo[i]; // Sumo los numeros del Array
		numerosIntroducidos = i + 1; //Contador para saber cuantos numeros hay en el Array
	}

	(float)media = (float)sumaArray / (float)numerosIntroducidos; //obtengo la media de los números del Array


	//Llamada de las funciones
	mostrarArray(arreglo, numerosIntroducidos);
	mostrarMedia(arreglo, &media, sumaArray);
	tolerancia(arreglo, &tol, &tolMin, &media, &tolMax);
	segundoArray(&tol, &tolMax, &tolMin, arreglo2, arreglo, &media);



	printf("\n\n");

	system("pause");

	return 0;

}
//FUNCIONES


// Creamos la funcion para mostrar los numeros
void mostrarArray(int arreglo[10], int numerosIntroducidos) {

	printf("Se han introducido %d numeros.\n\n", numerosIntroducidos);

	printf("****************FUNCION QUE MUESTRA LOS NUMEROS INTRODUCIDOS:****************\n\n");

	printf("Los numeros introducidos son:\n\n");

	for (int i = 0; i < 10; i++) {
		if (arreglo[i] == -1) {
			break;
		}
		printf("Numero %d: %d\n\n", i + 1, arreglo[i]);

	}

}


// Creamos la función para determinar que numeros están por encima de la media
void mostrarMedia(int arreglo[10], float* media, int* sumaArray) {

	printf("La suma de los numeros introducidos es %d \n\n", sumaArray);

	printf("Y la media de estos es es %6f \n\n", *media);

	printf("****************FUNCION QUE MUESTRA LOS NUMEROS INTRODUCIDOS QUE ESTAN POR ENCIMA DE LA MEDIA:****************\n\n");

	// Si el usuario introduce el numero -1 finalizara el array
	for (int i = 0; i < 10; i++) {
		if (arreglo[i] == -1) {
			break;
		}

		if (arreglo[i] > *media) {
			printf("Numero en posicion %d: %d por encima de la media\n\n", i + 1, arreglo[i]);
		}
	}
}


//Funcion tolerancia a aplicar
void tolerancia(int arreglo[10], float* tol, float* tolMin, float* media, float* tolMax) {

	printf("Indica cual es la tolerancia respecto a la media?\n");

	scanf("%f", tol);

	printf("\n");
}

//Función segundo Array
void segundoArray(float* tol, float* tolMax, float* tolMin, int arreglo2[10], int arreglo[10], float* media) {

	printf("****************FUNCION QUE A PARTIR DE LA TOLERANCIA INTRODUCE LO NECESARIO EN UN SEGUNDO ARRAY:****************\n\n");

	if (*tol) {
		*tolMin = *media - (*media * *tol);
		*tolMax = *media + (*media * *tol);
		printf("****************Introduce valores comprendidos entre %6f y %6f****************\n\n", *tolMin, *tolMax);
	}

	printf("****************FUNCION QUE MUESTRA LOS NMEROS INTRODUCIDOS EN AMBOS ARRAYS:****************\n\n");

	// Si el usuario introduce el numero -1 finalizara el array
	for (int i = 0; i < 10; i++) {
		if (arreglo[i] == -1) {
			break;

		}

		if ((arreglo[i] >= *tolMin) && (arreglo[i] <= *tolMax)) {
			arreglo2[i] = arreglo[i];
			printf("Numero %d: %d Segundo array %d: %d\n\n", i + 1, arreglo[i], i + 1, arreglo2[i]);
		}
		else {
			arreglo2[i] = 0;
			printf("Numero %d: %d Segundo array %d: %d\n\n", i + 1, arreglo[i], i + 1, arreglo2[i]);
		}

	}

}
