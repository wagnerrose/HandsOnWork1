echo "============================"
echo "Compilando ...."
g++ -g -o calculadora *.cpp
cat erros.txt | wc -l | awk '{print "Erros: ",$1}'
echo "============================="
read -p "Tecle algo para continuar."
