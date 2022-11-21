#include "battle.hpp"
#include "entities/pc.hpp"
#include "entities/npc.hpp"
#include "attacks/attack.hpp"
#include "namespaces/reader.hpp"

#include <string>
#include <iostream>

//Colocar em match
int Battle::_totalLoses = 0;

//File: Arquivo para o construtor de battle, contém, arquivo de npc, numero da
//batalha, numero do predio e três textos de vitória)
Battle::Battle (Pc *player, std::string file, std::string beginTxtAdress){

    _player = *player;
    
    std::vector<std::string> words;
    std::vector<std::string> files;
    std::vector<int> values;

    read::readfile (file, values, words, files);

    _adversary = new Npc(files[0]);
    _numBattle = values[0];
    _predio = values[1];
    _resultTxt = words[0];

    _beginTxt = beginTxtAdress;

    _totalDamagePc = 0;
    _totalDamageNpc = 0;
    _round = 0;

    _size = int((_player.getName()).size())+int((_adversary->getName()).size());
}

//Construtor sem leitura de arquivo para Npc
Battle::Battle (Pc* player, Npc* adversary, int numBattle, int predio) {
    _player = *player;
    _adversary = adversary;
    _numBattle = numBattle;
    _predio = predio;
    _totalDamagePc = 0;
    _totalDamageNpc = 0;
    _round = 0;
    _beginTxt = "Descrição interessante :D (teste)\n";
    _resultTxt = "Hmm obrigada por vencer?\n";
    _size = int((_player.getName()).size())+int((_adversary->getName()).size());
}

Battle::~Battle () {
    _adversary->~Npc();
}

bool Battle::getResult () {
    return _result;
}

int Battle::getTotalLoses () {
    return _totalLoses;
}

int Battle::getDamagePc () {
    return _totalDamagePc;
}

int Battle::getDamageNpc (){
    return _totalDamageNpc;
}

void Battle::setResult (bool result) {
    _result = result;
}

void Battle::setTotalLoses (int lose) {
    _totalLoses = lose;
}

//Texto que introduz a batalha e o adersário
void Battle::beginTxt () {
    read::readtxt (_beginTxt);
}

//Obs:tirar essa função quando implementar a interface
void Battle::imprimeVida () {

    std::cout << "== Barras de vida ";
    for (int i = 0; i < (11 + _size); i++) { std::cout << "="; }
    std::cout << "\n";
    read::wait(2);

    std::cout << "[ ";
    for (int i = 0; i < 25; i++){
        if (_player.getLife() - (4*i) > 0) { std::cout << "§"; }
        else { std::cout << " "; }
    }
    std::cout << " ] " << _player.getName() << std::endl;
    read::wait(1);

    std::cout << "[ ";
    for (int i = 0; i < 25; i++){
        if (_adversary->getLife() - (4*i) > 0) { std::cout << "§"; }
        else { std::cout << " "; }
    }
    std::cout << " ] " << _adversary->getName() << std::endl;
    read::wait(1);

    for (int i = 0; i < (29 + _size); i++) { std::cout << "="; }
    std::cout << "\n\n";

    read::wait(2);
}

//Retorna se o resuktado foi definido ou nn
bool Battle::defineResult () {
    //Se perder result = 1, se ganhar = 0;
    if (_player.getLife() <= 0) {
        this->setResult(1); 
        this->setTotalLoses(1);
        return true;
    }
    else if (_adversary->getLife() <= 0) {
        this->setResult(0);
        return true;
    }
    else {
        return false;
    }
}

//Lê o texto de vitória ou derrota ao fim da batalha
void Battle::resultTxt () {

    for (int i = 0; i < (29 + _size); i++) { std::cout << "="; }
    std::cout << "\n";

    if (_result == 0) {
        std::cout << _resultTxt;
    }
    else if ((_result == 1) && (_totalLoses != 3)){
        std::cout << "VOCÊ FOI REPROVAD@!\n\nEssa foi apenas uma derrota, não desista!\n";
        std::cout << "A ufmg precisa de voce!\n";
        std::cout << "(Você vai mesmo querer estudar 5 anos por esse diploma?)\n";
    }
    else if ((_result == 1) && (_totalLoses == 3)){
        std::cout << "VOCÊ FOI JUBILAD@!\n\nEssa foi a sua terceira derrota\n";
        std::cout << "Chegou-se a conclusao de que você não e capaz de ajudar a UFMG\n";
        std::cout << "Obrigada por tentar, mas nao volte tão cedo por favor!\n";
    }

    for (int i = 0; i < (29 + _size); i++) { std::cout << "="; }
    std::cout << "\n\n";

    read::wait (6);
}

