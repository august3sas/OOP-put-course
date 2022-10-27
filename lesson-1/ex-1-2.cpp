#include<iostream>
#include<vector>
class Room
{
public:
    std::vector<std::string>Rooms;//={"l053bt","cw8","cw4"};
    std::vector<int>Occupancy;
    int numberOfRooms;
    Room(int nofRooms)
    {
        this->numberOfRooms=nofRooms;
        setRooms();
        getRooms();
    }
    void setRooms()
    {
        std::cout<<"Enter Room names"<<std::endl;
        for(int i=0;i<this->numberOfRooms;i++)
        {
            std::string name;
            std::cin>>name;
            Rooms.push_back(name);
            Occupancy.push_back(0);
        }
    }
    void getRooms()
    {
        std::cout<<"availible rooms"<<std::endl;
        for(int i=0;i<3;i++)
        {
            std::cout<<Rooms[i]<<" ";
        }
    }
};
class LabGroup
{
    public:
    int numOfStudents;
    std::vector<std::string> StudentNames;
    void SetStudentNames()
    {
        std::cout<<"Enter Students names"<<std::endl;
        for(int i=0;i<this->numOfStudents;i++)
        {
            std::string name;
            std::cin>>name;
            StudentNames.push_back(name) ;
        }
    }
    LabGroup(int nofstudents)
    {
        this->numOfStudents=nofstudents;
        SetStudentNames();
    }
    void EnterRoom(Room r)
    {
        std::cout<<"Which room you want to enter (enter a number):"<<std::endl;
        for(int i=0;i<r.numberOfRooms;i++)
        {
            std::cout<<i<<": "<<r.Rooms[i]<<" Is the room occupied?: "<<r.Occupancy[i]<<std::endl;
        }
        int gotoroom;
        std::cin>>gotoroom;
        while(gotoroom>=r.numberOfRooms)
        {
            std::cout<<"try again."<<std::endl;
            std::cin>>gotoroom;
        }
        r.Occupancy[gotoroom]=1;
        std::cout<<"Lab group succesfully entered the room"<<std::endl;
        for(int i=0;i<r.numberOfRooms;i++)
        {
            std::cout<<i<<": "<<r.Rooms[i]<<" Is the room occupied?: "<<r.Occupancy[i]<<std::endl;
        }
    }
};

int main()
{
    std::cout<<"Enter the number of students in your lab group"<<std::endl;
    int tempvar;
    std::cin>>tempvar;
    std::cout<<"Enter the number of rooms"<<std::endl;
    int tempvar2;
    std::cin>>tempvar2;
    LabGroup L5(tempvar);
    Room Politechinka(tempvar2);
    L5.EnterRoom(Politechinka);
}
