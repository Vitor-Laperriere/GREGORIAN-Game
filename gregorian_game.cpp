#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <vector>
#include <semaphore>
#include "gregorian_game.h"

extern std::string palavraSorteada;
extern std::binary_semaphore semaforoSorteio, semaforoJogo;

void colorirTentativa(const std::string& tentativa, const std::string& palavraSorteada, sf::RenderWindow& window, sf::Font& font, int posY) {
    for (size_t i = 0; i < tentativa.size(); ++i) {
        sf::Text letra(std::string(1, tentativa[i]), font, 24);

        // Letra correta na posição correta
        if (i < palavraSorteada.size() && tentativa[i] == palavraSorteada[i]) {
            letra.setFillColor(sf::Color::Green);
        }
        // Letra correta, mas na posição errada
        else if (palavraSorteada.find(tentativa[i]) != std::string::npos) {
            bool letraNaPosicaoErrada = true;

            // Verifica se a letra aparece antes nesta posição na palavra sorteada
            for (size_t j = 0; j <= i && j < palavraSorteada.size(); ++j) {
                if (tentativa[i] == palavraSorteada[j]) {
                    letraNaPosicaoErrada = false;
                    break;
                }
            }

            letra.setFillColor(letraNaPosicaoErrada ? sf::Color::Yellow : sf::Color::Red);
        }
        // Letra incorreta
        else {
            letra.setFillColor(sf::Color::Red);
        }
        
        letra.setPosition(100 + i * 20, posY);
        window.draw(letra);
    }
}


int runGame(const std::vector<std::string>& dicionario) {

    const int maxTentativas = 8;// Número máximo de tentativas permitidas.
    int numTentativas = 0; // Contador de tentativas do usuário.
    bool acertou = false; // Indica se o usuário acertou a palavra.

    // Configuração inicial da janela do jogo.
    sf::RenderWindow window(sf::VideoMode(800, 600), "Gregorian");
    sf::Font font;
    if (!font.loadFromFile("../fonts/Kalnia-VariableFont.ttf")) {
        std::cerr << "Erro ao carregar a fonte." << std::endl;
        return -1;
    }

    semaforoSorteio.acquire(); // Espera a palavra ser sorteada

    // Variáveis para gerenciar as tentativas do usuário.
    std::string tentativa;
    std::vector<std::string> tentativas; // Armazena todas as tentativas feitas
    int posY = 50; // Posição inicial para desenhar o texto

    sf::Text text;
    text.setFont(font);
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::White);
    text.setPosition(100, 20);

    // Configuração do texto que será atualizado com a tentativa atual.
    sf::Text textTentativaAtual;
    textTentativaAtual.setFont(font);
    textTentativaAtual.setCharacterSize(24);
    textTentativaAtual.setFillColor(sf::Color::White);
    textTentativaAtual.setPosition(100, posY); // Posição inicial do texto da tentativa atual

    // Indica se a tentativa atual foi enviada.
    bool tentativaEnviada = false;

// Loop principal do jogo.
    while (window.isOpen()  && numTentativas < maxTentativas) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();// Fecha a janela se o evento de fechamento for acionado.

            // Captura eventos de teclado
            if (event.type == sf::Event::TextEntered) {
                if (event.text.unicode < 128) {
                    char c = static_cast<char>(event.text.unicode);

                    // Verifica se o caractere é uma letra e adiciona à tentativa
                    if (std::isalpha(c)) {
                        tentativa += std::tolower(c);
                    }

                    // Para apagar a última letra com a tecla backspace
                    if (event.text.unicode == '\b' && !tentativa.empty()) {
                        tentativa.pop_back();
                    }

                    textTentativaAtual.setString(tentativa); // Atualiza o texto sendo digitado
                }
            }

             if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Enter && !tentativa.empty()) {
                    tentativas.push_back(tentativa);
                    tentativaEnviada = true; // Define tentativaEnviada como true
                    numTentativas++; // Incrementa o contador de tentativas
                    if (tentativa == palavraSorteada) {
                        acertou = true;
                        break; // O usuário acertou a palavra
                    }
                    tentativa.clear();
                }
            }
        }
        if (tentativaEnviada) {
            if (tentativa == palavraSorteada) {
                acertou = true;
                break; // O usuário acertou a palavra
            }

            numTentativas++;
            if (numTentativas < maxTentativas) {
                tentativas.push_back(tentativa);
            }
            tentativa.clear();
            tentativaEnviada = false;
        }

        window.clear();

        // Desenha todas as tentativas anteriores
        posY = 90; // Reseta a posição Y
       for (const auto& t : tentativas) {
            colorirTentativa(t, palavraSorteada, window, font, posY);
            posY += 30; // Aumenta a posição Y para a próxima tentativa
        }

        window.draw(textTentativaAtual); // Desenha o texto da tentativa atual

        window.display();
    }
    if (!acertou) {
        // O usuário não acertou a palavra
        std::string msg = "A palavra era: " + palavraSorteada;
        sf::Text finalText(msg, font, 24);
        finalText.setFillColor(sf::Color::White);
        finalText.setPosition(100, posY + 30);
        window.draw(finalText);
        window.display();
        sf::sleep(sf::seconds(5)); // Mostra a mensagem por 5 segundos
    }
    else{
         std::string msg = "Acertou" + palavraSorteada;
    }
    return 0;
}
