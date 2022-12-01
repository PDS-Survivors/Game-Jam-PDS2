/**
 * @file battle.hpp
 * @author Talita Félix Lúcio (talitafelixlucio2004@gmail.com)
 * @brief Essa biblioteca possui três classes, sendo battle a principal e responsável por fazer
 * a batalha entre o player e um adversário atacontecer e as outras para tratamento de exceção.
 * @details 
 * @version 1.0
 * @date 2022-11-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef BATTLE_HPP
#define BATTLE_HPP

#include <string>
#include "entities/npc.hpp"
#include "entities/pc.hpp"

/**
 * @brief Executa a batalha entre o player e um adversário
 * @details Essa classe irá incializar um objeto batalha e realizar a luta entre o jogador e seu
 * adversário, impriminto uma descrição sobre a batalha antes de seu início e um texto com o
 * resultado dessa ao final
 * 
 */
class Battle {

    private:

        Pc _player;
        Npc* _adversary;

        bool _result;
        int _totalDamagePc;
        int _totalDamageNpc;
        int _numBattle;
        int _predio;
        int _round;

        int _size;
        std::string _name;
        std::string _beginTxt;
        std::string _resultTxt;

    public:

        /**
         * @brief Constrói um novo objeto Battle com o uso de um arquivo
         * @details Esse construtor receberá um arquivo com todas as informações específicas
         * da batalha e um ponteiro que carrega as informações do jogador. Além disso, ele irá
         * inicializar as variávis _round, _totalDamagePc e _totalDamageNpc como zero e a variável
         * _size, com o tamanho do nome da batalha.
         * 
         * @param player Ponteiro para um objeto Pc que contem as informações do jogador
         * @param file Arquivo na forma de string que possui informações sobre o adversário, nome
         * da batalha, texto de introdução da batalha (história do adversário) e um texto de 
         * vitória caso o jogador derrote o seu adversário.
         */
        Battle (Pc* player, std::string file);

        /**
         * @brief Constrói um novo objeto Battle
         * @details Esse construtor não está sendo usado durante o jogo, ele está aqui para ser
         * usado em testes de batalha para os quais não foram feitos arquivos. A principal
         * diferença com relação ao construtor com arquivo é que ele atribui à _beginTxt e _resultTxt
         * um texto pré-definido.
         * 
         * @param player Ponteiro para um objeto Pc que contem as informações do jogador
         * @param adversary Ponteiro para um objeto Npc que contem as informações do adversário
         * @param numBattle Número inteiro que indica qual a posição da batalha na pilha de execução
         * @param predio Número inteiro que indica em qual prédio a batalha está
         * @param name String que contém o nome da batalha
         */
        Battle (Pc player, Npc* adversary, int numBattle, int predio, std::string name);

        /**
         * @brief Destrutor de um objeto Battle
         * @details Exclui o ponteiro para Npc que foi alocado dinâmicamente na memória
         * 
         */
        ~Battle ();

        /**
         * @brief Mostra o resultado da batalha (_result)
         * @details _result não é inicializada no construtor. Ela apenas recebe um valor booleano
         * quando uma luta termina, por isso, caso o resultado não tenha sido definido, essa função
         * lança uma execeção ExcecaoResultadoNaoDefinido
         * 
         * @return true : o jogador foi derrotado
         * @return false : o jogador venceu a batalha
         */
        bool getResult ();

        /**
         * @brief Pega o valor atual de _totalDamagePc
         * @details Esse atributo armazeda a quantidade de dano que o jogador recebeu ao longo
         * da batalha e, toda vez que o adversário ataca, esse valor é atualizado
         * 
         * @return int _totalDamagePc : dano infligido no player
         */
        int getDamagePc ();

        /**
         * @brief Pega o valor atual de _totalDamageNpc
         * @details Esse atributo armazeda a quantidade de dano que o adversário recebeu ao longo
         * da batalha e, toda vez que o jogador ataca, esse valor é atualizado
         * 
         * @return int _totalDamageNpc : dano infligido no adversário
         */
        int getDamageNpc ();
        
        /**
         * @brief Pega o conteúdo de _name
         * @details É usado para apresentar a batalha e para mostrar o resumo dessa
         * 
         * @return std::string _name : nome da batalha
         */
        std::string getName();

