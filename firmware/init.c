
#include "init.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <irq.h>
#include <uart.h>
#include <generated/csr.h>



int bod[121]=
{
	8,8,8,8,8,8,8,8,8,8,8,
	8,8,8,8,6,8,8,8,8,8,8,
	8,8,8,8,6,6,6,8,8,8,8,
	8,8,8,6,6,6,6,6,8,8,8,
	8,8,6,6,6,6,6,6,6,8,8,
	8,6,6,6,6,6,6,6,6,6,8,
	8,8,6,6,6,6,6,6,6,8,8,
	8,8,8,6,6,6,6,6,8,8,8,
	8,8,8,8,6,6,6,8,8,8,8,
	8,8,8,8,8,6,8,8,8,8,8,
	8,8,8,8,8,8,8,8,8,8,8,
	
};

int cora[121]={
	1,1,1,1,1,1,1,1,1,1,1,
	1,1,0,0,1,1,1,0,0,1,1,
	1,0,0,0,0,1,0,0,0,0,1,
	1,0,0,0,0,1,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,1,
	1,1,0,0,0,0,0,0,0,1,1,
	1,1,1,0,0,0,0,0,1,1,1,
	1,1,1,1,0,0,0,1,1,1,1,
	1,1,1,1,1,0,1,1,1,1,1,
	1,1,1,1,1,1,1,1,1,1,1
};


int food[121]={
	8,8,8,8,8,8,8,8,8,8,8,
	8,8,8,8,9,9,9,8,8,8,8,
	8,8,9,9,9,9,9,9,9,8,8,
	8,8,9,9,9,9,9,9,9,8,8,
	8,9,9,9,9,9,9,9,9,9,8,
	8,9,9,9,9,9,9,9,9,9,8,//centro
	8,9,9,9,9,9,9,9,9,9,8,
	8,8,9,9,9,9,9,9,9,8,8,
	8,8,9,9,9,9,9,9,9,8,8,
	8,8,8,8,9,9,9,8,8,8,8,
	8,8,8,8,8,8,8,8,8,8,8
};


int snakeHeadUp[121]={
	8,8,8,8,6,6,6,8,8,8,8,
	8,8,1,6,6,6,6,6,1,8,8,
	8,1,0,0,6,6,6,0,0,1,8,
	8,1,0,0,6,6,6,0,0,1,8,
	1,1,1,1,1,6,1,1,1,1,1,
	1,1,1,1,1,6,1,1,1,1,1,//centro
	8,1,1,1,6,6,6,1,1,1,8,
	8,8,6,6,6,6,6,6,6,8,8,
	8,8,8,6,6,6,6,6,8,8,8,
	8,8,8,6,6,6,6,6,8,8,8,
	8,8,8,6,6,6,6,6,8,8,8
};

int snakeHeadDown[121]={
	8,8,8,6,6,6,6,6,8,8,8,
	8,8,8,6,6,6,6,6,8,8,8,
	8,8,8,6,6,6,6,6,8,8,8,
	8,8,6,6,6,6,6,6,6,8,8,
	8,1,1,1,6,6,6,1,1,1,8,
	1,1,1,1,1,6,1,1,1,1,1,
	1,1,1,1,1,6,1,1,1,1,1,
	8,1,0,0,6,6,6,0,0,1,8,
	8,1,0,0,6,6,6,0,0,1,8,
	8,8,1,6,6,6,6,6,1,8,8,
	8,8,8,8,6,6,6,8,8,8,8
};

int snakeHeadRight[121]={
	8,8,8,8,8,1,1,8,8,8,8,
	8,8,8,8,1,1,1,1,1,8,8,
	8,8,8,6,1,1,1,0,0,1,8,
	6,6,6,6,1,1,1,0,0,6,8,
	6,6,6,6,6,1,1,6,6,6,6,
	6,6,6,6,6,6,6,6,6,6,6,//Centro
	6,6,6,6,6,1,1,6,6,6,6,
	6,6,6,6,1,1,1,0,0,6,8,
	8,8,8,6,1,1,1,0,0,1,8,
	8,8,8,8,1,1,1,1,1,8,8,
	8,8,8,8,8,1,1,8,8,8,8,
};

