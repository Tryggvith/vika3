#ifndef PERFORMERSERVICE_H
#define PERFORMERSERVICE_H
#include "performer.h"
#include "dataaccess.h"

using namespace std;

class PerformerService
{
public:
    PerformerService();
    void openFiles();//opnar sql files um leið og forritið er keyrt, einu sinni.
    vector<Relations> startJoin(string CS, string id);
    vector<Performer> getPerformers(); //Nær í gögn úr skrá og skilar þeim í vector
    vector<Performer> searchpeople(QString name); //Leitar að ákveðnu nafni í listanum
    vector<computers> searchcomputer(QString name); //Leitar að ákveðnu nafni í listanum
    vector<Performer> sortByName(); //Ber saman nöfn og raðar þeim í stafrófsröð
    vector<Performer> sortBybYear(); //Ber saman ár og raðar þeim frá því lægsta til þess hæsta
    vector<Performer> sortByGender(); //Ber saman kyn
    vector<Performer> sortByNationality(); //Ber saman þjóðerni og raðar þeim eftir stafrófsröð
    vector<computers> getComputers(); //vektor fyrir computers.
    void removeScientist(string name);
    string removeComputer(string name);
    void addPerformer(string name, string gender, string birth, string death, string nation); //Bætir nýjum tölvunarfræðingi inn í skrána
    void addComputer(string name, string buildy, string brand, string constr);
    void addRelations(QString sId, QString cId);
    void removeJoin(int id);
    void updateScientist(string name, string gender, string bYear, string dYear, string nation, string id);
    void updateComputer(string name, string buildy, string brand, string constr, string id);
    vector<Performer> updateTableScientist();
    vector<computers> updateTableComputer();
    vector<RelationsTable2> viewScientist(int counter);
    vector<computers> sortComputers(string i1, string i2, string i3);
    vector<Performer> sortScientists(string i1, string i2, string i3);
    vector<RelationsID> viewJoin();
    vector<RelationsTable> readData();
private:
    DataAccess _data;// Sækir upplýsingar og leyfir virkni úr DataAccess.
};

#endif // PERFORMERSERVICE_H