        /**
         * @brief Muda o conteúdo de _result para aquele dado pelo parâmetro
         * @details Se a função receber como parâmetro 'true' o adversário ganhou, mas se receber
         * 'false' o jogador ganhou
         * 
         * @param result variável boolena que define o resultado da batalha
         */
        void setResult (bool result);
        
        /**
         * @brief Lê o texto introdutório da batalha (Descrição detalhada do Npc)
         * @details Essa leitura é feita com a função readtxt contida no namespace read e recebe
         * como parâmetro o atributo _beginTxt
         * 
         */
        void beginTxt();

        /**
         * @brief Imprime na tela as barras de vida do player e do adversário
         * @details A vida total tanto de Pc quanto de Npc, pode ser no máximo 100. Baseado nisso, 
         * as barras de vida são impressas entre colchetes, e cada símbolo '§' indica 4 pontos de
         * vida.
         * 
         */
        void imprimeVida ();

        /**
         * @brief Indica se o resultado da batalha já foi definido ou não
         * @details Esssa função faz isso usando o valor da vida das entidades. Se uma delas for
         * igual ou menor do que zero, então ela irá chamar a gunção getResult() usando como
         * parâmetro 1 caso o player tenha perdido e 0 caso o adversário tenha perdido, além de
         * retornar 'true'. Caso contrário ela apenas irá retornar 'false'.
         * 
         * @return true : o resultado da batalha já foi definido
         * @return false : o resultado ainda não foi definido
         */
        bool defineResult ();

        /**
         * @brief Lê um texto com o resultado da batalha
         * @details Caso o resultado seja a vitória, a função lerá o atributo _resultTxt, que é
         * específico de cada Npc, caso contrário podem ser impressos dois textos: uma para se for a
         * primeira ou segunda vez que o jogador perde, ou seja, ele irá continuar jogando, e outra
         * para caso seja a sua terceira derrota, ou seja, fim de jogo.
         * 
         */
        void resultTxt ();

        /**
         * @brief Imprime as estatísticas de jogo
         * @details Essa função irá imprimir vários dados de interre do jogador: O número do round
         * atual, qual o resultado da batalha, quem é o jogagor e qual a situação dos seus
         * atributos (vida, defesa e stamina) e quem é o adversário e qual a situação dos seus
         * atributos (vida, defesa e stamina).
         * 
         */
        void statistcs ();

        /**
         * @brief Função que organiza e executa a batalha
         * @details A primeia coisa que essa função faz é imprimir o nome da batalha e, logo em 
         * seguida o texto de introdução. Para definir quem ataca primeiro a função olha a defesa 
         * das entidades, aquela que tiver a defesa menor irá atacar primeiro (a função tem dois 
         * loops, um para cada entidade atacando primeiro). Após isso ela irá incrementar o valor de 
         * _round, para indicar que uma nova passada na batalha está começando. Logo depois será
         * chamada a função fightPc, caso o player tenha uma defesa menor, para que ele tenha seu
         * turno. Depois é a vez de adversário, então chama-se fightNpc, e o por fim a stamina dos 
         * dois é restaurda antes do início do próximo round. Sempre que uma entidade termina de 
         * atacar a função defineResult é chamada para encerrar a batalha caso haja um vencedor.
         * 
         */
        void fight (); 

        /**
         * @brief Executa o turno do player atacar
         * @details O turno do jogador irá continuar enquanto a sua stamina for maior do que o e
         * o resultado do jogo não seja definido. Dito isso o jogador terá de escolher entre três
         * opções. A primeira 'a' é Estatística, apenas chamará a função Statistic() e não consome
         * stamina. A segunda 'b' é Atacar: ela irá mostar pro jogador quais ataques ele pode usar
         * de acordo com sua stamina atual e esse terá que escolher um deles (será pedida uma
         * confirmação de ataque após a escolha), depois disso o ataque é executado e as barras
         * de vida são impressas. Já a terceira opção 'c' Esperar, encerra o turno do jogador, caso
         * ele ainda tenha stamina mas não queira atacar. Além disso o valor de _totalDamagePc e
         * _totalDamageNpc é atualizado.
         * 
         */
        void figthPc ();

        /**
         * @brief Executa o turno do adversário atacar
         * @details O turno de npc consiste em indicar que o Npc irá atacar, executar essa ação
         * com a função doTurn(), imprimir as barras de vida e atualizar os valores de 
         * _totalDamagePc e _totalDamageNpc.
         * 
         */
        void fightNpc ();

