#include <stdio.h>

// Variaveis
typedef struct {
    char numero[20];
    char nome[50];
    char banco[50];
    double saldo;
    int limite;
} CartaoCredito;

// Construtor
CartaoCredito criarCartaoCredito(const char *numero, const char *nome, const char *banco, double saldo, int limite) {
    CartaoCredito cartao;

    snprintf(cartao.numero, sizeof(cartao.numero), "%s", numero);
    snprintf(cartao.nome, sizeof(cartao.nome), "%s", nome);
    snprintf(cartao.banco, sizeof(cartao.banco), "%s", banco);
    cartao.saldo = saldo;
    cartao.limite = limite;

    return cartao;
}

// Metodo de acao: debita
int debitar(CartaoCredito *cartao, double valor) {
    if (valor + cartao->saldo > cartao->limite) {
        return 0;
    }

    cartao->saldo += valor;
    return 1;
}

// Metodo de acao: faz pagamento com juros de 2%
void fazerPagamento(CartaoCredito *cartao, double pagamento) {
    cartao->saldo = cartao->saldo * 1.02;
    cartao->saldo -= pagamento;
}

// Imprime informacoes sobre o cartao
void imprimirCartao(const CartaoCredito *cartao) {
    printf("Numero = %s\n", cartao->numero);
    printf("Nome = %s\n", cartao->nome);
    printf("Banco = %s\n", cartao->banco);
    printf("Saldo = %.2f\n", cartao->saldo);
    printf("Limite = %d\n\n", cartao->limite);
}

int main() {
    CartaoCredito cartao1 = criarCartaoCredito("1234 5678", "Vinicius", "Banco Master", 1000, 2000);
    printf("Cartao criado:\n");
    imprimirCartao(&cartao1);

    printf("Debitando 200\n");
    debitar(&cartao1, 200);
    imprimirCartao(&cartao1);

    printf("Fazendo pagamento de 300 com juros\n");
    fazerPagamento(&cartao1, 300);
    imprimirCartao(&cartao1);

    return 0;
}