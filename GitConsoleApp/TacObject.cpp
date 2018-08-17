#include "stdafx.h"
#include "TacObject.h"
#ifndef _USE_MATH_DEFINES
#define _USE_MATH_DEFINES
#endif // !_USE_MATH_DEFINES

#include <math.h>
Font TacObject::font;
TacObject::TacObject()
{
	sprite = CircleShape(50);
	sprite.setFillColor(Color(255, 0, 0));
	hasParent = false;
}

TacObject::TacObject(string nm, float xParam, float yParam)
{
	x = xParam;
	y = yParam;
	sprite = CircleShape(50);
	sprite.setPosition(x, y);
	sprite.setFillColor(Color(255, 0, 0));
	name = nm;
	if (font.getInfo().family == "")
	{
		TacObject::font.loadFromFile("C:\\Users\\Caleb\\Documents\\Github\\GitConsoleApp2\\Debug\\Montserrat-Regular.ttf");
	}
	text.setFont(TacObject::font);
	text.setString(name);
	text.setCharacterSize(24);
	text.setFillColor(sf::Color::Black);
	// places text
	text.setPosition(x, y);
	text.move(-(text.getLocalBounds().width) / 3, sprite.getLocalBounds().height / 2 + text.getLocalBounds().height);
	hasParent = false;
	//SetUpLines();
}

TacObject::TacObject(vector<TacObject*> pnt, string nm, float xParam, float yParam) : TacObject(nm, xParam, yParam)
{
	parents = pnt;
	SetUpLines();
}

TacObject::TacObject(TacObject * pnt, string nm, float xParam, float yParam) : TacObject(nm, xParam, yParam)
{
	AddParent(pnt);
	SetUpLines();
}

TacObject::TacObject(const TacObject& cpy)
{
	this->name = cpy.name;
	this->sprite = cpy.sprite;
	this->text = cpy.text;
	this->x = cpy.x;
	this->y = cpy.y;
	if (hasParent)
	{
		this->parents = cpy.parents;
		this->hasParent = true;
		SetUpLines();
	}
	else
	{
		this->hasParent = false;
	}
}
// draw all of the lines
void TacObject::DrawLines(RenderTarget &target)
{
	for (RectangleShape line : lines)
	{
		target.draw(line);
	}
}

void TacObject::draw(RenderTarget &target, RenderStates states) const
{
	target.draw(sprite);
	target.draw(text);

}

Vector2f TacObject::GetCenterOfSprite()
{
	float centerX = (sprite.getPosition().x + (sprite.getGlobalBounds().width) / 2);
	float centerY = (sprite.getPosition().y + (sprite.getGlobalBounds().height) / 2);
	return Vector2f(centerX, centerY);
}

TacObject::~TacObject()
{
}

vector<TacObject*> TacObject::GetParents()
{
	return parents;
}

void TacObject::AddParent(TacObject * newParent)
{
	if (newParent != nullptr && newParent != (TacObject*)0xcdcdcdcd)
	{
		this->parents.push_back(newParent);
		hasParent = true;
		SetUpLines();
	}
}

void TacObject::AddChild(TacObject * newChild)
{
	if (newChild != nullptr)
	{
		children.push_back(newChild);
	}
}

void TacObject::PlaceChildren()
{
	int numChildren = this->children.size();
	if (numChildren  <= 1)
	{
		return;
	}
	int placeX = -((numChildren - 1) * 300) / 2;
	for (int i = 0; i < numChildren; i++, placeX += 300)
	{
		this->children[i]->Move(placeX, 0);
		//this->children[i]->SetUpLines();
	}
	//this->SetUpLines();
}

void TacObject::AverageLocations(vector<TacObject*> objects)
{
	Vector2f result(0, 0);
	for (int i = 0; i < objects.size(); i++)
	{
		result += objects[i]->GetCenterOfSprite();
	}
	result.x /= objects.size();
	result.y /= objects.size();
}

void TacObject::SetUpLines()
{
	lines.clear();
	if (hasParent)
	{
		for (TacObject* parent : parents)
		{
			float xDistance = this->GetCenterOfSprite().x - parent->GetCenterOfSprite().x;
			float yDistance = this->GetCenterOfSprite().y - parent->GetCenterOfSprite().y;
			float distance = sqrt(pow(xDistance, 2) + pow(yDistance, 2));
			RectangleShape line = RectangleShape(Vector2f(5, distance));
			line.setOrigin(2.5, 0);
			line.setPosition(this->GetCenterOfSprite());
			float angle;
			if (xDistance == 0)
			{
				angle = 0;
			}
			else
			{
				angle = atan(yDistance / xDistance) * (-180 / M_PI);
				if (this->GetCenterOfSprite().x < parent->GetCenterOfSprite().x)
				{
					angle += 45;
				}
				else
				{
					angle += 315;
				}
			}
			line.setRotation(angle);
			line.setFillColor(Color::Black);
			lines.push_back(line);
		}
	}
}

void TacObject::Move(int deltaX, int deltaY)
{
	this->sprite.move(deltaX, deltaY);
	this->x += deltaX;
	this->y += deltaY;
	this->text.move(deltaX, deltaY);
	this->SetUpLines();
	for (int i = 0; i < this->children.size(); i++)
	{
		this->children[i]->Move(deltaX, deltaY);
	}

}

void TacObject::MoveTo(int newX, int newY)
{
	this->sprite.setPosition(newX, newY);
	this->x = newX;
	this->y = newY;
	this->SetUpLines();
}
