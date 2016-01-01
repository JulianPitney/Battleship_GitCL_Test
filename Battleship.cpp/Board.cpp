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


void Place_Ship()
{
	bool is_vertical = true;
	string orientation;
	int x_coord;
	int y_coord;

	int Carrier_Size = 5;
	int Battleship_Size = 4;
	int Submarine_Size = 3;
	int Destroyer_Size = 3;
	int Patrol_Size = 2;
	char Choice;

	cout << "Choose ship type" << endl;
	cout << "[1] Aircraft Carrier (5)" << endl;
	cout << "[2] Battleship (4)" << endl;
	cout << "[3] Submarine (3)" << endl;
	cout << "[4] Destroyer (3)" << endl;
	cout << "[5] Patrol (2)" << endl;
	cout << "Choice: ";
	cin >> Choice;




	cout << "Enter orientation (vertical/horizontal): ";
	cin >> orientation;

	if (orientation == "horizontal")
	{
		is_vertical = false;
	}
	else if (orientation != "vertical")
	{
		cout << "Invalid choice, aborting shit placement!" << endl;
		return;
	}

	cout << "Enter x coord: ";
	cin >> x_coord;
	cout << endl;
	cout << "Enter y coord: ";
	cin >> y_coord;
	cout << endl;

	switch (Choice)
	{
		case('1') :
			Check_And_Place(Carrier_Size, 'C', is_vertical, y_coord, x_coord);
		case('2') :
			Check_And_Place(Battleship_Size, 'B', is_vertical, y_coord, x_coord);
		case('3') :
			Check_And_Place(Submarine_Size, 'S', is_vertical, y_coord, x_coord);
		case('4') :
			Check_And_Place(Destroyer_Size, 'D', is_vertical, y_coord, x_coord);
		case('5') :
			Check_And_Place(Patrol_Size, 'P', is_vertical, y_coord, x_coord);

	}



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
	
	for (int i = 0; i < 5; i++)
	{
		test1->Place_Ship();
		test1->Display_Board();
	}


	return 0;
}
