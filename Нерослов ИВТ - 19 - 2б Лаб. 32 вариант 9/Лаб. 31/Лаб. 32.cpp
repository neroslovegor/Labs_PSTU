#include "Header.h"
using namespace std;
int MovVert;//перемещаемая вершина
int CursorX;//позиция курсора 
int CursorY;
bool* ThisVert = new bool[maximumVerts]; //курсор в зоне круга
bool MovMode = false; //перемещены ли вершины
bool IsMove = false; //отвечает за перемещение вершин 
vertCoord vertC[maximumVerts + 1];//координаты вершин
vector<pair<int, int>> PathVert;
vector<int> WayVert;
int R;
int butOn;
Graph graph;

int WinW = 1000;
int WinH = 700;
Graph::Graph()
{
	for (int i = 0; i < maximumVerts; i++)
	{
		ThisVert[i] = false;
		for (int j = 0; j < maximumVerts; j++)
			adjMatrix[i][j] = 0;
	}
}

int Graph::GetVertPos(const int& vertex)
{
	for (size_t i = 0; i < vertList.size(); i++)
	{
		if (vertList[i] == vertex)
			return i;
	}
	return -1;
}

bool Graph::IsEmpty()
{
	if (vertList.size() != 0)
		return false;
	else
		return true;
}

bool Graph::IsFull()
{
	return (vertList.size() == maximumVerts);
}

void Graph::InsertVertex(const int& vertex)
{
	if (!IsFull())
		vertList.push_back(vertex);
	else
	{
		cout << "Граф уже заполнен. Невозможно добавить новую вершину " << endl;
		return;
	}
}

void Graph::InsertEdge(const int& vertex1, const int& vertex2, int weight)
{
	if (weight < 1)
	{
		cout << "\nДанная величина веса некорректна\n";
		return;
	}
	if (GetVertPos(vertex1) != (-1) && GetVertPos(vertex2) != (-1))
	{
		int vertPos1 = GetVertPos(vertex1);
		int vertPos2 = GetVertPos(vertex2);
		if (adjMatrix[vertPos1][vertPos2] != 0 && adjMatrix[vertPos2][vertPos1] != 0)
		{
			cout << "Ребро между вершинами уже есть" << endl;
			return;
		}
		else
		{
			adjMatrix[vertPos1][vertPos2] = weight;
		}
	}
	else
	{
		cout << "Обеих вершин (или одной из них) нет в графе " << endl;
		return;
	}
}

void Graph::PrintGraph()
{
	if (!IsEmpty())
	{
		cout << "Матрица смежности графа: " << endl;
		for (int i = 0; i < vertList.size(); i++)
		{
			cout << vertList[i] << " ";
			for (int j = 0; j < vertList.size(); j++)
				cout << setw(4) << adjMatrix[i][j];
			cout << endl;
		}
	}
	else
		cout << "Граф пуст " << endl;
}

void Graph::DeleteVertex()
{
	if (IsEmpty())
	{
		cout << "\nГраф пуст\n";
		return;
	}
	int n = vertList.size();
	for (int j = 0; j < n; j++)
	{
		adjMatrix[n - 1][j] = 0;
		adjMatrix[j][n - 1] = 0;
	}

	vertList.pop_back();
}

void Graph::DeleteEdge(const int& vertex1, const int& vertex2)
{
	if (GetVertPos(vertex1) != (-1) && GetVertPos(vertex2) != (-1))	//если вершины есть в графе
	{
		int vertPos1 = GetVertPos(vertex1);							//находим позиции вершин
		int vertPos2 = GetVertPos(vertex2);
		if (adjMatrix[vertPos1][vertPos2] == 0 && adjMatrix[vertPos2][vertPos1] == 0)//если между ними уже есть ребро
		{
			cout << "Здесь ребра нет" << endl;
			return;
		}
		else														//иначе добавляем ребро
			adjMatrix[vertPos1][vertPos2] = 0;
	}
	else
	{
		cout << "Обеих вершин (или одной из них) нет в графе " << endl;
		return;
	}
}

