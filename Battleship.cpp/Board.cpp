#include <iostream>
#include <string>


// TESTING GIT RESET COMMANDS

using namespace std;



class Board
{
public:

	int board_size;
	char** board;
	int ships_remaining = 5;
	bool carrier_sunk = false; int carrier_life = 5;
	bool battleship_sunk = false; int battleship_life = 4;
	bool submarine_sunk = false; int submarine_life = 4;
	bool destroyer_sunk = false; int destroyer_life = 3;
	bool patrol_sunk = false; int patrol_life = 2;
	


Board(int size)
{
	board_size = size;

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
	for (int i = 0; i < board_size; i++)
	{
		for (int x = 0; x < board_size; x++)
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
			if (!(y_coord <= board_size - ship_size) || y_coord < 0 || y_coord > board_size)
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
			if (!(x_coord <= board_size - ship_size) || x_coord < 0 || x_coord > board_size)
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



	int process_fire(int x_coord, int y_coord)
	{
		char check_tile = board[y_coord][x_coord];

		switch (check_tile)
		{
		case('-') :
			cout << "Shot missed!" << endl;
			return 0;
		case('C') :
			cout << "Hit!" << endl;
			carrier_life -= 1;
			board[y_coord][x_coord] = '*';
			if (carrier_life == 0)
			{
				carrier_sunk = true;
				ships_remaining -= 1;
				cout << "Ship sunk!" << endl;
				if (ships_remaining == 0)
				{
					cout << "All ships sunk! Game over!" << endl;
					return 3;
				}
			}
			return 1;
		case('B') :
			cout << "Hit!" << endl;
			battleship_life -= 1;
			board[y_coord][x_coord] = '*';
			if (battleship_life == 0)
			{
				battleship_sunk = true;
				ships_remaining -= 1;
				cout << "Ship sunk!" << endl;
				if (ships_remaining == 0)
				{
					cout << "All ships sunk! Game over!" << endl;
					return 3;
				}
			}
			return 1;
		case('S') :
			cout << "Hit!" << endl;
			submarine_life -= 1;
			board[y_coord][x_coord] = '*';
			if (submarine_life == 0)
			{
				submarine_sunk = true;
				ships_remaining -= 1;
				cout << "Ship sunk!" << endl;
				if (ships_remaining == 0)
				{
					cout << "All ships sunk! Game over!" << endl;
					return 3;
				}
			}
			return 1;
		case('D') :
			cout << "Hit!" << endl;
			destroyer_life -= 1;
			board[y_coord][x_coord] = '*';
			if (destroyer_life == 0)
			{
				destroyer_sunk = true;
				ships_remaining -= 1;
				cout << "Ship sunk!" << endl;
				if (ships_remaining == 0)
				{
					cout << "All ships sunk! Game over!" << endl;
					return 3;
				}
			}
			return 1;
		case('P') :
			cout << "Hit!" << endl;
			patrol_life -= 1;
			board[y_coord][x_coord] = '*';
			if (patrol_life == 0)
			{
				patrol_sunk = true;
				ships_remaining -= 1;
				cout << "Ship sunk!" << endl;
				if (ships_remaining == 0)
				{
					cout << "All ships sunk! Game over!" << endl;
					return 3;
				}
			}
			return 1;
		case('*') :
			cout << "You already shot there! Pick new coordinates!" << endl;
			return 2;
		}
	}




};



class Player
{
public:


	Board* player_board;


	Player(int board_size)
	{
		player_board = new Board(board_size);
	}

	// Returns pointer to array containing firing coordinates
	int* fire_weapon()
	{
		int y_coords;
		int x_coords;


		cout << "Enter x coordinates: ";
		cin >> y_coords;
		cout << endl;
		cout << "Enter y coordinates: ";
		cin >> x_coords;

		int* output = new int[2];
		output[0] = y_coords;
		output[1] = x_coords;

		return output;
	}


	Board* get_board()
	{
		return player_board;
	}
};


void run_game(Player* player1, Player* player2)
{
	Board* player1_board = player1->get_board();
	Board* player2_board = player2->get_board();
	int* firing_coordinates;

	int game_code1 = 0;
	int game_code2 = 0;

	while (game_code1 != 3 && game_code2 != 3)
	{

		while (true)
		{
			cout << "Player 1's turn to fire!!!" << endl;
			cout << endl;
			firing_coordinates = player1->fire_weapon();
			game_code1 = player2_board->process_fire(firing_coordinates[0], firing_coordinates[1]);
			delete[] firing_coordinates;
			player2_board->Display_Board();

			if (game_code1 == 2)
			{
				continue;
			}
			else
			{
				break;
			}
			
		}

		while (true)
		{
			cout << "Player 2's turn to fire!!!" << endl;
			cout << endl;
			firing_coordinates = player2->fire_weapon();
			game_code2 = player1_board->process_fire(firing_coordinates[0], firing_coordinates[1]);
			delete[] firing_coordinates;
			player1_board->Display_Board();

			if (game_code2 == 2)
			{
				continue;
			}
			else
			{
				break;
			}
		}

		

		
	}
}









int main()
{
	int size;
	cout << "How big would you like the board to be? (int): ";
	cin >> size;


	Player* player_1 = new Player(size);
	Player* player_2 = new Player(size);

	cout << "Player 1's turn to place ships!" << endl;
	cout << endl;
	player_1->player_board->Place_All_Ships();
	cout << endl;
	cout << "Player 2's turn to place ships!" << endl;
	cout << endl;
	player_2->player_board->Place_All_Ships();


	run_game(player_1, player_2);

	
	return 0;
}
