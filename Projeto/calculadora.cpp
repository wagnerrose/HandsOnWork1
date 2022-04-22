// Programa: Conversor Decimal Binario Octal
// Autor: Wagner Rose
// data: 16 abr 22

#include <iostream>
#include <string>
#include <sstream>
#include <limits> // limpeza do buffer

#define MAX 32

// using namespace std;
using std::string;
using std::numeric_limits;

// definições de variaveis e funções
void converte_decbin(void);


int main(void)
{
  int opcao;
  int escolhe_opcao(void);
  bool valida = true;

  // loop de escolha do tipo de conversão
  while(valida){
    opcao = escolhe_opcao();
    std::cout << " Opção escolhida: " << opcao << std::endl;
    switch (opcao) {
      case 1:
        converte_decbin();
        break;
      default:
        std::cout << "===  Você selecionou sair do programa." << std::endl;
        std::cout << "===  Até mais." << std::endl;
        valida = false;
    }
  }
}

int escolhe_opcao()
{
  int opcao;
  bool valido = true;
  bool valido2;

  while(valido)
  {
    valido2 = true;
    while(valido2){
      std::cout << std::endl << "Escolha uma opção:" << std::endl;
      std::cout << "  1 - Conversão Decimal Binária" << std::endl;
      std::cout << "  2 - Conversão Binária Decimal" << std::endl;
      std::cout << "  9 - Sair" << std::endl;
      std::cout << "         Opção: ";

      // testa se foi digitado um valor válido(número_)
      if (std::cin >> opcao) {
        valido2 = false;
      } else {
       std::cout << "== Você deve escolher um número válido!" << std::endl;
       std::cin.clear(); // limpa as flags de erro do cin
       std::cin.ignore(numeric_limits<std::streamsize>::max(), '\n');  // ignora tudo até o \n - limpa o buffer
      }
      std::cout << std::endl;
    }

    switch(opcao){
      case 1:
        std::cout << "===  Você Selecionou Conversão Decimal Binária" << std::endl;
        valido = false;
        break;
      case 2:
        std::cout << "===  Você Selecionou Convesão Binária Decimal" << std::endl;
        std::cout << "===  Infelizmente a opção não foi implementada ainda. Aguarde atualização." << std::endl;
        break;
      case 9:
        std::cout << "===  Você selecionou sair do programa." << std::endl;
        valido = false;
        break;
      default:
        std::cout << "===  Você selecionou uma opção inválida." << std::endl;
        std::cout << "===  Tente outra vez." << std::endl;
    }
  } // fim while
  return opcao;
}
void converte_decbin(void){
  // declaracao de variaveis
  bool valido = true;
  int valor;
  string binario;

  int le_valor_dec(void);
  string to_bin(int valor);

  valor = le_valor_dec();
  std::cout << "\nValor decimal: " << valor << std::endl;
  binario = to_bin(valor);
  std::cout << "Valor binário: ";
  std::cout << binario << std::endl;
}

int le_valor_dec(void)
{
  bool valido = true;
  int valor;

  while(valido){
    std::cout << std::endl << "Informe o Valor decimal a converter: ";
    std::cin >> valor;
    if (valor <= 0) {
      std::cout << "\n===   O valor decimal deve ser maior q 0." << std::endl;
      std::cout << "===  Informe novo valor" << std::endl;
    } else {
      valido = false;
    }
  }
  return valor;
}

string to_bin(int valor)
{
  string binario;

  while(valor > 0){
    binario = (valor % 2 == 0 ? "0" : "1") + binario;
    valor /= 2;
  }
  return binario;
}
