#include "match.hpp"

Match::Match () {}

Match::~Match(){

    // delete _player;
        
    // while(!_buildings.empty()){
    //     delete (_buildings.top());
    // }

    // while(!_permanentEffects.empty()){
    //     delete (_permanentEffects.back());
    // }

}

int Match::getPlayerLifes (){
    return _player->getNumLifes();
}

std::string Match::getEpilogue(){
    return _epilogue;
}

void Match::setPlayer(int type){
    if (type == 0) {
        //Construtor para mago
        _player = new Pc ("lib/pcs/mago.txt");
    }
    else if (type == 1) {
        //Construtor para mestre de armas
        _player = new Pc ("");
    }
    else if (type == 2) {
        //Construtor para druida
        _player = new Pc ("");
    }
    else {
        throw std::invalid_argument("Não existe um personagem que corresponda a esse número");
    }
    
}

Pc* Match::getPlayer(){
    return _player;
}

//Monta uma pilha de prédios de acordo com sua ordem em um arquivo
//Obs:: O último prédio do percurso é o primeiro do arquivo
void Match::setBuildingStack () {

    int numBuildings;

    std::vector<std::string> words;
    std::vector<std::string> files;
    std::vector<int> values;

    reader::readfile (_match, values, words, files);

    //Número de prédios que a partida terá
    numBuildings = values[0];

    for (int i = 0; i < numBuildings; i++){
        Building* build = new Building (_player, files[i]);
        _buildings.emplace(build);
    }
}

std::stack<Building*>* Match::getBuildingStack(){
    return &_buildings;
}

void Match::chooseMatch () {

    std::vector<std::string> words;
    std::vector<std::string> files;
    std::vector<int> values;

    reader::readfile ("lib/matches/All.txt", values, words, files);

    std::cout << "== Selecione uma partida para começar sua aventura *.*\n\n";

    reader::wait(2);

    std::cout << "(0) : Entrada Carlos Luz\n";
    std::cout << "(1) : Entrada Antônio Carlos\n";
    std::cout << "(x) em breve mais opções...\n\n";

    bool cond = true;

    do 
    {
        char op;
        std::cin >> op;

        switch (op)
        {
            case '0' : _match = files[0]; cond = false; break;
            case '1' : std::cout << "Em construção, escolhe outro :D\n"; break;
            default : std::cout << "Escreva uma entrada válida para continuar\n"; break;
        }
    }
    while (cond);
}

void Match::playBuilding() {
    
    std::cout << "\nVocê acabou de entrar em um novo prédio *0*\n\n";

    //Janela com o nome do prédio na interface
    std::cout << "========================================================================================\n\n";
    std::cout << "                           Prédio " << _buildings.top()->get_number();
    std::cout << ": " << _buildings.top()->get_name() << "\n\n";
    std::cout << "== " << _buildings.top()->get_desc() << "\n\n";

    std::cout << "Prepard@ para enfrentear as anomalias desse prédio?\n\n";
    std::cout << "(s) Sim! Vamos acabar com isso logo\n(n) Calma aê, xô respirar antes\n";

    char c; std::cin >> c;

    if (c == 's'){
        while (!_buildings.top()->isComplete()) {
            _buildings.top()->doBattle();
            if (_player->getNumLifes() == 0) { break; }
        }
    }
    else if (c == 'n'){
        std::cout << "\nNo aguardo.\nPressione enter para voltar ao trabalho.\nNão demore!!!\n\n";
        getchar();
        getchar();

        while (!_buildings.top()->isComplete()) {
            _buildings.top()->doBattle();
            if (_player->getNumLifes() == 0) { break; }
        }
    }
    else {
        //Implementar tratamento de exceção
    }

    if (_player->getNumLifes() == 0){
        std::cout << "As anomalias do " << _buildings.top()->get_name() << " foram mais fortes do que você!\n\n";
        std::cout << "Diga adeus ao seu diploma.\n\n";
        std::cout << "Se você continuar desse jeito não sei o que será do seu futuro.\n\n";

        reader::wait(2);

        std::cout << "Melhore\n\n";

        reader::wait(2);
    }
    else {
        std::cout << "As anomalias do " << _buildings.top()->get_name() << " foram exterminadas!\n\n";
        std::cout << "Você está um prédio, mais próxim@ de seu diploma agora :D\n\n";

        reader::wait(2);
    }
    
    _buildings.pop();
}

