#include "performerservice.h"
#include "dataaccess.h"
#include <algorithm>
#include <iostream>

using namespace std;
PerformerService::PerformerService() //Tómur smiður
{

}

vector <Performer> PerformerService:: searchpeople(QString name) //Leitar að ákveðnu nafni í listanum
{
    vector<Performer> newVector = _data.searchScientist(name);
    return newVector;
}

vector<computers> PerformerService::searchcomputer(QString name) //Leitar að ákveðinni tölvu í listanum
{
    vector<computers> newVector = _data.searchComputer(name);
    return newVector;
}

void PerformerService::addPerformer(string name, string gender, string birth, string death, string nation) //Bætir nýjum tölvunarfræðingi inn í skrána
{
   _data.writeData(name, gender, birth, death, nation);
}

void PerformerService::addComputer(string name, string buildy, string brand, string constr) //Bætir nýjum tölvunarfræðingi inn í skrána
{
   _data.addCpu(name, buildy, brand, constr);
}

void PerformerService::removeScientist(string name)
{
    _data.removeDataScientist(name);
}

string PerformerService::removeComputer(string name)
{
    _data.removeDataComputer(name);
    return name;
}

void PerformerService::openFiles()
{
    _data.openSqlFiles();
}

vector<Relations> PerformerService::startJoin(string CS,int id)
{
    vector<Relations> join = _data.joinScientists(CS, id);
    return join;
}

vector<RelationsTable2> PerformerService::viewScientist(int counter)
{
    vector<RelationsTable2> pf;
    if(counter == 1)
    {
        vector<RelationsTable2> pf = _data.viewScientist();
        return pf;
    }
    else if(counter == 2)
    {
        vector<RelationsTable2> pf = _data.viewComputer();
        return pf;
    }
    return pf;
}

void PerformerService::addRelations(int sId, int cId)
{
    _data.addRelations(sId, cId);
}

vector<computers> PerformerService::sortComputers(string i1, string i2, string i3)
{
    vector<computers> pf = _data.sortCpu(i1, i2, i3);
    return pf;
}

vector<Performer> PerformerService::sortScientists(string i1, string i2, string i3)
{
    vector<Performer> pf = _data.sortScientists(i1, i2, i3);
    return pf;
}
vector<RelationsID> PerformerService::viewJoin()
{
    vector<RelationsID> pf = _data.viewJoin();
    return pf;
}

vector<RelationsTable> PerformerService::readData()
{
    vector<RelationsTable> pf = _data.readData();
    return pf;
}

void PerformerService::removeJoin(int id)
{
    _data.removeJoin(id);
}
void PerformerService::updateScientist(string name, string gender, string bYear, string dYear, string nation, string id)
{
    QString Qname = QString::fromStdString(name);
    QString Qgender = QString::fromStdString(gender);
    QString QbYear = QString::fromStdString(bYear);
    QString QdYear = QString::fromStdString(dYear);
    QString Qnation = QString::fromStdString(nation);
    QString Qid = QString::fromStdString(id);
    _data.updateScientist(Qname, Qgender, QbYear, QdYear, Qnation, Qid);
}
void PerformerService::updateComputer(string input, string id)
{
    _data.updateComputer(input, id);
}
vector<Performer> PerformerService::updateTableScientist()
{
    vector<Performer> pf = _data.updateTable();
    return pf;
}
