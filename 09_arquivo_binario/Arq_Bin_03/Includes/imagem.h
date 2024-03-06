#ifndef _IMAGEM_H
#define _IMAGEM_H

typedef enum {
    FLOAT = 0, 
    INT = 1    
} Tipo;

/**
 * @brief Estrutura para representar uma imagem.
 */
typedef struct tImagem Imagem;

/**
 * @brief Função para ler uma imagem de um arquivo binário e aloca-la na memória.
 * A função também armazena o número de bytes lidos na estrutura Imagem.
 * @param path O caminho para o arquivo de imagem.
 * @return Um ponteiro para a imagem lida. Se houver erro (de leitura ou alocação de memória), a função imprime uma mensagem de erro e termina o programa.
 */
Imagem *LerImagem(const char *caminho);

/**
 * @brief Função para destruir uma imagem.
 * @param img A imagem a ser destruída.
 */
void DestruirImagem(Imagem *img);

/**
 * @brief Função para obter o número de bytes lidos de uma imagem.
 * @param img A imagem.
 * @return O número de bytes lidos.
 */
int ObterNumeroBytesLidos(Imagem *img);

/**
 * @brief Função para imprimir uma imagem.
 * @param img A imagem.
 */
void ImprimirImagem(Imagem *img);

#endif