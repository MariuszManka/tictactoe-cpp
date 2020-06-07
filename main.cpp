//_________________________TODO_______________________________//
/*
1) Dodaæ opcjê vs AI i konieczn¹ logikê,
2) Porozdzielaæ projekt na osobne pliki (rozdzieliæ klasê Board na osobne klasy???)
3) Dodaæ obs³ugê b³êdów (gdy podamy przy wyborze pola coœ innego ni¿ liczê od 1 do 9 - linijka 132 - opcja default w switch'u)
4) Zastowsowaæ jakieœ techniki które by³y na zajêciach (Wzorce, Dziedziczenie, Polimorfizm, Funkcje zaprzyjaŸnione idk)???
_________________________________________________________________
*/

#include <iostream>
#include<Windows.h>
#include <locale.h>

using namespace std;

class Board {
	char matrix[3][3] = { '1', '2', '3','4','5', '6', '7', '8', '9' };//Tablica 2-wymiarowa z której tworzona jest plansza do gry
	char player; //Przechowuje informacje o tym czyja aktualnie jest kolejka (X czy O)
	int userFieldChoice; //Przechowuje informacje o tym które pole z planszy wybra³ gracz (od 1 do 9)
	int n = 0;//Liczba tur gry

public:	
	Board(char p) : player(p) {} //Konstruktor parametryczny
	Board() {//Gdy parametryczny nie jest podany wywo³uje siê domyœlny
		this->player = 'X';
	 }

private:
//Funkcja rysuj¹ca planszê do gry
	void Draw() {
		cout << "Kolej gracza: " << this->player<<" \n" << endl;
		for (int i = 0; i < 3; i++) { //Pêtla rysuj¹ca planszê
			for (int j = 0; j < 3; j++) {
				cout << this->matrix[i][j] << " ";
			}
			cout<<endl;
		}
	}

//Funkcja która uzupeˆnia tablicê X albo O w zale¿noœ˜ci od tego jakie pole wybraˆæ u¿ytkownik (userFieldChoice).
	void Input() {
		cout << "\n\n Wybierz pole: ";
		cin >> this->userFieldChoice;

		switch (this->userFieldChoice) { //Uzupe³nianie planszy X i O oraz sprawdzanie czy dane pole nie jest ju¿ zajête
		case 1:
			if (this->matrix[0][0] == '1')
				this->matrix[0][0] = this->player;

			else {
				cout << "To pole jest ju¿ zajête, proszê wybr¹æ inne!";
				this->Input();
			}			
			break;

		case 2:
			if (this->matrix[0][1] == '2')
				this->matrix[0][1] = this->player;
			else {
				cout << "To pole jest ju¿ zajête, proszê wybr¹æ inne!";
				this->Input();
			}
			
			break;

		case 3:
			if (this->matrix[0][2] == '3')
				this->matrix[0][2] = this->player;
			else {
				cout << "To pole jest ju¿ zajête, proszê wybr¹æ inne!";
				this->Input();
			}
			break;

		case 4:
			if (this->matrix[1][0] == '4')
				this->matrix[1][0] = this->player;
			else {
				cout << "To pole jest ju¿ zajête, proszê wybr¹æ inne!";
				this->Input();
			}
			break;

		case 5:
			if (this->matrix[1][1] == '5')
				this->matrix[1][1] = this->player;
			else {
				cout << "To pole jest ju¿ zajête, proszê wybr¹æ inne!";
				this->Input();
			}
			break;

		case 6:
			if (this->matrix[1][2] == '6')
				this->matrix[1][2] = this->player;
			else {
				cout << "To pole jest ju¿ zajête, proszê wybr¹æ inne!";
				this->Input();
			}
			break;

		case 7:
			if (this->matrix[2][0] == '7')
				this->matrix[2][0] = this->player;
			else {
				cout << "To pole jest ju¿ zajête, proszê wybr¹æ inne!";
				this->Input();
			}
			break;

		case 8:
			if (this->matrix[2][1] == '8')
				this->matrix[2][1] = this->player;
			else {
				cout << "To pole jest ju¿ zajête, proszê wybr¹æ inne!";
				this->Input();
			}
			break;

		case 9:
			if (this->matrix[2][2] == '9')
				this->matrix[2][2] = this->player;
			else {
				cout << "To pole jest ju¿ zajête, proszê wybr¹æ inne!";
				this->Input();
			}
			break;

		default:
			system("cls");
			cout << "Nie ma takiego pola, proszê wybraæ inne!";
			//TODO obs³u¿yæ klikniêcie czegoœ innego ni¿ liczy od 1 do 9.!!!
		}
	}