void Battle::statistcs () {

    std::cout << "== Estatisticas de Batalha ";
    for (int i = 0; i < (2 + _size); i++) { std::cout << "="; }
    std::cout << "\n\n";
    
    read::wait(2);

    std::cout << "== Round: " << std::to_string(_round) << "\n\n";
    read::wait(2);

    std::cout << "== Resultado: ";
    if (!this->defineResult()) { std::cout << "nao definido *-*\n\n"; }
    else if (_result) { std::cout << "derrota T_T\n\n"; }
    else { std::cout << "vitoria :D\n\n"; }
    read::wait(2);
    
    std::cout << "== Player: " << _player.getName();
    read::wait(1);
    std::cout << "\nVida inicial: " << std::to_string(_player.getLife() + _totalDamagePc);
    read::wait(1);
    std::cout << "\nVida atual: " << std::to_string(_player.getLife());
    read::wait(1);
    std::cout << "\nDefesa: " << std::to_string(_player.getDefense());
    read::wait(1);
    std::cout << "\nStamina: " << std::to_string(_player.getStamina());
    read::wait(1);

    std::cout << "\n\n== Adversário: " << _adversary->getName();
    read::wait(4); 
    std::cout << "\nVida inicial: " << std::to_string(_adversary->getLife() + _totalDamageNpc);
    read::wait(1);
    std::cout << "\nVida atual: " << std::to_string(_adversary->getLife());
    read::wait(1);
    std::cout << "\nDefesa: " << std::to_string(_adversary->getDefense());
    read::wait(1);
    std::cout << "\nStamina: " << std::to_string(_adversary->getStamina());
    read::wait(1);

    std::cout << std::endl;
    for (int i = 0; i < (29 + _size); i++) { std::cout << "="; };
    std::cout << "\n\n";

    read::wait(4);
}

void Battle::figthPc () {
    bool test = true;
    char get_char;

    std::cout << "Sua vez de brilhar! *.*\n\n";
    read::wait(2);

    while (test){

        //Escolha da ação: atacar, não atacar, mostrar estatísticas
        std::cout << "(a) Ver estatisticas     (b) Atacar!    (c) Esperar, apenas.\n";
        read::wait(1);

        std::cout << "== Stamina atual: " << _player.getStamina() << "\n\n";
        std::cin.ignore();
        get_char = std::cin.get();

        switch (get_char) {
            case 'a' :  this->statistcs(); break;
            case 'b' :  { 
                        int lpc = _player.getLife();
                        int lnpc = _adversary->getLife();
                        
                        _player.showHit();

                        Attack* att;
                        att = _player.chooseAttack();

                        if (att != nullptr) {
                            _player.doHit(_adversary, att);

                            _player.showAction(att);
                            std::cout << std::endl;

                            this->imprimeVida();
                        }

                        _totalDamagePc += (lpc - _player.getLife());
                        _totalDamageNpc += (lnpc - _adversary->getLife());
                        } 
                        break;
            case 'c' : test = false; break;
            //Substituir por tratamento de exceção
            default : std::cout << "Digite 'a', 'b' ou 'c' para continuar\n"; break;
        }

        if (this->defineResult()) break;

        if (test) {
            std::cout << "O que você fará em seguida?\n\n";
            
            read::wait(2);
        }
    }

    std::cout << "Fim do seu turno!\n\n";
    read::wait(1);
}

void Battle::fightNpc () {

    int lpc = _player.getLife();
    int lnpc = _adversary->getLife();

    //Escolha do ataque 
    std::cout << _adversary->getName() << " ira atacar ^o^\n\n"; 
    read::wait(2);

    _adversary->doTurn(&_player);

    _totalDamagePc += (lpc - _player.getLife());
    _totalDamageNpc += (lnpc - _adversary->getLife());

    this->imprimeVida();

    std::cout << "Fim de turno!\n\n";
    
    read::wait(2);
}

//Roda a batalha entre Pc e Npc
void Battle::fight () {

    std::cout << "======= FIGHT " << _numBattle << ": " << _player.getName() << " X ";
    std::cout << _adversary->getName() << " ========\n\n";
    read::wait(6);

    this->imprimeVida();

    //O npc tem defesa menor, logo ataca primeiro
    if (_player.getDefense() >= _adversary->getDefense()) {
         while (!this->defineResult()) {

            _round += 1;

            std::cout << "== ROUND " << _round << "\n\n";
            read::wait(2);
            
            this->fightNpc();      
                    
            if (this->defineResult()) break;

            this->figthPc();

            if (this->defineResult()) break;

            _player.rebootStamina();
            _adversary->rebootStamina();
        }
    }

    //O player tem defesa menor, logo ataca primeiro
    else {
        while (!this->defineResult()) {

            _round += 1;

            std::cout << "== ROUND " << _round << "\n\n";
            read::wait(2);

            this->figthPc();
                
            if (this->defineResult()) break;
                
            this->fightNpc();    

            if (this->defineResult()) break;

            _player.rebootStamina();
            _adversary->rebootStamina();
        }
    }

    std::cout << "== ";
    if (!_result) { std::cout << "APROVAD@ =";}
    else { std::cout << "REPROVAD@ ";}

    for (int i = 0; i < (16 + _size); i++) { std::cout << "=";}
    std::cout << "\n\n";

    read::wait(2);
}