#include <stdio.h>
#include <stdlib.h>


int main()
{
	float height_back_wall = 0;  //высота
	int width_back_wall = 0;    //ширина(ввод)
	float dvp_wall_thickness = 0.5;//толщина двп
	float depth_sidewall = 0;//глубина(ввод)
	float thickness_sidewall = 1.5;//толщина дсп
	float door_thickness = 1;//толщина дерева
	float density_dsp = 0.8;//г/см^3 плотность дсп
	float density_dvp = 0.82;//г/см ^3 плотность двп
	float density_wood = 0.52;//г/см^3 плотность дерева(сосна)
	float weight_covers = 0;// масса нижних и верхних планок.дсп
	float weight_sidewall = 0;//масса боковых стенок.
	                          //из высоты вычитается ширина верхней
	                          //и нижней планок.дсп
	float weight_back_wall = 0;//масса задней планки.
	                           //1.5см - это нижняя планка, 
	                           //она автоматом должна плюсоваться. двп
	float m4 = 0;//дсп. масса полок умноженная на их кол-во.
	int count_shelves = 0;//кол-во полок.
	                      //из полученного кол-ва убирается верхняя планка.
	int distance_between_shalves = 40;//расстояние между полками
	float weight_door = 0;//дерево. масса дверей, c учетом,
	                      //что они не везутся по полу во время открывания,
	                      //т.е. их высота равна высота минус
	                      //ширина нижней планки. удвоенная.
	float weight_closet = 0;//финальный вес шкафа.

	printf("You are welcomed by Skilful Hands. Create your closet as you see fit.\n"
		"Enter the desired width(80-120 cm) and depth(50-90 cm) of your closet\n"
		"so that we can calculate its weight. Ask why?\n"
		"Of course, so you know how many movers to call for pickup.\n");
	printf("width, depth\n");
	scanf("%d%d", &width_back_wall, &depth_sidewall);
	if (((width_back_wall >= 80) && (width_back_wall <= 120)) &&
	   ((depth_sidewall >= 50) && (depth_sidewall <= 90)))
	{
		height_back_wall = height_back_wall + thickness_sidewall;
		do
		{
			height_back_wall = height_back_wall + thickness_sidewall + distance_between_shalves;
			count_shelves  = count_shelves  + 1;
		} while (height_back_wall <= 220 - 40); 
		count_shelves  = count_shelves  - 1;
		weight_covers = width_back_wall * depth_sidewall * thickness_sidewall * 2 * density_dsp;
		weight_sidewall = (height_back_wall - thickness_sidewall - thickness_sidewall) * depth_sidewall * thickness_sidewall * density_dsp * 2;
		weight_back_wall = height_back_wall * width_back_wall * dvp_wall_thickness * density_dvp;
		m4 = density_dsp * (width_back_wall - thickness_sidewall - thickness_sidewall) * depth_sidewall * count_shelves * thickness_sidewall; 
		weight_door = density_wood * (height_back_wall - thickness_sidewall) * width_back_wall * door_thickness;
		weight_closet = (weight_covers + weight_sidewall + weight_back_wall + m4 + weight_door) / 1000;
		printf("\n %f kg\n", weight_closet);
	}
	else
	{
		if (width_back_wall > 120 || width_back_wall < 80) printf("width entered incorrectly\n"); 
	    if (depth_sidewall < 50 || depth_sidewall > 90) printf("depth entered incorrectly\n");
	}
	system("pause");
	return 0;
}