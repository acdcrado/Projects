#include "theatre.h"

int to_int(const std::string &a);
int wordcounter(std::string str)
{
    int words = 1;
    for (int i = 0; i < str.size(); i++)
    {
        if (str.at(i) == ' ')
        {
            words++;
        }
    }
    return words;
}
void word_maker(std::string input, std::string *result, int size)
{
    int curstring = 0;
    for (int i = 0; i < size; i++)
    {
        result[i].clear();
    }
    for (int i = 0; i < input.size(); i++)
    {
        if (input.at(i) == ' ')
        {
            curstring++;
        }
        else
        {
            result[curstring].push_back(input.at(i));
        }
    }
}
void help()
{
    std::cout << "addevent - Adds a new event\n";
    std::cout << "freeseats - Shows the free seats on a given event\n";
    std::cout << "book - Books a ticket for a given event\n";
    std::cout << "unbook - Unbooks a ticket for a given event\n";
    std::cout << "buy - Buys a ticket for a given event\n";
    std::cout << "bookings - Shows all booked tickets for a given event\n";
    std::cout << "check - Gives information about a given ticket's code\n";
    std::cout << "report - Gives reference to bought tickets for a given period of time\n";
    std::cout << "print - Gives all the information about auditoriums, events and tickets\n";
}
bool Theatre::is_valid_date(const std::string &_date)
{
    if (_date.size() != 10)
    {
        return false;
    }
    if (_date[4] != '-' || _date[7] != '-' ||
        _date[0] < '0' || _date[0] > '9' ||
        _date[1] < '0' || _date[0] > '9' ||
        _date[2] < '0' || _date[0] > '9' ||
        _date[3] < '0' || _date[0] > '9' ||
        _date[5] < '0' || _date[0] > '9' ||
        _date[6] < '0' || _date[0] > '9' ||
        _date[8] < '0' || _date[0] > '9' ||
        _date[9] < '0' || _date[0] > '9')
    {
        return false;
    }
    return true;
}

