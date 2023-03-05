#include "chiffrement.h"
#include "definitions.h"


int CLE = CLE_DEFAUT;

void crypto_initialiser_cle(int cle)
{
    CLE = cle;
}

void crypto_chiffrer()
{
    printf("+++++++++++++++++++++++chiffrement\n");
    ouvrir_fichier();

    CLE = 5;

     char LIGNE[50];
    while (fgets(LIGNE, sizeof(LIGNE), CLIENTS))
    {
       // printf("%s\n", LIGNE); // print the encrypted line


/*
        if (LIGNE[strlen(LIGNE)-1] == '\n') {
            LIGNE[strlen(LIGNE)-1] = '\0'; // replace newline with null character
        }
        */
        /*
        if (strlen(LIGNE) <= 1 || isspace(LIGNE[0])) {
            continue;
        }*/
        for(int i=0;i<strlen(LIGNE);i++)
        {
            // encryption code here
/*
            if (strlen(LIGNE) == 1 || isspace(LIGNE[0]))
            {
                continue;
            }*/

            if (!isalpha(LIGNE[i]))
                if (!isalpha(LIGNE[i]))
                LIGNE[i] = ((LIGNE[i] - '0' )+ CLE) % 10 + '0';

            if(isupper(LIGNE[i]))
                LIGNE[i]=((LIGNE[i]-'A') + CLE) % 26 + 'A';
            else

                if(islower(LIGNE[i]))
                    LIGNE[i]=((LIGNE[i]-'a') + CLE) % 26 + 'a';
        }
        printf("%s", LIGNE);
    }
    printf("\n");
    //recreer_fichier();
    fermer_fichier();
}

void crypto_dechiffrer(CH50 chaine)
{
printf("+++++++++++++++++++++++dechiffrement\n");
    ouvrir_fichier();

    CLE = 5;

     char LIGNE[50];
    while (fgets(LIGNE, sizeof(LIGNE), CLIENTS))
    {
       // printf("%s\n", LIGNE); // print the encrypted line


/*
        if (LIGNE[strlen(LIGNE)-1] == '\n') {
            LIGNE[strlen(LIGNE)-1] = '\0'; // replace newline with null character
        }
        */
        /*
        if (strlen(LIGNE) <= 1 || isspace(LIGNE[0])) {
            continue;
        }*/
        for(int i=0;i<strlen(LIGNE);i++)
        {
            // encryption code here
/*
            if (strlen(LIGNE) == 1 || isspace(LIGNE[0]))
            {
                continue;
            }*/

            if (!isalpha(LIGNE[i]))
                if (!isalpha(LIGNE[i]))
                LIGNE[i] = ((LIGNE[i] - '0' )- CLE) % 10 + '0';

            if(isupper(LIGNE[i]))
                LIGNE[i]=((LIGNE[i]-'A') - CLE) % 26 + 'A';
            else

                if(islower(LIGNE[i]))
                    LIGNE[i]=((LIGNE[i]-'a') - CLE) % 26 + 'a';
        }
        printf("%s", LIGNE);
    }
    printf("\n");
    //recreer_fichier();
    fermer_fichier();
}


