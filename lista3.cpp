#include <iostream>
#include <algorithm>

using namespace std;

//Ordena o vetor pelo método quick_sort. Não há retorno.
void quick_sort (int *array, int inicio, int fim){
    int i,j; //variáveis auxiliares para o inicio e para o fim do vetor
    int meio; //variável que armazena a média entre i e j
    int pivo; //Valor do vetor[meio]
    int troca; //Variável auxiliar para trocar elementos do vetor


    i = inicio;
    j = fim;
    meio = (i+j)/2;

    pivo = array[meio];

    do{
        while (array[i]<pivo)
            i++;
        while (array[j]>pivo)
            j--;

        if (i<=j){
            troca = array[i];
            array[i] = array[j];
            array[j] = troca;

            i++;
            j--;
        }


    } while (i < j);

    if (inicio < j)
        quick_sort(array,inicio,j);
    if (fim > i)
        quick_sort(array,i,fim);

}

int main(){

	int aux; //"Aux" é a variável que representa o número de tubos presentes no vetor
  int i,j; //Variáveis auxiliares para realização dos loops


  cout << "Tamanho do vetor" << endl;
  cin >> aux;

  int vetor[aux];

  srand((unsigned)time(NULL));
  for (int i=0; i < aux; i++){
    vetor[i] = rand()%100000;
  }

  quick_sort(vetor,0,aux);

  if(aux <= 20){
    cout << "Vetor ordenado = " << endl;
    for (size_t i = 0; i < aux; i++) {
        cout << vetor[i] << " ";
    }
    cout << endl;
  }
	return 0;
}
