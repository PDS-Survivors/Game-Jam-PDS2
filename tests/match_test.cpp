#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "match.hpp"
#include "../third_party/doctest.h"

TEST_CASE("Função setPlayer"){

    SUBCASE("Player Mago"){
        Match a;
        CHECK_NOTHROW(a.setPlayer(0));
    }

    SUBCASE("Player Mestre de Armas"){
        Match b;
        CHECK_NOTHROW(b.setPlayer(1));
    }
    
    SUBCASE("Player Druida"){
        Match c;
        CHECK_NOTHROW(c.setPlayer(2));
    }
    
    SUBCASE("Parametro inválido"){
        Match d, e;
        CHECK_THROWS(d.setPlayer(-1));
        CHECK_THROWS(e.setPlayer(3));
    }
    
    
}


TEST_CASE("Função chooseEvent"){
    CHECK(chooseEvent() < 17);
    CHECK(chooseEvent() >= 0);
}


TEST_CASE("Função doEvent"){
    SUBCASE("Parâmetro recebido = 0"){
        Match a;
        CHECK_EQ("Você estava indo de um predio a outro e estranhamente não aconteceu nada no caminho\n\n", a.doEvent(0));
    }

    SUBCASE("Parâmetro recebido = 1"){
        Match a;
        std::string event = "Você estava indo de um predio a outro e aconteceu algo muito estranho no caminho\n\n";
        event += "Professor indiano\n";
        event += "Apesar de estar indo bem em suas batalhas, uma coisa está tirando a sua paz,"; 
        event += "o ataque. Se você pelo menos conseguisse diminuir os atributos negativos ele seria perfeito."; 
        event += "Você passou em várias bibliotecas, pesquisou na internet e pediu ajuda aos professores e colegas, ";
        event += "mas ninguém conseguiu te ajudar. Você se cansou de procurar e abriu o youtube para ver edits aleatórios,";
        event += "mas ali estava ele, sua primeira recomendação foi um professor indiano falando exatamente sobre isso.";
        event += "Você assistiu todos os vídeos dele e finalmente conseguiu melhorar o ataque especial."; 
        event += "Obrigad@ professor indiano, você é meu herói.\n";
        event += "\nEfeitos:\n Multiplica dano do player por X permanentemente";
        CHECK_EQ(event, a.doEvent(1));
    }

    SUBCASE("Parâmetro recebido = 2"){
        Match a;
        std::string event = "Você estava indo de um predio a outro e aconteceu algo muito estranho no caminho\n\n";
        event += "Cuscuz\n";
        event += "Enquanto andava pelo campus feliz e orgulhos@ por ter vencido a batalha anterior";
        event += "você encontrou um simpático baiano. Ele te contou sobre sua terra natal e ";
        event += "como sentia saudades das comidas típicas dela. Você ficou muito curios@ ";
        event += "sobre o que ele estava falando e aceitou a oferta quando ele disse que cozinharia para você."; 
        event += " O prato feito foi cuscuz e você simplesmente amou. O baiano te deu o que sobrou do cuscuz, foi um almoço revitalizante!\n";
        CHECK_EQ(event, a.doEvent(2));
    }

    SUBCASE("Parâmetro recebido = 3"){
        Match a;
        std::string event = "Você estava indo de um predio a outro e aconteceu algo muito estranho no caminho\n\n";
        event += "Mano das pizzas\n";
        event += "\n\n";
        event += "\nEfeitos:\n";
        CHECK_EQ(event, a.doEvent(3));
    }

    SUBCASE("Parâmetro recebido = 4"){
        Match a;
        std::string event = "Você estava indo de um predio a outro e aconteceu algo muito estranho no caminho\n\n";
        event += "Machado\n";
        event += "\n\n";
        event += "\nEfeitos:\n";
        CHECK_EQ(event, a.doEvent(4));
    }

    SUBCASE("Parâmetro recebido = 5"){
        Match a;
        std::string event = "Você estava indo de um predio a outro e aconteceu algo muito estranho no caminho\n\n";
        event += "Cafex\n";
        event += "\n\n";
        event += "\nEfeitos:\n";
        CHECK_EQ(event, a.doEvent(5));
    }

    SUBCASE("Parâmetro recebido = 6"){
        Match a;
        std::string event = "Você estava indo de um predio a outro e aconteceu algo muito estranho no caminho\n\n";
        event += "Gatos da fafich\n";
        event += "\n\n";
        event += "\nEfeitos:\n";
        CHECK_EQ(event, a.doEvent(6));
    }

    SUBCASE("Parâmetro recebido = 7"){
        Match a;
        std::string event = "Você estava indo de um predio a outro e aconteceu algo muito estranho no caminho\n\n";
        event += "Os amigos que a gente faz pelo caminho\n";
        event += "\n\n";
        event += "\nEfeitos:\n";
        CHECK_EQ(event, a.doEvent(7));
    }

    SUBCASE("Parâmetro recebido = 8"){
        Match a;
        std::string event = "Você estava indo de um predio a outro e aconteceu algo muito estranho no caminho\n\n";
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
        CHECK_EQ(event, a.doEvent(8));
    }

    SUBCASE("Parâmetro recebido = 9"){
        Match a;
        std::string event = "Você estava indo de um predio a outro e aconteceu algo muito estranho no caminho\n\n";
        event += "Helder\n";
        event += "\n\n";
        event += "\nEfeitos:\n";
        CHECK_EQ(event, a.doEvent(9));
    }

    SUBCASE("Parâmetro recebido = 10"){
        Match a;
        std::string event = "Você estava indo de um predio a outro e aconteceu algo muito estranho no caminho\n\n";
        event += "Intoxicação alimentar\n";
        event += "Você fez uma pausa para comer no bandejão entre as batalhas para descansar, conversar sobre os"; 
        event += "monstros e recuperar as energias, mas a comida estava contaminada. Agora você está passando mal e seu";
        event += "maior medo é ficar longe de um banheiro.\n";
        event += "\nEfeitos:\n-Multiplica Vida por 0.75 em 3 batalhas.\n";
        event += "-Multiplica dano de Ataque1 por 0.5 em 2 batalhas.\n";
        event += "-Multiplica dano de Ataque2 por 0.5 em 2 batalhas.\n"; 
        event += "-Multiplica Defesa por 0.75 em 1 batalha.";
        CHECK_EQ(event, a.doEvent(10));
    }

    SUBCASE("Parâmetro recebido = 11"){
        Match a;
        std::string event = "Você estava indo de um predio a outro e aconteceu algo muito estranho no caminho\n\n";
        event += "Tropeçou na calçada\n";
        event += "\n\n";
        event += "\nEfeitos:\n";
        CHECK_EQ(event, a.doEvent(11));
    }

    SUBCASE("Parâmetro recebido = 12"){
        Match a;
        std::string event = "Você estava indo de um predio a outro e aconteceu algo muito estranho no caminho\n\n";
        event += "Semana de provas\n";
        event += "A semana de provas está chegando e você não estudou nada, pois estava ocupad@ derrotando diversas";
        event += "ameaças. Para não manchar o seu histórico com notas mais baixas ainda, você vira 3 noites seguidas estudando.";
        event += "Foram seções de estudo super produtivas!!! Você fechou uma das provas e ficou com mais de 80% nas outras duas,";
        event += "seus colegas de classe estão impressionados e seus parentes orgulhosos. Agora que a ansiedade e estresse passaram,"; 
        event += "você não tem mais energia para nada e sua imunidade está comprometida devido a falta de sono e excesso de energéticos.\n";
        event += "\nEfeitos:\n-Diminui 20 da Defesa permanentemente\n";
        event += "-Diminui 20 da Vida por 3 batalhas.";
        CHECK_EQ(event, a.doEvent(12));
    }

    SUBCASE("Parâmetro recebido = 13"){
        Match a;
        std::string event = "Você estava indo de um predio a outro e aconteceu algo muito estranho no caminho\n\n";
        event += "Crise existencial\n";
        event += "\n\n";
        event += "\nEfeitos:\n";
        CHECK_EQ(event, a.doEvent(13));
    }

    SUBCASE("Parâmetro recebido = 14"){
        Match a;
        std::string event = "Você estava indo de um predio a outro e aconteceu algo muito estranho no caminho\n\n";
        event += "Micos\n";
        event += "\n\n";
        event += "\nEfeitos:\n";
        CHECK_EQ(event, a.doEvent(14));
    }

    SUBCASE("Parâmetro recebido = 15"){
        Match a;
        std::string event = "Você estava indo de um predio a outro e aconteceu algo muito estranho no caminho\n\n";
        event += "Líquido estranho de cigarra\n";
        event += "\n\n";
        event += "\nEfeitos:\n";
        CHECK_EQ(event, a.doEvent(15));
    }

    SUBCASE("Parâmetro recebido = 16"){
        Match a;
        std::string event = "Você estava indo de um predio a outro e aconteceu algo muito estranho no caminho\n\n";
        event += "Atropelamento por bicicleta\n";
        event += "\n\n";
        event += "\nEfeitos:\n";
        CHECK_EQ(event, a.doEvent(16));
    }

    SUBCASE("Parâmetro recebido = 17"){
        Match a;
        std::string event = "Você estava indo de um predio a outro e aconteceu algo muito estranho no caminho\n\n";
        event += "Fila do bandejão\n";
        event += "\n\n";
        event += "\nEfeitos:\n";
        CHECK_EQ(event, a.doEvent(17));
    }

}