void Match::printEpilogue(){
    if (_player->getNumLifes() == 0) {
        std::cout << "Que vida triste e sem diploma a sua...\n\n";

        //Arquivo com epílogo de derrota
        reader::readtxt("");
    }
    else {
        std::cout << "Agora que você tem um diploma sua vida ira melhorar exponencialmente. Certo?\n\n";

        //Arquivo com epílogo de derrota
        reader::readtxt("");
    }
}

std::string Match::introducao(){
    //Substituir por leitura de arquivo futuramente
    std::string txt {};

    txt += "PROCURA-SE ESPECIALISTA DE ANOMALIAS\n\n";
    txt += "Nos últimos semestres um mal maior do que o corte de verbas tem assolado a UFMG:\no surgimento de anomalias nos mais diverios prédios da faculdade.\n\n";
    txt += "Elas tâm atrapalhado a vida de todos os estudantes e funcionários, de modo que é\nimpossível se dedicar completamente à tarefas e projetos importantes.\n\n";
    txt += "Temos sofrido com muitos casos reprovação, desaparecimento de pessoas e ataques de\npânico, a UFMG se encontra em crise.\n\n";
    txt += "Por isso estamos contratando um Especialista de Anomalias para resolver o problema.\nO cargo não possui muitos pré-requisitos: desde que você não desista fácil e consiga\nse adaptar a diversas situações no campus, acreditamos que está apto para ele.\n\n";
    txt += "O seu trabalho será encontrar e derrotar todas essas anomalias. Elas estão presentes\nnos 10 principais prédios da faculdade e algumas podem ser bem irritantes...\n\n";
    txt += "Sabemos o quanto essa tarefa é desafiadora e exaustiva, por isso, como forma de\npagamento, iremos providenciar para você um diploma oficial de nossa faculdade no curso\nde sua preferência. Não é maravilhoso poder se formar sem precisar estudar por cinco anos?\n\n";
    txt += "Precisamos muito de ajuda para conseguir resolver o problema. Por favor pense com\ncuidado sobre essa proposta.\n\n";
    txt += "Atenciosamente,\n";
    txt += "Membros desesperados da reitoria.\n\n";

    return txt;
}