int Graph::GetAmountEdges()
{
	int edges = 0;
	for (int i = 0; i < vertList.size(); i++)
		for (int j = 0; j < vertList.size(); j++)
			if (adjMatrix[i][j] > 0)
				edges++;
	return edges;
}

void Graph::drawGraph()
{
	int n = graph.GetAmountVerts();
	for (int i = 0; i < n; i++)
	{
		if (!MovMode)
			setCoords(i, n);
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int a = adjMatrix[i][j];
			if (a != 0)
				drawLine(a, vertC[i].x, vertC[i].y, vertC[j].x, vertC[j].y);
			if (a == adjMatrix[j][i] && a != 0)
				drawLine(a, vertC[j].x, vertC[j].y, vertC[i].x, vertC[i].y);
		}
	}
	drawVertex(n);
	glutPostRedisplay();
}

void Button1()
{
	if (butOn == 1)
		glColor3f(0.902f, 0.902f, 0.980f);
	else
		glColor3f(0.8, 0.7, 0.9);
	glBegin(GL_QUADS);
	glVertex2i(0, WinH);
	glVertex2i(0, WinH - WinH / 7);
	glVertex2i(WinW / 7, WinH - WinH / 7);
	glVertex2i(WinW / 7, WinH);
	glEnd();
	glColor3f(0.0f, 0.0f, 0.0f);
	glBegin(GL_LINE_LOOP);
	glVertex2i(0, WinH);
	glVertex2i(0, WinH - WinH / 7);
	glVertex2i(WinW / 7, WinH - WinH / 7);
	glVertex2i(WinW / 7, WinH);
	glEnd();
	string name = "Commivoyager";
	glRasterPos2i(25, WinH - 0.5 * WinH / 7);
	for (int i = 0; i < name.length(); i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, name[i]);
}

void Button2()
{
	if (butOn == 6)
		glColor3f(0.902f, 0.902f, 0.980f);
	else
		glColor3f(0.8, 0.7, 0.9);
	glBegin(GL_QUADS);
	glVertex2i(0, WinH - 4 * WinH / 7);
	glVertex2i(0, WinH - 5 * WinH / 7);
	glVertex2i(WinW / 7, WinH - 5 * WinH / 7);
	glVertex2i(WinW / 7, WinH - 4 * WinH / 7);
	glEnd();
	glColor3f(0.0f, 0.0f, 0.0f);
	glBegin(GL_LINE_LOOP);
	glVertex2i(0, WinH - 4 * WinH / 7);
	glVertex2i(0, WinH - 5 * WinH / 7);
	glVertex2i(WinW / 7, WinH - 5 * WinH / 7);
	glVertex2i(WinW / 7, WinH - 4 * WinH / 7);
	glEnd();
	string name = "Delete Vertex";
	glRasterPos2i(40, WinH - 4.5 * WinH / 7);
	for (int i = 0; i < name.length(); i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, name[i]);
}

void Button3()
{
	if (butOn == 3)
		glColor3f(0.902f, 0.902f, 0.980f);
	else
		glColor3f(0.8, 0.7, 0.9);
	glBegin(GL_QUADS);
	glVertex2i(0, WinH - 2 * WinH / 7);
	glVertex2i(0, WinH - 3 * WinH / 7);
	glVertex2i(WinW / 7, WinH - 3 * WinH / 7);
	glVertex2i(WinW / 7, WinH - 2 * WinH / 7);
	glEnd();
	glColor3f(0.0f, 0.0f, 0.0f);
	glBegin(GL_LINE_LOOP);
	glVertex2i(0, WinH - 2 * WinH / 7);
	glVertex2i(0, WinH - 3 * WinH / 7);
	glVertex2i(WinW / 7, WinH - 3 * WinH / 7);
	glVertex2i(WinW / 7, WinH - 2 * WinH / 7);
	glEnd();
	string name = "Add Edge";
	glRasterPos2i(40, WinH - 2.5 * WinH / 7);
	for (int i = 0; i < name.length(); i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, name[i]);
}

