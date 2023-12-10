#include <iostream>
#include <string>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <vector>
#include <fstream>
#include <random>
#include <semaphore>
#include "gregorian_game.h" 


// Variáveis globais para armazenar a palavra sorteada e o dicionário de palavras.
std::string palavraSorteada;
std::vector<std::string> dicionario;

// Definindo um semáforo binário para controle de sincronização
std::binary_semaphore semaforoSorteio(0), semaforoJogo(0);


// Função para carregar o dicionário de palavras
void carregarVetor(std::vector<std::string>& array) {
    std::ifstream arquivo("dicio.txt");

    if (!arquivo.is_open()) {
        std::cerr << "Erro ao abrir o arquivo." << std::endl;
        return;
    }

    std::string palavra;
    while (std::getline(arquivo, palavra)) {
        array.push_back(palavra);
    }

    arquivo.close();
}

// Função para sortear uma palavra aleatoriamente do dicionário.
std::string sortearPalavra(const std::vector<std::string>& array) {
    if (array.empty()) {
        std::cerr << "O dicionário está vazio." << std::endl;
        return "";
    }

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, array.size() - 1);

    int indiceAleatorio = dis(gen);

    return array[indiceAleatorio];
}

// Função executada por uma thread para controlar a lógica do jogo (sorteio da palavra).
void logicaDoJogo() {
   
    palavraSorteada = sortearPalavra(dicionario);
    semaforoSorteio.release();// Libera a thread principal para começar o jogo.

    semaforoJogo.acquire();// Espera a interação do usuário terminar.

}

int main() {
    
    carregarVetor(dicionario);
    std::thread threadLogica(logicaDoJogo);
   
    runGame(dicionario); // Note a passagem do dicionário como argumento
    threadLogica.join();
    

    return 0;
}


