#include <stdio.h>  
#include <stdlib.h> 

// Class for Square
class Square {
private:
    float side;
    
public:
    void setside(float s) {
     side = s;
     }
    float getarea() {
     return side * side;
     }
};

//class for cube
class Cube {
private:
    float side;
public:
    void setside(float s) {
         side = s;
          }  
    float getsurfaceArea() {
         return 6 * side * side;
          }
};

// Class for Rectangle
class Rectangle {
private:
    float length, breadth;
public:
    void setdimensions(float l, float b) {
         length = l; breadth = b;
          }  
    float getarea() {
         return length * breadth;
          }
};

// Class for Cuboid
class Cuboid {
private:
    float length, breadth, height;

public:
    void setdimensions(float l, float b, float h) {
         length = l; breadth = b; height = h;
          }  
    float getsurfaceArea() {
         return 2 * (length * breadth + breadth * height + height * length);
          }
};

int main() {
    int choice;
    float side, length, breadth, height;

    do {
        printf("\n        MENU       \n");
        printf("1. Square\n");
        printf("2. Cube\n");
        printf("3. Rectangle\n");
        printf("4. Cuboid\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                printf("Enter side length of square: ");
                scanf("%f", &side);
                if (side <= 0) {
                    printf("Invalid input.Side length must be positive.\n");
                } else {
                    Square square1;
                    square1.setside(side);
                    printf("Area of Square: %.2f\n", square1.getarea());
                }
                break;
            }

            case 2: {
                printf("Enter side length of cube: ");
                scanf("%f", &side);
                if (side <= 0) {
                    printf("Invalid input.Side length must be positive.\n");
                } else {
                    Cube cube1;
                    cube1.setside(side);
                    printf("Surface Area of Cube: %.2f\n",cube1.getsurfaceArea());
                }
                break;
            }

            case 3: {
                printf("Enter length and breadth of rectangle: ");
                scanf("%f %f", &length, &breadth);
                if (length <= 0 || breadth <= 0) {
                    printf("Invalid input.Length and breadth must be positive.\n");
                } else {
                    Rectangle rectangle1;
                    rectangle1.setdimensions(length, breadth);
                    printf("Area of Rectangle: %.2f\n", rectangle1.getarea());
                }
                break;
            }

            case 4: {
                printf("Enter length, breadth, and height of cuboid: ");
                scanf("%f %f %f", &length, &breadth, &height);
                if (length <= 0 || breadth <= 0 || height <= 0) {
                    printf("Invalid input.Length, breadth, and height must be positive.\n");
                } else {
                    Cuboid cuboid1;
                    cuboid1.setdimensions(length, breadth, height);
                    printf("Surface Area of Cuboid: %.2f\n", cuboid1.getsurfaceArea());
                }
                break;
            }

            case 5:
                printf("You choose to exit the program.");
                break;

            default:
                printf("Invalid choice.Please choose a valid option.\n");
        }
    } while (choice != 5);

    return 0;
}