int snakeHeadLeft[121]={
	8,8,8,8,1,1,8,8,8,8,8,
	8,8,1,1,1,1,1,8,8,8,8,
	8,1,0,0,1,1,1,6,8,8,8,
	8,6,0,0,1,1,1,6,6,6,6,
	6,6,6,6,1,1,6,6,6,6,6,
	6,6,6,6,6,6,6,6,6,6,6,//centro	
	6,6,6,6,1,1,6,6,6,6,6,
	8,6,0,0,1,1,1,6,6,6,6,
	8,1,0,0,1,1,1,6,8,8,8,
	8,8,1,1,1,1,1,8,8,8,8,
	8,8,8,8,1,1,8,8,8,8,8
};




int gTitle[40][40]={
	{1,1,1,1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1,1,1,1,1,1,1,1},
	{1,1,1,1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1,1,1,1,1,1,1,1},  //1
	{1,1,1,1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1,1,1,1,1,1,1,1},
	{1,1,1,1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1,1,1,1,1,1,1,1},

	{2,2,2,2,2,2,2,2,2,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,2,2,2,2,2,2},
	{2,2,2,2,2,2,2,2,2,2,2,2,0,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,0,2,2,2,2,2,2,2,2}, //2
	{2,2,2,2,2,2,2,2,2,2,2,2,0,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,0,2,2,2,2,2,2,2,2},
	{2,2,2,2,2,2,2,2,2,2,2,2,0,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,0,2,2,2,2,2,2,2,2},

	{2,2,2,2,2,2,2,2,0,0,0,0,0,3,3,0,2,2,2,2,2,2,2,2,2,2,2,2,0,3,3,0,0,0,0,0,2,2,2,2},
	{2,2,2,2,2,2,2,2,0,3,3,3,3,3,3,0,2,2,2,2,2,2,2,2,2,2,2,2,0,3,3,3,3,3,3,0,2,2,2,2}, //3
	{2,2,2,2,2,2,2,2,0,3,3,3,3,3,3,0,2,2,2,2,2,2,2,2,2,2,2,2,0,3,3,3,3,3,3,0,2,2,2,2},
	{2,2,2,2,2,2,2,2,0,0,0,0,0,0,0,0,2,2,2,2,2,2,2,2,2,2,2,2,0,3,3,3,3,3,3,0,2,2,2,2},

	{2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,0,3,3,3,3,3,3,0,2,2,2,2},
	{2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,0,3,3,3,3,3,3,0,2,2,2,2}, //4
	{2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,0,3,3,3,3,3,3,0,2,2,2,2},
	{2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,0,3,3,3,3,3,3,0,2,2,2,2},

	{2,2,2,2,2,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0,2,2,2,2,2,2,2,2,0,3,3,3,3,3,3,0,2,2,2,2},
	{2,2,2,2,2,2,2,2,0,3,3,3,3,3,3,3,3,3,3,0,2,2,2,2,2,2,2,2,0,3,3,3,3,3,3,0,2,2,2,2},//5
	{2,2,2,2,2,2,2,2,0,3,3,3,3,3,3,3,3,3,3,0,2,2,2,2,2,2,2,2,0,3,3,3,3,3,3,0,2,2,2,2},
	{2,2,2,2,2,2,2,2,0,3,3,3,3,3,3,0,0,0,0,0,2,2,2,2,2,2,2,2,0,3,3,3,3,3,3,0,2,2,2,2},

	{2,2,2,2,2,2,2,2,0,3,3,3,3,3,3,0,2,2,2,2,2,2,2,2,2,2,2,2,0,3,3,3,3,3,3,0,2,2,2,2},
	{2,2,2,2,2,2,2,2,0,3,3,3,3,3,3,0,2,2,2,2,2,2,2,2,2,2,2,2,0,3,3,3,3,3,3,0,2,2,2,2},
	{2,2,2,2,2,2,2,2,0,3,3,3,3,3,3,0,2,2,2,2,2,2,2,2,2,2,2,2,0,3,3,3,3,3,3,0,2,2,2,2},//6
	{2,2,2,2,2,2,2,2,0,3,3,3,3,3,3,0,2,2,2,2,2,2,2,2,2,2,2,2,0,3,3,3,3,3,3,0,2,2,2,2},

	{2,2,2,2,2,2,2,2,0,3,3,3,3,3,3,0,2,2,2,2,2,2,2,2,2,2,2,2,0,3,3,3,3,3,3,0,2,2,2,2},
	{2,2,2,2,2,2,2,2,0,3,3,3,3,3,3,0,2,2,2,2,2,2,2,2,2,2,2,2,0,3,3,3,3,3,3,0,2,2,2,2},
	{2,2,2,2,2,2,2,2,0,3,3,3,3,3,3,0,2,2,2,2,2,2,2,2,2,2,2,2,0,3,3,3,3,3,3,0,2,2,2,2},//7
	{2,2,2,2,2,2,2,2,0,3,3,0,0,0,0,0,2,2,2,2,2,2,2,2,2,2,2,2,0,3,3,0,0,0,0,0,2,2,2,2},

	{2,2,2,2,2,2,2,2,0,3,3,0,2,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,0,2,2,2,2,2,2,2,2},
	{2,2,2,2,2,2,2,2,0,3,3,0,2,2,2,2,0,3,3,3,3,3,3,3,3,3,3,3,3,3,3,0,2,2,2,2,2,2,2,2},
	{2,2,2,2,2,2,2,2,0,3,3,0,2,2,2,2,0,3,3,3,3,3,3,3,3,3,3,3,3,3,3,0,2,2,2,2,2,2,2,2},//8
	{2,2,2,2,2,2,2,2,0,0,0,0,2,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,2,2,2,2,2,2},

	{2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1,1,1,1},
	{2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1,1,1,1},
	{2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1,1,1,1},//9
	{2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1,1,1,1},

	{2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1,1,1,1,1,1,1,1},
	{2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1,1,1,1,1,1,1,1},
	{2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1,1,1,1,1,1,1,1},
	{2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1,1,1,1,1,1,1,1}//10
};

