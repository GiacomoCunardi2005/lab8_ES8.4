#include <cstring>
#include <iostream>
using namespace std;

// Definizione della struttura per rappresentare una canzone nella playlist
struct typeSTR_Canzone
{
    char c_TitoloCanzone[64];                               // Campo che contiene il valore informativo dell'elemento
    typeSTR_Canzone* STR_p_PuntatoreProssimoElemento;   // Puntatore al prossimo elemento nella lista
};

// Funzione per stampare l'intera playlist
void FX_void_StampaPlaylist (const typeSTR_Canzone* const_STR_p_Testa)
{
    // Itera attraverso la lista finché il puntatore al prossimo elemento non è nullo
    while(const_STR_p_Testa->STR_p_PuntatoreProssimoElemento != nullptr) {
        cout << const_STR_p_Testa->c_TitoloCanzone << endl; // Stampa il titolo della canzone
        const_STR_p_Testa = const_STR_p_Testa->STR_p_PuntatoreProssimoElemento; // Passa al prossimo elemento
    }
}

// Funzione per aggiungere una canzone alla playlist
bool FX_bool_AggiungiCanzone (typeSTR_Canzone*& STR_p_Testa,const char* arr_const_c_p_TitoloAlbum)
{
    // Verifica se il titolo della canzone supera la lunghezza massima consentita
    if(strlen(arr_const_c_p_TitoloAlbum) > 63)
        return false; // Ritorna false se il titolo è troppo lungo

    // Imposta un puntatore temporaneo per scorrere la lista
    typeSTR_Canzone* STR_p_Coda = STR_p_Testa;

    // Controlla se il titolo della canzone è già presente nella lista
    while(STR_p_Coda->STR_p_PuntatoreProssimoElemento != nullptr) {
        if(strcmp(arr_const_c_p_TitoloAlbum, STR_p_Coda->c_TitoloCanzone) == 0)
            return false; // Ritorna false se la canzone è già nella lista
        STR_p_Coda = STR_p_Coda->STR_p_PuntatoreProssimoElemento; // Passa al prossimo elemento
    }

    // Reimposta STR_p_Coda alla testa della lista
    STR_p_Coda = STR_p_Testa;

    // Crea un nuovo nodo per la canzone
    STR_p_Testa = new typeSTR_Canzone; // Alloca memoria per il nuovo elemento

    // Qui si tenta di copiare il titolo nel nuovo nodo, ma c'è un errore logico
    strcpy(STR_p_Testa->STR_p_PuntatoreProssimoElemento, arr_const_c_p_TitoloAlbum); // annot convert 'typeSTR_Canzone*' to 'char*'
    STR_p_Testa->STR_p_PuntatoreProssimoElemento = STR_p_Coda; // Collega il nuovo nodo alla lista esistente

    return true; // Canzone aggiunta con successo
}

bool FX_bool_EliminaCanzone(typeSTR_Canzone*& STR_p_Testa,const char* arr_const_c_p_TitoloAlbum)
{
    typeSTR_Canzone* STR_p_Coda = STR_p_Testa;

    while(STR_p_Coda->STR_p_PuntatoreProssimoElemento != nullptr)
    {
        if(STR_p_Coda->c_TitoloCanzone == arr_const_c_p_TitoloAlbum)
        {
            STR_p_Coda->STR_p_PuntatoreProssimoElemento = nullptr;
            return true;
        }
        STR_p_Coda = STR_p_Coda->STR_p_PuntatoreProssimoElemento; // Passa al prossimo elemento
    }
    return false;
}

bool FX_bool_CercaCanzone(typeSTR_Canzone*& STR_p_Testa,const char* arr_const_c_p_TitoloAlbum) {
    typeSTR_Canzone* STR_p_Coda = STR_p_Testa;

    while(STR_p_Coda->STR_p_PuntatoreProssimoElemento != nullptr)
    {
        if(STR_p_Coda->c_TitoloCanzone == arr_const_c_p_TitoloAlbum)
        {
            return true;
        }
        STR_p_Coda = STR_p_Coda->STR_p_PuntatoreProssimoElemento; // Passa al prossimo elemento
    }
    return false;
}

void FX_void_DeletePlaylist(const typeSTR_Canzone* const_STR_p_Testa)
{
    delete const_STR_p_Testa;
}

int main()
{
    // Dichiarazione del puntatore alla testa della playlist
    typeSTR_Canzone *STR_p_Canzone = nullptr; // Inizialmente la lista è vuota

    // Stampa la playlist inizialmente vuota
    FX_void_StampaPlaylist(STR_p_Canzone);

    // Tentativi di aggiungere canzoni alla playlist
    FX_bool_AggiungiCanzone(STR_p_Canzone, "Waiting For Love (Avicii)"); // Aggiunge la prima canzone
    FX_bool_AggiungiCanzone(STR_p_Canzone, "Wake me up (Avicii)"); // Aggiunge la seconda canzone
    FX_bool_AggiungiCanzone(STR_p_Canzone, "Frio (Lazza)"); // Aggiunge una terza canzone
    FX_bool_AggiungiCanzone(STR_p_Canzone, "Waiting For Love (Avicii)"); // Tentativo di aggiungere un duplicato

    // Stampa la playlist aggiornata
    FX_void_StampaPlaylist(STR_p_Canzone);

    FX_bool_EliminaCanzone(STR_p_Canzone, "Waiting For Love (Avicii)");
    FX_bool_EliminaCanzone(STR_p_Canzone, "Frio (Lazza)");

    FX_void_StampaPlaylist(STR_p_Canzone);

    cout << FX_bool_CercaCanzone(STR_p_Canzone, "Wake me up (Avicii)") << endl;
    cout << FX_bool_CercaCanzone(STR_p_Canzone, "Waiting For Love (Avicii)") << endl;

    FX_void_DeletePlaylist(STR_p_Canzone);
    FX_void_StampaPlaylist(STR_p_Canzone);

    return 0; // Termina il programma
}
