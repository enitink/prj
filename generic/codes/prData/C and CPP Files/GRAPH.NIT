#include<graphics.h>
#include<dos.h>
#include<stdio.h>
#include<conio.h>
#include <math.h>
#include <stdlib.h>
#include <stdarg.h>

#include <graphics.h>
void DrawBorder(void);
main()
  {
   int dri = DETECT,mode;
   initgraph(&dri,&mode,"bgi");
   setcolor(RED);
   textbackground(YELLOW+RED);
   settextstyle(4,HORIZ_DIR,7);
   outtextxy(0,10, " NITIN KUMAR");
   settextstyle(4,VERT_DIR,7);
   outtextxy(0,10, " NITIN KUMAR");
   settextstyle(4,VERT_DIR,7);
   outtextxy(500,10, " NITIN KUMAR");
   settextstyle(4,HORIZ_DIR,7);
   outtextxy(20,400, "NITIN KUMAR");

   sleep(5);
  }
void DrawBorder(void)
{
  struct viewporttype vp;

  setcolor( MaxColors - 1 );		/* Set current color to white	*/

  setlinestyle( SOLID_LINE, 0, NORM_WIDTH );

  getviewsettings( &vp );
  rectangle( 0, 0, vp.right-vp.left, vp.bottom-vp.top );

}
