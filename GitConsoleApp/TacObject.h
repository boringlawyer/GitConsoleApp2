#pragma once
#include <git2.h>
#include <SFML\Graphics.hpp>
#include <SFML\Graphics\Drawable.hpp>
#include <string>
#include <vector>
using namespace sf;
using namespace std;
class TacObject : public Drawable
{
public:
	TacObject();
	TacObject(string nm, float xParam, float yParam);
	TacObject(vector<TacObject*> pnt, string nm, float xParam, float yParam);
	TacObject(TacObject* pnt, string nm, float xParam, float yParam);
	TacObject(const TacObject&);
	virtual void DrawLines(RenderTarget &target);
	virtual void draw(RenderTarget &target, RenderStates states) const;
	virtual Vector2f GetCenterOfSprite();
	virtual ~TacObject();
	virtual vector<TacObject*> GetParents();
	virtual void AddParent(TacObject* newParent);
	virtual void AddChild(TacObject* newChild);
	virtual void PlaceChildren();
	virtual void FixChildrenWithMultipleParents();
protected:
	vector<TacObject*> parents;
	vector<TacObject*> children;
	bool hasParent;
	string name;
	CircleShape sprite;
	//RectangleShape line;
	vector<RectangleShape> lines;
	virtual void SetUpLines();
	virtual void Move(int deltaX, int deltaY);
	virtual void MoveTo(int newX, int newY);
	static Font font;
	Text text;
	float x;
	float y;
	Vector2f lineAnchor;
	Vector2f lineOffset;
};