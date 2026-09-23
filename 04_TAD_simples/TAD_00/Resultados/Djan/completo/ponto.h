/* ponto.h

	TAD Ponto: tipo abstrato de dado para representar um ponto no RxR.
	
	@author Rodrigo Laiola Guimaraes <rlaiola@inf.ufes.br>

*/

#ifndef _PONTO
#define _PONTO

/* TAD: Ponto (x,y) */

/* Tipo exportado */
struct ponto {
	float x;
	float y;
};
typedef struct ponto Ponto;

/* Funcoes exportadas */

/* Funcao cria 
** Retorna um ponto com coordenadas (x,y)
*/
Ponto pto_cria (float x, float y);

/* Funcao acessa x
** Retorna o valor da coordenada x de um ponto
*/
float pto_acessa_x (Ponto p);

/* Funcao acessa y
** Retorna o valor da coordenada x de um ponto
*/
float pto_acessa_y (Ponto p);

/* Funcao atribui x
** Atribui novo valor as coordenada x de um ponto
*/
Ponto pto_atribui_x (Ponto p, float x);

/* Funcao atribui y
** Atribui novo valor as coordenada x de um ponto
*/
Ponto pto_atribui_y (Ponto p, float y);

/* Funcao distancia
** Retorna a distancia entre dois pontos
*/
float pto_distancia (Ponto p1, Ponto p2);

#endif /* _PONTO */