int Theatre::find_code_index(const std::string &_code, const int &a, const int &b)
{
    for (int i = 0; i < auditoriums[a].get_events()[b].get_tickets().size(); i++)
    {
        if (auditoriums[a].get_events()[b].get_tickets()[i].get_u_Code() == _code)
        {
            return i;
        }
    }
    return -1;
}
bool Theatre::is_date_free(const std::string &_date)
{
    for (int i = 0; i < auditoriums.size(); i++)
    {
        for (int j = 0; j < auditoriums[i].get_events().size(); j++)
        {
            if (auditoriums[i].get_events()[j].get_date() == _date)
            {
                return false;
            }
        }
    }
    return true;
}
void Theatre::add_event(Event &temp_event)
{
    bool auditorium_found = false;
    if (is_date_free(temp_event.get_date()) == false)
    {
        std::cout << "Sorry, there is already an event in this auditorium on this date. Please try agian.\n";
    }
    else
    {
        if (is_valid_date(temp_event.get_date()))
        {
            for (int i = 0; i < auditoriums.size(); i++)
            {
                if (auditoriums[i].get_id() == temp_event.get_auditorium())
                {
                    auditoriums[i].get_events().push_back(temp_event);
                    auditorium_found = true;
                }
            }
            if (auditorium_found == false)
            {
                std::cout << "There isn't such auditorium. Please try again.\n";
            }
        }
        else
        {
            std::cout << "Invalid date, please try again from the beginning.\n";
        }
    }
}
void Theatre::free_seats(Event &temp_event)
{
    bool event_found = false;
    if (is_valid_date(temp_event.get_date()))
    {
        for (int i = 0; i < auditoriums.size(); i++)
        {
            for (int j = 0; j < auditoriums[i].get_events().size(); j++)
            {
                if (auditoriums[i].get_events()[j].get_date() == temp_event.get_date() && auditoriums[i].get_events()[j].get_name() == temp_event.get_name())
                {
                    std::cout << "There are " << auditoriums[i].get_rows() * auditoriums[i].get_seats_on_row() - auditoriums[i].get_events()[j].get_tickets().size()
                              << " free seats for " << temp_event.get_name() << " on " << temp_event.get_date() << ".\n";
                    event_found = true;
                }
            }
        }
        if (event_found == false)
        {
            std::cout << "There isn't such event. Please try again.\n";
        }
    }
    else
    {
        std::cout << "Invalid date, please try again from the beginning.\n";
    }
}
bool Theatre::found_date(const std::string& _date){
        for(int i=0;i<auditoriums.size();i++){
            for(int j=0;j<auditoriums[i].get_events().size();j++){
                if(auditoriums[i].get_events()[j].get_date()==_date){
                    return true;
                }
            }
        }
        return false;
}
void Theatre::book_ticket(Ticket &temp_ticket, std::string *info)
{
    bool ticket_found = false;
    bool adequate_seat = true;
    int foundi, foundj;
    if (is_valid_date(info[2]) == true && found_date(info[2]))
    {
        for (int i = 0; i < auditoriums.size(); i++)
        {
            for (int j = 0; j < auditoriums[i].get_events().size(); j++)
            {
                if (auditoriums[i].get_events()[j].get_date() == info[2] && auditoriums[i].get_events()[j].get_name() == info[3])
                {
                    foundi = i;
                    foundj = j;
                    if (auditoriums[i].get_rows() >= to_int(info[0]) && auditoriums[i].get_seats_on_row() >= to_int(info[1]))
                    {
                        for (int m = 0; m < auditoriums[i].get_events()[j].get_tickets().size(); m++)
                        {
                            if (auditoriums[i].get_events()[j].get_tickets()[m].get_row() == temp_ticket.get_row() && auditoriums[i].get_events()[j].get_tickets()[m].get_seat() == temp_ticket.get_seat())
                            {
                                ticket_found = true;
                                std::cout << "This place is already reserved/sold. Please try again.\n";
                                break;
                            }
                        }
                    }
                    else
                    {
                        std::cout << "There isn't such seat. Please try agian.\n";
                        adequate_seat = false;
                    }
                }
            }
        }
        if (ticket_found == false && adequate_seat == true)
        {
            temp_ticket.generate_code(temp_ticket.get_row(), temp_ticket.get_seat());
            temp_ticket.set_state_of_seat("booked");
            auditoriums[foundi].get_events()[foundj].get_tickets().push_back(temp_ticket);
        }
    }
    else
    {
        std::cout << "Invalid date, please try agian.\n";
    }
}
void Theatre::unbook_ticket(Ticket &temp_ticket, std::string *info)
{
    bool ticket_found = false;
    bool adequate_seat = true;
    int foundi, foundj;
   if (is_valid_date(info[2]) == true && found_date(info[2]))
    {
        for (int i = 0; i < auditoriums.size(); i++)
        {
            for (int j = 0; j < auditoriums[i].get_events().size(); j++)
            {
                if (auditoriums[i].get_events()[j].get_date() == info[2] && auditoriums[i].get_events()[j].get_name() == info[3])
                {
                    foundi = i;
                    foundj = j;
                    if (auditoriums[i].get_rows() >= to_int(info[0]) && auditoriums[i].get_seats_on_row() >= to_int(info[1]))
                    {
                        for (int m = 0; m < auditoriums[i].get_events()[j].get_tickets().size(); m++)
                        {
                            if (auditoriums[i].get_events()[j].get_tickets()[m].get_row() == temp_ticket.get_row() && auditoriums[i].get_events()[j].get_tickets()[m].get_seat() == temp_ticket.get_seat())
                            {
                                if (auditoriums[i].get_events()[j].get_tickets()[m].get_state_of_seat() == "bought")
                                {
                                    std::cout << "This place is already sold. Please try again.\n";
                                }
                                if (auditoriums[i].get_events()[j].get_tickets()[m].get_state_of_seat() == "booked")
                                {
                                    std::cout << "You've successfully unbooked the ticket.\n";
                                    auditoriums[i].get_events()[j].get_tickets().erase(
                                        auditoriums[i].get_events()[j].get_tickets().begin() +
                                        find_code_index(auditoriums[i].get_events()[j].get_tickets()[m].get_u_Code(), foundi, foundj));
                                }
                                ticket_found = true;
                            }
                        }
                    }
                    else
                    {
                        std::cout << "There isn't such seat. Please try agian.\n";
                        adequate_seat = false;
                    }
                }
            }
        }
        if (ticket_found == false && adequate_seat == true)
        {
            std::cout << "This seat isn't booked so it can't be unbooked. If u want to book it, use the command book.\n";
        }
    }
    else
    {
        std::cout << "Invalid date, please try agian.\n";
    }
}
void Theatre::buy_ticket(Ticket &temp_ticket, std::string *info)
{
    bool ticket_found = false;
    bool adequate_seat = true;
    int foundi, foundj;
   if (is_valid_date(info[2]) == true && found_date(info[2]))
    {
        for (int i = 0; i < auditoriums.size(); i++)
        {
            for (int j = 0; j < auditoriums[i].get_events().size(); j++)
            {
                if (auditoriums[i].get_events()[j].get_date() == info[2] && auditoriums[i].get_events()[j].get_name() == info[3])
                {
                    foundi = i;
                    foundj = j;
                    if (auditoriums[i].get_rows() >= to_int(info[0]) && auditoriums[i].get_seats_on_row() >= to_int(info[1]))
                    {
                        for (int m = 0; m < auditoriums[i].get_events()[j].get_tickets().size(); m++)
                        {
                            if (auditoriums[i].get_events()[j].get_tickets()[m].get_row() == temp_ticket.get_row() && auditoriums[i].get_events()[j].get_tickets()[m].get_seat() == temp_ticket.get_seat())
                            {
                                ticket_found = true;
                                std::cout << "This place is already reserved/sold. Please try again.\n";
                                break;
                            }
                        }
                    }
                    else
                    {
                        std::cout << "There isn't such seat. Please try agian.\n";
                        adequate_seat = false;
                    }
                }
            }
        }
        if (ticket_found == false && adequate_seat == true)
        {
            temp_ticket.generate_code(temp_ticket.get_row(), temp_ticket.get_seat());
            temp_ticket.set_state_of_seat("bought");
            auditoriums[foundi].get_events()[foundj].get_tickets().push_back(temp_ticket);
        }
    }
    else
    {
        std::cout << "Invalid date, please try agian.\n";
    }
}
void Theatre::check_code(std::string &_code)
{
    for (int i = 0; i < auditoriums.size(); i++)
    {
        for (int j = 0; j < auditoriums[i].get_events().size(); j++)
        {
            for (int m = 0; m < auditoriums[i].get_events()[j].get_tickets().size(); m++)
            {
                if (auditoriums[i].get_events()[j].get_tickets()[m].get_u_Code() == _code)
                {
                    auditoriums[i].get_events()[j].get_tickets()[m].read_code(_code);
                }
            }
        }
    }
}

