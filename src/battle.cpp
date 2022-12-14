#include "battle.hpp"
#include "entities/pc.hpp"
#include "entities/npc.hpp"
#include "attacks/attack.hpp"
#include "namespaces/reader.hpp"

#include <string>
#include <vector>
#include <iostream>

//File: Arquivo para o construtor de battle, contém, arquivo de npc, numero da
//batalha, numero do predio e três textos de vitória)
Battle::Battle (Pc *player, std::string file){

    _player = player;

    std::vector<std::string> words;
    std::vector<std::string> files;
    std::vector<int> values;

    reader::readfile (file, values, words, files);

    _numBattle = values[0];
    _predio = values[1];

    _adversary = new Npc(files[0]);
    _beginTxt = files[1];
    _resultTxt = files[2];
    _name = words[0];

    _totalDamagePc = 0;
    _totalDamageNpc = 0;
    _round = 0;

    _size = _name.size();
}

//Construtor sem leitura de arquivo para Npc
Battle::Battle (Pc player, Npc* adversary, int numBattle, int predio, std::string name) {
    *_player = player;
    _adversary = adversary;
    _numBattle = numBattle;
    _predio = predio;
    _totalDamagePc = 0;
    _totalDamageNpc = 0;
    _round = 0;
    _beginTxt = "Descrição interessante :D (teste)\n";
    _resultTxt = "Hmm obrigada por vencer?\n";
    _name = name;
    _size = _name.size();
}

Battle::~Battle () {
    std::cout<<"destroi battle"<<std::endl;
    delete[] _adversary;

}

bool Battle::getResult () {
    //if (!this->defineResult()) {throw ExcecaoResultadoNaoDefinido (); }
    //else { return _result;}
    return _result;
}

int Battle::getDamagePc () {
    return _totalDamagePc;
}

int Battle::getDamageNpc () {
    return _totalDamageNpc;
}

std::string Battle::getName () {
    return _name;
}

void Battle::setResult (bool result) {
    _result = result;
}

//Texto que introduz a batalha e o adversário
void Battle::beginTxt () {
    reader::readtxt (_beginTxt);
}

//Obs:tirar essa função quando implementar a interface
void Battle::imprimeVida () {

    std::cout << "== Barras de vida ";
    for (int i = 0; i < (7 + _size); i++) { std::cout << "="; }
    std::cout << "\n";
    reader::wait(2);

    // Imprime a barra de vida do player
    std::cout << "[ ";
    for (int i = 0; i < 25; i++){
        if (_player->getLife() - (4*i) > 0) { std::cout << "§"; }
        else { std::cout << " "; }
    }
    std::cout << " ] " << _player->getName() << std::endl;
    reader::wait(1);

    //Imprime a barra de vida do adversário
    std::cout << "[ ";
    for (int i = 0; i < 25; i++){
        if (_adversary->getLife() - (4*i) > 0) { std::cout << "§"; }
        else { std::cout << " "; }
    }
    std::cout << " ] " << _adversary->getName() << std::endl;
    reader::wait(1);

    for (int i = 0; i < (25 + _size); i++) { std::cout << "="; }
    std::cout << "\n\n";

    reader::wait(2);
}

