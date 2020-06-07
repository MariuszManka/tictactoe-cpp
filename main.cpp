//_________________________TODO_______________________________//
/*
1) Doda� opcj� vs AI i konieczn� logik�,
2) Porozdziela� projekt na osobne pliki (rozdzieli� klas� Board na osobne klasy???)
3) Doda� obs�ug� b��d�w (gdy podamy przy wyborze pola co� innego ni� licz� od 1 do 9 - linijka 132 - opcja default w switch'u)
4) Zastowsowa� jakie� techniki kt�re by�y na zaj�ciach (Wzorce, Dziedziczenie, Polimorfizm, Funkcje zaprzyja�nione idk)???
_________________________________________________________________
*/

#include <iostream>
#include<Windows.h>
#include <locale.h>

using namespace std;

class Board {
	char matrix[3][3] = { '1', '2', '3','4','5', '6', '7', '8', '9' };//Tablica 2-wymiarowa z kt�rej tworzona jest plansza do gry
	char player; //Przechowuje informacje o tym czyja aktualnie jest kolejka (X czy O)
	int userFieldChoice; //Przechowuje informacje o tym kt�re pole z planszy wybra� gracz (od 1 do 9)
	int n = 0;//Liczba tur gry

public:	
	Board(char p) : player(p) {} //Konstruktor parametryczny
	Board() {//Gdy parametryczny nie jest podany wywo�uje si� domy�lny
		this->player = 'X';
	 }

private:
//Funkcja rysuj�ca plansz� do gry
	void Draw() {
		cout << "Kolej gracza: " << this->player<<" \n" << endl;
		for (int i = 0; i < 3; i++) { //P�tla rysuj�ca plansz�
			for (int j = 0; j < 3; j++) {
				cout << this->matrix[i][j] << " ";
			}
			cout<<endl;
		}
	}

//Funkcja kt�ra uzupe�nia tablic� X albo O w zale�no��ci od tego jakie pole wybra�� u�ytkownik (userFieldChoice).
	void Input() {
		cout << "\n\n Wybierz pole: ";
		cin >> this->userFieldChoice;

		switch (this->userFieldChoice) { //Uzupe�nianie planszy X i O oraz sprawdzanie czy dane pole nie jest ju� zaj�te
		case 1:
			if (this->matrix[0][0] == '1')
				this->matrix[0][0] = this->player;

			else {
				cout << "To pole jest ju� zaj�te, prosz� wybr�� inne!";
				this->Input();
			}			
			break;

		case 2:
			if (this->matrix[0][1] == '2')
				this->matrix[0][1] = this->player;
			else {
				cout << "To pole jest ju� zaj�te, prosz� wybr�� inne!";
				this->Input();
			}
			
			break;

		case 3:
			if (this->matrix[0][2] == '3')
				this->matrix[0][2] = this->player;
			else {
				cout << "To pole jest ju� zaj�te, prosz� wybr�� inne!";
				this->Input();
			}
			break;

		case 4:
			if (this->matrix[1][0] == '4')
				this->matrix[1][0] = this->player;
			else {
				cout << "To pole jest ju� zaj�te, prosz� wybr�� inne!";
				this->Input();
			}
			break;

		case 5:
			if (this->matrix[1][1] == '5')
				this->matrix[1][1] = this->player;
			else {
				cout << "To pole jest ju� zaj�te, prosz� wybr�� inne!";
				this->Input();
			}
			break;

		case 6:
			if (this->matrix[1][2] == '6')
				this->matrix[1][2] = this->player;
			else {
				cout << "To pole jest ju� zaj�te, prosz� wybr�� inne!";
				this->Input();
			}
			break;

		case 7:
			if (this->matrix[2][0] == '7')
				this->matrix[2][0] = this->player;
			else {
				cout << "To pole jest ju� zaj�te, prosz� wybr�� inne!";
				this->Input();
			}
			break;

		case 8:
			if (this->matrix[2][1] == '8')
				this->matrix[2][1] = this->player;
			else {
				cout << "To pole jest ju� zaj�te, prosz� wybr�� inne!";
				this->Input();
			}
			break;

		case 9:
			if (this->matrix[2][2] == '9')
				this->matrix[2][2] = this->player;
			else {
				cout << "To pole jest ju� zaj�te, prosz� wybr�� inne!";
				this->Input();
			}
			break;

		default:
			system("cls");
			cout << "Nie ma takiego pola, prosz� wybra� inne!";
			//TODO obs�u�y� klikni�cie czego� innego ni� liczy od 1 do 9.!!!
		}
	}

