#pragma once
#include <vector>
#include <glut.h>
#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
#include <queue>
using namespace std;

const int maximumVerts = 20;//������������ ����� ������
extern int WinW;//������ � ������ ����
extern int WinH;
struct vertCoord //��������� ��������� ������
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
	bool IsEmpty();//�������� �� �������
	bool IsFull(); //�������� �� ������������
	int GetVertexElement(int i) { return vertList[i]; }//�������� �������� �������                               
	vector<int> GetVertList() { return  vertList; }      //�������� ������ ������                        
	int GetAdjMatrixElement(int i, int j) { return adjMatrix[i][j]; }//�������� ������� ������� ���������    
	int GetAmountEdges();//�������� ���������� �����                      
	int GetAmountVerts() { return vertList.size(); }//�������� ���������� ������                             
	int GetVertPos(const int& v);//�������� ���������� �������		                                                                              
	void InsertVertex(const int& v);//������� �������               
	void InsertEdge(const int& v, const int& v2, int w);//������� �����	    
	void PrintGraph();//����� �������                                                      
	void DeleteVertex();//�������� �������                                           
	void DeleteEdge(const int& v1, const int& v2);  //�������� �����                 
	void drawGraph(); //����������� �����                                              
};
extern Graph graph;
int** MatrTSP(); //��������� �������, ������� 0 �� -1
int* FindMin(int* l, int n);//����� ������������ �������� � ������ �������
int** ReductMatr(int** m); //�������� �������
int** RebuildMatr(int** m);
bool CommiCheck(int** matrix);
int Circle_Check(int x, int y);//�������� �� ��������� ������� � �������
void drawCircle(int x, int y, int R);
void drawText(int nom, int x1, int y1);
void drawLine(int text, int x0, int y0, int x1, int y1);
void drawVertex(int n);//��������� �������                                                      
void Button1();
void Button2();
void Button3();
void Button4();	
void Button5();
void Button6();
void ButtonsCheck(int x, int y);//�������� �� ��������� ������� � ������
void makeGraph();   //�������� �����                                                          
void setCoords(int i, int n); //������������ ��������� ���������                                                                                                                                               
void Move(int x, int y);   //������������ ������                                                 
void Click(int button, int state, int x, int y);  //���������� �� ������                         
void reshape(int w, int h);//������������ ���������������                                
void display();//������������ ����� �����������               