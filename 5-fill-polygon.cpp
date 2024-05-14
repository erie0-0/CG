#include<iostream>
#include<graphics.h>
#include<math.h>
using namespace std;
#include <graphics.h>
#include <iostream>
using namespace std;
int main()
{
int n, i, j, k, gd, gm, dy, dx;
int x, y, temp;
int a[20][2], xi[20];
float slope[20];
int temp1 = 0;
cout << "\nEnter the number of edges ";
cin >> n;
for (i = 0; i < n; i++)
{
cout << "Enter the coordinate x" << i + 1 << " ";
cin >> a[i][0];
cout << "Enter the coordinate y" << i + 1 << " ";
cin >> a[i][1];
}
a[n][0] = a[0][0];
a[n][1] = a[0][1];
initgraph(&gd, &gm, NULL);
setcolor(YELLOW);
for (i = 0; i < n; i++)
{
line(a[i][0], a[i][1], a[i + 1][0], a[i + 1][1]);
}
for (i = 0; i < n; i++)
{
dy = a[i + 1][1] - a[i][1];
dx = a[i + 1][0] - a[i][0];
if (dy == 0)
slope[i] = 1.0;
if (dx == 0)
slope[i] = 0.0;
if ((dy != 0) && (dx != 0))
{
slope[i] = (float)dx / dy;
}
}
for (y = 0; y < 400; y++)
{
k = 0;
for (i = 0; i < n; i++)
{
if (((a[i][1] <= y) && (a[i + 1][1] > y)) || ((a[i][1] > y) && (a[i + 1][1] <= y)))
{
xi[k] = (int)(a[i][0] + slope[i] * (y - a[i][1]));
k++;
}
}
for (j = 0; j < k; j++)
for (i = 0; i < k; i++)
{
if (xi[i] > xi[i + 1])
{
temp = xi[i];
xi[i] = xi[i + 1];
xi[i + 1] = temp;
}
}
setcolor(YELLOW);
for (i = 0; i < k; i += 2)
{
line(xi[i], y, xi[i + 1] + 1, y);
temp1 = i;
}
}
delay(7000);
return 0;
}
/*const int WINDOW_HEIGHT = 1000;
typedef struct tdcPt
{
int x;
int y;
}dcPt;
typedef struct tEdge
{
int yUpper;
float xIntersect, dxPerScan;
struct tEdge *next;
}Edge;
 
// Vertices: Array of structures.
dcPt vertex[5] = {{200, 500}, {300, 250}, {270, 230}, {320, 200}, {360, 290}};
void insertEdge(Edge *list, Edge *edge)
{
Edge *p, *q = list;
p = q->next;
while (p != NULL) 
{
if (edge->xIntersect < p->xIntersect)
p = NULL;
else 
{
q = p;
p = p->next;
}
} 
edge->next = q->next;
q->next = edge;
}
int yNext(int k, int cnt, dcPt *pts)
{
int j;
if ((k + 1) > (cnt - 1))
j = 0;
else
j = k + 1;
while(pts[k].y == pts[j].y)
{
if ((j + 1) > (cnt - 1))
j = 0;
else
j++;
}
return (pts[j].y);
}
void makeEdgeRec(dcPt lower, dcPt upper, int yComp, Edge *edge, Edge 
*edges[])
{
edge->dxPerScan = (float) (upper.x - lower.x) / (upper.y - lower.y);
edge->xIntersect = lower.x;
if (upper.y < yComp)
edge->yUpper = upper.y - 1;
else
edge->yUpper = upper.y;
insertEdge(edges[lower.y], edge);
}
void buildEdgeList(int cnt, dcPt *pts, Edge *edges[])
{
Edge *edge;
dcPt v1, v2;
int i, yPrev = pts[cnt - 2].y;
v1.x = pts[cnt - 1].x; v1.y = pts[cnt - 1].y;
for(int i = 0; i < cnt; i++) 
{
v2 = pts[i];
if (v1.y != v2.y) // nonhorizontal line 
{
edge = (Edge *) malloc (sizeof(Edge));
if (v1.y < v2.y) // upgoing edge
makeEdgeRec(v1, v2, yNext(i, cnt, pts), edge, edges);
else // down-going edge
makeEdgeRec(v2, v1 , yPrev, edge, edges);
}
yPrev = v1.y;
v1 = v2;
}
}
void buildActiveList(int scan, Edge *active, Edge *edges[])
{
Edge *p, *q;
p = edges[scan]->next;
while (p) 
{
q = p->next;
insertEdge(active, p);
p = q;
}
}
void fillScan(int scan, Edge *active)
{
Edge *p1, *p2 ;
int i;
p1 = active->next;
while (p1)
{
p2 = p1->next; 
for(i = p1->xIntersect; i < p2->xIntersect; i++)
putpixel((int) i, scan, GREEN);
p1 = p2->next; 
}
}
void deleteAfter(Edge *q)
{
Edge *p = q->next;
q->next = p->next;
free(p);
}
void updateActiveList(int scan, Edge *active)
{
Edge *q = active, *p = active->next;
while (p)
{
if (scan >= p->yUpper)
{
p = p->next;
deleteAfter(q);
}
else
{
p->xIntersect = p->xIntersect + p->dxPerScan;
q = p;
p = p->next;
}
}
}
void resortActiveList(Edge *active)
{
Edge *q, *p = active->next;
active->next = NULL;
while (p) 
{
q = p->next;
insertEdge(active, p);
p = q;
}
}
void scanFill(int cnt, dcPt *pts)
{
Edge *edges[WINDOW_HEIGHT], *active;
int i, scan;
for (i = 0; i < WINDOW_HEIGHT; i++) 
{
edges[i] = (Edge *) malloc (sizeof(Edge));;
edges[i]->next = NULL;
}
buildEdgeList(cnt, pts, edges);
active = (Edge *) malloc (sizeof(Edge));;
active->next = NULL;
for (scan = 0; scan < WINDOW_HEIGHT; scan++)
{
buildActiveList(scan, active, edges);
if (active->next) 
{
fillScan(scan, active);
updateActiveList(scan, active) ;
resortActiveList(active);
}
}
free(edges[WINDOW_HEIGHT]);
free(active);
}
int main()
{
int gd = DETECT, gm;
initgraph(&gd, &gm, (char*)"");
float X = getmaxx(), Y = getmaxy();
float x_mid = X / 2;
float y_mid = Y / 2;
cleardevice();
scanFill(5, vertex);
getch();
closegraph();
return 0;
}*/