int num1Uno[121]={
	5,5,5,5,5,5,5,5,5,5,5,
	5,5,5,5,5,5,5,5,5,5,5,
	5,5,5,5,5,5,5,5,5,5,5,
	 5,5,5,5,5,5,5,5,5,5,5,
	 5,5,5,5,5,0,0,0,0,5,5,
	 5,5,5,5,5,0,0,0,0,5,5,
	 5,0,0,0,0,0,0,0,0,5,5,
	 5,0,0,0,0,0,0,0,0,5,5,
	 5,0,0,0,0,0,0,0,0,5,5,
	 5,5,5,5,5,0,0,0,0,5,5,
	 5,5,5,5,5,0,0,0,0,5,5
};

int num1Dos[121]={
	 5,5,5,5,5,0,0,0,0,5,5,
	 5,5,5,5,5,0,0,0,0,5,5,
	 5,5,5,5,5,0,0,0,0,5,5,
	 5,5,5,5,5,0,0,0,0,5,5,
	 5,5,5,5,5,0,0,0,0,5,5,
	 5,5,5,5,5,0,0,0,0,5,5,
	 5,5,5,5,5,5,5,5,5,5,5,
	 5,5,5,5,5,5,5,5,5,5,5,
	5,5,5,5,5,5,5,5,5,5,5,
	5,5,5,5,5,5,5,5,5,5,5,
	5,5,5,5,5,5,5,5,5,5,5
};