TEST_CASE("Função introducao"){
    std::string txt = "PROCURA-SE ESPECIALISTA DE ANOMALIAS\n\n";
    txt += "Nos últimos semestres um mal maior do que o corte de verbas tem assolado a UFMG:\no surgimento de anomalias nos mais diverios prédios da faculdade.\n\n";
    txt += "Elas tâm atrapalhado a vida de todos os estudantes e funcionários, de modo que é\nimpossível se dedicar completamente à tarefas e projetos importantes.\n\n";
    txt += "Temos sofrido com muitos casos reprovação, desaparecimento de pessoas e ataques de\npânico, a UFMG se encontra em crise.\n\n";
    txt += "Por isso estamos contratando um Especialista de Anomalias para resolver o problema.\nO cargo não possui muitos pré-requisitos: desde que você não desista fácil e consiga\nse adaptar a diversas situações no campus, acreditamos que está apto para ele.\n\n";
    txt += "O seu trabalho será encontrar e derrotar todas essas anomalias. Elas estão presentes\nnos 10 principais prédios da faculdade e algumas podem ser bem irritantes...\n\n";
    txt += "Sabemos o quanto essa tarefa é desafiadora e exaustiva, por isso, como forma de\npagamento, iremos providenciar para você um diploma oficial de nossa faculdade no curso\nde sua preferência. Não é maravilhoso poder se formar sem precisar estudar por cinco anos?\n\n";
    txt += "Precisamos muito de ajuda para conseguir resolver o problema. Por favor pense com\ncuidado sobre essa proposta.\n\n";
    txt += "Atenciosamente,\n";
    txt += "Membros desesperados da reitoria.\n\n";
    CHECK_EQ(event, introducao(17));
}


