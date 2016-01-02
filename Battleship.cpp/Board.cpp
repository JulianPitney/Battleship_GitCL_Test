#include <iostream>
#include <string>


// TESTING GIT RESET COMMANDS

using namespace std;



class Board
{
public:

	int size;
	char** board;

Board()
{
	cout << "How big would you like the board to be? (int): ";
	cin >> size;

	board = new char*[size];

	for (int i = 0; i < size; i++)
	{
		board[i] = new char[size];

		for (int x = 0; x < size; x++)
		{
			board[i][x] = '-';
		}
	}
}


void Display_Board()
{
	for (int i = 0; i < size; i++)
	{
		for (int x = 0; x < size; x++)
		{
			cout << board[i][x] << " ";
		}

		cout << endl;
	}
}

void Place_All_Ships()
{
	char* ships = new char[5];
	int* sizes = new int[5];
	string* names = new string[5];

	ships[0] = 'C'; sizes[0] = 5; names[0] = "Aircraft Carrier";
	ships[1] = 'B'; sizes[1] = 4; names[1] = "Battleship";
	ships[2] = 'S'; sizes[2] = 3; names[2] = "Submarine";
	ships[3] = 'D'; sizes[3] = 3; names[3] = "Destroyer";
	ships[4] = 'P'; sizes[4] = 2; names[4] = "Patrol";

	int i = 0;

	while (i < 5)
	{
		cout << "Place " << names[i] << "!" << endl;
		if (Place_Ship(ships[i], sizes[i]) == true)
		{
			i++;
		}
		else
		{
			continue;
		}

	}
}


bool Place_Ship(char ship_type, int ship_size)
{
	bool is_vertical = true;
	string orientation;
	int x_coord;
	int y_coord;

	cout << "Enter orientation (vertical/horizontal): ";
	cin >> orientation;

	if (orientation == "horizontal")
	{
		is_vertical = false;
	}
	else if (orientation != "vertical")
	{
		cout << "Invalid choice, aborting shit placement!" << endl;
		return false;
	}

	cout << "Enter x coord: ";
	cin >> x_coord;
	cout << endl;
	cout << "Enter y coord: ";
	cin >> y_coord;
	cout << endl;

	
	return Check_And_Place(ship_size, ship_type, is_vertical, y_coord, x_coord);

	}

	bool Check_And_Place(int ship_size, char ship_type, bool is_vertical, int y_coord, int x_coord)
	{
		if (is_vertical)
		{
			if (!(y_coord <= size - ship_size))
			{
				cout << "Invalid coords, ship falls off board! Aborting placement." << endl;
				return false;
			}

			for (int y = y_coord; y < y_coord + ship_size; y++)
			{
				if (board[y][x_coord] == '-')
				{
					continue;
				}
				else
				{
					cout << "Invalid placement (ship off board or space occupied)" << endl;
					cout << "Aborting ship placement" << endl;
					return false;
				}
			}

			for (int y = y_coord; y < y_coord + ship_size; y++)
			{
				board[y][x_coord] = ship_type;
			}

		}
		else
		{
			if (!(x_coord <= size - ship_size))
			{
				cout << "Invalid coords, ship falls off board! Aborting placement." << endl;
				return false;
			}

			for (int x = x_coord; x < x_coord + ship_size; x++)
			{
				if (board[y_coord][x] == '-')
				{
					continue;
				}
				else
				{
					cout << "Invalid placement (ship off board or space occupied)" << endl;
					cout << "Aborting ship placement" << endl;
					return false;
				}
			}

			for (int x = x_coord; x < x_coord + ship_size; x++)
			{
				board[y_coord][x] = ship_type;
			}
		}

		cout << "Ship placed succesfully!" << endl;
		return true;
	}

};






int main()
{
	Board* test1 = new Board();
	
	test1->Place_All_Ships();
	test1->Display_Board();


	return 0;
}
