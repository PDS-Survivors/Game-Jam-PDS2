#include "battle.hpp"
#include "pc.hpp"
#include "npc.hpp"
#include "attack.hpp"
#include "effects/reader.hpp"

#include <string>
#include <iostream>

//Colocar em match
int Battle::_totalLoses = 0;

//Construtor com leitura de arquivo para Npc
Battle::Battle (Pc &player, std::string file, int numBattle, int predio){
    _player = player;
    _adversary = new Npc (file);
    _numBattle = numBattle;
    _predio = predio;
    _totalDamagePc = 0;
    _totalDamageNpc = 0;
}

//Construtor sem leitura de arquivo para Npc
Battle::Battle (Pc* player, Npc* adversary, int numBattle, int predio) {
    _player = *player;
    _adversary = adversary;
    _numBattle = numBattle;
    _predio = predio;
    _totalDamagePc = 0;
    _totalDamageNpc = 0;
}

Battle::~Battle () {
    delete _adversary;
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

int Battle::getTotalLoses () {
    return _totalLoses;
}

void Battle::setResult (bool result) {
    _result = result;
}

void Battle::setDamagePc (int damage) {
    _totalDamagePc += damage;
}

void Battle::setDamageNpc (int damage) {
    _totalDamageNpc += damage;
}

void Battle::setTotalLoses (int lose) {
    _totalLoses = lose;
}

//Texto que introduz a batalha e o adersário
std::string Battle::beginTxt () {
    std::string retorno {};

    retorno = retorno + "====== Batalha: " + char(_numBattle) + " ======\n";
    retorno = retorno + _adversary->getDescription() + "\n";

    return retorno;
}

//Obs:tirar essa função quando implementar a interface
void Battle::imprimeVida () {
    std::cout << "Vida " << _player.getName() << ": " << _player.getLife();
    std::cout << "\nVida " << _adversary->getName() << ": " << _adversary->getLife();
    std::cout << "\n\n";
}

bool Battle::defineResult () {
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
//É preciso criar uma variável em buildding para armazenar o número da batalha
//Podese substituir isso pela leitura de um arquivo;
std::string Battle::resultTxt() {
    std::string txt {};

    if ((_result == 0) && (_numBattle != 3)) {
        txt += "VOCÊ FOI APROVAD@!\n\nParabens por ter derrotado npc_nome!\n";
        txt += "Os aliados del@ estão furiosos com você\nSe prepare para o que está por vir\n";
    }
    else if ((_result == 1) && (_totalLoses == 3) && (_predio == 11)){
        txt += "PARABÉNS! VOCÊ SE FORMOU!\n\n";
        txt += "Foi difícil, foi estressante e agora você tem um pedaço de papel\n";
        txt += "Todos estão orgulhosos de onde você chegou e ansiosos por seu futuro\n";
        txt += "Mas você está pront@ para ele?\n";
    }
    else if ((_result == 0) && (_numBattle == 3)){
        txt += "VOCÊ PASSOU DE SEMESTRE!\n\n";
        txt += "Agora o predio_nome não pode mais te atrapalhar\n";
        txt += "Descanse enquanto pode, pois vai ficar pior ^-^\n";
    }
    else if ((_result == 1) && (_totalLoses != 3)){
        txt += "VOCÊ FOI REPROVAD@!\n\nEssa foi apenas uma derrota, não desista!\n";
        txt += "A ufmg precisa de você!\n";
        txt += "(Você vai mesmo querer estudar 5 anos por esse diploma?)\n";
    }
    else if ((_result == 1) && (_totalLoses != 3)){
        txt += "VOCÊ FOI JUBILAD@!\n\nEssa foi a sua terceira derrota\n";
        txt += "Chegou-se à conclusão de que você não é capaz de ajudar a UFMG\n";
        txt += "Obrigada por tentar, mas não volte tão cedo por favor!\n";
    }

    return txt;
}



std::string Battle::statistcs () {
    std::string stat {};

    stat += "======== Estatisticas de Batalha ========\n";
    stat += "== Resultado: ";
    if ((_player.getLife() >= 0) && (_adversary->getLife() >= 0))
        stat += "nao definido o-o";
    else if (_player.getLife() <= 0)
        stat += "derrota T-T";
    else
        stat += "vitoria :D";
    stat += "\n\n";
    stat += "== Player: "; stat += _player.getName();
    stat += "\nVida inicial: "; stat += std::to_string(_player.getLife() + _totalDamagePc);
    stat += "\nVida atual: "; stat += std::to_string(_player.getLife());
    stat += "\nDefesa: "; stat += std::to_string(_player.getDefense());
    stat += "\nStamina: "; stat += std::to_string(_player.getStamina());
    stat += "\n== Adversário: "; stat += _adversary->getName(); 
    stat += "\nVida inicial: "; stat += std::to_string(_adversary->getLife() + _totalDamageNpc);
    stat += "\nVida atual: "; stat += std::to_string(_adversary->getLife());
    stat += "\nDefesa: "; stat += std::to_string(_adversary->getDefense());
    stat += "\nStamina: "; stat += std::to_string(_adversary->getStamina());
    stat += "\n\n";

    return stat;
}

//Roda a batalha entre Pc e Npc
void Battle::fight () {
    bool test;
    char get_char;

    this->imprimeVida();

    //O npc tem defesa menor, logo ataca primeiro
    if (_player.getDefense() >= _adversary->getDefense()){
        while ((_player.getLife() >= 0) && (_adversary->getLife() >= 0)){
            test = true;

            //Vez do Npc atacar
            while (_adversary->getStamina() >= 5){
                int lpc = _player.getLife();
                int lnpc = _adversary->getLife();

                //Escolha do ataque 
                std::cout << _adversary->getName() << " ira atacar ^o^\n";
                Attack* att;       
                att = _adversary->chooseAttack(); 
                if (att != nullptr) {
                    _adversary->doHit(&_player, att);
                }

                this->setDamagePc(lpc - _player.getLife());
                this->setDamageNpc(lnpc - _adversary->getLife());

                _adversary->setStamina (-5);
                if (this->defineResult() == true) break;
            }
                
            _adversary->setStamina(-5);
            if (this->defineResult() == true) break;
            
            
            this-> imprimeVida();
            if (this->defineResult() == true) break;

            while ((_player.getStamina() >= 5) && (test == true)){

                //Escolha da ação: atacar, não atacar, mostrar estatísticas
                std::cout << "Sua vez de brilhar!\n";
                std::cout << "(a) Ver estatisticas     (b) Atacar!    (c) Esperar, apenas.\n";
                std::cin >> get_char;
                switch (get_char){
                    case 'a' :  std::cout << this->statistcs(); break;
                    case 'b' :  { 
                                int lpc = _player.getLife();
                                int lnpc = _adversary->getLife();

                                Attack* att;
                                att = _player.chooseAttack();
                                
                                

                                if (att != nullptr) {
                                    _player.doHit(_adversary, att);
                                }

                                this->setDamagePc(lpc - _player.getLife());
                                this->setDamageNpc(lnpc - _adversary->getLife());

                                _player.setStamina(-5);

                                } 
                                break;
                    case 'c' : test = false; break;
                    default : std::cout << "Digite 'a', 'b' ou 'c' para continuar"; break;
                }
                if (this->defineResult() == true) break;
            }

            this->imprimeVida ();
            if (this->defineResult() == true) break;

            _player.rebootStamina();
            _adversary->rebootStamina();
        }
    }
    else {
        //O player tem defesa menor, logo ataca primeiro
        while ((_player.getLife() >= 0) && (_adversary->getLife() >= 0)){
            test = true;

            while ((_player.getStamina() >= 5) && (test == true)){

                //Escolha da ação: atacar, não atacar, mostrar estatísticas
                std::cout << "Sua vez de brilhar!\n";
                std::cout << "(a) Ver estatisticas     (b) Atacar!    (c) Esperar, apenas.\n";
                std::cin >> get_char;
                switch (get_char){
                    case 'a' :  std::cout << this->statistcs(); break;
                    case 'b' :  {
                                int lpc = _player.getLife();
                                int lnpc = _adversary->getLife();

                                Attack* att;
                                att = _player.chooseAttack();
                                //
                                if (att != nullptr) {
                                    _player.doHit(_adversary, att);
                                }

                                this->setDamagePc(lpc - _player.getLife());
                                this->setDamageNpc(lnpc - _adversary->getLife());

                                 _player.setStamina(-5);
                                } 
                                break;
                    case 'c' : test = false; break;
                    default : std::cout << "Digite 'a', 'b' ou 'c' para continuar"; break;
                }
                if (this->defineResult() == true) break;
            }
            
            this->imprimeVida();
            if (this->defineResult() == true) break;
            
            while (_adversary->getStamina() >= 5){
                int lpc = _player.getLife();
                int lnpc = _adversary->getLife();

                //Escolha do ataque 
                std::cout << _adversary->getName() << " ira atacar ^o^\n";
                Attack* att;       
                att = _adversary->chooseAttack(); 
                if (att != nullptr) {
                    _adversary->doHit(&_player, att);
                }

                this->setDamagePc(lpc - _player.getLife());
                this->setDamageNpc(lnpc - _adversary->getLife());

                _adversary->setStamina (-5);
                if (this->defineResult() == true) break;
            }

            this->imprimeVida ();
            if (this->defineResult() == true) break;

            _player.rebootStamina();
            _adversary->rebootStamina();
        }
    }
}