#include "Cjt_bici.hh"

Cjt_bici::Cjt_bici(){};

void Cjt_bici::afegir_bici(const string& id_bici, const Bici& bici)
{

    cjt_bici[id_bici] = bici;
}

/*
void Cjt_bici::modificar_bici(const string& id_bici, const Bici& bici)
{
    cjt_bici.erase(id_bici);
    cjt_bici[id_bici] = bici;
}
*/

void Cjt_bici::eliminar_bici(const string& id_bici)
{
    cjt_bici.erase(id_bici);
}

bool Cjt_bici::existeix_bici(const string& id_bici) const
{
    map<string, Bici>::const_iterator it = cjt_bici.find(id_bici);
    if (it == cjt_bici.end()) return false;
    return true;
}

string Cjt_bici::on_esta(const string& id_bici) const
{
    map<string, Bici>::const_iterator it = cjt_bici.find(id_bici);
    return (it->second).consulta_estacio_bici();
}

Bici Cjt_bici::consulta_bici(const string& id_bici) const
{
    
    map<string, Bici>::const_iterator it = cjt_bici.find(id_bici);
    return (it->second);
}