std::string Match::introducao2(char op){
    //Substituir por leitura de arquivo futuramente
    std::string txt {};

    if (op == 's'){
        txt += "Texto em construção, volte depois\n\n";
    }
    else if (op == 'n') {
        txt += "De repende você sente alguém se aproximando por trás. Mas já é muito tarde,\na pessoa prende as suas mão atrás do corpo com uma corda aspera enquanto você se debate\nfreneticamente. Ela se afasta e logo em seguida vem a escuridão, ela colocou em saco\nde ... de pequi? no seu rosto.\n\n";
        txt += "Você é tirado de seu lugar e levado para fora. Outra pessoa se aproxima e te\njoga violentamente dentro de um carro, mas a a parte de cima da sua cabeça ababa batendo\nna lataria do carro e você desmaia...\n\n";
        txt += "'Nós avisamos para tomar cuidado com a resposta.' Você ouve uma voz falando\nrispidamente.\n\n";
        txt += "Aparentemente as mesmas pessoas que enviaram aquela oferta de emprego duvidosa\nagora estão diante de tu após um sequestro.\n\n";
        txt += "'Acontece que estamos realmente desesperados. Já pedimos para diversas pessoas\naceitarem o trabalho, mas a maioria descobriu o que aconteceu com os especialistas de\nanomalias anteriores e recusou a proposta... Não há mais tempo para procurar alguém\ne você era a pessoa mais fácil de sequestrar que achamos, caso recusasse a oferta.'\n\n";
        txt += "'Ahh' (Suspiro) 'Odeio ter que fazer isso.'\n\n";
        txt += "'Apesar das circunstâncias de nosso encontro não serem as ideias, ainda mantenho\na proposta de te dar um diploma ao derrotar todas as anomalias e...'\n\n";
        txt += "'Você quer saber o que aconteceu com os outros? Bem, isso não é muito importante\nno momento. Desde que você não seja derrotada mais do que 2 vezes vai ficar tudo bem.'\n\n";
        txt += "'Zeus! Olhe as horas, estou atrasado para uma reunião... Não precisa se preocupar,\nvocê tem cara se der inteligente. A UFMG precisa muito de você e cuidado com a reitoria...'\n\n";
        txt += "'Ah última coisa, preciso depois das suas informações para poder registrar você\noficialmente como noss@ funcionário/aluno. Vou deixar aqui um documento pra você \ncolocar suas informações. Boa sorte com tudo!'\n\n";
    }
    else {
        //Implementar tratamento de exceção
    }

    return txt;
}

bool Match::end () {
    return _buildings.empty();
}

