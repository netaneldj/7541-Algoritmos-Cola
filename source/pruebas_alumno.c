#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include "cola.h"
#include "testing.h"
#define ELEMENTOS 5

/* ******************************************************************
 *                   PRUEBAS UNITARIAS ALUMNO
 * *****************************************************************/
 
//Funcion destruir dato

void destruir_dato(void* valor){
	free(valor);
}

//Funciones de prueba

void prueba_encolar_desencolar_primero_vacia(cola_t* mi_cola,int valores[]){
	printf("Comienzan las pruebas de direcciones de memoria simples\n");
	for(int i=0;i<ELEMENTOS;i++){
		printf("Prueba nro: %d\n",i+1);
		print_test("La cola esta vacia",cola_esta_vacia(mi_cola));
		cola_encolar(mi_cola,&valores[i]);
		print_test("La cola no esta vacia",cola_esta_vacia(mi_cola)==false);
		print_test("Coincide encolado y direccion encolada ",cola_ver_primero(mi_cola)==&valores[i]);
		cola_desencolar(mi_cola);
		print_test("La cola esta vacia",cola_esta_vacia(mi_cola));
		printf("\n");
	}
	printf("\n");
}

void prueba_memoria_dinamica(cola_t* mi_cola, int valores[]){
	printf("Comienzan las pruebas con memoria dinamica\n");
	for(int i=0;i<ELEMENTOS;i++){
		printf("Prueba nro: %d\n",i+1);
		int* punt1 = malloc(sizeof(int));
		*punt1 = valores[i];
		print_test("La cola esta vacia",cola_esta_vacia(mi_cola));
		cola_encolar(mi_cola,punt1);
		print_test("La cola no esta vacia",cola_esta_vacia(mi_cola)==false);
		print_test("Coincide encolado y direccion encolada ",cola_ver_primero(mi_cola)==punt1);
		cola_desencolar(mi_cola);
		print_test("La cola esta vacia",cola_esta_vacia(mi_cola));
		printf("\n");
		free(punt1);
	}
	printf("\n");
}

void prueba_encolar_puntero(cola_t* mi_cola){
	printf("Comienza la prueba de encolar punteros a cadenas\n");
	char cadena[]="cadena a encolar";
	size_t len = strlen(cadena);
	char* punt2 = malloc((len-1)*sizeof(char));
	*punt2=*cadena;
	print_test("La cola esta vacia",cola_esta_vacia(mi_cola));
	cola_encolar(mi_cola,punt2);
	print_test("La cola no esta vacia",cola_esta_vacia(mi_cola)==false);
	print_test("Coincide encolado y direccion encolada ",cola_ver_primero(mi_cola)==punt2);
	cola_desencolar(mi_cola);
	print_test("La cola esta vacia",cola_esta_vacia(mi_cola));
	printf("\n");
	free(punt2);
}
void pruebas_cola_alumno(void){
	//Creo un array para despues apilar las direcciones de memoria en la cola
    int valores[ELEMENTOS];
    for(int i=0;i<ELEMENTOS;i++){
		valores[i]=i;
	}
	//Creo dos colas
	printf("Creo las colas...\n");
    cola_t* cola1 = cola_crear();
    cola_t* cola2 = cola_crear();
    cola_t* cola3 = cola_crear();
   //Realizo las pruebas de encolar, esta vacia, ver primero y desencolar
   prueba_encolar_desencolar_primero_vacia(cola1,valores);
   //Realizo las pruebas con memoria dinamica
   prueba_memoria_dinamica(cola2,valores);
   //Realizo la prueba con punteros a cadenas memoria dinamcia
   prueba_encolar_puntero(cola3);
   //Destruyo las colas
   printf("Destruyo las colas...\n");
   printf("\n");
   cola_destruir(cola1,destruir_dato);
   cola_destruir(cola2,destruir_dato);
   cola_destruir(cola3,destruir_dato);
   printf("Las pruebas finalizaron con exito ;)\n11");
}
