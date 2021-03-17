#include "events.h"

int to_int(const std::string &a);

void Event::copy(const std::string& _name,const std::string & _date, const int& _auditorium, const std::vector<Ticket>& _tickets){
    name=_name;
    date=_date;
    auditorium=_auditorium;
    tickets=_tickets;
}

Event::Event(const std::string& _name,const std::string & _date, const int& _auditorium, const std::vector<Ticket>& _tickets){
    copy(_name,_date,_auditorium,_tickets);
}
Event::Event(const std::string& _name,const std::string & _date, const int& _auditorium){
    name=_name;
    date=_date;
    auditorium=_auditorium;
}
Event::Event(const std::string& _name,const std::string & _date, const std::string& _auditorium){
    name=_name;
    date=_date;
    auditorium=to_int(_auditorium);
}
Event::Event(const std::string& _name,const std::string & _date){
    name=_name;
    date=_date;
}
void Event::print(){
    std::cout<<"\nName of event: "<<name<<"\nDate of event: "<<date<<"\nTickets: \n";
    for(int i=0;i<tickets.size();i++){
        tickets[i].print();
    }
    std::cout<<"\n";
}
std::vector<Ticket>& Event::get_tickets(){
    return tickets;
}
int Event::get_auditorium()const{
    return auditorium;
}
std::string Event::get_date()const{
    return date;
}
std::string Event::get_name()const{
    return name;
}

int Event::bought_tickets()const{
    int counter=0;
    for(int i=0;i<tickets.size();i++){
        if(tickets[i].get_state_of_seat()=="bought"){
            counter++;
        }
    }
    return counter;
}