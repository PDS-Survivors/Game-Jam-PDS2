#include "match.hpp"
#include <iostream>

//Variável estática de battle que armazena número de batalhas perdidas
int Battle::_totalLoses = 0;

Match::Match(){
}

void Match::setPlayer(int type){
    if (type == 0) {
        //Construtor para mago
        _player = new Pc ("lib/pcs/mago.txt");
    }
    else if (type == 1) {
        //Construtor para mestre de armas
        _player = new Pc ();
    }
    else if (type == 2) {
        //Construtor para druida
        _player = new Pc ();
    }
    else {
        //Implementar lançamento de exceção
    }
    
}

void Match::playBuilding(){
    
    std::cout << "Você acabou de entrar em um novo prédio *0*\n\n";

    //Janela com o nome do prédio na interface
    std::cout << _buildings.top()->get_name();
    std::cout << _buildings.top()->get_desc();

    std::cout << "Prepard@ para enfrentear as anomalias desse prédio?\n\n";
    std::cout << "(s) Sim! Vamos acabar com isso logo\n(n) Calma aê, xô respirar antes\n";

    char c; std::cin >> c;

    if (c == 's'){
        while (!_buildings.top()->isComplete()) {
            _buildings.top()->doBattle();
            if (_numLifes == 0) { return; }
        }
    }
    else if (c == 'n'){
        std::cout << "No aguardo.\nPressione enter para voltar ao trabalho.\nNão demore!!!\n\n";
        do { 
            std::cin >> c; 
        }
        while ( c != ' ' );

        while (!_buildings.top()->isComplete()) {
            _buildings.top()->doBattle();
            if (_numLifes == 0) { return; }
        }
    }
    else {
        //Implementar tratamento de exceção
    }

    std::cout << "As anomalias do " << _buildings.top()->get_name() << "foram exterminadas!\n\n";
    std::cout << "Você está um prédio, mais próxim@ de seu diploma agora :D\n\n";

    _buildings.pop();
}

int Match::chooseEffect(){}

void Match::eventHappen(){}

//errado, essa função tem que receber alguma coisa, estava em duvida do que seria especificamente por isso não pus
//recebe o valor de total loses
void Match::setEpilogue (){
}

//getepilogue para ser usado pela interface
void Match::printEpilogue(int lifes){
    if (lifes = 0) {
        std::cout << "Que vida triste e sem diploma a sua...\n\n";

        //Arquivo com epílogo de derrota
        read::readtxt("");
    }
    else {
        std::cout << "Agora que você tem um diploma sua vida ira melhorar exponencialmente. Certo?\n\n";

        //Arquivo com epílogo de derrota
        read::readtxt("");
    }
}

int Match::getNumLifes(){
    return _numLifes;
}

void Match::died(){
    _numLifes -= 1;
}

int Match::choseEvent(){
    unsigned seed = time(0);
    srand(seed);

    int p = rand()%2;
    if(p == 0){
        int v = 1+rand()%17;  
        return v;

    } else{
        return 0;
    }
}

