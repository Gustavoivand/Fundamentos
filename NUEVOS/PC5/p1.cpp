#include <iostream>
#include <cmath>

// Structure to store x and y positions of a point
struct Point {
    double x;
    double y;
};

//const int MAX_POINTS = 100;  // Change the maximum number of points as needed

// Function to compute the distance between two points
double distance(const Point& p1, const Point& p2) {
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}

// Function to compute the perimeter of the polygon formed by the points
double computePerimeter(const Point points[], int numPoints) {
    double perimeter = 0.0;

    for (int i = 0; i < numPoints; ++i) {
        int nextIndex = (i + 1) % numPoints;  // To connect the last point with the first one
        perimeter += distance(points[i], points[nextIndex]);
    }

    return perimeter;
}

// Function to compute the area of the polygon formed by the points
double computeArea(const Point points[], int numPoints) {
    double area = 0.0;

    for (int i = 0; i < numPoints; ++i) {
        int nextIndex = (i + 1) % numPoints;  // To connect the last point with the first one
        area += (points[i].x * points[nextIndex].y - points[nextIndex].x * points[i].y);
    }

    return 0.5 * std::abs(area);
}

int main() {
    int numPoints;

    std::cout << "Enter the number of points: ";
    std::cin >> numPoints;

    // Create an array to store the points
    Point *points= new Point[numPoints];
    // Input the points from the user
    for (int i = 0; i < numPoints; ++i) {
        std::cout << "Enter x-coordinate for point " << i + 1 << ": ";
        std::cin >> points[i].x;

        std::cout << "Enter y-coordinate for point " << i + 1 << ": ";
        std::cin >> points[i].y;
    }

    // Compute and display the perimeter
    double perimeter = computePerimeter(points, numPoints);
    std::cout << "Perimeter: " << perimeter << std::endl;

    // Compute and display the area
    double area = computeArea(points, numPoints);
    std::cout << "Area: " << area << std::endl;

    return 0;
}
