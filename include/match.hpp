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
#include <string>
#include <vector>
#include <stack>

class Match {
    private:
        Pc* _player;
        std::stack<Building*> _buildings;
        std::vector<Effect*> _permanentEffects;
        int _numLifes = 3;
        std::string _epilogue;

    public:

        /**
         * @brief Construct a new Match object
         * @details Lê do arquivo os prédios e os efeitos permanentes(usados nos eventos)
         * 
         */
        Match();

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
         * @brief "sorteia" qual o efeito que deve acontecer
         * @details com uma série de cálculos obtém um valor "aleatório" para ser o número do efeito que deve
         * ser apicado, o número do efeito corresponde a sua posição no vetor de efeitos _permanentEffects
         * 
         * @return inteiro que indica qual o efeito deve ser aplicado entre aqueles no vetor de efeitos 
         */
        int chooseEffect();

        /**
         * @brief Função que faz com que aconteça um evento
         * @details chama a função chooseEffect(), obtem qual o efeito deve ser aplicado nesse evento e passa
         * esse efeito para que seja implementado pela classe Pc
         * 
         */
        void eventHappen();

        /**
         * @brief Set the Epilogue object
         * @details epilogue é lido do arquivo e depende se o jogador ganhou ou perdeu a partida 
         * 
         * @param result informa se o jogador ganhou ou perdeu a partida
         * result == 1 : ganhou
         * result == 0 : perdeu
         * 
         */
        void setEpilogue(bool result);
        
        /**
         * @brief Imprime o epilogo na tela
         * @details O epilogo informa ao jogador o resultado de sua partida(Match): se ganhou ou perdeu
         * 
         */
        void printEpilogue();

        /**
         * @brief Retorna o numero de vidas que o jogador possui
         * @details Esse numero de vidas determina se o jogador pode continuar a partida ou se ele perdeu e a 
         * partida(match) deve ser interrompida 
         * 
         * @return int _numLifes
         */
        int getNumLifes();

        /**
         * @brief Reduz o numero de vidas que o jogador tem
         * @details Chamada quando o jogador morre ao lutar contra um adiversario
         * 
         */
        void died();

        /**
         * @brief Retorna 0 caso não vá occorer evento ou o numero do evento (1-17)
         * @details Decide de havera um evento ao final do predio, chance de 50% disso occorer, 
         * baseado no relogio interno do computador (occore o evento se a o numero da hora, 
         * contanto os centesimos milesimos de segundo etc. for par). Caso occora um evento 
         * ele é selecionado aleatoriamente de forma semelhante (Baseado em uma lista de eventos
         * possiveis, 17 no total, o evento e selecionado a partir do resto da divisão do numero 
         * da hora, contanto os centesimos milesimos de segundo etc. por 17).
         * Os eventos podem alterar diversar caracteristicas do player como defesa
         * ataque, dano, vida etc.  
        */
        int choseEvent();

        /**
         * @brief Executa o evento escolhido pela função choseEvent().
         * @details Executa o evento escolhido pela função choseEvent(). E retorna uma string (bem grande alias)
         * no formato "Titulo do evento" - "Desrição do evento" - "descrição dos eveitos do evento" 
        */
        std::string doEvent(int n);

};

#endif