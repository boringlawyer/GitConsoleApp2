#pragma once
#include <vector>
#include "TacObject.h"
#include "TacCommit.h"
bool AddTacCommit(vector<TacCommit*> &commits, TacCommit* newTacCommit);
void AttachParent(vector<TacCommit*> &objects, TacCommit* child, int yParam);
void AttachObjects(vector<TacCommit*> &objects, TacCommit* child, int yParam);
TacCommit* FindExistingTacCommit(vector<TacCommit*> objects, git_commit* current);
void BuildTacTree(vector<TacCommit*> &objects, git_commit* current);
extern int placeY;