void Theatre::bookings(Event &temp_event)
{
    bool event_found = false;
    if (is_valid_date(temp_event.get_date()))
    {
        for (int i = 0; i < auditoriums.size(); i++)
        {
            for (int j = 0; j < auditoriums[i].get_events().size(); j++)
            {
                if (auditoriums[i].get_events()[j].get_date() == temp_event.get_date() && auditoriums[i].get_events()[j].get_name() == temp_event.get_name())
                {
                    for (int m = 0; m < auditoriums[i].get_events()[j].get_tickets().size(); m++)
                    {
                        if (auditoriums[i].get_events()[j].get_tickets()[m].get_state_of_seat() == "booked")
                        {
                            auditoriums[i].get_events()[j].get_tickets()[m].print();
                        }
                    }
                    event_found = true;
                }
            }
        }
        if (event_found == false)
        {
            std::cout << "There isn't such event. Please try again.\n";
        }
    }
    else
    {
        std::cout << "Invalid date, please try again from the beginning.\n";
    }
}

void Theatre::all_in_file(std::ofstream &out)
{
    for (int i = 0; i < auditoriums.size(); i++)
    {
        out << auditoriums[i].get_id() << " " << auditoriums[i].get_rows() << " " << auditoriums[i].get_seats_on_row() << "\n";
        for (int j = 0; j < auditoriums[i].get_events().size(); j++)
        {
            out << auditoriums[i].get_events()[j].get_name() << " " << auditoriums[i].get_events()[j].get_date() << "\n";
            for (int m = 0; m < auditoriums[i].get_events()[j].get_tickets().size(); m++)
            {
                out << auditoriums[i].get_events()[j].get_tickets()[m].get_u_Code() << " "
                    << auditoriums[i].get_events()[j].get_tickets()[m].get_state_of_seat() << " "
                    << auditoriums[i].get_events()[j].get_tickets()[m].get_row() << " "
                    << auditoriums[i].get_events()[j].get_tickets()[m].get_seat() << "\n";
            }
        }
    }
}
void Theatre::load_from_file(std::istream &cin)
{
    std::string info[4];
    for (std::string line; getline(cin, line);)
    {
        if (wordcounter(line) == 3)
        {
            word_maker(line, info, 3);
            Auditorium temp_auditorium(info[0], info[1], info[2]);
            auditoriums.push_back(temp_auditorium);
        }
        if (wordcounter(line) == 2)
        {
            word_maker(line, info, 2);
            Event temp_event(info[0], info[1]);
            auditoriums[auditoriums.size() - 1].get_events().push_back(temp_event);
        }
        if (wordcounter(line) == 4)
        {
            word_maker(line, info, 4);
            Ticket temp_ticket(info[1], info[0], info[2], info[3]);
            auditoriums[auditoriums.size() - 1].get_events()[auditoriums[auditoriums.size() - 1].get_events().size() - 1].get_tickets().push_back(temp_ticket);
        }
    }
}

