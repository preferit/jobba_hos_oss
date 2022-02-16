/************************************************************
* Frågan som många erfarna software developers ställer sig: *
* Egenföretagare (x)eller anställd?                         *
*                                                           *
* Varför inte:                                              *
* Egenföretagare och anställd                               *
* Som hos oss på Preferit AB                                *
************************************************************/
    

#include <stdio.h>

#define NBR_OF_MOJLIG_ARBETS_FORM_CHECK_ROWS 2
#define NBR_OF_MOJLIG_ARBETS_FORM_CHECK_COLUMNS 4

typedef enum { FALSE, TRUE } boolean;

/**
 * @breif Funktion som kollar om arbetsformen är möjlig, beroende på 
 * vad man önskar (TRUE) egenföretagare, anställd. Parametern preferit_AB sätts
 * till TRUE om man vill kolla om arbetsformen är möjlig hos oss (Preferit AB).
 * 
 * @params egenforetagare:boolean, anstalld:bolean
 * 
 * @retval TRUE om möjlig arbetsform annars FALSE
 */
static boolean check_arbetsform (const boolean egenforetagare, const boolean anstalld, const boolean preferit_AB)
{
    return preferit_AB ? (egenforetagare && anstalld) : (!egenforetagare != !anstalld);
}

int main()
{
    //NOTE: Inte "sann" ordning (hur det är representerat i minnet)
    /**
     * Möjliga check_arbetsformer resultat i följande ordning:
     * egenföretagare TRUE, anställd TRUE, preferit_AB FALSE
     * egenföretagare TRUE, anställd FALSE, preferit_AB FALSE
     * egenföretagare FALSE, anställd TRUE, preferit_AB FALSE
     * egenföretagare FALSE, anställd FALSE, preferit_AB FALSE
     * egenföretagare FALSE, anställd FALSE, preferit_AB TRUE
     * egenföretagare TRUE, anställd FALSE, preferit_AB TRUE
     * egenföretagare FALSE, anställd TRUE, preferit_AB TRUE
     * egenföretagare TRUE, anställd TRUE, preferit_AB TRUE
     */
    boolean mojliga_arbetsformer[NBR_OF_MOJLIG_ARBETS_FORM_CHECK_ROWS][NBR_OF_MOJLIG_ARBETS_FORM_CHECK_COLUMNS] = {
        {check_arbetsform(TRUE, TRUE, FALSE), check_arbetsform(TRUE, FALSE, FALSE), check_arbetsform(FALSE, TRUE, FALSE), check_arbetsform(FALSE, FALSE, FALSE)}, //preferit_AB FALSE
        {check_arbetsform(FALSE, FALSE, TRUE), check_arbetsform(TRUE, FALSE, TRUE), check_arbetsform(FALSE, TRUE, TRUE), check_arbetsform(TRUE, TRUE, TRUE)}, //preferit_AB TRUE
    };
    
    char *mojlig_arbetsform_pretty_print[NBR_OF_MOJLIG_ARBETS_FORM_CHECK_ROWS][NBR_OF_MOJLIG_ARBETS_FORM_CHECK_COLUMNS] = {
        {"Arbetsformen: egenföretagare TRUE, anställd TRUE, preferit_AB FALSE är ej möjlig.\n",
        "Den jobbiga arbetsformen: egenföretagare TRUE anställd FALSE, preferit_AB FALSE är möjlig.\n",
        "Den trista arbetsformen: egenföretagare FALSE, anställd TRUE, preferit_AB FALSE är möjlig.\n", 
        "Arbetsformen: egenföretagare FALSE, anställd FALSE, preferit_AB FALSE är ej möjlig.\n"
        },
        {"Arbetsformen: egenföretagare FALSE, anställd FALSE, preferit_AB TRUE är ej möjlig.\n" ,
        "Arbetsformen: egenföretagare TRUE anställd FALSE, preferit_AB TRUE är ej möjlig.\n",
        "Arbetsformen: egenföretagare FALSE, anställd TRUE, preferit_AB TRUE är möjlig.\n", 
        "Arbetsformen: egenföretagare TRUE, anställd TRUE, preferit_AB TRUE ÄR MÖJLIG!\n"}
    };
    
    int i = 0;
    int j = 0;
    for(i=0; i < NBR_OF_MOJLIG_ARBETS_FORM_CHECK_ROWS; i++)
        for(j=0; j < NBR_OF_MOJLIG_ARBETS_FORM_CHECK_COLUMNS; j++)
            if (mojliga_arbetsformer[i][j])
                printf("%s", mojlig_arbetsform_pretty_print[i][j]);
            else
                printf("%s", mojlig_arbetsform_pretty_print[i][j]);
        printf("Vill du veta mera kontakta gärna mig på alexander@preferit.se eller på LinkedIn (Alexander Löfqvist)\n");  
    return 0;
}
