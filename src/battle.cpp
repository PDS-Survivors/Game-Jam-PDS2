#include "battle.hpp"
#include "pc.hpp"
#include "npc.hpp"
#include "attack.hpp"

#include <string>
#include <iostream>

int Battle::_totalLoses = 0;

Battle::Battle (Pc player, Npc* adversary, int numBattle, int predio) {
    _player = player;
    _adversary = adversary;
    _numBattle = numBattle;
    _predio = predio;
    _totalDamagePc = 0;
    _totalDamageNpc = 0;
}

Battle::~Battle () {
    _player.~Pc();
    _adversary->~Npc();
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
    std::cout << "Vida" << _player.getName() << ": ";
    for (int i = 0; i<=(_player.getLife()/5); i++){
        std::cout << "#";
    }
    std::cout << "\nVida" << _adversary->getName() << ": ";
    for (int i = 0; i<=(_adversary->getLife()/5); i++){
        std::cout << "#";
    }
    std::cout << std::endl;
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
        txt += "Descanse enquanto pode, pois vai ficar pior\n";
    }
    else if ((_result == 1) && (_totalLoses != 3)){
        txt += "VOCÊ FOI REPROVAD@!\n\nEssa foi apenas uma derrota, não desista!\n";
        txt += "A ufmg precisa de você!\n";
        txt += "(Você vai mesmo querer estudar 5 anos por esse diploma?)\n";
    }
    else if ((_result == 1) && (_totalLoses != 3)){
        txt += "VOCÊ FOI JUBILAD@!\n\nEssa foi a sua terceira derrota\n";
        txt += "Chegou-se à conclusão de que você não é capaz de ajudar a UFMG\n";
        txt += "Obrigada por tentar, mas não volte tão cedo por favor!";
    }

    return txt;
}

std::string Battle::statistcs () {
    std::string stat {};

    stat += "======== Estatisticas de Batalha ========\n";
    stat += "== Resultado: ";
    if ((_player.getLife() >= 0) || (_adversary->getLife() >= 0))
        stat += "nao definido o-o";
    else if (_player.getLife() <= 0)
        stat += "derrota T-T";
    else
        stat += "vitoria :D";
    stat += "\n\n";
    stat = stat + "== Player: " + _player.getName();
    stat = stat + "\nVida inial: " + char(_player.getLife() + _totalDamagePc); 
    stat = stat + "\nVida atual: " + char(_player.getLife()); 
    stat = stat + "\nDefesa: " + char(_player.getDefense());
    stat = stat + "\nStamina: " + char(_player.getStamina());
    stat = stat + "== Adversário: " + _adversary->getName(); 
    stat = stat + "Vida inicial: " + char(_adversary->getLife() + _totalDamageNpc);
    stat = stat + "\nVida atual: " + char(_adversary->getLife());
    stat = stat + "\nDefesa: " + char(_adversary->getDefense());
    stat = stat + "\nStamina: " + char(_adversary->getStamina());
    stat += "\n\n";

    return stat;
}

//Roda a batalha entre Pc e Npc
void Battle::fight () {
    bool test;

    //Imprime as barras de vida
    this->imprimeVida();

    //O npc tem defesa menor, logo ataca primeiro
    if (_player.getDefense() >= _adversary->getDefense()){
        while ((_player.getLife() >= 0) || (_adversary->getLife() >= 0)){
            test = 1;
            _player.rebootStamina();
            _adversary->rebootStamina();

            //Enquanto a stamina for maior ou igual a 5, pode-se atacar
            while (_adversary->getStamina() >= 5){
                _adversary->setStamina(-5);
                int lpc = _player.getLife();
                int lnpc = _adversary->getLife();

                //Escolha do ataque 
                std::cout << _adversary->getName() << "ira atacar ^o^ ";
                Attack* att;       
                att = _adversary->chooseAttack(); 
                _adversary->doHit(&_player, att);

                _totalDamagePc = (lpc - _player.getLife());
                _totalDamageNpc = (lnpc - _adversary->getLife());
            }
            while ((_player.getStamina() >= 5) && (test == 1)){

                //Escolha da ação: atacar, não atacar, mostrar estatísticas
                std::cout << "Sua vez de brilhar!\n";
                std::cout << "(a) Ver estatisticas     (b) Atacar!    (c) Esperar, apenas.\n";
                switch (getchar()){
                    case 'a' :  std::cout << this->statistcs(); break;
                    case 'b' :  { _player.setStamina(-5);
                                int lpc = _player.getLife();
                                int lnpc = _adversary->getLife();

                                Attack* att;
                                att = _adversary->chooseAttack();
                                _player.doHit(_adversary, att);

                                _totalDamagePc = (lpc - _player.getLife());
                                _totalDamageNpc = (lnpc - _adversary->getLife());
                                break;
                                }
                    case 'c' : test = 0; break;
                    default :  break;
                }
            }

            //Define o resultado
            if (_player.getLife() <= 0) {
                this->setResult(1); 
                this->setTotalLoses(1);
            }
            else if (_adversary->getLife() <= 0) {
                this->setResult(0);
            }

            //Imprime as barras de vida
            this->imprimeVida ();
        }
    }
    else{
        //O player tem defesa menor, logo ataca primeiro
        while ((_player.getLife() >= 0) || (_adversary->getLife() >= 0)){
            _player.rebootStamina();
            _adversary->rebootStamina();

            while (_player.getStamina() >= 5){
                std::cout << "Sua vez de brilhar!\n";

                std::cout << "(a) Ver estatisticas     (b) Atacar!    (c) Esperar, apenas.\n";
                switch (getchar()){
                    case 'a' : this->statistcs(); break;
                    case 'b' :  { _player.setStamina(-5);
                                int lpc = _player.getLife();
                                int lnpc = _adversary->getLife();

                                Attack* att;
                                att = _adversary->chooseAttack();
                                _player.doHit(_adversary, att);

                                _totalDamagePc = (lpc - _player.getLife());
                                _totalDamageNpc = (lnpc - _adversary->getLife());
                                break;
                                }
                    case 'c' : test = 0; break;
                    default : break;
                }
            }
            while (_adversary->getStamina() >= 5){
                _adversary->setStamina(-5);
                int lpc = _player.getLife();
                int lnpc = _adversary->getLife();

                std::cout << _adversary->getName() << "ira atacar";
                Attack* att; 
                att = _adversary->chooseAttack();
                _adversary->doHit(&_player, att);

                _totalDamagePc = (lpc - _player.getLife());
                _totalDamageNpc = (lnpc - _adversary->getLife());
            }

            if (_player.getLife() <= 0) {
                this->setResult(1); 
                this->setTotalLoses(1);
            }
            else if (_adversary->getLife() <= 0) {
                this->setResult(0);
            }

            this->imprimeVida ();
        }
    }
}