TEST_CASE("Função introducao2"){
    SUBCASE("Parametro recebido = s"){
        CHECK_EQ("Texto em construção, volte depois\n\n", introducao2(s));  
    }

    SUBCASE("Parametro recebido = n"){
        std::string txt = "De repende você sente alguém se aproximando por trás. Mas já é muito tarde,\na pessoa prende as suas mão atrás do corpo com uma corda aspera enquanto você se debate\nfreneticamente. Ela se afasta e logo em seguida vem a escuridão, ela colocou em saco\nde ... de pequi? no seu rosto.\n\n";
        txt += "Você é tirado de seu lugar e levado para fora. Outra pessoa se aproxima e te\njoga violentamente dentro de um carro, mas a a parte de cima da sua cabeça ababa batendo\nna lataria do carro e você desmaia...\n\n";
        txt += "'Nós avisamos para tomar cuidado com a resposta.' Você ouve uma voz falando\nrispidamente.\n\n";
        txt += "Aparentemente as mesmas pessoas que enviaram aquela oferta de emprego duvidosa\nagora estão diante de tu após um sequestro.\n\n";
        txt += "'Acontece que estamos realmente desesperados. Já pedimos para diversas pessoas\naceitarem o trabalho, mas a maioria descobriu o que aconteceu com os especialistas de\nanomalias anteriores e recusou a proposta... Não há mais tempo para procurar alguém\ne você era a pessoa mais fácil de sequestrar que achamos, caso recusasse a oferta.'\n\n";
        txt += "'Ahh' (Suspiro) 'Odeio ter que fazer isso.'\n\n";
        txt += "'Apesar das circunstâncias de nosso encontro não serem as ideias, ainda mantenho\na proposta de te dar um diploma ao derrotar todas as anomalias e...'\n\n";
        txt += "'Você quer saber o que aconteceu com os outros? Bem, isso não é muito importante\nno momento. Desde que você não seja derrotada mais do que 2 vezes vai ficar tudo bem.'\n\n";
        txt += "'Zeus! Olhe as horas, estou atrasado para uma reunião... Não precisa se preocupar,\nvocê tem cara se der inteligente. A UFMG precisa muito de você e cuidado com a reitoria...'\n\n";
        txt += "'Ah última coisa, preciso depois das suas informações para poder registrar você\noficialmente como noss@ funcionário/aluno. Vou deixar aqui um documento pra você \ncolocar suas informações. Boa sorte com tudo!'\n\n";
        
        CHECK_EQ(txt, introducao2(n));  
    }

    SUBCASE("Parâmetro inválido"){
        CHECK_THROWS(introducao2(a))
    }
    
}


TEST_CASE("Função getPlayerLifes"){
    Match a;
    CHECK(a.getPlayerLifes == 3);
}

