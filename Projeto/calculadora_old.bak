// Programa: Conversor Decimal Binario Octal
// Desenvolvedor: Wagner Rose
// data: 16 set 22

#include <iostream>
#define MAX 32
using namespace std;
// definições de variaveis e funções
int opcao;
int escolhe_opcao(void);
void converte_decbin(void);

int main(void)
{
  int opcao;

  // escolha de tipo de conversão
  opcao = escolhe_opcao();
  std::cout << " Opcao escolhida: " << opcao << std::endl;

  switch (opcao) {
    case 1:
      converte_decbin();
      break;
    default:
      std::cout << "Passei default" << std::endl;
  }
}

int escolhe_opcao()
{
  int opcao;
  bool valido = true;

  while(valido)
  {
    cout << endl << "Escolha uma opção:" << endl;
    cout << "  1 - Conversão Decimal Binária" << endl;
    cout << "  2 - Conversão Binária Decimal" << endl;
    cout << "  9 - Sair" << endl;
    cout << "         Opção: ";
    std::cin >> opcao;
    std::cout << std::endl;

    switch(opcao){
      case 1:
        std::cout << "===  Você Selecionaou Conversão Decimal Binaria" << std::endl;
        valido = false;
        break;
      case 2:
        std::cout << "===  Você Selecionou Convesão Binária Decimal" << std::endl;
        std::cout << "===  Infelizmente a função não esta implementada ainda. Aguarde atualização." << std::endl;
        break;
      case 9:
        std::cout << "===  Você selecionau sair do programa." << std::endl;
        std::cout << "===  Até mais." << std::endl;
        valido = false;
        break;
      default:
        std::cout << "===  Você selecionou uma opção inválida." << std::endl;
        std::cout << "=== Tente outra vez." << std::endl;
    }
  } // fim while
  return opcao;
}
void converte_decbin(void){
  bool valido = true;
  int valor;i
  char binario[MAX];
  int le_valor(void);
  void imprime_binario(char);

  valor = le_valor();
  std::cout << "\n Valor informado para conversão: " << valor << std::endl;
  binario = to_bin(valor);
  imprime_binario(binario);
}

int le_valor(void)
{
  bool valido = true;
  int decimal;

  while(valido){
    std::cout << endl << "Informe o Valor decimal a converter: ";
    std::cin >> decimal;
    if (decimal <= 0) {
      std::cout << "\n===   O valor decimal deve ser maior q 0." << std::endl;
      std::cout << "===  Informe novo valor" << std::endl;
    } else {
      valido = false;
    }
  }
  return decimal;
}

char to_bin(int decimal)
{
  char binario[MAX];
  while(decimal > 0){
    binario[i] = decimal % 2;
    decimal /= 2;
    i++;
  }
  return binario;
}
void imprime_binario(char binario[MAX]){
  for (i = 0; i < count; ++i) {
    
  }
}
