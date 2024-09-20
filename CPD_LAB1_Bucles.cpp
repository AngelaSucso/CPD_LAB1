#include <iostream>
#include <chrono>
#define MAX 15000

double A[MAX][MAX];
double x[MAX], y[MAX]= {0};

void primerBucle(){
    for(int i=0; i<MAX; i++){
        for(int j=0; j<MAX; j++){
            y[i] += A[i][j]*x[j];
        }
    }
}

void segundoBucle(){
    for(int j=0; j<MAX; j++){
        for(int i=0; i<MAX; i++){
            y[i] += A[i][j]*x[j];
        }
    }
}

int main(){

    //INICIALIZA A Y X
    for(int i=0; i<MAX; i++){
        for (int j = 0; j < MAX; j++){
            A[i][j]=(double)rand()/10;
        }
    }

    for(int i=0 ; i<MAX; i++){
        x[i] = (double)rand()/10;
    }

    auto start1 = std::chrono::high_resolution_clock::now();
    primerBucle();
    auto end1 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> duration = end1 - start1;

    auto start2 = std::chrono::high_resolution_clock::now();
    segundoBucle();
    auto end2 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> duration2 = end2- start2;

    std::cout << "Tiempo de ejecucion del bucle: " << duration.count() << " ms" << std::endl;
    std::cout << "Tiempo de ejecucion del bucle: " << duration2.count() << " ms" << std::endl;


    return 0;

}
