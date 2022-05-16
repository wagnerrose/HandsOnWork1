#!/bin/bash
echo -e "\n\t============================="
echo -e "\t<==     Compilando  ....  ==>"
g++ -g -c calculadora.cpp 2> erros.txt
erros=`cat erros.txt | wc -l`
echo -e "\t\tMensagens de erro: $erros"
echo -e "\t=============================\n"
if [ $erros -gt 0 ];
then
  echo -e "\t        Log de erros"
  echo -e "\t=============================\n"
cat erros.txt
else
  g++ -o calc calculadora.o
fi
echo 
read -p "Tecle algo para continuar."
