#include "ludo_piece.hpp"

LudoPiece::LudoPiece()
{
    render_position_movement_index = -1;
    status = HOME;
}
LudoPiece::LudoPiece(SDL_Point render_position)
{
    render_position_movement_index = -1;
    status = HOME;
    this->render_position = render_position;
}

LudoPiece::~LudoPiece()
{
    // Empty destructor
}

void LudoPiece::setRenderPosition(SDL_Point render_position)
{
    this->render_position = render_position;
}

SDL_Point LudoPiece::getRenderPosition()
{
    return this->render_position;
}

void LudoPiece::setStatus(Status_Of_Ludo_Piece status)
{
    this->status = status;
}

Status_Of_Ludo_Piece LudoPiece::getStatus()
{
    return this->status;
}

void LudoPiece::setRenderPositionMovementIndex(int value)
{
    this->render_position_movement_index = value;
}
int LudoPiece::getRenderPositionMovementIndex()
{
    return this->render_position_movement_index;
}
void LudoPiece::render(Window &window)
{

    SDL_Rect render_quad = {window.getWidth() / 15 * this->getRenderPosition().x + (window.getWidth() / 15 - 30) / 2, window.getHeight() / 15 * this->getRenderPosition().y + (window.getHeight() / 15 - 30) / 2, 30, 30};

    SDL_RenderFillRect(window.renderer, &render_quad);
}

RedLudoPiece::RedLudoPiece() : LudoPiece()
{
}

RedLudoPiece::RedLudoPiece(SDL_Point render_position) : LudoPiece(render_position)
{
}

RedLudoPiece::~RedLudoPiece()
{
    // Empty destructor
}

void RedLudoPiece ::updateRedPiece(Turn &current_turn, int rotated_dice_value)
{
    current_turn = GREEN_PIECE;

    if (rotated_dice_value == 6 || rotated_dice_value == 1)
    {
        current_turn = RED_PIECE;
    }

    if (this->getStatus() == HOME)
    {
        if (rotated_dice_value == 1)
        {
            this->setStatus(RUNNING);
            this->setRenderPositionMovementIndex(this->getRenderPositionMovementIndex() + rotated_dice_value);
            this->setRenderPosition(this->render_position_movement[this->getRenderPositionMovementIndex()]);

            current_turn = RED_PIECE;
        }
    }
    else if (this->getStatus() == RUNNING)
    {

        if (this->getRenderPositionMovementIndex() + rotated_dice_value < 56)
        {
            this->setRenderPositionMovementIndex(this->getRenderPositionMovementIndex() + rotated_dice_value);
            this->setRenderPosition(this->render_position_movement[this->getRenderPositionMovementIndex()]);
            std::cout << this->getRenderPositionMovementIndex() << std::endl;
        }
        else if (this->getRenderPositionMovementIndex() + rotated_dice_value == 56)
        {
            this->setRenderPosition({0, 14});
        }
    }
    else if (this->getStatus() == COMPLETED)
    {
    }
}

void RedLudoPiece::renderRedPiece(Window &window)
{
    SDL_SetRenderDrawColor(window.renderer, 200, 0, 0, 255);
    this->render(window);
}

GreenLudoPiece::GreenLudoPiece() : LudoPiece()
{
}
GreenLudoPiece::GreenLudoPiece(SDL_Point render_position) : LudoPiece(render_position)
{
}
GreenLudoPiece::~GreenLudoPiece()
{
    // Empty destructor
}

void GreenLudoPiece ::updateGreenPiece(Turn &current_turn, int rotated_dice_value)
{

    current_turn = YELLOW_PIECE;

    if (rotated_dice_value == 6 || rotated_dice_value == 1)
    {
        current_turn = GREEN_PIECE;
    }

    if (this->getStatus() == HOME)
    {
        if (rotated_dice_value == 1)
        {
            this->setStatus(RUNNING);
            this->setRenderPositionMovementIndex(this->getRenderPositionMovementIndex() + rotated_dice_value);
            this->setRenderPosition(this->render_position_movement[this->getRenderPositionMovementIndex()]);

            current_turn = GREEN_PIECE;
        }
    }
    else if (this->getStatus() == RUNNING)
    {

        if (this->getRenderPositionMovementIndex() + rotated_dice_value < 56)
        {
            this->setRenderPositionMovementIndex(this->getRenderPositionMovementIndex() + rotated_dice_value);
            this->setRenderPosition(this->render_position_movement[this->getRenderPositionMovementIndex()]);
            std::cout << this->getRenderPositionMovementIndex() << std::endl;
        }
        else if (this->getRenderPositionMovementIndex() + rotated_dice_value == 56)
        {
            this->setRenderPosition({1, 14});
        }
    }
    else if (this->getStatus() == COMPLETED)
    {
    }
}
void GreenLudoPiece::renderGreenPiece(Window &window)
{
    SDL_SetRenderDrawColor(window.renderer, 0, 200, 0, 255);
    this->render(window);
}