int num2Uno[121]={
	5,5,5,5,5,5,5,5,5,5,5,
	5,5,5,5,5,5,5,5,5,5,5,
	5,5,5,5,5,5,5,5,5,5,5,
	5,5,5,5,5,5,5,5,5,5,5,
	5,0,0,0,0,0,0,0,0,5,5,
	5,0,0,0,0,0,0,0,0,5,5,
	5,0,0,0,0,0,0,0,0,5,5,
	5,5,5,5,5,0,0,0,0,5,5,
	5,5,5,5,5,0,0,0,0,5,5,
	5,0,0,0,0,0,0,0,0,5,5,
	5,0,0,0,0,0,0,0,0,5,5
};


int num2Dos[121]={
	
	5,0,0,0,0,0,0,0,0,5,5,
	5,0,0,0,5,5,5,5,5,5,5,
	5,0,0,0,5,5,5,5,5,5,5,
	5,0,0,0,0,0,0,0,0,5,5,
	5,0,0,0,0,0,0,0,0,5,5,
	5,0,0,0,0,0,0,0,0,5,5,
	5,5,5,5,5,5,5,5,5,5,5,
	5,5,5,5,5,5,5,5,5,5,5,
	5,5,5,5,5,5,5,5,5,5,5,
	5,5,5,5,5,5,5,5,5,5,5,
	5,5,5,5,5,5,5,5,5,5,5,
};

int num3Dos[121]={


	5,0,0,0,0,0,0,0,0,5,5,
	5,0,0,0,0,0,0,0,0,5,5,
	5,5,5,5,5,0,0,0,0,5,5,
	5,5,5,5,5,0,0,0,0,5,5,
	5,0,0,0,0,0,0,0,0,5,5,
	5,0,0,0,0,0,0,0,0,5,5,
	5,0,0,0,0,0,0,0,0,5,5,
	5,5,5,5,5,5,5,5,5,5,5,
	5,5,5,5,5,5,5,5,5,5,5,
	5,5,5,5,5,5,5,5,5,5,5,
	5,5,5,5,5,5,5,5,5,5,5,
};

int num5Uno[121]={
	5,5,5,5,5,5,5,5,5,5,5,
	5,5,5,5,5,5,5,5,5,5,5,
	5,5,5,5,5,5,5,5,5,5,5,
	5,5,5,5,5,5,5,5,5,5,5,
	5,5,5,5,5,5,5,5,5,5,5,
	5,0,0,0,0,0,0,0,0,5,5,
	5,0,0,0,0,0,0,0,0,5,5,
	5,0,0,0,0,0,0,0,0,5,5,
	5,0,0,0,5,5,5,5,5,5,5,
	5,0,0,0,5,5,5,5,5,5,5,
	5,0,0,0,0,0,0,0,0,5,5
};





int num4Dos[121]={
	5,0,0,0,0,0,0,0,0,5,5,
	5,5,5,5,5,0,0,0,0,5,5,
	5,5,5,5,5,0,0,0,0,5,5,
	5,5,5,5,5,0,0,0,0,5,5,
	5,5,5,5,5,0,0,0,0,5,5,
	5,5,5,5,5,0,0,0,0,5,5,
	5,5,5,5,5,5,5,5,5,5,5,
	5,5,5,5,5,5,5,5,5,5,5,
	5,5,5,5,5,5,5,5,5,5,5,
	5,5,5,5,5,5,5,5,5,5,5,
	5,5,5,5,5,5,5,5,5,5,5
};





