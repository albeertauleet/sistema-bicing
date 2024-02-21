/** @file Bicing.hh
    @brief Especificación de la clase Bicing
    
*/

#ifndef BICING_HH
#define BICING_HH

#include "Estacio.hh"
#include "Bici.hh"
#include "Cjt_bici.hh"
#ifndef NO_DIAGRAM
#include "BinTree.hh"

#endif

/** @class Bicing
    @brief Representa un sistema de Bicing

    El Bicing representa una estructura per organitzar les diferents estacions i les bicis que conté cada una     

*/

class Bicing {
    private: 
        BinTree<string> estruc_estacions;
        map<string, Estacio> info_estacions;
        int places_lliures_totals;

        /** @brief Funció auxiliar per llegir el sistema bicing amb les seves estacions
            \pre <em>Cert</em>.
            \post Ens retorna el sistema bicing amb les seves estacions i les seves capacitats respectives
        */
        BinTree<string> i_llegir();

        /** @brief Funció auxiliar per reestructurar les estacions i les bicis de cada una
            \pre El primer node no està buit
            \post Modifica les bicis de cada estació de forma que les apropa a la primera estació, de forma que s'intentarà omplir una estació amb bicis de les dues estacions següents de forma que quedin les dues amb un número més o menys equilibrat. Es farà de forma repetitiva amb totes les estacions

        */
        void i_reestructurar_estacions(const BinTree<string>& t, Cjt_bici& cjt_bici);

        /** @brief Calcula el coeficient de desocupació general de totes les estacions, i un cop ha recorregut tot el arbre, guardarà el id de l'estació amb el major coeficient a id_max
            \pre <em>Cert</em>.
            \post Calcula el coeficient de totes les estacions i guarda el id de l'estació amb el coeficient major a id_max
           */
        void i_calcula_major_coeficient(const BinTree<string>& aux, string& id_max, double& max, double& coeficient, int& num_est);

    

    public: 
        // Constructores

        /** @brief Creadora per defecte. S'executa automàticament al declarar un Bicing
            \pre <em>Cert</em>.
            \post S'ha creat un Bicing sense inicialitzar.
        */ 
        Bicing();

        // Modificadores

        /** @brief Es modifica el Bicing passat com p.i afegint les estacions corresponents
            \pre Existeix un sistema de Bicing.
            \post S'ha modificat el Bicing afegint-l'hi les estacions que volíem afegir
        */
        void llegir();




        /** @brief Afegeix una estació al conjunt
            \pre No existeix l'estació al conjunt
            \post S'ha afegit l'estació al conjunt
        */
        void afegir_estacio(const string& id_estacio, const Estacio& estacio);


        /** @brief Modifica una estació del conjunt
            \pre Existeix l'estació amb identificador id_estacio
            \post S'ha modificat l'estació amb l'id corresponent
        */
        void modifica_estacio(const string& id_estacio,const Estacio& estacio);

        
        /** @brief Inicialitzar les places lliures totals
            \pre <em>Cert</em>. 
            \post Inicialitza les places lliures totals del bicing a 0 per tal d'evitar possibles errors
        */
        void inicialitzar_places_lliures_totals();
        
        /** @brief Modifica les places lliures totals del sistema bicing
            \pre <em>Cert</em>.
            \post Modifica les places lliures totals afegint/restant n places lliures.
        */
        void modifica_places(int n);

        /** @brief Reestructura les estacions i les seves bicis de forma que apropi les bicis a la primera estació
            \pre <em>Cert</em>.
            \post Apropa bicis a la primera estació, de forma que s'intentarà omplir una estació amb bicis de les dues estacions següents de forma que quedin les dues amb un número més o menys equilibrat. Es farà de forma repetitiva amb totes les estacions
        */
        void reestructurar_estacions(Cjt_bici& cjt_bici);

        /** @brief Assigna una bici a l'estació més apropiada
            \pre La bici no existeix i una o més estacions tenen alguna plaça lliure
            \post La bici s'aparca a l'estació amb major coeficient de desocupació general
        */
        void assignar_estacio(const string& id_bici, Cjt_bici& cjt_bici);


        // Consultores


        /** @brief Consulta si una estació existeix al sistema Bicing
            \pre Existeix un sistema Bicing
            \post Retorna <em>cert</em> si la estació existeix, <em>fals</em> altrament
        */
        bool existeix_estacio(const string& id_estacio) const;

        /** @brief Ens diu el número total de places lliures
            \pre <em>Cert</em>.
            \post Ens diu el número total de places lliures entre totes les estacions
        */
        int places_lliures_total() const;


        /** @brief Retorna l'estació amb id_estació com identificador
            \pre Existeix un sistema Bicing i una estació amb id_estació com identificador
            \post Retorna l'Estació amb id_estació com a identificador
        */
        Estacio consulta_estacio(const string& id_estacio) const; 

};

#endif