	//Funkcja kt�ra prze��cza graczy.
	void TogglePlayer() {

			if (this->player == 'X')
				this->player = 'O';
			else
				this->player = 'X';
	}

	//Funkcja sprawdzaj�ca czy gracz wygra�, jako parametr przyjmuje "player" kt�ry jest albo X albo O.
	char Win(char player) {

		//Sprawdzanie wierszy
		if (matrix[0][0] == player && matrix[0][1] == player && matrix[0][2] == player)      //1 2 3
			return player;
		else if (matrix[1][0] == player && matrix[1][1] == player && matrix[1][2] == player) //4 5 6
			return player;
		else if (matrix[2][0] == player && matrix[2][1] == player && matrix[2][2] == player) // 7 8 9
			return player;

		//Sprawdzanie kolumn
		else if (matrix[0][0] == player && matrix[1][0] == player && matrix[2][0] == player) //1 4 7
			return player;
		else if (matrix[0][1] == player && matrix[1][1] == player && matrix[2][1] == player) //2 5 8
			return player;
		else if (matrix[0][2] == player && matrix[1][2] == player && matrix[2][2] == player) //3 6 9
			return player;

		//Sprawdzanie przek�tnych
		else if (matrix[0][0] == player && matrix[1][1] == player && matrix[2][2] == player) //1 5 9
			return player;
		else if (matrix[2][0] == player && matrix[1][1] == player && matrix[0][2] == player) //3 5 7
			return player;

			return '-';//Je�li �adna z powy�szych zwracamy "-"
	}

public:
	//Funkcja odpowiedzialna za rozgrywk�
	void TicTacToeGame() {
		while(this->Win(this->player) == '-') {//P�tla kt�ra ko�czy si� gdy wygra kt�ry� z graczy (Funkcja Win zwr�ci co� innego ni� "-")
			system("cls");
			this->n++;//Tura zwi�kszana o 1
			this->Draw(); 
			this->Input();
			if (this->Win(this->player) == '-') {//Je�li nikt nie wygra� prze��czamy graczy
				if (this->n != 9)//Sprawdzamy czy gra dalej trwa (nie sko�czy�y si� wszystkie tury)
					this->TogglePlayer();
				else if (this->n == 9) {//Je�li nikt nie wygra� do 9 tury oznacza to remis
					system("cls");
					this->Draw();
					cout << "Remis! Zagraj ponownie!";
					return;
				}
			}
			else {//Przypadek gdy wygra jeden z graczy
				system("cls");
				this->Draw();
				cout << "Wygra� gracz: " << this->player<<"!"<<endl;
				return;
			}	
		}
	}

	virtual ~Board() { //Destruktor obiektu
		cout << "\nDzi�kujemy za skorzystanie z naszego programu, pozdrawiaj� Mariusz Ma�ka oraz Tymoteusz Ma�kowski!\n";
	};
};


//Funkcja  poza klas� pozwalaj�ca na wybranie gracza kt�ry ma zaczyna�
char WhichPlayer() {
	char choice;
	system("cls");
	cout << "Kt�ry gracz ma zaczyna�? ";
	cin >> choice;
	if (choice == 'X')
		return 'X';
	else if (choice == 'O')
		return 'O';
	else return 'X'; //W ka�dym innym przypadku domy�lnie zwracamy X
}


int main() {
	setlocale(LC_CTYPE, "Polish");

	int gamechoice; //Wyb�r trybu gry

	cout << "Wybierz tryb gry"<<endl;
	cout << "1 - Dwuosobowa lokalna\n2 - vs AI\n3 - Wyjd� z gry\n\n\n";
	cout << "Wybieram: ";
	cin >> gamechoice;
	if (gamechoice == 1)
	{
		Board game(WhichPlayer()); //Instancja klasy, wywo�uje konstruktor parametryczny, parametr jest zwracany z funkcji WhichPlayer;
		game.TicTacToeGame();
	}
	else if (gamechoice == 2)
	{
		cout << "debug 2";
	}
	else if (gamechoice == 3)
	{
		system("cls");
		cout << "Dzi�kujemy za gr�!";
		return 0;
	}
	else
	{
		cout << "debug niepoprawna liczba";
	}
	return 0;
}
