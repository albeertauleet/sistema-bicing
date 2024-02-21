#include "Estacio.hh"


Estacio::Estacio() {};

Estacio::Estacio(const string& id_estacio, const int& capacitat) 
{
    this->id_estacio = id_estacio;
    this->capacitat = capacitat;
    num_bicis = 0;
    bici_estacio = map<string, Bici>();
}

void Estacio::alta_bici(const string& id_bici)
{
    ++num_bicis;
    Bici bici(id_bici, id_estacio);
    bici_estacio.insert(make_pair(id_bici, bici));
   
}

void Estacio::baixa_bici(const string& id_bici) 
{
    num_bicis -= 1;
    bici_estacio.erase(id_bici);
   
}

void Estacio::afegir_bici(const Bici& bici) 
{
    ++num_bicis;
    string id_bici = bici.consulta_id_bici();
    bici_estacio[id_bici] = bici;
}

int Estacio::canviar_capacitat(int num)
{
    int aux = num - capacitat;
    capacitat = num;
    return aux;
}

void Estacio::pujar_bicis_dif(Estacio& aux, Cjt_bici& cjt_bici, const string& id_aux, int dif, int& places_lliures_aux, int& num_bicis_f) 
{
    
    Bici b_aux;
    string id_bici;
    map<string, Bici>::iterator it = bici_estacio.begin();
    for(int i = 0; i < dif; ++i)
    {
        b_aux = it->second;
        id_bici = it->first;
        num_bicis -= 1;
        it = bici_estacio.erase(it);
        b_aux.canviar_estacio(id_aux);
        aux.afegir_bici(b_aux);
        cjt_bici.afegir_bici(id_bici, b_aux);
        
    }
    places_lliures_aux -= dif;
    num_bicis_f -= dif;
}

void Estacio::pujar_bici(Estacio& aux, const string& id_aux,  Cjt_bici& cjt_bici, const string& id_bici)
{
    
    Bici b_aux = bici_estacio[id_bici];
    num_bicis -= 1;
    bici_estacio.erase(id_bici);
    b_aux.canviar_estacio(id_aux);
    aux.afegir_bici(b_aux);
    cjt_bici.afegir_bici(id_bici, b_aux);
    
}

bool Estacio::esta_plena() const
{
    return capacitat == num_bicis;
}

int Estacio::consulta_num_bicis() const
{
    return num_bicis;
}

string Estacio::consulta_identificador() const
{
    return id_estacio;
}

Bici Estacio::consulta_primera_bici() const
{
    map<string, Bici>::const_iterator it = bici_estacio.begin();
    return it->second;
}

string Estacio::consulta_id_primera_bici() const 
{
    map<string, Bici>::const_iterator it = bici_estacio.begin();
    return it->first;
}


int Estacio::places_lliures() const
{
    return capacitat-num_bicis;
}



void Estacio::bicis_guardades() const 
{
    map<string, Bici>::const_iterator it = bici_estacio.begin();
    for (int i = 0; i < num_bicis; ++i) 
    {
        cout << it->first << endl;
        ++it;
    }
}