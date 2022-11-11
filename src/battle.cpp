#include "battle.hpp"
#include "entity.hpp"
#include "attack.hpp"

#include <string>
#include <iostream>

Battle::Battle (Pc player, Npc* adversary, int* numBattle, int* totalLoses, int predio) {
    _player = player;
    _adversary = adversary;
    _numBattle = numBattle;
    *_numBattle += 1;
    _totalLoses = totalLoses;
    _predio = predio;
    _totalDamagePc = 0;
    _totalDamageNpc = 0;
}

Battle::~Battle () {
    delete _adversary;
    delete _numBattle;
    delete _totalLoses;
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
//É preciso criar uma variável em buildding para armazenar o número da batalha
//Podese substituir isso pela leitura de um arquivo;
std::string Battle::readResultTxt() {
    std::string txt {};
    if ((_result == 0) && (*_numBattle != 3)) {
        txt += "VOCÊ FOI APROVAD@!\n\nParabens por ter derrotado npc_nome!\n";
        txt += "Os aliados del@ estão furiosos com você\nSe prepare para o que está por vir\n";
    }
    else if ((_result == 1) && (*_totalLoses == 3) && (_predio == 11)){
        txt += "PARABÉNS! VOCÊ SE FORMOU!\n\n";
        txt += "Foi difícil, foi estressante e agora você tem um pedaço de papel\n";
        txt += "Todos estão orgulhosos de onde você chegou e ansiosos por seu futuro\n";
        txt += "Mas você está pront@ para ele?\n";
    }
    else if ((_result == 0) && (*_numBattle == 3)){
        txt += "VOCÊ PASSOU DE SEMESTRE!\n\n";
        txt += "Agora o predio_nome não pode mais te atrapalhar\n";
        txt += "Descanse enquanto pode, pois vai ficar pior\n";
    }
    else if ((_result == 1) && (*_totalLoses != 3)){
        txt += "VOCÊ FOI REPROVAD@!\n\nEssa foi apenas uma derrota, não desista!\n";
        txt += "A ufmg precisa de você!\n";
        txt += "(Você vai mesmo querer estudar 5 anos por esse diploma?)\n";
    }
    else if ((_result == 1) && (*_totalLoses != 3)){
        txt += "VOCÊ FOI JUBILAD@!\n\nEssa foi a sua terceira derrota\n";
        txt += "Chegou-se à conclusão de que você não é capaz de ajudar a UFMG\n";
        txt += "Obrigada por tentar, mas não volte tão cedo por favor!";
    }
    return txt;
}

std::string Battle::statistcs () {
    //Essa função pode ser chamada dentrou ou fora de fight e retorna
    //as estatísticas da batalha: resultado, player (vida inicial, atual, stamina e defesa)
    // e adversário (vida inicial, vida atual e defesa)
    std::string stat;
    stat = "======== Estatisticas de Batalha ========\n";
    stat += "== Resultado: ";
    if ((_player.getLife() >= 0) || (_adversary->getLife() >= 0))
        stat += "nao definido o-o";
    else if (_player.getLife() <= 0)
        stat += "derrota T-T";
    else
        stat += "vitoria :D";
    stat += "\n\n";
    stat += "== Player: "; stat += _player.getName();
    stat += "\nVida inial: "; stat += (_player.getLife() + _totalDamagePc); 
    stat += "\nVida atual: "; stat += _player.getLife(); 
    stat += "\nDefesa: "; stat += _player.getDefense();
    stat += "\nStamina: "; stat += _player.getStamina();
    stat += "== Adversário: "; stat += _adversary->getName(); 
    stat += "Vida inicial: "; stat += (_adversary->getLife() + _totalDamageNpc);
    stat += "\nVida atual: "; stat += _adversary->getLife();
    stat += "\nDefesa: "; stat += _adversary->getDefense();
    stat += "\nStamina: "; stat += _adversary->getStamina();
    stat += "\n\n";
    return stat;
}

//Roda a batalha entre Pc e Npc
void Battle::fight () {
    bool test;
    //Imprime as barras de vida
    std::cout << "Vida" << _player.getName() << ": ";
    for (int i = 0; i<=(_player.getLife()/5); i++){
        std::cout << "#";
    }
    std::cout << "\nVida" << _adversary->getName() << ": ";
    for (int i = 0; i<=(_adversary->getLife()/5); i++){
        std::cout << "#";
    }
    std::cout << std::endl;
    //Quem tiver a menor defesa irá atacar primeiro
    if (_player.getDefense() >= _adversary->getDefense()){
        while ((_player.getLife() >= 0) || (_adversary->getLife() >= 0)){
            test = 1;
            _player.rebootStamina();
            _adversary->rebootStamina();

            //Enquanto a stamina for maior ou igual a 5, pode-se atacar
            while (_adversary->getStamina() >= 5){
                _adversary->setStamina(-5);
                std::cout << _adversary->getName() << "ira atacar ^o^ ";
                Attack* att;

                //Escolha do ataque           
                att = _adversary->chooseAttack();  //Como fazer para um ataque ser aleatório?
                _adversary->doHit(&_player, att);
            }
            while ((_player.getStamina() >= 5) && (test == 1)){
                std::cout << "Sua vez de brilhar!\n";

                //Escolha da ação: atacar, não atacar, mostrar estatísticas
                std::cout << "(a) Ver estatisticas     (b) Atacar!    (c) Esperar, apenas.\n";
                switch (getchar()){
                    case 'a' :  std::cout << this->statistcs(); break;
                    case 'b' :  { _player.setStamina(-5);
                                Attack* att;
                                att = _adversary->chooseAttack();
                                _player.doHit(_adversary, att);
                                break;
                                }
                    case 'c' : test = 0; break;
                }
            }

            //Define o resultado
            if (_player.getLife() <= 0) {_result = 1; _totalLoses += 1;}
            else if (_adversary->getLife() <= 0) _result = 0;

            //Imprime as barras de vida
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
    }
    else{
        while ((_player.getLife() >= 0) || (_adversary->getLife() >= 0)){
           _player.rebootStamina();
            _adversary->rebootStamina();
            while (_player.getStamina() >= 5){
                 std::cout << "Sua vez de brilhar!\n";
                std::cout << "(a) Ver estatisticas     (b) Atacar!    (c) Esperar, apenas.\n";
                switch (getchar()){
                    case 'a' : this->statistcs(); break;
                    case 'b' :  { _player.setStamina(-5);
                                Attack* att;
                                att = _adversary->chooseAttack();
                                _player.doHit(_adversary, att);
                                break;
                                }
                    case 'c' : test = 0; break;
                }
            }
            while (_adversary->getStamina() >= 5){
                _adversary->setStamina(-5);
                std::cout << _adversary->getName() << "ira atacar";
                Attack* att; 
                att = _adversary->chooseAttack();
                _adversary->doHit(&_player, att);
            }
            if (_player.getLife() <= 0) {_result = 1; _totalLoses += 1;}
            else if (_adversary->getLife() <= 0) _result = 0;
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
    }
}