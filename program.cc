/**
    @mainpage Sistema de Bicing bifurcat
    
    En aquest programa es construeix un programa modular el qual ofereix una estructura per organitzar les diferents estacions de Bicing i les seves respectives bicis i la seva informació corresponent. A més, aquest programa proporciona un menú d'operacions per tal de que aquesta estructura estigui el més a prop possible de la realitat. S'introdueixen les calsses de <em>Bicing</em>m <em>Estacio</em> i <em>Bici</em>.

*/

/** @file main.cc
    @brief Programa principal per a la <em>Simulació del Bicing bifurcat</em>.*/

#include "Bicing.hh"
#include "Estacio.hh"
#include "Bici.hh"
#include "Cjt_bici.hh"
#ifndef NO_DIAGRAM
#include <iostream>
#endif
using namespace std;






int main() 
{
    Bicing bicing; // creem l'estructura per poder posar les estacions
    bicing.inicialitzar_places_lliures_totals();
    bicing.llegir();
    Cjt_bici cjt_bici; 
    string op;
    cin >> op;
    while (op != "fin" ) 
    {
        if (op == "alta_bici" or op == "ab")
        {
            string id_bici, id_estacio;
            cin >> id_bici >> id_estacio;
            cout << "#ab " << id_bici << " " << id_estacio << endl;

            if (cjt_bici.existeix_bici(id_bici)) cout << "error: la bici ya existe" << endl;
            else if (not bicing.existeix_estacio(id_estacio)) cout << "error: la estacion no existe" << endl;
            else 
            {
                if (bicing.consulta_estacio(id_estacio).esta_plena()) cout << "error: la bici no cabe" << endl;
                else 
                {
                    Estacio aux = bicing.consulta_estacio(id_estacio);// aixo no se si es correcte ja que no se si un cop modificada l'estacio s'actualitza automaticament al sistema bicing
                    aux.alta_bici(id_bici);
                    bicing.modifica_places(-1);
                    bicing.afegir_estacio(id_estacio, aux);
                    Bici bici(id_bici, id_estacio);
                    cjt_bici.afegir_bici(id_bici, bici);
                }
            } 
        }

        else if (op == "baja_bici" or op == "bb")
        {
            string id_bici;
            cin >> id_bici;
            cout << "#bb " << id_bici << endl;

            if (not cjt_bici.existeix_bici(id_bici)) cout << "error: la bici no existe" << endl;
            else 
            {
                Estacio aux = bicing.consulta_estacio(cjt_bici.on_esta(id_bici));
                aux.baixa_bici(id_bici);
                bicing.modifica_places(1);
                bicing.afegir_estacio(cjt_bici.on_esta(id_bici), aux);
                cjt_bici.eliminar_bici(id_bici);
            }

        }

        else if (op == "estacion_bici" or op == "eb")
        {
            string id_bici;
            cin >> id_bici;
            cout << "#eb " << id_bici << endl;

            if (not cjt_bici.existeix_bici(id_bici)) cout << "error: la bici no existe" << endl;
            else 
            {
                cout << cjt_bici.on_esta(id_bici) << endl;
            }
        }

        else if (op == "viajes_bici" or op == "vb") 
        {
            string id_bici;
            cin >> id_bici;
            cout << "#vb " << id_bici << endl;

            if (not cjt_bici.existeix_bici(id_bici)) cout << "error: la bici no existe" << endl;
            else 
            {
                cjt_bici.consulta_bici(id_bici).viatges_bici();
            }
        }

        else if (op == "mover_bici" or op == "mb")
        {
            string id_bici, id_estacio;
            cin >> id_bici >> id_estacio;
            cout << "#mb " << id_bici << " " << id_estacio << endl;

            if (not cjt_bici.existeix_bici(id_bici)) cout << "error: la bici no existe" << endl;
            else if (not bicing.existeix_estacio(id_estacio)) cout << "error: la estacion no existe" << endl;
            else if (cjt_bici.on_esta(id_bici) == id_estacio) cout << "error: la bici ya esta en el sitio" << endl;
            else if (bicing.consulta_estacio(id_estacio).esta_plena()) cout << "error: la bici no cabe" << endl;
            else 
            {
                Bici aux = cjt_bici.consulta_bici(id_bici);
                string aux_id = cjt_bici.on_esta(id_bici);
                Estacio auxe = bicing.consulta_estacio(aux_id);
                auxe.baixa_bici(id_bici);
                bicing.modifica_estacio(aux_id, auxe);
                aux.viatjar_estacio(id_estacio);
                auxe = bicing.consulta_estacio(id_estacio);
                auxe.afegir_bici(aux);
                bicing.modifica_estacio(id_estacio, auxe);
                cjt_bici.afegir_bici(id_bici, aux);
            }
        }
        
        else if (op == "bicis_estacion" or op == "be")
        {
            string id_estacio;
            cin >> id_estacio;
            cout << "#be " << id_estacio << endl;

            if (not bicing.existeix_estacio(id_estacio)) cout << "error: la estacion no existe" << endl;
            else
            {
                bicing.consulta_estacio(id_estacio).bicis_guardades();
            }
        }

        else if (op == "modificar_capacidad" or op == "mc") 
        {
            string id_estacio;
            int num;
            cin >> id_estacio >> num;
            cout << "#mc " << id_estacio << " " << num << endl;

            if (not bicing.existeix_estacio(id_estacio)) cout << "error: la estacion no existe" << endl;
            else if (num < bicing.consulta_estacio(id_estacio).consulta_num_bicis()) cout << "error: capacidad insuficiente" << endl;
            else 
            {
                Estacio aux = bicing.consulta_estacio(id_estacio);
                int aux_n = aux.canviar_capacitat(num);
                bicing.modifica_places(aux_n);
                bicing.afegir_estacio(id_estacio, aux);
            }

        }

        else if (op == "plazas_libres" or op == "pl")
        {
            cout << "#pl" << endl;
            cout << bicing.places_lliures_total() << endl;
        }

        else if (op == "subir_bicis" or op == "sb") 
        {
          cout << "#sb" << endl;
          bicing.reestructurar_estacions(cjt_bici);
        }

        else if (op == "asignar_estacion" or op == "ae")
        {
            string id_bici;
            cin >> id_bici;
            cout << "#ae " << id_bici << endl;

            if (cjt_bici.existeix_bici(id_bici)) cout << "error: la bici ya existe" << endl;
            else if (bicing.places_lliures_total() == 0) cout << "error: no hay plazas libres" << endl;
            else
            {
              bicing.assignar_estacio(id_bici, cjt_bici);
              bicing.modifica_places(-1);
            } 
    
        }

        cin >> op;


    }
}