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
 * @brief Função para obter a altura de uma imagem.
 * @param img A imagem.
 * @return A altura da imagem.
 */
int ObterAlturaImagem(Imagem *img);

/**
 * @brief Função para obter a largura de uma imagem.
 * @param img A imagem.
 * @return A largura da imagem.
 */
int ObterLarguraImagem(Imagem *img);

/**
 * @brief Função para obter o tipo de uma imagem.
 * @param img A imagem.
 * @return O tipo da imagem.
 */
Tipo ObterTipoImagem(Imagem *img);

/**
 * @brief Função para obter os dados de uma imagem.
 * @param img A imagem.
 * @return Um ponteiro para os dados da imagem.
 */
void *ObterDadosImagem(Imagem *img);

#endif