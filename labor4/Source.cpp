#define _CRT_SECURE_NO_WARNINGS
#include <ctime> // Библиотека времени
#include <cmath>
#include <locale.h>
#include <iostream> // Библиотека Ввода,Вывода
#include <conio.h>
#include <stack>
int n;
int** matrix = NULL;
using namespace std;
bool* visited = NULL;



struct spisok_smzh {

	int versh;
	spisok_smzh* next;

};

struct spiski_smzh {

	spisok_smzh* spisok;
	spiski_smzh* next;
};

spiski_smzh* p_spiski = NULL;
spiski_smzh* n_spiski = NULL;
spiski_smzh* p_spiski_start = NULL;
spisok_smzh* p_spisok = NULL;
spisok_smzh* p_spisok_start = NULL;
spisok_smzh* n_spisok = NULL;

void DFSS(int st)
{

	stack<int> s;
	s.push(st);
	visited[st] = true;
	while (!s.empty())
	{
		int v = s.top();
		s.pop();
		cout << v <<" ";
		
		for (int i = n-1; i > -1; --i)
		{
			if ((visited[i] == false) && (matrix[v][i]==1))
			{
				
				s.push(i);
				visited[i] = true;
			}
		}
	}
}

void DFS(int st)
{
	
	int r;
	p_spiski = p_spiski_start;
	spisok_smzh* p_spisok_loc = NULL;
	cout << st << " ";
	visited[st] = true;
	for (int i = 0; i<st; i++)
		p_spiski = p_spiski->next;
	p_spisok_loc = p_spiski->spisok;
	while (p_spisok_loc != NULL)
	{
		if (!visited[p_spisok_loc->versh])
		{
			DFS(p_spisok_loc->versh);
		}
		p_spisok_loc = p_spisok_loc->next;
	}
}

void main()
{
	setlocale(LC_ALL, "Russian"); // подключение русского
	srand(time(NULL)); // новый отсчёт времени

	
	int i, j, m;
	int start;
	cout << "n=";
	cin >> n;
	//cout << "Матрица: \n";
	int z;

	matrix = new int* [n]; // матрица
	visited = new bool[n];
	
	for (i = 0; i < n; i++)
	{
		matrix[i] = new int[n];
	}



	for (i = 0; i < n; i++)
	{
		for (m = 0; m < n; m++)
		{
			matrix[i][m] = rand() % 2;
		}
	}

	
	for (int i = 0; i < n; i++)
	matrix[i][i] = 0;

	for (int i = 0; i < n; i++)
	{ 
		
		for (j = 0; j < n; j++)
		{ 
			matrix[i][j] = matrix[j][i];
			cout << matrix[i][j]<<"  ";
		}
			cout << endl;
		
	}





	/*for (int i = 0; i < n; i++)
	{
		cout << "\n";
		cout << "{";
		for (j = 0; j < n; j++)

			if (matrix[i][j] == 1)
			{

				cout << j << " ";

			}
		cout << "}" << "   Вершина" << i;

	}
	*/
	cout << "\n";

	for (int i = 0; i < n; i++)
	{
		n_spiski = (spiski_smzh*)malloc(sizeof(spiski_smzh));
		p_spisok = NULL;
		p_spisok_start = NULL;
		for (j = 0; j < n; j++)
		{
			if (matrix[i][j] == 1)
			{
				n_spisok = (spisok_smzh*)malloc(sizeof(spisok_smzh));
				n_spisok->versh = j;
				if (p_spisok == NULL)
				{
					p_spisok = n_spisok;
					p_spisok_start = p_spisok;
				}
				else
				{
					p_spisok->next = n_spisok;
					p_spisok = n_spisok;
				}
				n_spisok->next = NULL;
			}
		}
		n_spiski->spisok = p_spisok_start;
		if (p_spiski == NULL)
		{
			p_spiski = n_spiski;
			p_spiski_start = p_spiski;
		}
		else
		{
			p_spiski->next = n_spiski;
			p_spiski = n_spiski;
		}
	}

	p_spiski = p_spiski_start;

	for(int i = 0; i < n; i++)
	{
		p_spisok = p_spiski->spisok;
		p_spisok_start = p_spisok;

		cout << "\n";
		cout << "{";
		while (p_spisok != NULL)
		{
			cout << p_spisok->versh << " ";
			p_spisok = p_spisok->next;
		}
		cout << "}" << "   Вершина" << i;
		p_spisok = p_spisok_start;
		p_spiski = p_spiski->next;
	}
	cout << "\n";

	p_spiski = p_spiski_start;


	for (i = 0; i < n; i++)
	{
		visited[i] = false;
	}
	 
	cout << "Стартовая вершина » ";
	cin >> start;
	bool* vis = new bool[n];
	cout << "Порядок обхода DFSS: ";
	DFSS(start);
	for (i = 0; i < n; i++)
	{
		visited[i] = false;
	}
	cout << "\n";
	cout << "Порядок обхода DFS: ";
	DFS(start);
	//delete[]visited;

}
