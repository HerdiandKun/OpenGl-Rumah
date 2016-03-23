void rectangle(float a, float b){
    float widthP = 0, heightP = 0;
    widthP = a/2;
    heightP = b/2;

    glBegin(GL_POLYGON);
    glVertex2f(-widthP, -heightP); //kiri-bawah
    glVertex2f(widthP, -heightP); //kanan-bawah
    glVertex2f(widthP, heightP);	//kanan-atas
    glVertex2f(-widthP, heightP);  //kiri-atas
    glEnd();
}
void bilah(){
	glColor3f (146, 145, 151);
    rectangle(2,0.5);
	glColor3f (0, 255, 0);
    glLineWidth(1);
    glBegin(GL_LINE_LOOP);
    glVertex2f(1, -0.25);
	glVertex2f(-1, -0.25);
	glVertex2f(-1, 0.25);
	glVertex2f(1, 0.25);
    glEnd();
    for(int i = 0 ; i < 3;i++){
		int a = i * 0.5;
		glLineWidth(1);
		glBegin(GL_LINES);
		glVertex2f(-0.5 + a , -0.25);
		glVertex2f(-0.5 + a , 0.25);
		glEnd();
	}
}
void kincir()
{
    glPushMatrix();
        glTranslatef(-1.25,0,0);
        bilah();
    glPopMatrix();
    glPushMatrix();
        glTranslatef(1.25,0,0);
        bilah();
    glPopMatrix();
    glPushMatrix();
        glTranslatef(0,1.25,0);
        glRotatef(90,0,0,1);
        bilah();
    glPopMatrix();
    glPushMatrix();
        glTranslatef(0,-1.25,0);
        glRotatef(90,0,0,1);
        bilah();
    glPopMatrix();
}

void callkincir()
{
	static float sudut = 0.0;
    glPushMatrix();
        glRotatef(sudut,0,0,1);
        kincir();
    glPopMatrix();
    sudut += 0.5;
    glFlush();
}

