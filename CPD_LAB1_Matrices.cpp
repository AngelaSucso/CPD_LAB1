#include <iostream>
#include <vector>
#include <chrono>

using namespace std;

vector<vector<double>> crearMatriz(int fil, int col){
    vector<double> vectorcito(col, 0);
    vector<vector<double>> matriz;

    for(int i = 0; i < fil; i++){
        matriz.push_back(vectorcito);
    }
    return matriz;
}

void llenarAleatorios(vector<vector<double>>& matriz, int TAM){
    for(int i=0; i<TAM; i++){
        for(int j=0; j<TAM; j++){
            matriz[i][j] = 1+rand()%10;
        }
    }
}

int main()
{
    vector<int> tamanos = {200, 300, 400, 500, 1000, 1500, 2000};
    vector<int> enes = {20, 50, 100};
    int TAM, N;

    vector<vector<double>> A;
    vector<vector<double>> B;
    vector<vector<double>> C;
    for(int pos_tam = 0; pos_tam < tamanos.size(); pos_tam++){
        TAM = tamanos[pos_tam];

        A = crearMatriz(TAM, TAM);
        B = crearMatriz(TAM, TAM);
        C = crearMatriz(TAM, TAM);
        llenarAleatorios(A, TAM);
        llenarAleatorios(B, TAM);

        for(int pos_N = 0; pos_N < enes.size(); pos_N++){
            N = enes[pos_N];
            cout << "tamano = " << TAM << "  " << "N = " << N << endl;

            auto start_time = std::chrono::high_resolution_clock::now();

            for(int k = 0; k < TAM; k++){
                for(int i = 0; i < TAM; i++){
                    int suma = 0;
                    for(int j = 0; j < TAM; j++){
                        suma += A[i][j] * B[j][k];
                    }
                    C[i][k] = suma;
                }
            }
            auto end_time = std::chrono::high_resolution_clock::now();

            cout << "Tiempo de ejecucion 1: " << chrono::duration_cast<chrono::milliseconds>(end_time - start_time).count() << " ms" << endl;

            cout << "-----------------------------------------------------"<<endl;

            start_time = std::chrono::high_resolution_clock::now();

            for(int ii=0; ii<TAM; ii+=N){
                for(int jj=0; jj<TAM; jj+=N){
                    for(int kk=0; kk<TAM; kk+=N){
                        for(int i=ii; i<ii+N; ++i){
                            for(int j=jj; j<jj+N; ++j){
                                for(int k=kk; k<kk+N; ++k)
                                    C[i][j] += A[i][k] * B[k][j];
                            }
                        }
                    }
                }
            }
            end_time = std::chrono::high_resolution_clock::now();
            cout << "Tiempo de ejecucion 2: " << chrono::duration_cast<chrono::milliseconds>(end_time - start_time).count() << " ms" << endl;
        }
    }
    return 0;
}