std::string Match::doEvent(int n){

        std::string event = {};
    if(n==0){
        event += "Você estava indo de um predio a outro e estranhamente não aconteceu nada no caminho\n\n";
    } else{
        
        event += "Você estava indo de um predio a outro e aconteceu algo muito estranho no caminho\n\n";

        switch (n){
        case 1:
        event += "Professor indiano\n";

        event += "Apesar de estar indo bem em suas batalhas, uma coisa está tirando a sua paz,"; 
        event += "o ataque. Se você pelo menos conseguisse diminuir os atributos negativos ele seria perfeito."; 
        event += "Você passou em várias bibliotecas, pesquisou na internet e pediu ajuda aos professores e colegas, ";
        event += "mas ninguém conseguiu te ajudar. Você se cansou de procurar e abriu o youtube para ver edits aleatórios,";
        event += "mas ali estava ele, sua primeira recomendação foi um professor indiano falando exatamente sobre isso.";
        event += "Você assistiu todos os vídeos dele e finalmente conseguiu melhorar o ataque especial."; 
        event += "Obrigad@ professor indiano, você é meu herói.\n";

        event += "\nEfeitos:\n Multiplica dano do player por X permanentemente";

        // alguma funçao que Aumente o dano produzido por pc em npc

        break;

        case 2:
        event += "Cuscuz\n";

        event += "Enquanto andava pelo campus feliz e orgulhos@ por ter vencido a batalha anterior";
        event += "você encontrou um simpático baiano. Ele te contou sobre sua terra natal e ";
        event += "como sentia saudades das comidas típicas dela. Você ficou muito curios@ ";
        event += "sobre o que ele estava falando e aceitou a oferta quando ele disse que cozinharia para você."; 
        event += " O prato feito foi cuscuz e você simplesmente amou. O baiano te deu o que sobrou do cuscuz, foi um almoço revitalizante!\n";
        
        event += "\nEfeitos:\n-Aumenta a vida maxima do player em X permanentemente";

        // alguma funçao que Aumente a totallife do player

        break;

        case 3:
        event += "Mano das pizzas\n";
        
        event += "\n\n";
        
        event += "\nEfeitos:\n";
        break;

        case 4:
        event += "Machado\n";
        
        event += "\n\n";
        
        event += "\nEfeitos:\n";
        break;

        case 5:
        event += "Cafex\n";
        
        event += "\n\n";
        
        event += "\nEfeitos:\n";
        break;

        case 6:
        event += "Gatos da fafich\n";
        
        event += "\n\n";
        
        event += "\nEfeitos:\n";
        break;

        case 7:
        event += "Os amigos que a gente faz pelo caminho\n";
        
        event += "\n\n";
        
        event += "\nEfeitos:\n";
        break;

        case 8:
        event += "Romance proibido\n";
        
        event += "Feliz por ter vencido mais uma batalha, você andava distraidamente pelo corredor, ";
        event += "pensando no diploma, sem conseguir ver nada do que estava acontecendo à sua volta. De repente, ";
        event += "você sente que trombou de cara com alguém! Você se afasta e olha para a pessoa, foi amor à primeira vista ";
        event += "<3 Aquela pessoa era seu antigo crush do terceiro ano da escola, quando você ainda estava na oitava série. ";
        event += "Imóvel, a única coisa que ficou fazendo foi encarar aquele ser ainda atordoado pelo encontro. Ele logo se ";
        event += " recuperou e lhe ofereceu a mão para levantar, insistindo para te levar para comer no ICEX como forma de ";
        event += " desculpas (embora a culpa fosse sua). Vocês começaram a conversar e descobriu que ele era um professor, ";
        event += " um dos mais temidos da faculdade, mas com você ele era a pessoa mais amável do mundo. Em pouquíssimo tempo ";
        event += " vocês ficaram próximos e ele pediu em namoro, com a única condição de não revelar para ninguém da faculdade."; 
        event += " Com isso vocês dois agora tem um romance proibido e namorar um professor tem suas vantagens.\n";
        
        event += "\nEfeitos:\n-Multiplica o reboot de stamina por 1,5.\n";
        event += "--Soma 15 a defesa permanentemente.";

        // alguma funçao que Aumente a defesa do player e Multiplica o reboot de stamina
        break;

        case 9:
        event += "Helder\n";
        
        event += "\n\n";
        
        event += "\nEfeitos:\n";
        break;

        case 10:
        event += "Intoxicação alimentar\n";
        
        event += "Você fez uma pausa para comer no bandejão entre as batalhas para descansar, conversar sobre os"; 
        event += "monstros e recuperar as energias, mas a comida estava contaminada. Agora você está passando mal e seu";
        event += "maior medo é ficar longe de um banheiro.\n";
        
        event += "\nEfeitos:\n-Multiplica Vida por 0.75 em 3 batalhas.\n";
        event += "-Multiplica dano de Ataque1 por 0.5 em 2 batalhas.\n";
        event += "-Multiplica dano de Ataque2 por 0.5 em 2 batalhas.\n"; 
        event += "-Multiplica Defesa por 0.75 em 1 batalha.";

        // alguma funçao que...
        break;

        case 11:
        event += "Tropeçou na calçada\n";
        
        event += "\n\n";
        
        event += "\nEfeitos:\n";
        break;

        case 12:
        event += "Semana de provas\n";
        
        event += "A semana de provas está chegando e você não estudou nada, pois estava ocupad@ derrotando diversas";
        event += "ameaças. Para não manchar o seu histórico com notas mais baixas ainda, você vira 3 noites seguidas estudando.";
        event += "Foram seções de estudo super produtivas!!! Você fechou uma das provas e ficou com mais de 80% nas outras duas,";
        event += "seus colegas de classe estão impressionados e seus parentes orgulhosos. Agora que a ansiedade e estresse passaram,"; 
        event += "você não tem mais energia para nada e sua imunidade está comprometida devido a falta de sono e excesso de energéticos.\n";
        
        event += "\nEfeitos:\n-Diminui 20 da Defesa permanentemente\n";
        event += "-Diminui 20 da Vida por 3 batalhas.";

        // alguma funçao que...
        break;

        case 13:
        event += "Crise existencial\n";
        
        event += "\n\n";
        
        event += "\nEfeitos:\n";
        break;

        case 14:
        event += "Micos\n";
        
        event += "\n\n";
        
        event += "\nEfeitos:\n";
        break;

        case 15:
        event += "Líquido estranho de cigarra\n";
        
        event += "\n\n";
        
        event += "\nEfeitos:\n";
        break;

        case 16:
        event += "Atropelamento por bicicleta\n";
        
        event += "\n\n";
        
        event += "\nEfeitos:\n";
        break;

        case 17:
        event += "Fila do bandejão\n";
        
        event += "\n\n";
        
        event += "\nEfeitos:\n";
        break;
        }
    }
    return event;
}

