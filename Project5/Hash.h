#pragma once

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;
typedef int entry_val;

//constants
const entry_val  MAX = 20;
const entry_val  INITIALIZE = -999;

class Hash
{
public:
	Hash();
	entry_val hashTable[MAX];
	entry_val getHash(entry_val);
	void insert(entry_val);
	bool Collision(entry_val, entry_val);
	void traverseHash();
	void resolveCollision(entry_val&, entry_val);
	void clear();

};