void Button4()
{
	if (butOn == 4)
		glColor3f(0.902f, 0.902f, 0.980f);
	else
		glColor3f(0.8, 0.7, 0.9);
	glBegin(GL_QUADS);
	glVertex2i(0, WinH - 3 * WinH / 7);
	glVertex2i(0, WinH - 4 * WinH / 7);
	glVertex2i(WinW / 7, WinH - 4 * WinH / 7);
	glVertex2i(WinW / 7, WinH - 3 * WinH / 7);
	glEnd();
	glColor3f(0.0f, 0.0f, 0.0f);
	glBegin(GL_LINE_LOOP);
	glVertex2i(0, WinH - 3 * WinH / 7);
	glVertex2i(0, WinH - 4 * WinH / 7);
	glVertex2i(WinW / 7, WinH - 4 * WinH / 7);
	glVertex2i(WinW / 7, WinH - 3 * WinH / 7);
	glEnd();
	string name = "Delete Edge";
	glRasterPos2i(40, WinH - 3.5 * WinH / 7);
	for (int i = 0; i < name.length(); i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, name[i]);
}

void Button5()
{
	if (butOn == 2)
		glColor3f(0.902f, 0.902f, 0.980f);
	else
		glColor3f(0.8, 0.7, 0.9);
	glBegin(GL_QUADS);
	glVertex2i(0, WinH - WinH / 7);
	glVertex2i(0, WinH - 2 * WinH / 7);
	glVertex2i(WinW / 7, WinH - 2 * WinH / 7);
	glVertex2i(WinW / 7, WinH - WinH / 7);
	glEnd();
	glColor3f(0.0f, 0.0f, 0.0f);
	glBegin(GL_LINE_LOOP);
	glVertex2i(0, WinH - WinH / 7);
	glVertex2i(0, WinH - 2 * WinH / 7);
	glVertex2i(WinW / 7, WinH - 2 * WinH / 7);
	glVertex2i(WinW / 7, WinH - WinH / 7);
	glEnd();
	string name = "New Graph";
	glRasterPos2i(35, WinH - 1.5 * WinH / 7);
	for (int i = 0; i < name.length(); i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, name[i]);
}

void Button6()
{
	if (butOn == 5)
		glColor3f(0.902f, 0.902f, 0.980f);
	else
		glColor3f(0.8, 0.7, 0.9);
	glBegin(GL_QUADS);
	glVertex2i(0, WinH - 5 * WinH / 7);
	glVertex2i(0, WinH - 6 * WinH / 7);
	glVertex2i(WinW / 7, WinH - 6 * WinH / 7);
	glVertex2i(WinW / 7, WinH - 5 * WinH / 7);
	glEnd();
	glColor3f(0.0f, 0.0f, 0.0f);
	glBegin(GL_LINE_LOOP);
	glVertex2i(0, WinH - 5 * WinH / 7);
	glVertex2i(0, WinH - 6 * WinH / 7);
	glVertex2i(WinW / 7, WinH - 6 * WinH / 7);
	glVertex2i(WinW / 7, WinH - 5 * WinH / 7);
	glEnd();
	string name = "Add Vertex";
	glRasterPos2i(40, WinH - 5.5 * WinH / 7);
	for (int i = 0; i < name.length(); i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, name[i]);
}
void drawCircle(int x, int y, int R)
{
	glColor3f(1.0f, 1.0f, 1.0f);
	float x1, y1;
	glBegin(GL_POLYGON);
	for (int i = 0; i < 360; i++)
	{
		float theta = 2.0f * 3.1415926f * float(i) / float(360);
		y1 = R * cos(theta) + y;
		x1 = R * sin(theta) + x;;
		glVertex2f(x1, y1);
	}
	glEnd();

	glColor3f(0.0f, 0.0f, 0.0f);
	float x2, y2;
	glBegin(GL_LINE_LOOP);
	for (int i = 0; i < 360; i++)
	{
		float theta = 2.0f * 3.1415926f * float(i) / float(360);
		y2 = R * cos(theta) + y;
		x2 = R * sin(theta) + x;
		glVertex2f(x2, y2);
	}
	glEnd();
}

void drawText(int text, int x1, int y1)
{
	glColor3f(0.0, 0.0, 0.0);
	GLvoid* font = GLUT_BITMAP_HELVETICA_18;
	string s = to_string(text);
	glRasterPos2i(x1 - 5, y1 - 5);
	for (size_t j = 0; j < s.length(); j++)
		glutBitmapCharacter(font, s[j]);
}

