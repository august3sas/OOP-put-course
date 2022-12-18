
import java.util.Scanner;
public class CustomReservation extends Reservation
{ 
    private Scanner sc=new Scanner(System.in);
    public CustomReservation(StationResState s)
    {
        srs=s;
    }
    public void DisplayPossibleSeats(int t)
    {
        Train inspectedTrain=srs.trainState.get(0).get(t);
        int aps=inspectedTrain.allPossibleSeats;
        int nw=inspectedTrain.nofWagons;
        int ns=inspectedTrain.TCs[0].nofseats;
        System.out.println("All Availible Seats:");
        for(int i=0;i<nw;i++)
        {
            System.out.println("\nWAGON NR "+(i+1));
            for(int j=0;j<ns;j+=4)
            {
                for(int k=0;k<4;k++)
                {
                    if(k%2==0&&k>0&&inspectedTrain.tp=="EZT")System.out.printf("\t\t");
                    if(!inspectedTrain.TCs[i].seats[j+k].IsOccupied())
                    {
                        System.out.print(inspectedTrain.TCs[i].seats[j+k].seatNumber+" ");
                    }
                    else System.out.print("   ");
                }
                System.out.println();
                //if(j>0&&j%8==0&&inspectedTrain.tp=="Classic")System.out.printf("\n|--------------------------------|\n");
            }
            
        }
    }
    public StationResState MakeReservation(int t,int w,int s,int start,int finish)
    {
        for(int i=start;i<=finish;i++)
        {
            srs.trainState.get(i).get(t).TCs[w-1].seats[s-1].ChangeOccupancy();
        }  
        System.out.println("You just made a reservation!");
        System.out.println("Reservation info:");
        System.out.println("Train "+srs.trainState.get(0).get(t).nameID);
        System.out.println("Wagon "+w);
        System.out.println("Seat "+s);
        System.out.println("From "+sbase.stationNames[start]);
        System.out.println("To "+sbase.stationNames[finish]);
        return srs;
    }
}
