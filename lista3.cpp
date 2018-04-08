#include <bits/stdc++.h>
#include <algorithm>
#include <sys/time.h>
#include <sys/resource.h>

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

    while(i<=j){
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


    }

    if (inicio < j)
        quick_sort(array,inicio,j);
    if (fim > i)
        quick_sort(array,i,fim);

}

void heap_sort(int *array, int n) {
   int i = n / 2, pai, filho, t;
   while(true) {
      if (i > 0) {
          i--;
          t = array[i];
      } else {
          n--;
          if (n == 0) return;
          t = array[n];
          array[n] = array[0];
      }
      pai = i;
      filho = i * 2 + 1;
      while (filho < n) {
          if ((filho + 1 < n)  &&  (array[filho + 1] > array[filho]))
              filho++;
          if (array[filho] > t) {
             array[pai] = array[filho];
             pai = filho;
             filho = pai * 2 + 1;
          } else {
             break;
          }
      }
      array[pai] = t;
   }
}

double calcula_tempo(const struct rusage *b, const struct rusage *a) {
    if (b == NULL || a == NULL)
        return 0;
    else
        return ((((a->ru_utime.tv_sec * 1000000 + a->ru_utime.tv_usec) -
                 (b->ru_utime.tv_sec * 1000000 + b->ru_utime.tv_usec)) +
                ((a->ru_stime.tv_sec * 1000000 + a->ru_stime.tv_usec) -
                 (b->ru_stime.tv_sec * 1000000 + b->ru_stime.tv_usec)))
                / 1000000.0);
}


int main(){

  struct rusage tempo_inicial, tempo_final;
  double tempo,tempo2;
	int aux; //"Aux" é a variável que representa o número de tubos presentes no vetor
  int i,j; //Variáveis auxiliares para realização dos loops


  cout << "Tamanho do vetor" << endl;
  cin >> aux;

  int vetor[aux],vetor2[aux];

  srand((unsigned)time(NULL));
  for (int i=0; i < aux; i++){
    vetor[i] = rand()%100000;
    vetor2[i] = vetor[i];
  }

  cout << endl;

  if(aux <= 20){
    cout << "Vetor desordenado = " << endl;
    for (size_t i = 0; i < aux; i++) {
        cout << vetor[i] << " ";
    }
    cout << endl;
  }

  cout << endl;

  getrusage(RUSAGE_SELF, &tempo_inicial);
    quick_sort(vetor,0,aux);
  getrusage(RUSAGE_SELF, &tempo_final);
  tempo = calcula_tempo(&tempo_inicial, &tempo_final);

  getrusage(RUSAGE_SELF, &tempo_inicial);
    heap_sort(vetor2,aux);
  getrusage(RUSAGE_SELF, &tempo_final);
  tempo2 = calcula_tempo(&tempo_inicial, &tempo_final);


  if(aux <= 20){
    cout << "Vetor ordenado = " << endl;
    for (size_t i = 0; i < aux; i++) {
        cout << vetor2[i] << " ";
    }
    cout << endl;
  }

  cout << endl;
  
  printf("Tempo Quick Sort: %lf\n",tempo);
  printf("Tempo Heap Sort: %lf\n",tempo2);

	return 0;
}