void Theatre::report(std::string &_from, std::string &_to, std::string &_id)
{
    int auditorium_id = to_int(_id);
    for (int i = 0; i < auditoriums.size(); i++)
    {
        if (auditoriums[i].get_id() == auditorium_id)
        {
            for (int j = 0; j < auditoriums[i].get_events().size(); j++)
            {
                if (strcmp(auditoriums[i].get_events()[j].get_date().c_str(), _from.c_str()) >= 0 &&
                    strcmp(auditoriums[i].get_events()[j].get_date().c_str(), _to.c_str()) <= 0)
                {
                    auditoriums[i].get_events()[j].print();
                    std::cout << "Tickets bought: " << auditoriums[i].get_events()[j].bought_tickets() << "\n";
                }
            }
        }
    }
}
void deleteFirst(std::string *str)
{
    for (int i = 0; i < 7; i++)
    {
        str[i] = str[i + 1];
    }
}

std::vector<Auditorium> &Theatre::get_auditoriums()
{
    return auditoriums;
}
void Theatre::print()
{
    for (int i = 0; i < auditoriums.size(); i++)
    {
        auditoriums[i].print();
    }
}
void Theatre::load_auditoriums(std::istream &cin)
{
    std::string info[3];
    for (std::string line; getline(cin, line);)
    {
        word_maker(line, info, 3);
        Auditorium temp_auditorium(info[0], info[1], info[2]);
        auditoriums.push_back(temp_auditorium);
    }
}
void Theatre::load_events(std::istream &cin)
{
    std::string info[3];
    for (std::string line; getline(cin, line);)
    {
        word_maker(line, info, 3);
        Event temp_event(info[1], info[0], info[2]);
        for (int i = 0; i < auditoriums.size(); i++)
        {
            if (auditoriums[i].get_id() == temp_event.get_auditorium())
            {
                auditoriums[i].get_events().push_back(temp_event);
            }
        }
    }
}
void Theatre::open()
{
    bool loaded_auditoriums = false;
    std::string str, info[15], opened_file;
    bool running = true;
    std::cout << "$\n";
    while (running)
    {
        getline(std::cin, str);
        std::cout << "\n";
        word_maker(str, info, 15);
        if (strcmp(info[0].c_str(), "addevent") == 0)
        {
            deleteFirst(info);
            Event temp_event(info[2], info[0], info[1]);
            add_event(temp_event);
        }
        else if (strcmp(info[0].c_str(), "freeseats") == 0)
        {
            deleteFirst(info);
            Event temp_event(info[1], info[0]);
            free_seats(temp_event);
        }
        else if (strcmp(info[0].c_str(), "book") == 0)
        {
            deleteFirst(info);
            Ticket temp_ticket(info[0], info[1]);
            book_ticket(temp_ticket, info);
        }
        else if (strcmp(info[0].c_str(), "unbook") == 0)
        {
            deleteFirst(info);
            Ticket temp_ticket(info[0], info[1]);
            unbook_ticket(temp_ticket, info);
        }
        else if (strcmp(info[0].c_str(), "buy") == 0)
        {
            deleteFirst(info);
            Ticket temp_ticket(info[0], info[1]);
            buy_ticket(temp_ticket, info);
        }
        else if (strcmp(info[0].c_str(), "bookings") == 0)
        {
            deleteFirst(info);
            Event temp_event(info[1], info[0]);
            bookings(temp_event);
        }
        else if (strcmp(info[0].c_str(), "check") == 0)
        {
            deleteFirst(info);
            check_code(info[0]);
        }
        else if (strcmp(info[0].c_str(), "report") == 0)
        {
            deleteFirst(info);
            report(info[0], info[1], info[2]);
        }
        else if (strcmp(info[0].c_str(), "load") == 0)
        {
            deleteFirst(info);
            if (loaded_auditoriums == false)
            {
                std::ifstream file(info[0].c_str());
                load_auditoriums(file);
                file.close();
                loaded_auditoriums = true;
                opened_file = info[0].c_str();
            }
            else
            {
                std::ifstream file(info[0].c_str());
                load_events(file);
                file.close();
                opened_file = info[0].c_str();
            }
        }
        else if (strcmp(info[0].c_str(), "close") == 0)
        {
            deleteFirst(info);
            for (int i = 0; i < auditoriums.size(); i++)
            {
                auditoriums[i].get_events().clear();
            }
        }
        else if (strcmp(info[0].c_str(), "save") == 0)
        {
            deleteFirst(info);
            std::ofstream file(opened_file, std::ios::out | std::ios::trunc);
            all_in_file(file);
            file.close();
        }
        else if (strcmp(info[0].c_str(), "save_as") == 0)
        {
            deleteFirst(info);
            std::ofstream newFile(info[0].c_str(), std::ios::out | std::ios::trunc);
            all_in_file(newFile);
            newFile.close();
            std::cout << " You have successfully saved new file containing the information about the theatre named " << info[0] << ". \n";
        }
        else if (strcmp(info[0].c_str(), "help") == 0)
        {
            help();
        }
        else if (strcmp(info[0].c_str(), "print") == 0)
        {
            print();
        }
        else if (strcmp(info[0].c_str(), "exit") == 0)
        {
            running = false;
        }
        else if (strcmp(info[0].c_str(), "open") == 0)
        {
            deleteFirst(info);
            std::cout << "\n";
            std::ofstream buf;
            buf.open(info[0].c_str(), std::ios::app);
            buf.close();
            bool loaded_auditoriums = false;
            std::fstream file;
            file.open(info[0].c_str());
            file.seekp(0, std::ios::end);
            int size = file.tellp();
            if (size == 0)
            {
                std::cout << "There aren't any auditoriums to be loaded. Please enter some using the command load\n";
            }
            else
            {
                file.close();
                std::ifstream file(info[0].c_str());
                load_from_file(file);
                loaded_auditoriums = true;
                file.close();
            }
            opened_file = info[0].c_str();
        }
        else
        {
            std::cout << "Invalid command, enter help to see supported commands.\n";
        }
        std::cout << "$\n";
    }
}
