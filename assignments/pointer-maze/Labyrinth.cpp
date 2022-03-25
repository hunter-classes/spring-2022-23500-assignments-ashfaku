#include "Labyrinth.h"
#include <iostream>
bool isPathToFreedom(MazeCell* start, const std::string& moves)
{
	int i = 0;
	bool b = false, p = false, w = false;
	while (i < moves.length())
	{
		if (start == nullptr)
		{
			std::cout << "hi" << std::endl;
			return false;
		}
		//std::cout << moves[i] << std::endl;
		switch (moves[i])
		{
			case 'N':
				start = start->north;
				break;
			case 'W':
				start = start->west;
				break;
			case 'E':
				start = start->east;
				break;
			case 'S':
				start = start->south;
				break;
		}
		if (start->whatsHere == Item::POTION)
                {
                        std::cout << "Potion" <<  std::endl;
                        p = true;
                }
                if (start->whatsHere == Item::WAND)
                {
                        std::cout << "Wand" << std::endl;
                        w = true;
                }
                if (start->whatsHere == Item::SPELLBOOK)
                {
                        std::cout << "Book" << std::endl;
                        b = true;
                }
		i++;
	}
	return b && p && w;
}
