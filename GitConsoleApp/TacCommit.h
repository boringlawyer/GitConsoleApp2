#pragma once
#include "TacObject.h"
class TacCommit : public TacObject
{
public:
	TacCommit();
	TacCommit(git_commit* commitParam, string nm, float xParam, float yParam);
	TacCommit(git_commit* commitParam, TacObject* pnt, string nm, float xParam, float yParam);
	TacCommit(const TacCommit&);
	virtual void draw(RenderTarget &target, RenderStates states) const;
	virtual bool operator==(TacCommit other);
	git_commit* GetGitCommit();
	void AddParent(TacCommit* newParent);
	void AddChild(TacCommit* newChild);
	virtual ~TacCommit();
protected:
	git_commit* commit;
};

