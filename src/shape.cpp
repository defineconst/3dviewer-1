#include "shape.h"
#include <QImage>

#include <iostream>
using namespace std;

// 注: 贴图有可能反了
GLuint LoadTexture(const string filename){
	GLuint id;
	glGenTextures(1, &id);
	glBindTexture(GL_TEXTURE_2D, id);

	QImage img(filename.c_str());
	unsigned char * buf = img.bits();
	unsigned int width = img.width();
	unsigned int height = img.height();

	GLenum image_format = GL_RGB;
	GLint internal_format = GL_BGRA_EXT;

	glTexImage2D(GL_TEXTURE_2D, 0, image_format, width, height,0, internal_format, GL_UNSIGNED_BYTE, buf);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

	glBindTexture(GL_TEXTURE_2D, 0);

	return id;
}

void DrawAxis(){

	glLineWidth(4);
	glBegin(GL_LINES);
		glColor3ub(255, 0, 0);
		glVertex3f(0, 0, 0);
		glVertex3f(1, 0, 0);
		glColor3ub(0, 255, 0);
		glVertex3f(0, 0, 0);
		glVertex3f(0, 1, 0);
		glColor3ub(0, 0, 255);
		glVertex3f(0, 0, 0);
		glVertex3f(0, 0, 1);
	glEnd();
	glLineWidth(1);
	
	double base = 0.05, height = 0.10;
	int slices = 10, stacks = 10;
	glColor3ub(255, 0, 0);
    glPushMatrix();  
    glTranslatef(1.0f - height,0.0f,0.0f);  
    glRotatef(90.0f,0.0f,1.0f,0.0f);  
    //glutWireCone(base,height,slices,stacks);  
    glPopMatrix();  
  
	glColor3ub(0, 255, 0);
    glPushMatrix();  
    glTranslatef(0.0f,1.0f - height,0.0f);  
    glRotatef(-90.0f,1.0f,0.0f,0.0f);  
    //glutWireCone(base,height,slices,stacks);  
    glPopMatrix();  
  
	glColor3ub(0, 0, 255);
    glPushMatrix();  
    glTranslatef(0.0f,0.0f,1.0f - height);  
    glRotatef(90.0f,0.0f,0.0f,1.0f);  
    //glutWireCone(base,height,slices,stacks);  
    glPopMatrix();  
}	

void DrawGround(){
	glLineWidth(2);
	const int K = 5;
	glColor3ub(127,127,127);
	glBegin(GL_LINES);
	for (int x = -K; x <= K;++x){
		glVertex3f(x,-K,0);
		glVertex3f(x,K,0);
	}
	for (int y = -K; y <= K;++y){
		glVertex3f(-K,y,0);
		glVertex3f(K,y,0);
	}
	glEnd();
	glLineWidth(0);
}
