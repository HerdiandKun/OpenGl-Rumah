#define MAX_PARTICLES 1000
int loop;

typedef struct {

  float xpos;
  float ypos;
  float zpos;
}particles;

particles par_sys[MAX_PARTICLES];

void initParticles(int i) {
    par_sys[i].xpos = (float) (rand() % 50);
    par_sys[i].ypos = (float) (rand() % 50);
    par_sys[i].zpos = (float) (rand() % 50);
}
void init( ) {
   for (loop = 0; loop < MAX_PARTICLES; loop++) {
        initParticles(loop);
    }
}
void Hujan() {
  float x, y, z;

  for (loop = 0; loop < MAX_PARTICLES; loop=loop+2) {
      x = par_sys[loop].xpos;
      y = par_sys[loop].ypos;
      z = par_sys[loop].zpos;

      // GambarHujan
      glColor3ub(255, 255, 255);
      glBegin(GL_LINES);
        glVertex3f(x, y, z);
        glVertex3f(x, y+1, z);
      glEnd();
    }
  }

