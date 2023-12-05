#include "Game.hpp"

#include "util/Convert.hpp"
#include "mechanics/grid/Board.hpp"
#include "mechanics/grid/TShape.hpp"

const char* imgPathList[] = 
{
    "assets/img/brick.png",
    "assets/img/brickRed.png",
    "assets/img/brickGreen.png",
    "assets/img/brickBlue.png",
    "assets/img/brickYellow.png",
    "assets/img/brickCyan.png",
    "assets/img/brickMagenta.png",
    "assets/img/brickOrange.png"
};

Game::Game(Window* window) : _keyState(SDL_GetKeyboardState(NULL))
{
    _win = window;
}

void Game::End()
{
    _running = false;
    _win->Print("Loop ended!");
}

Error Game::Run()
{
    _running = true;
    try
    {
        SDL_Renderer* winRenderer = _win->GetRenderer();

        Texture frameTex = Texture(winRenderer, "assets/img/frame.png");
        Sprite frame = Sprite(&frameTex);
        frame.SetPosition(0, 0);
        frame.SetSize(_win->GetSize());
        frame.SetCenter(_win->GetCenter());
        _win->AddToRenderList(&frame);

        // Texture redBrickTex = Texture(winRenderer, imgPathList[TILE_RED]);
        // Sprite redBrick = Sprite(&redBrickTex);
        // redBrick.SetPosition(96, 288);
        // redBrick.SetSize(TILE_SIZE, TILE_SIZE);

        // Sprite redBrick2 = Sprite(&redBrickTex);
        // redBrick2.SetPosition(130, 320);
        // redBrick2.SetSize(TILE_SIZE, TILE_SIZE);

        // _win->AddToRenderList(&redBrick);
        // _win->AddToRenderList(&redBrick2);


        // Load textures:
        
        Texture** tileTexArray = new Texture*[TILE_LAST - 1];
        for(int i = 0; i < TILE_LAST; i++)
        {
            tileTexArray[i] = new Texture(winRenderer, imgPathList[i]);
            if(!tileTexArray[i]->IsOK())
                _win->PrintError(tileTexArray[i]->GetError());
        }

        Size boardSize;
        boardSize.w = BOARD_WIDTH;
        boardSize.h = BOARD_HEIGHT;
        Size boardPxSize;
        boardPxSize.w = BOARD_WIDTH * TILE_SIZE;
        boardPxSize.h = BOARD_HEIGHT * TILE_SIZE;
        Point boardPos;
        boardPos.x = BOARD_POS_X;
        boardPos.y = BOARD_POS_Y;
        Board tileBoard = Board(boardSize, boardPxSize, boardPos);
        tileBoard.SetTextureArray(tileTexArray);

        tileBoard.SetTile(TILE_RED, 0, 0);
        tileBoard.SetTile(TILE_RED, BOARD_WIDTH-1, 0);
        tileBoard.SetTile(TILE_RED, 0, BOARD_HEIGHT-1);
        tileBoard.SetTile(TILE_RED, BOARD_WIDTH-1, BOARD_HEIGHT-1);

        _win->AddToRenderList(&tileBoard);
        


        while(_running)
        {
            _time.CalculateTime();
            HandleEvents();

            _win->Render();
        }

        return Error(); // Zwraca obiekt domyślny - brak błędów
    }
    catch(const std::exception& e)
    {
        return Error(ERROR_EXCEPTION, std::string(e.what()));
    }
}

void Game::HandleEvents()
{
    SDL_Event e;

    while(SDL_PollEvent(&e) != 0)
    {
        switch(e.type)
        {
            case SDL_QUIT:
                End();
            break;

            case SDL_KEYDOWN:
                KeyboardInput(e.key.keysym.sym);
            break;

            default:
                if (e.type != SDL_MOUSEMOTION && e.type != SDL_MOUSEBUTTONDOWN && e.type != SDL_MOUSEBUTTONUP)
                {
                    char *str = new char[32];
                    sprintf(str, "Unhandled event: %d", e.type);
                    _win->Print(std::string(str));
                }
            break;
        }
    }
}

void Game::KeyboardInput(SDL_Keycode key_code)
{
    switch(key_code)
    {
        case SDLK_ESCAPE:
            End();
        break;

        default:
            char *str = new char[32];
            sprintf(str, "Unhandled key: %d", key_code);
            _win->Print(std::string(str));
        break;
    }
    
    SDL_PumpEvents();

    // Tutaj można sprawdzić wciśnięcie klawiszy
}