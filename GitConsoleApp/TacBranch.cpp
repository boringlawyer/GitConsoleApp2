#include "stdafx.h"
#include "TacBranch.h"


TacBranch::TacBranch()
{
}

TacBranch::TacBranch(string nm, TacCommit * ref, float xParam, float yParam) : TacObject(ref, nm, xParam, yParam)
{
	sprite = RectangleShape(Vector2f(text.getGlobalBounds().width, text.getGlobalBounds().height));
	sprite.setFillColor(Color::Yellow);
	MoveTo(ref->GetCenterOfSprite().x - sprite.getGlobalBounds().width, ref->GetCenterOfSprite().y);
}


TacBranch::~TacBranch()
{
}

void TacBranch::draw(RenderTarget & target, RenderStates states) const
{
	target.draw(sprite);
	target.draw(text);
}

void TacBranch::MoveTo(int newX, int newY)
{
	this->sprite.setPosition(newX, newY);
	this->x = newX;
	this->y = newY;
	this->text.setPosition(newX, newY);
}
