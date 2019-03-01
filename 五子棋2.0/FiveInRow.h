int ForbiddenMove(int m, int j);
int Judge(int Position[16][16], int i, int j);
int Announce(int i, int j);
void DrawBoard();
void Putchess(int i, int j, int Mode);
void Evaluate(int);
struct point FindNextStep(int);
struct point GetPoint(int);
void PvP();
void PvC_Black();
void PvC_White();

extern char B[16][15*2+3];
extern char chess1[2];
extern char Current_chess1[2];
extern char chess2[2];
extern char Current_chess2[2];
extern int Position1[16][16];
extern int Position2[16][16];
extern int Value[16][16];
extern int dx[8];
extern int dy[8];

int Record1[2];
int Record2[2];
int Record3[2];
char B_recoder1[2];
char B_recoder2[2];

struct point{
	int x;
	int y;
};

#define Black 0
#define White 1