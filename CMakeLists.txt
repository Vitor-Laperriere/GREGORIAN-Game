cmake_minimum_required(VERSION 3.10)

# Definir o nome do projeto
project(GregorianGame)

# Especificar a versão do C++ utilizada
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Localizar o pacote SFML
# Para sistemas Windows, você pode precisar especificar o caminho para a SFML com o SFML_DIR
# set(SFML_DIR "<caminho_para_SFML>/lib/cmake/SFML")
find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

# Incluir os diretórios dos cabeçalhos da SFML
include_directories(${SFML_INCLUDE_DIR})

# Adicionar os arquivos fonte
add_executable(GregorianGame main.cpp gregorian_game.cpp)

# Linkar as bibliotecas da SFML com seu executável
target_link_libraries(GregorianGame sfml-graphics sfml-window sfml-system)

# Se o dicio.txt for um recurso necessário, você pode copiá-lo para o diretório de build
configure_file(dicio.txt ${CMAKE_BINARY_DIR}/dicio.txt COPYONLY)
