/**
 * @file match.hpp
 * @author Beatriz Siqueira Campagnaro (beatrizscampagnaro@gmail.com)
 * @brief Contém a classe principal Match 
 * @version 1.0
 * @date 2022-11-28
 * @details Essa classe inicializa o jogador, contém e chama os prédios. Ela também armazena o numero de 
 * vidas que o jogador ainda tem (quantas vezes pode morrer sem perder o jogo).
 * @copyright Copyright (c) 2022
 * 
 */


#ifndef MATCH_HPP
#define MATCH_HPP


#include "building.hpp"
#include "effects/effect.hpp"
#include "entities/pc.hpp"
#include "namespaces/reader.hpp"
#include <string>
#include <vector>
#include <stack>
#include <fstream>

class Match {
    private:
        Pc* _player;
        std::stack<Building*> _buildings;
        std::vector<Effect*> _permanentEffects;
        std::string _epilogue;
        std::vector<int> _alreadyHappened;

    public:

        /**
         * @brief Construct a new Match object
         * @details Lê do arquivo os prédios e os efeitos permanentes(usados nos eventos)
         * 
         */
        Match ();

        /**
         * @brief Constroi o objeto apontado por _player
         * @details Recebe o tipo de personagem que o jogador escolheu e cria o personagem adequado
         * 
         * @param type informa qual o tipo de personagem deve ser criado
         * 
         */
        void setPlayer(int type);

        /**
         * @brief Chama o prédio no topo da pilha para que seja jogado
         * @details Chama a função start_battle() do prédio no topo da pilha
         * 
         */
        void playBuilding();

        /**
         * @brief Set the Epilogue object
         * @details epilogue é lido do arquivo e depende se o jogador ganhou ou perdeu a partida 
         * 
         * @remark IMPORTANTE: Essa função lança a exceção ExcecaoProblemasAoAbrirArquivo caso haja problemas
         * com o arquivo
         * 
         * @param result informa se o jogador ganhou ou perdeu a partida
         * result == 1 : ganhou
         * result == 0 : perdeu
         * 
         */
        void setEpilogue ();
        
        /**
         * @brief Imprime o epilogo na tela
         * @details O epilogo informa ao jogador o resultado de sua partida(Match): se ganhou ou perdeu
         * 
         */
        void printEpilogue ();

        /**
         * @brief Retorna 0 caso não vá occorer evento ou o numero do evento (1-17)
         * @details Decide de havera um evento ao final do predio, chance de 50% disso occorer, 
         * baseado no relogio interno do computador (occore o evento se o numero da hora, 
         * contanto os centesimos, milesimos de segundo, etc., for par). Caso occora um evento 
         * ele é selecionado aleatoriamente de forma semelhante (Baseado em uma lista de eventos
         * possiveis, 17 no total, o evento e selecionado a partir do resto da divisão do numero 
         * da hora por 17).
         * Os eventos podem alterar diversas caracteristicas do player como defesa
         * ataque, dano, vida etc.  
        */
        int chooseEvent();

        /**
         * @brief Executa o evento escolhido pela função choseEvent().
         * @details Executa o evento escolhido pela função choseEvent(), caso o evento escolhido ja tenha occorido ele executa
         * o proximo evento da lista, dessa forma garantido que o mesmo evento não ocorra duas vezes na mesma gameplay.
         * E retorna uma string (bem grande alias) no formato "Titulo do evento" - "Desrição do evento" - "descrição dos eveitos do evento" 
        */
        std::string doEvent (int n);

        std::string introducao ();

        std::string introducao2 (char op);

        bool end ();

        void setBuildingStack (std::string arqv);

        int getPlayerLifes ();
};

class ExcecaoProblemasAoAbrirArquivo: public std::exception{
    private:
        std::string _error;
    
    public:
        /**
         * @brief Construtor de Excecao Problemas Ao Abrir Arquivo 
         * 
         * @param arquivo é o nome do arquivo que não foi aberto como deveria
         */
        ExcecaoProblemasAoAbrirArquivo(std::string arquivo);

        /**
         * @brief retorna frase de erro para que eja impressa
         * 
         * @return const char* ponteiro para "Erro ao abrir o arquivo: 'nome do arquivo' \n"
         */
        const char* what() const noexcept override;
};
#endif