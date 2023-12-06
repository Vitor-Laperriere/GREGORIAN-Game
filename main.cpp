#include <iostream>
#include <string>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <vector>
#include <fstream>
#include <random>

std::mutex mtx;
std::condition_variable cv;
bool ready = false;
std::string palavraSorteada;
std::vector<std::string> dicionario;

// Função para carregar o dicionário de palavras
void carregarDicionario() {
    // Implemente o código para carregar as palavras do dicionário
}

// Função para sortear uma palavra
void sortearPalavra() {
    // Implemente o código para sortear uma palavra do dicionário
}

void jogar() {
    std::unique_lock<std::mutex> lock(mtx);
    while (!ready) {
        cv.wait(lock);
    }
    
    // Implemente a lógica do jogo aqui
    // Exemplo: loop para as 8 tentativas, verificação das letras, etc.
}

void iniciarJogo() {
    std::lock_guard<std::mutex> lock(mtx);
    carregarDicionario();
    sortearPalavra();
    ready = true;
    cv.notify_one();
}

int main() {
    std::thread threadJogo(jogar);
    iniciarJogo();
    threadJogo.join();
    return 0;
}
