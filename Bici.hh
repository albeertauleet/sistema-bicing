/** @file Bici.hh
    @brief Especificació de la classe Bici.hh
*/

#ifndef BICI_HH 
#define BICI_HH

#ifndef NO_DIAGRAM
#include <list>
#include <iostream>
using namespace std;

#endif

/** @class Bici
    @brief Representa una bici
    
    La bici conté informació sobre el seu identificador, a on està estacionada i les seves operacions corresponents operacions

*/

class Bici {
    private:
        string id_bici;
        string id_estacionada;
        list<pair<string,string>> viatge;

    public:
        // Constructores

        /** @brief Creadora per defecte
            \pre <em>Cert</em>.
            \post Crea una bici sense inicialitzar
        */
        Bici();

        /** @brief Creadora amb variables
            \pre <em>Cert</em>.
            \post Crea una bici inicialitzada
        */
        Bici(string id_bici, string id_estacio);

        // Modificadores


        /** @brief Modifica l'estació on està la bici amb identificador id_bici
            \pre Existeix la bici amb identificador id_bici
            \post S'ha canviat l'estació on està guardada la bici amb identificador id_bici
        */
        void canviar_estacio(string id_estacio);


        /** @brief Transporta la bici de l'estació on està aparcada a l'estació destí
            \pre La bici existeix i no està aparcada a l'estació destí, la qual existeix i no està plena
            \post Transporta la bici a l'estació destí, afegint-li un viatge als viatges fets i sent l'estació destí l'estació on està aparcada
        */
        void viatjar_estacio(string id_estacio);


        // Consultores

        /** @brief Escriu els viatges que ha realitzar la  bici 
            \pre <em>Cert</em>.
            \post Escriu els viatges que ha realitzar la bici passada com a paràmetre implícit
        */
        void viatges_bici() const;

        /** @brief Ens retorna el identificador de la bici passada com a p.i
            \pre Existeix la bici 
            \post Ens retorna el seu identificador
        */
        string consulta_id_bici() const;
        

        /** @brief Ens retorna el identificador de l'estació on està.
            \pre Existeix la bici 
            \post Ens retorna l'identificador de l'estació
        */
        string consulta_estacio_bici() const;
};

#endif
