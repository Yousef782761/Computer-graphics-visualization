#include <GL/glut.h>  // Include the GLUT header file

void initGL() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black and opaque
    glMatrixMode(GL_PROJECTION); // Switch to setting the camera perspective
    gluOrtho2D(0.0, 200.0, 0.0, 200.0); // Set the Orthographic camera
}

void drawLeafOutlineVeins() {
    // Draw leaf outline
    glBegin(GL_LINE_LOOP); // Start drawing the leaf outline
    glColor3f(0.0f, 1.0f, 0.0f); // Set the color to green
    // Define the points for the outline of the leaf
    glVertex2f(100.0f, 180.0f); // Tip of the leaf
    glVertex2f(80.0f, 160.0f);  // Upper left
    glVertex2f(70.0f, 140.0f);  // Middle left upper
    glVertex2f(60.0f, 100.0f);  // Middle left lower
    glVertex2f(70.0f, 60.0f);   // Lower left
    glVertex2f(100.0f, 40.0f);  // Base of the leaf
    glVertex2f(130.0f, 60.0f);  // Lower right
    glVertex2f(140.0f, 100.0f); // Middle right lower
    glVertex2f(130.0f, 140.0f); // Middle right upper
    glVertex2f(120.0f, 160.0f); // Upper right
    glEnd(); // End of the leaf outline

    // Draw the central vein of the leaf
    glBegin(GL_LINES);
    glColor3f(0.75f, 0.6f, 0.2f); // Set the color to a lighter brown for the vein
    glVertex2f(100.0f, 180.0f);    // Start from the tip of the leaf
    glVertex2f(100.0f, 20.0f);     // Draw straight down to the base of the leaf

    // Improved vein paths
    glColor3f(0.75f, 0.6f, 0.2f); // Use the same color for the veins
    // Each vein will start from the central line and curve towards the leaf's edge
    glVertex2f(100.0f, 160.0f); glVertex2f(78.0f, 150.0f);
    glVertex2f(100.0f, 140.0f); glVertex2f(70.0f, 130.0f);
    glVertex2f(100.0f, 120.0f); glVertex2f(65.0f, 110.0f);
    glVertex2f(100.0f, 100.0f); glVertex2f(65.0f, 90.0f);
    glVertex2f(100.0f, 80.0f);  glVertex2f(70.0f, 70.0f);

    glVertex2f(100.0f, 160.0f); glVertex2f(125.0f, 150.0f);
    glVertex2f(100.0f, 140.0f); glVertex2f(130.0f, 130.0f);
    glVertex2f(100.0f, 120.0f); glVertex2f(137.0f, 110.0f);
    glVertex2f(100.0f, 100.0f); glVertex2f(137.0f, 90.0f);
    glVertex2f(100.0f, 80.0f);  glVertex2f(131.0f, 70.0f);

    glEnd(); // End of the veins
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer (background)
    drawLeafOutlineVeins();  // Draw the leaf outline and veins
    glFlush();  // Render now
}

int main(int argc, char** argv) {
    glutInit(&argc, argv); // Initialize GLUT
    glutCreateWindow("OpenGL 2D Leaf with Natural Veins"); // Create a window with the given title
    glutInitWindowSize(400, 400); // Set the window's initial width & height
    glutInitWindowPosition(50, 50); // Position the window's initial top-left corner
    glutDisplayFunc(display); // Register display callback handler for window re-paint
    initGL(); // Our own OpenGL initialization
    glutMainLoop(); // Enter the infinite event-processing loop
    return 0;
}
