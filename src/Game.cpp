#include "Game.hpp"

#include "util/Convert.hpp"

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

Game::Game(Window* window) : 
_keyState(SDL_GetKeyboardState(NULL)),
_frameTex(window->GetRenderer(), "assets/img/frame.png"),
_frame(&_frameTex),
_tileBoard(newSize(BOARD_WIDTH, BOARD_HEIGHT), newSize(BOARD_WIDTH * TILE_SIZE, BOARD_HEIGHT * TILE_SIZE), newPoint(BOARD_POS_X, BOARD_POS_Y)),
_actualShape(newPoint(3, 8), &_tileBoard),
_nextShapeBoard(newSize(4, 4), newSize(4 * TILE_SIZE, 4 * TILE_SIZE), newPoint(480, 640)),
_nextShape(newPoint(0, 0), &_nextShapeBoard)
{
    _win = window;

    SDL_Renderer* winRenderer = _win->GetRenderer();

    // _frameTex = Texture(winRenderer, "assets/img/frame.png");
    // _frame = Sprite(&_frameTex);
    _frame.SetPosition(0, 0);
    _frame.SetSize(_win->GetSize());
    _frame.SetCenter(_win->GetCenter());
    _win->AddToRenderList(&_frame);

    // Texture redBrickTex = Texture(winRenderer, imgPathList[TILE_RED]);
    // Sprite redBrick = Sprite(&redBrickTex);
    // redBrick.SetPosition(96, 288);
    // redBrick.SetSize(TILE_SIZE, TILE_SIZE);

    // _win->AddToRenderList(&redBrick);
    // _win->AddToRenderList(&redBrick2);

    // Load textures:
    
    _tileTexArray = new Texture*[TILE_LAST - 1];
    for(int i = 0; i < TILE_LAST; i++)
    {
        _tileTexArray[i] = new Texture(winRenderer, imgPathList[i]);
        if(!_tileTexArray[i]->IsOK())
            _win->PrintError(_tileTexArray[i]->GetError());
    }

    // Sprite redBrick2 = Sprite(tileTexArray[TILE_RED]);
    // redBrick2.SetPosition(130, 320);
    // redBrick2.SetSize(TILE_SIZE, TILE_SIZE);

    // _win->AddToRenderList(&redBrick2);

    // Size boardSize = newSize(BOARD_WIDTH, BOARD_HEIGHT);
    // Size boardPxSize = newSize(BOARD_WIDTH * TILE_SIZE, BOARD_HEIGHT * TILE_SIZE);
    // Point boardPos = newPoint(BOARD_POS_X, BOARD_POS_Y);
    // _tileBoard = Board(boardSize, boardPxSize, boardPos);
    _tileBoard.SetTextureArray(_tileTexArray);
    _nextShapeBoard.SetTextureArray(_tileTexArray);

    _nextShapeBoard.SetTile(TILE_BLUE, newPoint(0,0));
    _nextShapeBoard.SetTile(TILE_BLUE, newPoint(1,1));
    _nextShapeBoard.SetTile(TILE_BLUE, newPoint(2,2));
    _nextShapeBoard.SetTile(TILE_BLUE, newPoint(3,3));

    // tileBoard.SetTile(TILE_RED, 0, 0);
    // tileBoard.SetTile(TILE_RED, BOARD_WIDTH-1, 0);
    // tileBoard.SetTile(TILE_RED, 0, BOARD_HEIGHT-1);
    // tileBoard.SetTile(TILE_RED, BOARD_WIDTH-1, BOARD_HEIGHT-1);

    // Point shapePos = newPoint(3, 8);
    // _actualShape = TShape(shapePos);
    _actualShape.SetPattern(SHAPE_T, TILE_RED);

    //_tileBoard.TryMerge(&_actualShape);

    _win->AddToRenderList(&_tileBoard);
    _win->AddToRenderList(&_actualShape);
    _win->AddToRenderList(&_nextShapeBoard);
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
                if (e.type != SDL_MOUSEMOTION && e.type != SDL_MOUSEBUTTONDOWN && e.type != SDL_MOUSEBUTTONUP && e.type != SDL_TEXTINPUT && e.type != SDL_KEYUP)
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
            // char *str = new char[32];
            // sprintf(str, "Unhandled key: %d", key_code);
            // _win->Print(std::string(str));
            SDL_PumpEvents();

            // Rotating and switching
            if(_keyState[SDL_SCANCODE_E])
                _actualShape.Rotate(ROT_RIGHT);
            if(_keyState[SDL_SCANCODE_Q])
                _actualShape.Rotate(ROT_LEFT);
            if(_keyState[SDL_SCANCODE_R])
                NextShape();

            // Moving
            if(_keyState[SDL_SCANCODE_W])
                _actualShape.Move(DIR_UP, 1);
            if(_keyState[SDL_SCANCODE_A])
                _actualShape.Move(DIR_LEFT, 1);
            if(_keyState[SDL_SCANCODE_S])
                _actualShape.Move(DIR_DOWN, 1);
            if(_keyState[SDL_SCANCODE_D])
                _actualShape.Move(DIR_RIGHT, 1);

            RefreshBoard();
        break;
    }
}

void Game::NextShape()
{
    TPattern pat = _actualShape.GetPattern();
    pat = (TPattern)(1 + (int)pat);
    if(pat == SHAPE_LAST)
        pat = SHAPE_I;
    
    _actualShape.SetPattern(pat, TILE_RED);
}

void Game::RefreshBoard()
{
    // _tileBoard.Clear();
}