std::string introducao(){
    //Substituir por leitura de arquivo futuramente
    std::string txt {};

    txt += "PROCURA-SE ESPECIALISTA DE ANOMALIAS\n\n";
    txt += "Nos últimos semestres um mal maior do que o corte de verbas tem assolado a UFMG: o surgimento de anomalias nos mais diverios prédios da faculdade.\n";
    txt += "Elas tâm atrapalhado a vida de todos os estudantes e funcionários, de modo que é impossível se dedicar completamente à tarefas e projetos importantes.\n";
    txt += "Temos sofrido com muitos casos reprovação, desaparecimento de pessoas e ataques de pânico, a UFMG se encontra em crise.\n";
    txt += "Por isso estamos contratando um Especialista de Anomalias para resolver o problema. O cargo não possui muitos pré-requisitos: desde que você não desista fácil e consiga se adaptar a diversas situações no campus, acreditamos que está apto para ele.\n";
    txt += "O seu trabalho será encontrar e derrotar todas essas anomalias. Elas estão presentes nos 10 principais prédios da faculdade e algumas podem ser bem irritantes...\n";
    txt += "Sabemos o quanto essa tarefa é desafiadora e exaustiva, por isso, como forma de pagamento, iremos providenciar para você um diploma oficial de nossa faculdade no curso de sua preferência. Não é maravilhoso poder se formar sem precisar estudar por cinco anos?\n";
    txt += "Precisamos muito de ajuda para conseguir resolver o problema. Por favor pense com cuidado sobre essa proposta.\n\n";
    txt += "Atenciosamente,\n";
    txt += "Membros desesperados da reitoria.\n\n";

    return txt;
}

std::string introducao2(bool op){
    //Substituir por leitura de arquivo futuramente
    std::string txt {};

    if (op){
        txt += "Texto em construção, volte depois\n\n";
    }
    else {
        txt += "De repende você sente alguém se aproximando por trás. Mas já é muito tarde, a pessoa prende as suas mão atrás do corpo com uma corda aspera enquanto você se debate freneticamente. Ela se afasta e logo em seguida vem a escuridão, ela colocou em saco de ... de pequi? no seu rosto.\n";
        txt += "Você é tirado de seu lugar e levado para fora. Outra pessoa se aproxima e te joga violentamente dentro de um carro, mas a a parte de cima da sua cabeça ababa batendo na lataria do carro e você desmaia...\n";
        txt += "'Nós avisamos para tomar cuidado com a resposta.' Você ouve uma voz falando rispidamente.\n";
        txt += "Aparentemente as mesmas pessoas que enviaram aquela oferta de emprego duvidosa agora estão diante de tu após um sequestro.\n";
        txt += "'Acontece que estamos realmente desesperados. Já pedimos para diversas pessoas aceitarem o trabalho, mas a maioria descobriu o que aconteceu com os especialistas de anomalias anteriores e recusou a proposta... Não há mais tempo para procurar alguém e você era a pessoa mais fácil de sequestrar que achamos, caso recusasse a oferta.'\n";
        txt += "'Ahh' (Suspiro) 'Odeio ter que fazer isso.'\n";
        txt += "'Apesar das circunstâncias de nosso encontro não serem as ideias, ainda mantenho a proposta de te dar um diploma ao derrotar todas as anomalias e...'\n";
        txt += "'Você quer saber o que aconteceu com os outros? Bem, isso não é muito importante no momento. Desde que você não seja derrotada mais do que 2 vezes vai ficar tudo bem.'\n";
        txt += "'Zeus! Olhe as horas, estou atrasado para uma reunião... Não precisa se preocupar, você tem cara se der inteligente. A UFMG precisa muito de você e cuidado com a reitoria...'\n";
        txt += "'Ah última coisa, preciso depois das suas informações para poder registrar você oficialmente como noss@ funcionário/aluno. Vou deixar aqui um documento pra você colocar suas informações. Boa sorte com tudo!'\n\n";
    }

    return txt;
}

bool Match::end () {
    return _buildings.empty();
}