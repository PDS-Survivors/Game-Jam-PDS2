#include "match.hpp"
#include <iostream>

//Variável estática de battle que armazena número de batalhas perdidas
int Battle::_totalLoses = 0;

Match::Match(){};

void Match::setPlayer(int type){
    _player = new Pc(type);
}

void Match::playBuilding(){
    Building* building = _buildings.top();

    while (!(building->isComplete())){
        building->doBattle();
    }
       
}

void Match::setEpilogue(bool result){
    std::fstream epilogueFile;
    std::string epilogue = "";
    std::string line;
    epilogueFile.open("epilogue.txt", std::ios::in);
    if(!epilogueFile.is_open()){
        trow ExcecaoProblemasAoAbrirArquivo("epilogue.txt");
    }
    if(result){
        for(int i = 0; i < 4; i++){
            getline(epilogueFile, line);
            epilogue = epilogue + line + std::endl;
        }
    }else{
        epilogueFile.seekg("#");
    }
}
        
void Match::printEpilogue(){
    std::cout << _epilogue << std::endl;
}

int Match::getNumLifes(){
    return _numLifes;
}

void Match::died(){
    _numLifes -= 1;
}

int Match::chooseEvent(){
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

void Match::doEvent(){
        int n = chooseEvent();
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

ExcecaoProblemasAoAbrirArquivo::ExcecaoProblemasAoAbrirArquivo(std::string arquivo){
    _error = "Erro ao abrir o arquivo: " + arquivo + std::endl;
}

const char* what() const noexcept{
    return _error.c_str();
}