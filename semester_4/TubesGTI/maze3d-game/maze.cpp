#include <math.h>
#include <GL/glut.h>
#include <stdio.h>

#include "maze.h"
#include "hud.h"
#include "geometri.h"
#include "tree.h"
#include "hole.h"
#include "spike.h"


void drawMaze()
{
	// ================= DINDING =================
	WallTex(0, 0, 0,   2, 4,  -20, texWall); // 1
    WallTex( 0, 0, 0,   7.5, 4,  -2, texWall); // 2
    WallTex( 18, 0, 0,  20, 4, -20, texWall); // 3
    WallTex( 12.5, 0, 0,  20, 4, -2, texWall); // 4
    WallTex( 0, 0, -18,  20, 4, -20, texWall); // 5
    
    WallTex( 10, 0, -25,  20, 4, -27, texWall); //6
    WallTex( 10, 0, -25,  12, 4, -35, texWall); //7
    WallTex( 5, 0, -25,  -5, 4, -27, texWall); //8
    WallTex( -5, 0, -15, -7, 4, -27, texWall); //9
    WallTex( 3, 0, -40,  24, 4, -42, texWall); //10
    
    WallTex( 5, 0, -32, 3, 4, -42, texWall); //11
    WallTex( 22, 0, -42,  24, 4, -47, texWall); //12
    WallTex( 22, 0, -45, 39, 4, -47, texWall); //13
    WallTex( -2, 0, -32,  -16, 4, -34, texWall); //14
    WallTex( -14, 0, -32, -16, 4, -47, texWall); //15
    
    WallTex( -10, 0, -45,  -16, 4, -47, texWall); //16
	WallTex( -2, 0, -39,  -9, 4, -41, texWall); //17
    WallTex( -2, 0, -41, -4, 4, -47, texWall); //18
    WallTex( -2, 0, -45,  5, 4, -47, texWall); //19
    WallTex( 10, 0, -45,  17, 4, -47, texWall); //20
    
    WallTex( 10, 0, -47, 12, 4, -54, texWall); //21
    WallTex( 10, 0, -52,  -10, 4, -54, texWall); //22
    WallTex( -10, 0, -52,  -12, 4, -59, texWall); //23
    WallTex( -4, 0, -59, -43, 4, -61, texWall); //24
    WallTex( -28, 0, -52,  -30, 4, -59, texWall); //25
    
    WallTex( -21, 0, -45, -23, 4, -54, texWall); //26
    WallTex( -15, 0, -52,  -21, 4, -54, texWall); //27
    WallTex( -41, 0, -15,  -43, 4, -61, texWall); //28
    WallTex( -37, 0, -51,  -42, 4, -53, texWall); //29 
	WallTex( -35, 0, -47, -37, 4, -53, texWall); //30
	
    WallTex( -28, 0, -45,  -37, 4, -47, texWall); //31
    WallTex( -28, 0, -34, -30, 4, -45, texWall); //32
    WallTex( -21, 0, -38,  -30, 4, -40, texWall); //33
    WallTex( -36, 0, -34, -41, 4, -36, texWall); //34
    WallTex( -34, 0, -40,  -36, 4, -27, texWall); //35
    
    WallTex( -21, 0, -27, -34, 4, -29, texWall); //36
    WallTex( -36, 0, -15, -41, 4, -17, texWall); //37
//    WallTex( -36, 0, -34, -41, 4, -36, texWall); //38
    WallTex( -34, 0, 8,  -36, 4, -22, texWall); //39
    WallTex( -27, 0, -10, -34, 4, -12, texWall); //40
    
    WallTex( -27, 0, -17,  -29, 4, -22, texWall); //41
    WallTex( -21, 0, -20,  -27, 4, -22, texWall); //42
    WallTex( -21, 0, -1,   -23, 4, -20, texWall); //43
    WallTex( -12, 0, -1,  -21, 4, -3, texWall); //44
    WallTex( -12, 0, -8,  -14, 4, -27, texWall); //45
    
    WallTex( -5, 0, -8, -12, 4, -10, texWall); //46
    WallTex( -5, 0, -8,  -7, 4, 15, texWall); //47
	WallTex( -21, 0, 13,  -7, 4, 15, texWall); //48
    WallTex( -12, 0, 4,  -28, 4, 6, texWall); //49
	WallTex( -27, 0, -5,  -29, 4, 15, texWall); //50
	
	WallTex( -12, 0, 20,  -28, 4, 22, texWall); //51
	WallTex( -26, 0, 22,  -28, 4, 29, texWall); //52
	WallTex( -12, 0, 27,  -28, 4, 29, texWall); //53	
	WallTex( -5, 0, 20,  -7, 4, 29, texWall); //54
	WallTex( 7, 0, 27,  -5, 4, 29, texWall); //55
	
	WallTex( -24, 0, 34,  -26, 4, 43, texWall); //56
	WallTex( -17, 0, 43,  -31, 4, 45, texWall); //57
	WallTex( -34, 0, 15,  -36, 4, 21, texWall); //58
	WallTex( -34, 0, 13,  -41, 4, 15, texWall); //59
	WallTex( -41, 0, -5,  -43, 4, 50, texWall); //60
    
    WallTex( -34, 0, 26,  -41, 4, 28, texWall); //61
	WallTex( -34, 0, 28,  -36, 4, 34, texWall); //62
	WallTex( -31, 0, 32,  -36, 4, 34, texWall); //63	
	WallTex( -36, 0, 43,  -41, 4, 45, texWall); //64
    WallTex( -43, 0, 50,  14, 4, 52, texWall); //65
    
    WallTex( -10, 0, 43,  -12, 4, 50, texWall); //66
	WallTex( -10, 0, 43,  9, 4, 45, texWall); //67
	WallTex( 3, 0, 45,    5, 4, 47, texWall); //68	
    WallTex( 21, 0, 38,   23, 4, 52, texWall); //69
	WallTex( -21, 0, 36,  27, 4, 38, texWall); //70
	
	WallTex( 12, 0, 43,  14, 4, 50, texWall); //new
	WallTex( 12, 0, 43,  18, 4, 45, texWall); //new
	
	WallTex( 14, 0, 5,  16, 4, 36, texWall); //71
	WallTex( 9, 0, 5,   14, 4, 7, texWall); //72
    WallTex( 7, 0, 5,   9, 4, 15, texWall); //73
	WallTex( 2, 0, 20,  9, 4, 22, texWall); //74
	WallTex( 0, 0, 5,   2, 4, 22, texWall); //75
    
    WallTex( 17, 0, 50,  67, 4, 52, texWall); //76
	WallTex( 46, 0, 50,  48, 4, 42, texWall); //77
	WallTex( 46, 0, 40,  55, 4, 42, texWall); //78
	WallTex( 67, 0, 52,  69, 4, -14, texWall); //79
	WallTex( 60, 0, 32,  62, 4, 42, texWall); //80
	
	WallTex( 62, 0, 32,  67, 4, 34, texWall); //81
	WallTex( 67, 0, 25,  53, 4, 27, texWall); //82
	WallTex( 53, 0, 27,  55, 4, 33, texWall); //83
	WallTex( 55, 0, 33,  41, 4, 35, texWall); //84
	WallTex( 39, 0, 33,  41, 4, 43, texWall); //85
	
	WallTex( 28, 0, 41,  39, 4, 43, texWall); //86
	WallTex( 32, 0, 27,  34, 4, 43, texWall); //87
	WallTex( 21, 0, 25,  48, 4, 27, texWall); //88
	WallTex( 46, 0, 18,  48, 4, 25, texWall); //89
	WallTex( 48, 0, 18,  55, 4, 20, texWall); //90
	
	WallTex( 21, 0, 25,  23, 4, 5, texWall); //91
	WallTex( 21, 0, 10,	 34, 4, 12, texWall); //92
	WallTex( 32, 0, 5,   34, 4, 12, texWall); //93
	WallTex( 67, 0, 9,   62, 4, 7, texWall); //94
	WallTex( 60, 0, 20,  62, 4, -2, texWall); //95
	
	WallTex( 67, 0, -7,  53, 4, -5, texWall); //96
	WallTex( 53, 0, -5,  55, 4, 5, texWall); //9
	WallTex( 55, 0, 5,   39, 4, 7, texWall); //97
	WallTex( 39, 0, 17,  41, 4, -6, texWall); //98
	WallTex( 27, 0, 17,  41, 4, 19, texWall); //99
	WallTex( 34, 0, -6,  39, 4, -4, texWall); //100
	WallTex( 32, 0, -6,  34, 4, 0, texWall); //101
	
	WallTex( 46, 0, 0,	  48, 4, -13, texWall); //102
	WallTex( 30, 0, -11,  48, 4, -13, texWall); //103
	WallTex( 30, 0, -13,  32, 4, -27, texWall); //104
	WallTex( 32, 0, -25,  41, 4, -27, texWall); //105
	
	WallTex( 17, 0, -32,  48, 4, -34, texWall); //106
	WallTex( 46, 0, -18,  48, 4, -34, texWall); //107
	WallTex( 37, 0, -18,  46, 4, -20, texWall); //108
	WallTex( 30, 0, -39,  46, 4, -41, texWall); //109
	WallTex( 44, 0, -41,  46, 4, -53, texWall); //110
	
	WallTex( 44, 0, -51,  54, 4, -53, texWall); //111
	WallTex( 17, 0, -52,  19, 4, -61, texWall); //112
	WallTex( 2, 0, -59,  69, 4, -61, texWall); //113
	WallTex( 37, 0, -52,  39, 4, -59, texWall); //114
	WallTex( 24, 0, -52,  39, 4, -54, texWall); //115
	
	WallTex( 60, 0, -48,  62, 4, -59, texWall); //116
	WallTex( 67, 0, -19,  69, 4, -61, texWall); //117
	WallTex( 60, 0, -41,  69, 4, -43, texWall); //118
	WallTex( 60, 0, -33,  62, 4, -43, texWall); //119
	WallTex( 62, 0, -19,  67, 4, -21, texWall); //120
	
	WallTex( 60, 0, -19,  62, 4, -26, texWall); //121
	WallTex( 55, 0, -26,  62, 4, -28, texWall); //122
	WallTex( 55, 0, -26,  53, 4, -45, texWall); //123
	WallTex( 53, 0, -12,  55, 4, -20, texWall); //124
	WallTex( 53, 0, -12,  64, 4, -14, texWall); //125
	
	// ================= POHON KECIL =================
    drawSmallTree(20, 10);
    drawSmallTree(-15.5, -10.0 );
    drawSmallTree(17, 25);
    drawSmallTree(22,34);
    drawSmallTree(32,16);
    drawSmallTree(28,20);
    drawSmallTree(36,24);
    drawSmallTree(35,6);
    drawSmallTree(43.0, 32.0);
    drawSmallTree(5.5, 11.0);
    drawSmallTree(-1.0, -4.0);
    drawSmallTree(37.0, -21.0);
    drawSmallTree(42.0, -14.0);
    drawSmallTree(-2.0, 35.0);
    drawSmallTree(-12.0, 35.0);
    drawSmallTree(-33.5, 14.0);
	drawSmallTree(-33.5, 0.0);
	drawSmallTree(-8, 42.5);
	drawSmallTree(0, 39);
	drawSmallTree(7, 42.5);
	drawSmallTree(35, -35);
	drawSmallTree(49.0, -33.0);
	drawSmallTree(-26.0, -30.0);
	drawSmallTree(-11.0, -21.0);
	drawSmallTree(-4.0, 10.0);
	drawSmallTree(-19.0, 16.0);
	drawSmallTree(-26.0, 14.0);
	drawSmallTree(-29.0, 46.0);
	drawSmallTree(-19.0, 49.0);
	drawSmallTree(-28.0, 51.0);	
	drawSmallTree(51.0, -43.0);	
	drawSmallTree(52.0, -58.0);	
	drawSmallTree(59.0, -37.0);	
	drawSmallTree(36.0, -47.0);	
	drawSmallTree(24.0, -51.0);	
	drawSmallTree(-12.0, -47.0);
	drawSmallTree(0, -51.0);		
	drawSmallTree(17.0, -46.0);	
	drawSmallTree(-7.0, -31.0);	
	drawSmallTree(-14.0, -28.0);	
	drawSmallTree(2, -33.0);
	drawSmallTree(32, -9);

	// ================= POHON BESAR =================
	drawTree(10.0, -10.0);
	drawTree(28.0, -11);
	drawTree(1.0, -58.5);
	drawTree(-36.0, -56.5);
    drawTree(13.0, -55.0);
    drawTree(35.0, -56.0);
    drawTree(-27.0, -48.0);
    drawTree(58.0, -48.5);
    drawTree(27.0, -26.0);
    drawTree(22.0, -18.0);
    drawTree(22.0, -4.0);
    drawTree(-18.0, -35.0);
    drawTree(23.0, -35.0);
    drawTree(56.0, -22.5);
    drawTree(-39, -27.0);
    drawTree(9.5, -24.5);
    drawTree(-13.5, 12.0);
    drawTree(-19.0, -19.0);
    drawTree(-4.0, -14.0);
    drawTree(-32.0, -8.0);
    drawTree(53.0, -8.0);
    drawTree(-40.0, 1.0);
    drawTree(28.0, 2.0);
   	drawTree(47.0, 10.0);
   	drawTree(47.0, 17.0);
    drawTree(10.0, 23.0); //1
    drawTree(-33.0, 25.5); //1
    drawTree(-22.0, 25.0); //1
    drawTree(35.0, 29.0); 
    drawTree(-20.0, 31.5);
    drawTree(8.0, 31.0); //1
    drawTree(-35.0, 41.0);
    drawTree(28.0, 30.0);
    drawTree(39.0, 45.0);
    drawTree(58.0, 46.0);
    drawTree(30.0, 49.0);
    drawTree(54.0, 12.0);
    
    // ================= SEMAK =================
    drawSemak(16, -2);
    drawSemak(14, -2.7);
    drawSemak(16, -17);
    drawSemak(12, -16);
    drawSemak(3, -17);
    drawSemak(6.2, -2.3);
    
    // ================= HOLE =================
    drawHole(25.5, -15.0, 1.5f);
    drawHole(37.5, 6.0, 1.5f);
    drawHole(-19.0, 18.5, 1.5f);
    drawHole(-19.0, -10.0, 1.5f);
    drawHole(1.0, -43.0, 1.5f);
    drawHole(34.0, -43.0, 1.5f);
    drawHole(50.0, -5.0, 1.5f);
	
	// ================= SPIKE =================
	drawSpike(1, 4);
    drawSpike(1, 3);
    drawSpike(1, 2);
    drawSpike(1, 1);
    
    drawSpike(16, 4);
    drawSpike(16, 3);
    drawSpike(16, 2);
    drawSpike(16, 1);
    
    drawSpike(19, 10);
    drawSpike(18, 10);
    drawSpike(17, 10);
    
    drawSpike(17, 25);
    drawSpike(16, 25);
    drawSpike(15, 25);
    
    drawSpike(32, 15);
    drawSpike(32, 14);
    drawSpike(32, 13);

	drawSpike(22, 29);
    drawSpike(22, 30);
    drawSpike(22, 31);
	drawSpike(22, 32);
	    
	drawSpike(56, 19);
    drawSpike(57, 19);
    drawSpike(58, 19);
    drawSpike(59, 19);
    
    drawSpike(30, 26);
    drawSpike(29, 26);
    drawSpike(28, 26);
    
    drawSpike(40, 26);
    drawSpike(40, 26);
    drawSpike(40, 26);
    
    drawSpike(25, -4);
    drawSpike(26, -4);
    drawSpike(27, -4);
    drawSpike(28, -4);
    drawSpike(29, -4);
    drawSpike(30, -4);
    
    drawSpike(17, 18);
    drawSpike(18, 18);
    drawSpike(19, 18);
    drawSpike(20, 18);
    
    drawSpike(19, 25);
    drawSpike(20, 25);
    
    drawSpike(28, 22);
    drawSpike(28, 23);
    drawSpike(28, 24);
    
    drawSpike(36, 20);
    drawSpike(36, 21);
    drawSpike(36, 22);
    
    drawSpike(42, 43);
    drawSpike(43, 42);
    drawSpike(44, 41);
    drawSpike(45, 40);
    
    drawSpike(46, 39);
    drawSpike(47, 38);
    drawSpike(48, 37);
    drawSpike(49, 36);
    
    drawSpike(43, 28);
    drawSpike(43, 29);
    drawSpike(43, 30);
    
    drawSpike(5, 11);
    drawSpike(4, 11);
    drawSpike(3, 11);
    drawSpike(2, 11);
    
    drawSpike(-2, 33);
    drawSpike(-2, 32);
    drawSpike(-2, 31);
    drawSpike(-2, 30);
    
    drawSpike(-12, 33);
    drawSpike(-12, 32);
    drawSpike(-12, 31);
    drawSpike(-12, 30);
    
    drawSpike(-1, 19);
    drawSpike(-2, 20);
    drawSpike(-3, 21);
    drawSpike(-4, 22);
    
    drawSpike(-2, -4);
    drawSpike(-3, -4);
    drawSpike(-4, -4);
    drawSpike(-5, -4);
    
    drawSpike(42, -6);
    drawSpike(43, -7);
    drawSpike(44, -8);
    drawSpike(45, -9);
    
    drawSpike(42, -5);
    drawSpike(43, -4);
    drawSpike(44, -3);
    drawSpike(45, -2);
    
    drawSpike(-37, 8);
    drawSpike(-38, 9);
    drawSpike(-39, 10);
    drawSpike(-40, 11);
    
    drawSpike(-32, 14);
    drawSpike(-31, 14);
    drawSpike(-30, 14);
    
    drawSpike(-32, 0);
    drawSpike(-31, 0);
    drawSpike(-30, 0);
    
    drawSpike(-8, 39);
    drawSpike(-8, 41);
    drawSpike(-8, 40);
    
    drawSpike(0, 41);
    drawSpike(0, 42);
    drawSpike(0, 43);
    
    drawSpike(7, 39);
    drawSpike(7, 41);
    drawSpike(7, 40);
    
    drawSpike(42, -16);
    drawSpike(42, -17);
    drawSpike(42, -18);
    
    drawSpike(35, -38);
    drawSpike(35, -36);
    drawSpike(35, -37);
    
    drawSpike(45, -26);
    drawSpike(46, -26);
    drawSpike(44, -26);
    drawSpike(43, -26);
    
    drawSpike(51, -33);
    drawSpike(52, -33);
    drawSpike(53, -33);
    
    drawSpike(-26, -32);
    drawSpike(-26, -33);
    drawSpike(-26, -34);
    
    drawSpike(-9, -21);
    drawSpike(-8, -21);
    drawSpike(-7, -21);
    
    drawSpike(-29, 48);
    drawSpike(-29, 49);
    drawSpike(-29, 50);
    
    drawSpike(-19, 46);
    drawSpike(-19, 47);
    drawSpike(-19, 48);
    
    drawSpike(-23, 14);
    drawSpike(-24, 14);
    drawSpike(-25, 14);

    drawSpike(49, -43);
    drawSpike(48, -43);
    drawSpike(47, -43);
    drawSpike(46, -43);
    
    drawSpike(55, -37);
    drawSpike(56, -37);
    drawSpike(57, -37);
    
    drawSpike(52, -54);
    drawSpike(52, -56);
    drawSpike(52, -55);
    
    drawSpike(-12, -51);
    drawSpike(-12, -49);
    drawSpike(-12, -50);
    
    drawSpike(24, -50);
    drawSpike(24, -49);
    drawSpike(24, -48);
    
    drawSpike(36, -50);
    drawSpike(36, -51);
    drawSpike(36, -49);
    
    drawSpike(0, -49);
    drawSpike(0, -48);
    drawSpike(0, -47);
    
    drawSpike(19, -46);
    drawSpike(20, -46);
    drawSpike(21, -46);
    
    drawSpike(-7, -29);
    drawSpike(-7, -28);
    drawSpike(-7, -27);
   
    drawSpike(-14, -30);
    drawSpike(-14, -31);
    drawSpike(-14, -32);
	
	drawSpike(-13, -35);
    drawSpike(-12, -36);
    drawSpike(-11, -37);
	drawSpike(-10, -38);
	
	drawSpike(6, -39);
	drawSpike(7, -38);
	drawSpike(8, -37);
	drawSpike(9, -36);
	 
	drawSpike(-29, -12);
    drawSpike(-29, -13);
    drawSpike(-29, -14);
    drawSpike(-29, -15);
    
    drawSpike(13, -44);
    drawSpike(13, -43);
    drawSpike(13, -42);
    
    drawSpike(-2, -33);
    drawSpike(-1, -33);
    drawSpike(0, -33);
    
    drawSpike(-27, -3);
    drawSpike(-26, -3);
    drawSpike(-25, -3);
    drawSpike(-24, -3);
    
	// ================= FIREWORK =================
	firework(68.5f, -9.5f, 9.0f, 0);   // langsung
	firework(67.0f, -9.0f, 10.0f, 60); // jeda 1 detik
	firework(68.0f, -9.5f, 8.0f, 120); // jeda 2 detik
	
	firework(-41.5f, -10.5f, 9.0f, 0);   // langsung
	firework(-42.0f, -9.5f, 10.0f, 60); // jeda 1 detik
	firework(-40.5f, -9.0f, 8.0f, 120); // jeda 2 detik
	
	firework(10.5f, -61.5f, 9.0f, 0);   // langsung
	firework(11.0f, -61.0f, 10.0f, 60); // jeda 1 detik
	firework(9.5f, -61.0f, 8.0f, 120); // jeda 2 detik
	
	firework(19.0f, 53.5f, 9.0f, 0);   // langsung
	firework(17.0f, 54.0f, 10.0f, 60); // jeda 1 detik
	firework(18.0f, 53.5f, 8.0f, 120); // jeda 2 detik
}
