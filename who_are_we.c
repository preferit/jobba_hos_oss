#include <stdio.h>

#define UPPER_LIMIT (15)

int main()
{
    int nbr_of_current_employees = 10;
    
    printf("Hello there, här är en liten head count och namn på våra anställda :)\n\n");
    
    printf("Antal anställda: %d\n\n", nbr_of_current_employees);
    
    printf("Och vi är:\n");
    printf("Alexander\n");
    printf("BG\n");
    printf("Cleas\n");
    printf("David\n");
    printf("Gregory");
    printf("Petter\n");
    printf("Ingemar\n");
    printf("Jesper\n");
    printf("Martin\n");
    printf("Timo\n");
    printf("Ditt namn\n");
    printf("XX preferred\n");
    printf("XX preferred\n");
    printf("XX preferred\n");
    printf("XX preferred\n\n");
    printf("%d is our upper limit av antalet anställda.\n", UPPER_LIMIT);
    printf("Hade varit trevligt om du hade kunnat vara 1 av de %d som fattas :)\n", UPPER_LIMIT - nbr_of_current_employees);
    
    return 0;
}
