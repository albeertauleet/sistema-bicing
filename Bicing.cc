#include "Bicing.hh"

Bicing::Bicing () {};


BinTree<string> Bicing::i_llegir() 
{
    string id;
    cin >> id;
    if (id == "#") return BinTree<string>();
    else {
        int capacitat;
        cin >> capacitat;
        places_lliures_totals += capacitat;
        Estacio estacio(id, capacitat);
        afegir_estacio(id, estacio);
        return BinTree<string>(id, i_llegir(), i_llegir());
    }
}

void Bicing::i_reestructurar_estacions(const BinTree<string>& t, Cjt_bici& cjt_bici) 
{
    if (not t.left().empty()) 
    {
        const string id_aux = t.value();
        Estacio aux = info_estacions[id_aux];
        int places_lliures_aux = aux.places_lliures();

        if (places_lliures_aux > 0) {
            const string id_esquerra = t.left().value();
            const string id_dreta = t.right().value();
            Estacio& aux_esq = info_estacions[id_esquerra];
            Estacio& aux_dre = info_estacions[id_dreta];
            int num_bicis_esq = aux_esq.consulta_num_bicis();
            int num_bicis_dre = aux_dre.consulta_num_bicis();
            string id_bici_dre;
            string id_bici_esq;
            bool actualitzat_esq = false;
            bool actualitzat_dre = false;

            while ((num_bicis_esq > 0 or num_bicis_dre > 0) and places_lliures_aux  > 0) 
            {


                int dif = 0;

                if (num_bicis_esq > num_bicis_dre) 
                {
                    if (places_lliures_aux < num_bicis_esq - num_bicis_dre ) dif = places_lliures_aux;
                    else dif = num_bicis_esq - num_bicis_dre;
                    aux_esq.pujar_bicis_dif(aux, cjt_bici, id_aux, dif, places_lliures_aux, num_bicis_esq);
                    actualitzat_esq = true;
                } 
                else if (num_bicis_esq == num_bicis_dre) 
                {
                    id_bici_esq = aux_esq.consulta_id_primera_bici();
                    id_bici_dre = aux_dre.consulta_id_primera_bici();
                    if (id_bici_esq < id_bici_dre) 
                    {
                        aux_esq.pujar_bici(aux, id_aux, cjt_bici, id_bici_esq);
                        --num_bicis_esq;
                        actualitzat_esq = true;
                    } 
                    else 
                    {
                        aux_dre.pujar_bici(aux, id_aux, cjt_bici, id_bici_dre);
                        --num_bicis_dre;
                        actualitzat_dre = true;
                    }
                    --places_lliures_aux;
                } 
                else 
                {
                    if (places_lliures_aux < num_bicis_dre - num_bicis_esq ) dif = places_lliures_aux;
                    else dif = num_bicis_dre - num_bicis_esq;
                    aux_dre.pujar_bicis_dif(aux, cjt_bici, id_aux, dif, places_lliures_aux, num_bicis_dre);
                    actualitzat_dre = true;
                }
            }

            if (actualitzat_esq) info_estacions[id_esquerra] = aux_esq;
            if (actualitzat_dre) info_estacions[id_dreta] = aux_dre;
            if (actualitzat_esq or actualitzat_dre) info_estacions[id_aux] = aux;
        }

        i_reestructurar_estacions(t.left(), cjt_bici);
        i_reestructurar_estacions(t.right(), cjt_bici);
    }
}











/*

void Bicing::i_calcular_major_coeficient(const BinTree<string>& t, double& coeficient, int& num_est)
{
    if (not t.empty())
    {
        Estacio aux = info_estacions[t.value()];
        coeficient += aux.places_lliures();
        ++num_est;
        
    }
    if (not t.left().empty()) i_calcular_major_coeficient(t.left(), coeficient, num_est);
    if (not t.right().empty()) i_calcular_major_coeficient(t.right(), coeficient, num_est);
    
}
*/


void Bicing::i_calcula_major_coeficient(const BinTree<string>& aux, string& id_max, double& max, double& coeficient, int& num_est) 
{
    if (not aux.empty()) 
    {

        double coef_aux = 0.0;
        int num_est_aux = 0;

        if (not aux.left().empty()) 
        {
            i_calcula_major_coeficient(aux.left(), id_max, max, coef_aux, num_est_aux);
        }

        if (not aux.right().empty()) 
        {
            i_calcula_major_coeficient(aux.right(), id_max, max, coef_aux, num_est_aux);
        }

        const string id_auxe = aux.value();
        ++num_est_aux;
        Estacio auxe = info_estacions[id_auxe];
        coef_aux += auxe.places_lliures();

        if (coef_aux/num_est_aux > max or (coef_aux/num_est_aux == max and id_auxe < id_max)) 
        {
            max = coef_aux/num_est_aux;
            id_max = id_auxe;
        }

        coeficient += coef_aux;
        num_est += num_est_aux;
    }
}





void Bicing::llegir()
{
    estruc_estacions = i_llegir();
    
}

void Bicing::afegir_estacio(const string& id_estacio, const  Estacio& estacio) 
{
    info_estacions[id_estacio] = estacio;
}

void Bicing::modifica_estacio(const string& id_estacio, const Estacio& estacio) 
{
    map<string, Estacio>::iterator it = info_estacions.find(id_estacio);
    it->second = estacio;
}

void Bicing::inicialitzar_places_lliures_totals() 
{
    places_lliures_totals = 0;
}

void Bicing::modifica_places(int n)
{
    places_lliures_totals += n;
}

void Bicing::reestructurar_estacions(Cjt_bici& cjt_bici)
{
    if (not estruc_estacions.empty()) i_reestructurar_estacions(estruc_estacions, cjt_bici); 
}

void Bicing::assignar_estacio(const string& id_bici , Cjt_bici& cjt_bici)
{
    string id_max;
    double max = 0.0;
    double coeficient = 0.0;
    int num_est = 0;
    i_calcula_major_coeficient(estruc_estacions, id_max, max, coeficient, num_est);
    
    cout << id_max << endl;
    info_estacions[id_max].alta_bici(id_bici);
    Bici bici(id_bici, id_max);
    cjt_bici.afegir_bici(id_bici, bici);    
    
}

bool Bicing::existeix_estacio(const string& id_estacio) const 
{
    map<string, Estacio>::const_iterator it = info_estacions.find(id_estacio);
    if (it == info_estacions.end()) return false;
    return true;
}

int Bicing::places_lliures_total() const
{
    return places_lliures_totals;
}

Estacio Bicing::consulta_estacio(const string& id_estacio) const
{
    map<string, Estacio>::const_iterator it = info_estacions.find(id_estacio);
    return it->second;
}


