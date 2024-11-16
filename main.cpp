#include <cstring>
#include <iostream>
using namespace std;

struct typeSTR_Canzone
{
    char c_TitoloCanzone[64];                               // Campo che contiene il valore informativo dell'elemento
    typeSTR_Canzone* STR_p_PuntatoreProssimoElemento;   // Puntatore al prossimo elemento nella lista
};

void FX_void_StampaPlaylist (typeSTR_Canzone* STR_p_Testa)
{
    while(STR_p_Testa->STR_p_PuntatoreProssimoElemento != nullptr) {
        cout << STR_p_Testa->c_TitoloCanzone << endl;
        STR_p_Testa = STR_p_Testa->STR_p_PuntatoreProssimoElemento;
    }
}

bool FX_bool_AggiungiCanzone (typeSTR_Canzone*& STR_p_Testa,const char* arr_const_c_p_TitoloAlbum)
{
    if(strlen(arr_const_c_p_TitoloAlbum) > 63)
        return false;

    typeSTR_Canzone* STR_p_Coda = STR_p_Testa;

    while(STR_p_Coda->STR_p_PuntatoreProssimoElemento != nullptr) {
        if(strcmp(arr_const_c_p_TitoloAlbum, STR_p_Coda->c_TitoloCanzone) == 0)
            return false;
        STR_p_Coda = STR_p_Coda->STR_p_PuntatoreProssimoElemento;
    }

    STR_p_Coda = STR_p_Testa;
    STR_p_Testa = new typeSTR_Canzone;
    strcpy(STR_p_Testa->STR_p_PuntatoreProssimoElemento, arr_const_c_p_TitoloAlbum);
    STR_p_Testa->STR_p_PuntatoreProssimoElemento = STR_p_Coda;
    return true;
}


int main()
{
    typeSTR_Canzone* STR_p_Canzone;
    STR_p_Canzone = nullptr;

    FX_void_StampaPlaylist(STR_p_Canzone);

    FX_bool_AggiungiCanzone(STR_p_Canzone, "Waiting For Love (Avicii)");
    FX_bool_AggiungiCanzone(STR_p_Canzone, "Wake me up (Avicii)");
    FX_bool_AggiungiCanzone(STR_p_Canzone, "Frio (Lazza)");
    FX_bool_AggiungiCanzone(STR_p_Canzone, "Waiting For Love (Avicii)");

    FX_void_StampaPlaylist(STR_p_Canzone);

    return 0;
}
