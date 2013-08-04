#include <stdio.h>
#include <string.h>
#include <map>
#include <string>

using namespace std;

int main()
{
	FILE *fin, *fout;
	map<string, double> unit;
	char str[85], tar_unit[20], sou_unit[20], tmp[20];
	char dict[10][20] = {"miles", "yards", "inches", "feet", "faths", "furlongs", "meters"};
	double tar, sou, sum, ops;
	int i, k, op;

	fin = fopen("input.txt", "r");
	fout = fopen("output.txt", "w");

	fprintf(fout, "nationalpower@qq.com\n\n");

	i = 0;
	while (fgets(str, 80, fin)) {
		//printf("length: %d\n", strlen(str));
		if (strlen(str) == 1)
			break;
		sscanf(str, "%lf %s %s %lf %s", &tar, tar_unit, tmp, &sou, sou_unit);
		//printf("%lf %s %s %lf %s\n", tar, tar_unit, tmp, sou, sou_unit);
		unit[tar_unit] = sou;
		unit[dict[i]] = sou;
		//printf("dict[i]: %s, unit[dict[i]]: %lf\n", dict[i], unit[dict[i]]);
		i++;
	}
	unit[sou_unit] = 1;
	unit[dict[i]] = 1;

	while (fgets(str, 80, fin)) {
		if (strlen(str) != 1) {
			sum = 0;
			k = 0;
			op = 1;
			for (i = 0; i < strlen(str); i++) {
				//printf("str[%d]: %c\n", i, str[i]);
				if (str[i] != ' ' && str[i] != '\n') {
					tmp[k] = str[i];
					k++;
				} else {
					tmp[k] = '\0';
					k = 0;
					if (tmp[0] >= '0' && tmp[0] <= '9') {
						sscanf(tmp, "%lf", &ops);
						//printf("number: %lf\n", ops);
					} else if (tmp[0] == '+') {
						op = 1;
					} else if (tmp[0] == '-') {
						op = -1;
					} else {
						//printf("tmp: %s, %lf\n", tmp, unit[tmp]);
						sum += ops * op * unit[tmp];
					}
				}
			}
			//printf("%.2lf m\n", sum);
			fprintf(fout, "%.2lf m\n", sum);
		}
	}

	fclose(fin);
	fclose(fout);
	return 0;
}
