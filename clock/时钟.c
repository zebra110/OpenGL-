#include <windows.h>
#include <GL/glut.h>
void display(void)
{
 
 glClear(GL_COLOR_BUFFER_BIT);  //�����ɫ������
 glColor3f(0,1,1);   //������ɫ
 //glLoadIdentity();   //��վ���
 glTranslatef(0,0,-5); //�������е�������z�Ḻ�����ƶ�5����λ��
 glRotatef(40,0,1,0);
 gluLookAt(0,0,1,0,0,0,0,2,0); //�ӵ�任
 glScalef(1,2,1);  //ģ�ͱ任
 glutWireCube(1.0); //����ʵ����������߿�������
 glFlush();   //ˢ�´�������ʾ��ǰ����ͼ��
} 
void init(void)
{
 glClearColor(0,0,0,0);
 glShadeModel(GL_FLAT); //ѡ��ƽ������ģʽ��⻬����ģʽ
}

void reshape(int w,int h)
{
 glViewport(0,0,(GLsizei)w,(GLsizei)h);   //���û���
 glMatrixMode(GL_PROJECTION);  //ָ����һ�������ǵ�ǰ����
 glLoadIdentity();
    gluPerspective(60,1,1.5,20);   //����͸��ͶӰ����(fovy,aspect,zNear,zFar);
 //glFrustum(-1,1,-1,1,1.5,20.0);  //��͸�Ӿ�����Ե�ǰ����(left,Right,bottom,top,near,far);
 glMatrixMode(GL_MODELVIEW);
}
int main(int argc, char *argv[])
{
 glutInit(&argc, argv); //�̶���ʽ
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);   //����ģʽ
 glutInitWindowSize(400, 400);    //��ʾ��Ĵ�С
    glutInitWindowPosition(400,400); //ȷ����ʾ�����Ͻǵ�λ��
    glutCreateWindow("�ڢݸ�OpenGL���򣨻��������壩");
 init();
    glutDisplayFunc(display);
 glutReshapeFunc(reshape);
    glutMainLoop(); //����GLUT�¼�����ѭ��
    return 0;
}

 