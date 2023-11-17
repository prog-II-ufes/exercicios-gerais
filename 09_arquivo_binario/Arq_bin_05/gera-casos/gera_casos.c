#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
    Programa para gerar casos de teste no formato abaixo:

    tProduto *LeProduto(FILE *arquivo) {
        int codigo, quantidade;
        float preco;
        char nome[50];
        
        fread(&codigo, sizeof(int), 1, arquivo);
        fread(nome, sizeof(char), 50, arquivo);
        fread(&preco, sizeof(float), 1, arquivo);
        fread(&quantidade, sizeof(int), 1, arquivo);

        return CriaProduto(codigo, nome, preco, quantidade);
    }

    void LeEstabelecimento(tEstabelecimento *estabelecimento) {
        int quantidadeProdutos = 0;
        char nomeArquivo[50];
        scanf("%s", nomeArquivo);

        FILE *arquivo = fopen(nomeArquivo, "rb");
        if (arquivo == NULL)
            exit(printf("Erro ao abrir arquivo %s!\n", nomeArquivo));

        fread(&quantidadeProdutos, sizeof(int), 1, arquivo);
        for (int i = 0; i < quantidadeProdutos; i++) {
            tProduto *produto = LeProduto(arquivo);
            AdicionaProdutoEstabelecimento(estabelecimento, produto);
        }
        fclose(arquivo);
    }

*/

int main() {
    int quantidadeProdutos = 0;

    scanf("%d", &quantidadeProdutos);

    FILE *arquivo = fopen("produtos.bin", "wb");
    if (arquivo == NULL)
        exit(printf("Erro ao abrir arquivo produtos.bin!\n"));

    fwrite(&quantidadeProdutos, sizeof(int), 1, arquivo);

    for (int i = 0; i < quantidadeProdutos; i++) {
        int codigo, quantidade;
        float preco;
        char nome[50];

        scanf("\n%d", &codigo);
        scanf("\n%s", nome);
        scanf("\n%f", &preco);
        scanf("\n%d", &quantidade);

        fwrite(&codigo, sizeof(int), 1, arquivo);
        fwrite(nome, sizeof(char), 50, arquivo);
        fwrite(&preco, sizeof(float), 1, arquivo);
        fwrite(&quantidade, sizeof(int), 1, arquivo);
    }

    fclose(arquivo);

    return 0;
}