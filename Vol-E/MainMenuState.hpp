#pragma once

#include "State.hpp"
#include "Button.hpp"
#include "GameState.hpp"
#include "ResourceManager.hpp"


class ResourceManager;
// Main Menu state where we will be pushing all other states to 
// (ex: we will push the Game State first when we press "New Game
class MainMenuState : public State
{

private:

// == RESOURCES ==
ResourceManager mResManager;

Button* mMMButton;
sf::Font mFont;
sf::RectangleShape mBackground;
sf::Texture mBackgroundTex;

std::map<std::string, Button*> mButtonContainer;

// == INITIALIZER FUNCTIONS ==
void initFont();
void initButtons();
void initBG();

public:
// == CONSTRUCTOR/DESTRUCTOR ==
MainMenuState(sf::RenderWindow* Win, std::stack<State*>* States);
virtual ~MainMenuState();

// == MAIN FUNCTIONS ==
void cleanUpState() override;
void updateKeyInputs() override;
void checkEndState() override;
void updateButtons();
void updateState(const float& dt) override;
void renderButtons(sf::RenderTarget* targetWin);
void renderState(sf::RenderTarget* targetWin) override;


};