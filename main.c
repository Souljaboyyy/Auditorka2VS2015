#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<stdio.h>
#include<malloc.h>


struct person {
	int age;
	char name[50];
} ;

int main() {
	printf("Choose the number of exercise 1 or 2\n");
	int u;
	scanf_s("%d", &u);
	if (u == 1) {
		struct person *mass;
		int a, i, max, num = 0;
		char* y;
		FILE *fp;
		fopen_s(&fp, "persons.txt", "r");
		fscanf_s(fp, "%d", &a);
		mass = (struct person*)malloc(a * sizeof(struct person));
		for (i = 0; i < a; i++) {
			fscanf_s(fp, "%d", &(mass + i)->age);
			fgets((mass + i)->name, 50, fp);
			printf("%d ", (mass + i)->age);
			printf("%s", (mass + i)->name);
		}
		max = mass->age;
		for (i = 0; i < a; i++)
			if ((mass + i)->age >= max) {
				max = (mass + i)->age;
				num = i;
			}
		printf("\nSamiy stariy is %s emy %d\n let", (mass + num)->name, (mass + num)->age);
		free(mass);
	}
	else
	{
		char c1 = 's', c2 = 'a',t;
		int kv=0;
		int flag = 0;
		FILE *out;
		fopen_s(&out, "zadanie2.txt", "w");
		printf("press xx or zz to calculate\n");
		while ((c2 != 'x') && (c1 != 'z'))
		{
			c2 = getche();
			c1 = getche();
			fprintf(out,"%c%c", c2, c1);
		}
		fclose(out);
		fopen_s(&out, "zadanie2.txt", "r");
		printf("\n");
		while (!feof(out)) {

			t = fgetc(out);
			while (((int)t > 47) && ((int)t < 58)) {
					kv = kv*10+(int)t - 48;
					t = fgetc(out);
					flag++;
			}
			if (flag != 0)
				printf("%d ", kv*kv);
			kv = 0;
			flag = 0;
		}
		
		fclose(out);
		remove("zadanie2.txt");
		
		system("pause");
		return 0;
		


		
	}


	
	system("pause");
	return 0;
}