#include "battle.hpp"
#include "entity.hpp"
#include "attack.hpp"

#include <string>
#include <list>
#include <iostream>

Battle::Battle (Pc* player, Npc* adversary) {
    this->_player = player;
    this->_adversary = adversary;
    this->_totalDamagePc = 0;
    this->_totalDamageNpc = 0;
}

Battle::~Battle () {

}

bool Battle::getResult () {
    return _result;
}

int Battle::getDamagePc () {
    return _totalDamagePc;
}

int Battle::getDamageNpc () {
    return _totalDamageNpc;
}

void Battle::setDamagePc (int damage) {
    _totalDamagePc += damage;
}

void Battle::setDamageNpc (int damage) {
    _totalDamageNpc += damage;
}

//Lê a descrição do Npc no início da batalha
std::string Battle::readNpc () {
    return _adversary->getDescription();
}

//Lê o texto de vitória ou derrota ao fim da batalha
std::string Battle::readResultTxt() {

}

std::string Battle::statistcs () {
    //Essa função pode ser chamada dentrou ou fora de fight e retorna
    //as estatísticas da batalha: resultado, player (vida inicial, atual, stamina e defesa)
    // e adversário (vida inicial, vida atual e defesa)

    std::string stat;
    stat = "======== Estatisticas de Batalha ========/n";
    stat += "/n== Resultado: ";
    if ((_player.getLife() >= 0) || (_adversary->getLife() >= 0))
        stat += "nao definido o-o";
    else if (_player.getLife() <= 0)
        stat += "derrota T-T";
    else
        stat += "vitoria :D";
    stat += "/n/n";
    stat += "== Player: "; stat += _player.getName(); stat += "/n";
    stat += "Vida inial: "; stat += (_player.getLife() + _totalDamagePc); 
    stat += "/nVida atual: "; stat += _player.getLife(); 
    stat += "/nDefesa: "; stat += _player.getDefense();
    stat += "/nStamina: "; stat += _player.getStamina();
    stat += "== Adversário: "; stat += _adversary->getName(); 
    stat += "Vida inicial: "; stat += (_adversary->getLife() + _totalDamageNpc);
    stat += "/nVida atual: "; stat += _adversary->getLife();
    stat += "/nDefesa: "; stat += _adversary->getDefense();
    stat += "/n";
    return stat;
}

//Roda a batalha entre Pc e Npc
void Battle::fight () {
    //OBS: colocar opção de sair no meio da batalha e de
    //mostrar as estatísticas durante ela também;

    //Imprime as barras de vida
    std::cout << "Vida" << _player.getName() << ": ";
    for (int i = 0; i<=(_player.getLife()/5); i++){
        std::cout << "#";
    }
    std::cout << "/nVida" << _adversary->getName() << ": ";
    for (int i = 0; i<=(_adversary->getLife()/5); i++){
        std::cout << "#";
    }
    std::cout << std::endl;
    //Quem tiver a menor defesa irá atacar primeiro
    if (_player.getDefense() >= _adversary->getDefense()){
        while ((_player.getLife() >= 0) || (_adversary->getLife() >= 0)){
            _player.rebootStamina();
            _adversary->rebootStamina();
    //Enquanto a stamina for maior ou igual a 5, pode-se atacar
            while (_adversary->getStamina() >= 5){
                _adversary->setStamina(-5);
                std::cout << _adversary->getName() << "ira atacar";
                Attack* att;
    //Escolha do ataque           
                att = _adversary->chooseAttack();
                _adversary->doHit(_player, att);
            }
            while (_player.getStamina() >= 5){
                _player.setStamina(-5);
                std::cout << "Sua vez de brilhar";
                Attack* att;
                att = _adversary->chooseAttack();
                _player.doHit(_adversary, att);
            }
    //Define o resultado
            if (_player.getLife() <= 0) _result = 1;
            else if (_adversary->getLife() <= 0) _result = 0;
    //Imprime as barras de vida
            std::cout << "Vida" << _player.getName() << ": ";
            for (int i = 0; i<=(_player.getLife()/5); i++){
                std::cout << "#";
            }
            std::cout << "/nVida" << _adversary->getName() << ": ";
            for (int i = 0; i<=(_adversary->getLife()/5); i++){
                std::cout << "#";
            }
            std::cout << std::endl;
        }
    }
    else{
        while ((_player.getLife() >= 0) || (_adversary->getLife() >= 0)){
           _player.rebootStamina();
            _adversary->rebootStamina();
            while (_player.getStamina() >= 5){
                _player.setStamina(-5);
                std::cout << "Sua vez de brilhar";
                Attack* att;
                att = _adversary->chooseAttack();
                _player.doHit(_adversary, att);
            }
            while (_adversary->getStamina() >= 5){
                _adversary->setStamina(-5);
                std::cout << _adversary->getName() << "ira atacar";
                Attack* att; 
                att = _adversary->chooseAttack();
                _adversary->doHit(_player, att);
            }
            if (_player.getLife() <= 0) _result = 1;
            else if (_adversary->getLife() <= 0) _result = 0;
    //Imprime as barras de vida
            std::cout << "Vida" << _player.getName() << ": ";
            for (int i = 0; i<=(_player.getLife()/5); i++){
                std::cout << "#";
            }
            std::cout << "/nVida" << _adversary->getName() << ": ";
            for (int i = 0; i<=(_adversary->getLife()/5); i++){
                std::cout << "#";
            }
            std::cout << std::endl;
        }
    }
}

//?
Attack* readCommand() {

}