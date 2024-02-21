/** @file Estacio.hh
    @brief Especificació de la clase Estacio.hh
*/

#ifndef ESTACIO_HH
#define ESTACIO_HH
#include "Bici.hh"
#include "Cjt_bici.hh"
#ifndef NO_DIAGRAM

#include <map>

#endif

/** @class Estacio
    @brief Representa una estació
    
    L'estació conté informació de sobre la seva capacitat i sobre les bicis que té emmagatzemades

*/

class Estacio {
    private:
        string id_estacio;
        int capacitat;
        int num_bicis;
        map<string, Bici> bici_estacio;
    
    public: 
        // Constructores

        /** @brief Creadora per defecte. S'executa automàticament al declarar una estació
            \pre <em>Cert</em>.
            \post S'ha creat una estació sense inicialitzar.
        */ 
        Estacio();



        /** @brief Creadora amb variables.
            \pre <em>Cert</em>.
            \post S'ha creat una estació inicialitzada.
        */
        Estacio(const string& id_estacio, const int& capacitat);

        // Modificadores

        /** @brief Afegeix una bici amb identificador id_bici a l'estació
            \pre Existeix l'estació amb id_estació i no existeix ninguna bici amb id_bici
            \post S'ha afegit la bici a l'estació 
        */
        void alta_bici(const string& id_bici);

        /** @brief Dona de baixa una bici
            \pre Existeix una bici amb identificador id_bici
            \post Elimina la bici de la seva estació corresponent
        */
        void baixa_bici(const string& id_bici);

        /** @brief Afegeix una bici ja existent a l'estació
            \pre Existeix una bici amb identificador id_bici i una estació amb identificador id_estacio la qual no està plena
            \post S'ha afegit la bici a l'estació
        */
        void afegir_bici(const Bici& bici);

        /** @brief Canvia la capacitat a num
            \pre L'estació existeix i num es major que la capacitat actual
            \post La capacitat de l'estació passa a ser num
        */
        int canviar_capacitat(int num);

        
        /** @brief Puja dif números de bici de l'estació passada com a p.i a l'estació aux 
            \pre L'estació aux no està plena i l'estació passada com a p.i te bicis guardades
            \post Mou dif bicis de l'estació passada  com a p.i a l'estació aux, decrementa dif cops les places_lliures_aux i el num_bicis_f
         * 
        */
        void pujar_bicis_dif(Estacio& aux, Cjt_bici& cjt_bici, const string& id_aux, int dif, int& places_lliures_aux, int& num_bicis_f);

        /** @brief Mou una bici de l'estació passada com a p.i a l'estació aux
            \pre L'estació aux no està plena i l'estació passada com a p.i te mínim una bici guardada
            \post Mou una bici de l'estació passada com a p.i a l'estació aux
        */
        void pujar_bici(Estacio& aux, const string& id_aux, Cjt_bici& cjt_bici, const string& id_bici);

        // Consultoras


        /** @brief Ens informa si una estació està plena o no
            \pre <em>Cert</em>.
            \post Retorna cert si l'estació està plena, fals en cas contrari*/
        bool esta_plena() const;

        /** @brief Ens diu el número de bicis que hi ha guardades
            \pre Existeix l'estació
            \post Ens diu el número de bicis que hi ha guardades
        */
        int consulta_num_bicis() const;

        string consulta_identificador() const;

        /** @brief Ens retorna la primera bici guardada
            \pre L'estació no està buida 
            \post Ens retorna la primera bici guardada a l'estació
        */
        Bici consulta_primera_bici() const;

        string consulta_id_primera_bici() const;

        /** @brief Ens diu el número de places lliures que hi ha en aquella estació
            \pre <em>Cert</em>.
            \post Ens diu el número de places lliures
        */
        int places_lliures() const;


        /** @brief Imprimeix totes les bicis guardades a aquella estació
            \pre L'estació existeix
            \post Ens dirà quines bicis estan guardades a aquella estació per ordre de identificador
        */
        void bicis_guardades() const;





};

#endif