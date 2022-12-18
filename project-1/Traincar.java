
//import java.util.Arrays;

public class Traincar{
    public String type;
    public int tcID;
    public int nofseats;
    public Seat[] seats;
    public Traincar(String wagtype)
    {
        //System.out.println("wagon");
        type=wagtype;
        if(type=="EZT")
        {
            GenerateLayoutEZT();
        }
        else if(type=="Classic")
        {
            GenerateLayoutCLS();
        }
        seats=new Seat[nofseats];
        for(int i=0;i<nofseats;i++)
        {
            seats[i]=new Seat();
        }
        GenerateSeatNames();
        tcID=0;
    }
    private void GenerateLayoutEZT()
    {
        nofseats=40;
    }
    private void GenerateLayoutCLS()
    {
        nofseats=48;
    }
    private void GenerateSeatNames()
    {
        for(int i=0;i<nofseats;i++)
        {
            seats[i].seatNumber=i+1;
        }
    }
    public void DisplaySeats()
    {
        if(type=="EZT")
        {
            int rows=10;
            for(int i=0;i<rows;i++)
            {
                //System.out.printf("%d\t%d\t\t%d\t%d\n",seats[4*i].seatNumber,seats[4*i+1].seatNumber,seats[4*i+2].seatNumber,seats[4*i+3].seatNumber);
                System.out.printf("%d\t%d\t\t%d\t%d\n",seats[4*i].CheckOccupancy(),seats[4*i+1].CheckOccupancy(),seats[4*i+2].CheckOccupancy(),seats[4*i+3].CheckOccupancy());
            }
        }
        else if(type=="Classic")
        {
            int divisions=6;
            for(int i=0;i<divisions;i++)
            {
                //System.out.printf("%d\t%d\t%d\t%d\n\n%d\t%d\t%d\t%d\n|--------------------------------|\n",seats[8*i].seatNumber,seats[8*i+1].seatNumber,seats[8*i+2].seatNumber,seats[8*i+3].seatNumber,seats[8*i+4].seatNumber,seats[8*i+5].seatNumber,seats[8*i+6].seatNumber,seats[8*i+7].seatNumber);
                System.out.printf("\t%d\t%d\t%d\t%d\n\n\t%d\t%d\t%d\t%d\n|--------------------------------|\n",seats[8*i].CheckOccupancy(),seats[8*i+1].CheckOccupancy(),seats[8*i+2].CheckOccupancy(),seats[8*i+3].CheckOccupancy(),seats[8*i+4].CheckOccupancy(),seats[8*i+5].CheckOccupancy(),seats[8*i+6].CheckOccupancy(),seats[8*i+7].CheckOccupancy());
            }
        }
        
    }
}