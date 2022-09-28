#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Graphics/Texture.hpp"

class AnimationComponent
{
private:

	static constexpr int nFrames = 8;
	static constexpr float nHoldTime = 0.1f;
	int iFrame = 0;
	float iFramreTime = 0.0f;

	sf::Texture aTexture;
	sf::IntRect mFrames[nFrames];
	
public:
	AnimationComponent(int x, int y, int width, int height)
	{
		aTexture.loadFromFile("res/textures/drifter_walk_cycle.png");
		for (int i{ 0 }; i < nFrames; ++i)
		{
			mFrames[i] = { x + i * width, y, x + (i + 1) * width, y + height };
		}
	}

	void animateSprite(sf::Sprite& spr) const
	{
		spr.setTexture(aTexture);
		spr.setTextureRect(mFrames[iFrame]);
	}

	void updateAnimation(const float& dt)
	{

	}

};