#include "cola.h"
#include <stdlib.h>

typedef struct nodo_cola{
	void* dato;
	struct nodo_cola* prox;
} nodo_cola_t;

struct cola{
	nodo_cola_t* primero;
	nodo_cola_t* ultimo;
};

//Funcion auxiliar para crear nodo
nodo_cola_t* nodo_crear(void* valor){
	nodo_cola_t* nuevo_nodo = malloc(sizeof(nodo_cola_t));
	if(nuevo_nodo==NULL)return NULL;
	nuevo_nodo->dato = valor;
	nuevo_nodo->prox = NULL;
	return nuevo_nodo;
}

//Funciones a completar
cola_t* cola_crear(void){
	cola_t* cola = malloc(sizeof(cola_t));
	if(cola==NULL)return NULL;
	cola->primero = NULL;
	cola->ultimo = NULL;
	return cola;
}

void cola_destruir(cola_t *cola, void (*destruir_dato)(void*)){
	while(!cola_esta_vacia(cola)){
		if(destruir_dato!=NULL){
			destruir_dato(cola_desencolar(cola));
		} else {
			cola_desencolar(cola);
		}
	}
	free(cola);
}

bool cola_esta_vacia(const cola_t *cola){
	if(cola->primero==NULL)return true;
	return false;
}

bool cola_encolar(cola_t *cola, void* valor){
	nodo_cola_t* nuevo_nodo = nodo_crear(valor);
	if(nuevo_nodo==NULL)return false;
	if(cola_esta_vacia(cola)){
		cola->primero = nuevo_nodo;
		cola->ultimo = nuevo_nodo;
	} else {
		cola->ultimo->prox = nuevo_nodo;
		cola->ultimo = nuevo_nodo;
	}
	return true;
}

void* cola_ver_primero(const cola_t *cola){
	if(cola_esta_vacia(cola))return NULL;
	return cola->primero->dato;
}

void* cola_desencolar(cola_t *cola){
	if(cola_esta_vacia(cola))return NULL;
	nodo_cola_t* nodo_destruir = cola->primero;
	void* valor = cola->primero->dato;
	cola->primero = cola->primero->prox;
	free(nodo_destruir);
	return valor;
}
