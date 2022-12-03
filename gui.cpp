#include "raylib.h"
#include "raymath.h"
#include <string>
#include <vector>   

#include <math.h>       // Required for:

#if defined(PLATFORM_WEB)
    #include <emscripten/emscripten.h>
#endif

#define T_BLANK (Color){ 10, 10, 10, 200}

typedef enum {TITLE, CHARACTERS, CREDITS, BIO, INTRO, SIM, NAO, STORY, ENCOUNTER1, BATTLE1, APROVADO1, REPROVADO1, ENCOUNTER2, BATTLE2, ENCOUNTER3, BATTLE3, ENDING } GameScreen;
typedef enum {mage, master, druid} CharacterClass;

static const int screenWidth = 1280;
static const int screenHeight = 720;

// Game general variables
static int currentScreen = TITLE;
static int character = mage;
static int elementPositionY = -128;
static int framesCounter = 0;
static int scrollingY = 0;
static int score = 0;
static int hiscore = 0;
static int titleState = 0;
static int optionSelect = 0;       // Main menu option selection
int i = 0, j = 0, k = 0;

int pcvida, pcvidamax, pcestamina, pcestaminamax, pcdef, pcdefmax;
int npcvida, npcvidamax, npcestamina, npcestaminamax;
std::string desc;
std::string tipo;
std::string ataque2;
std::string ataque1;
std::string ataque;

static bool exitGame = false;
static bool act = false;
static bool decision = false;

static int stepFrameCount = 0;

std::string string;

// IMAGENS
static Texture2D texTitle = { 0 };
static Texture2D texBar = { 0 };
static Texture2D battleBar = { 0 };
static Texture2D background = { 0 };
static Texture2D druidPic = { 0 };
static Texture2D bdruidPic = { 0 };
static Texture2D warriorPic = { 0 };
static Texture2D magePic = { 0 };
static Texture2D back1 = { 0 };
static Texture2D pintura = { 0 };
static Texture2D bmasterPic = {0};
Texture2D charac_pic;

// FONTES
static Font font = { 0 };
static Font base = { 0 };

// AUDIOS

static Model model = { 0 };

// Render texture to draw full screen, enables screen scaling
static RenderTexture2D screenTarget = { 0 };

static void UpdateDrawFrame(void);              // Update and Draw one frame
std::vector<std::string> tramontina(std::string a); //corta string e coloca em vetor

int main()
{

    SetConfigFlags(FLAG_MSAA_4X_HINT | FLAG_WINDOW_TRANSPARENT);
    InitWindow(screenWidth, screenHeight, "Escape from UFMG");

    // carrega fotos
    texTitle = LoadTexture("resources/interface/title.png");
    texBar = LoadTexture("resources/interface/barra_texto.png");
    battleBar = LoadTexture("resources/interface/barra_acao.png");
    background = LoadTexture("resources/background/arena.png");
    bdruidPic = LoadTexture("resources/pc/druida2.png");
    druidPic = LoadTexture("resources/pc/druida.png");
    warriorPic = LoadTexture("resources/pc/chuvas.png");
    magePic = LoadTexture("resources/pc/mago.png");
    back1 = LoadTexture("resources/background/fundo1.png");
    pintura = LoadTexture("resources/npc/pintura.png");
    bmasterPic = LoadTexture("resources/pc/chuvas2.png");

    // carrega fontes
    font = LoadFont("resources/interface/alpha_beta.png");

    // carrega audios

    screenTarget = LoadRenderTexture(1280, 720);
    SetTextureFilter(screenTarget.texture, TEXTURE_FILTER_BILINEAR);

#if defined(PLATFORM_WEB)
    emscripten_set_main_loop(UpdateDrawFrame, 60, 1);
#else
    SetTargetFPS(60);   

    while (!WindowShouldClose() && !exitGame)    
    {
        UpdateDrawFrame();
    }
#endif

    CloseWindow();                  

    return 0;
}

