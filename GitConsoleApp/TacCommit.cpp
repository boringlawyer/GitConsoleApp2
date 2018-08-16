#include "stdafx.h"
#include "TacCommit.h"


TacCommit::TacCommit()
{
}

TacCommit::TacCommit(git_commit* commitParam, string nm, float xParam, float yParam) : TacObject(nm, xParam, yParam)
{
	commit = commitParam;
	/*name = nm;
	x = xParam;
	y = yParam;
	*/
	this;
}

TacCommit::TacCommit(git_commit * commitParam, TacObject * pnt, string nm, float xParam, float yParam) : TacObject(pnt, nm, xParam, yParam)
{
	commit = commitParam;
	/*parent = pnt;
	name = nm;
	x = xParam;
	y = yParam;*/
}

TacCommit::TacCommit(const TacCommit &cpy) : TacObject(cpy)
{
	this->commit = cpy.commit;
}

void TacCommit::draw(RenderTarget & target, RenderStates states) const
{
	target.draw(sprite);
	target.draw(text);
}

bool TacCommit::operator==(TacCommit other)
{
	return other.commit == this->commit;
	return false;
}

git_commit * TacCommit::GetGitCommit()
{
	return this->commit;
}

void TacCommit::AddParent(TacCommit * newParent)
{
	if (newParent == nullptr)
	{
		return;
	}
	// if newParent is already in parents, abort
	for (int i = 0; i < this->parents.size(); i++)
	{
		if (newParent == parents[i])
		{
			return;
		}
	}
	this->parents.push_back(newParent);
	hasParent = true;
	SetUpLines();
}

void TacCommit::AddChild(TacCommit * newChild)
{
	if (newChild == nullptr)
	{
		return;
	}
	// if newChild is already in children, abort
	for (int i = 0; i < this->children.size(); i++)
	{
		if (newChild == this->children[i])
		{
			return;
		}
	}
	children.push_back(newChild);
}

/*Vector2f TacCommit::GetCenterOfSprite()
{
	float centerX = (x + sprite.getGlobalBounds().width / 2);
	float centerY = (y + sprite.getGlobalBounds().height / 2);
	return Vector2f(centerX, centerY);
}*/

/*TacObject * TacCommit::GetParent()
{
	return parent;
}*/

/*void TacCommit::SetParent(TacObject * newParent)
{
	if (newParent != nullptr && newParent != (TacObject*)0xcdcdcdcd)
	{
		this->parent = newParent;
		hasParent = true;
		SetUpLines();
	}
}*/


TacCommit::~TacCommit()
{
}