int Match::chooseEvent(){
    unsigned seed = time(0);
    srand(seed);

    int p = rand()%2;
    if(p == 0){
        int v = 1+rand()%18;  
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
            if(_alreadyHappened[1] == 0){
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

                _alreadyHappened[1] = 1;

                break;
            }

        case 2:
            if(_alreadyHappened[2] == 0){
                event += "Cuscuz\n";

                event += "Enquanto andava pelo campus feliz e orgulhos@ por ter vencido a batalha anterior";
                event += "você encontrou um simpático baiano. Ele te contou sobre sua terra natal e ";
                event += "como sentia saudades das comidas típicas dela. Você ficou muito curios@ ";
                event += "sobre o que ele estava falando e aceitou a oferta quando ele disse que cozinharia para você."; 
                event += " O prato feito foi cuscuz e você simplesmente amou. O baiano te deu o que sobrou do cuscuz, foi um almoço revitalizante!\n";
        
                event += "\nEfeitos:\n-Aumenta a vida maxima do player em X permanentemente";

                // alguma funçao que Aumente a totallife do player

                _alreadyHappened[2] = 1;

                break;    
            }
        

        case 3:
            if(_alreadyHappened[3] == 0){
                event += "Mano das pizzas\n";
        
                event += "\n\n";
        
                event += "\nEfeitos:\n";

                // alguma funçao que...

                _alreadyHappened[3] = 1;

                break;    
            }
        

        case 4:
            if(_alreadyHappened[4] == 0){
                event += "Machado\n";
        
                event += "\n\n";
        
                event += "\nEfeitos:\n";

                // alguma funçao que...

                _alreadyHappened[4] = 1;

                break;    
            }
        

        case 5:
            if(_alreadyHappened[5] == 0){
                event += "Cafex\n";
        
                event += "\n\n";
        
                event += "\nEfeitos:\n";

                // alguma funçao que...

                _alreadyHappened[5] = 1;

                break;
            }
        

        case 6:
            if(_alreadyHappened[6] == 0){
                event += "Gatos da fafich\n";
        
                event += "\n\n";
        
                event += "\nEfeitos:\n";
                
                // alguma funçao que...

                _alreadyHappened[6] = 1;

                break;
            }
        

        case 7:
            if(_alreadyHappened[7] == 0){
                event += "Os amigos que a gente faz pelo caminho\n";
        
                event += "\n\n";
        
                event += "\nEfeitos:\n";

                // alguma funçao que...

                _alreadyHappened[7] = 1;

                break;
            }
        

        case 8:
            if(_alreadyHappened[8] == 0){
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

                _alreadyHappened[8] = 1;

                break;    
            }
        

        case 9:
            if(_alreadyHappened[9] == 0){
                event += "Helder\n";
        
                event += "\n\n";
        
                event += "\nEfeitos:\n";

                // alguma funçao que...

                _alreadyHappened[9] = 1;

                break;    
            }
        

        case 10:
            if(_alreadyHappened[10] == 0){
                event += "Intoxicação alimentar\n";
        
                event += "Você fez uma pausa para comer no bandejão entre as batalhas para descansar, conversar sobre os"; 
                event += "monstros e recuperar as energias, mas a comida estava contaminada. Agora você está passando mal e seu";
                event += "maior medo é ficar longe de um banheiro.\n";
        
                event += "\nEfeitos:\n-Multiplica Vida por 0.75 em 3 batalhas.\n";
                event += "-Multiplica dano de Ataque1 por 0.5 em 2 batalhas.\n";
                event += "-Multiplica dano de Ataque2 por 0.5 em 2 batalhas.\n"; 
                event += "-Multiplica Defesa por 0.75 em 1 batalha.";

                // alguma funçao que...

                _alreadyHappened[10] = 1;

                break;
            }
        

        case 11:
            if(_alreadyHappened[11] == 0){
                event += "Tropeçou na calçada\n";
        
                event += "\n\n";
        
                event += "\nEfeitos:\n";

                // alguma funçao que...

                _alreadyHappened[11] = 1;

                break;
            }
        

        case 12:
            if(_alreadyHappened[12] == 0){
                event += "Semana de provas\n";
        
                event += "A semana de provas está chegando e você não estudou nada, pois estava ocupad@ derrotando diversas";
                event += "ameaças. Para não manchar o seu histórico com notas mais baixas ainda, você vira 3 noites seguidas estudando.";
                event += "Foram seções de estudo super produtivas!!! Você fechou uma das provas e ficou com mais de 80% nas outras duas,";
                event += "seus colegas de classe estão impressionados e seus parentes orgulhosos. Agora que a ansiedade e estresse passaram,"; 
                event += "você não tem mais energia para nada e sua imunidade está comprometida devido a falta de sono e excesso de energéticos.\n";
        
                event += "\nEfeitos:\n-Diminui 20 da Defesa permanentemente\n";
                event += "-Diminui 20 da Vida por 3 batalhas.";

                // alguma funçao que...

                _alreadyHappened[12] = 1;

                break;
            }
        
        case 13:
            if(_alreadyHappened[13] == 0){
                event += "Crise existencial\n";
        
                event += "\n\n";
        
                event += "\nEfeitos:\n";

                // alguma funçao que...

                _alreadyHappened[13] = 1;

                break;
            }   
        
        case 14:
            if(_alreadyHappened[14] == 0){
                event += "Micos\n";
        
                event += "\n\n";
        
                event += "\nEfeitos:\n";

                // alguma funçao que...

                _alreadyHappened[14] = 1;

                break;
            }
        
        case 15:
            if(_alreadyHappened[15] == 0){
                event += "Líquido estranho de cigarra\n";
        
                event += "\n\n";
        
                event += "\nEfeitos:\n";

                // alguma funçao que...

                _alreadyHappened[15] = 1;

                break;
            }
       
        case 16:
            if(_alreadyHappened[16] == 0){
                event += "Atropelamento por bicicleta\n";
        
                event += "\n\n";
        
                event += "\nEfeitos:\n";

                // alguma funçao que...

                _alreadyHappened[16] = 1;

                break;
            }
        

        case 17:
            if(_alreadyHappened[17] == 0){
                event += "Fila do bandejão\n";
        
                event += "\n\n";
        
                event += "\nEfeitos:\n";

                // alguma funçao que...

                _alreadyHappened[17] = 1;

                break;
            }
        
        }
    }
    return event;
}