void drawLine(int text, int x0, int y0, int x1, int y1) //ребро неориентированного взвешенного графа
{
	glColor3i(0, 0, 0);
	glBegin(GL_LINES);
	glVertex2i(x0, y0);
	glVertex2i(x1, y1);
	glEnd();
	drawText(text, (x0 + x1) / 2 + 10, (y0 + y1) / 2 + 10);

	float vx = x0 - x1;
	float vy = y0 - y1;
	float s = 1.0f / sqrt(vx * vx + vy * vy);
	vx *= s;
	vy *= s;
	x1 = x1 + R * vx;
	y1 = y1 + R * vy;

	glColor3i(0, 0, 0);
	glBegin(GL_TRIANGLES);
	glVertex2f(x1, y1);
	glVertex2f(x1 + 10 * (vx + vy), y1 + 10 * (vy - vx));
	glVertex2f(x1 + 10 * (vx - vy), y1 + 10 * (vy + vx));
	glEnd();
}

void drawVertex(int n)
{
	for (int i = 0; i < n; i++)
	{
		drawCircle(vertC[i].x, vertC[i].y, R);
		drawText(i + 1, vertC[i].x, vertC[i].y);
	}
}

void setCoords(int i, int n)
{
	int R_;
	int x0 = WinW / 2;
	int y0 = WinH / 2;
	if (WinW > WinH)
	{
		R = 5 * (WinH / 13) / n;
		R_ = WinH / 2 - R - 10;
	}
	else
	{
		R = 5 * (WinW / 13) / n;
		R_ = WinW / 2 - R - 10;
	}
	float theta = 2.0f * 3.1415926f * i / n;
	int y1 = R_ * cos(theta) + y0;
	int x1 = R_ * sin(theta) + x0;
	vertC[i].x = x1;
	vertC[i].y = y1;
}

void makeGraph()
{
	int amountVerts, amountEdges, sourceVertex, targetVertex, edgeWeight;
	cout << "Введите количество вершин в графе: "; cin >> amountVerts;
	cout << "Введите количество ребер в графе: "; cin >> amountEdges;
	for (int i = 1; i <= amountVerts; i++)
		graph.InsertVertex(i);
	for (int i = 0; i < amountEdges; i++)
	{
		cout << "Исходная вершина: "; cin >> sourceVertex;
		cout << "Конечная вершина: "; cin >> targetVertex;
		cout << "Вес ребра: "; cin >> edgeWeight;
		graph.InsertEdge(sourceVertex, targetVertex, edgeWeight);
	}
	cout << endl;
	MovMode = false;
	graph.PrintGraph();
}

int** MatrTSP()
{
	int n = graph.GetAmountVerts();
	int** matrix = new int* [n];
	for (int i = 0; i < n; i++)
		matrix[i] = new int[n];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int elem = graph.GetAdjMatrixElement(i, j);
			if (elem == 0 or i == j)
				matrix[i][j] = -1;
			else
				matrix[i][j] = elem;
		}
	}
	return matrix;
}

int* FindMin(int* line, int n)
{
	int min = 1000000;
	for (int j = 0; j < n; j++)
		if (line[j] >= 0 && line[j] < min)
			min = line[j];
	for (int j = 0; j < n; j++)
		if (line[j] >= 0)
			line[j] -= min;
	return line;
}

int** ReductMatr(int** oldmatrix)
{
	int** matrix = oldmatrix;
	int n = graph.GetAmountVerts();
	for (int i = 0; i < n; i++)
		matrix[i] = FindMin(matrix[i], n);
	for (int i = 0; i < n; i++)
	{
		int min = 1000000;
		for (int j = 0; j < n; j++)
		{
			if (matrix[j][i] >= 0 && matrix[j][i] < min)
				min = matrix[j][i];
		}
		for (int j = 0; j < n; j++)
		{
			if (matrix[j][i] >= 0)
				matrix[j][i] -= min;
		}
	}
	return matrix;
}

