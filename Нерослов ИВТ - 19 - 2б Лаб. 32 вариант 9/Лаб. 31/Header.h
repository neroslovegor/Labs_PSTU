#pragma once
#include <vector>
#include <glut.h>
#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
#include <queue>
using namespace std;

const int maximumVerts = 20;//максимальное число вершин
extern int WinW;//ширина и высота окна
extern int WinH;
struct vertCoord //структура координат вершин
{
	int x, y;
};

class Graph
{
private:
	vector<int> vertList;
	int adjMatrix[maximumVerts][maximumVerts];
public:
	Graph();
	~Graph() {};
	bool IsEmpty();//проверка на пустоту
	bool IsFull(); //проверка на переполнение
	int GetVertexElement(int i) { return vertList[i]; }//получить значение вершины                               
	vector<int> GetVertList() { return  vertList; }      //получить вектор вершин                        
	int GetAdjMatrixElement(int i, int j) { return adjMatrix[i][j]; }//получить элемент матрицы смежности    
	int GetAmountEdges();//получить количество ребер                      
	int GetAmountVerts() { return vertList.size(); }//получить количество вершин                             
	int GetVertPos(const int& v);//получить координаты вектора		                                                                              
	void InsertVertex(const int& v);//вставка вершины               
	void InsertEdge(const int& v, const int& v2, int w);//вставка ребра	    
	void PrintGraph();//вывод матрицы                                                      
	void DeleteVertex();//удаление вершины                                           
	void DeleteEdge(const int& v1, const int& v2);  //удаление ребра                 
	void drawGraph(); //изображение графа                                              
};
extern Graph graph;
int** MatrTSP(); //создается матрица, заменяя 0 на -1
int* FindMin(int* l, int n);//поиск минимального элемента в строке матрицы
int** ReductMatr(int** m); //редукция матрицы
int** RebuildMatr(int** m);
bool CommiCheck(int** matrix);
int Circle_Check(int x, int y);//проверка на вхождение курсорв в вершину
void drawCircle(int x, int y, int R);
void drawText(int nom, int x1, int y1);
void drawLine(int text, int x0, int y0, int x1, int y1);
void drawVertex(int n);//рисование вершины                                                      
void Button1();
void Button2();
void Button3();
void Button4();	
void Button5();
void Button6();
void ButtonsCheck(int x, int y);//проверка на вхождение курсора в кнопки
void makeGraph();   //создание графа                                                          
void setCoords(int i, int n); //установление начальных координат                                                                                                                                               
void Move(int x, int y);   //передвижение вершин                                                 
void Click(int button, int state, int x, int y);  //нажимаение на кнопки                         
void reshape(int w, int h);//обеспечивает масштабирование                                
void display();//обеспечивает вывод изображения               