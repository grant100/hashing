#include "stdafx.h"
#include "Hash.h"

//Constructor definition
Hash::Hash()
{
	for (entry_val i = 0; i < MAX; i++)
	{
		hashTable[i] = INITIALIZE;
	}		
}

// Function Name: insert(entry_val data)
// Purpose:	 insert key into hash table
// Parameters: entry_val
// Returns:	  void
// Pre-conditions: none	
// Post-conditions: data inserted
void Hash::insert(entry_val data)
{
	entry_val hashValue = INITIALIZE;
	hashValue = getHash(data);
	if (Collision(hashValue, data) == false)//collision check
	{		
		resolveCollision(hashValue, data);
	}
	else
	{
		cout << "\n" << "Inserted: Location: ("<<hashValue<<")"<<" Value (" << data<<")";
		hashTable[hashValue] = data;
	}
}

// Function Name: getHash(entry_val data)
// Purpose:	 get hash value
// Parameters: entry_val
// Returns:	  entry_val
// Pre-conditions: none	
// Post-conditions: hash value
entry_val Hash::getHash(entry_val data)
{
	return data%MAX;//hash generator
}

// Function Name: Collision( entry_val hashValue, entry_val data)
// Purpose:	check for collision of hash values
// Parameters: entry_val
// Returns:	  bool
// Pre-conditions: none	
// Post-conditions: none
bool Hash::Collision( entry_val hashValue, entry_val data)
{
	if (hashTable[hashValue] != INITIALIZE)
	{		
		return false;
	}
	else
	{
		return true;
	}
}

// Function Name: traverseHash()
// Purpose:	check for collision of hash values
// Parameters: none
// Returns:	  void
// Pre-conditions: none	
// Post-conditions: display location and data value
void Hash::traverseHash()
{
	cout << "\nElement    Value";
	for (int i = 0; i < MAX; i++)
	{
		cout << "\n  " << i << "         " << hashTable[i];
	}
}

// Function Name: resolveCollision(entry_val &hashValue, entry_val data)
// Purpose:	resolve collisions
// Parameters: none
// Returns:	  void
// Pre-conditions: Collision == false	
// Post-conditions: collision in hash table is resolved
void Hash::resolveCollision(entry_val &hashValue, entry_val data)
{
	int loop_cnt = 0;
	int original_location = hashValue;
	while (hashTable[hashValue] != INITIALIZE  && loop_cnt < MAX - 1 && hashTable[hashValue]!=data)
	{
		if (hashValue == MAX - 1 && hashTable[hashValue] != INITIALIZE)
		{
			hashValue = 0;//end of array, begin loop from index 0
			loop_cnt++;
		}
		else
		{
			hashValue++;
			loop_cnt++;
		}			
	}

	if (hashTable[hashValue] == data)//dupes
	{
		cout << "\n" << "Duplicate Data ("<<data<<") not inserted...";
	}
	else
	{
		if (loop_cnt == MAX - 1 && hashTable[hashValue] != INITIALIZE)//table is full (looped through MAX-1 times without getting an uninitialized index) 
		{
			cout << "\n" << "Hash Table is full (" << data << ") not inserted....";
		}
		else
		{
			cout << "\nCollision: location (" << original_location << "): New location: ("<<hashValue<<") Inserted: (" << data << ")";
			hashTable[hashValue] = data;
		}
	}		
}

// Function Name: clear()
// Purpose:	clear data out of hash table
// Parameters: none
// Returns:	  void
// Pre-conditions: none	
// Post-conditions: hash table cleared
void Hash::clear()
{
	for (entry_val i = 0; i < MAX; i++)
	{
		hashTable[i] = INITIALIZE;
	}
}