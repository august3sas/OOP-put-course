
import java.util.Scanner;
import java.util.ArrayList;
public class MenuMessageBoard {
    private Scanner cin=new Scanner(System.in);
    protected ArrayList<Train> trainList;
    protected StationResState srs;
    public StationBase stationBase = new StationBase();
    protected void Separator()
    {
        System.out.println("----------------------------------------");
    }
    protected void WelcomeMessage()
    {
        System.out.println("Welcome to InterCity Ticket Reservation System.");
        System.out.println("As we are a small, local company, we operate just one, but very busy train line.");
        System.out.println("We operate on the train line 272 from Kepno to Poznan Glowny");
        
        Separator();
    }
    protected void IndicatorMessage()
    {
        System.out.println("Tell me what would you like to do next!");
        System.out.println("1. Make a reservation for a train!");
        System.out.println("2. Display all the availible trains and their names & IDs! ");
        System.out.println("3. Display all the availible stations that our trains serve");
        System.out.println("4. Display the informations about our train fleet");
        System.out.println("5. Exit");
        Separator();
    }
    protected void ReservationMenu()
    {
        System.out.println("Choose the station that you want to start your journey from!");
        System.out.printf("Enter the starting station: ");
        String ss1=cin.next();
        int s1;
        if(Character.isDigit(ss1.charAt(0)))
        {
            s1=Integer.parseInt(ss1);
        }
        else
        {
            s1=stationBase.returnIndexOfElement(ss1);
        }
        if(s1<=0||s1>=29)throw new IllegalArgumentException("Wrong Argument!");
        System.out.println("\nStation chosen: "+stationBase.stationNames[s1-1]+" (id: "+s1+")");
        System.out.printf("Enter the final station: ");
        String ss2=cin.next();
        int s2;
        if(Character.isDigit(ss2.charAt(0)))
        {
            s2=Integer.parseInt(ss2);
        }
        else
        {
            s2=stationBase.returnIndexOfElement(ss2);
        }
        if(s2<=0||s2>=29||s1==s2)throw new IllegalArgumentException("Wrong Argument!");
        System.out.println("\nStation chosen: "+stationBase.stationNames[s2-1]+" (id: "+s2+")");
        System.out.printf("Choose a train: (enter its name): ");
        String tr1=cin.next();
        int trid=findTrainByName(tr1);
        if(trid==-1)throw new IllegalArgumentException("Wrong Argument!");
        CustomReservation cr = new CustomReservation(srs);
        cr.DisplayPossibleSeats(trid);
        int wag=1;
        int sea=1;
        do
        {
            System.out.printf("Choose an availible wagon: ");
            wag=cin.nextInt();
            if(wag<1||wag>trainList.get(trid).nofWagons)throw new IllegalArgumentException("Wrong Argument!");
            System.out.printf("Choose an availible seat: ");
            sea=cin.nextInt();
            if(sea<1||sea>trainList.get(trid).TCs[wag-1].nofseats)throw new IllegalArgumentException("Wrong Argument!");
            if(srs.trainState.get(0).get(trid).TCs[wag-1].seats[sea-1].IsOccupied())
            {
                System.out.println("Seat is already booked");
            }
        }while(srs.trainState.get(0).get(trid).TCs[wag-1].seats[sea-1].IsOccupied());
        srs=cr.MakeReservation(trid,wag,sea,s1-1,s2-1);
    }
    protected void DisplayAllTrains()
    {
        System.out.println("All our availible trains:");
        for(int i=0;i<trainList.size();i++)
        {
            System.out.printf("Train %s %d has %d traincars and seats %d people. Its type is %s.\n",trainList.get(i).nameID,trainList.get(i).codeID,trainList.get(i).nofWagons,trainList.get(i).allPossibleSeats,trainList.get(i).tp);
        }
        Separator();
    }
    protected void DisplayAllStations()
    {
        for(int i=0;i<stationBase.stationNames.length;i++)
        {
            System.out.printf("%d. %s\n",stationBase.stationID[i],stationBase.stationNames[i]);
        }
        Separator();
    }
    protected void DisplayInfoTrainFleet()
    {
        System.out.println("In our fleet we exploit two main train types.");
        System.out.println("The first one is the classic lineup, known as \"Classic\". A train of this type consists of one locomotive and multiple traincars.");
        System.out.println("The second one is known as Electrical Multiple Unit (EMU or EZT) in short. It consists of several traincars, two of which are serving as a shunting car, and one or more has a hidden engine, which powers the train.");
        Separator();
    }
    private int findTrainByName(String x)
    {
        for(int i=0;i<trainList.size();i++)
        {
            if(x.equals(trainList.get(i).nameID))
            {
                return i;
            }
        }
        return -1;
    }
}