//Indica se o resultado já foi definido ou não
bool Battle::defineResult () {
    //Se perder result = 1, se ganhar = 0;
    if (_player->getLife() <= 0) {
        this->setResult(1); 
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

    for (int i = 0; i < (25 + _size); i++) { std::cout << "="; }
    std::cout << "\n";

    if (_result == 0) {
        reader::readtxt(_resultTxt);
    }
    else if ((_result == 1) && (_player->getNumLifes() > 0)){
        std::cout << "VOCÊ FOI REPROVAD@!\n\nEssa foi apenas uma derrota, não desista!\n";
        std::cout << "A ufmg precisa de voce!\n";
        std::cout << "(Você vai mesmo querer estudar 5 anos por esse diploma?)\n";
    }
    else if ((_result == 1) && (_player->getNumLifes() == 0)){
        std::cout << "VOCÊ FOI JUBILAD@!\n\nEssa foi a sua terceira derrota\n";
        std::cout << "Chegou-se a conclusao de que você não e capaz de ajudar a UFMG\n";
        std::cout << "Obrigada por tentar, mas nao volte tão cedo por favor!\n";
    }

    for (int i = 0; i < (25 + _size); i++) { std::cout << "="; }
    std::cout << "\n\n";

    reader::wait (6);
}

void Battle::statistcs () {

    std::cout << "== Estatisticas de Batalha ";
    for (int i = 0; i < (_size - 2); i++) { std::cout << "="; }
    std::cout << "\n\n";
    
    reader::wait(2);

    std::cout << "== Round: " << std::to_string(_round) << "\n\n";
    reader::wait(2);

    std::cout << "== Resultado: ";
    if (!this->defineResult()) { std::cout << "nao definido *-*\n\n"; }
    else if (_result) { std::cout << "derrota T_T\n\n"; }
    else { std::cout << "vitoria :D\n\n"; }
    reader::wait(2);
    
    std::cout << "== Player: " << _player->getName();
    reader::wait(1);
    std::cout << "\nVidas restantes: " << std::to_string(_player->getNumLifes());
    reader::wait(1);
    std::cout << "\nVida inicial: " << std::to_string(_player->getLife() + _totalDamagePc);
    reader::wait(1);
    std::cout << "\nVida atual: " << std::to_string(_player->getLife());
    reader::wait(1);
    std::cout << "\nDefesa: " << std::to_string(_player->getDefense());
    reader::wait(1);
    std::cout << "\nStamina: " << std::to_string(_player->getStamina());
    reader::wait(1);

    std::cout << "\n\n== Adversário: " << _adversary->getName();
    reader::wait(2); 
    std::cout << "\nVida inicial: " << std::to_string(_adversary->getLife() + _totalDamageNpc);
    reader::wait(1);
    std::cout << "\nVida atual: " << std::to_string(_adversary->getLife());
    reader::wait(1);
    std::cout << "\nDefesa: " << std::to_string(_adversary->getDefense());
    reader::wait(1);
    std::cout << "\nStamina: " << std::to_string(_adversary->getStamina());
    reader::wait(1);

    std::cout << std::endl;
    for (int i = 0; i < (25 + _size); i++) { std::cout << "="; };
    std::cout << "\n\n";

    reader::wait(4);
}

void Battle::figthPc () {
    bool test = true;

    std::cout << "Sua vez de brilhar! *.*\n\n";
    reader::wait(2);

    while (test) {

        try {
            //Escolha da ação: mostrar estatísticas, atacar, não atacar
            std::cout << "(a) Ver estatisticas     (b) Atacar!    (c) Esperar, apenas.\n";
            reader::wait(1);

            std::cout << "== Stamina atual: " << _player->getStamina() << "\n\n";

            char get_char;
            std::cin >> get_char;
        
            switch (get_char) {
                //Mostra as estatísticas de jogo
                case 'a' :  this->statistcs(); break;

                //Mostra quais ataques estão disponíveis para o jogador escolher
                case 'b' :  { 
                            int lpc = _player->getLife();
                            int lnpc = _adversary->getLife();
                            
                            _player->showHit();

                            Attack* att;
                            bool cond = true;

                            do { 
                                att = _player->chooseAttack(); 

                                if (att == nullptr) { cond = false; }
                                else {
                                    //Confirmação do ataque, o jogador pode continuar ele ou cancelar
                                    std::cout << "Tem certeza que quer usar " << att->getName();
                                    std::cout << "? (s/n)\n";

                                    try {
                                        char c;
                                        std::cin >> c;

                                        if (c == 's') { cond = false; }

                                        else if (c == 'n') { 
                                            std::cout << "Uai, qual então?\n"; 
                                            reader::wait(1);
                                        }

                                        else { throw ExcecaoEntradaInvalida2(); }
                                    }
                                    catch (ExcecaoEntradaInvalida2 &e) {
                                        std::cout << e.what();
                                        reader::wait(1);
                                    }
                                }
                            }
                            while (cond);

                            //Apenas executa um ataque se for dada uma entrada válida
                            //Substituir por tratamento de excessão
                            if (att != nullptr) {
                                _player->doHit(_adversary, att);

                                this->imprimeVida();
                            }
                            else {test = false; break;}
                            
                            //Atualiza dados para as estatísticas
                            _totalDamagePc += (lpc - _player->getLife());
                            _totalDamageNpc += (lnpc - _adversary->getLife());

                            } break;

                //Encerra o turno do player
                case 'c' : test = false; break;
                default : throw ExcecaoEntradaInvalida(); break;
            }

            if (this->defineResult()) break;
            
            //Se a stamina for 0 o turno é encerrado
            else if (_player->getStamina() == 0) {
                test = false;
                break;
            }

            else if (test) {
                std::cout << "O que você fará em seguida?\n\n";
                reader::wait(2);
            }
        }
        catch (ExcecaoEntradaInvalida &e) { std::cout << e.what(); reader::wait(1);}
    }

    std::cout << "Fim do seu turno!\n\n";
    reader::wait(1);
}

void Battle::fightNpc () {

    int lpc = _player->getLife();
    int lnpc = _adversary->getLife();

    std::cout << _adversary->getName() << " ira atacar ^o^\n"; 
    reader::wait(2);

    //O npc ataca seguindo um comportamento pré-estabelecido
    _adversary->doTurn(_player);

    _totalDamagePc += (lpc - _player->getLife());
    _totalDamageNpc += (lnpc - _adversary->getLife());

    this->imprimeVida();

    std::cout << "Fim de turno!\n\n";

    reader::wait(2);
}

//Roda a batalha entre Pc e Npc
void Battle::fight () {

    std::cout << "======= FIGHT " << _numBattle << ": " << _name << " ========\n\n";
    reader::wait(6);

    this->beginTxt();

    this->imprimeVida();

    //O npc tem defesa menor, logo ataca primeiro
    if (_player->getDefense() >= _adversary->getDefense()) {
         while (true) {

            _round += 1;

            std::cout << "== ROUND " << _round << "\n\n";
            reader::wait(2);
            
            this->fightNpc();      
                    
            if (this->defineResult()) {
                if (_result) {_player->setNumLifes(-1);}
                break;
            }

            this->figthPc();

            //No final de cada round a stamina de pc e npc é restaurada
            _player->rebootStamina();
            _adversary->rebootStamina();

            if (this->defineResult()) {
                if (_result) {_player->setNumLifes(-1);}
                break;
            }
        }
    }

    //O player tem defesa menor, logo ataca primeiro
    else {
        while (true) {

            _round += 1;

            std::cout << "== ROUND " << _round << "\n\n";
            reader::wait(2);

            this->figthPc();
                
            if (this->defineResult()) {
                if (_result) {_player->setNumLifes(-1);}
                break;
            }
                
            this->fightNpc();    

            _player->rebootStamina();
            _adversary->rebootStamina();

            if (this->defineResult()) {
                if (_result) {_player->setNumLifes(-1);}
                break;
            }
        }
    }

    std::cout << "== ";
    if (!_result) { std::cout << "APROVAD@ =";}
    else { std::cout << "REPROVAD@ ";}

    for (int i = 0; i < (12 + _size); i++) { std::cout << "=";}
    std::cout << "\n\n";

    reader::wait(2);

    this->resultTxt ();

    //Ao final de uma batalha a vida do player e do adversário é restaurada
    //Fazer função battleReset?
    _player->rebootLife (_player->getLife() + _totalDamagePc);
    _adversary->rebootLife (_adversary->getLife() + _totalDamageNpc);

    _player->setStamina(5);
    _adversary->setStamina(5);

    _round = 0;

    _totalDamagePc = 0;
    _totalDamageNpc = 0;
}

void Battle::manageAttacks(){

    std::cout << std::endl;
    for (int i = 0; i < (25 + _size); i++) { std::cout << "="; };
    std::cout << "\n\n";
    reader::wait(2);

    std::cout<<"Olha so!!! Parece que ";
    std::cout<<_adversary->getName();
    std::cout<<" deixou cair um ataque...\n"<<std::endl;

    reader::wait(3);

    //pega um ataque aleatório do npc
    Attack* attack = _adversary->getHit( behavior::rollDice(0, _adversary->sizeofHit()));

    std::cout<<"== "<<attack->getName()<< " : "<<std::endl;
    reader::wait(2);

    std::cout<<attack->getDescription()<<std::endl;
    reader::wait(1);

    if(!attack->isDefense()) std::cout<<"dano: "<<attack->getDamage()<<std::endl;
    reader::wait(1);

    std::cout<<"stamina: "<<attack->getStamina()<<std::endl;

    std::cout<<std::endl<<std::endl;

    reader::wait(3);

    std::cout<<"Vai levar ou deixar pra tras?"<<std::endl;
    std::cout<<std::endl;

    reader::wait(2);

    std::cout<<"(l) Levar, quanto mais melhor neh"<<std::endl;
    std::cout<<"(d) Deixar, meu bolso ta cheio..."<<std::endl;

    reader::wait(1);

    bool cond = true;

    while (cond) {
        char choice;
        std::cin >> choice;

        try {
            if(choice == 'l'){
                //Se o player tiver menos de 4 ataques ele é adicionado automaticamente
                if (_player->sizeofHit() < 4) {
                    _player->addHit(attack);

                    std::cout << '\n' << attack->getName();
                    std::cout << " foi adcionado à sua coleção de ataques! :D\n\n";

                    reader::wait(2);

                    _player->showHit();

                    reader::wait(5);
                }
                //Caso a coleçao de ataques esteja cheia ele precisará de desfazer de um ataque
                else {
                    std::cout << "Essa é a sua coleção de atques:\n\n";
                    reader::wait(2);
                    _player->showHit();
                    reader::wait(2);
                    
                    std::cout << "\nPor qual deles você deseja substituir o novo ataque?\n";
                    std::cout << "Obs: Caso você queira cancelar essa ação pressione '5'\n\n";

                    int op;
                    std::cin >> op;
                    _player->delHit(op);
                    _player->addHit(attack);

                    std::cout << "Uhuuul. Aqui estão os seus novos ataques:\n\n";
                    reader::wait(2);

                    _player->showHit();
                    reader::wait(5);
                    
                    std::cout << "\n";
                }
                cond = false;
            }  
            else if(choice == 'd'){
                std::cout << "Não faria o mesmo se fosse você, que sem graça...\n\n";
                reader::wait(3);
                cond = false;
            }
            else { throw ExcecaoEntradaInvalida3(); }
        }
        catch (ExcecaoEntradaInvalida3 &e) {
            std::cout << e.what();
            reader::wait(1);
        }
    }

    std::cout << std::endl;
    for (int i = 0; i < (25 + _size); i++) { std::cout << "="; };
    std::cout << "\n\n";

    reader::wait(4);
}

ExcecaoEntradaInvalida::ExcecaoEntradaInvalida () {
    _msgErro = "\nEntrada inválida.\nDigite 'a', 'b' ou 'c' para continuar\n\n";
}

const char* ExcecaoEntradaInvalida::what () const noexcept {
    return _msgErro.c_str();
}

ExcecaoEntradaInvalida2::ExcecaoEntradaInvalida2 () {
    _msgErro = "\nEntrada inválida.\nDigite 's' ou 'n' para continuar\n\n";
}

const char* ExcecaoEntradaInvalida2::what () const noexcept {
    return _msgErro.c_str();
}

ExcecaoEntradaInvalida3::ExcecaoEntradaInvalida3 () {
    _msgErro = "\nEntrada inválida.\nDigite 'l' ou 'd' para continuar\n\n";
}

const char* ExcecaoEntradaInvalida3::what () const noexcept {
    return _msgErro.c_str();
}

ExcecaoResultadoNaoDefinido::ExcecaoResultadoNaoDefinido () {
    _msgErro = "\nO resultado ainda não foi definido. Termine a batalha para sabê-lo\n\n";
}

const char* ExcecaoResultadoNaoDefinido::what () const noexcept {
    return _msgErro.c_str();
}