int** RebuildMatr(int** oldmatrix)
{
	int n = graph.GetAmountVerts();
	int** matrix = ReductMatr(oldmatrix);
	int max = -1;
	int line, column;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (matrix[i][j] == 0)
			{
				int minLine = 1000000;
				int minColumn = 1000000;
				for (int k = 0; k < n; k++)
				{
					if (matrix[i][k] != -1 && k != j && matrix[i][k] < minLine)
						minLine = matrix[i][k];
				}
				for (int k = 0; k < n; k++)
				{
					if (matrix[k][j] != -1 && k != i && matrix[k][j] < minColumn)
						minColumn = matrix[k][j];
				}
				if (max < minColumn + minLine)
				{
					max = minColumn + minLine;
					line = i;
					column = j;
				}
			}
		}
	}

	pair<int, int> p;
	p.first = line + 1;
	p.second = column + 1;
	PathVert.push_back(p);

	matrix[line][column] = -1;
	matrix[column][line] = -1;

	for (int i = 0; i < n; i++)
	{
		matrix[line][i] = -1;
		matrix[i][column] = -1;
	}
	return matrix;
}

void CommiResult(int n)
{
	int second = PathVert[0].second;
	int i = 2;
	WayVert.push_back(PathVert[0].first);
	WayVert.push_back(PathVert[0].second);
	while (i != graph.GetAmountVerts() + 1)
		for (int j = 1; j < graph.GetAmountVerts(); j++)
			if (PathVert[j].first == second)
			{
				second = PathVert[j].second;
				WayVert.push_back(second);
				i++;
			}
	WayVert.pop_back();
	cout << "Ответ: ";
	int j = 0;
	for (int i = 0; i < WayVert.size(); i++)
	{
		if (WayVert[i] == n)
			j = i;
	}
	for (int i = 0; i < WayVert.size() + 1; i++)
	{
		cout << WayVert[j % WayVert.size()];
		if (i != WayVert.size())
			cout << " -> ";
		j++;
	}
	int sum = 0;
	for (int i = 0; i < PathVert.size(); i++)
	{
		int line = PathVert[i].first - 1;
		int column = PathVert[i].second - 1;
		sum += graph.GetAdjMatrixElement(line, column);
	}
	cout << "\nS = " << sum << endl;;
}

bool CommiCheck(int** matrix)
{
	if (graph.IsEmpty())
		return false;
	for (int i = 0; i < graph.GetAmountVerts(); i++)
	{
		int cnt = 0;
		for (int j = 0; j < graph.GetAmountVerts(); j++)
		{
			if (matrix[i][j] > 0)
				cnt++;
		}
		if (cnt < 1)
			return false;
	}
	return true;
}

int Circle_Check(int x, int y)
{
	for (int i = 0; i < graph.GetAmountVerts(); i++)
		if (pow(x - vertC[i].x, 2) + pow(y - vertC[i].y, 2) <= R * R)
			return i;
	return -1;
}

