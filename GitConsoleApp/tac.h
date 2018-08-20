#pragma once
#include <vector>
#include "TacObject.h"
#include "TacCommit.h"
#include <map>
bool AddTacCommit(vector<TacCommit*> &commits, TacCommit* newTacCommit);
void AttachObjects(vector<TacCommit*> &objects, TacCommit* child, int yParam);
TacCommit* FindExistingTacCommit(vector<TacCommit*> objects, git_commit* current);
void BuildTacTree(/*vector<TacCommit*> &objects, git_commit* current*/);
void BuildChild_Parents(git_commit* branchCommit);
void BuildGit_Tac();
extern int placeY;
// maps a commit to its parents
//extern map<git_commit*, vector<git_commit*>> child_Parents;
// maps the git_commit to the derived TacCommit
//extern map<git_commit*, TacCommit*> git_Tac;