static void UpdateDrawFrame(void)
{
    switch (currentScreen)
    {
        case TITLE:
        {
            framesCounter++;

            if (IsKeyPressed(KEY_DOWN))
            {
                optionSelect++;
            }
            else if (IsKeyPressed(KEY_UP))
            {
                optionSelect--;
            }

            if (optionSelect < 0) optionSelect = 2;
            else if (optionSelect > 2) optionSelect = 0;

            if (IsKeyPressed(KEY_ENTER))
            {
                if (optionSelect == 0)
                {
                    //currentScreen = CHARACTERS;        // Gameplay screen
                    currentScreen = INTRO;
                }
                else if (optionSelect == 1)
                {
                    currentScreen = CREDITS;    // Credits screen
                }
                else if (optionSelect == 2) exitGame = true;            // Exit game

                framesCounter = 0;
            }

        } break;
        case INTRO:
        {
            if (decision == false)
            {
                if (IsKeyPressed(KEY_ENTER)) //pulas os textos
                {
                   i++;  
                } 
                else if (IsKeyPressed(KEY_ENTER) && string[sizeof(string)] == '&') //pulas os textos
                {
                    decision = true;    
                }
            }    
            else if (decision == true)
            {
                i = 1;
                if (IsKeyPressed(KEY_RIGHT))
                {
                    optionSelect++;
                }
                else if (IsKeyPressed(KEY_LEFT))
                {
                    optionSelect--;
                }

                if (optionSelect < 0) optionSelect = 1;
                else if (optionSelect > 1) optionSelect = 0;

                if (IsKeyPressed(KEY_ENTER))
                {
                    if (optionSelect == 0)
                    {
                        //aceita a decisao
                        currentScreen = SIM;
                        decision = false;
                    }
                    else if (optionSelect == 1)
                    {
                        //nega a decisao 
                        currentScreen = NAO; 
                        decision = false;
                    }
                }   
            }
        } break;  
        case SIM:
            {
                if (decision == false)
                {
                    if (IsKeyPressed(KEY_ENTER)) //pulas os textos
                    {
                    i++;  
                    } 
                }    
                else if (decision == true)
                {
                    i = 0;
                    currentScreen = CHARACTERS; 
                    decision = false;
                }
            } break;
            case NAO:
            {
                if (decision == false)
                {
                    if (IsKeyPressed(KEY_ENTER)) //pulas os textos
                    {
                    i++;  
                    } 
                }    
                else if (decision == true)
                {
                    i = 0;
                    currentScreen = CHARACTERS; 
                    decision = false;
                }
            } break;
        case CHARACTERS:
        {
            framesCounter++;

            if (IsKeyPressed(KEY_RIGHT))
            {
                optionSelect++;
            }
            else if (IsKeyPressed(KEY_LEFT))
            {
                optionSelect--;
            }

            if (optionSelect < 0) optionSelect = 3;
            else if (optionSelect > 3) optionSelect = 0;

            if (IsKeyPressed(KEY_ENTER))
            {
                if (optionSelect == 0)
                {
                    currentScreen = BIO;   
                    character = mage;     
                }
                else if (optionSelect == 1)
                {
                    currentScreen = BIO;
                    character = master;   
                }
                else if (optionSelect == 2)
                {
                    currentScreen = BIO;  
                    character = druid;  
                }
                else if (optionSelect == 3)
                {
                    currentScreen = TITLE;
                }

                framesCounter = 0;
            }
            //batongas
        } break;
        case BIO:
        {
            framesCounter++;
            if(character == mage) charac_pic = magePic;
            else if(character == master) charac_pic = warriorPic;
            else if(character == druid) charac_pic = druidPic;

            if(character == mage) 
            {
                pcvida = pcvidamax = 50, pcestamina = pcestaminamax = 5, pcdef = pcdefmax = 60;
                desc = "Não é mágica, é matemática!";
                tipo = "(Exatas/TI)";
                ataque1 = "Vetores";
                ataque2 = "Raio de Derivadas Infinitas";

            }else if(character == master) 
            {
                pcvida = pcvidamax = 40, pcestamina = pcestaminamax = 5, pcdef = pcdefmax = 70;
                desc = "Levantar a voz não vence uma língua afiada.";
                tipo = "(Humanas/Linguagens)";
                ataque1 = "Livrada";
                ataque2 = "Estilingue de Traumas";
            }else if(character == druid) 
            {
                pcvida = pcvidamax = 60, pcestamina = pcestaminamax = 5, pcdef = pcdefmax = 40;
                desc = "Altos contatos com a natureza.";
                tipo = "(Biológicas)";
                ataque1 = "Bisturi infectada";
                ataque2 = "Mini Golens de Melancia";
            }

            if (IsKeyPressed(KEY_RIGHT))
            {
                optionSelect++;
            }
            else if (IsKeyPressed(KEY_LEFT))
            {
                optionSelect--;
            }

            if (optionSelect < 0) optionSelect = 1;
            else if (optionSelect > 1) optionSelect = 0;

            if (IsKeyPressed(KEY_ENTER))
            {
                if (optionSelect == 0)
                { 
                    currentScreen = STORY;     
                }
                else if (optionSelect == 1)
                {
                    currentScreen = CHARACTERS;   
                }
            }   
        } break;  
        case STORY:
        {
            if (decision == false)
                {
                    if (IsKeyPressed(KEY_ENTER)) //pulas os textos
                    {
                    i++;  
                    } 
                }    
                else if (decision == true)
                {
                    i = 0;
                    currentScreen = ENCOUNTER1;
                    decision = false; 
                }
        } break;
        case ENCOUNTER1:
        {
            if (decision == false)
                {
                    if (IsKeyPressed(KEY_ENTER)) //pulas os textos
                    {
                    i++;  
                    } 
                }    
                else if (decision == true)
                {
                    i = 0;
                    currentScreen = BATTLE1;
                    decision = false; 
                    act = false;
                    npcvida = npcvidamax = 60;
                }
        } break;
        case BATTLE1:
        {
            if(npcvida <= 0) 
            {
                k = 1;
                decision = 1;
            }    
            else if(pcvida <= 0) 
            {
                k = 2;
                decision = 1;
            }

            if(act == false)
            {
                if (IsKeyPressed(KEY_ENTER)) //pulas os textos
                {
                    i++; 
                    if (decision == true) j++;   
                } 
            }
            else if(act == true)
            {
                if (IsKeyPressed(KEY_RIGHT))
                {
                    optionSelect++;
                }
                else if (IsKeyPressed(KEY_LEFT))
                {
                    optionSelect--;
                }
                if (IsKeyPressed(KEY_DOWN))
                {
                    optionSelect+=2;
                }
                else if (IsKeyPressed(KEY_UP))
                {
                    optionSelect-=2;
                }
                if (optionSelect < 0) optionSelect = 3;
                else if (optionSelect > 3) optionSelect = 0;
                if (IsKeyPressed(KEY_ENTER)) //CHAMA A FUNÇÃO DE ATAQUE
                {
                    if (optionSelect == 0)
                    {                        
                        ataque = ataque1;
                        npcvida = npcvida - 25;
                        pcvida = pcvida - 15;
                        pcestamina -= 2;
                        act = false;
                    }
                    else if (optionSelect == 1)
                    {
                        ataque = ataque2;
                        npcvida = npcvida - 35;
                        pcvida = pcvida - 15;
                        pcestamina -= 3;
                        act = false;
                    }
                    else if (optionSelect == 2 || optionSelect == 3 )
                    {
                        ataque = "Você não fez nada";
                        pcestamina = 5;
                        pcvida = pcvida - 15;
                        act = false;
                    }
                    act = false;
                } 
            }
        } break; 
        case APROVADO1:
        {
            if (decision == false)
                {
                    if (IsKeyPressed(KEY_ENTER)) //pulas os textos
                    {
                    i++;  
                    } 
                }    
                else if (decision == true)
                {
                    i = 0;
                    currentScreen = ENCOUNTER2;
                }
        } break;
        case REPROVADO1:
        {
            if (decision == false)
                {
                    if (IsKeyPressed(KEY_ENTER)) //pulas os textos
                    {
                    i++;  
                    } 
                }    
                else if (decision == true)
                {
                    if (IsKeyPressed(KEY_RIGHT))
                    {
                        optionSelect++;
                    }
                    else if (IsKeyPressed(KEY_LEFT))
                    {
                        optionSelect--;
                    }

                    if (optionSelect < 0) optionSelect = 1;
                    else if (optionSelect > 1) optionSelect = 0;

                    if (IsKeyPressed(KEY_ENTER))
                    {
                        if (optionSelect == 0)
                        {
                            //aceita a decisao
                            currentScreen = BATTLE1;
                            decision = false;
                        }
                        else if (optionSelect == 1)
                        {
                            exitGame = true;
                        }
                    }   
                }
        } break;
        case CREDITS:
        {
            //batongas
        } break;
        case ENDING:
        {
            if (IsKeyPressed(KEY_ENTER))
            {
                currentScreen = CREDITS;
                titleState = 0;
                framesCounter = 0;
            }

        } break;
        default: break;
    }


    BeginTextureMode(screenTarget);
        ClearBackground(BLACK);

        switch (currentScreen)
        {
            case TITLE:
            {
                DrawTexture(texTitle, 215, 120, WHITE);
                DrawRectangle(480, 400 + optionSelect*80, 320, 80, SKYBLUE);
                DrawTextEx(font, "COMECAR", (Vector2){ 512, 412 }, 60, 4, (optionSelect == 0)? BLUE : SKYBLUE);
                DrawTextEx(font, "CREDITOS", (Vector2){ 506, 412 + 80 }, 60, 4, (optionSelect == 1)? BLUE : SKYBLUE);
                DrawTextEx(font, "SAIR", (Vector2){ 574, 412 + 160 }, 60, 4, (optionSelect == 2)? BLUE : SKYBLUE);
            } break;
            case INTRO:
            {
                if (decision == false) 
                {
                    DrawRectangle(0, 0, 1280, 720, BLACK);
                    if (i>0) DrawTextEx(base, "PROCURA-SE ESPECIALISTA DE ANOMALIAS", (Vector2){80, 70}, 20, 4, WHITE);
                    if (i>1) DrawTextEx(base, "Nos últimos semestres um mal maior do que o corte de verbas tem assolado a UFMG: o surgi-", (Vector2){80,100}, 20, 4, WHITE);
                    if (i>2) DrawTextEx(base, "mento de anomalias nos mais diversos prédios da faculdade.", (Vector2){80,120}, 20, 4, WHITE);
                    if (i>=4) DrawTextEx(base, "Elas tâm atrapalhado a vida de todos os estudantes e funcionários, de modo que é impossí-", (Vector2){80,140}, 20, 4, WHITE);
                    if (i>=5) DrawTextEx(base, "vel se dedicar completamente à tarefas e projetos importantes.", (Vector2){80,160}, 20, 4, WHITE);
                    if (i>=6) DrawTextEx(base, "Temos sofrido com muitos casos reprovação, desaparecimento de pessoas e ataques de pânico,", (Vector2){80,180}, 20, 4, WHITE);
                    if (i>=7) DrawTextEx(base, "a UFMG se encontra em crise.", (Vector2){80,200}, 20, 4, WHITE);
                    if (i>=8) DrawTextEx(base, "Por isso estamos contratando um Especialista de Anomalias para resolver o problema. O cargo", (Vector2){80,220}, 20, 4, WHITE);
                    if (i>=9) DrawTextEx(base, "não possui muitos pré-requisitos: desde que você não desista fácil e consiga se adaptar a", (Vector2){80,240}, 20, 4, WHITE);
                    if (i>=10) DrawTextEx(base, "diversas situações no campus, acreditamos que está apto para ele.", (Vector2){80,260}, 20, 4, WHITE);
                    if (i>=11) DrawTextEx(base, "Seu trabalho será encontrar e derrotar todas essas anomalias. Elas estão presentes nos", (Vector2){80,280}, 20, 4, WHITE);
                    if (i>=12) DrawTextEx(base, "10 principais prédios da faculdade e algumas podem ser bem irritantes...", (Vector2){80,300}, 20, 4, WHITE);
                    if (i>=13) DrawTextEx(base, "Sabemos o quanto essa tarefa é desafiadora e exaustiva, por isso, como forma de pagamento,", (Vector2){80,320}, 20, 4, WHITE);
                    if (i>=14) DrawTextEx(base, "iremos providenciar para você um diploma oficial de nossa faculdade no curso de sua pre-", (Vector2){80,340}, 20, 4, WHITE);
                    if (i>=15) DrawTextEx(base, "ferencia. Não é maravilhoso poder se formar sem precisar estudar por cinco anos?", (Vector2){80,360}, 20, 4, WHITE);
                    if (i>=16) DrawTextEx(base, "Precisamos muito de ajuda para conseguir resolver o problema. Por favor pense com cui-", (Vector2){80,380}, 20, 4, WHITE);
                    if (i>=17) DrawTextEx(base, "dado sobre essa proposta.", (Vector2){80,400}, 20, 4, WHITE);
                    if (i>=18) DrawTextEx(base, "", (Vector2){80,420}, 20, 4, WHITE);
                    if (i>=19) DrawTextEx(base, "Atenciosamente,", (Vector2){80,440}, 20, 4, WHITE);
                    if (i>=20) DrawTextEx(base, "Membros desesperados da reitoria.", (Vector2){80,460}, 20, 4, WHITE);
                    if (i>=21) decision = true;
                }else if (decision == true)
                {
                    DrawTextEx(font, "VOCE ACEITARA ESSA PROPOSTA?", (Vector2){180, 120},60, 4, BLUE);
                    DrawRectangle(460 + optionSelect*272, 448, 100, 60, SKYBLUE);
                    DrawTextEx(font, "SIM", (Vector2){ 470, 458 }, 40, 4, (optionSelect == 0)? BLUE : SKYBLUE);
                    DrawTextEx(font, "NAO", (Vector2){ 748, 458 }, 40, 4, (optionSelect == 1)? BLUE : SKYBLUE);
                }


            } break; 
            case SIM:
            {
                DrawRectangle(0, 0, 1280, 720, BLACK);
                if (i>1) DrawTextEx(base, "Nos últimos semestres um mal maior do que o corte de verbas tem assolado a UFMG: o surgi-", (Vector2){80,100}, 20, 4, WHITE);
                if (i>2) DrawTextEx(base, "mento de anomalias nos mais diverios prédios da faculdade.", (Vector2){80,120}, 20, 4, WHITE);
                if (i>=4) DrawTextEx(base, "Elas tâm atrapalhado a vida de todos os estudantes e funcionários, de modo que é impossí-", (Vector2){80,140}, 20, 4, WHITE);
                if (i>=5) DrawTextEx(base, "vel se dedicar completamente à tarefas e projetos importantes.", (Vector2){80,160}, 20, 4, WHITE);
                if (i>=6) DrawTextEx(base, "Temos sofrido com muitos casos reprovação, desaparecimento de pessoas e ataques de pânico,", (Vector2){80,180}, 20, 4, WHITE);
                if (i>=7) DrawTextEx(base, "a UFMG se encontra em crise.", (Vector2){80,200}, 20, 4, WHITE);
                if (i>=8) DrawTextEx(base, "Por isso estamos contratando um Especialista de Anomalias para resolver o problema. O cargo", (Vector2){80,220}, 20, 4, WHITE);
                if (i>=9) DrawTextEx(base, "não possui muitos pré-requisitos: desde que você não desista fácil e consiga se adaptar a", (Vector2){80,240}, 20, 4, WHITE);
                if (i>=10) DrawTextEx(base, "diversas situações no campus, acreditamos que está apto para ele.", (Vector2){80,260}, 20, 4, WHITE);
                if (i>=11) DrawTextEx(base, "seu trabalho será encontrar e derrotar todas essas anomalias. Elas estão presentes nos", (Vector2){80,280}, 20, 4, WHITE);
                if (i>=12) DrawTextEx(base, "10 principais prédios da faculdade e algumas podem ser bem irritantes...", (Vector2){80,300}, 20, 4, WHITE);
                if (i>=13) DrawTextEx(base, "Sabemos o quanto essa tarefa é desafiadora e exaustiva, por isso, como forma de pagamento,", (Vector2){80,320}, 20, 4, WHITE);
                if (i>=14) DrawTextEx(base, "iremos providenciar para você um diploma oficial de nossa faculdade no curso de sua pre-", (Vector2){80,340}, 20, 4, WHITE);
                if (i>=15) DrawTextEx(base, "ferencia. Não é maravilhoso poder se formar sem precisar estudar por cinco anos?", (Vector2){80,360}, 20, 4, WHITE);
                if (i>=16) DrawTextEx(base, "Precisamos muito de ajuda para conseguir resolver o problema. Por favor pense com cui-", (Vector2){80,380}, 20, 4, WHITE);
                if (i>=17) DrawTextEx(base, "dado sobre essa proposta.", (Vector2){80,400}, 20, 4, WHITE);
                if (i>=18) DrawTextEx(base, "", (Vector2){80,420}, 20, 4, WHITE);
                if (i>=19) DrawTextEx(base, "Atenciosamente,", (Vector2){80,440}, 20, 4, WHITE);
                if (i>=20) DrawTextEx(base, "Membros desesperados da reitoria.", (Vector2){80,460}, 20, 4, WHITE);
                if (i>=21) decision = true;
            } break;
            case NAO:
            {
                DrawRectangle(0, 0, 1280, 720, BLACK);
                if (i>1) DrawTextEx(base, "De repende você sente alguém se aproximando por trás. Mas já é muito tarde, a pessoa pren-", (Vector2){80,100}, 20, 4, WHITE);
                if (i>2) DrawTextEx(base, "de as suas mão atrás do corpo com uma corda áspera enquanto você se debate freneticamente.", (Vector2){80,120}, 20, 4, WHITE);
                if (i>=4) DrawTextEx(base, "Ela se afasta e logo em seguida vem a escuridão, ela colocou um saco de ... de pequi? no ", (Vector2){80,140}, 20, 4, WHITE);
                if (i>=5) DrawTextEx(base, "seu rosto.", (Vector2){80,160}, 20, 4, WHITE);
                if (i>=6) DrawTextEx(base, "Você é tirado de seu lugar e levado para fora. Outra pessoa se aproxima e te joga violen-", (Vector2){80,180}, 20, 4, WHITE);
                if (i>=7) DrawTextEx(base, "tamente dentro de um carro, mas a a parte de cima da sua cabeça acaba batendo na lataria ", (Vector2){80,200}, 20, 4, WHITE);
                if (i>=8) DrawTextEx(base, "do carro e você desmaia...", (Vector2){80,220}, 20, 4, WHITE);
                if (i>=9) DrawTextEx(base, "'Nós avisamos para tomar cuidado com a resposta.' Você ouve uma voz falando rispidamente.", (Vector2){80,240}, 20, 4, WHITE);
                if (i>=10) DrawTextEx(base, "Aparentemente as mesmas pessoas que enviaram aquela oferta de emprego duvidosa agora es-", (Vector2){80,260}, 20, 4, WHITE);
                if (i>=11) DrawTextEx(base, "tão diante de tu após um sequestro.", (Vector2){80,280}, 20, 4, WHITE);
                if (i>=12) DrawTextEx(base, "'Acontece que estamos realmente desesperados. Já pedimos para diversas pessoas aceitarem", (Vector2){80,300}, 20, 4, WHITE);
                if (i>=13) DrawTextEx(base, "o trabalho, mas a maioria descobriu o que aconteceu com os especialistas de anomalias an-", (Vector2){80,320}, 20, 4, WHITE);
                if (i>=14) DrawTextEx(base, "teriores e recusou a proposta... Não há mais tempo para procurar alguém e você era a pes-", (Vector2){80,340}, 20, 4, WHITE);
                if (i>=15) DrawTextEx(base, "soa mais fácil de sequestrar que achamos, caso recusasse a oferta.'", (Vector2){80,360}, 20, 4, WHITE);
                if (i>=16) DrawTextEx(base, "'Ahh' (Suspiro) 'Odeio ter que fazer isso.'", (Vector2){80,380}, 20, 4, WHITE);
                if (i>=17) DrawTextEx(base, "'Apesar das circunstâncias de nosso encontro não serem as ideias, ainda mantenho a pro-", (Vector2){80,400}, 20, 4, WHITE);
                if (i>=18) DrawTextEx(base, "posta  de te dar um diploma ao derrotar todas as anomalias e...'", (Vector2){80,420}, 20, 4, WHITE);
                if (i>=19) DrawTextEx(base, "'Você quer saber o que aconteceu com os outros? Bem, isso não é muito importante no mo-", (Vector2){80,440}, 20, 4, WHITE);
                if (i>=20) DrawTextEx(base, "mento. Desde que você não seja derrotad@ mais do que 2 vezes vai ficar tudo bem.'", (Vector2){80,460}, 20, 4, WHITE);
                if (i>=21) DrawTextEx(base, "'Zeus! Olhe as horas, estou atrasado para uma reunião... Não precisa se preocupar, você ", (Vector2){80,480}, 20, 4, WHITE);
                if (i>=22) DrawTextEx(base, "tem cara se der inteligente. A UFMG precisa muito de você e cuidado com a reitoria...'", (Vector2){80,500}, 20, 4, WHITE);
                if (i>=23) DrawTextEx(base, "'Ah última coisa, preciso depois das suas informações para poder registrar você oficial-", (Vector2){80,520}, 20, 4, WHITE);
                if (i>=24) DrawTextEx(base, "mente como noss@ funcionário/aluno. Vou deixar aqui um documento pra você colocar suas ", (Vector2){80,540}, 20, 4, WHITE);
                if (i>=25) DrawTextEx(base, "informações. Boa sorte com tudo'", (Vector2){80,560}, 20, 4, WHITE);
                if (i>=26) decision = true;
            } break;
            case CHARACTERS:
            {
                DrawTextEx(font, "ESCOLHA UM PERSONAGEM", (Vector2){280, 80},60, 4, BLUE);
                DrawRectangle(190, 210, 220, 300, BLUE);
                DrawRectangle(530, 210, 220, 300, BLUE);
                DrawRectangle(870, 210, 220, 300, BLUE);
                if(optionSelect < 3) DrawRectangle(190 + optionSelect*340, 210, 220, 300, SKYBLUE);
                else DrawRectangle(1040, 580, 160, 60, SKYBLUE);
                DrawTextureEx(druidPic, (Vector2){880, 236}, 0, 1.5, WHITE);
                DrawTextureEx(warriorPic, (Vector2){544, 236}, 0, 1.5, WHITE);
                DrawTextureEx(magePic, (Vector2){222, 220}, 0, 1.25, WHITE);
                DrawTextEx(font, "VOLTAR", (Vector2){ 1062, 594 }, 32, 4, (optionSelect == 3)? DARKBLUE : SKYBLUE);
                DrawTextEx(font, "A MAGA", (Vector2){ 245, 470 }, 26, 4, (optionSelect == 0)? DARKBLUE : WHITE);
                DrawTextEx(font, "O GUERREIRO", (Vector2){ 552, 470 }, 26, 4, (optionSelect == 1)? DARKBLUE : WHITE);
                DrawTextEx(font, "O DRUIDA", (Vector2){ 915, 470 }, 26, 4, (optionSelect == 2)? DARKBLUE : WHITE);
            } break;
            case BIO:
            {
                DrawRectangle(430, 80, 420, 560, DARKBLUE);
                DrawRectangle(438, 88, 404, 544, BLUE);
                DrawRectangle(450, 100, 180, 220, GRAY);
                if (character == mage) DrawTextureEx(charac_pic, (Vector2){472, 110}, 0, 1.10, WHITE);
                else if (character == master) DrawTextureEx(charac_pic, (Vector2){450, 120}, 0, 1.4, WHITE);
                else if (character == druid) DrawTextureEx(charac_pic, (Vector2){448, 120}, 0, 1.4, WHITE);
                if (character == mage) DrawTextEx(base, "Mago", (Vector2){ 650, 100 }, 30, 4, WHITE);
                else if (character == master) DrawTextEx(base, "Guerreiro", (Vector2){ 650, 100 }, 30, 4, WHITE);
                else if (character == druid) DrawTextEx(base, "Druida", (Vector2){ 650, 100 }, 30, 4, WHITE);
                //std::string vida = std::to_string(pcvidamax);
                DrawTextEx(base, "Vida:", (Vector2){ 650, 160 }, 24, 4, WHITE);
                DrawTextEx(base, std::to_string(pcvidamax).c_str(), (Vector2){ 804, 160 }, 24, 4, WHITE);
                DrawTextEx(base, "Defesa:", (Vector2){ 650, 220 }, 24, 4, WHITE);
                DrawTextEx(base, std::to_string(pcdefmax).c_str(), (Vector2){ 804, 220 }, 24, 4, WHITE);
                DrawTextEx(base, "Estamina", (Vector2){ 650, 280 }, 24, 4, WHITE);
                DrawTextEx(base, std::to_string(pcestaminamax).c_str(), (Vector2){ 820, 280 }, 24, 4, WHITE);
                DrawTextEx(base, "Tipo:", (Vector2){ 452, 340 }, 24, 4, WHITE);
                DrawTextEx(base, tipo.c_str(), (Vector2){ 528, 340 }, 22, 4, WHITE);
                DrawTextEx(base, "Descrição:", (Vector2){ 452, 380 }, 24, 4, WHITE);
                if (character == mage) DrawTextEx(base, desc.c_str(), (Vector2){ 452, 408 }, 24, 4, WHITE);
                else if (character == master) 
                {
                    DrawTextEx(base, "Levantar a voz não vence", (Vector2){ 452, 408 }, 22, 4, WHITE);
                    DrawTextEx(base, "uma lingua afiada.", (Vector2){ 452, 432 }, 24, 4, WHITE);
                } else if (character == druid)
                {
                    DrawTextEx(base, "Altos contatos com a", (Vector2){ 452, 408 }, 22, 4, WHITE);
                    DrawTextEx(base, "natureza.", (Vector2){ 452, 432 }, 24, 4, WHITE);
                }
                DrawRectangle(460 + optionSelect*272, 568, 90, 50, SKYBLUE);
                DrawTextEx(font, "DESEJA SELECIONAR ESSE", (Vector2){ 460, 520 }, 24, 4, WHITE);
                DrawTextEx(font, "PERSONAGEM?", (Vector2){ 460, 540 }, 24, 4, WHITE);
                DrawTextEx(font, "SIM", (Vector2){ 470, 578 }, 32, 4, (optionSelect == 0)? BLUE : WHITE);
                DrawTextEx(font, "NAO", (Vector2){ 748, 578 }, 32, 4, (optionSelect == 1)? BLUE : WHITE);
            } break;   
                    
            case STORY:
            {
                if (i>0) DrawTextEx(base, "CAPÍTULO 1: Nem tão belas... Artes.", (Vector2){80, 70}, 20, 4, WHITE);
                if (i>1) DrawTextEx(base, "Enquanto você preenchia o documento, o carro seguiu viagem rumo à honrada, e mais novo", (Vector2){80,100}, 20, 4, WHITE);
                if (i>2) DrawTextEx(base, "palco de anomalias, UFMG. Coincidentemente, assim que você assina a última página o veí-.", (Vector2){80,120}, 20, 4, WHITE);
                if (i>=4) DrawTextEx(base, "culo cessa seu movimento e o motorista fala com você:", (Vector2){80,140}, 20, 4, WHITE);
                if (i>=5) DrawTextEx(base, "", (Vector2){80,160}, 20, 4, WHITE);
                if (i>=6) DrawTextEx(base, "- Chegamos, pode descer.", (Vector2){80,180}, 20, 4, WHITE);
                if (i>=7) DrawTextEx(base, "", (Vector2){80,200}, 20, 4, WHITE);
                if (i>=8) DrawTextEx(base, "Você desce do carro e a paisagem é exatamente como as fotos na internet, um campus am-", (Vector2){80,220}, 20, 4, WHITE);
                if (i>=9) DrawTextEx(base, "plo, cheio de árvores e praticamente plano, pelo menos na entrada. Porém a faculdade es-", (Vector2){80,240}, 20, 4, WHITE);
                if (i>=10) DrawTextEx(base, "tava deserta, você mal via alguém, e as pessoas que encontrava não queriam contato, pro-", (Vector2){80,260}, 20, 4, WHITE);
                if (i>=11) DrawTextEx(base, "vavelmente por conta da crise atual.", (Vector2){80,280}, 20, 4, WHITE);
                if (i>=12) DrawTextEx(base, "Sua primeira intrução é ir até a Escola de Belas Artes, e assim o faz, adentrando o notá-", (Vector2){80,300}, 20, 4, WHITE);
                if (i>=13) DrawTextEx(base, "vel prédio de cores quentes.", (Vector2){80,320}, 20, 4, WHITE);
                if (i>=14) decision = true;
            } break;
            case ENCOUNTER1:
            {
                if (i>0) DrawTextEx(base, "Você entra no prédio com cautela, mas este esta vazio e tudo aparenta estar em seu", (Vector2){80, 80}, 20, 4, WHITE);
                if (i>1) DrawTextEx(base, "devido lugar. Há desenhos, pinturas e mini-esculturas expostas pelos corredores, to-", (Vector2){80,100}, 20, 4, WHITE);
                if (i>2) DrawTextEx(base, "das dignas de sua adimiração.", (Vector2){80,120}, 20, 4, WHITE);
                if (i>=4) DrawTextEx(base, "Alguns minutos se passam e você consegue exploras a maior parte das salas do primei-", (Vector2){80,140}, 20, 4, WHITE);
                if (i>=5) DrawTextEx(base, "ro andar. Parecia que as coisas estavam normais, talvez as anomalias não tivessem ", (Vector2){80,160}, 20, 4, WHITE);
                if (i>=6) DrawTextEx(base, "chegado ali. Mas uma coisa lhe incomodava, em todas as salas você uma pintura em um", (Vector2){80,180}, 20, 4, WHITE);
                if (i>=7) DrawTextEx(base, "cavalete, e era sempre o mesmo desenho, que você não soube identificar, pois prová-", (Vector2){80,200}, 20, 4, WHITE);
                if (i>=8) DrawTextEx(base, "velmente não havia sido terminado. Será que algum professor passou o mesmo trabalho", (Vector2){80,220}, 20, 4, WHITE);
                if (i>=9) DrawTextEx(base, "para todas as turmas? Ou os alunos decidiram pintar a mesma coisa?", (Vector2){80,240}, 20, 4, WHITE);
                if (i>=10) DrawTextEx(base, "Você não sabia a resposta para essas perguntas, e decide deixá-las de lado para se-", (Vector2){80,260}, 20, 4, WHITE);
                if (i>=11) DrawTextEx(base, "guir com a investigação, mas elas decidiram vir até você. Virando o corredor, o mes-", (Vector2){80,280}, 20, 4, WHITE);
                if (i>=12) DrawTextEx(base, "mo cavalete está na sua frente, e ele não parece feliz.", (Vector2){80,300}, 20, 4, WHITE);
                if (i>=13) DrawTextEx(base, "", (Vector2){80,320}, 20, 4, WHITE);
                if (i>=14) DrawTextEx(base, "", (Vector2){80,340}, 20, 4, WHITE);
                if (i>=15) DrawTextEx(base, "Pintura Inacabada:", (Vector2){80,360}, 20, 4, WHITE);
                if (i>=16) DrawTextEx(base, "- Você... Não... Me terminou... Agora... VOU ACABAR COM VOCÊ!!!", (Vector2){80,400}, 20, 4, WHITE);
                if (i>=17) decision = true;
            } break;
            case BATTLE1:
            {
                DrawTextureEx(background, (Vector2){-1, 0}, 0, 2.8, WHITE);

                DrawRectangle(72, 72, 496, 136, DARKBLUE);
                DrawRectangle(80, 80, 480, 120, LIGHTGRAY);
                DrawTextEx(base, "Pintura Inacabada", (Vector2){90, 90}, 24, 4, BLACK);
                DrawTextEx(base, "Vida:    /", (Vector2){90, 120}, 24, 4, BLACK);
                DrawTextEx(base, std::to_string(npcvida).c_str(), (Vector2){170, 120}, 24, 4, BLACK);
                DrawTextEx(base, std::to_string(npcvidamax).c_str(), (Vector2){220, 120}, 24, 4, BLACK);
                
                DrawRectangle(712, 350, 496, 136, DARKBLUE);
                DrawRectangle(720, 358, 480, 120, LIGHTGRAY);
                DrawTextEx(base, "Vida:    /", (Vector2){730, 380}, 26, 4, BLACK);
                DrawTextEx(base, std::to_string(pcvida).c_str(), (Vector2){814, 380}, 26, 4, BLACK);
                DrawTextEx(base, std::to_string(pcvidamax).c_str(), (Vector2){872, 380}, 26, 4, BLACK);
                DrawTextEx(base, "Estamina:   /", (Vector2){730, 420}, 26, 4, BLACK);
                DrawTextEx(base, std::to_string(pcestamina).c_str(), (Vector2){880, 420}, 26, 4, BLACK);
                DrawTextEx(base, std::to_string(pcestaminamax).c_str(), (Vector2){920, 420}, 26, 4, BLACK);

                if (character == mage) DrawTextureEx(charac_pic, (Vector2){272, 300}, 0, 1.10, WHITE);
                else if (character == master) DrawTextureEx(bmasterPic, (Vector2){208, 300}, 0, 1.6, WHITE);
                else if (character == druid) DrawTextureEx(bdruidPic, (Vector2){208, 300}, 0, 1.6, WHITE);

                DrawTextureEx(pintura, (Vector2){840, 60}, 0, 0.4, WHITE);

                if(act == false)
                {
                    DrawTexture(texBar, 0, 504, WHITE);
                    if (decision == true)
                    {
                        if (k==1) 
                        {
                            if (j==0) DrawTextEx(base, "Parabéns! Você derrotou Pintura Inacabada.", (Vector2){120, 610}, 24, 4, BLACK);
                            if (j==1)currentScreen = ENCOUNTER2;
                        }    
                        else if (k==2) 
                        {
                            if (j==0) DrawTextEx(base, "Essa não! Você foi derrotado.", (Vector2){120, 610}, 24, 4, BLACK);
                            if (j==1) currentScreen = REPROVADO1;
                        }    
                    }
                    if (decision == false)
                    {
                        if (i==0) DrawTextEx(base, "A wild Pintura Inacabada Appeared", (Vector2){120, 610}, 24, 4, BLACK);
                        if (i==1) 
                        {
                            i++;
                            act = true;
                        }
                        if (i==2) 
                            {
                                if (optionSelect < 2) 
                                { 
                                    DrawTextEx(base, "Você usou", (Vector2){120, 610}, 24, 4, BLACK);
                                    DrawTextEx(base, ataque.c_str(), (Vector2){270, 610}, 24, 4, BLACK);
                                } else DrawTextEx(base, ataque.c_str(), (Vector2){120, 610}, 24, 4, BLACK);
                            }    
                        if (i==3) DrawTextEx(base, "Pintura Inacabada usou Restos de Tinta", (Vector2){120, 610}, 24, 4, BLACK);
                        if (i==4)
                        {
                            i++;
                            act = true;
                        }
                        if (i==5) 
                            {
                                if (optionSelect < 2) 
                                { 
                                    DrawTextEx(base, "Você usou", (Vector2){120, 610}, 24, 4, BLACK);
                                    DrawTextEx(base, ataque.c_str(), (Vector2){270, 610}, 24, 4, BLACK);
                                } else DrawTextEx(base, ataque.c_str(), (Vector2){120, 610}, 24, 4, BLACK);
                            }    
                        if (i==6) DrawTextEx(base, "Pintura Inacabada usou Restos de Tinta", (Vector2){120, 610}, 24, 4, BLACK);
                        if (i==7)
                        {
                            i++;
                            act = true;
                        }
                        if (i==8) 
                            {
                                if (optionSelect < 2) 
                                { 
                                    DrawTextEx(base, "Você usou", (Vector2){120, 610}, 24, 4, BLACK);
                                    DrawTextEx(base, ataque.c_str(), (Vector2){270, 610}, 24, 4, BLACK);
                                } else DrawTextEx(base, ataque.c_str(), (Vector2){120, 610}, 24, 4, BLACK);
                            }    
                        if (i==9) DrawTextEx(base, "Pintura Inacabada usou Restos de Tinta", (Vector2){120, 610}, 24, 4, BLACK);
                        if (i==10)
                        {
                            i++;
                            act = true;
                        }
                    }    
                }
                else if(act == true)
                {
                    DrawTexture(battleBar, 0, 504, WHITE);
                    DrawTextEx(base, ataque1.c_str(), (Vector2){90,562}, 20, 4, BLACK);
                    DrawTextEx(base, ataque2.c_str(), (Vector2){470,562}, 20, 4, BLACK);
                    DrawTextEx(base, "Não fazer nada", (Vector2){90,642}, 20, 4, BLACK);
                    if(optionSelect == 0) DrawRectangle(60, 560, 20, 20, BLACK);
                    else if(optionSelect == 1) DrawRectangle(440, 560, 20, 20, BLACK);
                    else if(optionSelect == 2) DrawRectangle(60, 640, 20, 20, BLACK);
                    else if(optionSelect == 3) DrawRectangle(440, 640, 20, 20, BLACK);
                }
            } break; 
            case CREDITS:
            {

            } break;
            case ENDING:
            {
                
            } break;
            default: break;
        }
    EndTextureMode();

    BeginDrawing();
        ClearBackground(BLACK);
        DrawTextureRec(screenTarget.texture, (Rectangle){ 0, 0, screenTarget.texture.width, -screenTarget.texture.height }, (Vector2){ 0, 0 }, WHITE);
    EndDrawing();

}

std::vector<std::string> tramontina(std::string a)
{
    std::vector<std::string> texto;
}

//g++ gui.cpp -lraylib -lGL -lm -lpthread -ldl -lrt -lX11

//$(CC) main.cpp $(RAYLIB)  
