#include <windows.h>
#include <GL/glut.h>
void display(void)
{
 
 glClear(GL_COLOR_BUFFER_BIT);  //清空颜色缓冲区
 glColor3f(0,1,1);   //重置颜色
 //glLoadIdentity();   //清空矩阵
 glTranslatef(0,0,-5); //将场景中的物体沿z轴负方向移动5个单位长
 glRotatef(40,0,1,0);
 gluLookAt(0,0,1,0,0,0,0,2,0); //视点变换
 glScalef(1,2,1);  //模型变换
 glutWireCube(1.0); //绘制实心立方体和线框立方体
 glFlush();   //刷新窗口以显示当前绘制图形
} 
void init(void)
{
 glClearColor(0,0,0,0);
 glShadeModel(GL_FLAT); //选择平面明暗模式或光滑明暗模式
}

void reshape(int w,int h)
{
 glViewport(0,0,(GLsizei)w,(GLsizei)h);   //设置机口
 glMatrixMode(GL_PROJECTION);  //指定哪一个矩阵是当前矩阵
 glLoadIdentity();
    gluPerspective(60,1,1.5,20);   //创建透视投影矩阵(fovy,aspect,zNear,zFar);
 //glFrustum(-1,1,-1,1,1.5,20.0);  //用透视矩阵乘以当前矩阵(left,Right,bottom,top,near,far);
 glMatrixMode(GL_MODELVIEW);
}
int main(int argc, char *argv[])
{
 glutInit(&argc, argv); //固定格式
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);   //缓存模式
 glutInitWindowSize(400, 400);    //显示框的大小
    glutInitWindowPosition(400,400); //确定显示框左上角的位置
    glutCreateWindow("第⑤个OpenGL程序（绘制立方体）");
 init();
    glutDisplayFunc(display);
 glutReshapeFunc(reshape);
    glutMainLoop(); //进人GLUT事件处理循环
    return 0;
}

 