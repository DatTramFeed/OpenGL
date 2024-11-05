#include <GL/glut.h>

// Tọa độ và góc quay của camera
float cameraX = 0.0f, cameraY = 1.0f, cameraZ = 5.0f;
float cameraAngle = 0.0f;

// Hàm để vẽ mặt sàn
void drawFloor() {
    glColor3f(0.6f, 0.6f, 0.6f);
    glBegin(GL_QUADS);
    glVertex3f(-5.0f, 0.0f, -5.0f);
    glVertex3f(5.0f, 0.0f, -5.0f);
    glVertex3f(5.0f, 0.0f, 5.0f);
    glVertex3f(-5.0f, 0.0f, 5.0f);
    glEnd();
}

// Hàm để vẽ một cột
void drawColumn(float x, float z) {
    glColor3f(1.0f, 0.5f, 0.0f);
    glPushMatrix();
    glTranslatef(x, 0.5f, z);
    glScalef(0.2f, 1.0f, 0.2f);
    glutSolidCube(1.0);
    glPopMatrix();
}

// Hàm để vẽ một bàn
void drawTable(float x, float z) {
    glPushMatrix();
    glTranslatef(x, 0.3f, z);

    // Mặt bàn
    glColor3f(0.5f, 0.35f, 0.05f);
    glPushMatrix();
    glScalef(1.0f, 0.05f, 0.5f);
    glutSolidCube(1.0);
    glPopMatrix();

    // Chân bàn
    glColor3f(0.4f, 0.25f, 0.05f);
    glPushMatrix();
    glTranslatef(-0.4f, -0.3f, -0.2f);
    glScalef(0.1f, 0.6f, 0.1f);
    glutSolidCube(1.0);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.4f, -0.3f, -0.2f);
    glScalef(0.1f, 0.6f, 0.1f);
    glutSolidCube(1.0);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.4f, -0.3f, 0.2f);
    glScalef(0.1f, 0.6f, 0.1f);
    glutSolidCube(1.0);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.4f, -0.3f, 0.2f);
    glScalef(0.1f, 0.6f, 0.1f);
    glutSolidCube(1.0);
    glPopMatrix();

    glPopMatrix();
}

// Hàm hiển thị
void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    // Đặt camera
    gluLookAt(cameraX, cameraY, cameraZ, cameraX + sin(cameraAngle), cameraY, cameraZ - cos(cameraAngle), 0.0f, 1.0f, 0.0f);

    // Vẽ mặt sàn
    drawFloor();

    // Vẽ các đối tượng
    drawColumn(-2.0f, -2.0f);
    drawColumn(2.0f, -2.0f);
    drawTable(0.0f, 2.0f);

    glutSwapBuffers();
}

// Hàm xử lý nhập từ bàn phím
void keyboard(unsigned char key, int x, int y) {
    const float speed = 0.1f;
    switch (key) {
        case 'w':  // Tiến về phía trước
            cameraX += speed * sin(cameraAngle);
            cameraZ -= speed * cos(cameraAngle);
            break;
        case 's':  // Lùi về phía sau
            cameraX -= speed * sin(cameraAngle);
            cameraZ += speed * cos(cameraAngle);
            break;
        case 'a':  // Sang trái
            cameraX -= speed * cos(cameraAngle);
            cameraZ -= speed * sin(cameraAngle);
            break;
        case 'd':  // Sang phải
            cameraX += speed * cos(cameraAngle);
            cameraZ += speed * sin(cameraAngle);
            break;
        case 'q':  // Xoay trái
            cameraAngle -= 0.1f;
            break;
        case 'e':  // Xoay phải
            cameraAngle += 0.1f;
            break;
        case 27:   // ESC để thoát
            exit(0);
    }
    glutPostRedisplay();
}

// Hàm khởi tạo
void init() {
    glClearColor(0.5f, 0.7f, 1.0f, 1.0f); // Màu nền
    glEnable(GL_DEPTH_TEST);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, 1.0, 0.1, 100.0);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("3D World with Moving Camera");

    init();
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMainLoop();

    return 0;
}
