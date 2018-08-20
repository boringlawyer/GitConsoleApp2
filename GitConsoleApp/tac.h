#pragma once
#include <vector>
#include "TacObject.h"
#include "TacCommit.h"
#include <map>
void BuildTacTree(/*vector<TacCommit*> &objects, git_commit* current*/);
void BuildChild_Parents(git_commit* branchCommit);
void BuildGit_Tac();
extern int placeY;