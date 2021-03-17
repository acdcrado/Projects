#include "auditorium.h"
#include "cmath"

int to_int(const std::string &a);
std::vector<Event>& Auditorium::get_events(){
    return events;
}

Auditorium::Auditorium(std::string& _id, std::string& _rows, std::string& _seats_on_rows){
    id=to_int(_id);
    rows=to_int(_rows);
    seats_on_row=to_int(_seats_on_rows);
}

void Auditorium::print(){
    std::cout<<"Auditorium: "<<id<<"\nRows: "<<rows<<"\nSeats on each row: "<<seats_on_row<<"\n";
    for(int i=0;i<events.size();i++){
        events[i].print();
    }
    std::cout<<"\n";
}
int Auditorium::get_id()const{
    return id;
}
int Auditorium::get_rows()const{
    return rows;
}
int Auditorium::get_seats_on_row()const{
    return seats_on_row;
}