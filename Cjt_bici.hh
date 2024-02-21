/** @file Cjt_bici.hh
    @brief Especificació de la classe Cjt_bici.hh
*/

#ifndef CJT_BICI_HH
#define CJT_BICI_HH

#include "Bici.hh"
#ifndef NO_DIAGRAM
#include <map>

#endif

/** @class Cjt_bici
    @brief Representa el conjunt de bicis al sistema de Bicing
*/

class Cjt_bici {
    private: 

        map<string, Bici> cjt_bici;

    public:

        // Constructores

        /** @brief Creadora per defecte
            \pre <em>Cert</em>.
            \post S'ha creat un conjunt de bicis buit.
        */
        Cjt_bici();


        // Modificadores

        /** @brief Afegeix una bici al conjunt
            \pre No existeix la bici al conjunt i l'estació existeix al sistema bicing
            \post S'ha afegit la bici al conjunt
        */
        void afegir_bici(const string& id_bici, const Bici& bici);
        
        /***/
        //void modificar_bici(const string& id_bici, const Bici& bici);


        /** @brief Elimina una bici del registre de bicis totals
            \pre Existeix una bici amb identificador id_bici
            \post S'ha eliminat la bici amb identificador id_bici del registre de bicis totals
        */
        void eliminar_bici(const string& id_bici);


        // Consultores

        /** @brief Ens diu si la bici ja existeix al conjunt
            \pre <em>Cert</em>. 
            \post Ens retorna cert si la bici ja està al conjunt, fals altrament.
        */
        bool existeix_bici(const string& id_bici) const;


        /** @brief Retorna el identificador de la estació  el qual està emmagatzemada la bici amb identificar id_bici
            \pre Existeix una bici amb identificador id_bici
            \post Retorna el identificador de la estació la qual està emmagatzemada la bici
        */
        string on_esta(const string& id_bici) const;


        /** @brief Retorna la bici amb id_bici com identificador
            \pre Existeix un sistema bicing i una bici amb id_bici com identificador
            \post Retorna la bici amb id_bici com identificador
        */
        Bici consulta_bici(const string& id_bici) const;



};

#endif