int num6Dos[121]={
	5,0,0,0,0,0,0,0,0,5,5,
	5,0,0,5,5,5,5,0,0,5,5,
	5,0,0,5,5,5,5,0,0,5,5,
	5,0,0,0,0,0,0,0,0,5,5,
	5,0,0,0,0,0,0,0,0,5,5,
	5,0,0,0,0,0,0,0,0,5,5,
	5,5,5,5,5,5,5,5,5,5,5,
	5,5,5,5,5,5,5,5,5,5,5,
	5,5,5,5,5,5,5,5,5,5,5,
	5,5,5,5,5,5,5,5,5,5,5,
	5,5,5,5,5,5,5,5,5,5,5


};

int num7Uno[121]={
	5,5,5,5,5,5,5,5,5,5,5,
	5,5,5,5,5,5,5,5,5,5,5,
	5,5,5,5,5,5,5,5,5,5,5,
	5,5,5,5,5,5,5,5,5,5,5,
	5,5,5,5,5,5,5,5,5,5,5,
	5,0,0,0,0,0,0,0,0,5,5,
	5,0,0,0,0,0,0,0,0,5,5,
	5,0,0,0,0,0,0,0,0,5,5,
	5,5,5,5,5,5,0,0,0,5,5,
	5,5,5,5,5,5,0,0,0,5,5,
	5,5,5,5,5,5,0,0,0,5,5
};



int num8Uno[121]={
	5,5,5,5,5,5,5,5,5,5,5,
	5,5,5,5,5,5,5,5,5,5,5,
	5,5,5,5,5,5,5,5,5,5,5,
	5,5,5,5,5,5,5,5,5,5,5,
	5,5,5,5,5,5,5,5,5,5,5,
	5,0,0,0,0,0,0,0,0,5,5,
	5,0,0,0,0,0,0,0,0,5,5,
	5,0,0,0,0,0,0,0,0,5,5,
	5,0,0,5,5,5,5,0,0,5,5,
	5,0,0,5,5,5,5,0,0,5,5,
	5,0,0,0,0,0,0,0,0,5,5,
	

};

int num0Uno[121]={
	5,5,5,5,5,5,5,5,5,5,5,
	5,5,5,5,5,5,5,5,5,5,5,
	5,5,5,5,5,5,5,5,5,5,5,
	5,5,5,5,5,5,5,5,5,5,5,
	5,5,5,5,5,5,5,5,5,5,5,
	5,0,0,0,0,0,0,0,0,5,5,
	5,0,0,0,0,0,0,0,0,5,5,
	5,0,0,0,0,0,0,0,0,5,5,
	5,0,0,5,5,5,0,0,0,5,5,
	5,0,0,5,5,5,0,0,0,5,5,
	5,0,0,5,5,5,0,0,0,5,5

};


int num0Dos[121]={


	5,0,0,5,5,5,0,0,0,5,5,
	5,0,0,5,5,5,0,0,0,5,5,
	5,0,0,5,5,5,0,0,0,5,5,
	5,0,0,0,0,0,0,0,0,5,5,
	5,0,0,0,0,0,0,0,0,5,5,
	5,0,0,0,0,0,0,0,0,5,5,
	5,5,5,5,5,5,5,5,5,5,5,
	5,5,5,5,5,5,5,5,5,5,5,
	5,5,5,5,5,5,5,5,5,5,5,
	5,5,5,5,5,5,5,5,5,5,5,
	5,5,5,5,5,5,5,5,5,5,5,
};

int num4Uno[121]={
	
	5,5,5,5,5,5,5,5,5,5,5,
	5,5,5,5,5,5,5,5,5,5,5,
	5,5,5,5,5,5,5,5,5,5,5,
	5,5,5,5,5,5,5,5,5,5,5,
	5,5,5,5,5,5,5,5,5,5,5,
	5,0,0,5,5,5,0,0,0,5,5,
	5,0,0,5,5,5,0,0,0,5,5,
	5,0,0,5,5,5,0,0,0,5,5,
	5,0,0,0,0,0,0,0,0,5,5,
	5,0,0,0,0,0,0,0,0,5,5,
	5,0,0,0,0,0,0,0,0,5,5,
};


 void lcd_write(unsigned char rs, unsigned int data)
{
	rs_out_write(rs);
	lcd_mosi_data_write(data<<16);
	lcd_start_write(1);
	while(lcd_active_read()){}

}