        /**
         * @brief O player descobre um novo ataque e pode adicioná-lo à sua coleção
         * @details Essa função pega um ataque aleatório do adversário contra qual o player lutou
         * e o introduz ao jogador. Esse tem a opção de ficar ou descartar o ataque. Caso ele
         * escolha ficar com esse existem dois casos: o que a pasta de ataques ainda não está cheia,
         * logo o novo ataque é adcionado automaticamente a ela, e o caso em que ela está cheia
         * e é preciso escolher qual ataque retirar para colocar esse novo no lugar. 
         * 
         */
        void manageAttacks();
};

/**
 * @brief Classe para tratamentp de exceção
 * @details Responsável por tratar a exceção lançada quando o player não digita uma entrada válida
 * na vez de escolher qual ação irá fazer em figthpc()
 * 
 */
class ExcecaoEntradaInvalida : public std::exception {

     private:
        std::string _msgErro;
    
     public:

        /**
         * @brief Construtor de um objeto ExcecaoEntradaInvalida
         * @details Esse construtor não recebe parâmetros e inicializa o atributo _msgErro
         * 
         */
        ExcecaoEntradaInvalida ();

        /**
         * @brief Função que mostra a mensagem de erro
         * @details Essa função será chamada durante o laçamento da exceçaõ e irá retornar a
         * string _msgErro como um const char*
         * 
         * @return const char* : retorna a string _msgErro no formato pedido
         */
        const char* what () const noexcept override;
 };

/**
 * @brief Classe para tratamentp de exceção
 * @details Responsável por tratar a exceção lançada quando o player não digita uma entrada válida
 * quando é pedida a confirmação do ataque escolhido em fightPc()
 * 
 */
class ExcecaoEntradaInvalida2 : public std::exception {

    private:
        std::string _msgErro;

    public:

        /**
         * @brief Construtor de um objeto ExcecaoEntradaInvalida2
         * @details Esse construtor não recebe parâmetros e inicializa o atributo _msgErro
         * 
         */
        ExcecaoEntradaInvalida2 () ;

        /**
         * @brief Função que mostra a mensagem de erro
         * @details Essa função será chamada durante o laçamento da exceçaõ e irá retornar a
         * string _msgErro como um const char*
         * 
         * @return const char* : retorna a string _msgErro no formato pedido
         */
        const char* what () const noexcept override;
};

/**
 * @brief Classe para tratamentp de exceção
 * @details Essa classe é responsável pela exceção lançada quando o jogador digita uma entrada
 * inválida em manageAttacks() quando o narrador pergunta se ele quer o ataque ou não;
 * 
 */
class ExcecaoEntradaInvalida3 : public std::exception {

    private:
        std::string _msgErro;
    
    public:

        /**
         * @brief Construtor de um objeto ExcecaoEntradaInvalida3
         * @details Esse construtor não recebe parâmetros e inicializa o atributo _msgErro
         * 
         */
        ExcecaoEntradaInvalida3 ();

        /**
         * @brief Função que mostra a mensagem de erro
         * @details Essa função será chamada durante o laçamento da exceçaõ e irá retornar a
         * string _msgErro como um const char*
         * 
         * @return const char* : retorna a string _msgErro no formato pedido
         */
        const char* what () const noexcept override;
};

/**
 * @brief Classe para tratamentp de exceção
 * @details Essa exceção é usada quando alguem tenta pegar o valor do resultado do jogo sendo
 * que esse ainda não foi definido
 * 
 */
class ExcecaoResultadoNaoDefinido : public std::exception {

    private:

        std::string _msgErro;

    public:

        /**
         * @brief Construtor de um objeto ExcecaoResultadoNaoDefinido
         * @details Esse construtor não recebe parâmetros e inicializa o atributo _msgErro
         * 
         */
        ExcecaoResultadoNaoDefinido ();

        /**
         * @brief Função que mostra a mensagem de erro
         * @details Essa função será chamada durante o laçamento da exceçaõ e irá retornar a
         * string _msgErro como um const char*
         * 
         * @return const char* : retorna a string _msgErro no formato pedido
         */
        const char* what () const noexcept override;

};

#endif