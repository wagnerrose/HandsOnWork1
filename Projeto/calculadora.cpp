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
int escolhe_opcao(void);
void limpa_tela(void);
void tecle_algo(void);

int main(void) {
  int opcao;
  bool valida = true;

    // loop de escolha do tipo de conversão
  do {
    limpa_tela();
    opcao = escolhe_opcao();
    switch (opcao) {
      case 1:
        converte_decbin();
        break;
      case 2:
        converte_bindec();
        break;
      default:
        valida = false;
    }
  } while(valida);
 return 0;
}

int escolhe_opcao(void) {
  int opcao;
  bool valido = true;

  while(valido)
  {
    do {
      std::cout << std::endl << "\t\tEscolha uma opção:" << std::endl;
      std::cout << "\t\t  1 - Conversão Decimal Binária" << std::endl;
      std::cout << "\t\t  2 - Conversão Binária Decimal" << std::endl;
      std::cout << "\t\t  9 - Sair" << std::endl;
      std::cout << "\t\t         Opção: ";

      // testa se foi digitado um valor válido(número_)
      if (std::cin >> opcao) {
        break;
      } else {
       std::cout << "\n\t\t=== Você deve escolher uma opção válida!" << std::endl;
       std::cout << "\t\t=== Tente outra vez." << std::endl;
       std::cin.clear(); // limpa as flags de erro do cin
       std::cin.ignore(numeric_limits<std::streamsize>::max(), '\n');  // ignora tudo até o \n - limpa o buffer
       tecle_algo();
       limpa_tela();
      }
      std::cout << std::endl;
    } while(true);

    switch(opcao){
      case 1:
        std::cout << "\n\t\t===  Você Selecionou Conversão Decimal Binária" << std::endl;
        valido = false;
        break;
      case 2:
        std::cout << "\n\t\t===  Você Selecionou Conversão Binária Decimal" << std::endl;
        valido = false;
        break;
      case 9:
        std::cout << "\n\t\t===  Você selecionou sair do programa." << std::endl;
        std::cout << "\t\t===  Até mais.\n" << std::endl;
        valido = false;
        break;
      default:
        std::cout << "\n\t\t===  Você selecionou uma opção inválida." << std::endl;
        std::cout << "\t\t===  Tente outra vez." << std::endl;
        tecle_algo();
        limpa_tela();
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
  std::cout << "\n\t\t====== Resultado ======" << std::endl;
  std::cout << "\t\t=== Valor decimal: " << valor << std::endl;
  binario = to_bin(valor);
  std::cout << "\t\t=== Valor binário: ";
  std::cout << binario << std::endl;
  std::cout << "\n\t\t=== Tecle algo para continuar. ";
  std::cin.ignore();
  std::getchar();
}

void converte_bindec(void){

  string le_valor_bin(void);
  int to_dec(string);

  string binario = le_valor_bin();
  std::cout << "\n\t\t====== Resultado ======" << std::endl;
  std::cout << "\t\tValor binário: " << binario << std::endl;
  int decimal = to_dec(binario);

  std::cout << "\t\tValor decimal: " << decimal << std::endl;
  tecle_algo();
}

int le_valor_dec(void) {
  bool valido = true;
  bool valido2;
  int valor;

  while(valido) {
    valido2 = true;
    while(valido2){
      std::cout << std::endl << "\t\tInforme o Valor decimal a converter: ";
      // testa se foi digitado um valor válido(número_)
      if (std::cin >> valor) {
        valido2 = false;
      } else {
        std::cout << "\t\t=== Você deve escolher um número decimal válido!" << std::endl;
        std::cout << "\t\t===  Tente outra vez." << std::endl;
        std::cin.clear(); // limpa as flags de erro do cin
        std::cin.ignore(numeric_limits<std::streamsize>::max(), '\n');  // ignora tudo até o \n - limpa o buffer
      }
      std::cout << std::endl;
    }
    if (valor <= 0) {
      std::cout << "\n\t\t=== O valor decimal deve ser maior q 0." << std::endl;
      std::cout << "\t\t=== Você deve escolher um número decimal válido!" << std::endl;
      std::cout << "\t\t=== Tente outra vez." << std::endl;
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
  // std::smatch match;
  
  do {
    std::cout << std::endl << "\t\tInforme o Valor binario a converter: ";
    // std::cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
    std::cin.ignore();
    std::getline(std::cin, binario);
    // loop iteração na string para verificacao de validade dos caracteres digitados
   
    if (std::regex_match(binario, re)) {
    // std::cout << "binário válido" << std::endl;
    // std::cout << binario << std::endl;
    valid = true;
    } else {
      std::cout << "\n\t\t=== Você deve escolher um número binário válido!" << std::endl;
      std::cout << "\t\t===  Tente outra vez." << std::endl;
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
  // int tamanho_valor = valor.length()-1;
  // Declaracao do iterador da string

  std::cout << "Tamanho da string binaria: " << valor.size()<< std::endl;

  for (int i=0; i < valor.size(); i++) {
    if (valor[i]== '1'){
      decimal += (int) pow(2, (valor.size()-1) - i);
    }
    // std::cout << "indice:" << i;
    // std::cout << "  binario:" << valor[i];
    // std::cout << " decimal: " << decimal << std::endl;
  }
  return decimal;
}

void tecle_algo(void) {

  std::cout << "\n\t\t=== Tecle ENTER para continuar. ";
  std::cin.ignore();
  std::getchar();
}

void limpa_tela(void){
  std::system("clear||cls");
}