BlueLudoPiece::BlueLudoPiece()
{
}
BlueLudoPiece::BlueLudoPiece(SDL_Point render_position) : LudoPiece(render_position)
{
}
BlueLudoPiece::~BlueLudoPiece()
{
    // Empty destructor
}

void BlueLudoPiece ::updateBluePiece(Turn &current_turn, int rotated_dice_value)
{

    current_turn = RED_PIECE;

    if (rotated_dice_value == 6 || rotated_dice_value == 1)
    {
        current_turn = BLUE_PIECE;
    }

    if (this->getStatus() == HOME)
    {
        if (rotated_dice_value == 1)
        {
            this->setStatus(RUNNING);
            this->setRenderPositionMovementIndex(this->getRenderPositionMovementIndex() + rotated_dice_value);
            this->setRenderPosition(this->render_position_movement[this->getRenderPositionMovementIndex()]);
            current_turn = BLUE_PIECE;
        }
    }
    else if (this->getStatus() == RUNNING)
    {

        if (this->getRenderPositionMovementIndex() + rotated_dice_value < 56)
        {
            this->setRenderPositionMovementIndex(this->getRenderPositionMovementIndex() + rotated_dice_value);
            this->setRenderPosition(this->render_position_movement[this->getRenderPositionMovementIndex()]);
            std::cout << this->getRenderPositionMovementIndex() << std::endl;
        }
        else if (this->getRenderPositionMovementIndex() + rotated_dice_value == 56)
        {
            this->setRenderPosition({0, 14});
        }
    }
    else if (this->getStatus() == COMPLETED)
    {
    }
}
void BlueLudoPiece::renderBluePiece(Window &window)
{
    SDL_SetRenderDrawColor(window.renderer, 0, 0, 200, 255);
    this->render(window);
}

YellowLudoPiece::YellowLudoPiece()
{
}
YellowLudoPiece::YellowLudoPiece(SDL_Point render_position) : LudoPiece(render_position)
{
}
YellowLudoPiece::~YellowLudoPiece()
{
    // Empty destructor
}

void YellowLudoPiece ::updateYellowPiece(Turn &current_turn, int rotated_dice_value)
{

    current_turn = BLUE_PIECE;

    if (rotated_dice_value == 6 || rotated_dice_value == 1)
    {
        current_turn = YELLOW_PIECE;
    }

    if (this->getStatus() == HOME)
    {
        if (rotated_dice_value == 1)
        {
            this->setStatus(RUNNING);
            this->setRenderPositionMovementIndex(this->getRenderPositionMovementIndex() + rotated_dice_value);
            this->setRenderPosition(this->render_position_movement[this->getRenderPositionMovementIndex()]);

            current_turn = YELLOW_PIECE;
        }
    }
    else if (this->getStatus() == RUNNING)
    {

        if (this->getRenderPositionMovementIndex() + rotated_dice_value < 56)
        {
            this->setRenderPositionMovementIndex(this->getRenderPositionMovementIndex() + rotated_dice_value);
            this->setRenderPosition(this->render_position_movement[this->getRenderPositionMovementIndex()]);
            std::cout << this->getRenderPositionMovementIndex() << std::endl;
        }
        else if (this->getRenderPositionMovementIndex() + rotated_dice_value == 56)
        {
            this->setRenderPosition({0, 14});
        }
    }
    else if (this->getStatus() == COMPLETED)
    {
    }
}
void YellowLudoPiece::renderYellowPiece(Window &window)
{
    SDL_SetRenderDrawColor(window.renderer, 200, 200, 0, 255);
    this->render(window);
}