void busy_wait(unsigned int ds)
{
	timer0_en_write(0);
	timer0_reload_write(0);
	timer0_load_write(SYSTEM_CLOCK_FREQUENCY/10*ds);
	timer0_en_write(1);
	timer0_update_value_write(1);
	while(timer0_value_read()) timer0_update_value_write(1);
}


void lcd_initialize(void){

	// INICIALIZANDO
	lcd_write(0,0x0010); //Start Byte Direccion
	lcd_write(1,0x0000);//Direccion
	lcd_write(0,0x0011); //Start Byte Direccion
	lcd_write(1,0x0000);//Direccion


	//Power Control 3
	lcd_write(0,0x0012);
	lcd_write(1,0x0000);

	//Power Control 4
	lcd_write(0,0x0013);
	lcd_write(1,0x0000);


	//Power Control 5
	lcd_write(0,0x0014);
	lcd_write(1,0x0000);
	busy_wait(0.4);
	
	//Power-on
	//Power Control 2
	lcd_write(0,0x0011);
	lcd_write(1,0x0018);

	//Power Control 3
	lcd_write(0,0x0012);
	lcd_write(1,0x6121);

	//Power Control 4
	lcd_write(0,0x0013);
	lcd_write(1,0x006F);
	//Power Control 5
	lcd_write(0,0x0014);
	lcd_write(1,0x495F);

	//Power Control 1 
	lcd_write(0,0x0010);
	lcd_write(1,0x0800);


	busy_wait(0.1);

	//Power Control 2
	lcd_write(0,0x0011);
	lcd_write(1,0x103B);


	busy_wait(0.5);

	//Driver Output control
	lcd_write(0,0x0001);
	lcd_write(1,0x011C);


	//LCD AC Driving control
	lcd_write(0,0x0002);
	lcd_write(1,0x0100);


	//Entry Mode
	lcd_write(0,0x0003);
	lcd_write(1,0x1038);


	//Disp control
	lcd_write(0,0x0007);
	lcd_write(1,0x0000);


	//Blank Period Control1
	lcd_write(0,0x0008);
	lcd_write(1,0x0808);

	//Frame Cycle Control
	lcd_write(0,0x000B);
	lcd_write(1,0x1100);


	//Interface control
	lcd_write(0,0x000C);
	lcd_write(1,0x0000);


	//Osc Control
	lcd_write(0,0x000F);
	lcd_write(1,0x0D01);


	//VCI Recycling
	lcd_write(0,0x0015);
	lcd_write(1,0x0020);


	//Ram Addr 1
	lcd_write(0,0x0020);
	lcd_write(1,0x0000);


	//Ram Addr 2
	lcd_write(0,0x0021);
	lcd_write(1,0x0000);



///sET GRAM AREA
	lcd_write(0,0x0030);
	lcd_write(1,0x0000);


	lcd_write(0,0x0031); //Start Byte Direccion
	lcd_write(1,0x00DB);//Start Byte Power Control 1


	lcd_write(0,0x0032); //Start Byte Direccion
	lcd_write(1,0x0000);//Start Byte Power Control 1

	lcd_write(0,0x0033); //Start Byte Direccion
	lcd_write(1,0x0000);//Start Byte Power Control 1


	lcd_write(0,0x0034); //Start Byte Direccion
	lcd_write(1,0x00DB);//Start Byte Power Control 1


	lcd_write(0,0x0035); //Start Byte Direccion
	lcd_write(1,0x0000);//Start Byte Power Control 1

// Horizontal address position

	//END
	lcd_write(0,0x0036); 
	lcd_write(1,0x0084);
	
	//START
	lcd_write(0,0x0037); 
	lcd_write(1,0x002C);
//Vertical address position
	//END
	lcd_write(0,0x0038); 
	lcd_write(1,0x00A5);
	//START
	lcd_write(0,0x0039);
	lcd_write(1,0x0037);

//// SET GAMMA CURVE

	lcd_write(0,0x0050); //Start Byte Direccion
	lcd_write(1,0x0000);//Start Byte Power Control 1

	lcd_write(0,0x0051); //Start Byte Direccion
	lcd_write(1,0x0808);//Start Byte Power Control 1

	lcd_write(0,0x0052); //Start Byte Direccion
	lcd_write(1,0x080A);//Start Byte Power Control 1

	lcd_write(0,0x0053); //Start Byte Direccion
	lcd_write(1,0x000A);//Start Byte Power Control 1

	lcd_write(0,0x0054); //Start Byte Direccion
	lcd_write(1,0x0A08);//Start Byte Power Control 1

	lcd_write(0,0x0055); //Start Byte Direccion
	lcd_write(1,0x0808);//Start Byte Power Control 1


	lcd_write(0,0x0056); //Start Byte Direccion
	lcd_write(1,0x0000);//Start Byte Power Control 1

	lcd_write(0,0x0057); //Start Byte Direccion
	lcd_write(1,0x0A00);//Start Byte Power Control 1

	lcd_write(0,0x0058); //Start Byte Direccion
	lcd_write(1,0x0710);//Start Byte Power Control 1

	lcd_write(0,0x0059); //Start Byte Direccion
	lcd_write(1,0x0710);//Start Byte Power Control 1



///DISP_CTRL1
	lcd_write(0,0x0007); //Start Byte Direccion
	lcd_write(1,0x0012);//Start Byte Power Control 1
	
	busy_wait(0.5);

	lcd_write(0,0x0007); //Start Byte Direccion
	lcd_write(1,0x1017);//Start Byte Power Control 1

///ENTRY MODE

	lcd_write(0,0x0003); //Start Byte Direccion
	lcd_write(1,0x1038);//Start Byte Power Control 1

/// HORIZONTAL_WINDOW_ADDR1
	lcd_write(0,0x0036); //Start Byte Direccion
	lcd_write(1,0x00AF);//Start Byte Power Control 1

/// HORIZONTAL_WINDOW_ADDR2
	lcd_write(0,0x0037); //Start Byte Direccion
	lcd_write(1,0x0000);//Start Byte Power Control 1
/// VERTICAL_WINDOW_ADDR1
	lcd_write(0,0x0038); //Start Byte Direccion
	lcd_write(1,0x00DB);//Start Byte Power Control 1
/// VERTICAL_WINDOW_ADDR1
	lcd_write(0,0x0039); //Start Byte Direccion
	lcd_write(1,0x0000);//Start Byte Power Control 1
/// RAM_ADDR_SET1
	lcd_write(0,0x0020); //Start Byte Direccion
	lcd_write(1,0x0000);//Start Byte Power Control 1
/// RAM_ADDR_SET2
	lcd_write(0,0x0021); //Start Byte Direccion
	lcd_write(1,0x0000);//Start Byte Power Control 1

//WRITE DATA TO GRAM
	/// HORIZONTAL_WINDOW_ADDR1
	lcd_write(0,0x0022); //Start Byte Direccion

}

	int yMin= 58;
	int yMax= 68;
	int xMin= 50;
	int xMax= 100;

	


void screen(int yMin, int yMax, int xMin, int xMax, int a){
	
	for(int i=yMin; i< yMax; i++)
	{
		lcd_write(0,0x0020);
		lcd_write(1, i)	;
		for (int j = xMin; j < xMax; j++)
		{
			lcd_write(0,0x0021);
			lcd_write(1,j);
			lcd_write(0,0x0022);
			lcd_write(1,a);
		}
	}
}


