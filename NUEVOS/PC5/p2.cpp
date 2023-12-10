#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cmath>
using namespace std;
// Structure to store line data
struct Puntos
{
    double x;
    double y;
};

struct Poligono{
    string nombre;
    Puntos* punto;
    int numPuntos;
    double area;
    double perimetro;
};
int contarfilas(string filePath){
    ifstream inputFile(filePath);
    string line;
    if (!inputFile.is_open()) {
        cerr << "Error opening the file.\n";
        return 1;
    }
    int i=0;
    while (getline(inputFile,line)){
		i++;
	}
    inputFile.close();
    return i;
};
int contarpares(string cadena){
    istringstream iss(cadena);
    int i=0;
    double a;
    while (iss)
        {
            iss>>a;
            i++;
        }
        return (i-1)/2;
};
double distance(const Puntos& p1, const Puntos& p2) {
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}

// Function to compute the perimeter of the polygon formed by the points
double computePerimeter(const Puntos points[], int numPoints) {
    double perimeter = 0.0;

    for (int i = 0; i < numPoints; ++i) {
        int nextIndex = (i + 1) % numPoints;  // To connect the last point with the first one
        perimeter += distance(points[i], points[nextIndex]);
    }
    return perimeter;
}
// Function to compute the area of the polygon formed by the points
double computeArea(const Puntos points[], int numPoints) {
    double area = 0.0;

    for (int i = 0; i < numPoints; ++i) {
        int nextIndex = (i + 1) % numPoints;  // To connect the last point with the first one
        area += (points[i].x * points[nextIndex].y - points[nextIndex].x * points[i].y);
    }

    return 0.5 * std::abs(area);
}
void llenarPoligonos(string filePath, Poligono* poli, int n){
    ifstream inputFile(filePath);
    string line;
    int m;
    if (!inputFile.is_open()) {
        cerr << "Error opening the file.\n";
    }
    for (int i = 0; i < n; i++)
    {
        getline(inputFile,line);
        m=contarpares(line.substr(1));
        poli[i].nombre=line[0];
        poli[i].numPuntos=m;
        Puntos* punto =new Puntos[m];
        istringstream iss(line.substr(1));
        for (int j = 0; j < m; j++)
        {
            iss>>punto[j].x;
            iss>>punto[j].y;

        };
        poli[i].punto=punto;
        poli[i].area=computeArea(punto, m);
        poli[i].perimetro=computePerimeter(punto,m);
    }
    inputFile.close();
    
};


int main() {
    // Specify the file path
    string filePath = "coordenadas.txt";  // Change this to the path of your text file
    int n= contarfilas(filePath);
    cout<<"Filas del texto: "<<n<<endl;
    Poligono* poli= new Poligono[n];
    llenarPoligonos(filePath,poli,n);
    int max=poli[0].area;
    int min=poli[0].area;
    int estmin=0;
    int estmax=0;
    for (int i = 0; i < n; i++)
    {
        if (poli[i].area>max)
        {
            max=poli[i].area;
            estmax=i;
        }
        if (poli[i].area<min)
        {
            min=poli[i].area;
            estmin=i;
        }
    }
    string OutPath ="areas.txt";
    ofstream outputFile(OutPath);
    if (!outputFile.is_open()) {
        std::cerr << "Error opening the file for writing.\n";
        return 1;
    }
    outputFile<<"El area mínima es: "<<poli[estmin].area<<"\n"<<"El area máxima es: "<<poli[estmax].area;
    outputFile.close();
    return 0;
}
