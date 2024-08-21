#include <iostream>
#include <string>
#include <clocale>
#include <algorithm>  // Para usar std::transform

int main() {
    // Tentar configurar a localidade para diferentes opções
    if (setlocale(LC_ALL, "pt_BR.UTF-8") == NULL && 
        setlocale(LC_ALL, "Portuguese_Brazil") == NULL && 
        setlocale(LC_ALL, "portuguese") == NULL) {
        std::cerr << "Erro ao configurar a localidade!" << std::endl;
    } else {
        std::cout << "Localidade configurada com sucesso!" << std::endl;
    }
    
    std::string nome, resposta;
    int idade;
    bool verificacao = false;
    
    std::cout << "Olá! Qual o seu nome? ";
    std::getline(std::cin, nome);
    
    // Loop para verificar e corrigir a idade se necessário
    do {
        std::cout << "E a sua idade? ";
        std::cin >> idade;
        
        // Limpa o buffer de entrada
        std::cin.ignore();
        
        std::cout << nome << ", vi aqui que você tem " << idade << " anos, é isso mesmo? (Sim/Não) ";
        
        std::getline(std::cin, resposta);

        // Converte a resposta para minúsculas
        std::transform(resposta.begin(), resposta.end(), resposta.begin(), [](unsigned char c){ return std::tolower(c); });

        if (resposta == "sim") {
            verificacao = true;  // Resposta é válida, sai do laço
        } else if (resposta == "não") {
            std::cout << "Vamos corrigir a sua idade então." << std::endl;
        } else {
            std::cout << "Resposta inválida, por favor, responda com 'Sim' ou 'Não'." << std::endl;
        }

    } while (!verificacao);

    std::cout << "Que ótimo! Bem-vindo, " << nome << "! Idade confirmada: " << idade << " anos." << std::endl;

    return 0;
}
