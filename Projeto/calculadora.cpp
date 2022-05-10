// Programa: Conversor Decimal Binario Octal
// Autor: Wagner Rose
// data: 16 abr 22
// Atualizado: 04 Mai 22

#include <iostream>
#include <string>
#include <regex>  // uso de expressoes regulares
#include <sstream>
#include <limits> // limpeza do buffer
#include <math.h>

#define MAX 32

// using namespace std;
using std::string;
using std::numeric_limits;

// definições de variaveis e funções
void converte_decbin(void);
void converte_bindec(void);

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
      case 2:
        converte_bindec();
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
        std::cout << "===  Você Selecionou Conversão Binária Decimal" << std::endl;
        valido = false;
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
  std::cout << "\n\tValor decimal: " << valor << std::endl;
  binario = to_bin(valor);
  std::cout << "\tValor binário: ";
  std::cout << binario << std::endl;
}

void converte_bindec(void){

  string le_valor_bin(void);
  int to_dec(string);

  string binario = le_valor_bin();
  std::cout << "\n\tValor binário: " << binario << std::endl;
  int decimal = to_dec(binario);

  std::cout << "\tValor decimal: " << decimal << std::endl;
}

int le_valor_dec(void) {
  bool valido = true;
  bool valido2;
  int valor;

  while(valido) {
    valido2 = true;
    while(valido2){
      std::cout << std::endl << "Informe o Valor decimal a converter: ";
      // testa se foi digitado um valor válido(número_)
      if (std::cin >> valor) {
        valido2 = false;
      } else {
        std::cout << "== Você deve escolher um número válido!" << std::endl;
        std::cin.clear(); // limpa as flags de erro do cin
        std::cin.ignore(numeric_limits<std::streamsize>::max(), '\n');  // ignora tudo até o \n - limpa o buffer
      }
      std::cout << std::endl;
    }
    if (valor <= 0) {
      std::cout << "\n===   O valor decimal deve ser maior q 0." << std::endl;
      std::cout << "===  Informe novo valor" << std::endl;
    }
    else {
      valido = false;
    }
  }
  return valor;
}

string le_valor_bin(void) {

  bool valid = false;
  string binario;
  string r = "^[01]+$";
  std::regex re(r);
  std::smatch match;
  
  do {
    std::cout << std::endl << "Informe o Valor binario a converter: ";
    std::getline(std::cin, binario);
    // loop iteração na string para verificacao de validade dos caracteres digitados
   
    // if (std::regex_search(binario, match, re)) {
    if (std::regex_match(binario, match, re)) {
    std::cout << "binário válido" << std::endl;
    std::cout << binario << std::endl;
    valid = true;
    } else {
      std::cout << "Binário inválido!!";
      std::cout << "Volte a informar o valor correto"<< std::endl;
    }
  } while (!valid);
  return binario;
}

string to_bin(int valor) {
  string binario;

  while(valor > 0){
    binario = (valor % 2 == 0 ? "0" : "1") + binario;
    valor /= 2;
  }
  return binario;
}

int to_dec (string valor){
  
  int ind = 0;
  int decimal = 0;
  int tamanho_valor = valor.length()-1;
  // Declaracao do iterador da string

  for (int i=0; i <= tamanho_valor; i++) {
    if (valor[i]== '1'){
      decimal += (int) pow(2, tamanho_valor-i);
    }
    // std::cout << "indice:" << i;
    // std::cout << "  binario:" << valor[i];
    // std::cout << " decimal: " << decimal << std::endl;
  }
  return decimal;
}
