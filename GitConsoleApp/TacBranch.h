#pragma once
#include "TacObject.h"
#include "TacCommit.h"
using namespace sf;
class TacBranch :
	public TacObject
{
public:
	TacBranch();
	TacBranch(string nm, TacCommit * ref, float xParam, float yParam);
	virtual ~TacBranch();
	void draw(RenderTarget &target, RenderStates states) const;
private:
	RectangleShape sprite;
	void MoveTo(int newX, int newY);
};