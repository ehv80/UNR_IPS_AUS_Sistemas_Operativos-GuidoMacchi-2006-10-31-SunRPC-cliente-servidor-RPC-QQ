/* Archivo: qq_client.c 
 * NUESTRO PROPIO CLIENTE RPC 
 * PARA EL SERVIDOR RPC: qq_server.c */

/* ARCHIVOS DE CABECERA */
#include<stdio.h>
#include<rpc/rpc.h>
#include<rpc/xdr.h>

/* DEFINICIONES */
#define	NPROG	0x30000003
#define	NVERS	11
#define	NFUNC	1

/* FUNCION PRINCIPAL MAIN */
int main()
{
	int i;
	double d;
	for(i=0 ; i<10 ; i++){
		callrpc(
			"localhost",
			NPROG,
			NVERS,
			NFUNC,
			xdr_int,	/* CANONIZA A UN DATO DE TIPO int */
			&i,
			xdr_double,	/* CANONIZA A UN DATO DE TIPO double */
			&d
			);
		printf("Para %d viene %f \n", i , d );
	}
	return 0;
}
/* Archivo: qq_client.c */ 