	//Funkcja która przeˆ¹cza graczy.
	void TogglePlayer() {

			if (this->player == 'X')
				this->player = 'O';
			else
				this->player = 'X';
	}

	//Funkcja sprawdzaj¹ca czy gracz wygraˆ, jako parametr przyjmuje "player" który jest albo X albo O.
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

		//Sprawdzanie przek¹tnych
		else if (matrix[0][0] == player && matrix[1][1] == player && matrix[2][2] == player) //1 5 9
			return player;
		else if (matrix[2][0] == player && matrix[1][1] == player && matrix[0][2] == player) //3 5 7
			return player;

			return '-';//Jeœli ¿adna z powy¿szych zwracamy "-"
	}

public:
	//Funkcja odpowiedzialna za rozgrywkê
	void TicTacToeGame() {
		while(this->Win(this->player) == '-') {//Pêtla która koñczy siê gdy wygra któryœ z graczy (Funkcja Win zwróci coœ innego ni¿ "-")
			system("cls");
			this->n++;//Tura zwiêkszana o 1
			this->Draw(); 
			this->Input();
			if (this->Win(this->player) == '-') {//Jeœli nikt nie wygra³ prze³¹czamy graczy
				if (this->n != 9)//Sprawdzamy czy gra dalej trwa (nie skoñczy³y siê wszystkie tury)
					this->TogglePlayer();
				else if (this->n == 9) {//Jeœli nikt nie wygra³ do 9 tury oznacza to remis
					system("cls");
					this->Draw();
					cout << "Remis! Zagraj ponownie!";
					return;
				}
			}
			else {//Przypadek gdy wygra jeden z graczy
				system("cls");
				this->Draw();
				cout << "Wygra³ gracz: " << this->player<<"!"<<endl;
				return;
			}	
		}
	}

	virtual ~Board() { //Destruktor obiektu
		cout << "\nDziêkujemy za skorzystanie z naszego programu, pozdrawiaj¹ Mariusz Mañka oraz Tymoteusz Ma³kowski!\n";
	};
};


//Funkcja  poza klas¹ pozwalaj¹ca na wybranie gracza który ma zaczynaæ
char WhichPlayer() {
	char choice;
	system("cls");
	cout << "Który gracz ma zaczynaæ? ";
	cin >> choice;
	if (choice == 'X')
		return 'X';
	else if (choice == 'O')
		return 'O';
	else return 'X'; //W ka¿dym innym przypadku domyœlnie zwracamy X
}


int main() {
	setlocale(LC_CTYPE, "Polish");

	int gamechoice; //Wybór trybu gry

	cout << "Wybierz tryb gry"<<endl;
	cout << "1 - Dwuosobowa lokalna\n2 - vs AI\n3 - WyjdŸ z gry\n\n\n";
	cout << "Wybieram: ";
	cin >> gamechoice;
	if (gamechoice == 1)
	{
		Board game(WhichPlayer()); //Instancja klasy, wywo³uje konstruktor parametryczny, parametr jest zwracany z funkcji WhichPlayer;
		game.TicTacToeGame();
	}
	else if (gamechoice == 2)
	{
		cout << "debug 2";
	}
	else if (gamechoice == 3)
	{
		system("cls");
		cout << "Dziêkujemy za grê!";
		return 0;
	}
	else
	{
		cout << "debug niepoprawna liczba";
	}
	return 0;
}
