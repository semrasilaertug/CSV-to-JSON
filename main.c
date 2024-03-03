#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <locale.h>

int main(int argc, char** argv)
{
	setlocale(LC_ALL, "Turkish");
	
	FILE *dosya_csv, *dosya_json;
    char* okunacak_csv = argv[1];
    char* olusturulacak_json = argv[2];
    char* header = argv[3];
    

	if(argc != 4){
		printf("Programýn çalýþmasý için 4 argüman girilmeli!");
		return 0;
	}
	
	if( strcmp(header,"off") != 0 && strcmp(header,"OFF") != 0 )
	{
		printf("Programýn çalýþmasý için header off veya OFF olmalýdýr.");
		return 0;
	}
	
	
    dosya_csv = fopen(okunacak_csv, "r");
    
    if (dosya_csv == NULL)
    {
        printf("Dosya Okunamadý.");
        return 0;
    }
    
    else
    {
	
    dosya_json = fopen(olusturulacak_json,"w");


    char satir[600];
    char kes[] = ",\n";
    int	 sayacKolon;
	char *ptr;

	fprintf(dosya_json, "[\n");

	    while (fgets(satir, sizeof(satir), dosya_csv) != NULL)
	    {
	        fprintf(dosya_json, "\t{\n");
	        ptr = strtok(satir, kes);

			
				for(sayacKolon=1 ; ptr!=NULL ; sayacKolon++)
			   {

					fprintf(dosya_json," \t\t\"Kolon%d\":\t\"%s\",\n",sayacKolon,ptr);
				
				    ptr = strtok(NULL, kes);
				}

	        fprintf(dosya_json, "\n\t},\n");		

	    }

	fprintf(dosya_json, "\n]");

    fclose(dosya_csv);
    fclose(dosya_json);

    printf("Ýstenilen dosya baþarýyla oluþturuldu.");

    return 0;
    
	}
	
	return 0;

}


