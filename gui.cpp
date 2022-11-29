#include "raylib.h"
#include "raymath.h"
#include <string>

#include <math.h>       // Required for:

#if defined(PLATFORM_WEB)
    #include <emscripten/emscripten.h>
#endif

typedef enum {TITLE, CHARACTERS, CREDITS, BIO, STORY, BATTLE, EVENT, ENDING } GameScreen;
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
static Texture2D warriorPic = { 0 };
static Texture2D magePic = { 0 };
Texture2D charac_pic;

// FONTES
static Font font = { 0 };

// AUDIOS

static Model model = { 0 };

// Render texture to draw full screen, enables screen scaling
static RenderTexture2D screenTarget = { 0 };

static void UpdateDrawFrame(void);              // Update and Draw one frame

int main()
{

    SetConfigFlags(FLAG_MSAA_4X_HINT | FLAG_WINDOW_TRANSPARENT);
    InitWindow(screenWidth, screenHeight, "Escape from UFMG");

    // carrega fotos
    texTitle = LoadTexture("resources/interface/title.png");
    texBar = LoadTexture("resources/interface/barra_texto.png");
    battleBar = LoadTexture("resources/interface/barra_acao.png");
    background = LoadTexture("resources/background/funfofaketeste.png");
    druidPic = LoadTexture("resources/pc/druida.png");
    warriorPic = LoadTexture("resources/pc/chuvas.png");
    magePic = LoadTexture("resources/pc/mago.png");

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
                    currentScreen = CHARACTERS;        // Gameplay screen
                }
                else if (optionSelect == 1)
                {
                    currentScreen = CREDITS;    // Credits screen
                }
                else if (optionSelect == 2) exitGame = true;            // Exit game

                framesCounter = 0;
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
            if(character == druid) charac_pic = druidPic;
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
                    //currentScreen = STORY;   
                    currentScreen = BATTLE;     
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
                   //chama a proxima linha de texto   
                } 
                else if (IsKeyPressed(KEY_ENTER) && string[sizeof(string)] == '&') //pulas os textos
                {
                    //chama o proximo bloco de texto ou batalha    
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
                    }
                    else if (optionSelect == 1)
                    {
                        //nega a decisao  
                    }
                }   
            }
        } break;
        case BATTLE:
        {
            if(act == false)
            {
                if (IsKeyPressed(KEY_ENTER)) //pulas os textos
                {
                    act = true;    
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
                    //optionSelect == 0, 1, 2, 3 (4 ATAQUES DISPONIVEIS);
                    act = false;
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
            case CHARACTERS:
            {
                DrawTextEx(font, "ESCOLHA UM PERSONAGEM", (Vector2){280, 80},60, 4, BLUE);
                DrawRectangle(190, 210, 220, 300, BLUE);
                DrawRectangle(530, 210, 220, 300, BLUE);
                DrawRectangle(870, 210, 220, 300, BLUE);
                if(optionSelect < 3) DrawRectangle(190 + optionSelect*340, 210, 220, 300, SKYBLUE);
                else DrawRectangle(1040, 580, 160, 60, SKYBLUE);
                DrawTextureEx(druidPic, (Vector2){900, 220}, 0, 0.5, WHITE);
                DrawTextureEx(warriorPic, (Vector2){544, 236}, 0, 1.5, WHITE);
                DrawTextureEx(magePic, (Vector2){222, 220}, 0, 1.25, WHITE);
                DrawTextEx(font, "VOLTAR", (Vector2){ 1062, 594 }, 32, 4, (optionSelect == 3)? BLUE : SKYBLUE);
                DrawTextEx(font, "A MAGA", (Vector2){ 245, 470 }, 26, 4, (optionSelect == 0)? BLUE : SKYBLUE);
                DrawTextEx(font, "O GUERREIRO", (Vector2){ 552, 470 }, 26, 4, (optionSelect == 1)? BLUE : SKYBLUE);
                DrawTextEx(font, "O DRUIDA", (Vector2){ 915, 470 }, 26, 4, (optionSelect == 2)? BLUE : SKYBLUE);
            } break;
            case BIO:
            {
                DrawRectangle(430, 80, 420, 560, DARKBLUE);
                DrawRectangle(438, 88, 404, 544, BLUE);
                DrawRectangle(450, 100, 180, 220, GRAY);
                if (character == mage) DrawTextureEx(charac_pic, (Vector2){472, 110}, 0, 1.10, WHITE);
                else if (character == master) DrawTextureEx(charac_pic, (Vector2){450, 120}, 0, 1.4, WHITE);
                else if (character == druid) DrawTextureEx(charac_pic, (Vector2){440, 120}, 0, 1.25, WHITE);
                DrawRectangle(460 + optionSelect*272, 568, 90, 50, SKYBLUE);
                DrawTextEx(font, "DESEJA SELECIONAR ESSE", (Vector2){ 460, 520 }, 24, 4, SKYBLUE);
                DrawTextEx(font, "PERSONAGEM?", (Vector2){ 460, 540 }, 24, 4, SKYBLUE);
                DrawTextEx(font, "SIM", (Vector2){ 470, 578 }, 32, 4, (optionSelect == 0)? BLUE : SKYBLUE);
                DrawTextEx(font, "NAO", (Vector2){ 748, 578 }, 32, 4, (optionSelect == 1)? BLUE : SKYBLUE);
            } break;   
            case BATTLE:
            {
                DrawTexture(background, 0, 0, WHITE);
                DrawRectangle(80, 80, 480, 120, LIGHTGRAY);
                DrawRectangle(720, 358, 480, 120, LIGHTGRAY);
                if(act == false)
                {
                    DrawTexture(texBar, 0, 504, WHITE);
                }
                else if(act == true)
                {
                    DrawTexture(battleBar, 0, 504, WHITE);
                    DrawRectangle(200 + optionSelect*100, 360, 40, 40, BLACK);
                }
            } break;         
            case STORY:
            {

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

//g++ gui.cpp -lraylib -lGL -lm -lpthread -ldl -lrt -lX11