void Move(int x, int y)//отслеживание движения мыши
{
	y = WinH - y;
	CursorX = x;
	CursorY = y;
	int i = Circle_Check(x, y);
	if (i != -1)
		ThisVert[i] = true;
	else
		for (int j = 0; j < graph.GetAmountVerts(); j++)
			ThisVert[j] = false;
	if (IsMove)
	{
		vertC[MovVert].x = CursorX;
		vertC[MovVert].y = CursorY;
	}
	ButtonsCheck(x, y);
	glutPostRedisplay();
}
void ButtonsCheck(int x, int y)
{
	if (x < WinW / 7 and x > 0 and y < WinH and y > WinH - WinH / 7)
		butOn = 1;
	else if (x < WinW / 7 and x > 0 and y < WinH - WinH / 7 and y > WinH - 2 * WinH / 7)
		butOn = 2;
	else if (x < WinW / 7 and x > 0 and y <WinH - 2 * WinH / 7 and y > WinH - 3 * WinH / 7)
		butOn = 3;
	else if (x < WinW / 7 and x > 0 and y <WinH - 3 * WinH / 7 and y > WinH - 4 * WinH / 7)
		butOn = 4;
	else if (x < WinW / 7 and x > 0 and y <WinH - 4 * WinH / 7 and y > WinH - 5 * WinH / 7)
		butOn = 6;
	else if (x < WinW / 7 and x > 0 and y <WinH - 5 * WinH / 7 and y > WinH - 6 * WinH / 7)
		butOn = 5;
	else
		butOn = 0;
}
void Click(int button, int state, int x, int y)//действия с кнопками 
{
	int j = Circle_Check(x, WinH - y);
	if (IsMove)
	{
		if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		{
			IsMove = false;
			return;
		}
	}
	if (j != -1)
	{
		MovMode = true;
		if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		{
			IsMove = true;
			MovVert = j;
			return;
		}
	}
	if (x <= WinW / 7 and x >= 0 and y >= 0 and y <= WinH / 7)
	{
		if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		{
			int num;
			WayVert.clear();
			PathVert.clear();
			cout << "Введите исходную вершину: ";
			cin >> num;
			cout << endl;
			cout << "Решение задачи коммивояжера\n";
			int** matrix = MatrTSP();
			bool tsp = CommiCheck(matrix);
			if (!tsp)
			{
				cout << "\nЗадача Коммивояжера не может быть решена\n\n";
				return;
			}
			int n = graph.GetAmountVerts();
			while (PathVert.size() < n)
				matrix = RebuildMatr(matrix);
			cout << endl;
			CommiResult(num);
			return;
		}
	}
	if (x <= WinW / 7 and x >= 0 and y >= WinH / 7 and y <= 2 * WinH / 7)
	{
		if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		{
			WayVert.clear();
			PathVert.clear();
			Graph New;
			graph = New;
			makeGraph();
			return;
		}
		if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
		{
			MovMode = false;
			return;
		}
	}
	if (x <= WinW / 7 and x >= 0 and y >= 2 * WinH / 7 and y <= 3 * WinH / 7)
	{
		if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		{
			int sourceVertex, targetVertex, edgeWeight, vertNum;
			cout << "Количество добавляемых ребер: "; cin >> vertNum;
			for (int i = 0; i < vertNum; i++)
			{
				cout << "Исходная вершина: "; cin >> sourceVertex;
				cout << "Конечная вершина: "; cin >> targetVertex;
				cout << "Вес ребра: "; cin >> edgeWeight;
				graph.InsertEdge(sourceVertex, targetVertex, edgeWeight);
			}
			return;
		}
	}
	if (x <= WinW / 7 and x >= 0 and y >= 3 * WinH / 7 and y <= 4 * WinH / 7)
	{
		if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		{
			int sourceVertex, targetVertex;
			cout << "Исходная вершина: "; cin >> sourceVertex;
			cout << "Конечная вершина: "; cin >> targetVertex;
			graph.DeleteEdge(sourceVertex, targetVertex);
			return;
		}
	}
	if (x <= WinW / 7 and x >= 0 and y >= 5 * WinH / 7 and y <= 6 * WinH / 7)
	{
		if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		{
			int cur = graph.GetAmountVerts();
			graph.InsertVertex(cur + 1);
			vertC[cur].x = WinW / 2;
			vertC[cur].y = WinH / 2;
			cout << "\nДобавлена вершина: " << cur + 1 << endl;
			return;
		}
	}
	if (x <= WinW / 7 and x >= 0 and y >= 4 * WinH / 7 and y <= 5 * WinH / 7)
	{
		if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		{
			graph.DeleteVertex();
			int cur = graph.GetAmountVerts();
			cout << "\nУдалена вершина: " << cur << endl;
			return;
		}
	}
}

void reshape(int w, int h)//обеспечивает масшатабирование
{
	WinW = w;
	WinH = h;
	glViewport(0, 0, (GLsizei)WinW, (GLsizei)WinH);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, (GLdouble)WinW, 0, (GLdouble)WinH);
	glutPostRedisplay();
}

void display()//вывод изображения на экран
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, WinW, 0, WinH);
	glViewport(0, 0, WinW, WinH);
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);

	graph.drawGraph();

	Button1();
	Button2();
	Button3();
	Button4();
	Button5();
	Button6();

	glutSwapBuffers();
}