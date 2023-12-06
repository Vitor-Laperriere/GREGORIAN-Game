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

// Função para sortear uma palavra

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
    //carregarDicionario();
   // sortearPalavra();
    ready = true;
    cv.notify_one();
}

int main() {
    std::vector<std::string> palavras;
    carregarVetor(palavras);
    std::string palavraAleatoria = sortearPalavra(palavras);
    std::cout << "Palavra aleatória " << palavraAleatoria << std::endl;

    return 0;
}


